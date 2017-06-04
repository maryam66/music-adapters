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

}

//  Receive 0MQ string from socket and convert into string
std::string
ZMQInPort::recv () {

    zmq::message_t message;
    subscriber->recv(&message);

    return std::string(static_cast<char*>(message.data()), message.size());
}

Json::Value
ZMQInPort::recvAsJson()
{

  std::string message = recv();

  Json::Reader json_reader;
  Json::Value json_msg; 
  if ( !json_reader.parse(message, json_msg))
  {
      std::cout << "ERROR WHILE PARSING JSON" << std::endl;
  }
  return json_msg;
    
}
