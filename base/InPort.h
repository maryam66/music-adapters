#ifndef IN_PORT_H
#define IN_PORT_H

#include "Port.h"

class InPort : Port 
{
    public:
        virtual void init(MUSIC::Setup* setup, char* port_name) {};
};

#endif // ADAPTER_H

