#include <vector>
#include <string>

#include "classes/Assistant.h"
#include "classes/Delivery.h"

std::vector<Assistant> read_assistants_file(const std::string filename);

std::vector<Delivery> read_deliveries_file(const std::string filename);
