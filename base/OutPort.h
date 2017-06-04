#ifndef OUT_PORT_H
#define OUT_PORT_H

#include "Port.h"

class OutPort : Port 
{
    public:
        virtual void init(MUSIC::Setup* setup, char* port_name) {};
};

#endif // ADAPTER_H

