#ifndef DELIVERY_H
#define DELIVERY_H

class Delivery {
private:
  inline static unsigned int last_id = 0;

  unsigned int id;
  unsigned int volume;
  unsigned int weight;
  unsigned int compensation;
  unsigned int delivery_time;
  //possibly bool express;
  //possibly unsigned int num_days;
  /* to be completed */

public:
  
  /* constructor */
  Delivery(unsigned int volume, unsigned int weight, unsigned int compensation, unsigned int delivery_time);
  
  /* getters */
  unsigned int get_id();
  unsigned int get_volume();
  unsigned int get_weight();
  unsigned int get_compensation();
  unsigned int get_delivery_time();

  /* to be completed */
};

#endif