/* < Include ::: Header > */
#include "control_parameters_can.h"

/* < Variables ::: Globales :: Registros del Sistema > */
xControls_t xControls = {
    /* < - Serial --------------------------------------------------------- > */
    .Board.Serial.Ascii[0] = '0', // < Serial de la Board, (2Bytes*Byte = 8 Valores)
    .Board.Serial.Ascii[1] = '0',
    .Board.Serial.Ascii[2] = '0',
    .Board.Serial.Ascii[3] = '0',
    .Board.Serial.Ascii[4] = '0',
    .Board.Serial.Ascii[5] = '0',
    .Board.Serial.Ascii[6] = '0',
    .Board.Serial.Ascii[7] = '1',
    /* < - Password ------------------------------------------------------- > */
    .Board.Password.Ascii[0] = '0', // < Llave de Cifrado de la Board, (2Bytes*Byte = 4 Valores)               
    .Board.Password.Ascii[1] = '0',
    .Board.Password.Ascii[2] = '0',
    .Board.Password.Ascii[3] = '0',
};

/* <------------------------------------------------------------------------> */

/* < Variables ::: Globales :: Parametros del Sistema en Rom... > */
xParametersCAN_t xSystemParametersCAN = {
    /* < - Parametros de Gestion ------------------------------------------ > */
    .Parametro.Tipo_Puerta = Parametro_Puerta_Automatica, // < Tipo de Bloqueo de Puerta (Automatico/Batiente/Manual)   
    .Parametro.Gestion_Cierre_Puerta = Parametro_Puerta_Cierre_Automatico, // < Indica si la Puerta de Cierra Automaticamente, Llamada o Manualmente            
    .Parametro.Gestion_Velocidad_Inversor = Parametro_Control_Inverter_Simple, // < Indica si el Control del Motor sera de Doble o Simple Velocidad...
    .Parametro.Modo_Hidrahulico = Parametro_Hidraulico_OFF, // < Modo de Renivelacion para Controles Hidrahulicos (On/Off) 
    .Parametro.Sensor_Hidrahulico = Parametro_Sensor_Hidraulico_OFF, // < Tercer Sensor de Renivelacion para Controles Hidrahulicos (On/Off)     
    .Parametro.Sensor_Unit_Power_Suply = Parametro_Sensor_Hidraulico_OFF, // < Control del Sensor de UPS  (On/Off)
    .Parametro.Sensor_Llave_Servicio = Parametro_Sensor_Service_ON, // < Control del Llave de Servicio
    .Parametro.Sensor_Llave_Bloqueo = Parametro_Sensor_MainBlock_OFF, // < Control del Llave de Bloqueo del Control Principal
    .Parametro.Borrado_Llamadas = Parametro_Borrado_Llamadas_OFF, // < Control de Borrado de Llamadas (On/Off)                     
    .Parametro.Gestion_Llamadas = Parametro_Gestion_Colectivo_Dual, // < Control de Llamadas (Simple/Viaje Subiendo (void*) & Bajando/Prioridad Subiendo/Prioridad Bajando/Prioridad Dual))        
    .Parametro.Gestion_Grupal = Parametro_Control_Grupal_OFF, // < Control de Gestion de Llamadas por Grupos RS485, (NULL) Deshabilitado
    .Parametro.Modo_Master_Slave = Parametro_Control_Grupal_Master, // < Control de Gestion de Llamadas por Grupos RS485, Control Maestro/Esclavo        
    .Parametro.Gestion_Numero_Slaves = Parametro_Max_Esclavos, // < Control de Gestion de Llamadas por Grupos RS485, Numero de Esclavos a Manipular     
    .Parametro.Modo_Auxiliar_Master = Parametro_Auxiliar_Master_OFF, // < Indica si En el modo Esclavo, Funcionara como Maestra en Ausencia de la Maestra Principal (Mayor Prioridad)
    .Parametro.Prioridad_Slave = NULL, // < Indica la Prioridad de la Tarjeta Esclava...                 
    /* < - Parametros de Puertas ------------------------------------------ > */
    .Puertas.Estado[0x00] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x01] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x02] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x03] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x04] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x05] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x06] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x07] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x08] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x09] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x0A] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x0B] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x0C] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x0D] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x0E] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x0F] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x10] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x11] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x12] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x13] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x14] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x15] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x16] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x17] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x18] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x19] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x1A] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x1B] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x1C] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x1D] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x1E] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    .Puertas.Estado[0x1F] = Parametro_Puerta_Apertura_Delantera, // < Indica la Cantidad de Puertas a Gestionar...
    /* < - Parametros de Control ------------------------------------------ > */
    .Control.Numero_Puertas = Parametro_Puerta_Single, // < Indica la Cantidad de Puerta a Controlar (Maximo 2, Minimo 1)
    .Control.Numero_Max_Pisos = (8), // < Numero Maximo de Pisos (Max 32 pisos)...
    .Control.Numero_Max_Sotanos = Parametro_Min_Sotanos, // < Numero de Sotanos para Gestion de Llamdas ::: Solo Aplica para Modo (Prioridad...)
    .Control.Numero_Retorno_Cabina = (0), // < Numero de Piso de Retorno de Automatico ::: (0) Desactivado...        
    .Control.Numero_Retorno_Bombero = (0), // < Numero de Piso de Retorno a Piso de Emergancia por Llavin de Bomberos ::: (0) Desactivado...Maximo        
    .Control.Numero_Limite_Viajes = (0), // < Numero de Piso de Viajes Maximos de Matenimiento ::: (0) Desactivado...
    /* < - Parametros de Tiempo ------------------------------------------- > */
    .Tiempo.Start_Post = (1), // < Tiempo en Segundos, Iniciar el Ascensor (PC:0x00)
    .Tiempo.Reconocimiento_Subiendo = (15), // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
    .Tiempo.Reconocimiento_Intermedio = (60), // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
    .Tiempo.Reconocimiento_Bajando = (30), // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
    .Tiempo.Renivelacion_Cabina_Subiendo = (10), // < Tiempo en Segundos, Disparar Error de Renivelacion de Cabina Subiendo...
    .Tiempo.Renivelacion_Cabina_Bajando = (10), // < Tiempo en Segundos, Disparar Error de Renivelacion de Cabina Bajando...
    .Tiempo.Atender_Boton_Cerrar = (3), // < Tiempo en Segundos, Atender Boton de Cierre de Puerta ::: Solo Aplica Puerta Automatica...
    .Tiempo.Atender_Boton_Abrir = (3), // < Tiempo en Segundos, Atender Botones Luego de Accion de Reapertura ::: Solo Aplica para Puerta Automatica...
    .Tiempo.Accion_Cerrar_Puerta = (6), // < Tiempo en Segundos, Cerrar Puerta ::: Solo Aplica Puerta Automatica/Batiente/Manual...    
    .Tiempo.Retorno_Cabina = (10), // < Tiempo en Minutos, Disparo de Viaje de Cabina a Origen...         
    .Tiempo.Viaje_Entre_Pisos_Cabina = (15), // < Tiempo en Segundos, Disparo de Error, Seguridad de Viaje de Cabina...         
    .Tiempo.Apagar_Luz_Cabina = (1), // < Tiempo en Minutos, Habilatacion de Luz de Cabina...   
    .Tiempo.Inicio_Sonido_Cabina = (30), // < Tiempo en Segundos, Habilatacion de Sonido de Puerta...
    .Tiempo.Chequeo_Limites_Velocidad = (10), // < Tiempo en Segundos, Habilatacion de Chequeo de Seguidad de Limites
    .Tiempo.Reinicio_Error_Sistema = (10), // < Tiempo en Minutos, Reinicia el Control Luego de Agotar el Tiempo luego de Disparo por Error..
    .Tiempo.Incio_Viaje_Cabina = (1), // < Tiempo en Milisegundos, Espera para Arrancar Viaje Luego de Cerrar Puertas
    .Tiempo.Final_Viaje_Cabina = (1), // < Tiempo en Milisegundos, Entre La parada y la Apertura de Puertas.    
    .Tiempo.Enganche_Puerta_Batiente = (1), // < Tiempo en Milisegundos, Para Asegurar la Puerta en modo Batiente...
    /* < - Logica de Entrada Sensores ------------------------------------- > */
    .Input.LogicSenses.RegisterSenses = Parametro_Input_Logig_Pulse_Low | Parametro_Input_Logig_Level_Low | Parametro_Input_Logig_Speed_Fast_Low | Parametro_Input_Logig_Speed_Nomi_Low | Parametro_Input_Logig_Releveling_Low | Parametro_Input_Logig_UPS_Low | Parametro_Input_Logig_Break_Low | Parametro_Input_Logig_Aux_Low,
    /* < - Logica de Entrada Seguridades ---------------------------------- > */
    .Input.LogicSecurities.RegisterSecurties = (Parametro_Input_Logig_Security_One_Low | Parametro_Input_Logig_Security_Two_Low | Parametro_Input_Logig_Door_Hall_Low | Parametro_Input_Logig_Door_Cabin_Low | Parametro_Input_Logig_Door_Swing_Low | Parametro_Input_Logig_Review_Set_Low | Parametro_Input_Logig_Review_Up_Low | Parametro_Input_Logig_Review_Down_Low),
    /* < - Logica de Salida de Relays - Stop ------------------------------ > */
    .Outputs.LogicStop.RegisterRelays = (Parametro_Output_Inv_All_Clear),
    /* < - Logica de Salida de Relays - Level Up -------------------------- > */
    .Outputs.LogicNivelacionArriba.RegisterRelays = (Parametro_Output_Inv_Level_Set | Parametro_Output_Inv_Way_Up_Set),
    /* < - Logica de Salida de Relays - Review Up ------------------------- > */
    .Outputs.LogicRevisionArriba.RegisterRelays = (Parametro_Output_Inv_Review_Set | Parametro_Output_Inv_Way_Up_Set),
    /* < - Logica de Salida de Relays - Middle One Up --------------------- > */
    .Outputs.LogicIntermediaUnoArriba.RegisterRelays = (Parametro_Output_Inv_Middle_One_Set | Parametro_Output_Inv_Way_Up_Set),
    /* < - Logica de Salida de Relays - Middle Two Up --------------------- > */
    .Outputs.LogicIntermediaDosArriba.RegisterRelays = (Parametro_Output_Inv_Middle_Two_Set | Parametro_Output_Inv_Way_Up_Set),
    /* < - Logica de Salida de Relays - Nominal Up ------------------------ > */
    .Outputs.LogicNominalArriba.RegisterRelays = (Parametro_Output_Inv_Speed_Nom_Set | Parametro_Output_Inv_Way_Up_Set),
    /* < - Logica de Salida de Relays - Level Down ------------------------ > */
    .Outputs.LogicNivelacionBajando.RegisterRelays = (Parametro_Output_Inv_Level_Set | Parametro_Output_Inv_Way_Down_Set),
    /* < - Logica de Salida de Relays - LReview Down ---------------------- > */
    .Outputs.LogicRevisionBajando.RegisterRelays = (Parametro_Output_Inv_Review_Set | Parametro_Output_Inv_Way_Down_Set),
    /* < - Logica de Salida de Relays - Middle One Down ------------------- > */
    .Outputs.LogicIntermediaUnoBajando.RegisterRelays = (Parametro_Output_Inv_Middle_One_Set | Parametro_Output_Inv_Way_Down_Set),
    /* < - Logica de Salida de Relays - Middle Two Down ------------------- > */
    .Outputs.LogicIntermediaDosBajando.RegisterRelays = (Parametro_Output_Inv_Middle_Two_Set | Parametro_Output_Inv_Way_Down_Set),
    /* < - Logica de Salida de Relays - Nominal Down ---------------------- > */
    .Outputs.LogicNominalBajando.RegisterRelays = (Parametro_Output_Inv_Speed_Nom_Set | Parametro_Output_Inv_Way_Down_Set),
    /* < - Logica Activacion Seguridades ---------------------------------- > */
    .Securities.EnableControlReset.FlagsResetError = (Parametro_Reset_MovedLevelCabin | Parametro_Reset_RelevelingTimeDown | Parametro_Reset_RelevelingTimeUp | Parametro_Reset_OverflowLimitSpeed | Parametro_Reset_WrongDetectLimitSpeed | Parametro_Reset_WrongSenseLevel | Parametro_Reset_WtongSensePulse | Parametro_Reset_OverflowTimeTravel),
    /* < - Parametros de Comunicacion ------------------------------------------ > */
    .Communication.Velocidad_BUSCAN = Paramero_Velcidad_BusCAN_Low, // < Seleccion de Velocidad del BUS.CAN (100Khz, 250Khz, 500Khz) (LOW, MED, HIG)    
};

/* <------------------------------------------------------------------------> */

const uint8_t __attribute__((space(psv))) * pxAddressxSystemParametersCAN[] = {
    /* < - Parametros de Gestion ------------------------------------------ > */
    (void*) &xSystemParametersCAN.Parametro.Tipo_Puerta, // < Tipo de Bloqueo de Puerta (Automatico/Batiente/Manual)   
    (void*) &xSystemParametersCAN.Parametro.Gestion_Cierre_Puerta, // < Indica si la Puerta de Cierra Automaticamente, Llamada o Manualmente            
    (void*) &xSystemParametersCAN.Parametro.Gestion_Velocidad_Inversor, // < Indica si el Control del Motor sera de Doble o Simple Velocidad...
    (void*) &xSystemParametersCAN.Parametro.Modo_Hidrahulico, // < Modo de Renivelacion para Controles Hidrahulicos (On/Off) 
    (void*) &xSystemParametersCAN.Parametro.Sensor_Hidrahulico, // < Tercer Sensor de Renivelacion para Controles Hidrahulicos (On/Off)     
    (void*) &xSystemParametersCAN.Parametro.Sensor_Unit_Power_Suply, // < Control del Sensor de UPS  (On/Off)
    (void*) &xSystemParametersCAN.Parametro.Sensor_Llave_Servicio, // < Control del Llave de Servicio
    (void*) &xSystemParametersCAN.Parametro.Sensor_Llave_Bloqueo, // < Control del Llave de Bloqueo del Control Principal
    (void*) &xSystemParametersCAN.Parametro.Borrado_Llamadas, // < Control de Borrado de Llamadas (On/Off)                     
    (void*) &xSystemParametersCAN.Parametro.Gestion_Llamadas, // < Control de Llamadas (Simple/Viaje Subiendo (void*) & Bajando/Prioridad Subiendo/Prioridad Bajando/Prioridad Dual))        
    (void*) &xSystemParametersCAN.Parametro.Gestion_Grupal, // < Control de Gestion de Llamadas por Grupos RS485, (NULL) Deshabilitado
    (void*) &xSystemParametersCAN.Parametro.Modo_Master_Slave, // < Control de Gestion de Llamadas por Grupos RS485, Control Maestro/Esclavo        
    (void*) &xSystemParametersCAN.Parametro.Gestion_Numero_Slaves, // < Control de Gestion de Llamadas por Grupos RS485, Numero de Esclavos a Manipular     
    (void*) &xSystemParametersCAN.Parametro.Modo_Auxiliar_Master, // < Indica si En el modo Esclavo, Funcionara como Maestra en Ausencia de la Maestra Principal (Mayor Prioridad)
    (void*) &xSystemParametersCAN.Parametro.Prioridad_Slave, // < Indica la Prioridad de la Tarjeta Esclava...   
    /* < - Parametros de Puertas ------------------------------------------ > */
    (void*) &xSystemParametersCAN.Puertas.Estado, // < Indica el Numero de Piso, que Puerta se debe Abrir, (Uno, Dos ó Ambas) 
    /* < - Parametros de Control ------------------------------------------ > */
    (void*) &xSystemParametersCAN.Control.Numero_Max_Pisos, // < Numero Maximo de Pisos (Max 32 pisos)...
    (void*) &xSystemParametersCAN.Control.Numero_Max_Sotanos, // < Numero de Sotanos para Gestion de Llamdas ::: Solo Aplica para Modo (Prioridad...)
    (void*) &xSystemParametersCAN.Control.Numero_Retorno_Cabina, // < Numero de Piso de Retorno de Automatico ::: (NULL) Desactivado...        
    (void*) &xSystemParametersCAN.Control.Numero_Retorno_Bombero, // < Numero de Piso de Retorno a Piso de Emergancia por Llavin de Bomberos ::: (0x00) Desactivado...Maximo        
    (void*) &xSystemParametersCAN.Control.Numero_Limite_Viajes, // < Numero de Piso de Viajes Maximos de Matenimiento ::: (NULL) Desactivado...
    /* < - Parametros de Tiempo ------------------------------------------- > */
    (void*) &xSystemParametersCAN.Tiempo.Start_Post, // < Tiempo en Segundos, Iniciar el Ascensor (PC:0x00)
    (void*) &xSystemParametersCAN.Tiempo.Reconocimiento_Subiendo, // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
    (void*) &xSystemParametersCAN.Tiempo.Reconocimiento_Intermedio, // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
    (void*) &xSystemParametersCAN.Tiempo.Reconocimiento_Bajando, // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
    (void*) &xSystemParametersCAN.Tiempo.Renivelacion_Cabina_Subiendo, // < Tiempo en Segundos, Disparar Error de Renivelacion de Cabina Subiendo...
    (void*) &xSystemParametersCAN.Tiempo.Renivelacion_Cabina_Bajando, // < Tiempo en Segundos, Disparar Error de Renivelacion de Cabina Bajando...
    (void*) &xSystemParametersCAN.Tiempo.Atender_Boton_Cerrar, // < Tiempo en Segundos, Atender Boton de Cierre de Puerta ::: Solo Aplica Puerta Automatica...
    (void*) &xSystemParametersCAN.Tiempo.Atender_Boton_Abrir, // < Tiempo en Segundos, Atender Botones Luego de Accion de Reapertura ::: Solo Aplica para Puerta Automatica...
    (void*) &xSystemParametersCAN.Tiempo.Accion_Cerrar_Puerta, // < Tiempo en Segundos, Cerrar Puerta ::: Solo Aplica Puerta Automatica/Batiente/Manual...    
    (void*) &xSystemParametersCAN.Tiempo.Retorno_Cabina, // < Tiempo en Minutos, Disparo de Viaje de Cabina a Origen...         
    (void*) &xSystemParametersCAN.Tiempo.Viaje_Entre_Pisos_Cabina, // < Tiempo en Segundos, Disparo de Error, Seguridad de Viaje de Cabina...         
    (void*) &xSystemParametersCAN.Tiempo.Apagar_Luz_Cabina, // < Tiempo en Minutos, Habilatacion de Luz de Cabina...   
    (void*) &xSystemParametersCAN.Tiempo.Inicio_Sonido_Cabina, // < Tiempo en Segundos, Habilatacion de Sonido de Puerta...
    (void*) &xSystemParametersCAN.Tiempo.Chequeo_Limites_Velocidad, // < Tiempo en Segundos, Habilatacion de Chequeo de Seguidad de Limites
    (void*) &xSystemParametersCAN.Tiempo.Reinicio_Error_Sistema, // < Tiempo en Minutos, Reinicia el Control Luego de Agotar el Tiempo luego de Disparo por Error..
    (void*) &xSystemParametersCAN.Tiempo.Incio_Viaje_Cabina, // < Tiempo en Milisegundos, Espera para Arrancar Viaje Luego de Cerrar Puertas
    (void*) &xSystemParametersCAN.Tiempo.Final_Viaje_Cabina, // < Tiempo en Milisegundos, Entre La parada y la Apertura de Puertas.
    (void*) &xSystemParametersCAN.Tiempo.Enganche_Puerta_Batiente, // < Tiempo en Milisegundos, Para Asegurar la Puerta en modo Batiente...
    /* < - Logica de Entrada Sensores & Seguridades ----------------------- > */
    (void*) &xSystemParametersCAN.Input.LogicSenses,
    (void*) &xSystemParametersCAN.Input.LogicSecurities,
    /* < - Logica de Salida de Relays ------------------------------------- > */
    (void*) &xSystemParametersCAN.Outputs.LogicStop,
    (void*) &xSystemParametersCAN.Outputs.LogicNivelacionArriba,
    (void*) &xSystemParametersCAN.Outputs.LogicRevisionArriba,
    (void*) &xSystemParametersCAN.Outputs.LogicIntermediaUnoArriba,
    (void*) &xSystemParametersCAN.Outputs.LogicIntermediaDosArriba,
    (void*) &xSystemParametersCAN.Outputs.LogicNominalArriba,
    (void*) &xSystemParametersCAN.Outputs.LogicNivelacionBajando,
    (void*) &xSystemParametersCAN.Outputs.LogicRevisionBajando,
    (void*) &xSystemParametersCAN.Outputs.LogicIntermediaUnoBajando,
    (void*) &xSystemParametersCAN.Outputs.LogicIntermediaDosBajando,
    (void*) &xSystemParametersCAN.Outputs.LogicNominalBajando,
    /* < - Logica Activacion Seguridades ---------------------------------- > */
    (void*) &xSystemParametersCAN.Securities.EnableControlReset,
    /* < - Parametros de Comunicacion ------------------------------------- > */
    (void*) &xSystemParametersCAN.Communication.Velocidad_BUSCAN, // < Seleccion de Velocidad del BUS.CAN (100Khz, 250Khz, 500Khz) (LOW, MED, HIG)    
};

const uint8_t __attribute__((space(psv))) xSizexSystemParametersCAN[] = {
    /* < - Parametros de Gestion ------------------------------------------ > */
    sizeof (xSystemParametersCAN.Parametro.Tipo_Puerta), // < Tipo de Bloqueo de Puerta (Automatico/Batiente/Manual)   
    sizeof (xSystemParametersCAN.Parametro.Gestion_Cierre_Puerta), // < Indica si la Puerta de Cierra Automaticamente, Llamada o Manualmente            
    sizeof (xSystemParametersCAN.Parametro.Gestion_Velocidad_Inversor), // < Indica si el Control del Motor sera de Doble o Simple Velocidad...
    sizeof (xSystemParametersCAN.Parametro.Modo_Hidrahulico), // < Modo de Renivelacion para Controles Hidrahulicos (On/Off) 
    sizeof (xSystemParametersCAN.Parametro.Sensor_Hidrahulico), // < Tercer Sensor de Renivelacion para Controles Hidrahulicos (On/Off)     
    sizeof (xSystemParametersCAN.Parametro.Sensor_Unit_Power_Suply), // < Control del Sensor de UPS  (On/Off)
    sizeof (xSystemParametersCAN.Parametro.Sensor_Llave_Servicio), // < Control del Llave de Servicio
    sizeof (xSystemParametersCAN.Parametro.Sensor_Llave_Bloqueo), // < Control del Llave de Bloqueo del Control Principal
    sizeof (xSystemParametersCAN.Parametro.Borrado_Llamadas), // < Control de Borrado de Llamadas (On/Off)                     
    sizeof (xSystemParametersCAN.Parametro.Gestion_Llamadas), // < Control de Llamadas (Simple/Viaje Subiendo sizeof ( Bajando/Prioridad Subiendo/Prioridad Bajando/Prioridad Dual))        
    sizeof (xSystemParametersCAN.Parametro.Gestion_Grupal), // < Control de Gestion de Llamadas por Grupos RS485, (NULL) Deshabilitado
    sizeof (xSystemParametersCAN.Parametro.Modo_Master_Slave), // < Control de Gestion de Llamadas por Grupos RS485, Control Maestro/Esclavo        
    sizeof (xSystemParametersCAN.Parametro.Gestion_Numero_Slaves), // < Control de Gestion de Llamadas por Grupos RS485, Numero de Esclavos a Manipular     
    sizeof (xSystemParametersCAN.Parametro.Modo_Auxiliar_Master), // < Indica si En el modo Esclavo, Funcionara como Maestra en Ausencia de la Maestra Principal (Mayor Prioridad)
    sizeof (xSystemParametersCAN.Parametro.Prioridad_Slave), // < Indica la Prioridad de la Tarjeta Esclava...   
    /* < - Parametros de Puertas ------------------------------------------ > */
    sizeof (xSystemParametersCAN.Puertas.Estado), // < Indica el Numero de Piso, que Puerta se debe Abrir, (Uno, Dos ó Ambas) 
    /* < - Parametros de Control ------------------------------------------ > */
    sizeof (xSystemParametersCAN.Control.Numero_Max_Pisos), // < Numero Maximo de Pisos (Max 32 pisos)...
    sizeof (xSystemParametersCAN.Control.Numero_Max_Sotanos), // < Numero de Sotanos para Gestion de Llamdas ::: Solo Aplica para Modo (Prioridad...)
    sizeof (xSystemParametersCAN.Control.Numero_Retorno_Cabina), // < Numero de Piso de Retorno de Automatico ::: (NULL) Desactivado...        
    sizeof (xSystemParametersCAN.Control.Numero_Retorno_Bombero), // < Numero de Piso de Retorno a Piso de Emergancia por Llavin de Bomberos ::: (0x00) Desactivado...Maximo        
    sizeof (xSystemParametersCAN.Control.Numero_Limite_Viajes), // < Numero de Piso de Viajes Maximos de Matenimiento ::: (NULL) Desactivado...
    /* < - Parametros de Tiempo ------------------------------------------- > */
    sizeof (xSystemParametersCAN.Tiempo.Start_Post), // < Tiempo en Segundos, Iniciar el Ascensor (PC:0x00)
    sizeof (xSystemParametersCAN.Tiempo.Reconocimiento_Subiendo), // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
    sizeof (xSystemParametersCAN.Tiempo.Reconocimiento_Intermedio), // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
    sizeof (xSystemParametersCAN.Tiempo.Reconocimiento_Bajando), // < Tiempo en Segundos, Disparar Error de Nivelacion de Reconocimiento...
    sizeof (xSystemParametersCAN.Tiempo.Renivelacion_Cabina_Subiendo), // < Tiempo en Segundos, Disparar Error de Renivelacion de Cabina Subiendo...
    sizeof (xSystemParametersCAN.Tiempo.Renivelacion_Cabina_Bajando), // < Tiempo en Segundos, Disparar Error de Renivelacion de Cabina Bajando...
    sizeof (xSystemParametersCAN.Tiempo.Atender_Boton_Cerrar), // < Tiempo en Segundos, Atender Boton de Cierre de Puerta ::: Solo Aplica Puerta Automatica...
    sizeof (xSystemParametersCAN.Tiempo.Atender_Boton_Abrir), // < Tiempo en Segundos, Atender Botones Luego de Accion de Reapertura ::: Solo Aplica para Puerta Automatica...
    sizeof (xSystemParametersCAN.Tiempo.Accion_Cerrar_Puerta), // < Tiempo en Segundos, Cerrar Puerta ::: Solo Aplica Puerta Automatica/Batiente/Manual...    
    sizeof (xSystemParametersCAN.Tiempo.Retorno_Cabina), // < Tiempo en Minutos, Disparo de Viaje de Cabina a Origen...         
    sizeof (xSystemParametersCAN.Tiempo.Viaje_Entre_Pisos_Cabina), // < Tiempo en Segundos, Disparo de Error, Seguridad de Viaje de Cabina...         
    sizeof (xSystemParametersCAN.Tiempo.Apagar_Luz_Cabina), // < Tiempo en Minutos, Habilatacion de Luz de Cabina...   
    sizeof (xSystemParametersCAN.Tiempo.Inicio_Sonido_Cabina), // < Tiempo en Segundos, Habilatacion de Sonido de Puerta...
    sizeof (xSystemParametersCAN.Tiempo.Chequeo_Limites_Velocidad), // < Tiempo en Segundos, Habilatacion de Chequeo de Seguidad de Limites
    sizeof (xSystemParametersCAN.Tiempo.Reinicio_Error_Sistema), // < Tiempo en Minutos, Reinicia el Control Luego de Agotar el Tiempo luego de Disparo por Error..
    sizeof (xSystemParametersCAN.Tiempo.Incio_Viaje_Cabina), // < Tiempo en Milisegundos, Espera para Arrancar Viaje Luego de Cerrar Puertas
    sizeof (xSystemParametersCAN.Tiempo.Final_Viaje_Cabina), // < Tiempo en Milisegundos, Entre La parada y la Apertura de Puertas.
    sizeof (xSystemParametersCAN.Tiempo.Enganche_Puerta_Batiente), // < Tiempo en Milisegundos, Para Asegurar la Puerta en modo Batiente...
    /* < - Logica de Entrada Sensores & Seguridades ----------------------- > */
    sizeof (xSystemParametersCAN.Input.LogicSenses),
    sizeof (xSystemParametersCAN.Input.LogicSecurities),
    /* < - Logica de Salida de Relays ------------------------------------- > */
    sizeof (xSystemParametersCAN.Outputs.LogicStop),
    sizeof (xSystemParametersCAN.Outputs.LogicNivelacionArriba),
    sizeof (xSystemParametersCAN.Outputs.LogicRevisionArriba),
    sizeof (xSystemParametersCAN.Outputs.LogicIntermediaUnoArriba),
    sizeof (xSystemParametersCAN.Outputs.LogicIntermediaDosArriba),
    sizeof (xSystemParametersCAN.Outputs.LogicNominalArriba),
    sizeof (xSystemParametersCAN.Outputs.LogicNivelacionBajando),
    sizeof (xSystemParametersCAN.Outputs.LogicRevisionBajando),
    sizeof (xSystemParametersCAN.Outputs.LogicIntermediaUnoBajando),
    sizeof (xSystemParametersCAN.Outputs.LogicIntermediaDosBajando),
    sizeof (xSystemParametersCAN.Outputs.LogicNominalBajando),
    /* < - Logica Activacion Seguridades ---------------------------------- > */
    sizeof (xSystemParametersCAN.Securities.EnableControlReset),
    /* < - Parametros de Comunicacion ------------------------------------- > */
    sizeof (xSystemParametersCAN.Communication.Velocidad_BUSCAN), // < Seleccion de Velocidad del BUS.CAN (100Khz, 250Khz, 500Khz) (LOW, MED, HIG)    
};

/* <------------------------------------------------------------------------> */

/* < Prototipo ::: Funciones de Control > */
void vReadSingleParametersCAN(void* pxAddress, uint8_t Size) {
    /* < Variables ::: Locales > */
    uint8_t CounterAddress;
    uint8_t BufferSendCAN[3] = {0, 0, 0};
    /* < Find ::: Address Pointer of Variables > */
    for (CounterAddress = 0; CounterAddress < sizeof (pxAddressxSystemParametersCAN); CounterAddress++) {
        /* < Compare ::: Address of Variable > */
        if (pxAddress == pxAddressxSystemParametersCAN[CounterAddress]) {
            /* < Stop ::: Execute For... > */
            break;
        }
    }
    /* < Copiled ::: Data to Send... > */
    BufferSendCAN[0] = pdClear; // < Write Data in Mode No Bulk...
    BufferSendCAN[1] = CounterAddress; // < Start Address Program Data...        
    BufferSendCAN[2] = Size; // < Size of Program Data (Buffer Size)...
    /* < Send ::: Menssege Into de Bus CAN... (Set Program Device... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_RECEIVE_GAME_CAT, 0, NULL, CAN_MESSAGE_RTR, CAN_FRAME_STD, CAN_BUFFER_CTRL_ZERO);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
    /* <  > */
    vCANModuleSendMessege(ADDRESS_CAN_READ_DATA_GAME_CAT, sizeof (BufferSendCAN), BufferSendCAN, CAN_MESSAGE_DATA, CAN_FRAME_STD, CAN_BUFFER_CTRL_ONE);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
    /* < Send ::: Menssege Into de Bus CAN... (Clear Program Device... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_END_CTL_GAME_CAT, 0, NULL, CAN_MESSAGE_RTR, CAN_FRAME_STD, CAN_BUFFER_CTRL_TWO);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
}

void vSaveSingleParametersCAN(void* pxAddress, uint8_t Size) {
    /* < Variables ::: Locales > */
    uint8_t CounterAddress;
    uint8_t BufferSendCAN[7] = {0, 0, 0, 0, 0, 0, 0};
    /* < Find ::: Address Pointer of Variables > */
    for (CounterAddress = 0; CounterAddress < sizeof (pxAddressxSystemParametersCAN); CounterAddress++) {
        /* < Compare ::: Address of Variable > */
        if (pxAddress == pxAddressxSystemParametersCAN[CounterAddress]) {
            /* < Stop ::: Execute For... > */
            break;
        }
    }
    /* < Copiled ::: Data to Send... > */
    BufferSendCAN[0] = pdClear; // < Write Data in Mode No Bulk...
    BufferSendCAN[1] = CounterAddress; // < Start Address Program Data...        
    BufferSendCAN[2] = Size; // < Size of Program Data (Buffer Size)...
    memcpy(&BufferSendCAN[3], pxAddress, Size);
    /* < Send ::: Menssege Into de Bus CAN... (Set Program Device... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_PROGRAM_GAME_CAT, 0, NULL, CAN_MESSAGE_RTR, CAN_FRAME_STD, CAN_BUFFER_CTRL_ZERO);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
    /* < Send ::: Menssege Into de Bus CAN... (Set Option to Program Device... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_WRITE_DAT_GAME_CAT, sizeof (BufferSendCAN), BufferSendCAN, CAN_MESSAGE_DATA, CAN_FRAME_STD, CAN_BUFFER_CTRL_ONE);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
    /* < Send ::: Menssege Into de Bus CAN... (Clear Program Device... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_END_CTL_GAME_CAT, 0, NULL, CAN_MESSAGE_RTR, CAN_FRAME_STD, CAN_BUFFER_CTRL_ONE);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
}

void vReadParametersCAN(void* pxAddress, uint8_t Size) {
    /* < Variables ::: Locales > */
    uint8_t Counter = 0;
    uint8_t BufferSendCAN[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    /* < Find ::: Address Pointer of Variables > */
    for (Counter = 0; Counter < sizeof (pxAddressxSystemParametersCAN); Counter++) {
        /* < Compare ::: Address of Variable > */
        if (pxAddress == pxAddressxSystemParametersCAN[Counter]) {
            /* < Stop ::: Execute For... > */
            break;
        }
    }
    /* < Send ::: Menssege Into de Bus CAN... (Set Program Device... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_RECEIVE_GAME_CAT, 0, NULL, CAN_MESSAGE_RTR, CAN_FRAME_STD, CAN_BUFFER_CTRL_ZERO);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
    /* < Send ::: Menssege Into de Bus CAN... (Set Option to Program Device... ) > */
    if (Size > sizeof (uint32_t)) BufferSendCAN[0] = pdSet; // < Write Data in Mode Bulk...      
    BufferSendCAN[1] = Counter; // < Start Address Program Data...    
    BufferSendCAN[2] = Size; // < Size of Program Data (Buffer Size in Fragment Bytes*8).....    
    vCANModuleSendMessege(ADDRESS_CAN_READ_DATA_GAME_CAT, 3, BufferSendCAN, CAN_MESSAGE_DATA, CAN_FRAME_STD, CAN_BUFFER_CTRL_ONE);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
    /* < Send ::: Menssege Into de Bus CAN... (Set Read Device... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_BULK_DATA_GAME_CAT, 0, NULL, CAN_MESSAGE_RTR, CAN_FRAME_STD, CAN_BUFFER_CTRL_TWO);
    /* < Delay ::: Working Main Board > */
    __delay_ms(500);
    /* < Send ::: Menssege Into de Bus CAN... (Clear Program Device... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_END_CTL_GAME_CAT, 0, NULL, CAN_MESSAGE_RTR, CAN_FRAME_STD, CAN_BUFFER_CTRL_TWO);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
}

void vClearParametersCAN(void* pxAddress, uint8_t Size) {
    /* < Clear ::: Register Memory Ram> */
    memset(pxAddress, 0, Size);
}

void vSavedParametersCAN(void* pxAddress, uint8_t Lenght) {
    /* < Variables ::: Locales > */
    uint8_t CounterAddress = 8;
    uint8_t CounterBuffer = 8;
    uint8_t CounterPointer = 0;
    uint8_t BufferSendCAN[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    /* < Find ::: Address Pointer of Variables > */
    for (CounterAddress = 0; CounterAddress < sizeof (pxAddressxSystemParametersCAN); CounterAddress++) {
        /* < Compare ::: Address of Variable > */
        if (pxAddress == pxAddressxSystemParametersCAN[CounterAddress]) {
            /* < Stop ::: Execute For... > */
            break;
        }
    }
    /* < Send ::: Menssege Into de Bus CAN... (Set Program Device... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_PROGRAM_GAME_CAT, 0, NULL, CAN_MESSAGE_RTR, CAN_FRAME_STD, CAN_BUFFER_CTRL_ZERO);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
    /* < Send ::: Menssege Into de Bus CAN... (Set Option to Program Device... ) > */
    if (Lenght > sizeof (uint32_t)) {
        BufferSendCAN[0] = pdSet; // < Write Data in Mode Bulk...
        BufferSendCAN[1] = CounterAddress; // < Start Address Program Data...        
        BufferSendCAN[2] = Lenght; // < Size of Program Data (Buffer Size in Fragment Bytes*8)...
        vCANModuleSendMessege(ADDRESS_CAN_WRITE_DAT_GAME_CAT, 3, BufferSendCAN, CAN_MESSAGE_DATA, CAN_FRAME_STD, CAN_BUFFER_CTRL_ONE);
        /* < Delay ::: Working Main Board > */
        __delay_ms(100);
        /* < Set ::: ConterBuffer a Lenght Data > */
        if (Lenght < 8) CounterBuffer = Lenght;
        /* < Send ::: Buffer Data... > */
        do {
            /* < Copy ::: Data tu Buffer > */
            memcpy(BufferSendCAN, (pxAddress + CounterPointer), CounterBuffer);
            /* < Send ::: Menssege Into de Bus CAN... (Send Pakage Data... ) > */
            vCANModuleSendMessege(ADDRESS_CAN_BULK_DATA_GAME_CAT, CounterBuffer, BufferSendCAN, CAN_MESSAGE_DATA, CAN_FRAME_STD, CAN_BUFFER_CTRL_TWO);
            /* < Delay ::: Working Main Board > */
            __delay_ms(200);
            /* < Set ::: Next Size for CounterBuffer > */
            CounterPointer = (CounterPointer + CounterBuffer);
            Lenght = (Lenght - CounterBuffer);
            if (Lenght < 8) CounterBuffer = Lenght;
        } while (CounterBuffer);
    } else {
        BufferSendCAN[0] = pdClear; // < Write Data in Mode Double Word...
        BufferSendCAN[1] = CounterAddress; // < Start Address Program Data...        
        BufferSendCAN[2] = Lenght; // < Size of Program Data (Buffer Size)...
        /* < Copy ::: Data tu Buffer > */
        memcpy(&BufferSendCAN[3], pxAddress, Lenght);
        /* < Send ::: Menssege Into de Bus CAN... (Send Pakage Data... ) > */
        vCANModuleSendMessege(ADDRESS_CAN_WRITE_DAT_GAME_CAT, (Lenght + 3), BufferSendCAN, CAN_MESSAGE_DATA, CAN_FRAME_STD, CAN_BUFFER_CTRL_ZERO);
        /* < Delay ::: Working Main Board > */
        __delay_ms(100);
    }
    /* < Send ::: Menssege Into de Bus CAN... (Clear Program Device... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_END_CTL_GAME_CAT, 0, NULL, CAN_MESSAGE_RTR, CAN_FRAME_STD, CAN_BUFFER_CTRL_ONE);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
}

void vSendSerialPassword(void* pxAddress, uint8_t Size) {
    /* < Variables ::: Locales > */
    uint8_t BufferSendCAN[8];
    /* < Copy ::: Data tu Buffer > */
    memcpy(BufferSendCAN, pxAddress, Size);
    /* < Send ::: Menssege Into de Bus CAN... (Set Serial Board... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_SERIALS_GAME_CAT, Size, BufferSendCAN, CAN_MESSAGE_DATA, CAN_FRAME_STD, CAN_BUFFER_CTRL_ONE);
    /* < Delay ::: Working Main Board > */
    __delay_ms(100);
    /* < Copy ::: Data tu Buffer > */
    memcpy(BufferSendCAN, (pxAddress + 8U), (Size - 4U));
    /* < Send ::: Menssege Into de Bus CAN... (Set Serial Board... ) > */
    vCANModuleSendMessege(ADDRESS_CAN_PASSWRD_GAME_CAT, (Size - 4U), BufferSendCAN, CAN_MESSAGE_DATA, CAN_FRAME_STD, CAN_BUFFER_CTRL_ONE);
}
