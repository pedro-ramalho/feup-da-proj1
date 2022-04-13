#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <ctime>
#include <random>

#include "classes/Assistant.h"
#include "classes/Delivery.h"
#include "const.h"



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


/* sorting functions */

bool sort_ass_value(Assistant a1, Assistant a2);


/* verify if a delivery fits inside a vehicle */

bool fits(Delivery delivery, Assistant assistant);


/* data generation */

void generate_data(int exponent);