#include "include/classes/Assistant.h"
#include "include/utils.h"
#include "include/const.h"

int main() {
  std::vector<Delivery> test = read_deliveries_file("data/deliveries.txt");
  print_vector(test);

  return 0;
}