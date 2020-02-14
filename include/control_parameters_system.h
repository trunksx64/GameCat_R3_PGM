#ifndef CONTROL_PARAMETERS_SYSTEM_H
#define	CONTROL_PARAMETERS_SYSTEM_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: typeDefs :: Parametros del Systema... > */
typedef struct ParameterSystem_t {    
    uint8_t Parameter_Language;
    uint16_t Parameter_Brightness;
} xParameterSystem;

/* < Definicion ::: Macros de Tipo de Variable... > */
#define PARAMETER_LANGUAGE_ENG                      1
#define PARAMETER_LANGUAGE_ESP                      2

/* < Definicion ::: Variables Externas... > */
extern xParameterSystem ParameterSystem;

#endif	/* < CONTROL_PARAMETERS_SYSTEM_H > */

