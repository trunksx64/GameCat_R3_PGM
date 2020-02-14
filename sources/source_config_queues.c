/* < Include ::: Header > */
#include "source_config_system.h"

/* < Declaracion ::: Variables (Pointers) :: Queues > */
QueueHandle_t xQueueReceiveDataCAN;

/* < Queues ::: Funciones :: Configuracion Resources Rtos > */
void vConfigurationQueues(void) {
    /* < Creación ::: Recepcion de Datos Bus CAN > */
    xQueueReceiveDataCAN = xQueueCreate((UBaseType_t) 10, sizeof (xMessegeECAN_t));   
}

