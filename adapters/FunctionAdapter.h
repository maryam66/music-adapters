#ifndef FUNCTION_ADAPTER_H
#define FUNCTION_ADAPTER_H

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

const std::string DEFAULT_FUNCTION = "log";
const double DEFAULT_SCALE = 1.0;
const double DEFAULT_SLOPE = 1.0;
const double DEFAULT_X_OFFSET = 0.0;
const double DEFAULT_Y_OFFSET = 0.0;
const double DEFAULT_EXPONENT = 1.0;

class FunctionAdapter : public Adapter
{
    public:
        FunctionAdapter();
        void init(int argc, char** argv);
        void tick();

    private:
        std::string function;
        double scale, slope, x_offset, y_offset, exponent;
};

#endif // FUNCTION_ADAPTER_H
