#ifndef OUT_PORT_H
#define OUT_PORT_H

#include "Port.h"

class OutPort : Port 
{
    public:
        virtual void init(MUSIC::Setup* setup, char* port_name) = 0;
        int data_size;
        double* data;
};

#endif // ADAPTER_H

