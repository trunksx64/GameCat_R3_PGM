/* < Include ::: Header > */
#include "source_config_system.h"

/* < Declaracion ::: Variables (Pointers) :: Timers > */
TimerHandle_t xTimerRefreshScreen;
TimerHandle_t xTimerReadingJoystick;

/* < Timers ::: Funciones :: Configuracion Resources Rtos > */
void vConfigurationTimers(void) {
    /* < Creacion ::: Temporizador de Sistema :: Refresco del LCD... > */
    xTimerRefreshScreen = xTimerCreate("Screen", (TickType_t) (50 / portTICK_PERIOD_MS), Timer_Reload_Enable, (void*) 1, vThreadTimerSystem);
    /* < Creacion ::: Temporizador de Sistema :: Lectura del Joystick... > */
    xTimerReadingJoystick = xTimerCreate("Joystick", (TickType_t) (10 / portTICK_PERIOD_MS), Timer_Reload_Enable, (void*) 2, vThreadTimerSystem);
}
