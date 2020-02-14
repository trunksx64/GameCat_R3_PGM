/* < Include ::: Header > */
#include "control_draw_menu.h"
#include "control_parameters_system.h"

/* < Definicion ::: Variable de Menu Trabajo... > */
xSelectedWorkMenu_t SelectedWorkMenu = {
    .WorkMenuIndex[0] = NULL,
    .WorkMenuIndex[1] = NULL,
    .WorkMenuIndex[2] = NULL,
    .WorkMenuIndex[3] = NULL,
    .SubMenuSelect = 0
};

void vIncremetnSelectedWorkMenu(void *Menu) {
    /* < Vaiables ::: Locales > */
    uint8_t LevelSubMenus = (sizeof (SelectedWorkMenu.WorkMenuIndex) / sizeof (void*));
    /* < Check ::: Level Menu... > */
    if (SelectedWorkMenu.SubMenuSelect < LevelSubMenus) {
        /* < Check ::: No Equal Pointers... > */
        if (SelectedWorkMenu.WorkMenuIndex[SelectedWorkMenu.SubMenuSelect] != Menu) {
            /* < Copy ::: Next Pointer Sub Menu... > */
            SelectedWorkMenu.WorkMenuIndex[SelectedWorkMenu.SubMenuSelect] = Menu;
            /* < Increment ::: Index Sub Menu... > */
            SelectedWorkMenu.SubMenuSelect += 1;
        }
    }
}

void vDecrementnSelectedWorkMenu(void) {
    /* < Check ::: Level Menu... > */
    if (SelectedWorkMenu.SubMenuSelect > 0) {
        /* < Check ::: No Equal Pointers... > */
        if (SelectedWorkMenu.WorkMenuIndex[SelectedWorkMenu.SubMenuSelect - 1] != NULL) {
            /* < Del ::: Current Pointer Sub Menu... > */
            SelectedWorkMenu.WorkMenuIndex[SelectedWorkMenu.SubMenuSelect - 1] = NULL;
            /* < Decrement ::: Index Sub Menu... > */
            SelectedWorkMenu.SubMenuSelect -= 1;
        }
    }
}

/* < Funciones ::: Ejecucion de Cotroles... > */
void vDrawingMenuControl(xSelectedWorkMenu_t * Menu) {
    /* < Variables ::: Locales (Lines, Floors & Blocks) > */
    uint8_t StartTextLine = 5;
    uint8_t DrawingLines = 0;
    /* < Variables ::: Locales (Varaibles) > */
    uint8_t *Byte = NULL;
    uint16_t *Word = NULL;
    uint32_t *Long = NULL;
    /* < Variables ::: Locales (Strings) > */
    char StringNumberLine[5];
    char StringNumberVariable[7];
    /* < Variables ::: Locales (Pointer Menu) > */
    xControlMenu_t *CurrentWorkMenu = (xControlMenu_t*) Menu->WorkMenuIndex[Menu->SubMenuSelect - 1]; // < Copy Pointer Struct Menu for Working
    xIconsMenu_t *CurrentIconsMenu = (xIconsMenu_t*) CurrentWorkMenu->pxCurrentMenu; // < Copy Pointer Struct Serial for Working    
    xSerialMenu_t *CurrentSerialMenu = (xSerialMenu_t*) CurrentWorkMenu->pxCurrentMenu; // < Copy Pointer Struct Menu Icons for Working        
    xSerialMenu_t *CurrentPasswordMenu = (xSerialMenu_t*) CurrentWorkMenu->pxCurrentMenu; // < Copy Pointer Struct Menu Icons for Working        
    xListsMenu_t *CurrentListMenu = (xListsMenu_t*) CurrentWorkMenu->pxCurrentMenu; // < Copy Pointer Struct Menu List for Working  
    /* < Chequeo ::: Tipo de Menu a Trabajar... > */
    switch (CurrentWorkMenu->xType) {
        case TYPE_MENU_ICONS:
            vGLCDClearBuffer(); // < Borrado de Pantalla...
            vGLCDBufferDrawBitmap(0, 18, GLCD_PIXEL_BLACK, Icon_CursorL); // < Draw Left xCursor..            
            vGLCDBufferDrawBitmap(80, 18, GLCD_PIXEL_BLACK, Icon_CursorR); // < Draw Right xCursor..            
            vDrawFillRoundRectangle(0, 39, 84, 9, 3, GLCD_PIXEL_BLACK); // < Draw Box Text
            vGLCDBufferDrawBitmap(26, 3, GLCD_PIXEL_BLACK, CurrentIconsMenu[CurrentWorkMenu->xSelection].pxIcon); // < Draw Icon..            
            vPutsCharGlcd(ALIGMENT_FONT_CENTER, 40, GLCD_PIXEL_WHITE, CurrentIconsMenu[CurrentWorkMenu->xSelection].StringText[ParameterSystem.Parameter_Language - 1]); // < Draw Text   
            break;
        case TYPE_MENU_SERIAL:
            vGLCDClearBuffer(); // < Borrado de Pantalla...
            vDrawFillRoundRectangle(0, 0, 84, 9, 3, GLCD_PIXEL_BLACK); // < Draw Box Text
            vDrawFillRoundRectangle(0, 39, 84, 9, 3, GLCD_PIXEL_BLACK); // < Draw Box Text
            vPutsCharGlcd(3, 1, GLCD_PIXEL_WHITE, CurrentWorkMenu->StringText[ParameterSystem.Parameter_Language - 1]); // < Draw Text
            vPutsCharGlcd(3, 40, GLCD_PIXEL_WHITE, CurrentSerialMenu->StringText[ParameterSystem.Parameter_Language - 1]); // < Draw Text
            sprintf(StringNumberLine, "(%u)", (CurrentWorkMenu->xSelection + 1)); // < Compiled Buffer String...
            vPutsCharGlcd(ALIGMENT_FONT_RIGHT, 1, GLCD_PIXEL_WHITE, StringNumberLine); // < Draw Number Line
            /* < Draw ::: Cursor Position... > */
            vGLCDBufferDrawBitmap((3 + (CurrentWorkMenu->xSelection * 10)), 12, GLCD_PIXEL_BLACK, Icon_CursorD);
            vGLCDBufferDrawBitmap((3 + (CurrentWorkMenu->xSelection * 10)), 31, GLCD_PIXEL_BLACK, Icon_CursorU);
            /* < Clear ::: Variable Auxiliar... > */
            DrawingLines = 0;
            /* < Dibujado de los Cuadros de Seleccion... Texto > */
            for (uint8_t Count = 0; Count < (CurrentSerialMenu[0].LengthOptions); Count++) {
                vDrawRoundRectangle((2 + DrawingLines), 18, 9, 11, 2, GLCD_PIXEL_BLACK);
                /* < Incremento ::: Variable Auxiliar > */
                DrawingLines += 10;
            }
            /* < Clear ::: Variable Auxiliar... > */
            DrawingLines = 0;
            /* < Copy ::: Pointer String... > */
            Byte = CurrentSerialMenu[0].pxVariable;
            /* < Drawing ::: Chat to Chat for the Text... > */
            for (uint8_t Count = 0; Count < (CurrentSerialMenu[0].LengthOptions); Count++) {
                /* < Dibujado ::: Cada Letras en Caja... > */
                xPutCharGlcd((4 + DrawingLines), 20, GLCD_PIXEL_BLACK, Byte[Count]);
                /* < Incremento ::: Variable Auxiliar > */
                DrawingLines += 10;
            }
            break;
        case TYPE_MENU_PASSWORD:
            vGLCDClearBuffer(); // < Borrado de Pantalla...
            vDrawFillRoundRectangle(0, 0, 84, 9, 3, GLCD_PIXEL_BLACK); // < Draw Box Text            
            vPutsCharGlcd(3, 1, GLCD_PIXEL_WHITE, CurrentWorkMenu->StringText[ParameterSystem.Parameter_Language - 1]); // < Draw Text            
            vPutsCharGlcd(3, 30, GLCD_PIXEL_BLACK, CurrentPasswordMenu[1].StringText[ParameterSystem.Parameter_Language - 1]); // < Draw Text            
            sprintf(StringNumberLine, "(%u.%u)", (CurrentWorkMenu->xOption + 1), (CurrentWorkMenu->xSelection + 1)); // < Compiled Buffer String...
            vPutsCharGlcd(ALIGMENT_FONT_RIGHT, 1, GLCD_PIXEL_WHITE, StringNumberLine); // < Draw Number Line            
            /* < Draw ::: Cursor Position... > */
            if (CurrentWorkMenu->xOption == pdFalse)vGLCDBufferDrawBitmap((3 + (CurrentWorkMenu->xSelection * 10)), 11, GLCD_PIXEL_BLACK, Icon_CursorD);
            else if (CurrentWorkMenu->xOption == pdTrue)vGLCDBufferDrawBitmap((43 + (CurrentWorkMenu->xSelection * 10)), 40, GLCD_PIXEL_BLACK, Icon_CursorU);
            /* < Clear ::: Variable Auxiliar... > */
            DrawingLines = 0;
            /* < Dibujado de los Cuadros de Seleccion... Texto > */
            for (uint8_t Count = 0; Count < (CurrentPasswordMenu[0].LengthOptions); Count++) {
                vDrawRoundRectangle((2 + DrawingLines), 16, 9, 11, 2, GLCD_PIXEL_BLACK);
                /* < Incremento ::: Variable Auxiliar > */
                DrawingLines += 10;
            }
            /* < Clear ::: Variable Auxiliar... > */
            DrawingLines = 40;
            /* < Dibujado de los Cuadros de Seleccion... Texto > */
            for (uint8_t Count = 0; Count < (CurrentPasswordMenu[1].LengthOptions); Count++) {
                vDrawRoundRectangle((2 + DrawingLines), 28, 9, 11, 2, GLCD_PIXEL_BLACK);
                /* < Incremento ::: Variable Auxiliar > */
                DrawingLines += 10;
            }
            /* < Clear ::: Variable Auxiliar... > */
            DrawingLines = 0;
            /* < Copy ::: Pointer String... > */
            Byte = CurrentPasswordMenu[0].pxVariable;
            /* < Drawing ::: Chat to Chat for the Text... > */
            for (uint8_t Count = 0; Count < (CurrentSerialMenu[0].LengthOptions); Count++) {
                /* < Dibujado ::: Cada Letras en Caja... > */
                xPutCharGlcd((4 + DrawingLines), 18, GLCD_PIXEL_BLACK, Byte[Count]);
                /* < Incremento ::: Variable Auxiliar > */
                DrawingLines += 10;
            }
            /* < Clear ::: Variable Auxiliar... > */
            DrawingLines = 40;
            /* < Copy ::: Pointer String... > */
            Byte = CurrentPasswordMenu[1].pxVariable;
            /* < Drawing ::: Chat to Chat for the Text... > */
            for (uint8_t Count = 0; Count < (CurrentSerialMenu[1].LengthOptions); Count++) {
                /* < Dibujado ::: Cada Letras en Caja... > */
                xPutCharGlcd((4 + DrawingLines), 30, GLCD_PIXEL_BLACK, Byte[Count]);
                /* < Incremento ::: Variable Auxiliar > */
                DrawingLines += 10;
            }
            break;
        case TYPE_MENU_LIST:
            vGLCDClearBuffer(); // < Borrado de Pantalla...
            vDrawFillRoundRectangle(0, 0, 84, 9, 3, GLCD_PIXEL_BLACK); // < Draw Box Text
            vPutsCharGlcd(3, 1, GLCD_PIXEL_WHITE, CurrentWorkMenu->StringText[ParameterSystem.Parameter_Language - 1]); // < Draw Text
            sprintf(StringNumberLine, "(%u)", (CurrentWorkMenu->xSelection + 1)); // < Compiled Buffer String...
            vPutsCharGlcd(ALIGMENT_FONT_RIGHT, 1, GLCD_PIXEL_WHITE, StringNumberLine); // < Draw Number Line
            vGLCDBufferDrawBitmap(0, (12 + (CurrentWorkMenu->xCursor * SelectedFont.Height)), GLCD_PIXEL_BLACK, Icon_CursorR); // < Draw xCursor
            /* < Drawing ::: Four Lines for List Menu... >  */
            while ((DrawingLines < CurrentWorkMenu->xLength) && (DrawingLines < LENGTH_LINES_MENU_LIST)) {
                /* < Check ::: Type Line (Title or Variable...) > */
                if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].TypeVariable == TYPE_VARIABLE_TITLE) {
                    StartTextLine = ALIGMENT_FONT_CENTER; // < Center of Text...
                } else {
                    /* < Check ::: Icon Line? > */
                    if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxIcon) {
                        vGLCDBufferDrawBitmap(5, (12 + (DrawingLines * SelectedFont.Height)), GLCD_PIXEL_BLACK, CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxIcon); // < Draw Icon Line
                        StartTextLine = 13; // < Add 8 Pilexs...
                    } else {
                        StartTextLine = 5; // < Minus 8 Pilexs...
                    }
                }
                /* < Drawing ::: Text of Line... > */
                vPutsCharGlcd(StartTextLine, (12 + (DrawingLines * SelectedFont.Height)), GLCD_PIXEL_BLACK, CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].StringText[ParameterSystem.Parameter_Language - 1]);
                /* < Check ::: Options for List Menu... >  */
                if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxVariable) {
                    /* < Check ::: Type of Variable> */
                    switch (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].TypeVariable) {
                        case TYPE_VARIABLE_INT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].SizeVariable == sizeof (uint8_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxVariable; // < Pointer of Variable 
                                sprintf(StringNumberVariable, "[%u]", *Byte); // < Compiled Buffer String...                                
                            } else if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].SizeVariable == sizeof (uint16_t)) {
                                Word = CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxVariable; // < Pointer of Variable 
                                sprintf(StringNumberVariable, "[%u]", *Word); // < Compiled Buffer String...                                
                            } else if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].SizeVariable == sizeof (uint32_t)) {
                                Long = CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxVariable; // < Pointer of Variable 
                                sprintf(StringNumberVariable, "[%lu]", *Long); // < Compiled Buffer String...                                
                            }
                            vPutsCharGlcd(ALIGMENT_FONT_RIGHT, (12 + (DrawingLines * SelectedFont.Height)), GLCD_PIXEL_BLACK, StringNumberVariable); // < Draw Number Variable
                            break;
                        case TYPE_VARIABLE_BOOL:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].SizeVariable == sizeof (uint1_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxVariable; // < Pointer of Variable
                                vDrawFillRoundRectangle(70, (12 + (DrawingLines * SelectedFont.Height)), 13, 7, 2, GLCD_PIXEL_BLACK); // < Draw Box
                                /* < Compare ::: Value of Variable > */
                                if (*Byte == pdFalse) {
                                    vDrawFillRoundRectangle(71, (13 + (DrawingLines * SelectedFont.Height)), 5, 5, 2, GLCD_PIXEL_WHITE);
                                } else if (*Byte == pdTrue) {
                                    vDrawFillRoundRectangle(77, (13 + (DrawingLines * SelectedFont.Height)), 5, 5, 2, GLCD_PIXEL_WHITE);
                                }
                            }
                            break;
                        case TYPE_VARIABLE_SIGNAL:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].SizeVariable == sizeof (uint1_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxVariable; // < Pointer of Variable                            
                                vGLCDBufferDrawBitmap(67, (12 + (DrawingLines * 8)), GLCD_PIXEL_BLACK, Icon_CursorL); // < Draw Icon xCursor
                                vGLCDBufferDrawBitmap(80, (12 + (DrawingLines * 8)), GLCD_PIXEL_BLACK, Icon_CursorR); // < Draw Icon xCursor
                                /* < Compare ::: Value of Variable > */
                                if (*Byte == pdFalse) {
                                    vGLCDBufferDrawBitmap(72, (13 + (DrawingLines * 8)), GLCD_PIXEL_BLACK, Icon_CursorD); // < Draw Icon Line
                                } else if (*Byte == pdTrue) {
                                    vGLCDBufferDrawBitmap(72, (13 + (DrawingLines * 8)), GLCD_PIXEL_BLACK, Icon_CursorU); // < Draw Icon Line
                                }
                            }
                            break;
                        case TYPE_VARIABLE_BIT_BOOL:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].SizeVariable == sizeof (uint8_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxVariable; // < Pointer of Variable                                                                
                                vDrawFillRoundRectangle(70, (12 + (DrawingLines * SelectedFont.Height)), 13, 7, 2, GLCD_PIXEL_BLACK); // < Draw Box
                                /* < Compare ::: Value of Variable > */
                                if (!!(*Byte & CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].LengthOptions)) {
                                    vDrawFillRoundRectangle(77, (13 + (DrawingLines * SelectedFont.Height)), 5, 5, 2, GLCD_PIXEL_WHITE);
                                } else {
                                    vDrawFillRoundRectangle(71, (13 + (DrawingLines * SelectedFont.Height)), 5, 5, 2, GLCD_PIXEL_WHITE);
                                }
                            }
                            break;
                        case TYPE_VARIABLE_BIT_TEXT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].SizeVariable == sizeof (uint8_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxVariable; // < Pointer of Variable                                                                
                                /* < Compare ::: Value of Variable > */
                                if (!!(*Byte & CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].LengthOptions)) {
                                    vPutsCharGlcd(ALIGMENT_FONT_RIGHT, (12 + (DrawingLines * SelectedFont.Height)), GLCD_PIXEL_BLACK, "High"); // < Draw Number Variable
                                } else {
                                    vPutsCharGlcd(ALIGMENT_FONT_RIGHT, (12 + (DrawingLines * SelectedFont.Height)), GLCD_PIXEL_BLACK, "Low"); // < Draw Number Variable
                                }
                            }
                            break;
                        case TYPE_VARIABLE_TEXT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].SizeVariable == sizeof (uint8_t)) {
                                /* < Check ::: Lenght of Variable > */
                                if (CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].LengthOptions <= LENGTH_MAX_OPTIONS_TEXT) {
                                    Byte = CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxVariable; // < Pointer of Variable                                    
                                    vPutsCharGlcd(ALIGMENT_FONT_RIGHT, (12 + (DrawingLines * SelectedFont.Height)), GLCD_PIXEL_BLACK, CurrentListMenu[CurrentWorkMenu->xScroll + DrawingLines].pxStringOptions[*Byte]); // < Draw Number Variable
                                }
                            }
                            break;
                    }
                }
                /* < Increment ::: DrawingLines > */
                DrawingLines++;
            }
            break;
        case TYPE_MENU_BAR:

            break;
        case TYPE_MENU_CLOCK:

            break;
        case TYPE_MENU_MESSAGE:

            break;
        case TYPE_MENU_BUTTONS:

            break;
    }
}

/* < Definicion ::: Variable de Entradas de Botones... > */
static xCheckInputPulse InputSetUp;
static xCheckInputPulse InputSetDown;
static xCheckInputPulse InputSetLeft;
static xCheckInputPulse InputSetRight;
static xCheckInputPulse InputButtonA;
static xCheckInputPulse InputButtonB;
static xCheckInputPulse InputButtonX;
static xCheckInputPulse InputButtonY;
static xCheckInputPulse InputButtonZ;

uint1_t xExecuteMenuControl(xSelectedWorkMenu_t *Menu, void *Inputs) {
    /* < Variables ::: Locales (Pointer Joystick) > */
    uint1_t Return = pdClear;
    xBufferJoystick *InputJoystick = (xBufferJoystick*) Inputs; // < Copy Pointer Struct for Inputs
    /* < Variables ::: Locales (Varaibles) > */
    uint8_t *Byte = NULL;
    uint16_t *Word = NULL;
    uint32_t *Long = NULL;
    /* < Variables ::: Locales (Functions) > */
    void(*CallFunctionTwo)(void*, uint8_t) = NULL;
    /* < Variables ::: Locales (Pointer Menu) > */
    xControlMenu_t *CurrentWorkMenu = (xControlMenu_t*) Menu->WorkMenuIndex[Menu->SubMenuSelect - 1]; // < Copy Pointer Struct Menu for Working
    xIconsMenu_t *CurrentIconsMenu = (xIconsMenu_t*) CurrentWorkMenu->pxCurrentMenu; // < Copy Pointer Struct Menu Icons for Working    
    xSerialMenu_t *CurrentSerialMenu = (xSerialMenu_t*) CurrentWorkMenu->pxCurrentMenu; // < Copy Pointer Struct Menu Icons for Working        
    xSerialMenu_t *CurrentPasswordMenu = (xSerialMenu_t*) CurrentWorkMenu->pxCurrentMenu; // < Copy Pointer Struct Menu Icons for Working        
    xListsMenu_t *CurrentListMenu = (xListsMenu_t*) CurrentWorkMenu->pxCurrentMenu; // < Copy Pointer Struct Menu List for Working          
    /* < Chequeo ::: Tipo de Menu a Trabajar... > */
    switch (CurrentWorkMenu->xType) {
        case TYPE_MENU_ICONS:
            /* < Check ::: Joystick... > */
            if (xReadRepeatPulse(&InputSetLeft, InputJoystick->Buttons.Bits.xArrow_Left, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Control ::: Backward Menu > */
                if (CurrentWorkMenu->xSelection == 0) {
                    CurrentWorkMenu->xSelection = (CurrentWorkMenu->xLength - 1);
                } else {
                    CurrentWorkMenu->xSelection -= 1;
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputSetRight, InputJoystick->Buttons.Bits.xArrow_Right, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Control ::: Forward Menu > */
                if (CurrentWorkMenu->xSelection == (CurrentWorkMenu->xLength - 1)) {
                    CurrentWorkMenu->xSelection = 0;
                } else {
                    CurrentWorkMenu->xSelection += 1;
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputButtonA, InputJoystick->Buttons.Bits.xButton_A, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Chequeo ::: Puntero Submenu... > */
                if (CurrentIconsMenu[CurrentWorkMenu->xSelection].pxNextMenu) {
                    /* < Copy ::: Pointer Submenu... > */
                    vIncremetnSelectedWorkMenu((void*) CurrentIconsMenu[CurrentWorkMenu->xSelection].pxNextMenu);
                }
                /* < Return ::: Control > */
                Return = pdSet;
            }
            break;
        case TYPE_MENU_SERIAL:
            /* < Check ::: Joystick... > */
            if (xReadRepeatPulse(&InputSetUp, InputJoystick->Buttons.Bits.xArrow_Up, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Check ::: Pointer is not Null... > */
                if (CurrentSerialMenu[0].pxVariable) {
                    /* < Copy ::: Pointer Variable... > */
                    Byte = (uint8_t*) CurrentSerialMenu[0].pxVariable;
                    /* < Increment ::: Pointer to Value > */
                    if (Byte[CurrentWorkMenu->xSelection] == 0) Byte[CurrentWorkMenu->xSelection] = '0';
                    else Byte[CurrentWorkMenu->xSelection]++;
                    /* < Check ::: Limit to Ascii > */
                    if (Byte[CurrentWorkMenu->xSelection] == ':') Byte[CurrentWorkMenu->xSelection] = 'A';
                    else if (Byte[CurrentWorkMenu->xSelection] == '[') Byte[CurrentWorkMenu->xSelection] = '0';
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputSetDown, InputJoystick->Buttons.Bits.xArrow_Down, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Check ::: Pointer is not Null... > */
                if (CurrentSerialMenu[0].pxVariable) {
                    /* < Copy ::: Pointer Variable... > */
                    Byte = (uint8_t*) CurrentSerialMenu[0].pxVariable;
                    /* < Increment ::: Pointer to Value > */
                    if (Byte[CurrentWorkMenu->xSelection] == 0) Byte[CurrentWorkMenu->xSelection] = 'Z';
                    else Byte[CurrentWorkMenu->xSelection]--;
                    /* < Check ::: Limit to Ascii > */
                    if (Byte[CurrentWorkMenu->xSelection] == '@') Byte[CurrentWorkMenu->xSelection] = '9';
                    else if (Byte[CurrentWorkMenu->xSelection] == '/') Byte[CurrentWorkMenu->xSelection] = 'Z';
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputSetLeft, InputJoystick->Buttons.Bits.xArrow_Left, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Control ::: Backward Menu > */
                if (CurrentWorkMenu->xSelection == 0) {
                    CurrentWorkMenu->xSelection = (CurrentSerialMenu[0].LengthOptions - 1);
                } else {
                    CurrentWorkMenu->xSelection -= 1;
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputSetRight, InputJoystick->Buttons.Bits.xArrow_Right, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Control ::: Forward Menu > */
                if (CurrentWorkMenu->xSelection == (CurrentSerialMenu[0].LengthOptions - 1)) {
                    CurrentWorkMenu->xSelection = 0;
                } else {
                    CurrentWorkMenu->xSelection += 1;
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputButtonB, InputJoystick->Buttons.Bits.xButton_B, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Chequeo ::: Puntero Submenu... > */
                if (SelectedWorkMenu.SubMenuSelect) {
                    /* < Copy ::: Pointer Return Submenu... > */
                    vDecrementnSelectedWorkMenu();
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputButtonA, InputJoystick->Buttons.Bits.xButton_A, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Check ::: Valid Pointer > */
                if (CurrentSerialMenu[3].pxVariable) {
                    /* < Check ::: Type of Variable> */
                    if (CurrentSerialMenu[3].TypeVariable == TYPE_VARIABLE_FUNCTION_C) {
                        /* < Copy ::: Pointer To Function... > */
                        CallFunctionTwo = (void*) CurrentWorkMenu->pxFunctionC;
                        /* < Execute ::: SubFunction > */
                        CallFunctionTwo(CurrentSerialMenu[3].pxVariable, CurrentSerialMenu[3].SizeVariable);
                    }
                }
            } else if (xReadRepeatPulse(&InputButtonX, InputJoystick->Buttons.Bits.xButton_X, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Check ::: Valid Pointer > */
                if (CurrentSerialMenu[1].pxVariable) {
                    /* < Check ::: Type of Variable> */
                    if (CurrentSerialMenu[1].TypeVariable == TYPE_VARIABLE_FUNCTION_A) {
                        /* < Copy ::: Pointer To Function... > */
                        CallFunctionTwo = (void*) CurrentWorkMenu->pxFunctionA;
                        /* < Execute ::: SubFunction > */
                        CallFunctionTwo(CurrentSerialMenu[1].pxVariable, CurrentSerialMenu[1].SizeVariable);
                    }
                }
            }
            break;
        case TYPE_MENU_PASSWORD:
            /* < Check ::: Joystick... > */
            if (xReadRepeatPulse(&InputSetUp, InputJoystick->Buttons.Bits.xArrow_Up, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Check ::: Pointer is not Null... > */
                if (CurrentPasswordMenu[CurrentWorkMenu->xOption].pxVariable) {
                    /* < Copy ::: Pointer Variable... > */
                    Byte = (uint8_t*) CurrentPasswordMenu[CurrentWorkMenu->xOption].pxVariable;
                    /* < Increment ::: Pointer to Value > */
                    if (Byte[CurrentWorkMenu->xSelection] == 0) Byte[CurrentWorkMenu->xSelection] = '0';
                    else Byte[CurrentWorkMenu->xSelection]++;
                    /* < Check ::: Limit to Ascii > */
                    if (Byte[CurrentWorkMenu->xSelection] == ':') Byte[CurrentWorkMenu->xSelection] = 'A';
                    else if (Byte[CurrentWorkMenu->xSelection] == '[') Byte[CurrentWorkMenu->xSelection] = '0';
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputSetDown, InputJoystick->Buttons.Bits.xArrow_Down, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Check ::: Pointer is not Null... > */
                if (CurrentSerialMenu[0].pxVariable) {
                    /* < Copy ::: Pointer Variable... > */
                    Byte = (uint8_t*) CurrentPasswordMenu[CurrentWorkMenu->xOption].pxVariable;
                    /* < Increment ::: Pointer to Value > */
                    if (Byte[CurrentWorkMenu->xSelection] == 0) Byte[CurrentWorkMenu->xSelection] = 'Z';
                    else Byte[CurrentWorkMenu->xSelection]--;
                    /* < Check ::: Limit to Ascii > */
                    if (Byte[CurrentWorkMenu->xSelection] == '@') Byte[CurrentWorkMenu->xSelection] = '9';
                    else if (Byte[CurrentWorkMenu->xSelection] == '/') Byte[CurrentWorkMenu->xSelection] = 'Z';
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputSetLeft, InputJoystick->Buttons.Bits.xArrow_Left, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Control ::: Backward Menu > */
                if (CurrentWorkMenu->xSelection == 0) {
                    if (CurrentWorkMenu->xOption == pdFalse) CurrentWorkMenu->xOption = pdSet;
                    else if (CurrentWorkMenu->xOption == pdTrue) CurrentWorkMenu->xOption = pdClear;
                    CurrentWorkMenu->xSelection = (CurrentSerialMenu[CurrentWorkMenu->xOption].LengthOptions - 1);
                } else {
                    CurrentWorkMenu->xSelection -= 1;
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputSetRight, InputJoystick->Buttons.Bits.xArrow_Right, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Control ::: Forward Menu > */
                if (CurrentWorkMenu->xSelection == (CurrentSerialMenu[CurrentWorkMenu->xOption].LengthOptions - 1)) {
                    if (CurrentWorkMenu->xOption == pdFalse) CurrentWorkMenu->xOption = pdSet;
                    else if (CurrentWorkMenu->xOption == pdTrue) CurrentWorkMenu->xOption = pdClear;
                    CurrentWorkMenu->xSelection = 0;
                } else {
                    CurrentWorkMenu->xSelection += 1;
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputButtonB, InputJoystick->Buttons.Bits.xButton_B, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Chequeo ::: Puntero Submenu... > */
                if (SelectedWorkMenu.SubMenuSelect) {
                    /* < Copy ::: Pointer Return Submenu... > */
                    vDecrementnSelectedWorkMenu();
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputButtonA, InputJoystick->Buttons.Bits.xButton_A, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Check ::: Valid Pointer > */
                if (CurrentPasswordMenu[2].pxVariable) {
                    /* < Check ::: Type of Variable> */
                    if (CurrentPasswordMenu[2].TypeVariable == TYPE_VARIABLE_FUNCTION_A) {
                        /* < Copy ::: Pointer To Function... > */
                        CallFunctionTwo = (void*) CurrentWorkMenu->pxFunctionA;
                        /* < Execute ::: SubFunction > */
                        CallFunctionTwo(CurrentSerialMenu[2].pxVariable, CurrentSerialMenu[2].SizeVariable);
                    }
                }
            } else if (xReadRepeatPulse(&InputButtonX, InputJoystick->Buttons.Bits.xButton_X, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Check ::: Valid Pointer > */
                if (CurrentPasswordMenu[3].pxVariable) {
                    /* < Check ::: Type of Variable> */
                    if (CurrentPasswordMenu[3].TypeVariable == TYPE_VARIABLE_FUNCTION_B) {
                        /* < Copy ::: Pointer To Function... > */
                        CallFunctionTwo = (void*) CurrentWorkMenu->pxFunctionB;
                        /* < Execute ::: SubFunction > */
                        CallFunctionTwo(CurrentSerialMenu[3].pxVariable, CurrentSerialMenu[3].SizeVariable);
                    }
                }
            } else if (xReadRepeatPulse(&InputButtonZ, InputJoystick->Buttons.Bits.xButton_Z, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Check ::: Valid Pointer > */
                if (CurrentPasswordMenu[2].pxVariable && CurrentPasswordMenu[3].pxVariable) {
                    /* < Check ::: Type of Variable> */
                    if (CurrentPasswordMenu[2].TypeVariable == TYPE_VARIABLE_FUNCTION_A && CurrentPasswordMenu[3].TypeVariable == TYPE_VARIABLE_FUNCTION_B) {
                        /* < Clear ::: Variable > */
                        memset(CurrentPasswordMenu[2].pxVariable, '0', CurrentPasswordMenu[2].SizeVariable);
                        memset(CurrentPasswordMenu[3].pxVariable, '0', CurrentPasswordMenu[3].SizeVariable);
                    }
                }
                /* < Return ::: Control > */
                Return = pdSet;
            }
            break;
        case TYPE_MENU_LIST:
            /* < Check ::: Joystick... > */
            if (xReadRepeatPulse(&InputSetUp, InputJoystick->Buttons.Bits.xArrow_Up, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Control ::: Backward Up > */
                if (CurrentWorkMenu->xSelection) {
                    if (CurrentWorkMenu->xCursor) CurrentWorkMenu->xCursor--; // < Decrement xCursor
                    else CurrentWorkMenu->xScroll--; // < Decrement xScroll
                    CurrentWorkMenu->xSelection--; // < Decrement xSelection
                } else {
                    /* < Chequea ::: El Numero de Lineas... > */
                    if (CurrentWorkMenu->xLength > LENGTH_LINES_MENU_LIST) {
                        CurrentWorkMenu->xCursor = (LENGTH_LINES_MENU_LIST - 1); // < Set xCursor    
                        CurrentWorkMenu->xScroll = (CurrentWorkMenu->xLength - LENGTH_LINES_MENU_LIST); // < Set xScroll
                    } else {
                        CurrentWorkMenu->xCursor = (CurrentWorkMenu->xLength - 1); // < Set xCursor    
                        CurrentWorkMenu->xScroll = 0; // < Clear xScroll    
                    }
                    CurrentWorkMenu->xSelection = (CurrentWorkMenu->xLength - 1); // < Set xSelection    
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputSetDown, InputJoystick->Buttons.Bits.xArrow_Down, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Control ::: Backward Down > */
                if (CurrentWorkMenu->xSelection < (CurrentWorkMenu->xLength - 1)) {
                    if (CurrentWorkMenu->xCursor < (LENGTH_LINES_MENU_LIST - 1)) CurrentWorkMenu->xCursor++; // < Increment xCursor
                    else CurrentWorkMenu->xScroll++; // < Increment xScroll
                    CurrentWorkMenu->xSelection++; // < Increment xSelection
                } else {
                    CurrentWorkMenu->xSelection = 0; // < Clear xSelection
                    CurrentWorkMenu->xScroll = 0; // < Clear xScroll
                    CurrentWorkMenu->xCursor = 0; // < Clear xCursor
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputSetLeft, InputJoystick->Buttons.Bits.xArrow_Left, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Check ::: if Varaible es Valid... > */
                if (CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable) {
                    /* < Check ::: Type of Variable> */
                    switch (CurrentListMenu[CurrentWorkMenu->xSelection].TypeVariable) {
                        case TYPE_VARIABLE_INT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint8_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable 
                                /* < Decrement ::: Variable > */
                                if (*Byte) {
                                    *Byte = (*Byte - 1);
                                }
                            } else if (CurrentListMenu[CurrentWorkMenu->xSelection ].SizeVariable == sizeof (uint16_t)) {
                                Word = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable 
                                /* < Decrement ::: Variable > */
                                if (*Word) {
                                    *Word = (*Word - 1);
                                }
                            } else if (CurrentListMenu[CurrentWorkMenu->xSelection ].SizeVariable == sizeof (uint32_t)) {
                                Long = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable 
                                /* < Decrement ::: Variable > */
                                if (*Long) {
                                    *Long = (*Long - 1);
                                }
                            }
                            break;
                        case TYPE_VARIABLE_BOOL:
                        case TYPE_VARIABLE_SIGNAL:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint1_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable
                                /* < Clear ::: Variable > */
                                if (*Byte == pdTrue) {
                                    *Byte = pdClear;
                                }
                            }
                            break;
                        case TYPE_VARIABLE_BIT_BOOL:
                        case TYPE_VARIABLE_BIT_TEXT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint8_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable; // < Pointer of Variable
                                /* < Clear ::: Bit of Variable > */
                                *Byte &= ~(CurrentListMenu[CurrentWorkMenu->xSelection].LengthOptions);
                            }
                            break;
                        case TYPE_VARIABLE_TEXT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint8_t)) {
                                /* < Check ::: Lenght of Variable > */
                                if (CurrentListMenu[CurrentWorkMenu->xSelection].LengthOptions <= LENGTH_MAX_OPTIONS_TEXT) {
                                    Byte = CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable; // < Pointer of Variable
                                    /* < Increment ::: Variable > */
                                    if (*Byte > 0) {
                                        *Byte -= 1;
                                    }
                                }
                            }
                            break;
                    }
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputSetRight, InputJoystick->Buttons.Bits.xArrow_Right, DIRECT_LOGIC, REPEAT_OFF)) {
                /* < Check ::: if Varaible es Valid... > */
                if (CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable) {
                    /* < Check ::: Type of Variable> */
                    switch (CurrentListMenu[CurrentWorkMenu->xSelection].TypeVariable) {
                        case TYPE_VARIABLE_INT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint8_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable 
                                /* < Increment ::: Variable > */
                                if (*Byte < CurrentListMenu[CurrentWorkMenu->xSelection].LengthOptions) {
                                    *Byte += 1;
                                }
                            } else if (CurrentListMenu[CurrentWorkMenu->xSelection ].SizeVariable == sizeof (uint16_t)) {
                                Word = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable 
                                /* < Increment ::: Variable > */
                                if (*Word < CurrentListMenu[CurrentWorkMenu->xSelection].LengthOptions) {
                                    *Word += 1;
                                }
                            } else if (CurrentListMenu[CurrentWorkMenu->xSelection ].SizeVariable == sizeof (uint32_t)) {
                                Long = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable 
                                /* < Decrement ::: Variable > */
                                if (*Long < CurrentListMenu[CurrentWorkMenu->xSelection].LengthOptions) {
                                    *Long += 1;
                                }
                            }
                            break;
                        case TYPE_VARIABLE_BOOL:
                        case TYPE_VARIABLE_SIGNAL:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint1_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable
                                /* < Clear ::: Variable > */
                                if (*Byte == pdFalse) {
                                    *Byte = pdSet;
                                }
                            }
                            break;
                        case TYPE_VARIABLE_BIT_BOOL:
                        case TYPE_VARIABLE_BIT_TEXT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint8_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable; // < Pointer of Variable
                                /* < Set ::: Bit of Variable > */
                                *Byte |= CurrentListMenu[CurrentWorkMenu->xSelection].LengthOptions;
                            }
                            break;
                        case TYPE_VARIABLE_TEXT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint8_t)) {
                                /* < Check ::: Lenght of Variable > */
                                if (CurrentListMenu[CurrentWorkMenu->xSelection].LengthOptions <= LENGTH_MAX_OPTIONS_TEXT) {
                                    Byte = CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable; // < Pointer of Variable
                                    /* < Increment ::: Variable > */
                                    if (*Byte < (CurrentListMenu[CurrentWorkMenu->xSelection].LengthOptions - 1)) {
                                        *Byte += 1;
                                    }
                                }
                            }
                            break;
                    }
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputButtonB, InputJoystick->Buttons.Bits.xButton_B, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Chequeo ::: Puntero Submenu... > */
                if (SelectedWorkMenu.SubMenuSelect) {
                    /* < Copy ::: Pointer Return Submenu... > */
                    vDecrementnSelectedWorkMenu();
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputButtonA, InputJoystick->Buttons.Bits.xButton_A, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Check ::: Valid Pointer > */
                if (CurrentListMenu[CurrentWorkMenu->xSelection].TypeFunction) {
                    /* < Check ::: Type of Variable> */
                    switch (CurrentListMenu[CurrentWorkMenu->xSelection].TypeFunction) {
                        case TYPE_VARIABLE_FUNCTION_A:
                            /* < Copy ::: Pointer To Function... > */
                            CallFunctionTwo = (void*) CurrentWorkMenu->pxFunctionA;
                            /* < Execute ::: SubFunction > */
                            CallFunctionTwo(CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable, CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable);
                            break;
                        case TYPE_VARIABLE_FUNCTION_B:
                            /* < Copy ::: Pointer To Function... > */
                            CallFunctionTwo = (void*) CurrentWorkMenu->pxFunctionB;
                            /* < Execute ::: SubFunction > */
                            CallFunctionTwo(CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable, CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable);
                            break;
                        case TYPE_VARIABLE_FUNCTION_C:
                            /* < Copy ::: Pointer To Function... > */
                            CallFunctionTwo = (void*) CurrentWorkMenu->pxFunctionC;
                            /* < Execute ::: SubFunction > */
                            CallFunctionTwo(CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable, CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable);
                            break;
                        case TYPE_VARIABLE_FUNCTION_D:
                            /* < Copy ::: Pointer To Function... > */
                            CallFunctionTwo = (void*) CurrentWorkMenu->pxFunctionD;
                            /* < Execute ::: SubFunction > */
                            CallFunctionTwo(CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable, CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable);
                            break;
                    }
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputButtonY, InputJoystick->Buttons.Bits.xButton_Y, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Check ::: Valid Pointer > */
                if (CurrentListMenu[CurrentWorkMenu->xSelection].TypeFunction) {
                    /* < Check ::: Type of Variable> */
                    switch (CurrentListMenu[CurrentWorkMenu->xSelection].TypeFunction) {

                    }
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputButtonX, InputJoystick->Buttons.Bits.xButton_X, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Check ::: Valid Pointer > */
                if (CurrentListMenu[CurrentWorkMenu->xSelection].TypeFunction) {
                    /* < Check ::: Type of Variable> */
                    switch (CurrentListMenu[CurrentWorkMenu->xSelection].TypeFunction) {
                        case TYPE_VARIABLE_FUNCTION_D:
                            /* < Copy ::: Pointer To Function... > */
                            CallFunctionTwo = (void*) CurrentWorkMenu->pxFunctionE;
                            /* < Execute ::: SubFunction > */
                            CallFunctionTwo(CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable, CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable);
                            break;
                    }
                }
                /* < Return ::: Control > */
                Return = pdSet;
            } else if (xReadRepeatPulse(&InputButtonZ, InputJoystick->Buttons.Bits.xButton_Z, DIRECT_LOGIC, RELEALSE_BUTTON)) {
                /* < Check ::: if Varaible es Valid... > */
                if (CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable) {
                    /* < Check ::: Type of Variable> */
                    switch (CurrentListMenu[CurrentWorkMenu->xSelection].TypeVariable) {
                        case TYPE_VARIABLE_INT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint8_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable 
                                /* < Clear ::: Variable > */
                                *Byte = NULL;
                            } else if (CurrentListMenu[CurrentWorkMenu->xSelection ].SizeVariable == sizeof (uint16_t)) {
                                Word = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable 
                                /* < Clear ::: Variable > */
                                *Word = NULL;
                            } else if (CurrentListMenu[CurrentWorkMenu->xSelection ].SizeVariable == sizeof (uint32_t)) {
                                Long = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable 
                                /* < Clear ::: Variable > */
                                *Long = NULL;
                            }
                            break;
                        case TYPE_VARIABLE_BOOL:
                        case TYPE_VARIABLE_SIGNAL:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint1_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xSelection ].pxVariable; // < Pointer of Variable
                                /* < Clear ::: Variable > */
                                *Byte = pdClear;
                            }
                            break;
                        case TYPE_VARIABLE_BIT_BOOL:
                        case TYPE_VARIABLE_BIT_TEXT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint8_t)) {
                                Byte = CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable; // < Pointer of Variable
                                /* < Set ::: Bit of Variable > */
                                *Byte &= ~CurrentListMenu[CurrentWorkMenu->xSelection].LengthOptions;
                            }
                            break;
                        case TYPE_VARIABLE_TEXT:
                            /* < Check ::: Size of Variable > */
                            if (CurrentListMenu[CurrentWorkMenu->xSelection].SizeVariable == sizeof (uint8_t)) {
                                /* < Check ::: Lenght of Variable > */
                                if (CurrentListMenu[CurrentWorkMenu->xSelection].LengthOptions <= LENGTH_MAX_OPTIONS_TEXT) {
                                    Byte = CurrentListMenu[CurrentWorkMenu->xSelection].pxVariable; // < Pointer of Variable
                                    /* < Clear ::: Variable > */
                                    *Byte = NULL;
                                }
                            }
                            break;
                    }
                }
                /* < Return ::: Control > */
                Return = pdSet;
            }
            break;
        case TYPE_MENU_BAR:

            break;
        case TYPE_MENU_CLOCK:

            break;
        case TYPE_MENU_MESSAGE:

            break;
        case TYPE_MENU_BUTTONS:

            break;
    }
    /* < Return ::: Value > */
    return (Return);
}
