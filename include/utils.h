#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>

#include "classes/Assistant.h"
#include "classes/Delivery.h"

/* printing functions */

template<typename T>
void print_vector(std::vector<T> vector) {
  std::for_each(vector.begin(), vector.end(), 
  [](const T& elem) {
    std::cout << elem << std::endl;
  });
}


/* input validation */

bool is_integer(std::string& str);
int choose_option();


/* fetch data from a text file and return it's contents */

std::vector<Assistant> read_assistants_file(const std::string filename);
std::vector<Delivery> read_deliveries_file(const std::string filename);
std::vector<std::string> read_menu_file(const std::string filename);