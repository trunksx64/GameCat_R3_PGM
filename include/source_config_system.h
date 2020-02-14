#ifndef MAIN_PROTOTHREADS_H
#define	MAIN_PROTOTHREADS_H

/* < Include ::: Processor Header >*/
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"
#include "main_configuration.h"
/* < Configuration Rtos Settings > */
#include "FreeRTOS.h"
#include "event_groups.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"
#include "task.h"

/* < Configuracion ::: Yield in case Cooperative Scheduling is Being Used > */
#define StartTask() while(RunTask){

#if (configUSE_PREEMPTION == 0)
#define EndTask() taskYIELD(); }
#else
#define EndTask() }
#endif

/* < Define ::: Control for Read Flags > */
#define Flag_ClearOnExit        pdTRUE
#define Flag_HoldOnExit         pdFALSE
#define Flag_WaitForAllBits     pdTRUE
#define Flag_NoWaitForAllBits   pdFALSE

/* < Declaracion ::: Control Reload Soft Timer > */
#define Timer_Reload_Enable     pdTRUE
#define Timer_Reload_Disable    pdFALSE

/* < ---------------------------------------------------------------------- > */

/* < Declaracion ::: Control de Programacion:: Banderas x Bit > */
#define Flag_ProgramCtrl_SerialBoard_Pass           ((EventBits_t) 0x01)
#define Flag_ProgramCtrl_PasswdBoard_Pass           ((EventBits_t) 0x02)
#define Flag_ProgramCtrl_Write_Enabled              ((EventBits_t) 0x04)
#define Flag_ProgramCtrl_Read_Enabled               ((EventBits_t) 0x08)
#define Flag_ProgramCtrl_Mode_Bulk_Write            ((EventBits_t) 0x10)
#define Flag_ProgramCtrl_Mode_Bulk_Read             ((EventBits_t) 0x20)

/* < ---------------------------------------------------------------------- > */

/* < Declaracion Etxern ::: Variables (Pointers) :: EventGroups > */
extern EventGroupHandle_t xEventGroupProgramControls;
/* < Declaracion Etxern ::: Variables (Pointers) :: Mutexes > */

/* < Declaracion Extern ::: Variables (Pointers) :: Queues > */
extern QueueHandle_t xQueueReceiveDataCAN;
/* < Declaracion Etxern ::: Variables (Pointers) :: Timers > */
extern TimerHandle_t xTimerRefreshScreen;
extern TimerHandle_t xTimerReadingJoystick;
/* < Declaracion Extern ::: Variables (Pointers) :: Tasks > */
extern TaskHandle_t xThreadHandlMenu;

/* < Prototipo ::: Funciones :: Configuracion Resources Rtos > */
void vConfigurationEventGroups(void); // < Configure ::: Flags 
void vConfigurationMutexes(void); // < Configure ::: Mutexes
void vConfigurationQueues(void); // < Configure ::: Queues
void vConfigurationTimers(void); // < Configure ::: Timers
void vConfigurationTasks(void); // < Configure ::: Tasks

/* < Prototipo ::: Funciones :: Configuracion threads Rtos > */
void vThreadTimerSystem(TimerHandle_t pxTimer);
void vThreadControlMenu(void *pvParameters);

#endif	/* < MAIN_PROTOTHREADS_H > */

