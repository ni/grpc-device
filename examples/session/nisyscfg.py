r"""Get information about the remote machine using NI System Configuration.

Getting Started:

To run this example, install NI System Configuration on the server machine:
  https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Running from the command line:

usage: nisyscfg.py [-h]
                   [server_address] [port_number]
                   {enumerate-devices,enumerate-software} ...

positional arguments:
  server_address        The IP address or machine name of the server. The default is localhost.
  port_number           The port number of the server. The default is 31763.

optional arguments:
  -h, --help            show the help message and exit

subcommands:
  {enumerate-devices,enumerate-software}
    enumerate-devices   Prints the list of devices connected to the server.
    enumerate-software  Prints the list of NI software packages installed on the server.
"""

import argparse

import grpc
import session_pb2 as session_types
import session_pb2_grpc as grpc_session


def main(args):
    # Store command line args
    SERVER_ADDRESS = args.server_address
    SERVER_PORT = args.port_number
    ACTION = args.action

    # Open communication with the server using gRPC APIs.
    channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
    client = grpc_session.SessionUtilitiesStub(channel)

    try:
        if ACTION == "enumerate-devices":
            enumerate_devices(client)
        elif ACTION == "enumerate-software":
            enumerate_software(client, args.show_hidden)

    # If the API throws an exception, print the error message.
    except grpc.RpcError as rpc_error:
        error_message = rpc_error.details()
        for entry in rpc_error.trailing_metadata() or []:
            if entry.key == "ni-error":
                value = entry.value if isinstance(entry.value, str) else entry.value.decode("utf-8")
                error_message += f"\nError status: {value}"
        if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
            error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
        elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
            error_message = (
                "The operation is not implemented or is not supported/enabled in this service"
            )
        print(f"{error_message}")


# Retrieves a list of devices (simulated and physical) connected to the server, then prints them.
def enumerate_devices(client):
    enumerate_devices_response = client.EnumerateDevices(session_types.EnumerateDevicesRequest())
    print_devices(enumerate_devices_response.devices)


# Retrieves a list of NI packages installed on the server.
def enumerate_software(client, show_hidden_packages):
    enumerate_software_response = client.EnumerateInstalledSoftware(
        session_types.EnumerateInstalledSoftwareRequest(
            include_hidden_packages=show_hidden_packages
        )
    )
    print_software(enumerate_software_response.software)


# Display devices connected to the server.
def print_devices(devices):
    """Print device info."""
    if not devices:
        print("No devices are connected.")
        return
    print(
        "\n-----------------------------------------------------------------------------------------------------\n"
    )
    print("  List of devices connected to the server: \n")
    print(
        "-----------------------------------------------------------------------------------------------------\n"
    )
    for device in devices:
        print(f"    {device.name}")
        print(f"        Model: {device.model}")
        print(f"        Vendor: {device.vendor}")
        print(f"        Serial Number: {device.serial_number} \n")


# Display software installed on the server.
def print_software(software):
    """Print software info."""
    if not software:
        print("No NI packages found.")
        return
    print(
        "\n-----------------------------------------------------------------------------------------------------\n"
    )
    print("  List of NI software installed on the server: \n")
    print(
        "-----------------------------------------------------------------------------------------------------\n"
    )
    for package in software:
        print(f"    Package ID: {package.package_id}")
        print(f"    Product Name: {package.product_name}")
        print(f"    Version: {package.package_version} \n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Get information about the remote machine using NI System Configuration."
    )
    parser.add_argument(
        "server_address",
        help="The IP address or machine name of the server. The default is localhost.",
        nargs="?",
        default="localhost",
    )
    parser.add_argument(
        "port_number",
        help="The port number of the server. The default is 31763.",
        nargs="?",
        default="31763",
    )
    subparsers = parser.add_subparsers(title="subcommands", dest="action", required=True)
    subparsers.add_parser(
        "enumerate-devices",
        help="Prints the list of devices connected to the server.",
    )
    parser_enumerate_software = subparsers.add_parser(
        "enumerate-software",
        help="Prints the list of NI software packages installed on the server.",
    )
    parser_enumerate_software.add_argument(
        "--show-hidden",
        help="Include hidden packages in the list of software.",
        action="store_true",
        default=False,
    )

    args = parser.parse_args()
    main(args)