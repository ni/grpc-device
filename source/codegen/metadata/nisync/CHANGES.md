# Changes in metadata from the nimi-python metadata

## config.py

The following metadata was added :
- 'linux_rt_support': True

## attributes.py

Removed the following deprecated attributes.
- TIMEREF_CLK_ADJ_OFFSET
- GPS_UTC_OFFSET
- IRIG_TAI_OFFSET

Added the following internal attribute.
- MODEL_CODE

## functions.py

The following functions were tagged as 'codegen_method':'CustomCode':
- ReadMultipleTriggerTimeStamp