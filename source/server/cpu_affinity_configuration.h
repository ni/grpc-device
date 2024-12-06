#ifndef CPU_AFFINITY_CONFIGURATION_H
#define CPU_AFFINITY_CONFIGURATION_H

struct CpuAffinityConfiguration {
    int sideband_read_write;
    int stream_write;
    int server;
};

#endif // CPU_AFFINITY_CONFIGURATION_H
