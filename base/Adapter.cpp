#include "Adapter.h" 


Adapter::Adapter(InPort in, OutPort out, int argc, char** argv){
    init(argc, argv);
    initMUSIC(argc, argv);
    runMUSIC();
}


void
ContContAdapter::initMUSIC(int argc, char** argv)
{
    timestep = DEFAULT_TIMESTEP;

    MUSIC::Setup* setup = new MUSIC::Setup (argc, argv);

    setup->config("stoptime", &stoptime);
    setup->config("music_timestep", &timestep);

    port_in = setup->publishContInput("in");
    port_out = setup->publishContOutput("out");

    comm = setup->communicator ();
    int rank = comm.Get_rank ();       
    int nProcesses = comm.Get_size (); 
    if (nProcesses > 1)
    {
        std::cout << "ERROR: num processes (np) not equal 1" << std::endl;
        comm.Abort(1);
    }

    // get dimensions of data
    if (port_in->hasWidth() && port_out->hasWidth())
    {
        size_data_in = port_in->width();
        size_data_out = port_out->width();
    }
    else
    {
        std::cout << "ERROR: Port-width not defined" << std::endl;
        comm.Abort(1);
    }

    data_in = new double[size_data_in];
    for (int i = 0; i < size_data_in; ++i)
    {
        data_in[i] = 0.;
    }

    data_out = new double[size_data_out];
    for (int i = 0; i < size_data_out; ++i)
    {
        data_out[i] = 0.;
    }

    // Declare where in memory to put command_data
    MUSIC::ArrayData dmap_in(data_in,
      		 MPI::DOUBLE,
      		 0,
      		 size_data_in);
    port_in->map (&dmap_in, 0., 1, false);
    
    MUSIC::ArrayData dmap_out(data_out,
      		 MPI::DOUBLE,
      		 0,
      		 size_data_out);
    port_out ->map (&dmap_out, 1);

    MPI::COMM_WORLD.Barrier();
    runtime = new MUSIC::Runtime (setup, timestep);
}

void 
ContContAdapter::runMUSIC()
{
    std::cout << "running cont_cont adapter" << std::endl;
    
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);
    unsigned int ticks_skipped = 0;

    for (int t = 0; runtime->time() < stoptime; t++)
    {
   
        tick();
       
#if DEBUG_OUTPUT
        std::cout << "ContCont Adapter: ";
        for (int i = 0; i < size_data_out; ++i)
        {
            std::cout << data_out[i] << " ";
        }
        std::cout << std::endl;
#endif
        runtime->tick();
    }

    gettimeofday(&end, NULL);
    unsigned int dt_s = end.tv_sec - start.tv_sec;
    unsigned int dt_us = end.tv_usec - start.tv_usec;
    if (end.tv_sec > start.tv_sec)
    {
        dt_us += 1000000;
    }
    std::cout << "cont_cont adapter: total simtime: " << dt_s << " " << dt_us << " ticks skipped " << ticks_skipped <<  std::endl;
}

void
ContContAdapter::finalize(){
    runtime->finalize();
    delete runtime;
}

