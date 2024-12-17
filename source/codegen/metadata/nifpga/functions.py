functions = {
    'Abort': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcknowledgeIrqs': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'irqs',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsBool': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'NiFpga_Bool *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsDbl': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'double *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsI16': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'int16_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsI32': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'int32_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsI64': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'int64_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsI8': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'int8_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsSgl': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'float *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsU16': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'uint16_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsU32': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'uint32_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsU64': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'uint64_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadElementsU8': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'uint8_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoReadRegion': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'region',
                'type': 'void *'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'void *'
            },
            {
                'direction': 'in',
                'name': 'isSigned',
                'type': 'NiFpga_Bool'
            },
            {
                'direction': 'in',
                'name': 'elementSizeBytes',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsBool': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'NiFpga_Bool *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsDbl': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'double *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsI16': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'int16_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsI32': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'int32_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsI64': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'int64_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsI8': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'int8_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsSgl': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'float *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsU16': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'uint16_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsU32': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'uint32_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsU64': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'uint64_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteElementsU8': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'uint8_t *'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'AcquireFifoWriteRegion': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'region',
                'type': 'void *'
            },
            {
                'direction': 'out',
                'name': 'elements',
                'type': 'void *'
            },
            {
                'direction': 'in',
                'name': 'isSigned',
                'type': 'NiFpga_Bool'
            },
            {
                'direction': 'in',
                'name': 'elementSizeBytes',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'elementsRequested',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsAcquired',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'CalculateFxpDeltaDouble': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'typeInfo',
                'type': 'NiFpga_FxpTypeInfo'
            }
        ],
        'returns': 'static'
    },
    'CalculateFxpDeltaFloat': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'typeInfo',
                'type': 'NiFpga_FxpTypeInfo'
            }
        ],
        'returns': 'static'
    },
    'Close': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'enum': 'CloseAttribute',
                'name': 'attribute',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'CloseHostMemoryBuffer': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'memoryName',
                'type': 'char[]'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'CloseLowLatencyBuffer': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'memoryName',
                'type': 'char[]'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'CommitFifoConfiguration': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ConfigureFifo': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'depth',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ConfigureFifo2': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'requestedDepth',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'actualDepth',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ConvertFromDoubleToFxp': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'typeInfo',
                'type': 'NiFpga_FxpTypeInfo'
            },
            {
                'direction': 'in',
                'name': 'data',
                'type': 'double'
            }
        ],
        'returns': 'static'
    },
    'ConvertFromFloatToFxp': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'typeInfo',
                'type': 'NiFpga_FxpTypeInfo'
            },
            {
                'direction': 'in',
                'name': 'data',
                'type': 'float'
            }
        ],
        'returns': 'static'
    },
    'ConvertFromFxpToDouble': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'typeInfo',
                'type': 'NiFpga_FxpTypeInfo'
            },
            {
                'direction': 'in',
                'name': 'data',
                'type': 'uint64_t'
            }
        ],
        'returns': 'static'
    },
    'ConvertFromFxpToFloat': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'typeInfo',
                'type': 'NiFpga_FxpTypeInfo'
            },
            {
                'direction': 'in',
                'name': 'data',
                'type': 'uint64_t'
            }
        ],
        'returns': 'static'
    },
    'Download': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'Finalize': {
        'codegen_method': 'no',
        'parameters': [
        ],
        'returns': 'NiFpga_Status'
    },
    'FindFifo': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifoName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'fifoNumber',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'FindRegister': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'registerName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'registerOffset',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'GetBitfileSignature': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'out',
                'name': 'signature',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'signatureSize',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'GetFifoPropertyI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'enum': 'FifoProperty',
                'name': 'property',
                'type': 'NiFpga_FifoProperty'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'GetFifoPropertyI64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'enum': 'FifoProperty',
                'name': 'property',
                'type': 'NiFpga_FifoProperty'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int64_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'GetFifoPropertyPtr': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'property',
                'type': 'NiFpga_FifoProperty'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'void *'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'GetFifoPropertyU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'enum': 'FifoProperty',
                'name': 'property',
                'type': 'NiFpga_FifoProperty'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'GetFifoPropertyU64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'enum': 'FifoProperty',
                'name': 'property',
                'type': 'NiFpga_FifoProperty'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uint64_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'GetFpgaViState': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'out',
                'enum': 'FpgaViState',
                'name': 'state',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'GetPeerToPeerFifoEndpoint': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'endpoint',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'Initialize': {
        'codegen_method': 'no',
        'parameters': [
        ],
        'returns': 'NiFpga_Status'
    },
    'IsError': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'status',
                'type': 'NiFpga_Status'
            }
        ],
        'returns': 'static'
    },
    'IsNotError': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'status',
                'type': 'NiFpga_Status'
            }
        ],
        'returns': 'static'
    },
    'MapP2PSinkFifo': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'size',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'virtualAddress',
                'type': 'void *'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'MergeStatus': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'status',
                'type': 'NiFpga_Status * const'
            },
            {
                'direction': 'in',
                'name': 'newStatus',
                'type': 'NiFpga_Status'
            }
        ],
        'returns': 'static'
    },
    'Open': {
        'custom_close': 'Close(id, 0)',
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'bitfile',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signature',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resource',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'OpenAttribute',
                'name': 'attribute',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'cppName': 'initializationBehavior',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.SessionInitializationBehavior',
                'name': 'initializationBehavior',
                'proto_only': True,
                'type': 'int32'
            },
            {
                'cppName': 'newSessionInitialized',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'newSessionInitialized',
                'proto_only': True,
                'type': 'bool'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'OpenHostMemoryBuffer': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'memoryName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'memorySize',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'virtualAddress',
                'type': 'void *'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'OpenLowLatencyBuffer': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'memoryName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'memorySizeToHost',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'virtualAddressToHost',
                'type': 'void *'
            },
            {
                'direction': 'out',
                'name': 'memorySizeToFpga',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'virtualAddressToFpga',
                'type': 'void *'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadArrayBool': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'NiFpga_Bool[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadArrayDbl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'double[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadArrayI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'int16_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadArrayI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'int32_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadArrayI64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'int64_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadArrayI8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'int8_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadArraySgl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'float[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadArrayU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'uint16_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadArrayU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'uint32_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadArrayU64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'uint64_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadArrayU8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'type': 'uint8_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadBool': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'NiFpga_Bool'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadDbl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'double'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadFifoBool': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'NiFpga_Bool[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoComposite': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'void'
            },
            {
                'direction': 'in',
                'name': 'bytesPerElement',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoDbl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'double[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'int16_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'int32_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoI64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'int64_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoI8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'int8_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoSgl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'float[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'uint16_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'uint32_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoU64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'uint64_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoU8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'uint8_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'elementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFxp64': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'typeInfo',
                'type': 'NiFpga_FxpTypeInfo'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uint64_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'int16_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'int32_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadI64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'int64_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadI8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'int8_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadSgl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'float'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'uint16_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadU64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'uint64_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReadU8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'uint8_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'ReleaseFifoElements': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'elements',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReleaseFifoRegion': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'region',
                'type': 'void'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'ReserveIrqContext': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'irqContext',
                'type': 'NiFpga_IrqContext'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'Reset': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'Run': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'enum': 'RunAttribute',
                'name': 'attribute',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'SetFifoPropertyI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'enum': 'FifoProperty',
                'name': 'property',
                'type': 'NiFpga_FifoProperty'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'SetFifoPropertyI64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'enum': 'FifoProperty',
                'name': 'property',
                'type': 'NiFpga_FifoProperty'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int64_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'SetFifoPropertyPtr': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'property',
                'type': 'NiFpga_FifoProperty'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'void'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'SetFifoPropertyU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'enum': 'FifoProperty',
                'name': 'property',
                'type': 'NiFpga_FifoProperty'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'SetFifoPropertyU64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'enum': 'FifoProperty',
                'name': 'property',
                'type': 'NiFpga_FifoProperty'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uint64_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'StartFifo': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'StopFifo': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'UnmapP2PSinkFifo': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'UnreserveFifo': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'UnreserveIrqContext': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'irqContext',
                'type': 'NiFpga_IrqContext'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WaitOnIrqs': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'irqContext',
                'type': 'NiFpga_IrqContext'
            },
            {
                'direction': 'in',
                'name': 'irqs',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'irqsAsserted',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'timedOut',
                'type': 'NiFpga_Bool'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteArrayBool': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'NiFpga_Bool[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteArrayDbl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'double[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteArrayI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'int16_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteArrayI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'int32_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteArrayI64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'int64_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteArrayI8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'int8_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteArraySgl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'float[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteArrayU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'uint16_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteArrayU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'uint32_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteArrayU64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'uint64_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteArrayU8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'array',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'uint8_t[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteBool': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'NiFpga_Bool'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteDbl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'double'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteFifoBool': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'NiFpga_Bool[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoComposite': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'type': 'void'
            },
            {
                'direction': 'in',
                'name': 'bytesPerElement',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoDbl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'double[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'int16_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'int32_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoI64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'int64_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoI8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'int8_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoSgl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'float[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'uint16_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'uint32_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoU64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'uint64_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoU8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'fifo',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'uint8_t[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'size_t'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'name': 'emptyElementsRemaining',
                'type': 'size_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFxp64': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'name': 'typeInfo',
                'type': 'NiFpga_FxpTypeInfo'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uint64_t'
            }
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'int16_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'int32_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteI64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'int64_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteI8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'int8_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteSgl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'float'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'uint16_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'uint32_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteU64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'uint64_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    },
    'WriteU8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session'
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t'
            },
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'value',
                'type': 'uint8_t'
            }
        ],
        'returns': 'NiFpga_Status',
        'supports_streaming': True
    }
}
