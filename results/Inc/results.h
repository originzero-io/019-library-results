/*
 * results.h
 *
 *  Created on: Dec 12, 2022
 *      Author: fatih
 */

#ifndef RESULTS_H_
#define RESULTS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Macro to check if a result value corresponds to an error.
 * @param[in] v The result value to check.
 * @return True if the value represents an error, False otherwise.
 */
#define RESULT_IS_ERROR(v) (v < 0)

/**
 * @brief Macro to check if a result value corresponds to a success state.
 * @param[in] v The result value to check.
 * @return True if the value represents a success state, False otherwise.
 */
#define RESULT_IS_SUCCESS(v) (v > 0)

/**
 * @brief Maximum number of error log entries in the queue.
 *
 * This constant defines the maximum number of error log entries that can be stored in the error log queue.
 * It determines the size of the circular buffer used to store error information.
 */
#define RESULT_ERROR_BUFFER_COUNT 10


/* @formatter:off */
/**
 * @brief Enumeration of possible operation results and states.
 */
typedef enum results_enum
{
    /* SUCCESS */
    RESULT_SUCCESS = 1,              /**< Operation was successful. */
    RESULT_CONNECTED,                /**< Connected successfully. */
    RESULT_DISCONNECTED,             /**< Disconnected successfully. */
    RESULT_PACKED,                   /**< Data packed successfully. */

    /* ERRORS */
    RESULT_ERR_UNKNOWN = -127,       /**< Unknown error. */
    RESULT_ERR_HEAP_MEM,             /**< Heap memory allocation error. */
    RESULT_ERR_TIMEOUT,              /**< The operation timed out. */
    RESULT_ERR_RECEIVE_TIMEOUT,      /**< Receive operation timed out. */
    RESULT_ERR_SIZE,                 /**< Size error. */
    RESULT_ERR_NULL,                 /**< Function parameters or variables are null. */
    RESULT_ERR_CRC,                  /**< CRC error. */
    RESULT_ERR_LEN,                  /**< Length error. */
    RESULT_ERR_CHECKSUM,             /**< Checksum error. */
    RESULT_ERR_QUIUE,                /**< Queue added error. */
    RESULT_ERR_NOTFOUND,             /**< Search result not found. */
    RESULT_ERR_PACKING,              /**< Packaging error. */
    RESULT_ERR_NOT_INIT,             /**< Initialization not done. */
    RESULT_ERR_SECTOR_NUMBER_BIG,    /**< Sector number too big. */
    RESULT_ERR_VERIFY,               /**< Verification error. */
    RESULT_ERR_CHECK,                /**< Check error. */
    RESULT_ERR_AUTO_ECC_GENERATION,  /**< Auto ECC generation error. */
    RESULT_ERR_FSM_STATUS,           /**< FSM status error. */
    RESULT_ERR_ENABLE,               /**< Enable error. */
    RESULT_ERR_INIT,                 /**< Initialization error. */
    RESULT_ERR_ERASE,                /**< Erase error. */
    RESULT_ERR_CONNECTION,           /**< Connection error. */
    RESULT_ERR_NOTCONNECTED,         /**< Not connected. */
    RESULT_ERR_PORT,                 /**< Incorrect port. */
    RESULT_ERR_LINK,                 /**< Ethernet link error. */
    RESULT_ERR_TRANSMIT,             /**< Transmission error. */
    RESULT_ERR_LISTEN,               /**< Listen error. */
    RESULT_ERR_BIND,                 /**< Bind error. */
    RESULT_ERR_NETIF,                /**< Network interface error. */
    RESULT_ERR_ETHERNET,             /**< Ethernet error. */
    RESULT_ERR_PARAMATER,            /**< Parameter error. */
    RESULT_ERR_TRANSMIT_TIMEOUT,     /**< Transmit operation timed out. */

    /* STATE */
    RESULT_IN_THE_PROCESS,           /**< Operation in progress. */
    RESULT_NOT_FOR_ME                /**< Not applicable to this case. */

} results_enum_t;

/* @formatter:on */

/**
 * @struct result_struct
 * @brief Structure to store information about errors for logging purposes.
 */
typedef struct result_struct
{
    results_enum_t result;    /**< The result or error code. */
    uint8_t library_code;     /**< An 8-bit code identifying the library/module related to the error. */
    uint8_t function_code;    /**< An 8-bit code identifying the specific function within the library/module. */
    uint8_t is_loaded;        /**< Flag indicating whether the error was loaded. */
} result_struct_t;

void result_error_callback(results_enum_t result, uint8_t library_code, uint8_t function_code);
void result_loop(void);

#ifdef __cplusplus
}
#endif

#endif /* RESULTS_H_ */
