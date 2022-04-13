#include "../../include/classes/Platform.h"

using std::unordered_map;
using std::cout;

Platform::Platform() {
  this->assistants = {};
  this->deliveries = {};
}

std::vector<Assistant> Platform::get_assistants() const {
  return this->assistants;
}

std::vector<Delivery> Platform::get_deliveries() const {
  return this->deliveries;
}

void Platform::load_scenario(unsigned int scenario, unsigned int size) {
  const std::string assistants_file = ASSISTANTS_FILE_PREFIX + std::to_string(int(pow(2, size + 7))) + TEXT_FILE_SUFFIX;
  const std::string deliveries_file = DELIVERIES_FILE_PREFIX + std::to_string(int(pow(2, size + 7))) + TEXT_FILE_SUFFIX;

  this->assistants = read_assistants_file(assistants_file);
  this->deliveries = read_deliveries_file(deliveries_file);
  
  switch (scenario) {
    case 1: this->minimize_assistants(assistants_file, deliveries_file); break;
    // case 2: this->maximize_profits(); break;
    // case 3: this->minimize_time(); break;
    default: std::cerr << "That scenario does not exist." << std::endl;
  }
}

void Platform::minimize_assistants(std::string assistants_file, std::string deliveries_file) {
  /* start counter */
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  this->total_volume = 0;
  this->total_weight = 0;

  for (Delivery delivery : this->deliveries) {
    total_weight += delivery.get_weight();
    total_volume += delivery.get_volume();
  }

  for (Assistant assistant : this->assistants)
    assistant.set_value(std::min(assistant.get_max_weight() / this->total_weight, assistant.get_max_volume() / this->total_volume));

  std::sort(this->assistants.begin(), assistants.end(), sort_ass_value);
  
  std::sort(this->deliveries.begin(), this->deliveries.end(), [&](Delivery d1, Delivery d2) {
    return std::max(d1.get_weight() / total_weight, d1.get_volume() / total_volume) > 
           std::max(d2.get_weight() / total_weight, d2.get_volume() / total_volume);
  });
  
  for (const Delivery& delivery : this->deliveries) 
    for (Assistant& assistant : this->assistants) 
      if (fits(delivery, assistant)) {
        task_assigns[assistant.get_id()].push_back(delivery.get_id());

        assistant.set_weight(assistant.get_max_weight() - delivery.get_weight());
        assistant.set_volume(assistant.get_max_volume() - delivery.get_volume());
        
        break;
      }
  
  /* stop counter, calculate time elapsed */
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  long int time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
  
  this->print_solution(time_elapsed, assistants_file, deliveries_file);
}

void Platform::print_solution(long int time_elapsed, std::string assistants_file, std::string deliveries_file) {
  int num_deliveries = 0;
  int num_assistants = 0;

  this->assistants = read_assistants_file(assistants_file);
  this->deliveries = read_deliveries_file(deliveries_file);

  for (auto it : task_assigns) {
    if (!it.second.empty()) {
      cout << "Assistant " << it.first << " - deliveries:";
      int carried_weight = 0;
      int carried_volume = 0;
      
      for (const unsigned int& delivery : it.second) {
        num_deliveries++;
        carried_weight += this->deliveries[delivery].get_weight();
        carried_volume += this->deliveries[delivery].get_volume();
        cout << " " << delivery;
      }
      cout << "\ncarried weight: " << carried_weight << "/" << this->assistants[it.first].get_max_weight();
      cout << "\ncarried volume: " << carried_volume << "/" << this->assistants[it.first].get_max_volume();
      cout << "\n\n";
    }
    num_assistants++;
  }

  cout << "Time elapsed: " << time_elapsed << std::endl;
  cout << "Number of assistants: " << num_assistants << std::endl;
  cout << "Number of deliveries: " << num_deliveries << std::endl;
  cout << "\n\n";
}
