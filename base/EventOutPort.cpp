#include "EventOutPort.h"

void
EventOutPort::init(MUSIC::Setup* setup, char* port_name)
{

    port = setup->publishEventOutput(port_name);

    
    // map linear index to event out port 
    MUSIC::LinearIndex l_index(0, data_size);
    port->map(&l_index, MUSIC::Index::GLOBAL, 1);
 
}

