#ifndef ASSISTANT_H
#define ASSISTANT_H

#include <iostream>

class Assistant {
private:
  inline static unsigned int last_id = 0;

  unsigned int id;
	unsigned int max_volume;
	unsigned int max_weight;
  unsigned int cost;
  //possibly int max_time
  
public:

  /* constructor */
  Assistant(unsigned int volume, unsigned int weight, unsigned int cost);

  /* getters */  
  unsigned int get_id() const;
  unsigned int get_cost() const;
  unsigned int get_max_volume() const;
  unsigned int get_max_weight() const;
  static unsigned int get_last_id();

  /* setters */
  void set_weight(unsigned int weight);
  void set_volume(unsigned int volume);
  static void reset_last_id();

  /* operator overloads */
  friend std::ostream& operator<<(std::ostream& os, const Assistant &a);

};

#endif
