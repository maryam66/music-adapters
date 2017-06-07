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

    msg_type = DEFAULT_MESSAGE_TYPE;

}

void ZMQContAdapter::init(int argc, char** argv)
{

    Adapter::init(argc, argv);

    // config needed for this specific adapter
    
}

void
ZMQContAdapter::tick()
{
    Json::Value json_msg = static_cast<ZMQInPort*>(port_in)->recvAsJson();

    if (msg_type == ALEGrayScaleImage){
        for (int i = 0; i < port_out->data_size; ++i)
        {
          // outgoing messages should be between -1 and 1. Grayscale pixels have to be treated accordingly
          port_out->data[i] = (json_msg[i].asDouble() / 127.) - 1;
        } 
    }

    if (msg_type == FloatArray){
        for (int i = 0; i < port_out->data_size; ++i)
        {
          //TODO check for input range and rescale to [-1, 1]
          port_out->data[i] = json_msg[i].asDouble() / 2.;
        } 
    }

    if (msg_type == GymObservation){

        struct timeval now_;
        gettimeofday(&now_, NULL);
        double ts_now = now_.tv_sec + now_.tv_usec/1000000.;

        int i = 0;
        Json::Value::iterator it = json_msg.begin();
        while (it != json_msg.end()){
            Json::Value v = (*it);
            //std::cout << "ZMQ Cont tick " << v << static_cast<ContOutPort*>(port_out)->data[i] << std::endl;
            port_out->data[i] = 2 * (v["value"].asFloat() - v["min"].asFloat()) / 
                      ((v["max"].asFloat() - v["min"].asFloat())) - 1;

            double t_diff = ts_now - v["ts"].asDouble();
            if (t_diff > 0.01){
                std::cout << "WARNING: ZMQ_in_adapter " << " might be out of sync" << std::endl;
            }

#if DEBUG_OUTPUT
            std::cout << v  << std::endl;
#endif
            ++it;
            ++i;
        }

    }
        
#if DEBUG_OUTPUT
    std::cout << " ZMQ CONT OUTPUT: " << std::endl; 
    for (int i = 0; i < port_out->data_size; ++i)
    {
        std::cout << port_out->data[i] << " ";
    }
    std::cout << std::endl;
#endif


    //std::cout << "ZMQCONT Tick called " << json_msg << std::endl;
}

