#ifndef ZMQ_CONT_ADAPTER_H
#define ZMQ_CONT_ADAPTER_H

#include <iostream>
#include <map>
#include <math.h>

#include <music.hh>
#include <mpi.h>

#include "Adapter.h"
#include "ZMQInPort.h"
#include "ContOutPort.h"

#include "sys/time.h"

#include <iostream>
#include "jsoncpp/json/json.h"

#define DEBUG_OUTPUT false 

enum msg_types {ALEGrayScaleImage, FloatArray, GymObservation};


const msg_types DEFAULT_MESSAGE_TYPE = GymObservation;

class ZMQContAdapter : public Adapter
{
    public:
        ZMQContAdapter();
        void init(int argc, char** argv);
        void tick();
        void asyncTick();

    private:
        msg_types msg_type;

};

#endif // ZMQ_CONT_ADAPTER_H
