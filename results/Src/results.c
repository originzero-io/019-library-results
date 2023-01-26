/*
 * results.c
 *
 *  Created on: Dec 16, 2022
 *      Author: fatih
 */

#include "results.h"
#include "sci.h"

static result_struct_t results_errors_quiue[RESULT_ERROR_BUFFER_COUNT];
static uint8_t results_errors_quiue_index_counter;

//static void uart_write(uint8_t *string, uint32_t string_len);

void result_error_callback(results_enum_t result, uint8_t library_code, uint8_t function_code)
{
	results_errors_quiue[results_errors_quiue_index_counter].result = result;
	results_errors_quiue[results_errors_quiue_index_counter].library_code = library_code;
	results_errors_quiue[results_errors_quiue_index_counter].function_code = function_code;
	results_errors_quiue[results_errors_quiue_index_counter].is_loaded = 1;

	if (RESULT_ERROR_BUFFER_COUNT < (++results_errors_quiue_index_counter))
	{
		results_errors_quiue_index_counter = 0;
	}
}

void result_loop(void)
{
	static uint8_t results_errors_quiue_index_counter_loop, is_logged = 0,
			tried_count = 0;

	do
	{

		if (1 == results_errors_quiue[results_errors_quiue_index_counter_loop].is_loaded)
		{
			/*todo LOG WRITE */
			char array[15];
			int len = sprintf(&array[0], "%d.%d.%d\n", results_errors_quiue[results_errors_quiue_index_counter_loop].library_code, results_errors_quiue[results_errors_quiue_index_counter_loop].function_code, results_errors_quiue[results_errors_quiue_index_counter_loop].result);
			//uart_write((uint8_t*) &array[0], len);
			results_errors_quiue[results_errors_quiue_index_counter_loop].is_loaded = 0;
			is_logged = 1;
		}

		tried_count++;

		if (RESULT_ERROR_BUFFER_COUNT < (++results_errors_quiue_index_counter_loop))
		{
			results_errors_quiue_index_counter_loop = 0;
		}

	} while (0 == is_logged && RESULT_ERROR_BUFFER_COUNT > tried_count);
}
/*
static void uart_write(uint8_t *string, uint32_t string_len)
{
	while (string_len--)
	{
		while ((scilinREG->FLR & 0x4) == 4)
			; /* wait until busy */
		/*sciSendByte(scilinREG, *string++); /* send out text   */
/*};
}*/
