#ifndef EVENT_OUT_PORT_H
#define EVENT_OUT_PORT_H

#include <music.hh>
#include "OutPort.h"

#define DEBUG_OUTPUT false 

const double DEFAULT_TIMESTEP = 1e-3;

class EventOutPort : OutPort{
    public:
        double* data; 
        void init(MUSIC::Setup* setup, char* port_name, int data_size);

    private:

        MUSIC::EventOutputPort* port;

};

#endif // EVENT_OUT_PORT_H


