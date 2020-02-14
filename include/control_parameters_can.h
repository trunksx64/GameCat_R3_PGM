#ifndef CONTROL_PARAMETERS_CAN_H
#define	CONTROL_PARAMETERS_CAN_H

/* < Include ::: Processor Header >*/
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"
/* < Configuration Drivers Settings > */
#include "driver_controller_area_network.h"

/* < Definicion ::: Typedefs... for control of Flags... > */
typedef union xFlagsResetError {
    uint8_t FlagsResetError;

    struct {
        unsigned MovedLevelCabin : 1; // < Habilita el Reinicio del Control por Falla de Seguridad...
        unsigned RelevelingTimeDown : 1;
        unsigned RelevelingTimeUp : 1;
        unsigned OverflowLimitSpeed : 1;
        unsigned WrongDetectLimitSpeed : 1;
        unsigned WrongSenseLevel : 1;
        unsigned WtongSensePulse : 1;
        unsigned OverflowTimeTravel : 1;
    } Bits;
} xFlagsResetError_t;

/* < Definicion ::: Typedefs... for Logic Input Senses & Securities > */
typedef union xLogicSenses {
    /* < Registro ::: All Bits > */
    uint8_t RegisterSenses;

    struct {
        unsigned PulsoConteo : 1;
        unsigned NivelParqueo : 1;
        unsigned FinalVelocidadRapida : 1;
        unsigned FinalVelocidadNormal : 1;
        unsigned ControlRenivelacion : 1;
        unsigned ControlUnidadSuministroEnergia : 1;
        unsigned ControlFreno : 1;
        unsigned ControlAuxiliar : 1;
    } Bits;
} xLogicSenses_t;

typedef union xLogicSecurities {
    /* < Registro ::: All Bits > */
    uint8_t RegisterSecurties;

    /* < Field ::: Bits > */
    struct {
        unsigned SeguridadOne : 1;
        unsigned SeguridadTwo : 1;
        unsigned SeguridadPuertaHall : 1;
        unsigned SeguridadPuertaCabin : 1;
        unsigned SeguridadPuertaBatiente : 1;
        unsigned ControlRevisionEnable : 1;
        unsigned ControlRevisionSubiendo : 1;
        unsigned ControlRevisionBajando : 1;
    } Bits;
} xLogicSecurities_t;

/* < Definicion ::: Typedefs... for Logic Output Relay > */
typedef union xLogicRelay {
    /* < Registro ::: All Bits > */
    uint8_t RegisterRelays;

    /* < Field ::: Bits > */
    struct {        
        unsigned DireccionAbajo : 1;
        unsigned DireccionArriba : 1;
        unsigned VelocidadNominal : 1;
        unsigned VelocidadIntermediaDos : 1;
        unsigned VelocidadIntermediaUno : 1;
        unsigned VelocidadRevision : 1;
        unsigned VelocidadNivelacion : 1;
        unsigned : 1;
    } Bits;

    /* < Field ::: Byte > */
    struct {        
        unsigned Value : 7;
        unsigned : 1;
    } Byte;
} xLogicRelay_t;

/* <------------------------------------------------------------------------> */

/* < Definicion ::: Typedefs... for All Controls System > */
typedef struct xControls {

    /* < - Serial & Password ---------------------------------------------- > */
    struct {

        union {
            uint16_t Eeprom[4]; // < Serial de la Board, (2Bytes*Word = 8 Valores)
            uint8_t Ascii[8];
        } Serial;

        union {
            uint16_t Eeprom[2]; // < Llave de Cifrado de la Board, (2Bytes*Word = 4 Valores)               
            uint8_t Ascii[4];
        } Password;
    } Board;

    /* < - Resources Parameters ------------------------------------------- > */
    struct {
        uint16_t SystemParametersCRC; // < Valor del CRC de Todos los Parametros
        uint16_t SystemSerialCRC; // < Valor del CRC de Serial
        uint16_t SystemPasswordCRC; // < Valor del CRC de Password                            
        uint16_t SystemParkingCRC; // < Valor del CRC de Password       
    } Register;

    /* < - Resources Reocrd Journal --------------------------------------- > */
    struct {
        uint16_t IndexRegisterRecord; // < Indica La Posicion del Proximo Record del Journal
    } Record;
} xControls_t;

/* <------------------------------------------------------------------------> */

typedef struct xDataGameCat {
    uint8_t AddressBulkData;
    uint8_t CounterPointer;
    uint8_t LengthBulkData;
    uint8_t BufferBulkData[4];
} xDataGameCat_t;

/* <------------------------------------------------------------------------> */

/* < Definicion ::: Typedefs... for All Parameters > */
typedef struct xParameters {

    /* < - Parametros de Gestion ------------------------------------------ > */
    struct {
        uint8_t Tipo_Puerta; // < Tipo de Bloqueo de Puerta (Automatico/Batiente/Manual)        
        uint8_t Gestion_Cierre_Puerta; // < Indica si la Puerta de Cierra Automaticamente, Llamada o Manualmente                
        uint1_t Gestion_Velocidad_Inversor; // < Indica si el Control del Motor sera de Doble o Simple Velocidad...
        uint1_t Modo_Hidrahulico; // < Modo de Renivelacion para Controles Hidrahulicos (On/Off) 
        uint1_t Sensor_Hidrahulico; // < Tercer Sensor de Renivelacion para Controles Hidrahulicos (On/Off)     
        uint1_t Sensor_Unit_Power_Suply; // < Control del Sensor de UPS  (On/Off)
        uint1_t Sensor_Llave_Servicio; // < Control del Llave de Servicio
        uint1_t Sensor_Llave_Bloqueo; // < Control del Llave de Bloqueo del Control Principal
        uint1_t Borrado_Llamadas; // < Control de Borrado de Llamadas (On/Off)                     
        uint8_t Gestion_Llamadas; // < Control de Llamadas (Simple/Viaje Subiendo & Bajando/Prioridad Bajando/Prioridad Dual))                
        uint1_t Gestion_Grupal; // < Control de Gestion de Llamadas por Grupos RS485, (NULL) Deshabilitado
        uint1_t Modo_Master_Slave; // < Control de Gestion de Llamadas por Grupos RS485, Control Maestro/Esclavo        
        uint8_t Gestion_Numero_Slaves; // < Control de Gestion de Llamadas por Grupos RS485, Numero de Esclavos a Manipular   
        uint1_t Modo_Auxiliar_Master; // < Indica si la En modo Esclavo, Funcionara como Maestra en Ausencia de la Maestra Principal (Mayor Prioridad)
        uint8_t Prioridad_Slave; // < Indica la Prioridad de la Tarjeta Esclava...   
    } Parametro;

    /* < - Parametros de Puertas ------------------------------------------ > */
    struct {
        uint8_t Estado[32]; // < Indica el Numero de Piso, que Puerta se debe Abrir, (Uno, Dos ó Ambas) 
    } Puertas;

    /* < - Parametros de Control ------------------------------------------ > */
    struct {
        uint8_t Numero_Puertas; // < Indica la Cantidad de Puerta a Controlar (Maximo 2, Minimo 1)
        uint8_t Numero_Max_Pisos; // < Numero Maximo de Pisos (Max 32 pisos)...
        uint8_t Numero_Max_Sotanos; // < Numero de Sotanos para Gestion de Llamdas ::: Solo Aplica para Modo (Prioridad...)
        uint8_t Numero_Retorno_Cabina; // < Numero de Piso de Retorno de Automatico ::: (NULL) Desactivado...        
        uint8_t Numero_Retorno_Bombero; // < Numero de Piso de Retorno a Piso de Emergancia por Llavin de Bomberos ::: (0x00) Desactivado...Maximo                       
        uint32_t Numero_Limite_Viajes; // < Numero de Piso de Viajes Maximos de Matenimiento ::: (NULL) Desactivado...
    } Control;

    /* < - Parametros de Tiempo ------------------------------------------- > */
    struct {
        uint8_t Start_Post; // < Tiempo en Segundos, Iniciar el Ascensor (PC:0x00)
        uint8_t Reconocimiento_Subiendo; // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
        uint8_t Reconocimiento_Intermedio; // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
        uint8_t Reconocimiento_Bajando; // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
        uint8_t Renivelacion_Cabina_Subiendo; // < Tiempo en Segundos, Disparar Error de Renivelacion de Cabina Subiendo...
        uint8_t Renivelacion_Cabina_Bajando; // < Tiempo en Segundos, Disparar Error de Renivelacion de Cabina Bajando...
        uint8_t Atender_Boton_Cerrar; // < Tiempo en Segundos, Atender Boton de Cierre de Puerta ::: Solo Aplica Puerta Automatica...
        uint8_t Atender_Boton_Abrir; // < Tiempo en Segundos, Atender Botones Luego de Accion de Reapertura ::: Solo Aplica para Puerta Automatica...
        uint8_t Accion_Cerrar_Puerta; // < Tiempo en Segundos, Cerrar Puerta ::: Solo Aplica Puerta Automatica/Batiente/Manual...    
        uint8_t Retorno_Cabina; // < Tiempo en Minutos, Disparo de Viaje de Cabina a Origen...         
        uint8_t Viaje_Entre_Pisos_Cabina; // < Tiempo en Segundos, Disparo de Error, Seguridad de Viaje de Cabina...         
        uint8_t Apagar_Luz_Cabina; // < Tiempo en Minutos, Habilatacion de Luz de Cabina...   
        uint8_t Inicio_Sonido_Cabina; // < Tiempo en Segundos, Habilatacion de Sonido de Puerta...
        uint8_t Chequeo_Limites_Velocidad; // < Tiempo en Segundos, Habilatacion de Chequeo de Seguidad de Limites
        uint8_t Reinicio_Error_Sistema; // < Tiempo en Minutos, Reinicia el Control Luego de Agotar el Tiempo luego de Disparo por Error..
        uint16_t Incio_Viaje_Cabina; // < Tiempo en Milisegundos, Espera para Arrancar Viaje Luego de Cerrar Puertas
        uint16_t Final_Viaje_Cabina; // < Tiempo en Milisegundos, Entre La parada y la Apertura de Puertas.
        uint16_t Enganche_Puerta_Batiente; // < Tiempo en Milisegundos, Para Asegurar la Puerta en modo Batiente...
    } Tiempo;

    /* < - Logica de Entrada Sensores & Seguridades ----------------------- > */
    struct {
        xLogicSenses_t LogicSenses;
        xLogicSecurities_t LogicSecurities;
    } Input;

    /* < - Logica de Salida de Relays ------------------------------------- > */
    struct {
        xLogicRelay_t LogicStop;
        xLogicRelay_t LogicNivelacionArriba;
        xLogicRelay_t LogicRevisionArriba;
        xLogicRelay_t LogicIntermediaUnoArriba;
        xLogicRelay_t LogicIntermediaDosArriba;
        xLogicRelay_t LogicNominalArriba;
        xLogicRelay_t LogicNivelacionBajando;
        xLogicRelay_t LogicRevisionBajando;
        xLogicRelay_t LogicIntermediaUnoBajando;
        xLogicRelay_t LogicIntermediaDosBajando;
        xLogicRelay_t LogicNominalBajando;
    } Outputs;

    /* < - Logica Activacion Seguridades ---------------------------------- > */
    struct {
        xFlagsResetError_t EnableControlReset; // < Habilita el Reinicio del Control por Falla de Seguridad...
    } Securities;

    /* < - Parametros de BUS CAN ------------------------------------------ > */
    struct {
        uint16_t Velocidad_BUSCAN; // < Seleccion de Velocidad del BUS.CAN (100Khz, 250Khz, 500Khz) (LOW, MED, HIG)
    } Communication;
} xParametersCAN_t;

/* <------------------------------------------------------------------------> */

/* < Definicion ::: Macros de Control para de Serial + Key + CRC :: Parametros > */
#define Parametro_Polynomi_CRC_8Bits            0xA0
/* < Definicion ::: Macros de Control para Numero de Puertas :: Parametros > */
#define Parametro_Puerta_Single                 0x00 // < Indica que Hay una Sola Puerta
#define Parametro_Puerta_Dual                   0x01 // < Indica que Hay dos Puertas pero Solo se Acciona Una
/* < Definicion ::: Macros de Control para la Accion de Puertas :: Parametros > */
#define Parametro_Puerta_Apertura_Delantera     0x00 // < Indica que se Debe Abrir la Puerta Delantera
#define Parametro_Puerta_Apertura_Trasera       0x01 // < Indica que se Debe Abrir la Puerta Trasera
#define Parametro_Puerta_Apertura_Ambas         0x02 // < Indica que se Debe Abrir Ambas Puertas
/* < Definicion ::: Macros de Control para Tipo de Control Puerta :: Parametros > */
#define Parametro_Puerta_Automatica             0x00 // < Puertas con Operador de Puerta
#define Parametro_Puerta_Semi_Automatica        0x01 // < Puerta Hibrida (Automatica en cabina, Batiente en Hall)
#define Parametro_Puerta_Batiente               0x02 // < Puettas con Control de Batiente...
#define Parametro_Puerta_Manual                 0x03 // < Puertas Sin Control + Tiempo de Espera
/* < Definicion ::: Macros de Control para Control de Ciere de Puerta (Solo Automatica) :: Parametros > */
#define Parametro_Puerta_Cierre_Automatico      0x00 // < El Control de Puerta Automatico envia la Orden de Cierre...
#define Parametro_Puerta_Cierre_Llamada         0x01 // < El Inicio de LLamada, Indica el Cierre de Puerra
#define Parametro_Puerta_Cierre_Boton           0x02 // < El Boton de Cierre de Puerta, Indica el Cierre de Puerta 
/* < Definicion ::: Macros de Control para Control de Velocidad :: Parametros > */
#define Parametro_Control_Inverter_Simple       0x00 //    
#define Parametro_Control_Inverter_Double       0x01 //    
/* < Definicion ::: Macros de Control para Control de Renivelacion :: Parametros > */
#define Parametro_Hidraulico_OFF                0x00 // < Renivelacion Deshabilitada
#define Parametro_Hidraulico_ON                 0x01 // < Renivalacion Habilitada
/* < Definicion ::: Macros de Control para Sensor de Renivelacion :: Parametros > */
#define Parametro_Sensor_Hidraulico_OFF         0x00 // < Sensor Renivelacion Deshabilitada
#define Parametro_Sensor_Hidraulico_ON          0x01 // < Sensor Renivalacion Habilitada 
/* < Definicion ::: Macros de Control para Sensor de UPS :: Parametros > */
#define Parametro_UPS_OFF                       0x00 // < UPS Deshabilitada
#define Parametro_UPS_ON                        0x01 // < UPS Habilitada
/* < Definicion ::: Macros de Control para Llavin de Servicio :: Parametros > */
#define Parametro_Sensor_Service_OFF            0x00 // < Llavin de Servicio Deshabilitada
#define Parametro_Sensor_Service_ON             0x01 // < Llavin de Servicio Habilitada 
/* < Definicion ::: Macros de Control para Llavin de Bloqueo :: Parametros > */
#define Parametro_Sensor_MainBlock_OFF          0x00 // < Llavin de Servicio Deshabilitada
#define Parametro_Sensor_MainBlock_ON           0x01 // < Llavin de Servicio Habilitada 
/* < Definicion ::: Macros de Control Borrar Llamadas :: Parametros > */
#define Parametro_Borrado_Llamadas_OFF          0x00 // < Borrando de Llamadas Dehablitado    
#define Parametro_Borrado_Llamadas_ON           0x01 // < Borrando de Llamadas Hablitado   
/* < Definicion ::: Macros de Control para Gestion de Llamadas :: Parametros > */
#define Parametro_Gestion_Simple                0x00 // < Gestion de Llamdas Sin Prioridad    
#define Parametro_Gestion_Colectivo_Dual        0x01 // < Gestion de Llamdas Con Prioridad de Sentido de Viaje
#define Parametro_Gestion_Colectivo_Bajando     0x02 // < Gestion de Llamdas Con Prioridad de Viaje Bajando
#define Parametro_Gestion_Selectivo_Dual        0x03 // < Gestion de Llamdas Con Prioridad de Viaje Subiendo/Bajando
/* < Definicion ::: Macros de Grupal de Llamadas :: Parametros > */
#define Parametro_Control_Grupal_OFF            0x00 // < Control Grupal Habilitado
#define Parametro_Control_Grupal_ON             0x01 // < Control Grupal Deshabilitado
/* < Definicion ::: Macros de Grupal Maestro/Esclavo :: Parametros > */
#define Parametro_Control_Grupal_Master         0x00 // < Seleccion de Maestro con Control Grupal
#define Parametro_Control_Grupal_Slave          0x01 // < Seleccion de Esclavo con Control Grupal
/* < Definicion ::: Macros de Numero de Esclavo :: Parametros > */
#define Parametro_Min_Esclavos                  0x01 // < Valor de piso Minimo (1)
#define Parametro_Max_Esclavos                  0x08 // < Valor de piso Maximo (8)
/* < Definicion ::: Macros de Numero de Esclavo :: Parametros > */
#define Parametro_Auxiliar_Master_OFF           0x00 // < La Esclava no Funcionara como Auxiliar Maestra...
#define Parametro_Auxiliar_Master_ON            0x01 // < La Esclava Funcionara como Maestra, si falta la Maestra...
/* < Definicion ::: Macros Limite de Pisos :: Parametros > */
#define Parametro_Piso_Inicial                  0x01 // < Valor de piso Minimo (1)
#define Parametro_Min_Pisos                     0x02 // < Valor de piso Minimo (2)
#define Parametro_Max_Pisos                     0x20 // < Valor de piso Maximo (8)
/* < Definicion ::: Macros Numero de Sotanos :: Parametros > */
#define Parametro_Min_Sotanos                   0x01 // < Valor de piso Minimo (1)
#define Parametro_Max_Sotanos                   0x08 // < Valor de piso Maximo (4)
/* < Definicion ::: Macros de Control para Veloicidad CAN :: Comunicacion > */
#define Paramero_Velcidad_BusCAN_Low            0x00 // < 100Khz
#define Paramero_Velcidad_BusCAN_Med            0x01 // < 250Khz
#define Paramero_Velcidad_BusCAN_Hig            0x02 // < 500Khz

/* <------------------------------------------------------------------------> */

/* < Definicion ::: Macros Logica de Entradas :: Parametros > */
#define Parametro_Input_Logig_All_High          0xFF
#define Parametro_Input_Logig_Pulse_High        0x01
#define Parametro_Input_Logig_Level_High        0x02
#define Parametro_Input_Logig_Speed_Fast_High   0x04
#define Parametro_Input_Logig_Speed_Nomi_High   0x08
#define Parametro_Input_Logig_Releveling_High   0x10
#define Parametro_Input_Logig_UPS_High          0x20
#define Parametro_Input_Logig_Break_High        0x40
#define Parametro_Input_Logig_Aux_High          0x80

#define Parametro_Input_Logig_Pulse_Low         0x00
#define Parametro_Input_Logig_Level_Low         0x00
#define Parametro_Input_Logig_Speed_Fast_Low    0x00
#define Parametro_Input_Logig_Speed_Nomi_Low    0x00
#define Parametro_Input_Logig_Releveling_Low    0x00
#define Parametro_Input_Logig_UPS_Low           0x00
#define Parametro_Input_Logig_Break_Low         0x00
#define Parametro_Input_Logig_Aux_Low           0x00

/* <------------------------------------------------------------------------> */

/* < Definicion ::: Macros Logica de Seguridades :: Parametros > */
#define Parametro_Input_Logig_Security_One_High 0x01
#define Parametro_Input_Logig_Security_Two_High 0x02
#define Parametro_Input_Logig_Door_Hall_High    0x04
#define Parametro_Input_Logig_Door_Cabin_High   0x08
#define Parametro_Input_Logig_Door_Swing_High   0x10
#define Parametro_Input_Logig_Review_Set_High   0x20
#define Parametro_Input_Logig_Review_Up_High    0x40
#define Parametro_Input_Logig_Review_Down_High  0x80

#define Parametro_Input_Logig_Security_One_Low  0x00
#define Parametro_Input_Logig_Security_Two_Low  0x00
#define Parametro_Input_Logig_Door_Hall_Low     0x00
#define Parametro_Input_Logig_Door_Cabin_Low    0x00
#define Parametro_Input_Logig_Door_Swing_Low    0x00
#define Parametro_Input_Logig_Review_Set_Low    0x00
#define Parametro_Input_Logig_Review_Up_Low     0x00
#define Parametro_Input_Logig_Review_Down_Low   0x00

/* <------------------------------------------------------------------------> */

/* < Definicion ::: Macros Salida de Variador :: Parametros > */
#define Parametro_Output_Inv_All_Clear          0x00
#define Parametro_Output_Inv_Way_Down_Set       0x01
#define Parametro_Output_Inv_Way_Up_Set         0x02
#define Parametro_Output_Inv_Speed_Nom_Set      0x04
#define Parametro_Output_Inv_Middle_Two_Set     0x08
#define Parametro_Output_Inv_Middle_One_Set     0x10
#define Parametro_Output_Inv_Review_Set         0x20
#define Parametro_Output_Inv_Level_Set          0x40

/* < Definicion ::: Macros Entrada Enable Securities Reset :: Parametros > */
#define Parametro_Reset_MovedLevelCabin         0x01
#define Parametro_Reset_RelevelingTimeDown      0x02
#define Parametro_Reset_RelevelingTimeUp        0x04
#define Parametro_Reset_OverflowLimitSpeed      0x08
#define Parametro_Reset_WrongDetectLimitSpeed   0x10       
#define Parametro_Reset_WrongSenseLevel         0x20    
#define Parametro_Reset_WtongSensePulse         0x40
#define Parametro_Reset_OverflowTimeTravel      0x80

/* <------------------------------------------------------------------------> */

/* < Definicion ::: Macros de Control Direccionamiento CAN (11Bits) :: Parametros > */

#define	ADDRESS_CAN_MAIN_MASK                   0x0007	// < Mascara del ID Principal
#define	ADDRESS_CAN_CALL_MASK                   0x0002	// < Mascara del ID Llamadas
#define	ADDRESS_CAN_DOOR_MASK                   0x0003	// < Mascara del ID Puertas
#define	ADDRESS_CAN_KEYS_MASK                   0x0004	// < Mascara del ID Llavines
#define	ADDRESS_CAN_GAME_MASK                   0x0006	// < Mascara del ID Programador

/* <------------------------------------------------------------------------> */

#define	ADDRESS_CAN_DRAWING_MASK                0x0001	// < Mascara del ID para Display
#define	ADDRESS_CAN_DRAWING_FLOOR               0x0009	// < Dibuja en Displays el Valor del Piso Actual
#define	ADDRESS_CAN_DRAWING_ARROWS              0x0011	// < Dibuja en Displays el Valor de la Flecha Actual
#define	ADDRESS_CAN_DRAWING_CALLS_CABIN         0x0019	// < Dibuja en Botones la Llamada de Piso Ultima Registrada En Cabina
#define	ADDRESS_CAN_DRAWING_CALLS_HALL_DW       0x0021	// < Dibuja en Botones la Llamada de Piso Ultima Registrada En Pasillo (Dirección Abajo)
#define	ADDRESS_CAN_DRAWING_CALLS_HALL_UP       0x0029	// < Dibuja en Botones la Llamada de Piso Ultima Registrada En Pasillo (Dirección Arriba)
#define	ADDRESS_CAN_DRAWING_MENSSEGES           0x0031	// < Dibuja en Displays el Valor de Mensajes de Error
		
/* <------------------------------------------------------------------------> */

#define	ADDRESS_CAN_REQUEST_CALL_QUERY          0x000A	// < Envia Peticion de Llamda Desde Botones Hacia Main Control
#define	ADDRESS_CAN_REQUEST_DOOR_QUERY          0x0013	// < Envia Peticion de Control de Puertas Hacia Main Control
#define	ADDRESS_CAN_REQUEST_KEYS_QUERY          0x001C	// < Envia Estado de Llavines hacia Main Control
			
/* <------------------------------------------------------------------------> */

#define	ADDRESS_CAN_SERIALS_GAME_CAT            0x000E	// < Primera Activacion de Programacion de Main Control, Requiere Review Enabled
#define	ADDRESS_CAN_PASSWRD_GAME_CAT            0x0016	// < Segunfa Activavion de Programacion de Main Control, Requiere Review Enabled
#define	ADDRESS_CAN_PROGRAM_GAME_CAT            0x001E	// < Habilita la Programacion de la Memoria del Main Control desde el Game//Cat
#define	ADDRESS_CAN_RECEIVE_GAME_CAT            0x0026	// < Habilita el Envio de Datos del Main Control al Game//Cat
#define	ADDRESS_CAN_REQUEST_GAME_CAT            0x002E	// < Envio de Respuesta de Main Control al Game//Cat
#define	ADDRESS_CAN_WORKING_GAME_CAT            0x0036	// < Habilitacion de Control de Maniobra, solo en Automatico....
#define	ADDRESS_CAN_STATUSS_GAME_CAT            0x003E	// < Envio constante de parametros de Estado del Main Control al Game//Cat
#define	ADDRESS_CAN_END_CTL_GAME_CAT            0x0046	// < Finaliza Cualquier control; Programacion, Lectura & Maniobra.
		
#define	ADDRESS_CAN_WRITE_DAT_GAME_CAT          0x004E	// < Lectura de una sola posicion de Memoria max de 32Bits, Habiltita el modo Bulk Lectura
#define	ADDRESS_CAN_READ_DATA_GAME_CAT          0x0056	// < Escritura de una sola posicion de Memoria max de 32Bits, Habiltita el modo Bulk Escritura
#define	ADDRESS_CAN_BULK_DATA_GAME_CAT          0x005E	// < Envio Masivo de Informacion, max 255 Bytes, requiere Habilitar el Modo Bulk en R/W
#define	ADDRESS_CAN_CLEAR_DAT_GAME_CAT          0x0066	// < Bora toda la Programacion de Parametros, no los Seriales
#define	ADDRESS_CAN_BLANK_DAT_GAME_CAT          0x006E	// < Borra toda la Meria Flash del Main Control...

/* < Variables ::: Globales Extern :: Parametros del Sistema > */
extern xControls_t xControls;
extern xParametersCAN_t xSystemParametersCAN;
extern const uint8_t *pxAddressxSystemParametersCAN[];
extern const uint8_t xSizexSystemParametersCAN[];

/* < Prototipo ::: Funciones de Control > */
void vReadSingleParametersCAN(void* pxAddress, uint8_t Size);
void vSaveSingleParametersCAN(void* pxAddress, uint8_t Size);
void vReadParametersCAN(void* pxAddress, uint8_t Size);
void vClearParametersCAN(void* pxAddress, uint8_t Size);
void vSavedParametersCAN(void* pxAddress, uint8_t Lenght);
void vSendSerialPassword(void* pxAddress, uint8_t Size);

#endif	/* < CONTROL_PARAMETERS_CAN_H > */

