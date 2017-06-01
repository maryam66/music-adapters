#ifndef ZMQ_OUT_PORT_H
#define ZMQ_OUT_PORT_H

#include <music.hh>
#include "zhelpers.hpp"

#define DEBUG_OUTPUT false 

class ZMQOutPort{
    public:
        double* data; 
        void init(MUSIC::Setup* setup, char* port_name, int data_size);

    private:
        zmq::context_t *context;
        zmq::socket_t *publisher; 

};

#endif // ZMQ_OUT_PORT_H


