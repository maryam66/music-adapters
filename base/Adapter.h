#ifndef ADAPTER_H
#define ADAPTER_H

#include <music.hh>
#include <mpi.h>
#include "InPort.h"
#include "OutPort.h"

#include "sys/time.h"


#define DEBUG_OUTPUT false 

const double DEFAULT_TIMESTEP = 1e-3;
const double DEFAULT_STOPTIME = 1.;

class Adapter
{

    public:
        void init(int argc, char** argv);
        void run();
        void finalize();

        //int get_data_size_in() { return port_in->data_size; };
        //int get_data_size_out() { return port_out->data_size; };

    private:
        MPI::Intracomm comm;
        MUSIC::Runtime* runtime;
        double stoptime;
        double timestep;


        //virtual void init(int argc, char** argv);
        virtual void tick(){};
    protected:

        InPort* port_in;
        OutPort* port_out;

};

#endif // ADAPTER_H

