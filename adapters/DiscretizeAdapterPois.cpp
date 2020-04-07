#include "DiscretizeAdapterPois.h"

int
main(int argc, char** argv)
{

    DiscretizeAdapterPois* adapter = new DiscretizeAdapterPois();
    adapter->init(argc, argv);

    adapter->run(false);
    
    adapter->finalize();
}

DiscretizeAdapterPois::DiscretizeAdapterPois()
{
    port_in = new ContInPort();
    port_out = new EventOutPort();
}

void DiscretizeAdapterPois::init(int argc, char** argv)
{
    grid_positions_filename = DEFAULT_GRID_POSITIONS_FILENAME;

    Adapter::init(argc, argv, "Discretize");

    // config needed for this specific adapter
    setup->config("grid_positions_filename", &grid_positions_filename);
    
    readGridPositionFile();
    readSeedfromNetParams();

    // setting up the random number generator with seed=Seed
    // std::uniform_real_distribution<> dis(0.0, 1.0);

    gen.seed(Seed);
    std::cout << "The seed number is:" << Seed << std::endl;
}


void
DiscretizeAdapterPois::tick()
{
    double rnd = 0.0;
    // double tmp_ = 0;
    double fr_prob_tmp = 0;
    // bool spk = 0;
    // time = runtime->time();
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < port_out->data_size; ++i){
        double tmp_ = 0; 
    
        // calculate distance to this place cell 
        for (int j = 0; j < port_in->data_size; ++j){
            tmp_ += std::pow((port_in->data[j] - grid_positions[i][j]) / sigmas[i][j], 2);
        }
       
        // calculate activation in respect to gaussion kernel
        // port_out->data[i] = -1. + 2. * std::exp(-tmp_/2.);

        // modifying maximum firing rate to fit it into the spiking network
        fr_prob_tmp = 70. * timestep * std::exp(-tmp_/2.); //70. should be a par
        
        rnd = dis(gen);
        std::cout << "The generated random number is: " << rnd << std::endl;

        if (rnd < fr_prob_tmp){
            static_cast<EventOutPort*>(port_out)->send(i, runtime->time() + timestep);
            // port_out->insertEvent(i, time)
        }
        // if (rnd < fr_prob_tmp){
        //     spk = 1;
        // }
        // else
        // {
        //     spk = 0;
        // }
        // port_out->data[i] = spk;
    }
}

/**
 * Read the provided JSON file to extracts the multidimensional mean and sigma for the Gaussian tuning curves (place cells).
 * 
 * The file must be structured such that for each output neuron the corresponding means and sigmas are concatenated.
 * A valid JSON string for two output neurons in a two dimensional space would look like:
 *  
 * [[mean_x0, mean_y0, sigma_x0, sigma_y0],
 *  [mean_x1, mean_y1, sigma_x1, sigma_y1]]
 *
 * Example Python script to create a valid JSON file:
 *
 * @code
 * import numpy as np
 * import json
 * 
 * num_neurons_x = 5
 * num_neurons_y = 10
 * 
 * sigma_x = 0.2 
 * sigma_y = 0.1
 * 
 * pos = []
 * 
 * for i, x in enumerate(np.linspace(-1.0, 1.0, num_neurons_x)):
 *     for j, y in enumerate(np.linspace(-1.0, 1.0, num_neurons_y)):
 *         pos.append([x, y, sigma_x, sigma_y])
 * 
 * with open("grid_pos.json", "w+") as f:
 *     json.dump(pos, f)
 *
 * @endcode
 *
 * 
 */
void 
DiscretizeAdapterPois::readGridPositionFile()
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

        for (int i = 0; i < port_out->data_size; ++i)
        {
            double* pos_ = new double[port_in->data_size];
            double* sigmas_ = new double[port_in->data_size];

            for (int j = 0; j < port_in->data_size; ++j)
            {
                pos_[j] = json_grid_positions[i][j].asDouble();
               
                //put sigmas on the diagonal
                sigmas_[j] = json_grid_positions[i][port_in->data_size + j].asDouble(); 
            }
            grid_positions.insert(std::pair<int, double*>(i, pos_));
            sigmas.insert(std::pair<int, double*>(i, sigmas_));
        }


    }

}

void DiscretizeAdapterPois::readSeedfromNetParams()
{
    std::string search;
    std::ifstream inFile;
    std::string line;
    // int Seed;

    inFile.open("network_params.json");

    if(!inFile){
    std::cout << "Unable to open file" << std::endl;
    exit(1);
    }
    // std::cout << "Enter word to search for: ";
    // std::cin >>search;
    search = "seed";


    size_t pos;
    while(inFile.good())
    {
        getline(inFile,line); // get line from file
        pos = line.find(search); // search
        if(pos != std::string::npos) // string::npos is returned if string is not found
            {
                std::cout <<"Found!";
                std::cout << line << std::endl;
                std::size_t poscolon = line.find_first_of(":");
                // std::cout << poscolon << std::endl;
                std::string str_tmp = line.substr(poscolon);
                // std::cout << str_tmp << std::endl;
                str_tmp.erase(0, 1);
                // std::cout << str_tmp << std::endl;
                std::size_t poscomma = line.find(",");
                // std::cout << poscomma << std::endl;
                if (poscomma != std::string::npos){
                    str_tmp.erase(poscomma-poscolon-1);
                    // std::string Seed = line.substr(1, line.find(":"));
                    // std::cout << str_tmp << std::endl;
                }
                Seed = std::stod(str_tmp);
                std::cout << (Seed) << std::endl;
                break;
            }
    }
    inFile.close();
}