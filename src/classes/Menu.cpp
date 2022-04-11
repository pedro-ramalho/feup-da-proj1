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

  /*
  switch (option) {
    case 0: exit(0);
    case 1: ...
    case 2: ...
    case 3: ...
    case 4: ...
    case 5: ...
    case 6: ...
    case 7: ...
    default: ...
  }
  */
}