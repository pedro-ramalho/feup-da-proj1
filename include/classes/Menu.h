#ifndef MENU_H
#define MENU_H

#include "Platform.h"

class Menu {
private:
  Platform platform;
  std::vector<std::string> layout;
  std::vector<std::string> sizes;
  /* to be completed */

public:

  /* constructor */
  Menu();

  /* other methods */
  void run();
  void init_scenario(unsigned int scenario, unsigned int size);
  void ask_size(unsigned int scenario); 
};

#endif