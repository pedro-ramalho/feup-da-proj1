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
  
  void print_solution();
  /* to be completed */
public:

  /* constructor */
  Platform();

  /* getters */
  std::vector<Assistant> get_assistants() const;
  std::vector<Delivery>  get_deliveries() const;

  /* other functions */
  void load_scenario(unsigned int scenario);

  /* algorithms & optimizations */
  void minimize_assistants();
  void maximize_profits();
  void minimize_time();
  void temp();

  /* print functions */
  /* to be completed */
};

#endif
