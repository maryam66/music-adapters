#include "ZMQOutPort.h"

void
ZMQOutPort::init(MUSIC::Setup* setup, char* port_name)
{

    //data = new double[data_size];
    //for (int i = 0; i < data_size; ++i)
    //{
    //    data[i] = 0.;
    //}

    context = new zmq::context_t(1);
    publisher = new zmq::socket_t(*context, ZMQ_PUB);

    publisher->bind(DEFAULT_ZMQ_ADDR.c_str());

}

//  Convert string to 0MQ string and send to socket
bool
ZMQOutPort::send (const std::string & string) {

    zmq::message_t message(string.size());
    memcpy (message.data(), string.data(), string.size());

    bool rc = publisher->send (message);
    return (rc);
}


