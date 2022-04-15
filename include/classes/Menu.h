#ifndef MENU_H
#define MENU_H

#include "Platform.h"

class Menu {
private:
  /**
   * @brief Platform being managed by the user
   * 
   */
  Platform platform;

  /**
   * @brief Menu layout
   * 
   */
  std::vector<std::string> layout;

  /**
   * @brief Different input sizes the available to the user
   * 
   */
  std::vector<std::string> sizes;

public:

  /**
   * @brief Construct a new Menu object
   * 
   */
  Menu();

  /**
   * @brief Runs the Menu
   * 
   */
  void run();

  /**
   * @brief Initializes the scenario input by the user
   * 
   * @param scenario 
   * @param size 
   */
  void init_scenario(unsigned int scenario, unsigned int size);

  /**
   * @brief Requests the user an input size
   * 
   * @param scenario 
   */
  void ask_size(unsigned int scenario); 
};

#endif