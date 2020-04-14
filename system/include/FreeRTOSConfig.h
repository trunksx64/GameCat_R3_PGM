/* < FreeRTOS V10.1.1 - Copyright (C) 2018 Real Time Engineers Ltd. > */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* < Include ::: Processor Header >*/
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_delays.h"

/* < Application Specific Definitions > */
#define configUSE_PREEMPTION                    1
#define configUSE_TICKLESS_IDLE                 0
#define configCPU_CLOCK_HZ                      FCY
#define configTICK_RATE_HZ                      1000
#define configMAX_PRIORITIES                    3
#define configMINIMAL_STACK_SIZE                64
#define configMAX_TASK_NAME_LEN                 8
#define configUSE_16_BIT_TICKS                  1
#define configIDLE_SHOULD_YIELD                 0
#define configUSE_TASK_NOTIFICATIONS            0
#define configUSE_MUTEXES                       0
#define configUSE_RECURSIVE_MUTEXES             0
#define configUSE_COUNTING_SEMAPHORES           0
#define configUSE_QUEUE_SETS                    0
#define configUSE_TIME_SLICING                  1

/* Memory allocation related definitions. */
#define configSUPPORT_STATIC_ALLOCATION         0
#define configSUPPORT_DYNAMIC_ALLOCATION        1
#define configTOTAL_HEAP_SIZE                   1200
#define configAPPLICATION_ALLOCATED_HEAP        0

/* Hook function related definitions. */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configCHECK_FOR_STACK_OVERFLOW          0
#define configUSE_MALLOC_FAILED_HOOK            0
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0

/* Co-routine related definitions. */
#define configUSE_CO_ROUTINES                   0
#define configMAX_CO_ROUTINE_PRIORITIES         0

/* Software timer related definitions. */
#define configUSE_TIMERS                        0
#define configTIMER_QUEUE_LENGTH                4
#define configTIMER_TASK_PRIORITY               0
#define configTIMER_TASK_STACK_DEPTH            configMINIMAL_STACK_SIZE

/* Optional functions - most linkers will remove unused functions anyway. */
#define INCLUDE_vTaskPrioritySet                0
#define INCLUDE_uxTaskPriorityGet               0
#define INCLUDE_vTaskDelete                     0
#define INCLUDE_vTaskSuspend                    0
#define INCLUDE_xResumeFromISR                  0
#define INCLUDE_vTaskDelayUntil                 0
#define INCLUDE_vTaskDelay                      0
#define INCLUDE_xTaskGetSchedulerState          0
#define INCLUDE_xTaskGetCurrentTaskHandle       0
#define INCLUDE_uxTaskGetStackHighWaterMark     0
#define INCLUDE_xTaskGetIdleTaskHandle          0
#define INCLUDE_eTaskGetState                   0
#define INCLUDE_xEventGroupSetBitFromISR        0
#define INCLUDE_xTimerPendFunctionCall          0
#define INCLUDE_xTaskAbortDelay                 0
#define INCLUDE_xTaskGetHandle                  0
#define INCLUDE_xTaskResumeFromISR              0

/* < Interrupt nesting behaviour configuration > */
#define configKERNEL_INTERRUPT_PRIORITY         1

#endif /* FREERTOS_CONFIG_H */

