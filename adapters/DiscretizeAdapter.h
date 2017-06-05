#ifndef DISCRETIZE_ADAPTER_H
#define DISCRETIZE_ADAPTER_H

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

#define DEBUG_OUTPUT false 


const string DEFAULT_GRID_POSITIONS_FILENAME = "grid_positions.json";

class DiscretizeAdapter : public Adapter
{
    public:
        DiscretizeAdapter();
        void tick();
        
        void readGridPositionFile();

    private:
        string grid_positions_filename;
        Json::Value json_grid_positions; 
        std::map<int, double*> grid_positions;
        std::map<int, double*> sigmas;



};

#endif // DISCRETIZE_ADAPTER_H
