#ifndef VECSUM_ADAPTER_H
#define VECSUM_ADAPTER_H

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
#include "float.h"

/**
 * Outputs the index channel of the maximum incoming value. Projects N incoming channels to 1 outgoing channel.
 */
class VecsumAdapter : public Adapter
{
    const double DEFAULT_TAU = 0.05;
    const double PI = M_PI;
    public:
        VecsumAdapter();
        void init(int argc, char** argv);
        void tick();

        double *action_fr = NULL;
        double **action_dir = NULL;
        // double action_fr[40] = {0.0};
        double action_vec[2] = {0.0};
        // double action_dir[40][2] = {0.0};
        double tau, decay_rate;

    private:
        void assign_action_to_neurons();
        void initialize_action_fr();
};

#endif // VECSUM_ADAPTER_H

