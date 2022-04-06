#include "../../include/classes/Delivery.h"

Delivery::Delivery(unsigned int volume, unsigned int weight, unsigned int compensation, unsigned int time) {
  this->volume = volume;
  this->weight = weight;
  this->compensation = compensation;
  this->time = time;
  this->id = Delivery::last_id;
  
  Delivery::last_id++;
}

unsigned int Delivery::get_id() const {
  return this->id;
}

unsigned int Delivery::get_volume() const {
  return this->volume;
}

unsigned int Delivery::get_weight() const {
  return this->weight;
}

unsigned int Delivery::get_compensation() const {
  return this->compensation;
}

unsigned int Delivery::get_time() const {
  return this->time;
}

std::ostream & operator << (std::ostream &os, const Delivery &a) {
  os << "Delivery: id = " << a.get_id() << ", volume = " << a.get_volume() << ", weight = " << a.get_weight() << ", compensation = " << a.get_compensation() << ", time = " << a.get_time() << ".";
  return os;
}