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
    std::cout << "ZMQOut" << std::endl;

}

