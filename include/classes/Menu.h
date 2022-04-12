#ifndef MENU_H
#define MENU_H

#include "Platform.h"
#include "../utils.h"
#include "../const.h"

class Menu {
private:
  Platform platform;
  std::vector<std::string> layout;
  /* to be completed */

public:

  /* constructor */
  Menu();

  /* other methods */
  void run();

  void init_scenario(unsigned int scenario); // opt 3, 4, 5
};

#endif