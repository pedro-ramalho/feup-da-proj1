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

void Platform::clear() {
  std::cout << "Clearing Platform...\n";
  this->assistants = {};
  this->deliveries = {};
  this->task_assigns.clear();
  this->total_volume = 0;
  this->total_weight = 0;
}

void Platform::load_scenario(unsigned int scenario, unsigned int size) {
  std::string assistants_file = ASSISTANTS_FILE_PREFIX + std::to_string(int(pow(2, size + 6))) + TEXT_FILE_SUFFIX;
  std::string deliveries_file = DELIVERIES_FILE_PREFIX + std::to_string(int(pow(2, size + 6))) + TEXT_FILE_SUFFIX;

  if (size == 10) {
    assistants_file = "data/assistants.txt";
    deliveries_file = "data/deliveries.txt";
  }

  this->assistants = read_assistants_file(assistants_file);
  this->deliveries = read_deliveries_file(deliveries_file);
  
  switch (scenario) {
    case 1: this->minimize_assistants(assistants_file, deliveries_file); break;
    case 2: this->maximize_profits(assistants_file, deliveries_file); break;
    case 3: this->minimize_time(assistants_file, deliveries_file); break;
    default: std::cerr << "That scenario does not exist." << std::endl;
  }
}

void Platform::minimize_assistants(std::string assistants_file, std::string deliveries_file) {
  /* start counter */
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  
  std::sort(this->assistants.begin(), this->assistants.end(), sort_ass_value);
  std::sort(this->deliveries.begin(), this->deliveries.end(), sort_del_value);

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
  double time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
  
  this->print_solution(time_elapsed, assistants_file, deliveries_file);
}

void Platform::maximize_profits(std::string assistants_file, std::string deliveries_file) {
  /* start counter */
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  int profit = 0;

  std::sort(this->assistants.begin(), this->assistants.end(), sort_ass_cost);
  std::sort(this->deliveries.begin(), this->deliveries.end(), sort_del_reward);

  for (const Delivery& delivery : this->deliveries)
    for (Assistant& assistant : this->assistants) {
      if (fits(delivery, assistant)) {
        task_assigns[assistant.get_id()].push_back(delivery.get_id());

        assistant.set_weight(assistant.get_max_weight() - delivery.get_weight());
        assistant.set_volume(assistant.get_max_volume() - delivery.get_volume());
        
        break;
      }
    }

  /* stop counter, calculate time elapsed */
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  double time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
  
  this->print_solution(time_elapsed, assistants_file, deliveries_file);
}

void Platform::minimize_time(std::string assistants_file, std::string deliveries_file) {
  int total_time = 0, curr_index = 0, num_deliveries = 0;

  std::sort(this->deliveries.begin(), this->deliveries.end(), sort_del_time);

  std::cout << "\nDelivery order: ";
  while (true) {
    total_time += this->deliveries[curr_index].get_time();
    num_deliveries++;

    if (total_time > TIME_LIMIT) {
      total_time -= this->deliveries[curr_index].get_time();
      num_deliveries--;
      break;
    }

    std::cout << this->deliveries[curr_index].get_id() << " ";
    curr_index++;
  }
  std::cout << "\n\nTotal time: " << total_time << "/" << TIME_LIMIT << '\n';
  std::cout << "Number of deliveries: " << num_deliveries << std::endl;
}

void Platform::print_solution(double time_elapsed, std::string assistants_file, std::string deliveries_file) {
  int num_deliveries = 0;
  int num_assistants = 0;
  long int total_cost = 0, total_reward = 0;

  this->assistants = read_assistants_file(assistants_file);
  this->deliveries = read_deliveries_file(deliveries_file);

  for (auto it : task_assigns) {
    if (!it.second.empty()) {
      total_cost += this->assistants[it.first].get_cost();
      cout << "Assistant " << it.first << " - deliveries:";
      int carried_weight = 0;
      int carried_volume = 0;
      
      for (const unsigned int& delivery : it.second) {
        num_deliveries++;
        carried_weight += this->deliveries[delivery].get_weight();
        carried_volume += this->deliveries[delivery].get_volume();
        total_reward += this->deliveries[delivery].get_compensation();
        cout << " " << delivery;
      }
      cout << "\ncarried weight: " << carried_weight << "/" << this->assistants[it.first].get_max_weight();
      cout << "\ncarried volume: " << carried_volume << "/" << this->assistants[it.first].get_max_volume();
      cout << "\n\n";
    }
    num_assistants++;
  }
  long int profit = total_reward - total_cost;

  cout << "Time elapsed: " << time_elapsed << std::endl;
  cout << "Number of assistants: " << num_assistants << std::endl;
  cout << "Number of deliveries: " << num_deliveries << std::endl;
  cout << "Profit: " << profit << std::endl;
  cout << "\n\n";
}
