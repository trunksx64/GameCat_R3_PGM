#ifndef CONTROL_DRAW_MENU_H
#define	CONTROL_DRAW_MENU_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"
/* < Configuration Drivers Settings > */

/* < Configuration Libraries Settings > */
#include "library_storage_bitmaps.h"
#include "library_storage_fonts.h"
#include "library_draw_font.h"
#include "library_draw_primitives.h"
#include "library_joystick.h"
#include "library_management_pulses.h"
/* < Configuration Controls Settings > */
#include "control_struct_menu.h"
#include "control_parameters_system.h"

/* < Definicion ::: typeDefs :: Menus Auxiliares... > */
typedef struct xSelectedWorkMenu {
    void *WorkMenuIndex[4];
    uint8_t SubMenuSelect;
} xSelectedWorkMenu_t;

/* < Definicion ::: Macros de Control... > */
#define LENGTH_LINES_MENU_LIST              4
#define LENGTH_MAX_OPTIONS_TEXT             4

/* < Definicion ::: Variable de Menu Trabajo... > */
extern xSelectedWorkMenu_t SelectedWorkMenu;

/* < Prototipo ::: Funciones de Control > */
void vIncremetnSelectedWorkMenu(void *Menu);
void vDecrementnSelectedWorkMenu(void);
void vDrawingMenuControl(xSelectedWorkMenu_t *Menu);
uint1_t xExecuteMenuControl(xSelectedWorkMenu_t *Menu, void *Inputs);

#endif	/* < CONTROL_DRAW_MENU_H > */


