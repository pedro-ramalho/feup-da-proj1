#include "include/utils.h"

int main() {
  std::vector<Assistant> bruh = read_assistants_file("data/assistants.txt");
  std::vector<Delivery> bruh2 = read_deliveries_file("data/deliveries.txt");
  print_vector(bruh2);
  
  return 0;
}