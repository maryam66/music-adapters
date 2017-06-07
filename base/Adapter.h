#ifndef ADAPTER_H
#define ADAPTER_H

#include <music.hh>
#include <mpi.h>
#include "InPort.h"
#include "OutPort.h"

#include "sys/time.h"
#include "rtclock.h"

#define DEBUG_OUTPUT false 

const double DEFAULT_TIMESTEP = 1e-3;
const double DEFAULT_STOPTIME = 1.;
const double DEFAULT_RTF = 1.;

class Adapter
{

    public:
        MUSIC::Setup* setup;
        MUSIC::Runtime* runtime;
        
        double stoptime;

        void init(int argc, char** argv);
        void run(bool threaded);
        virtual void tick(){};
        virtual void asyncTick(){};
        void finalize();


    private:
        MPI::Intracomm comm;
        double timestep;
        double rtf;

        pthread_t thread;

    protected:

        InPort* port_in;
        OutPort* port_out;

};

#endif // ADAPTER_H

