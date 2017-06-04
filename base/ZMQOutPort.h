#ifndef ZMQ_OUT_PORT_H
#define ZMQ_OUT_PORT_H

#include <music.hh>
#include <zmq.hpp> // https://github.com/zeromq/cppzmq
#include "OutPort.h"

#define DEBUG_OUTPUT false 

const std::string DEFAULT_ZMQ_ADDR = "tcp://127.0.0.1:5556";
const std::string DEFAULT_ZMQ_TOPIC = "out";

class ZMQOutPort : public OutPort
{

    public:
        double* data; 
        int data_size;
        void init(MUSIC::Setup* setup, char* port_name);

    private:

        zmq::context_t *context;
        zmq::socket_t *publisher; 

};

#endif // ZMQ_OUT_PORT_H


