#ifndef ZMQ_IN_PORT_H
#define ZMQ_IN_PORT_H

#include <music.hh>
#include <zmq.hpp> // https://github.com/zeromq/cppzmq
#include "InPort.h"

#include "jsoncpp/json/json.h"

#define DEBUG_OUTPUT false 

const std::string DEFAULT_ZMQ_ADDR = "tcp://localhost:5555";
const std::string DEFAULT_ZMQ_TOPIC = "in";

class ZMQInPort : public InPort
{

    public:
        //double* data; 
        void init(MUSIC::Setup* setup, char* port_name);

        std::string recv();
        Json::Value recvAsJson();

    private:

        zmq::context_t *context;
        zmq::socket_t *subscriber; 

};

#endif // ZMQ_IN_PORT_H 


