#ifndef ARGMAX_ADAPTER_H
#define ARGMAX_ADAPTER_H

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

class ArgmaxAdapter : public Adapter
{
    public:
        ArgmaxAdapter();
        void init(int argc, char** argv);
        void tick();

};

#endif // ARGMAX_ADAPTER_H

