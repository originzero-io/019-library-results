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

typedef enum results_enum
{
	RESULT_SUCCESS,
	RESULT_ERR_HEAP_MEM,
	RESULT_ERR_TIMEOUT,
	RESULT_ERR_SIZE,
	RESULT_ERR_LEN,
	RESULT_ERR_NULL,
	RESULT_ERR_CRC,
	RESULT_ERR_CHECKSUM,
	RESULT_ERR_NOT_FOUND
}results_enum_t;


typedef struct result_struct
{
	results_enum_t result;
	uint8_t library_code;
	uint8_t function_code;
}result_struct_t;

result_struct_t results_return(results_enum_t result, uint8_t library_code, uint8_t function_code);
void result_error_callback(result_struct_t result);



#ifdef __cplusplus
}
#endif

#endif /* RESULTS_H_ */
