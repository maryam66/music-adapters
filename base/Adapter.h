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

template<class InPort, class OutPort>
class Adapter
{

    public:
        Adapter(int argc, char** argv);
        void finalize();

    private:
        MPI::Intracomm comm;
        MUSIC::Runtime* runtime;
        double stoptime;
        double timestep;
        int size_data_in;
        int size_data_out;
        double* data_in;
        double* data_out;

        InPort port_in;
        OutPort port_out;

        void initMUSIC(int argc, char** argv);
        void runMUSIC();

        virtual void init(int argc, char** argv);
        virtual void tick();};

#endif // ADAPTER_H

