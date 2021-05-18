# -*- coding: utf-8 -*-
# This file is generated from NI-TClk API metadata version 255.0.0d0
attributes = {
    1: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'SYNC_PULSE_SOURCE',
        'resettable': False,
        'type': 'ViString'
    },
    2: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXPORTED_SYNC_PULSE_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    3: {
        'access': 'read-write',
        'attribute_class': 'AttributeSessionReference',
        'channel_based': False,
        'name': 'START_TRIGGER_MASTER_SESSION',
        'resettable': False,
        'type': 'ViSession',
        'type_in_documentation': 'Driver Session or nitclk.SessionReference',
    },
    4: {
        'access': 'read-write',
        'attribute_class': 'AttributeSessionReference',
        'channel_based': False,
        'name': 'REF_TRIGGER_MASTER_SESSION',
        'resettable': False,
        'type': 'ViSession',
        'type_in_documentation': 'Driver Session or nitclk.SessionReference',
    },
    5: {
        'access': 'read-write',
        'attribute_class': 'AttributeSessionReference',
        'channel_based': False,
        'codegen_method': 'no',
        'name': 'SCRIPT_TRIGGER_MASTER_SESSION',
        'resettable': False,
        'type': 'ViSession',
        'type_in_documentation': 'Driver Session or nitclk.SessionReference',
    },
    6: {
        'access': 'read-write',
        'attribute_class': 'AttributeSessionReference',
        'channel_based': False,
        'name': 'PAUSE_TRIGGER_MASTER_SESSION',
        'resettable': False,
        'type': 'ViSession',
        'type_in_documentation': 'Driver Session or nitclk.SessionReference',
    },
    8: {
        'access': 'read only',
        'channel_based': False,
        'name': 'TCLK_ACTUAL_PERIOD',
        'resettable': False,
        'type': 'ViReal64',
    },
    9: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXPORTED_TCLK_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString',
    },
    10: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'SYNC_PULSE_CLOCK_SOURCE',
        'resettable': False,
        'type': 'ViString'
    },
    11: {
        'access': 'read-write',
        'attribute_class': 'AttributeViReal64TimeDeltaSeconds',
        'channel_based': False,
        'name': 'SAMPLE_CLOCK_DELAY',
        'resettable': False,
        'type': 'ViReal64',
        'type_in_documentation': 'hightime.timedelta, datetime.timedelta, or float in seconds',
    },
    13: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'SYNC_PULSE_SENDER_SYNC_PULSE_SOURCE',
        'resettable': False,
        'type': 'ViString'
    },
    16: {
        'access': 'read-write',
        'attribute_class': 'AttributeSessionReference',
        'channel_based': False,
        'name': 'SEQUENCER_FLAG_MASTER_SESSION',
        'resettable': False,
        'type': 'ViSession',
        'type_in_documentation': 'Driver Session or nitclk.SessionReference',
    }
}
