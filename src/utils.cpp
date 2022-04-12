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

  // std::cout << "filename: " << filename << std::endl;

  std::ifstream file;
  std::string line;
  std::vector<Assistant> assistants;

  Assistant::reset_last_id();
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

  Delivery::reset_last_id();

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


bool sort_delw(Delivery d1, Delivery d2) {
  if (d1.get_weight() == d2.get_weight())
    return d1.get_volume() > d2.get_volume();
  
  return d1.get_weight() > d2.get_weight();
}

bool sort_delv(Delivery d1, Delivery d2) {
  if (d1.get_volume() == d2.get_volume())
    return d1.get_weight() > d2.get_weight();

  return d1.get_volume() > d2.get_volume();
}

bool sort_assw(Assistant a1, Assistant a2) {
  if (a1.get_max_weight() == a2.get_max_weight())
    return a1.get_max_volume() > a2.get_max_volume();
  
  return a1.get_max_weight() > a2.get_max_weight();
}

bool sort_assv(Assistant a1, Assistant a2) {
  if (a1.get_max_volume() == a2.get_max_volume())
    return a1.get_max_weight() > a2.get_max_weight();
  
  return a1.get_max_volume() > a2.get_max_volume();
}

bool sort_ass_value(Assistant a1, Assistant a2) {
  return a1.get_value() > a2.get_value();
}

bool fits(Delivery delivery, Assistant assistant) {
  return assistant.get_max_volume() >= delivery.get_volume() && assistant.get_max_weight() >= delivery.get_weight();
}