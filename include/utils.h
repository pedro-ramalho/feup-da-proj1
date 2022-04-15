#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#include <map>

#include "classes/Assistant.h"
#include "classes/Delivery.h"
#include "const.h"



/**
 * @brief Prints the contents of a vector to the standard output
 * 
 * @tparam T 
 * @param vector 
 */
template<typename T>
void print_vector(std::vector<T> vector) {
  std::for_each(vector.begin(), vector.end(), 
  [](const T& elem) {
    std::cout << elem << std::endl;
  });
}


/**
 * @brief Checks if a given string is made up of digits only
 * 
 * @param str 
 * @return true if there are only digits in the string
 * @return false otherwise
 */
bool is_integer(std::string& str);

/**
 * @brief Requests the user for an integer input until the input is valid
 * 
 * @return int
 */
int choose_option();


/**
 * @brief Reads Assistants information from a text file
 * 
 * @param filename name of the file to read information from
 * @return std::vector<Assistant> set of Assistants
 */
std::vector<Assistant> read_assistants_file(const std::string filename);

/**
 * @brief Reads Deliveries information from a text file
 * 
 * @param filename name of the file to read information from
 * @return std::vector<Delivery> set of Deliveries
 */
std::vector<Delivery> read_deliveries_file(const std::string filename);

/**
 * @brief Reads information from a text file
 * 
 * @param filename name of the file to read information from
 * @return std::vector<std::string> set of strings making up the file
 */
std::vector<std::string> read_menu_file(const std::string filename);

/**
 * @brief Auxiliary function used to sort Assistants in descending order of value
 * 
 * @param a1 Assistant 1
 * @param a2 Assistant 2
 * @return true if the Assistant 1 is more valuable (capable to carry a larger number of deliveries) than Assistant 2
 * @return false otherwise
 */
bool sort_ass_value(Assistant a1, Assistant a2);

/**
 * @brief Auxiliary function used to sort Assistants in descending order of cost
 * 
 * @param a1 Assistant 1
 * @param a2 Assistant 2
 * @return true if the Assistant 1 costs more than Assistant 2
 * @return false otherwise
 */
bool sort_ass_cost(Assistant a1, Assistant a2);

/**
 * @brief Auxiliary function used to sort Deliveries in descending order of value
 * 
 * @param d1 Delivery 1
 * @param d2 Delivery 2
 * @return true if Delivery 1 is more valuable (occupies less space) than Delivery 2
 * @return false otherwise
 */
bool sort_del_value(Delivery d1, Delivery d2);

/**
 * @brief Auxiliary function used to sort Deliveries in ascending order of time
 * 
 * @param d1 Delivery 1
 * @param d2 Delivery 2
 * @return true if Delivery 1 takes less time to deliver than Delivery 2
 * @return false otherwise
 */
bool sort_del_time(Delivery d1, Delivery d2);

/**
 * @brief Auxiliary function used to sort Deliveries in descending order of reward
 * 
 * @param d1 Delivery 1
 * @param d2 Delivery 2
 * @return true if Delivery 1 has a larger reward (a bigger ration between cost and size) than Delivery 2
 * @return false otherwise
 */
bool sort_del_reward(Delivery d1, Delivery d2);

/**
 * @brief Checks if a delivery fits into an Assistant's vehicle
 * 
 * @param delivery 
 * @param assistant 
 * @return true if the assistant has enough space to carry the delivery
 * @return false otherwise
 */
bool fits(Delivery delivery, Assistant assistant);

/**
 * @brief Generates a text file containing information about 2^exponent Assistants and (9 * 2^n) Deliveries
 * 
 * @param exponent 
 */
void generate_data(int exponent);