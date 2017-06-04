#include "ZMQInPort.h"


void
ZMQInPort::init(MUSIC::Setup* setup, char* port_name)
{

    //data = new double[data_size];
    //for (int i = 0; i < data_size; ++i)
    //{
    //    data[i] = 0.;
    //}

    context = new zmq::context_t(1);
    subscriber = new zmq::socket_t(*context, ZMQ_SUB);

    subscriber->connect(DEFAULT_ZMQ_ADDR.c_str());
    subscriber->setsockopt(ZMQ_SUBSCRIBE, "", 0);
    std::cout << "ZMQIn" << std::endl;


}

