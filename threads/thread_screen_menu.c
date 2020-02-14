/* < Configuracion ::: Header > */
#include "source_config_system.h"

/* < Declaración de Variables ::: Until Delay > */
#define TimeRecurring_t (TickType_t)(100 / portTICK_PERIOD_MS)
static TickType_t xLastWakeControlMenu;
/* < Declaración de Variables ::: Banderas de Control > */
static EventBits_t Parameters_FlagProgramControl;
/* < Declaración de Variables ::: Control Write/Read Parameters > */
static xMessegeECAN_t ReceiveProgramerBuffer;
static xDataGameCat_t BulkDataParameters;

/* < Ejecución de la Tarea :: Control Menu > */
void vThreadControlMenu(void *pvParameters) {
    /* < Inicializa ::: Tiempo Actual > */
    xLastWakeControlMenu = xTaskGetTickCount();
    /* < - Start Timers - System ------------------------------------------ > */
    xTimerStart(xTimerRefreshScreen, (TickType_t) 0); // < Dibujado de Pantalla
    xTimerStart(xTimerReadingJoystick, (TickType_t) 0); // < Lectura de Joystick
    /* < - Draw - Logo - Game//Cat ---------------------------------------- > */
    vGLCDBufferDrawBitmap(0, 0, GLCD_PIXEL_BLACK, Logo_GameCat);
    /* < Delay Time For Start Control... > */
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    /* < Clear ::: Screen... > */
    vGLCDClearBuffer();
    /* < - Setting ::: Menu Main Icons... > */
    vIncremetnSelectedWorkMenu(&MainCANCtrl);
    vDrawingMenuControl(&SelectedWorkMenu);

    /* < Ejecución ::: Tarea > */
    StartTask() {
        /* < Break ::: DEBUG > */
        pdNop();
        /* < Lectura ::: Banderas de Control > */
        Parameters_FlagProgramControl = xEventGroupWaitBits(xEventGroupProgramControls, Flag_ProgramCtrl_SerialBoard_Pass | Flag_ProgramCtrl_PasswdBoard_Pass | Flag_ProgramCtrl_Write_Enabled | Flag_ProgramCtrl_Read_Enabled | Flag_ProgramCtrl_Mode_Bulk_Write | Flag_ProgramCtrl_Mode_Bulk_Read, Flag_HoldOnExit, Flag_NoWaitForAllBits, 0);
        /* < Execute ::: Menu Display... > */
        if (xExecuteMenuControl(&SelectedWorkMenu, &xReadBufferJoystick)) {
            /* < Draw ::: Menu Display... > */
            vDrawingMenuControl(&SelectedWorkMenu);
        }
        /* < Chequeo ::: Si Hay Dato en Las Colas... > */
        if (uxQueueMessagesWaiting(xQueueReceiveDataCAN)) {
            /* < Chequeo ::: Recepcion ::: Buffer del Bus CAN... > */
            if (xQueueReceive(xQueueReceiveDataCAN, (void*) &ReceiveProgramerBuffer, (TickType_t) 0)) {
                /* < Select ::: ID to Redirect Messege... > */
                switch (ReceiveProgramerBuffer.ID) {
                    case ADDRESS_CAN_PROGRAM_GAME_CAT:
                        /* < Set ::: Event Flags... > */
                        xEventGroupSetBits(xEventGroupProgramControls, Flag_ProgramCtrl_Write_Enabled);
                        break;
                    case ADDRESS_CAN_END_CTL_GAME_CAT:
                        /* < Clear ::: All Event Flags... > */
                        xEventGroupClearBits(xEventGroupProgramControls, Flag_ProgramCtrl_Write_Enabled | Flag_ProgramCtrl_Read_Enabled | Flag_ProgramCtrl_Mode_Bulk_Write | Flag_ProgramCtrl_Mode_Bulk_Read);
                        break;
                    case ADDRESS_CAN_WRITE_DAT_GAME_CAT:
                        /* < Check ::: Status Bit Write... > */
                        if ((Parameters_FlagProgramControl & Flag_ProgramCtrl_Write_Enabled) == Flag_ProgramCtrl_Write_Enabled) {
                            /* < Check ::: if Write Data is Single or Masive... > */
                            if (ReceiveProgramerBuffer.Data[0] == pdSet) {
                                /* < Copy ::: Address > */
                                BulkDataParameters.AddressBulkData = ReceiveProgramerBuffer.Data[1];
                                /* < Copy ::: Lenght > */
                                BulkDataParameters.LengthBulkData = ReceiveProgramerBuffer.Data[3];
                                BulkDataParameters.CounterPointer = 0;
                                /* < Set ::: Event Flags... > */
                                xEventGroupSetBits(xEventGroupProgramControls, Flag_ProgramCtrl_Mode_Bulk_Write);
                            } else {
                                /* < Copy ::: Data to Buffer Parameters... > */
                                memcpy((void*) pxAddressxSystemParametersCAN[ReceiveProgramerBuffer.Data[1]], (void*) &ReceiveProgramerBuffer.Data[3], ReceiveProgramerBuffer.Data[2]);
                            }
                        }
                        break;
                    case ADDRESS_CAN_BULK_DATA_GAME_CAT:
                        /* < Check ::: Status Bit Write Bulk... > */
                        if ((Parameters_FlagProgramControl & (Flag_ProgramCtrl_Mode_Bulk_Write | Flag_ProgramCtrl_Mode_Bulk_Read)) == Flag_ProgramCtrl_Mode_Bulk_Write) {
                            /* < Copy ::: Data to Buffer Parameters... > */
                            memcpy((void*) (pxAddressxSystemParametersCAN[BulkDataParameters.AddressBulkData] + BulkDataParameters.CounterPointer), (void*) ReceiveProgramerBuffer.Data, ReceiveProgramerBuffer.DataLength);
                            /* < Update ::: Next Parameters to Copy... >  */
                            BulkDataParameters.CounterPointer = (BulkDataParameters.CounterPointer + ReceiveProgramerBuffer.DataLength);
                        }
                        break;
                }
            }
        }
        /* < Control de Tiempo Periódico > */
        vTaskDelayUntil(&xLastWakeControlMenu, TimeRecurring_t);
    }
    /* < Final de Ejecucion ::: Tarea > */
    EndTask();
}
