# Why are there .proto files here?

Hapigen is also producing .proto files based on the metadata files (functions.py, etc). We are importing the hapigen created
.proto files here so we can validate that they match against the ones generated in grpc-device.

# Failing build on Validate Imported Protos step

Check these three potential issues, in order, to fix the build error:

1. Make sure .proto from driver export is copied over to grpc-device
2. Make sure you built grpc-device locally to get any generated folder changes (specifically .proto files there)
3. The proto generators (mako and helper python files) likely changed between grpc-device and hapigen and need to be synced up. 
