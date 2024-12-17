#ifndef MONIKER_STREAM_PROCESSOR_H
#define MONIKER_STREAM_PROCESSOR_H

struct MonikerStreamProcessor {
    int moniker_sideband_stream_read_write = -1;
    int moniker_stream_write = -1;
    int moniker_stream_read = -1;
    int moniker_stream_read_write = -1;
};

#endif // Moniker_Stream_Processor_H
