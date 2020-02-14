/* < Include ::: Header > */
#include "source_config_system.h"

/* < Declaracion ::: Variables (Pointers) :: Tasks > */
TaskHandle_t xThreadHandlMenu;

/* < Tasks ::: Funciones :: Configuracion Resources Rtos > */
void vConfigurationTasks(void) {
    /* < Creacion ::: Tarea :: Control de Parametros > */
    xTaskCreate(vThreadControlMenu, "Menu", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 2), &xThreadHandlMenu);
}
