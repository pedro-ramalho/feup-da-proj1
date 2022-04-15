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

void Assistant::set_weight(unsigned int weight) {
  this->max_weight = weight;
}

void Assistant::set_volume(unsigned int volume) {
  this->max_volume = volume;
}

unsigned int Assistant::get_last_id() {
  return Assistant::last_id;
}

void Assistant::reset_last_id() {
  Assistant::last_id = 0;
}

std::ostream & operator << (std::ostream &os, const Assistant &a) {
  os << "Assistant " << a.get_id() << "\n> Volume: " << a.get_max_volume() << "\n> Weight: " << a.get_max_weight() << "\n> Cost: " << a.get_cost() << "\n\n";
  return os;
}