#ifndef EVENT_IN_PORT_H
#define EVENT_IN_PORT_H

#include <music.hh>
#include "InPort.h"

#define DEBUG_OUTPUT false 


class EventInPort : public InPort, MUSIC::EventHandlerGlobalIndex{
    public:
        double* data;  
        int data_size;
        void init(MUSIC::Setup* setup, char* port_name);

    private:

        MUSIC::EventInputPort* port;

};

#endif // EVENT_IN_PORT_H


