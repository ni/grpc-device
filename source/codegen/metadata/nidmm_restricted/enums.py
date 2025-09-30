# -*- coding: utf-8 -*-
# This file is generated from NI-DMM API metadata version 26.0.0d6
enums = {
    'AcquisitionStatus': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_RUNNING_ANTICOLLISION',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_FINISHED_WITH_BACKLOG',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_FINISHED_WITH_NO_BACKLOG',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_PAUSED',
                'value': 3
            },
            {
                'name': 'NIDMM_VAL_NO_ACQUISITION_IN_PROGRESS',
                'value': 4
            }
        ]
    },
    'PrivilegeLevel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_NO_PRIVILEGE',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_MONITOR_PRIVILEGE',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_REVOKABLE_CONTROL_PRIVILEGE',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_NON_REVOKABLE_CONTROL_PRIVILEGE',
                'value': 3
            }
        ]
    }
}
