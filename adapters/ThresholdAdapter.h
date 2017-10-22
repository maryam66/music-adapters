#ifndef THRESHOLD_ADAPTER_H
#define THRESHOLD_ADAPTER_H

#include <iostream>
#include <map>
#include <math.h>
#include <cmath>

#include <music.hh>
#include <mpi.h>

#include "Adapter.h"
#include "ContInPort.h"
#include "ContOutPort.h"

#include "sys/time.h"
#include "float.h"

const double DEFAULT_THRESHOLD = 0.0;
const int DEFAULT_HEAVISIDE = 1;

class ThresholdAdapter : public Adapter
{
    public:
        ThresholdAdapter();
        void init(int argc, char** argv);
        void tick();

    private:
        double threshold;
        int heaviside;
};

#endif // THRESHOLD_ADAPTER_H
