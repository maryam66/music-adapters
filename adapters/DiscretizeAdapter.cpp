#include "DiscretizeAdapter.h"

int
main(int argc, char** argv)
{

    DiscretizeAdapter* adapter = new DiscretizeAdapter();
    adapter->init(argc, argv);

    adapter->run(false);
    
    adapter->finalize();
}

DiscretizeAdapter::DiscretizeAdapter()
{
    port_in = new ContInPort();
    port_out = new ContOutPort();
}

void DiscretizeAdapter::init(int argc, char** argv)
{
    grid_positions_filename = DEFAULT_GRID_POSITIONS_FILENAME;

    Adapter::init(argc, argv);

    // config needed for this specific adapter
    setup->config("grid_positions_filename", &grid_positions_filename);
    
    readGridPositionFile();
}


void
DiscretizeAdapter::tick()
{
    for (int i = 0; i < port_out->data_size; ++i){
        double tmp_ = 0; 
    
        // calculate distance to this place cell 
        for (int j = 0; j < port_in->data_size; ++j){
            tmp_ += std::pow((port_in->data[j] - grid_positions[i][j]) / sigmas[i][j], 2);
        }
       
        // calculate activation in respect to gaussion kernel
        port_out->data[i] = -1. + 2. * std::exp(-tmp_/2.);
    }
   
       
#if DEBUG_OUTPUT
    std::cout << "Discretize Adapter: ";
    for (int i = 0; i < size_data_out; ++i)
    {
        std::cout << data_out[i] << " ";
    }
    std::cout << std::endl;
#endif

}


void 
DiscretizeAdapter::readGridPositionFile()
{
    Json::Reader json_reader;

    std::ifstream grid_positions_file;
    grid_positions_file.open(grid_positions_filename.c_str(), std::ios::in);
    string json_grid_positions_ = "";
    string line;

    while (std::getline(grid_positions_file, line))
    {
        json_grid_positions_+= line;
    }
    grid_positions_file.close();
    
    if ( !json_reader.parse(json_grid_positions_, json_grid_positions))
    {
      // report to the user the failure and their locations in the document.
      std::cout   << "WARNING: ros discretize adapter: Failed to parse file \"" << grid_positions_filename << "\"\n" 
		  << json_grid_positions_ << " It has to be in JSON format.\n "
		  << json_reader.getFormattedErrorMessages();
        
        return;
    }
    else
    {

            std::cout << "read grid file " << static_cast<ContOutPort*>(port_out)->data_size << std::endl;
        for (int i = 0; i < static_cast<ContOutPort*>(port_out)->data_size; ++i)
        {
            double* pos_ = new double[static_cast<ContInPort*>(port_in)->data_size];
            double* sigmas_ = new double[static_cast<ContInPort*>(port_in)->data_size];

            for (int j = 0; j < static_cast<ContInPort*>(port_in)->data_size; ++j)
            {
                pos_[j] = json_grid_positions[i][j].asDouble();
               
                //put sigmas on the diagonal
                sigmas_[j] = json_grid_positions[i][static_cast<ContInPort*>(port_in)->data_size + j].asDouble(); 
                std::cout << "discretize " << pos_[j] << " " << sigmas_[j] << std::endl;
            }
            grid_positions.insert(std::pair<int, double*>(i, pos_));
            sigmas.insert(std::pair<int, double*>(i, sigmas_));
        }


    }

}



