#include "NefEncoder.h"

int
main(int argc, char** argv)
{

    NefEncoder* adapter = new NefEncoder();
    adapter->init(argc, argv);

    adapter->run(false);
    
    adapter->finalize();
}

NefEncoder::NefEncoder()
{
    port_in = new ContInPort();
    port_out = new EventOutPort();
}

void NefEncoder::init(int argc, char** argv)
{
    resolution = DEFAULT_NEURON_RESOLUTION;

    Adapter::init(argc, argv, "NefEncoder");

    srand48_r(time(NULL), &randBuffer);

    // config needed for this specific adapter
    setup->config("neuron_resolution", &resolution);
    
    for (int n = 0; n < port_out->data_size; ++n){
        IAFNeuron neuron(port_in->data_size, randBuffer);
        neuron.setResolution(resolution);
        neuron.init_nef(port_in->data_size);
        neuron.encode(port_in->data);
        neurons.push_back(neuron);
    }
 
}


void
NefEncoder::tick()
{
    t = runtime->time();
    
    for (unsigned int n = 0; n < neurons.size(); ++n)
    {
        neurons[n].encode(port_in->data);
    }
    
    double next_t = t + timestep;
    while (t <= next_t)
    {
        for (unsigned int n = 0; n < neurons.size(); ++n)
        {
            if (neurons[n].propagate())
            {
                static_cast<EventOutPort*>(port_out)->send(n, runtime->time() + timestep);
            }
        }
        t += resolution; // propagate one timestep 
    }
}


