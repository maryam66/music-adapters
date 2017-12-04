#include "FunctionAdapter.h"

int
main(int argc, char** argv)
{

    FunctionAdapter* adapter = new FunctionAdapter();
    adapter->init(argc, argv);

    adapter->run(false);
    
    adapter->finalize();
}

FunctionAdapter::FunctionAdapter()
{
    port_in = new ContInPort();
    port_out = new ContOutPort();
}

void FunctionAdapter::init(int argc, char** argv)
{
    function = DEFAULT_FUNCTION;
    scale = DEFAULT_SCALE;
    slope = DEFAULT_SLOPE;
    x_offset = DEFAULT_X_OFFSET;
    y_offset = DEFAULT_Y_OFFSET;
    exponent = DEFAULT_EXPONENT;

    Adapter::init(argc, argv, "Function");

    // config needed for this specific adapter
    setup->config("function", &function);
    setup->config("scale", &scale);
    setup->config("slope", &slope);
    setup->config("x_offset", &x_offset);
    setup->config("y_offset", &y_offset);
    setup->config("exponent", &exponent);
}


void
FunctionAdapter::tick()
{
    for (int i = 0; i < port_in->data_size; ++i)
    {
        if (function == "log")
        {
            port_out->data[i] = scale * std::log(port_in->data[i] * slope + x_offset) + y_offset;
        }
        else if (function == "exp")
        {
            port_out->data[i] = scale * std::exp(port_in->data[i] * slope + x_offset) + y_offset;
        }
        else if (function == "sin")
        {
            port_out->data[i] = scale * std::sin(port_in->data[i] * slope + x_offset) + y_offset;
        }
        else if (function == "cos")
        {
            port_out->data[i] = scale * std::cos(port_in->data[i] * slope + x_offset) + y_offset;
        }
        else if (function == "tan")
        {
            port_out->data[i] = scale * std::tan(port_in->data[i] * slope + x_offset) + y_offset;
        }
        else if (function == "sqrt")
        {
            port_out->data[i] = scale * std::sqrt(port_in->data[i] * slope + x_offset) + y_offset;
        }
        else if (function == "pow")
        {
            port_out->data[i] = scale * std::pow(port_in->data[i] * slope + x_offset, exponent) + y_offset;
        }


    }
}


