#include "ContZMQAdapter.h"

int
main(int argc, char** argv)
{

    ContZMQAdapter* adapter = new ContZMQAdapter();
    adapter->init(argc, argv);

    adapter->run(false);
    
    adapter->finalize();
}

ContZMQAdapter::ContZMQAdapter()
{
    port_in = new ContInPort();
    port_out = new ZMQOutPort();
}

void ContZMQAdapter::init(int argc, char** argv)
{
    msg_type = DEFAULT_MESSAGE_TYPE;

    Adapter::init(argc, argv, "ContZMQ");

    // config needed for this specific adapter
    
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
        
        for (int i = 0; i < port_in->data_size; ++i){
            Json::Value val;
            val["value"] = port_in->data[i];
            val["ts"] = ts_now;
            json_data.append(val);
        }
    }
   static_cast<ZMQOutPort*>(port_out)->send (writer.write(json_data));

}


