/* < Include ::: Header > */
#include "source_config_system.h"

/* < Declaracion ::: Variables (Pointers) :: EventGroups > */
EventGroupHandle_t xEventGroupProgramControls;

/* < EventGroups ::: Funciones :: Configuracion Resources Rtos > */
void vConfigurationEventGroups(void) {
    /* < Creaci�n ::: EventGroups :: Programacion de Controles > */
    xEventGroupProgramControls = xEventGroupCreate();
}
