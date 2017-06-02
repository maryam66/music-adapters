#ifndef EVENT_IN_PORT_H
#define EVENT_IN_PORT_H

#include <music.hh>
#include "InPort.h"

#define DEBUG_OUTPUT false 

const double DEFAULT_TIMESTEP = 1e-3;

class EventInPort : InPort, MUSIC::EventHandlerGlobalIndex{
    public:
        double* data;  
        void init(MUSIC::Setup* setup, char* port_name, int data_size);

    private:

        MUSIC::EventInputPort* port;

};

#endif // EVENT_IN_PORT_H


