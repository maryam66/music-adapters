#ifndef CONT_CONT_ADAPTER_H
#define CONT_CONT_ADAPTER_H

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

#include "jsoncpp/json/json.h"
#include <fstream>

#include <gsl/gsl_matrix_double.h>
#include <gsl/gsl_vector_double.h>
#include <gsl/gsl_blas.h>

const string DEFAULT_WEIGHTS_FILENAME = "weights.json";

class ContContAdapter : public Adapter
{
    public:
        ContContAdapter();
        void init(int argc, char** argv);
        void tick();
    private:
        string weights_filename;
        Json::Value json_weights; 
        double* weights;
        gsl_vector_view vec_data_in;
        gsl_vector_view vec_data_out;
        gsl_matrix_view mat_weights;

        void readWeightsFile();

};

#endif // CONT_CONT_ADAPTER_H

