#ifndef DELIVERY_H
#define DELIVERY_H

#include <iostream>

class Delivery {
private:
  inline static unsigned int last_id = 0;

  unsigned int id;
  unsigned int volume;
  unsigned int weight;
  unsigned int compensation;
  unsigned int time;
  //possibly bool express;
  //possibly unsigned int num_days;
  /* to be completed */

public:
  
  /* constructor */
  Delivery(unsigned int volume, unsigned int weight, unsigned int compensation, unsigned int time);
  
  /* getters */
  unsigned int get_id() const;
  unsigned int get_volume() const;
  unsigned int get_weight() const;
  unsigned int get_compensation() const;
  unsigned int get_time() const;

  friend std::ostream& operator<<(std::ostream& os, const Delivery &a);
  /* to be completed */
};

#endif