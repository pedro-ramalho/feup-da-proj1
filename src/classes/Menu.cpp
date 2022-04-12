#include "../../include/classes/Menu.h"

Menu::Menu() {
  this->layout = read_menu_file(MENU_FILE);
}

void Menu::run() {
  int option = -1;

  print_vector(this->layout);

  do {
    option = choose_option();
  } while (option == -1);

  if (option == 0)
    exit(0);
  
  this->init_scenario(option);
}

// load the scenario
void Menu::init_scenario(unsigned int scenario) {
  this->platform.load_scenario(scenario);
}
