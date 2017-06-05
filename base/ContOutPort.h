#ifndef CONT_OUT_PORT_H
#define CONT_OUT_PORT_H

#include <music.hh>
#include "OutPort.h"

#define DEBUG_OUTPUT false 


class ContOutPort : public OutPort{
    public:
        void init(MUSIC::Setup* setup, char* port_name);

    private:

        MUSIC::ContOutputPort* port;

};

#endif // CONT_OUT_PORT_H


