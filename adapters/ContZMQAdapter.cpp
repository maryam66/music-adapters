#include "ContZMQAdapter.h"


static void*
zmq_thread(void* arg)
{
  //ContZMQAdapter* zmq_cont_adapter = static_cast<ContZMQAdapter*>(arg);
  //zmq_cont_adapter->runZMQ();
}


int
main(int argc, char** argv)
{

    ContZMQAdapter* adapter = new ContZMQAdapter();
    adapter->init(argc, argv);

    //pthread_t t;
    //pthread_create (&t, NULL, zmq_thread, &zmq_cont_adapter);
    adapter->run();

    //pthread_join(t, NULL);
    
    adapter->finalize();
}

ContZMQAdapter::ContZMQAdapter()
{
    port_in = new ContInPort();
    port_out = new ZMQOutPort();
}


void
ContZMQAdapter::tick()
{
    std::cout << "ZMQCONT Tick called" << std::endl;
}

