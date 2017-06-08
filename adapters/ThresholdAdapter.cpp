#include "ThresholdAdapter.h"

int
main(int argc, char** argv)
{

    ThresholdAdapter* adapter = new ThresholdAdapter();
    adapter->init(argc, argv);

    adapter->run(false);
    
    adapter->finalize();
}

ThresholdAdapter::ThresholdAdapter()
{
    port_in = new ContInPort();
    port_out = new ContOutPort();
}

void ThresholdAdapter::init(int argc, char** argv)
{
    Adapter::init(argc, argv);

    // config needed for this specific adapter
}


void
ThresholdAdapter::tick()
{
    double max = -DBL_MAX;
    int argmax = 0;
    for (int i = 0; i < port_in->data_size; ++i)
    {
        if (port_in->data[i] < 0.5)
            port_out->data[i] = 0.;
        else
            port_out->data[i] = 1.;
    }
}


