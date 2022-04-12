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

void Platform::load_scenario(unsigned int scenario) {
  std::string x = "./data/assistants" + std::to_string(scenario) + ".txt";

  this->assistants = read_assistants_file("data/assistants.txt");
  this->deliveries = read_deliveries_file("data/deliveries.txt");
  // this->minimize_assistants();
   this->temp();
}

void Platform::minimize_assistants() {
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
  
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Time passed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl;
  
  this->print_solution();
}

void Platform::temp() {
  /* sort by volume */
  std::sort(this->assistants.begin(), this->assistants.end(), sort_assv);
  std::sort(this->deliveries.begin(), this->deliveries.end(), sort_delv);  

  for (const Delivery& delivery : this->deliveries)
    for (Assistant& assistant : this->assistants)
      if (fits(delivery, assistant)) {
        task_assigns[assistant.get_id()].push_back(delivery.get_id());

        assistant.set_weight(assistant.get_max_weight() - delivery.get_weight());
        assistant.set_volume(assistant.get_max_volume() - delivery.get_volume());
        
        break;
      }

  this->print_solution();
  this->task_assigns.clear();

  /* sort by weight */
  this->assistants = read_assistants_file("data/assistants.txt");
  this->deliveries = read_deliveries_file("data/deliveries.txt");

  std::sort(this->assistants.begin(), this->assistants.end(), sort_assw);
  std::sort(this->deliveries.begin(), this->deliveries.end(), sort_delw);  

  for (const Delivery& delivery : this->deliveries) {
    for (Assistant& assistant : this->assistants)
      if (fits(delivery, assistant)) {
        task_assigns[assistant.get_id()].push_back(delivery.get_id());

        assistant.set_weight(assistant.get_max_weight() - delivery.get_weight());
        assistant.set_volume(assistant.get_max_volume() - delivery.get_volume());
        
        break;
      }
  }
  this->print_solution();
}


// Assistant 1 - deliveries 1, 2, 3...
// carried weight: xx/yy
// carried volume: xx/yy
void Platform::print_solution() {
  int num_deliveries = 0;
  int num_assistants = 0;

  this->assistants = read_assistants_file("data/assistants.txt");
  this->deliveries = read_deliveries_file("data/deliveries.txt");


  for (int i = 0; i < Assistant::get_last_id(); i++) {
    if (!task_assigns[i].empty()) {
      cout << "Assistant " << i << " - deliveries:";
      int carried_weight = 0;
      int carried_volume = 0;
      for (const unsigned int& delivery : task_assigns[i]) {
        num_deliveries++;
        carried_weight += this->deliveries[delivery].get_weight();
        carried_volume += this->deliveries[delivery].get_volume();
        std::cout << " " << delivery;
      }
      cout << "\ncarried weight: " << carried_weight << "/" << this->assistants[i].get_max_weight();
      cout << "\ncarried volume: " << carried_volume << "/" << this->assistants[i].get_max_volume();
      cout << "\n\n";
    }
  }

  for (auto i : task_assigns)
    if (!i.second.empty())
      num_assistants++;

  cout << "Number of assistants: " << num_assistants << std::endl;
  cout << "Number of deliveries: " << num_deliveries << std::endl;
  cout << "\n\n";
}
