#ifndef EVENT_OUT_PORT_H
#define EVENT_OUT_PORT_H

#include <music.hh>
#include "OutPort.h"

#define DEBUG_OUTPUT false 


class EventOutPort : public OutPort{
    public:
        double* data; 
        void init(MUSIC::Setup* setup, char* port_name);

    private:

        MUSIC::EventOutputPort* port;

};

#endif // EVENT_OUT_PORT_H


