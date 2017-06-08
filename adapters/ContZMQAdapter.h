#ifndef CONT_ZMQ_ADAPTER_H
#define CONT_ZMQ_ADAPTER_H

#include <iostream>
#include <map>
#include <math.h>

#include <music.hh>
#include <mpi.h>

#include "Adapter.h"
#include "ContInPort.h"
#include "ZMQOutPort.h"

#include "sys/time.h"

#include <iostream>
#include "jsoncpp/json/json.h"

enum msg_types {FloatArray, GymCommand};

const msg_types DEFAULT_MESSAGE_TYPE = GymCommand;

class ContZMQAdapter : public Adapter
{
    public:
        ContZMQAdapter();
        void init(int argc, char** argv);
        void tick();

    private:
        msg_types msg_type;
        Json::FastWriter writer;

};

#endif // CONT_ZMQ_ADAPTER_H
