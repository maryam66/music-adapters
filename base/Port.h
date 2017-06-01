#ifndef PORT_H
#define PORT_H

#include <music.hh>

class Port 
{
    public:
        virtual void init(MUSIC::Setup* setup, char* port_name, int data_size);
        virtual void tick();

};

#endif // ADAPTER_H

