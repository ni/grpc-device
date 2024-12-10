#ifndef CPU_AFFINITY_CONFIGURATION_H
#define CPU_AFFINITY_CONFIGURATION_H

struct CpuAffinityConfiguration {
    int sideband_read_write = -1;
    int stream_write = -1;
    int server = -1;
};

#endif // CPU_AFFINITY_CONFIGURATION_H
