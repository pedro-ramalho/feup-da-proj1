#ifndef PLATFORM_H
#define PLATFORM_H

#include <vector>
#include <unordered_map>
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

  /* to be completed */
   
};

#endif