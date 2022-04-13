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

bool sort_ass_value(Assistant a1, Assistant a2) {
  return a1.get_value() > a2.get_value();
}

bool fits(Delivery delivery, Assistant assistant) {
  return assistant.get_max_volume() >= delivery.get_volume() 
      && assistant.get_max_weight() >= delivery.get_weight();
}

void generate_data(int exponent) {
  int num_assistants = pow(2, exponent);
  int num_deliveries = 9 * num_assistants; // this ratio was based on the original dataset (50 assistants to 450 deliveries)
  
  int volume, weight, reward, cost, time;

  /* specify paths */
  std::string assistants_file = "data/assistants" + std::to_string(num_assistants) + ".txt";
  std::string deliveries_file = "data/deliveries" + std::to_string(num_assistants) + ".txt";

  std::ofstream f_ass, f_del;

  /* generate assistants data */
  f_ass.open(assistants_file);

  f_ass << num_assistants << '\n';
  f_ass << ASSISTANTS_HEADER; // write the header

  srand(std::time(NULL));

  for (int n = 0; n < num_assistants; n++) {
    volume = 250 + rand() % ((400 + 1) - 250);
    weight = 250 + rand() % ((400 + 1) - 250);
    cost = 13000 + rand() % ((1700 + 1) - 13000);
    f_ass << volume << " " << weight << " " << cost << '\n';
  }

  f_ass.close();

  
  /* generate deliveries data */
  f_del.open(deliveries_file);

  f_del << num_deliveries << '\n';
  f_del << DELIVERIES_HEADER;

  srand(std::time(NULL));

  for (int n = 0; n < num_deliveries; n++) {
    volume = 1 + rand() % ((30 + 1) - 1);
    weight = 1 + rand() % ((30 + 1) - 1);
    reward = 200 + rand() % ((2000 + 1) - 200);
    time = 100 + rand() % ((1100 + 1) - 100);
    f_del << volume << " " << weight << " " << reward << " " << time << " " << '\n';
  }

  f_del.close();
}
