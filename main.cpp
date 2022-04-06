#include "include/utils.h"

int main() {
  Assistant assistant(0, 0, 0);
  Assistant assistant2(1, 1, 1);
  std::vector<Assistant> bruh = {assistant, assistant2};
  print_vector(bruh);
  
  return 0;
}