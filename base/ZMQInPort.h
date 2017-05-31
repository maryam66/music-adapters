#ifndef ZMQ_IN_PORT_H
#define ZMQ_IN_PORT_H

#include "zhelpers.hpp"

#define DEBUG_OUTPUT false 

class ZMQInPort{
    public:
        ZMQInPort(char* port_name, int data_size);
        double* data; 

    private:

        zmq::context_t *context;
        zmq::socket_t *subscriber; 

};

#endif // ZMQ_IN_PORT_H 


