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

#define RESULT_IS_ERROR(v) (v < 0)

#define RESULT_ERROR_BUFFER_COUNT 10

/* @formatter:off */
typedef enum results_enum
{
	/* SUCCESS */
	RESULT_SUCCESS = 1,
	RESULT_CONNECTED,
	RESULT_DISCONNECTED,


	/* ERRORS */
	RESULT_ERR_UNKNOWN = -127,         /* Unknown error. */
	RESULT_ERR_HEAP_MEM,
	RESULT_ERR_TIMEOUT,                /* The operation timed out. */
	RESULT_ERR_RECEIVE_TIMEOUT,        /* Receive timed out. */
	RESULT_ERR_SIZE,                   /* Size error */
	RESULT_ERR_NULL,                   /* Function parameters or variables are null. */
	RESULT_ERR_CRC,                    /* CRC error. */
	RESULT_ERR_LEN,                    /* Length error. */
	RESULT_ERR_CHECKSUM,               /* checksum error. */
	RESULT_ERR_QUIUE,                  /* Quiue added error. */
	RESULT_ERR_NOTFOUND,               /* Search was not found. */
	RESULT_ERR_PACKING,                /* Packaging has been done. */
	RESULT_ERR_NOT_INIT,               /* It didn't initialize. */
	RESULT_ERR_SECTOR_NUMBER_BIG,      /* Sector number big. */
	RESULT_ERR_VERIFY,                 /* Verify error. */
	RESULT_ERR_CHECK,                  /* check error. */
	RESULT_ERR_AUTO_ECC_GENERATION,    /* Auto ECC generation error. */
	RESULT_ERR_FSM_STATUS,             /* FSM status error. */
	RESULT_ERR_ENABLE,                 /* Enable error. */
	RESULT_ERR_INIT,                   /* Initialize error. */
	RESULT_ERR_ERASE,                  /* Erase error. */
	RESULT_ERR_CONNECTION,             /* Connection is error */
	RESULT_ERR_NOTCONNECTED,			/* Connection is no*/
	RESULT_ERR_PORT,                   /* Port is wrong */
	RESULT_ERR_LINK,                   /* Ethernet link error*/
	RESULT_ERR_TRANSMIT,               /* Transmit error */
	RESULT_ERR_LISTEN,                 /* Listen error */
	RESULT_ERR_BIND,                   /* Bind error */

	/* STATE */
	RESULT_IN_THE_PROCESS

}results_enum_t;
/* @formatter:on */

typedef struct result_struct
{
	results_enum_t result;
	uint8_t library_code;
	uint8_t function_code;
	uint8_t is_loaded;
} result_struct_t;

void result_error_callback(results_enum_t result, uint8_t library_code, uint8_t function_code);
void result_loop(void);

#ifdef __cplusplus
}
#endif

#endif /* RESULTS_H_ */
