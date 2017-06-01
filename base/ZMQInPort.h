#ifndef ZMQ_IN_PORT_H
#define ZMQ_IN_PORT_H

#include <music.hh>
#include "zhelpers.hpp"

#define DEBUG_OUTPUT false 

class ZMQInPort{
    public:
        double* data; 
        void init(MUSIC::Setup* setup, char* port_name, int data_size);

    private:

        zmq::context_t *context;
        zmq::socket_t *subscriber; 

};

#endif // ZMQ_IN_PORT_H 


