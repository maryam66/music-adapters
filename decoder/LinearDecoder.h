#ifndef LINEAR_DECODER_H
#define LINEAR_DECODER_H

#include <iostream>
#include <map>
#include <math.h>
#include <cmath>

#include <music.hh>
#include <mpi.h>

#include "Adapter.h"
#include "EventInPort.h"
#include "ContOutPort.h"

#include "sys/time.h"

#include "jsoncpp/json/json.h"
#include <fstream>

const double DEFAULT_TAU = 0.03;

class LinearDecoder : public Adapter
{
    public:
        LinearDecoder();
        void init(int argc, char** argv);
        void tick();

    private:
        double tau, inv_tau, propagator;
};

#endif // LINEAR_DECODER_H

