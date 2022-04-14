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

/*
  C(n, k) n = deliveries.size();
  for loop
    combinations = C(n, k)
    k++
    best_set = {1, 4, 5}
    erase(1, 4, 5)

  for every assistant:
    combs = get_all_combinations()
  
    best_comb = choose_best(combs)

    task[assistant] = best_comb
*/



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
    assistant.set_value(assistant.get_max_volume() + assistant.get_max_weight()); 
    

  std::sort(this->assistants.begin(), assistants.end(), sort_ass_value);
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
  long int time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
  
  this->print_solution(time_elapsed, assistants_file, deliveries_file);
}

void Platform::maximize_profits(std::string assistants_file, std::string deliveries_file) {
  
  /* BASIC SOLUTION (first-fit decreasing)

    sort(assistants by cost, ascending order)
    sort(deliveries by reward, descending order)

    for delivery in deliveries
      for assistant in assistants
        if fits(delivery, assistant)
          task[assistant].add(delivery)
  */

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

void Platform::print_solution(long int time_elapsed, std::string assistants_file, std::string deliveries_file) {
  int num_deliveries = 0;
  int num_assistants = 0;

  this->assistants = read_assistants_file(assistants_file);
  this->deliveries = read_deliveries_file(deliveries_file);

  for (auto it : task_assigns) {
    if (!it.second.empty()) {
      // cout << "Assistant " << it.first << " - deliveries:";
      int carried_weight = 0;
      int carried_volume = 0;
      
      for (const unsigned int& delivery : it.second) {
        num_deliveries++;
        carried_weight += this->deliveries[delivery].get_weight();
        carried_volume += this->deliveries[delivery].get_volume();
        // cout << " " << delivery;
      }
      //cout << "\ncarried weight: " << carried_weight << "/" << this->assistants[it.first].get_max_weight();
      //cout << "\ncarried volume: " << carried_volume << "/" << this->assistants[it.first].get_max_volume();
      //cout << "\n\n";
    }
    num_assistants++;
  }

  cout << "Time elapsed: " << time_elapsed << std::endl;
  cout << "Number of assistants: " << num_assistants << std::endl;
  cout << "Number of deliveries: " << num_deliveries << std::endl;
  cout << "\n\n";
}
