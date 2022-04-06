#ifndef PLATFORM_H
#define PLATFORM_H

#include <unordered_map>
#include <vector>
#include <list>
#include <string>

#include "Assistant.h"
#include "Delivery.h"


class Platform {
private:
  std::vector<Assistant> assistants;
  std::vector<Delivery> deliveries;

  std::unordered_map<unsigned, std::list<unsigned>> task_assigns;
  
  /* to be completed */
public:

  /* constructor */
  Platform();

  /* getters */
  std::vector<Assistant> get_assistants() const;
  std::vector<Delivery> get_deliveries() const;

  /* other functions */
  void load_scenario(unsigned int scenario);

  /* algorithms & optimizations */
  
  /* print functions */

  /* to be completed */
};

#endif
