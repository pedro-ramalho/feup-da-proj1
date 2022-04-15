#include <string>

/** @defgroup Constants Constants
 * @{
 * 
 * Constants used throughout the project
 */


/* file access */

#define ASSISTANTS_FILE_PREFIX "data/assistants" /**< @brief prefix to access the assistants file */
#define DELIVERIES_FILE_PREFIX "data/deliveries" /**< @brief prefix to access the deliveries file */
#define TEXT_FILE_SUFFIX       ".txt"            /**< @brief text file suffix */
#define MENU_FILE              "data/menu.txt"   /**< @brief access the menu file */
#define SIZES_FILE             "data/sizes.txt"  /**< @brief access the sizes file */


/* file headers */

#define ASSISTANTS_HEADER "volMax pesoMax custo\n" /**< @brief assistans file header */
#define DELIVERIES_HEADER "volume peso recompensa duração(s)\n" /**< @brief deliveries file header */


/* time limits */

#define TIME_LIMIT 28800 /**< @brief time limit for expresso deliveries */

/**@}*/