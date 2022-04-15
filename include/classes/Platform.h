#ifndef PLATFORM_H
#define PLATFORM_H

#include <unordered_map>
#include <vector>
#include <list>
#include <string>

#include "Assistant.h"
#include "Delivery.h"
#include "../utils.h"
#include "../const.h"


class Platform {
private:

  /**
   * @brief assistants who are signed in the Platform
   * 
   */
  std::vector<Assistant> assistants;

  /**
   * @brief set of deliveries given by suppliers
   * 
   */
  std::vector<Delivery> deliveries;

  /**
   * @brief assign an Assistant with a given id to a list of Delivery id's
   * 
   */
  std::unordered_map<unsigned, std::list<unsigned>> task_assigns;
  
  /**
   * @brief Prints the distribution between Assistants and Deliveries to the standard output after running a scenario
   * 
   * @param time_elapsed duration of the algorithm
   * @param assistants_file file to read assistants information from
   * @param deliveries_file file to read deliveries information from
   */
  void print_solution(double time_elapsed, std::string assistants_file, std::string deliveries_file);

public:

  /**
   * @brief Construct a new Platform object
   * 
   */
  Platform();

  /**
   * @brief Get the set of Assistants
   * 
   * @return std::vector<Assistant> 
   */
  std::vector<Assistant> get_assistants() const;

  /**
   * @brief Get the set of Deliveries
   * 
   * @return std::vector<Delivery> 
   */
  std::vector<Delivery>  get_deliveries() const;

  /**
   * @brief Load a specific scenario
   * 
   * @param scenario scenario input by the user, can be 1, 2 or 3
   * @param size size of input
   */
  void load_scenario(unsigned int scenario, unsigned int size);

  /**
   * @brief Minimizes the amount of Assistants needed to carry a set of Deliveries
   * 
   * @param assistants_file file to read assistants information from
   * @param deliveries_file file to read deliveries information from
   */
  void minimize_assistants(std::string assistants_file, std::string deliveries_file);

  /**
   * @brief Maximizes the profits of the company, given a set of Assistants and Deliveries
   * 
   * @param assistants_file file to read assistants information from
   * @param deliveries_file file to read deliveries information from
   */
  void maximize_profits(std::string assistants_file, std::string deliveries_file);

  /**
   * @brief Minimizes the time of delivery for expresso deliveries
   * 
   * @param assistants_file file to read assistants information from
   * @param deliveries_file file to read deliveries information from
   */
  void minimize_time(std::string assistants_file, std::string deliveries_file);

  /**
   * @brief Clears the information stored on the Platform
   * 
   */
  void clear();
};

#endif
