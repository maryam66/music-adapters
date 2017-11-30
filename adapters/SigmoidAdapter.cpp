#include "SigmoidAdapter.h"

int
main(int argc, char** argv)
{

    SigmoidAdapter* adapter = new SigmoidAdapter();
    adapter->init(argc, argv);

    adapter->run(false);
    
    adapter->finalize();
}

SigmoidAdapter::SigmoidAdapter()
{
    port_in = new ContInPort();
    port_out = new ContOutPort();
}

void SigmoidAdapter::init(int argc, char** argv)
{
    Adapter::init(argc, argv, "Sigmoid");

    // config needed for this specific adapter
}

void
SigmoidAdapter::tick()
{
    for (int i = 0; i < port_in->data_size; ++i)
    {
        port_out->data[i] = 1. / ( 1. + std::exp(- port_in->data[i]));
    }
}


