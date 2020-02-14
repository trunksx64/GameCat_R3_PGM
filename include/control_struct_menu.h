#ifndef CONTROL_STRUCT_MENU_H
#define	CONTROL_STRUCT_MENU_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"
/* < Configuration Libraries Settings > */
#include "library_storage_bitmaps.h"
/* < Configuration Controls Settings > */
#include "control_parameters_can.h"

/* < Definicion ::: typeDefs :: Menus > */
typedef struct xControlMenu {
    /* <--------------------------------------------------------------------> */
    const void *pxCurrentMenu; // < Puntero de Datos del Menu a Dibujar...
    /* <--------------------------------------------------------------------> */
    const char *StringText[2]; // < Puntero del Texto en Ingles/Español   
    /* <--------------------------------------------------------------------> */
    const void *pxFunctionA; // < Puntero Asociados a las Funciones de Ejecucion de los Botones...
    const void *pxFunctionB;
    const void *pxFunctionC;
    const void *pxFunctionD;
    const void *pxFunctionE;
    /* <--------------------------------------------------------------------> */
    uint8_t xType; // < Tipo de Menu a Dibujar por (vDrawingMenuControl)
    uint8_t xLength; // < Longitud de Lineas por Variable Asociada al Menu (Menu/xControlMenu)
    uint8_t xSelection; // < Indica la Variable Seleccionada para Trabajar...
    uint8_t xCursor; // < Posicion de Dibujado del Cursor de Seleccion...
    uint8_t xScroll; // < Variable que Desplaza las lineas en el Menu 
    uint8_t xOption; // < Indica Si Hay mas de 2 Selecciones en las Variables...
} xControlMenu_t;

typedef struct xIconsMenu {
    /* <--------------------------------------------------------------------> */
    const void *pxNextMenu; // < Puntero del Sub Menu a Dibujar...
    const uint8_t *pxIcon; // < Puntero del Icono a Dibujar...
    /* <--------------------------------------------------------------------> */
    const char *StringText[2]; // < Puntero del Texto en Ingles/Español    
} xIconsMenu_t;

typedef struct xSerialMenu {
    /* <--------------------------------------------------------------------> */
    const uint8_t *pxIcon; // < Puntero del Icono a Dibujar...
    /* <--------------------------------------------------------------------> */
    const char *StringText[2]; // < Puntero del Texto en Ingles/Español    
    /* <--------------------------------------------------------------------> */
    void *pxVariable; // < Puntero de la Varible a Manipular...    
    uint8_t TypeVariable; // < Indica el Tipo de Variable a Manipular    
    uint8_t SizeVariable; // < Tamaño en Bytes de la Variable a Manipular
    uint8_t LengthOptions; // < Tamaño Maximo de Opciones a Manipular (Contar/Incrementar)
} xSerialMenu_t;

typedef struct xListsMenu {
    /* <--------------------------------------------------------------------> */
    const void *pxNextMenu; // < Puntero del Sub Menu a Dibujar...
    const uint8_t *pxIcon; // < Puntero del Icono a Dibujar...
    /* <--------------------------------------------------------------------> */
    const char *StringText[2]; // < Puntero del Texto en Ingles/Español    
    /* <--------------------------------------------------------------------> */
    void *pxVariable; // < Puntero de la Varible a Manipular...
    uint8_t TypeFunction; // < Indica el Tipo de Variable a Manipular   
    uint8_t TypeVariable; // < Indica el Tipo de Variable a Manipular
    uint8_t SizeVariable; // < Tamaño en Bytes de la Variable a Manipular
    uint32_t LengthOptions; // < Tamaño Maximo de Opciones a Manipular (Contar/Incrementar)
    const char *pxStringOptions[4]; // < Puntero de la Variables de los Datos/Valores a Dibujar
} xListsMenu_t;

typedef struct xNumbersMenu {
    /* <--------------------------------------------------------------------> */
    const uint8_t *pxIcon; // < Puntero del Icono a Dibujar...
    /* <--------------------------------------------------------------------> */
    const char *StringText[2]; // < Puntero del Texto en Ingles/Español    
    /* <--------------------------------------------------------------------> */
    void *pxVariable; // < Puntero de la Varible a Manipular...
    uint8_t TypeVariable; // < Indica el Tipo de Variable a Manipular
    uint8_t SizeVariable; // < Tamaño en Bytes de la Variable a Manipular
    uint16_t LengthOptions; // < Tamaño Maximo de Opciones a Manipular (Contar/Incrementar)
    uint8_t MaxValueOption; // < Valor Maximo del Indice de Valores...
} xNumbersMenu_t;

typedef struct xBrightnessMenu {
    /* <--------------------------------------------------------------------> */
    const uint8_t *pxIcon; // < Puntero del Icono a Dibujar...
    /* <--------------------------------------------------------------------> */
    const char *StringText[2]; // < Puntero del Texto en Ingles/Español    
    /* <--------------------------------------------------------------------> */
    void *pxVariable; // < Puntero de la Varible a Manipular...
    uint8_t TypeVariable; // < Indica el Tipo de Variable a Manipular
    uint8_t SizeVariable; // < Tamaño en Bytes de la Variable a Manipular
} xBrightnessMenu_t;

typedef struct xMessgeWindow {
    /* <--------------------------------------------------------------------> */
    const uint8_t *pxIcon; // < Puntero del Icono a Dibujar...
    /* <--------------------------------------------------------------------> */
    const char *StringText[2]; // < Puntero del Texto en Ingles/Español    
} xMessgeWindow_t;

/* < Definicion ::: Macros de Tipo de Menu... > */
#define TYPE_MENU_ICONS                 1
#define TYPE_MENU_LIST                  2
#define TYPE_MENU_FLOORS                3
#define TYPE_MENU_SERIAL                4
#define TYPE_MENU_PASSWORD              5
#define TYPE_MENU_BAR                   6
#define TYPE_MENU_CLOCK                 7
#define TYPE_MENU_MESSAGE               8
#define TYPE_MENU_BUTTONS               9

/* < Definicion ::: Macros de Tipo de Variable... > */
#define TYPE_VARIABLE_TITLE             1
#define TYPE_VARIABLE_RETURN            2
#define TYPE_VARIABLE_INT               3
#define TYPE_VARIABLE_BOOL              4
#define TYPE_VARIABLE_SIGNAL            5
#define TYPE_VARIABLE_BIT_BOOL          6
#define TYPE_VARIABLE_BIT_TEXT          7
#define TYPE_VARIABLE_TEXT              8
#define TYPE_VARIABLE_SERIAL            9
#define TYPE_VARIABLE_FUNCTION_A        10
#define TYPE_VARIABLE_FUNCTION_B        11
#define TYPE_VARIABLE_FUNCTION_C        12
#define TYPE_VARIABLE_FUNCTION_D        13
#define TYPE_VARIABLE_FUNCTION_E        14
#define TYPE_VARIABLE_SUB_MENU          15

/* < Definicion ::: Macros de Tipo de Mensage... > */
#define MENSSEGE_WINDOW_ONE             1
#define MENSSEGE_WINDOW_TWO             2
#define MENSSEGE_WINDOW_THREE           3

/* < Definicion ::: Extern :: Variables Menus CAN... > */
extern const xIconsMenu_t __attribute__((space(auto_psv))) MainCANMenu[];
extern const xSerialMenu_t __attribute__((space(auto_psv))) SerialCANMenu[];
extern const xSerialMenu_t __attribute__((space(auto_psv))) PasswordCANMenu[];
extern const xListsMenu_t __attribute__((space(auto_psv))) ParametersCANMenu[];
extern const xListsMenu_t __attribute__((space(auto_psv))) DoorStatusMenuCAN[];
extern const xListsMenu_t __attribute__((space(auto_psv))) ControlsMenuCAN[];
extern const xListsMenu_t __attribute__((space(auto_psv))) TimesMenuCAN[];
extern const xListsMenu_t __attribute__((space(auto_psv))) OutputsMenuCAN[];
extern const xListsMenu_t __attribute__((space(auto_psv))) InputsMenuCAN[];
extern const xListsMenu_t __attribute__((space(auto_psv))) ErrorsMenuCAN[];
extern const xListsMenu_t __attribute__((space(auto_psv))) StatusMenuCAN[];
extern const xListsMenu_t __attribute__((space(auto_psv))) ManeuverMenuCAN[];
extern const xListsMenu_t __attribute__((space(auto_psv))) SettingsMenuCAN[];

/* < Definicion ::: Extern :: Variables Controles CAN... > */
extern xControlMenu_t MainCANCtrl;
extern xControlMenu_t SerialCANCtrl;
extern xControlMenu_t PasswordCANCtrl;
extern xControlMenu_t ParametersCANCtrl;
extern xControlMenu_t StatusDoorCANCtrl;
extern xControlMenu_t ControlsCANCtrl;
extern xControlMenu_t TimesCANCtrl;
extern xControlMenu_t InputsCANCtrl;
extern xControlMenu_t OutputsCANCtrl;

/* < Definicion ::: Extern :: Variables BASE... > */

#endif	/* < CONTROL_STRUCT_MENU_H > */

