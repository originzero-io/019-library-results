/*
 * results.c
 *
 *  Created on: Dec 16, 2022
 *      Author: fatih
 */

#include "results.h"

result_struct_t results_return(results_enum_t result, uint8_t library_code, uint8_t function_code)
{
	result_struct_t return_value;

	return_value.result = result;
	return_value.library_code = library_code;
	return_value.function_code = function_code;

	return return_value;
}


void result_error_callback(result_struct_t result)
{

}
