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


    msg_type = DEFAULT_MESSAGE_TYPE;
}


void
ContZMQAdapter::tick()
{

    Json::Value json_data(Json::arrayValue);

    if (msg_type == FloatArray){
        
        for (int i = 0; i < port_in->data_size; ++i){
           json_data.append(Json::Value(port_in->data[i]));
        }
        

    }
    else if (msg_type == GymCommand){

        struct timeval now_;
        gettimeofday(&now_, NULL);
        double ts_now = now_.tv_sec + now_.tv_usec/1000000.;
        
        for (unsigned int i = 0; i < port_in->data_size; ++i){
            Json::Value val;
            val["value"] = port_in->data[i];
            val["ts"] = ts_now;
            json_data.append(val);
        }
    }
   static_cast<ZMQOutPort*>(port_out)->send (writer.write(json_data));

}


