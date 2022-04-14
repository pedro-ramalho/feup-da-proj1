#ifndef PLATFORM_H
#define PLATFORM_H

#include <unordered_map>
#include <vector>
#include <list>
#include <string>

#include "Assistant.h"
#include "Delivery.h"
#include "../utils.h"
#include "../const.h"


class Platform {
private:
  unsigned int total_weight;
  unsigned int total_volume;

  std::vector<Assistant> assistants;
  std::vector<Delivery> deliveries;

  std::unordered_map<unsigned, std::list<unsigned>> task_assigns;
  
  void find_set_backtrack(Assistant assistant, std::vector<Delivery> deliveries, 
  std::vector<Delivery> curr_sol, std::vector<Delivery> best, unsigned int curr_idx, unsigned int size);
  void print_solution(long int time_elapsed, std::string assistants_file, std::string deliveries_file);
  /* to be completed */
public:

  /* constructor */
  Platform();

  /* getters */
  std::vector<Assistant> get_assistants() const;
  std::vector<Delivery>  get_deliveries() const;

  /* other functions */
  void load_scenario(unsigned int scenario, unsigned int size);

  /* algorithms & optimizations */
  void minimize_assistants(std::string assistants_file, std::string deliveries_file);
  void maximize_profits(std::string assistants_file, std::string deliveries_file);
  void minimize_time(std::string assistants_file, std::string deliveries_file);

  /* print functions */
  /* to be completed */
};

#endif
