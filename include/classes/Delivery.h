#ifndef DELIVERY_H
#define DELIVERY_H

#include <iostream>

class Delivery {
private:
  /**
   * @brief last id used by a Delivery object
   * 
   */
  inline static unsigned int last_id = 0;

  /**
   * @brief id used to identify a Delivery
   * 
   */
  unsigned int id;

  /**
   * @brief volume occupied by a Delivery
   * 
   */
  unsigned int volume;

  /**
   * @brief weight occupied by a Delivery
   * 
   */
  unsigned int weight;

  /**
   * @brief compensation paid by the supplier to the company
   * 
   */
  unsigned int compensation;

  /**
   * @brief delivery time for expresso deliveries
   * 
   */
  unsigned int time;

public:
  
  /**
   * @brief Construct a new Delivery object
   * 
   * @param volume 
   * @param weight 
   * @param compensation 
   * @param time 
   */
  Delivery(unsigned int volume, unsigned int weight, unsigned int compensation, unsigned int time);
  
  /**
   * @brief Get the id of a Delivery
   * 
   * @return unsigned int 
   */
  unsigned int get_id() const;

  /**
   * @brief Get the volume of a Delivery
   * 
   * @return unsigned int 
   */
  unsigned int get_volume() const;

  /**
   * @brief Get the weight of a Delivery
   * 
   * @return unsigned int 
   */
  unsigned int get_weight() const;

  /**
   * @brief Get the compensation of a Delivery
   * 
   * @return unsigned int 
   */
  unsigned int get_compensation() const;

  /**
   * @brief Get the delivery time of a Delivery
   * 
   * @return unsigned int 
   */
  unsigned int get_time() const;

  /**
   * @brief Resets the last id used by a Delivery object
   * 
   */
  static void reset_last_id();
  
  /**
   * @brief Prints a Delivery object to the standard output
   * 
   * @param os 
   * @param a 
   * @return std::ostream& 
   */
  friend std::ostream& operator<<(std::ostream& os, const Delivery &a);
};

#endif