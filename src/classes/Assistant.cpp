#include "../../include/classes/Assistant.h"

Assistant::Assistant(unsigned int volume, unsigned int weight, unsigned int cost) {
  this->max_volume = volume;
  this->max_weight = weight;
  this->cost = cost;
  this->id = Assistant::last_id;

  Assistant::last_id++;
}

unsigned int Assistant::get_max_volume() const {
  return this->max_volume;
}

unsigned int Assistant::get_max_weight() const {
  return this->max_weight;
}

unsigned int Assistant::get_cost() const {
  return this->cost;
}

unsigned int Assistant::get_id() const {
  return this->id;
}


std::ostream & operator << (std::ostream &os, const Assistant &a) {
    os << "Assistant: id = " << a.get_id() << ", volume = " << a.get_max_volume() << ", weight = " << a.get_max_weight() << ", cost = " << a.get_cost() << ".";
    return os;
}