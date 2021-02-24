#
# This example lists out devices/chassis in a Hierarchial Manner 
# by estabilishing communication with the server over gRPC
#
# Copyright 2021 National Instruments
# Licensed under the MIT license
#
# Getting Started:
#
# To run this example, users have to make sure that the "NI System Configuration API" is installed on the server machine.
# Link : https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.proto) files
#   > python -m grpc_tools.protoc -I../../source --python_out=. --grpc_python_out=. server_utilities.proto
#

import grpc
import server_utilities_pb2 as serverType
import server_utilities_pb2_grpc as grpcServer

from collections import defaultdict

# Create the communcation channel for the remote host (in this case we are connecting to a local server)
serverAddress = "localhost:50051"
channel = grpc.insecure_channel(serverAddress)

# Create communication with the server using the created communication channel
server = grpcServer.ServerUtilitiesStub(channel)
print("Connecting: ")

###################################################################################################

# Enumerate the devices connected to the server machine.
# This API gives a list of devices/chassis connected to the server machine.
enumerateDeviceResponse = server.EnumerateDevices(serverType.EnumerateDevicesRequest())

# For storing properties of the device/chassis
class Properties :
    def __init__(self, name , model , vendor , serialNumber, parent , slotNumber) :
        self.name = name
        self.model = model
        self.vendor = vendor
        self.serialNumber = serialNumber
        self.parent = parent
        self.slotNumber = slotNumber

# Properties of a perticular device/chassis can be mapped to its name 
# because every device/chassis has a unique name
nameToProperties = defaultdict()

# This will be used for custom sorting the devices based on the Slot Number
def comparator(name):
    deviceProperty = nameToProperties[name]
    slotNumber = int(deviceProperty.slotNumber)
    return slotNumber

class Tree :
    def __init__(self) :
        self.tree = defaultdict(list)

    def addEdge(self , parent , child) :
        self.tree[parent].append(child)

    def printHardwareProperties(self , name , level) :
        space = ""
        for i in range(level) :
            space += "   "
        if (level != 0) :
            deviceProperty = nameToProperties[name]
            if (level > 1) :
                print(space + "Slot " + deviceProperty.slotNumber + ": " + name)
            else :
                if (level == 1) :
                    print(space + name)
            print(space + "   " + "Model: " + deviceProperty.model)
            print(space + "   " + "Vendor: " + deviceProperty.vendor)
            print(space + "   " + "Serial Number: " + deviceProperty.serialNumber + "\n")

        if name in self.tree :
            children = self.tree[name]
            children = sorted(children , key=comparator , reverse=False)
            for child in children :
                self.printHardwareProperties(child , level+1)      
        return

def listOfDevices() :
    print("Devices: " + "\n") 
    tree = Tree()

    # Creating the tree for the Hierarchy
    # "My System" would be the root node and all the devices/chassis would be connected to it.
    # for example                 
    #                                    "My System"
    #                                  /      |       \
    #                        "Chassis1"  "Chassis2"  "Device1"
    #                     /        \         |
    #            "Block Carrier1"  "device2"  "device3"
    #                   |
    #                 "device4"

    for it in enumerateDeviceResponse.devices :
        deviceProperty = Properties(
            it.name,
            it.model,
            it.vendor,
            it.serial_number,
            it.parent,
            it.slot_number
        )
        nameToProperties[it.name] = deviceProperty        
        if (len(it.parent) == 0) :
            tree.addEdge("My System" , it.name)
        else :
            tree.addEdge(it.parent , it.name)
    
    # Function to list devices along with the properties in a Hierarchial Manner
    # from the root node
    tree.printHardwareProperties("My System" , 0)

# Calling listOfDevices() function
listOfDevices()    
###############################################################################################################
