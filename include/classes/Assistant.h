#ifndef ASSISTANT_H
#define ASSISTANT_H

#include <iostream>

class Assistant {
private:
  /**
   * @brief last id used by an Assistant object
   * 
   */
  inline static unsigned int last_id = 0;

  /**
   * @brief id used to identify an Assistant
   * 
   */
  unsigned int id;

  /**
   * @brief maximum volume of an Assistant's vehicle
   * 
   */
	unsigned int max_volume;

  /**
   * @brief maximum weight of an Assistant's weight
   * 
   */
	unsigned int max_weight;

  /**
   * @brief cost payed by the company for an Assistant's service
   * 
   */
  unsigned int cost;
  
public:

  /**
   * @brief Construct a new Assistant object
   * 
   * @param volume maximum volume of the Assistant's vehicle
   * @param weight maximum weight of the Assistant's vehicle
   * @param cost cost paid by the company for the Assistant's service
   */
  Assistant(unsigned int volume, unsigned int weight, unsigned int cost);

  /**
   * @brief Get the id of an Assistant
   * 
   * @return unsigned int 
   */
  unsigned int get_id() const;

  /**
   * @brief Get the cost of an Assistant
   * 
   * @return unsigned int 
   */
  unsigned int get_cost() const;

  /**
   * @brief Get the max volume of an Assistant
   * 
   * @return unsigned int 
   */
  unsigned int get_max_volume() const;

  /**
   * @brief Get the max weight of an Assistant
   * 
   * @return unsigned int 
   */
  unsigned int get_max_weight() const;

  /**
   * @brief Get the last id of an Assistant
   * 
   * @return unsigned int 
   */
  static unsigned int get_last_id();

  /**
   * @brief Set the weight of an Assistant
   * 
   * @param weight 
   */
  void set_weight(unsigned int weight);

  /**
   * @brief Set the volume of an Assistant
   * 
   * @param volume 
   */
  void set_volume(unsigned int volume);

  /**
   * @brief Resets the last id used by an Assistant object
   * 
   */
  static void reset_last_id();

  /**
   * @brief Print an Assistant to the standard output
   * 
   * @param os 
   * @param a 
   * @return std::ostream& 
   */
  friend std::ostream& operator<<(std::ostream& os, const Assistant &a);
};

#endif
