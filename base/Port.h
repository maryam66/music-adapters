#ifndef PORT_H
#define PORT_H

#include <music.hh>

class Port 
{
    public:
        virtual void init(MUSIC::Setup* setup, char* port_name) = 0;
        int data_size = 0;
        double* data;
};

#endif // ADAPTER_H

