#ifndef CONT_IN_PORT_H
#define CONT_IN_PORT_H

#include <music.hh>
#include "InPort.h"

#define DEBUG_OUTPUT false 


class ContInPort : public InPort{
    public:
        double* data;  
        void init(MUSIC::Setup* setup, char* port_name);

    private:

        MUSIC::ContInputPort* port;

};

#endif // CONT_IN_PORT_H


