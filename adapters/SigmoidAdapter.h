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

class SigmoidAdapter : public Adapter
{
    public:
        SigmoidAdapter();
        void init(int argc, char** argv);
        void tick();

    private:
};

#endif // SIGMOID_ADAPTER_H
