#include "EventInPort.h"


void 
EventInPort::init(MUSIC::Setup* setup, char* port_name, int data_size)
{

    port = setup->publishEventInput(port_name);

    // map linear index to event out port 
    MUSIC::LinearIndex l_index(0, data_size);
    port->map(&l_index, this, 0.0, 1); //TODO acceptable latency of 0. Does that work? 
}

