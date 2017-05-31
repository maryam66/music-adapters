#ifndef CONT_IN_PORT_H
#define CONT_IN_PORT_H

#include <music.hh>
#include "InPort.h"

#define DEBUG_OUTPUT false 

const double DEFAULT_TIMESTEP = 1e-3;

class ContInPort : InPort{
    public:
        ContInPort(MUSIC::Setup* setup, char* port_name, int data_size);
        double* data;  

    private:

        MUSIC::ContInputPort* port;

};

#endif // CONT_IN_PORT_H


