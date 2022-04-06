#ifndef ASSISTANT_H
#define ASSISTANT_H

class Assistant {
private:
  inline static int last_id = 0;

  unsigned int id;
  unsigned int cost;
	unsigned int max_volume;
	unsigned int max_weight;
  //possibly int max_time
  
public:

  /* constructor */
  Assistant(unsigned int volume, unsigned int weight, unsigned int cost);

  /* getters */  
  unsigned get_id();
  unsigned get_cost();
  unsigned get_max_volume();
  unsigned get_max_weight();

};

#endif
