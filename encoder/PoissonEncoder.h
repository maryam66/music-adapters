#ifndef POISSON_ENCODER_H
#define POISSON_ENCODER_H

#include <iostream>
#include <map>
#include <math.h>
#include <cmath>

#include <music.hh>
#include <mpi.h>

#include "Adapter.h"
#include "ContInPort.h"
#include "EventOutPort.h"

#include "sys/time.h"

#include "jsoncpp/json/json.h"
#include <fstream>

const double DEFAULT_RATE_MIN = 0.;
const double DEFAULT_RATE_MAX = 100.;

class PoissonEncoder : public Adapter
{
    public:
        PoissonEncoder();
        void init(int argc, char** argv);
        void tick();
        

    private:
        double normalization_factor;
        double rate_min, rate_max;
        double* next_spike;
        double* last_spike;

        struct drand48_data randBuffer;

        double denormalize(double s);
        double negexp (double m);

};

#endif // POISSON_ENCODER_H

