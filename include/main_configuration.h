#ifndef MAIN_CONFIGURATION_H
#define	MAIN_CONFIGURATION_H

/* < Include ::: Processor Header >*/
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"
/* < Configuration Drivers Settings > */
#include "driver_analog_digital_converter.h"
#include "driver_controller_area_network.h"
#include "driver_cyclic_redundancy_check.h"
#include "driver_direct_memory_access_zero.h"
#include "driver_direct_memory_access_one.h"
#include "driver_output_compare_one.h"
#include "driver_serial_peripheral_interface_one.h"
#include "driver_timer_two.h"
#include "driver_timer_five.h"
#include "driver_universal_asynchronous_receiver_transmitter_one.h"
#include "driver_universal_asynchronous_receiver_transmitter_two.h"
/* < Configuration Libraries Settings > */
#include "library_draw_font.h"
#include "library_draw_primitives.h"
#include "library_glcd_pcd8544.h"
#include "library_joystick.h"
#include "library_management_pulses.h"
#include "library_storage_bitmaps.h"
#include "library_storage_fonts.h"
/* < Configuration Controls Settings > */
#include "control_draw_menu.h"
#include "control_parameters_can.h"
#include "control_parameters_system.h"
#include "control_struct_menu.h"

/* < Prototipo ::: Funciones :: Configuracion >*/
void vHardwareConfiguration(void);

#endif	/* < MAIN_CONFIGURATION_H > */

