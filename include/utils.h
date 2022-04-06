#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>

#include "classes/Assistant.h"
#include "classes/Delivery.h"


template<typename T>
void print_vector(std::vector<T> vector) {
  std::for_each(vector.begin(), vector.end(), 
  [](const T& elem) {
    std::cout << elem << std::endl;
  });
}


std::vector<Assistant> read_assistants_file(const std::string filename);

std::vector<Delivery> read_deliveries_file(const std::string filename);
