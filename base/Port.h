#ifndef PORT_H
#define PORT_H

#include <music.hh>

class Port 
{
    public:
        virtual void init(MUSIC::Setup* setup, char* port_name) = 0;
};

#endif // ADAPTER_H

