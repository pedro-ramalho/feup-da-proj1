#include "../../include/classes/Platform.h"

Platform::Platform() {
  this->assistants = {};
  this->deliveries = {};
}

std::vector<Assistant> Platform::get_assistants() const {
  return this->assistants;
}

std::vector<Delivery> Platform::get_deliveries() const {
  return this->deliveries;
}

