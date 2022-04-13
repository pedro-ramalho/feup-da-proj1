#include "../../include/classes/Menu.h"

Menu::Menu() {
  this->layout = read_menu_file(MENU_FILE);
  this->sizes = read_menu_file(SIZES_FILE);
}

void Menu::run() {
  int option = -1;

  print_vector(this->layout);

  do {
    option = choose_option();
  } while (option == -1);

  if (option == 0)
    exit(0);
  
  this->ask_size(option);
}

void Menu::ask_size(unsigned int scenario) {
  int option = -1;
  
  print_vector(this->sizes);

  do {
    option = choose_option();
  } while (option < 0 || option > 10);

  if (option == 0)
    exit(0);
  
  this->init_scenario(scenario, option);
}

// load the scenario
void Menu::init_scenario(unsigned int scenario, unsigned int size) {
  this->platform.load_scenario(scenario, size);
}
