#
# Example communication with niFgen over gRPC
#
# Copyright 2020 National Instruments
# Licensed under the MIT license
#
# Getting Started:
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.proto) files
#   > py -m grpc_tools.protoc -I../../source --python_out=. --grpc_python_out=. server_utilities.proto
#
# Update the server address 
#
#

import grpc
import server_utilities_pb2 as server_utilities_type
import server_utilities_pb2_grpc as grpc_server_utilities

from collections import defaultdict

# This is the location (ipaddress or machine name):(port) of the server
serverAddress = "localhost:50051"

channel = grpc.insecure_channel(serverAddress)
server_utilities_stub = grpc_server_utilities.ServerUtilitiesStub(channel)

###################################################################################################

# Enumerate Device API
DeviceEnumerator = server_utilities_stub.EnumerateDevices(server_utilities_type.EnumerateDevicesRequest(
    ))

# For storing properties of the device/chassis
class Properties :
    def __init__(self, name , model , vendor , serial_number, parent , slot_number) :
        self.name = name
        self.model = model
        self.vendor = vendor
        self.serial_number = serial_number
        self.parent = parent
        self.slot_number = slot_number

# Since every device/chassis will have a unique name 
# so properties of that device/chassis can be mapped to its name in a dictionary
name_to_properties = defaultdict()

def comparator( name ):
    name_property = name_to_properties[name]
    slot_number = int(name_property.slot_number)
    return slot_number

class Tree :

    def __init__(self) :
        self.tree = defaultdict(list)

    def addEdge(self , parent , child) :
        self.tree[parent].append(child)

    def printHW(self , name , level) :
        space = ""
        for i in range(level) :
            space += "   "

        if (level != 0) :
            device_property = name_to_properties[name]
            if (level > 1) :
                print(space + "Slot " + device_property.slot_number + ": " + name )
            else :
                if (level == 1) :
                    print(space + name)

            print(space + "   " + "Model: " + device_property.model)
            print(space + "   " + "Vendor: " + device_property.vendor )
            print(space + "   " + "Serial Number: " + device_property.serial_number + "\n" )

        if name in self.tree :
            children = self.tree[name]
            children = sorted(children , key=comparator , reverse=False)
            for child in children :
                self.printHW( child , level+1 )
        
        return

def list_of_devices() :

    print("Connecting: ")
    print("Devices: " + "\n")

    tree = Tree()

    # Creating the tree for the Hierarchy
    for it in DeviceEnumerator.devices :
        device_property = Properties(
            it.name,
            it.model,
            it.vendor,
            it.serial_number,
            it.parent,
            it.slot_number
        )
        name_to_properties[it.name] = device_property
        
        if (len(it.parent) == 0) :
            tree.addEdge("My System" , it.name)
        else :
            tree.addEdge(it.parent , it.name)
    
    # Function to list devices in a Hierarchial Manner
    tree.printHW("My System" , 0)

# Calling List Device function
list_of_devices()    
###############################################################################################################
