#include "../include/utils.h"

std::vector<Assistant> read_assistants_file(const std::string filename) {
  unsigned short data_size;
  unsigned int volume, weight, cost;

  std::ifstream file;
  std::string line;
  std::vector<Assistant> assistants;

  file.open(filename);
  
  if (!file.is_open()) {
      std::cerr << "Could not open Assistants file." << std::endl;
      std::cin.get();
    
      exit(1); 
  }

  // fetch number of elements
  std::getline(file, line); 
  data_size = stoi(line);
  assistants.reserve(data_size);

  // ignore header
  std::getline(file, line); 

  // iterate through file and parse lines
  while (getline(file, line)) {
    std::stringstream parser(line);
    parser >> volume >> weight >> cost;
    
    assistants.emplace_back(volume, weight, cost);
  }
  
  return assistants;
}

std::vector<Delivery> read_deliveries_file(const std::string filename) {
  unsigned short data_size;
  unsigned int volume, weight, compensation, time;

  std::ifstream file;
  std::string line;
  std::vector<Delivery> deliveries;

  file.open(filename);
  
  if (!file.is_open()) {
      std::cerr << "Could not open Delivery file." << std::endl;
      std::cin.get();
    
      exit(1); 
  }

  // fetch number of elements
  std::getline(file, line); 
  data_size = stoi(line);
  deliveries.reserve(data_size);

  // ignore header
  std::getline(file, line); 

  // iterate through file and parse lines
  while (getline(file, line)) {
    std::stringstream parser(line);
    parser >> volume >> weight >> compensation >> time;

    deliveries.emplace_back(volume, weight, compensation, time);
  }
  
  return deliveries;
}
