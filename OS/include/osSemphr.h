/**
 * @file  osSemphr.h
 * @author Carlos Gonzalez Cortes
 * @author Ignacio Ibanez Aliaga
 * @date 2017
 * @copyright GNU Public License.
 */

#ifndef _OS_SEMPHR_H_
#define _OS_SEMPHR_H_

#include "os.h"

#if __linux__
	#include <pthread.h>
	#include <stdint.h>
	typedef pthread_mutex_t osSemaphore;

	#define CSP_SEMAPHORE_OK 	1
	#define CSP_SEMAPHORE_ERROR 2
	#define CSP_MUTEX_OK 		CSP_SEMAPHORE_OK
	#define CSP_MUTEX_ERROR		CSP_SEMAPHORE_ERROR
#else
	#include "freertos/FreeRTOS.h"
	#include "freertos/queue.h"
	#include "freertos/semphr.h"
	typedef xSemaphoreHandle osSemaphore;

	#define CSP_SEMAPHORE_OK 	pdPASS
    #define CSP_SEMAPHORE_ERROR	pdFAIL
    #define CSP_MUTEX_OK		CSP_SEMAPHORE_OK
    #define CSP_MUTEX_ERROR		CSP_SEMAPHORE_ERROR
#endif

int osSemaphoreCreate(osSemaphore* mutex);
int osSemaphoreTake(osSemaphore* mutex, uint32_t timeout);
int osSemaphoreGiven(osSemaphore* mutex);

#endif