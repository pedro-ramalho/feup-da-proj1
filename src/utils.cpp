#include "../include/utils.h"

std::vector<std::string> read_menu_file(const std::string filename) {
  std::vector<std::string> content;
  std::ifstream file;
  std::string line;
  
  file.open(filename);

  while (getline(file, line))
    content.push_back(line);

  file.close();

  return content;
}

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

bool is_integer(std::string& str) {
  int size = str.size();

  for (int i = 0; i < size; i++)
    if (!isdigit(str[i]))
      return false;

  return true;
}

int choose_option() {
  std::string option = "";

  while (true) {
    std::cout << "\nChoose an option:" << std::endl;
    std::cout << ">> ";
    std::getline(std::cin, option);
    
    if (std::cin.eof()) {
      std::cout << '\n';
      std::cin.clear();
      return 0;
    }

    if (is_integer(option))
      return stoi(option);
    else {
      std::cerr << "Error: invalid input type!" << std::endl;
      std::cout << '\n';
      std::cin.clear();
    }
  }
  
  return -1;
}
