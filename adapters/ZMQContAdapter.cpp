#include "ZMQContAdapter.h"


static void*
zmq_thread(void* arg)
{
  //ZMQContAdapter* zmq_cont_adapter = static_cast<ZMQContAdapter*>(arg);
  //zmq_cont_adapter->runZMQ();
}


int
main(int argc, char** argv)
{

    ZMQContAdapter* adapter = new ZMQContAdapter();
    adapter->init(argc, argv);

    //pthread_t t;
    //pthread_create (&t, NULL, zmq_thread, &zmq_cont_adapter);
    adapter->run();

    //pthread_join(t, NULL);
    
    adapter->finalize();
}

ZMQContAdapter::ZMQContAdapter()
{
    port_in = new ZMQInPort();
    port_out = new ContOutPort();
}


void
ZMQContAdapter::tick()
{
    std::cout << "ZMQCONT Tick called" << std::endl;
}

