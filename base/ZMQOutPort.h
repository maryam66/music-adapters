#ifndef ZMQ_OUT_PORT_H
#define ZMQ_OUT_PORT_H

#include "zhelpers.hpp"

#define DEBUG_OUTPUT false 

class ZMQOutPort{
    public:
        ZMQOutPort(char* port_name, int data_size);
        double* data; 

    private:
        zmq::context_t *context;
        zmq::socket_t *publisher; 

};

#endif // ZMQ_OUT_PORT_H


