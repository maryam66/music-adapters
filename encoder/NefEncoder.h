#ifndef NEF_ENCODER_H
#define NEF_ENCODER_H

#include <iostream>
#include <map>
#include <math.h>
#include <cmath>

#include <music.hh>
#include <mpi.h>

#include "Adapter.h"
#include "ContInPort.h"
#include "EventOutPort.h"
#include "IAFNeuron.h"

#include "sys/time.h"

#include "jsoncpp/json/json.h"
#include <fstream>


const double DEFAULT_NEURON_RESOLUTION = 1e-3;
const bool DEFAULT_ONE_HOT = false;

class NefEncoder : public Adapter
{
    public:
        NefEncoder();
        void init(int argc, char** argv);
        void tick();
        

    private:
        double resolution;
        bool one_hot;
        std::vector<IAFNeuron> neurons;
        double t;

        struct drand48_data randBuffer;


};

#endif // NEF_ENCODER_H

