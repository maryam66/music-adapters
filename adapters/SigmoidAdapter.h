#ifndef SIGMOID_ADAPTER_H
#define SIGMOID_ADAPTER_H

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

const double DEFAULT_SCALE = 1.0;
const double DEFAULT_SLOPE = 1.0;
const double DEFAULT_X_OFFSET = 0.0;
const double DEFAULT_Y_OFFSET = 0.0;

class SigmoidAdapter : public Adapter
{
    public:
        SigmoidAdapter();
        void init(int argc, char** argv);
        void tick();

    private:
        double scale, slope, x_offset, y_offset;
};

#endif // SIGMOID_ADAPTER_H
