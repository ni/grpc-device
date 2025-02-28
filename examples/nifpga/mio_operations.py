r"""FPGA RMIO Test Module."""
##This example was built for a larger self-test application. It may have missing dclarations and would require Selftest_CF module to run

TEST_MODULE_NAME = 'RMIO'

FPGA_Main_ControlBool_Start = 0x1800E
FPGA_Main_ControlBool_Stop = 0x18012

FPGA_Main_IndicatorArrayI64_AIs = 0x18000
FPGA_Main_IndicatorArrayI64Size_AIs = 8
#Controls
FPGA_Main_ControlU8_Connector0Port_0 = 0x18006
FPGA_Main_ControlU8_Connector1Port_0 = 0x1801E
FPGA_Main_ControlU8_Connector1Port_2 = 0x18026
#Indicators
FPGA_Main_IndicatorU8_Connector0Port_1 = 0x1800A
FPGA_Main_IndicatorU8_Connector1Port_1 = 0x18022
FPGA_Main_IndicatorU8_Connector1Port_3 = 0x1802A

import sys
import os
import SelfTest_CF
import datetime

import grpc
import nifpga_pb2 as nifpga_types
import nifpga_pb2_grpc as grpc_nifpga
import time
import numpy as np

response=None

def U8_Digital_Port_Operations(nifpga_client, FPGA_session, FPGA_Control_ID, FPGA_Indicator_ID, Values_to_Write):
    """This function performs a series of write/read operations on a U8 digital port and performs a Pass/Fail Test at the end."""
    i=0
    Test_Status=True
    Measurements=[]
    for i in range(len(Values_to_Write)):
        #Write Port 0
        response=nifpga_client.WriteU8(
            nifpga_types.WriteU8Request(
                session=FPGA_session,
                control = FPGA_Control_ID,
                value = Values_to_Write[i],
            )
        )
        raise_if_error(response)
        
        #Read Port 1
        response=nifpga_client.ReadU8(
            nifpga_types.ReadU8Request(
                session=FPGA_session,
                indicator = FPGA_Indicator_ID,
            )
        )
        raise_if_error(response)
        Measurements.append(response.value)
        #Check Measurement
        if Measurements[i]!=Values_to_Write[i]:
            #Measurement is incorrect
            Test_Status=False
        i=i+1
    #We compute Test Status
    if Test_Status==True:
        Status='Pass'
    else:
        Status='Fail'   
    return Status,Measurements;

def AI_AO_Operations(nifpga_client, FPGA_session, FPGA_Indicator_ID, AO_Values):
    """This function performs a read operations on 8 Analog Inputs and performs a Pass/Fail Test at the end."""
    i=0
    Test_Status=True
    Measurements=[]
    response=nifpga_client.ReadArrayI64(
        nifpga_types.ReadArrayI64Request(
            session=FPGA_session,
            indicator = FPGA_Indicator_ID,
            size = len(AO_Values),
        )
    )
    raise_if_error(response)
    converted_value = float(0)
    for i in range(FPGA_Main_IndicatorArrayI64Size_AIs):
        converted_value= float(response.array[i])*3.552714e-15
        Measurements.append(converted_value)
        # We check real values against expected values with a 1% tolerance
        Test_Status=Test_Status and (SelfTest_CF.Test_Numeric_Test(AO_Values[i],Measurements[i],1))
        i=i+1
    #We compute Test Status
    if Test_Status==True:
        Status='Pass'
    else:
        Status='Fail'   
    return Status,Measurements;

def raise_if_error(response):
    """Raise an exception if an error was returned."""
    if response.status != 0:
        if response.status > 0:
          #print(f"Warning: {response.status}") 
          print(f'{"":25}\tWARN.\tWarning: {response.status}.')    
        else:
            raise Exception(f"Error: {response.status}")
    Status = response.status
    return Status

def FPGA_RMIO_Operations(gRPC_channel, FPGA_ResourceName,Bitfile_Path,Bitfile_Signature):
    """This function interacts with the RMIO board (PXIe-784x board)"""

    My_Module_Result=SelfTest_CF.Module_Result()
    My_Module_Result.Test_Module_Name = TEST_MODULE_NAME
    My_Module_Result.Status_Code=0
    My_Module_Result.NB_Tests_Completed=0
    My_Module_Result.Module_Tests_Result_list=[]
    Tests_Result_list = []

    # Create a gRPC channel + nifpga_client.
    nifpga_client = grpc_nifpga.NiFpgaStub(gRPC_channel)
    #task = None
    FPGA_session = None
    Measurements=[]

    try:
        response = nifpga_client.Open(
            nifpga_types.OpenRequest(
                session_name="my RMIO FPGA session",
                bitfile=Bitfile_Path,
                signature=Bitfile_Signature,
                resource=FPGA_ResourceName,
                attribute_mapped= nifpga_types.OPEN_ATTRIBUTE_NoRun,
            )
        )
        My_Module_Result.Status_Code=raise_if_error(response)
        FPGA_session = response.session
    
        response=nifpga_client.Run(
            nifpga_types.RunRequest(
                session=FPGA_session,
                attribute=nifpga_types.RUN_ATTRIBUTE_UNSPECIFIED,
                #attribute_raw=0,
            )
        )
        My_Module_Result.Status_Code=raise_if_error(response)

        # Start Bitfile
        response=nifpga_client.WriteBool(
            nifpga_types.WriteBoolRequest(
                session=FPGA_session,
                control = FPGA_Main_ControlBool_Start,
                value = 1,
            )
        )
        My_Module_Result.Status_Code=raise_if_error(response)

        #----------------------------------- TESTS -----------------------------------  
        #---------------------- Connector 0 PORTS 0-1 Loopback -----------------------
        MyTestResult=SelfTest_CF.Test_Result()
        MyTestResult.CustomInit('Connector 0: Digital Ports 0 and 1 Loopback','Fail',2,[],[0x55,0xAA],'This test checks digital IOs from Port 0 and Port 1 of Connector 0. This test requires an external loopback between the 2 ports. 2 values (0x55(85d) and 0xAA(170d)) are sequentially written on Port 0 with a read on Port 1.',str(datetime.datetime.now()))
        Measurements.clear()
        
        MyTestResult.Test_PassFail_Status,Measurements=U8_Digital_Port_Operations(nifpga_client, FPGA_session, FPGA_Main_ControlU8_Connector0Port_0, FPGA_Main_IndicatorU8_Connector0Port_1, MyTestResult.Test_Expected_Numeric_Results)
        MyTestResult.Test_Numeric_Results.extend(Measurements)

        Tests_Result_list.append(MyTestResult)
        del MyTestResult
        #-----------------------------------------------------------------------------

        #---------------------- Connector 1 PORTS 0-1 Loopback -----------------------
        MyTestResult=SelfTest_CF.Test_Result()
        MyTestResult.CustomInit('Connector 1: Digital Ports 0 and 1 Loopback','Fail',2,[],[0x55,0xAA],'This test checks digital IOs from Port 0 and Port 1 of Connector 1. This test requires an external loopback between the 2 ports. 2 values (0x55(85d) and 0xAA(170d)) are sequentially written on Port 0 with a read on Port 1.',str(datetime.datetime.now()))
        Measurements.clear()
        
        MyTestResult.Test_PassFail_Status,Measurements=U8_Digital_Port_Operations(nifpga_client, FPGA_session, FPGA_Main_ControlU8_Connector1Port_0, FPGA_Main_IndicatorU8_Connector1Port_1, MyTestResult.Test_Expected_Numeric_Results)
        MyTestResult.Test_Numeric_Results.extend(Measurements)


        Tests_Result_list.append(MyTestResult)
        del MyTestResult
        #-----------------------------------------------------------------------------

        #---------------------- Connector 1 PORTS 2-3 Loopback -----------------------
        MyTestResult=SelfTest_CF.Test_Result()
        MyTestResult.CustomInit('Connector 1: Digital Ports 2 and 3 Loopback','Fail',2,[],[0x55,0xAA],'This test checks digital IOs from Port 2 and Port 3 of Connector 1. This test requires an external loopback between the 2 ports. 2 values (0x55(85d) and 0xAA(170d)) are sequentially written on Port 2 with a read on Port 3.',str(datetime.datetime.now()))
        Measurements.clear()
        
        MyTestResult.Test_PassFail_Status,Measurements=U8_Digital_Port_Operations(nifpga_client, FPGA_session, FPGA_Main_ControlU8_Connector1Port_2, FPGA_Main_IndicatorU8_Connector1Port_3, MyTestResult.Test_Expected_Numeric_Results)
        MyTestResult.Test_Numeric_Results.extend(Measurements)

        Tests_Result_list.append(MyTestResult)
        del MyTestResult
        #-----------------------------------------------------------------------------

        #--------------------------- Analog Inputs/Outputs ---------------------------
        MyTestResult=SelfTest_CF.Test_Result()
        MyTestResult.CustomInit('Connector 0: Analog Inputs/Ouputs Loopback','Fail',8,[],[1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0],'This test checks analog inputs/outputs. This test requires an external loopback between the AIx and AOx. 8 values (1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0) are written on AOx.',str(datetime.datetime.now()))
        Measurements.clear()        

        MyTestResult.Test_PassFail_Status,Measurements=AI_AO_Operations(nifpga_client, FPGA_session, FPGA_Main_IndicatorArrayI64_AIs, MyTestResult.Test_Expected_Numeric_Results)
        MyTestResult.Test_Numeric_Results.extend(Measurements)
        
        Tests_Result_list.append(MyTestResult)
        del MyTestResult
        #-----------------------------------------------------------------------------
        #         
        # Stop
        response=nifpga_client.WriteBool(
            nifpga_types.WriteBoolRequest(
                session=FPGA_session,
                control = FPGA_Main_ControlBool_Stop,
                value = 1,
            )
        )
        My_Module_Result.Status_Code=raise_if_error(response)



    except:
        #error_message = rpc_error.details()
        My_Module_Result.Status_Code=response.status
        print(f'{"":25}\tERROR\tFPGA RMIO Exception, error code: {response.status}.')    
        
    finally:
        if FPGA_session:
            nifpga_client.Close(
                nifpga_types.CloseRequest(
                    session=FPGA_session,
                    #attribute=nifpga_types.CLOSE_ATTRIBUTE_UNSPECIFIED,
                    attribute=nifpga_types.CLOSE_ATTRIBUTE_NoResetIfLastSession,
                )
            )
         
        My_Module_Result.Module_Tests_Result_list=Tests_Result_list
        My_Module_Result.NB_Tests_Completed=len(My_Module_Result.Module_Tests_Result_list)
    return My_Module_Result   