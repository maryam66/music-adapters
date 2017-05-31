#ifndef CONT_OUT_PORT_H
#define CONT_OUT_PORT_H

#include <music.hh>
#include "OutPort.h"

#define DEBUG_OUTPUT false 

const double DEFAULT_TIMESTEP = 1e-3;

class ContOutPort : OutPort{
    public:
        ContOutPort(MUSIC::Setup* setup, char* port_name, int data_size);
        double* data; 

    private:

        MUSIC::ContOutputPort* port;

};

#endif // CONT_OUT_PORT_H


