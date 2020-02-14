#ifndef DRIVER_ANALOG_DIGITAL_CONVERTER_H
#define	DRIVER_ANALOG_DIGITAL_CONVERTER_H

/* < Configuration Bits Settings > */
#include "xc.h"
/* < Configuration Main Settings > */
#include "main_typedefs.h"
#include "main_delays.h"

/* < Definicion ::: Pines de Control :: ADC_Convert > */
#define TrisInputAN0                    TRISAbits.TRISA0

/* < Definicion ::: Configuracion INT :: ADC_Convert : Interruption > */
#define ADC_INT_ENABLE                  0x80  // < enable / disable interrupts
#define ADC_INT_DISABLE                 0x00

#define ADC_INT_PRI_0                   0x00 // < Setting the priority of adc interrupt
#define ADC_INT_PRI_1                   0x01
#define ADC_INT_PRI_2                   0x02
#define ADC_INT_PRI_3                   0x03
#define ADC_INT_PRI_4                   0x04
#define ADC_INT_PRI_5                   0x05
#define ADC_INT_PRI_6                   0x06
#define ADC_INT_PRI_7                   0x07

/* < Definicion ::: Configuracion 1 :: ADC_Convert : ADCON1 > */
#define ADC_MODULE_ON                   0x8000  // < A/D Converter on
#define ADC_MODULE_OFF                  0x0000  // < A/D Converter off

#define ADC_IDLE_STOP                   0x2000  // < A/D Stop in Idle mode
#define ADC_IDLE_CONTINUE               0x0000  // < A/D Operate in Idle mode 

#define ADC_ADDMABM_ORDER               0x1000  // < DMA buffers are written in the order of conversion 
#define ADC_ADDMABM_SCATTR              0x0000  // < DMA buffers are written in Scatter/Gather mode 

#define ADC_AD12B_12BIT                 0x0400  // < 12 bit, 1-channel ADC operation 
#define ADC_AD12B_10BIT                 0x0000  // < 10 bit, 4-channel ADC operation 

#define ADC_FORMAT_SIGN_INT             0x0100  // < A/D data format signed integer 
#define ADC_FORMAT_INTG                 0x0000  // < A/D data format integer 

#define ADC_CLK_AUTO                    0x00E0  // < Internal counter ends sampling and starts conversion (Auto convert) 
#define ADC_CLK_TMR5                    0x0080  // < GP Timer5 compare ends sampling and starts conversion 
#define ADC_CLK_TMR3                    0x0040  // < GP Timer3 compare ends sampling and starts conversion 
#define ADC_CLK_INT0                    0x0020  // < Active transition on INTx ends sampling and starts conversion 
#define ADC_CLK_MANUAL                  0x0000  // < Clearing sample (SAMP) bit ends sampling and starts conversion 

#define ADC_SIMULTANEOUS                0x0008  // < Simultaneous sampling of CH0, CH1, CH2 and CH3 based on CHPS and AD12B bits
#define ADC_MULTIPLE                    0x0000  // < Samples multiple channels individually in sequence 

#define ADC_AUTO_SAMPLING_ON            0x0004  // < Sampling begins immediately after last conversion 
#define ADC_AUTO_SAMPLING_OFF           0x0000  // < Sampling begins when SAMP bit is set 

#define ADC_SAMP_ON                     0x0002  // < sample / hold amplifiers are sampling 
#define ADC_SAMP_OFF                    0x0000  // < sample / hold amplifiers are holding 

/* < Definicion ::: Configuracion 2 :: ADC_Convert : ADCON 2 > */
#define ADC_VREF_AVDD_AVSS              0x0000  // < A/D Voltage reference configuration Vref+ is AVdd and Vref- is AVss  
#define ADC_VREF_EXT_AVSS               0x2000  // < A/D Voltage reference configuration Vref+ external and Vref- is AVss  
#define ADC_VREF_AVDD_EXT               0x4000  // < A/D Voltage reference configuration Vref+ AVdd and Vref- external  
#define ADC_VREF_EXT_EXT                0x6000  // < A/D Voltage reference configuration both Vref+ and Vref- are external  

#define ADC_SCAN_ON                     0x0400  // < A/D Scan Input Selections for CH0 during SAMPLE A  
#define ADC_SCAN_OFF                    0x0000  // < A/D Do notScan Input Selections for CH0+ during SAMPLE A  

#define ADC_SELECT_CHAN_0123            0x0300  // < Converts CH0, CH1, CH2 and CH3  
#define ADC_SELECT_CHAN_01              0x0100  // < Converts CH0 and CH1  
#define ADC_SELECT_CHAN_0               0x0000  // < Converts CH0  

#define ADC_BUF_FILL_0x8_0xF            0x0080  // < ADC is currently filling buffer 0x8-0xF
#define ADC_BUF_FILL_0x0_0x7            0x0000  // < ADC is currently filling buffer 0x0-0x7

#define ADC_SAMPLES_PER_INT_1           0x0000 // <A/D Interrupt at the completion of conversion for each sample  
#define ADC_SAMPLES_PER_INT_2           0x0004 // <A/D Interrupt at the completion of conversion for each 2nd sample  
#define ADC_SAMPLES_PER_INT_3           0x0008 // <A/D interrupt at the completion of conversion for each 3rd sample  
#define ADC_SAMPLES_PER_INT_4           0x000C // <A/D interrupt at the completion of conversion for each 4th sample  
#define ADC_SAMPLES_PER_INT_5           0x0010 // <A/D interrupt at the completion of conversion for each 5th sample  
#define ADC_SAMPLES_PER_INT_6           0x0014 // <A/D interrupt at the completion of conversion for each 6th sample  
#define ADC_SAMPLES_PER_INT_7           0x0030 // <A/D interrupt at the completion of conversion for each 7th sample  
#define ADC_SAMPLES_PER_INT_8           0x001C // <A/D interrupt at the completion of conversion for each 8th sample  
#define ADC_SAMPLES_PER_INT_9           0x0020 // <A/D interrupt at the completion of conversion for each 9th sample  
#define ADC_SAMPLES_PER_INT_10          0x0024 // <A/D interrupt at the completion of conversion for each 10th sample  
#define ADC_SAMPLES_PER_INT_11          0x0028 // <A/D interrupt at the completion of conversion for each 11th sample  
#define ADC_SAMPLES_PER_INT_12          0x002C // <A/D interrupt at the completion of conversion for each 12th sample  
#define ADC_SAMPLES_PER_INT_13          0x0030 // <A/D interrupt at the completion of conversion for each 13th sample  
#define ADC_SAMPLES_PER_INT_14          0x0034 // <A/D interrupt at the completion of conversion for each 14th sample  
#define ADC_SAMPLES_PER_INT_15          0x0038 // <A/D interrupt at the completion of conversion for each 15th sample  
#define ADC_SAMPLES_PER_INT_16          0x003C // <A/D interrupt at the completion of conversion for each 16th sample  

#define ADC_ALT_BUF_ON                  0x0002  // < Buffer configured as 8-word buffers  
#define ADC_ALT_BUF_OFF                 0x0000  // < Buffer configured as 16-word buffer  

#define ADC_ALT_INPUT_ON                0x0001  // < Alternate between MUXA and MUXB  
#define ADC_ALT_INPUT_OFF               0x0000  // < Use MUXA only  

/* < Definicion ::: Configuracion 3 :: ADC_Convert : ADCON 3 > */
#define ADC_CONV_CLK_INT_RC             0x8000  // < A/D Conversion Clock Source internal RC Clock  
#define ADC_CONV_CLK_SYSTEM             0x0000  // < A/D Conversion Clock Source Clock derived from system clock  

#define ADC_SAMPLE_TIME_0               0x0000  // < A/D Auto Sample Time 0 Tad  
#define ADC_SAMPLE_TIME_1               0x0100  // < A/D Auto Sample Time 1 Tad  
#define ADC_SAMPLE_TIME_2               0x0200  // < A/D Auto Sample Time 2 Tad  
#define ADC_SAMPLE_TIME_3               0x0300  // < A/D Auto Sample Time 3 Tad  
#define ADC_SAMPLE_TIME_4               0x0400  // < A/D Auto Sample Time 4 Tad  
#define ADC_SAMPLE_TIME_5               0x0500  // < A/D Auto Sample Time 5 Tad  
#define ADC_SAMPLE_TIME_6               0x0600  // < A/D Auto Sample Time 6 Tad  
#define ADC_SAMPLE_TIME_7               0x0700  // < A/D Auto Sample Time 7 Tad  
#define ADC_SAMPLE_TIME_8               0x0800  // < A/D Auto Sample Time 8 Tad  
#define ADC_SAMPLE_TIME_9               0x0900  // < A/D Auto Sample Time 9 Tad  
#define ADC_SAMPLE_TIME_10              0x0A00  // < A/D Auto Sample Time 10 Tad  
#define ADC_SAMPLE_TIME_11              0x0B00  // < A/D Auto Sample Time 11 Tad  
#define ADC_SAMPLE_TIME_12              0x0C00  // < A/D Auto Sample Time 12 Tad  
#define ADC_SAMPLE_TIME_13              0x0D00  // < A/D Auto Sample Time 13 Tad  
#define ADC_SAMPLE_TIME_14              0x0E00  // < A/D Auto Sample Time 14 Tad  
#define ADC_SAMPLE_TIME_15              0x0F00  // < A/D Auto Sample Time 15 Tad  
#define ADC_SAMPLE_TIME_16              0x1000  // < A/D Auto Sample Time 16 Tad  
#define ADC_SAMPLE_TIME_17              0x1100  // < A/D Auto Sample Time 17 Tad  
#define ADC_SAMPLE_TIME_18              0x1200  // < A/D Auto Sample Time 18 Tad  
#define ADC_SAMPLE_TIME_19              0x1300  // < A/D Auto Sample Time 19 Tad  
#define ADC_SAMPLE_TIME_20              0x1400  // < A/D Auto Sample Time 20 Tad  
#define ADC_SAMPLE_TIME_21              0x1500  // < A/D Auto Sample Time 21 Tad  
#define ADC_SAMPLE_TIME_22              0x1600  // < A/D Auto Sample Time 22 Tad  
#define ADC_SAMPLE_TIME_23              0x1700  // < A/D Auto Sample Time 23 Tad  
#define ADC_SAMPLE_TIME_24              0x1800  // < A/D Auto Sample Time 24 Tad  
#define ADC_SAMPLE_TIME_25              0x1900  // < A/D Auto Sample Time 25 Tad  
#define ADC_SAMPLE_TIME_26              0x1A00  // < A/D Auto Sample Time 26 Tad  
#define ADC_SAMPLE_TIME_27              0x1B00  // < A/D Auto Sample Time 27 Tad  
#define ADC_SAMPLE_TIME_28              0x1C00  // < A/D Auto Sample Time 28 Tad  
#define ADC_SAMPLE_TIME_29              0x1D00  // < A/D Auto Sample Time 29 Tad  
#define ADC_SAMPLE_TIME_30              0x1E00  // < A/D Auto Sample Time 30 Tad  
#define ADC_SAMPLE_TIME_31              0x1F00  // < A/D Auto Sample Time 31 Tad  

#define ADC_CONV_CLK_256Tcy             0x00FF  // < A/D conversion clock select bit ADCS<7:0> 
#define ADC_CONV_CLK_255Tcy             0x00FE  
#define ADC_CONV_CLK_254Tcy             0x00FD  
#define ADC_CONV_CLK_253Tcy             0x00FC  
#define ADC_CONV_CLK_252Tcy             0x00FB
#define ADC_CONV_CLK_251Tcy             0x00FA
#define ADC_CONV_CLK_250Tcy             0x00F9
#define ADC_CONV_CLK_249Tcy             0x00F8
#define ADC_CONV_CLK_248Tcy             0x00F7
#define ADC_CONV_CLK_247Tcy             0x00F6
#define ADC_CONV_CLK_246Tcy             0x00F5
#define ADC_CONV_CLK_245Tcy             0x00F4
#define ADC_CONV_CLK_244Tcy             0x00F3
#define ADC_CONV_CLK_243Tcy             0x00F2
#define ADC_CONV_CLK_242Tcy             0x00F1
#define ADC_CONV_CLK_241Tcy             0x00F0
#define ADC_CONV_CLK_240Tcy             0x00EF
#define ADC_CONV_CLK_239Tcy             0x00EE
#define ADC_CONV_CLK_238Tcy             0x00ED
#define ADC_CONV_CLK_237Tcy             0x00EC
#define ADC_CONV_CLK_236Tcy             0X00EB
#define ADC_CONV_CLK_235Tcy             0x00EA
#define ADC_CONV_CLK_234Tcy             0x00E9
#define ADC_CONV_CLK_233Tcy             0x00E8
#define ADC_CONV_CLK_232Tcy             0x00E7
#define ADC_CONV_CLK_231Tcy             0x00E6
#define ADC_CONV_CLK_230Tcy             0x00E5
#define ADC_CONV_CLK_229Tcy             0x00E4
#define ADC_CONV_CLK_228Tcy             0x00E3
#define ADC_CONV_CLK_227Tcy             0x00E2
#define ADC_CONV_CLK_226Tcy             0x00E1
#define ADC_CONV_CLK_225Tcy             0x00E0
#define ADC_CONV_CLK_224Tcy             0x00DF
#define ADC_CONV_CLK_223Tcy             0x00DE
#define ADC_CONV_CLK_222Tcy             0x00DD
#define ADC_CONV_CLK_221Tcy             0x00DC
#define ADC_CONV_CLK_220Tcy             0x00DB
#define ADC_CONV_CLK_219Tcy             0x00DA
#define ADC_CONV_CLK_218Tcy             0x00D9
#define ADC_CONV_CLK_217Tcy             0x00D8
#define ADC_CONV_CLK_216Tcy             0x00D7
#define ADC_CONV_CLK_215Tcy             0x00D6
#define ADC_CONV_CLK_214Tcy             0x00D5
#define ADC_CONV_CLK_213Tcy             0x00D4
#define ADC_CONV_CLK_212Tcy             0x00D3
#define ADC_CONV_CLK_211Tcy             0x00D2
#define ADC_CONV_CLK_210Tcy             0x00D1
#define ADC_CONV_CLK_209Tcy             0x00D0
#define ADC_CONV_CLK_208Tcy             0x00CF
#define ADC_CONV_CLK_207Tcy             0x00CE
#define ADC_CONV_CLK_206Tcy             0x00CD
#define ADC_CONV_CLK_205Tcy             0x00CC
#define ADC_CONV_CLK_204Tcy             0x00CB
#define ADC_CONV_CLK_203Tcy             0x00CA
#define ADC_CONV_CLK_202Tcy             0x00C9
#define ADC_CONV_CLK_201Tcy             0x00C8
#define ADC_CONV_CLK_200Tcy             0x00C7
#define ADC_CONV_CLK_199Tcy             0x00C6
#define ADC_CONV_CLK_198Tcy             0x00C5
#define ADC_CONV_CLK_197Tcy             0x00C4
#define ADC_CONV_CLK_196Tcy             0x00C3
#define ADC_CONV_CLK_195Tcy             0x00C2
#define ADC_CONV_CLK_194Tcy             0x00C1  
#define ADC_CONV_CLK_193Tcy             0x00C0 
#define ADC_CONV_CLK_192Tcy             0x00BF  
#define ADC_CONV_CLK_191Tcy             0x00BE  
#define ADC_CONV_CLK_190Tcy             0x00BD  
#define ADC_CONV_CLK_189Tcy             0x00BC  
#define ADC_CONV_CLK_188Tcy             0x00BB
#define ADC_CONV_CLK_187Tcy             0x00BA
#define ADC_CONV_CLK_186Tcy             0x00B9
#define ADC_CONV_CLK_185Tcy             0x00B8
#define ADC_CONV_CLK_184Tcy             0x00B7
#define ADC_CONV_CLK_183Tcy             0x00B6
#define ADC_CONV_CLK_182Tcy             0x00B5
#define ADC_CONV_CLK_181Tcy             0x00B4
#define ADC_CONV_CLK_180Tcy             0x00B3
#define ADC_CONV_CLK_179Tcy             0x00B2
#define ADC_CONV_CLK_178Tcy             0x00B1
#define ADC_CONV_CLK_177Tcy             0x00B0
#define ADC_CONV_CLK_176Tcy             0x00AF
#define ADC_CONV_CLK_175Tcy             0x00AE
#define ADC_CONV_CLK_174Tcy             0x00AD
#define ADC_CONV_CLK_173Tcy             0x00AC
#define ADC_CONV_CLK_172Tcy             0x00AB
#define ADC_CONV_CLK_171Tcy             0x00AA
#define ADC_CONV_CLK_170Tcy             0x00A9
#define ADC_CONV_CLK_169Tcy             0x00A8
#define ADC_CONV_CLK_168Tcy             0x00A7
#define ADC_CONV_CLK_167Tcy             0x00A6
#define ADC_CONV_CLK_166Tcy             0x00A5
#define ADC_CONV_CLK_165Tcy             0x00A4
#define ADC_CONV_CLK_164Tcy             0x00A3
#define ADC_CONV_CLK_163Tcy             0x00A2
#define ADC_CONV_CLK_162Tcy             0x00A1
#define ADC_CONV_CLK_161Tcy             0x00A0
#define ADC_CONV_CLK_160Tcy             0x009F
#define ADC_CONV_CLK_159Tcy             0x009E
#define ADC_CONV_CLK_158Tcy             0x009D
#define ADC_CONV_CLK_157Tcy             0x009C
#define ADC_CONV_CLK_156Tcy             0x009B
#define ADC_CONV_CLK_155Tcy             0x009A
#define ADC_CONV_CLK_154Tcy             0x0099
#define ADC_CONV_CLK_153Tcy             0x0098
#define ADC_CONV_CLK_152Tcy             0x0097
#define ADC_CONV_CLK_151Tcy             0x0096
#define ADC_CONV_CLK_150Tcy             0x0095
#define ADC_CONV_CLK_149Tcy             0x0094
#define ADC_CONV_CLK_148Tcy             0x0093
#define ADC_CONV_CLK_147Tcy             0x0092
#define ADC_CONV_CLK_146Tcy             0x0091
#define ADC_CONV_CLK_145Tcy             0x0090
#define ADC_CONV_CLK_144Tcy             0x008F
#define ADC_CONV_CLK_143Tcy             0x008E
#define ADC_CONV_CLK_142Tcy             0x008D
#define ADC_CONV_CLK_141Tcy             0x008C
#define ADC_CONV_CLK_140Tcy             0x008B
#define ADC_CONV_CLK_139Tcy             0x008A
#define ADC_CONV_CLK_138Tcy             0x0089
#define ADC_CONV_CLK_137Tcy             0x0088
#define ADC_CONV_CLK_136Tcy             0x0087
#define ADC_CONV_CLK_135Tcy             0x0086
#define ADC_CONV_CLK_134Tcy             0x0085
#define ADC_CONV_CLK_133Tcy             0x0084
#define ADC_CONV_CLK_132Tcy             0x0083
#define ADC_CONV_CLK_131Tcy             0x0082
#define ADC_CONV_CLK_130Tcy             0x0081  
#define ADC_CONV_CLK_129Tcy             0x0080  
#define ADC_CONV_CLK_128Tcy             0x007F  
#define ADC_CONV_CLK_127Tcy             0x007E  
#define ADC_CONV_CLK_126Tcy             0x007D  
#define ADC_CONV_CLK_125Tcy             0x007C  
#define ADC_CONV_CLK_124Tcy             0x007B
#define ADC_CONV_CLK_123Tcy             0x007A
#define ADC_CONV_CLK_122Tcy             0x0079
#define ADC_CONV_CLK_121Tcy             0x0078
#define ADC_CONV_CLK_120Tcy             0x0077
#define ADC_CONV_CLK_119Tcy             0x0076
#define ADC_CONV_CLK_118Tcy             0x0075
#define ADC_CONV_CLK_117Tcy             0x0074
#define ADC_CONV_CLK_116Tcy             0x0073
#define ADC_CONV_CLK_115Tcy             0x0072
#define ADC_CONV_CLK_114Tcy             0x0071
#define ADC_CONV_CLK_113Tcy             0x0070
#define ADC_CONV_CLK_112Tcy             0x006F
#define ADC_CONV_CLK_111Tcy             0x006E
#define ADC_CONV_CLK_110Tcy             0x006D
#define ADC_CONV_CLK_109Tcy             0x006C
#define ADC_CONV_CLK_108Tcy             0x006B
#define ADC_CONV_CLK_107Tcy             0x006A
#define ADC_CONV_CLK_106Tcy             0x0069
#define ADC_CONV_CLK_105Tcy             0x0068
#define ADC_CONV_CLK_104Tcy             0x0067
#define ADC_CONV_CLK_103Tcy             0x0066
#define ADC_CONV_CLK_102Tcy             0x0065
#define ADC_CONV_CLK_101Tcy             0x0064
#define ADC_CONV_CLK_100Tcy             0x0063
#define ADC_CONV_CLK_99Tcy              0x0062
#define ADC_CONV_CLK_98Tcy              0x0061
#define ADC_CONV_CLK_97Tcy              0x0060
#define ADC_CONV_CLK_96Tcy              0x005F
#define ADC_CONV_CLK_95Tcy              0x005E
#define ADC_CONV_CLK_94Tcy              0x005D
#define ADC_CONV_CLK_93Tcy              0x005C
#define ADC_CONV_CLK_92Tcy              0x005B
#define ADC_CONV_CLK_91Tcy              0x005A
#define ADC_CONV_CLK_90Tcy              0x0059
#define ADC_CONV_CLK_89Tcy              0x0058
#define ADC_CONV_CLK_88Tcy              0x0057
#define ADC_CONV_CLK_87Tcy              0x0056
#define ADC_CONV_CLK_86Tcy              0x0055
#define ADC_CONV_CLK_85Tcy              0x0054
#define ADC_CONV_CLK_84Tcy              0x0053
#define ADC_CONV_CLK_83Tcy              0x0052
#define ADC_CONV_CLK_82Tcy              0x0051
#define ADC_CONV_CLK_81Tcy              0x0050
#define ADC_CONV_CLK_80Tcy              0x004F
#define ADC_CONV_CLK_79Tcy              0x004E
#define ADC_CONV_CLK_78Tcy              0x004D
#define ADC_CONV_CLK_77Tcy              0x004C
#define ADC_CONV_CLK_76Tcy              0x004B
#define ADC_CONV_CLK_75Tcy              0x004A
#define ADC_CONV_CLK_74Tcy              0x0049
#define ADC_CONV_CLK_73Tcy              0x0048
#define ADC_CONV_CLK_72Tcy              0x0047
#define ADC_CONV_CLK_71Tcy              0x0046
#define ADC_CONV_CLK_70Tcy              0x0045
#define ADC_CONV_CLK_69Tcy              0x0044
#define ADC_CONV_CLK_68Tcy              0x0043
#define ADC_CONV_CLK_67Tcy              0x0042
#define ADC_CONV_CLK_66Tcy              0x0041  
#define ADC_CONV_CLK_65Tcy              0x0040 
#define ADC_CONV_CLK_64Tcy              0x003F  
#define ADC_CONV_CLK_63Tcy              0x003E  
#define ADC_CONV_CLK_62Tcy              0x003D  
#define ADC_CONV_CLK_61Tcy              0x003C  
#define ADC_CONV_CLK_60Tcy              0x003B
#define ADC_CONV_CLK_59Tcy              0x003A
#define ADC_CONV_CLK_58Tcy              0x0039
#define ADC_CONV_CLK_57Tcy              0x0038
#define ADC_CONV_CLK_56Tcy              0x0037
#define ADC_CONV_CLK_55Tcy              0x0036
#define ADC_CONV_CLK_54Tcy              0x0035
#define ADC_CONV_CLK_53Tcy              0x0034
#define ADC_CONV_CLK_52Tcy              0x0033
#define ADC_CONV_CLK_51Tcy              0x0032
#define ADC_CONV_CLK_50Tcy              0x0031
#define ADC_CONV_CLK_49Tcy              0x0030
#define ADC_CONV_CLK_48Tcy              0x002F
#define ADC_CONV_CLK_47Tcy              0x002E
#define ADC_CONV_CLK_46Tcy              0x002D
#define ADC_CONV_CLK_45Tcy              0x002C
#define ADC_CONV_CLK_44Tcy              0x002B
#define ADC_CONV_CLK_43Tcy              0x002A
#define ADC_CONV_CLK_42Tcy              0x0029
#define ADC_CONV_CLK_41Tcy              0x0028
#define ADC_CONV_CLK_40Tcy              0x0027
#define ADC_CONV_CLK_39Tcy              0x0026
#define ADC_CONV_CLK_38Tcy              0x0025
#define ADC_CONV_CLK_37Tcy              0x0024
#define ADC_CONV_CLK_36Tcy              0x0023
#define ADC_CONV_CLK_35Tcy              0x0022
#define ADC_CONV_CLK_34Tcy              0x0021
#define ADC_CONV_CLK_33Tcy              0x0020
#define ADC_CONV_CLK_32Tcy              0x001F
#define ADC_CONV_CLK_31Tcy              0x001E
#define ADC_CONV_CLK_30Tcy              0x001D
#define ADC_CONV_CLK_29Tcy              0x001C
#define ADC_CONV_CLK_28Tcy              0x001B
#define ADC_CONV_CLK_27Tcy              0x001A
#define ADC_CONV_CLK_26Tcy              0x0019
#define ADC_CONV_CLK_25Tcy              0x0018
#define ADC_CONV_CLK_24Tcy              0x0017
#define ADC_CONV_CLK_23Tcy              0x0016
#define ADC_CONV_CLK_22Tcy              0x0015
#define ADC_CONV_CLK_21Tcy              0x0014
#define ADC_CONV_CLK_20Tcy              0x0013
#define ADC_CONV_CLK_19Tcy              0x0012
#define ADC_CONV_CLK_18Tcy              0x0011
#define ADC_CONV_CLK_17Tcy              0x0010
#define ADC_CONV_CLK_16Tcy              0x000F
#define ADC_CONV_CLK_15Tcy              0x000E
#define ADC_CONV_CLK_14Tcy              0x000D
#define ADC_CONV_CLK_13Tcy              0x000C
#define ADC_CONV_CLK_12Tcy              0x000B
#define ADC_CONV_CLK_11Tcy              0x000A
#define ADC_CONV_CLK_10Tcy              0x0009
#define ADC_CONV_CLK_9Tcy               0x0008
#define ADC_CONV_CLK_8Tcy               0x0007
#define ADC_CONV_CLK_7Tcy               0x0006
#define ADC_CONV_CLK_6Tcy               0x0005
#define ADC_CONV_CLK_5Tcy               0x0004
#define ADC_CONV_CLK_4Tcy               0x0003
#define ADC_CONV_CLK_3Tcy               0x0002
#define ADC_CONV_CLK_2Tcy               0x0001  
#define ADC_CONV_CLK_1Tcy               0x0000

/* < Definicion ::: Configuracion 4 :: ADC_Convert : ADCON 4 > */
#define ADC_DMA_BUF_LOC_128             0x0007  // < Allocates words of buffer to each analog input 
#define ADC_DMA_BUF_LOC_64              0x0006  // < Allocates words of buffer to each analog input 
#define ADC_DMA_BUF_LOC_32              0x0005  // < Allocates words of buffer to each analog input 
#define ADC_DMA_BUF_LOC_16              0x0004  // < Allocates words of buffer to each analog input 
#define ADC_DMA_BUF_LOC_8               0x0003  // < Allocates words of buffer to each analog input 
#define ADC_DMA_BUF_LOC_4               0x0002  // < Allocates words of buffer to each analog input 
#define ADC_DMA_BUF_LOC_2               0x0001  // < Allocates words of buffer to each analog input 
#define ADC_DMA_BUF_LOC_1               0x0000  // < Allocates words of buffer to each analog input 

/* < Definicion ::: Configuracion 5 :: ADC_Convert : AD1CHS123 > */
#define ADC_CH123_NEG_SAMPLEB_9_10_11  0x0600 // <A/D CH1 neg i/p is AN9 , CH2 neg i/p is AN10, CH3 neg i/p is AN11 
#define ADC_CH123_NEG_SAMPLEB_6_7_8    0x0400 // <A/D CH1 neg i/p is AN6 , CH2 neg i/p is AN7, CH3 neg i/p is AN8 
#define ADC_CH123_NEG_SAMPLEB_NVREF    0x0000 // <A/D CH1, CH2 and CH3 neg i/p is Vref- 

#define ADC_CH123_POS_SAMPLEB_3_4_5    0x0100 // < A/D CH1 pos i/p is AN3, CH2 pos i/p is AN4, CH3 pos i/p is AN5 
#define ADC_CH123_POS_SAMPLEB_0_1_2    0x0000 // < A/D CH1 pos i/p is AN0, CH2 pos i/p is AN1, CH3 pos i/p is AN2 

#define ADC_CH123_NEG_SAMPLEA_9_10_11  0x0006 // <A/D CH1 neg i/p is AN9 , CH2 neg i/p is AN10, CH3 neg i/p is AN11 
#define ADC_CH123_NEG_SAMPLEA_6_7_8    0x0004 // <A/D CH1 neg i/p is AN6 , CH2 neg i/p is AN7, CH3 neg i/p is AN8 
#define ADC_CH123_NEG_SAMPLEA_NVREF    0x0000 // <A/D CH1 , CH2 and CH3 neg i/p is Vref- 

#define ADC_CH123_POS_SAMPLEA_3_4_5    0x0001 // < A/D CH1 pos i/p is AN3, CH2 pos i/p is AN4, CH3 pos i/p is AN5
#define ADC_CH123_POS_SAMPLEA_0_1_2    0x0000 // < A/D CH1 pos i/p is AN0, CH2 pos i/p is AN1, CH3 pos i/p is AN2

// < Definicion ::: Configuracion 6 :: ADC_Convert : AD1CHS0 > */
#define ADC_CH0_NEG_SAMPLEB_AN1        0x8000 // < A/D CH0 neg I/P sel for SAMPLE B is AN01  
#define ADC_CH0_NEG_SAMPLEB_NVREF      0x0000 // < A/D CH0 neg I/P sel for SAMPLE B is nVref  

#define ADC_CH0_POS_SAMPLEB_AN31       0x1F00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN31  
#define ADC_CH0_POS_SAMPLEB_AN30       0x1E00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN30  
#define ADC_CH0_POS_SAMPLEB_AN29       0x1D00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN29  
#define ADC_CH0_POS_SAMPLEB_AN28       0x1C00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN28  
#define ADC_CH0_POS_SAMPLEB_AN27       0x1B00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN27  
#define ADC_CH0_POS_SAMPLEB_AN26       0x1A00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN26  
#define ADC_CH0_POS_SAMPLEB_AN25       0x1900 // <  A/D CH0 pos i/p sel for SAMPLE B is AN25  
#define ADC_CH0_POS_SAMPLEB_AN24       0x1800 // <  A/D CH0 pos i/p sel for SAMPLE B is AN24  
#define ADC_CH0_POS_SAMPLEB_AN23       0x1700 // <  A/D CH0 pos i/p sel for SAMPLE B is AN23  
#define ADC_CH0_POS_SAMPLEB_AN22       0x1600 // <  A/D CH0 pos i/p sel for SAMPLE B is AN22  
#define ADC_CH0_POS_SAMPLEB_AN21       0x1500 // <  A/D CH0 pos i/p sel for SAMPLE B is AN21  
#define ADC_CH0_POS_SAMPLEB_AN20       0x1400 // <  A/D CH0 pos i/p sel for SAMPLE B is AN20  
#define ADC_CH0_POS_SAMPLEB_AN19       0x1300 // <  A/D CH0 pos i/p sel for SAMPLE B is AN19  
#define ADC_CH0_POS_SAMPLEB_AN18       0x1200 // <  A/D CH0 pos i/p sel for SAMPLE B is AN18  
#define ADC_CH0_POS_SAMPLEB_AN17       0x1100 // <  A/D CH0 pos i/p sel for SAMPLE B is AN17  
#define ADC_CH0_POS_SAMPLEB_AN16       0x1000 // <  A/D CH0 pos i/p sel for SAMPLE B is AN16  
#define ADC_CH0_POS_SAMPLEB_AN15       0x0F00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN15  
#define ADC_CH0_POS_SAMPLEB_AN14       0x0E00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN14  
#define ADC_CH0_POS_SAMPLEB_AN13       0x0D00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN13  
#define ADC_CH0_POS_SAMPLEB_AN12       0x0C00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN12  
#define ADC_CH0_POS_SAMPLEB_AN11       0x0B00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN11  
#define ADC_CH0_POS_SAMPLEB_AN10       0x0A00 // <  A/D CH0 pos i/p sel for SAMPLE B is AN10  
#define ADC_CH0_POS_SAMPLEB_AN9        0x0900 // <  A/D CH0 pos i/p sel for SAMPLE B is AN09  
#define ADC_CH0_POS_SAMPLEB_AN8        0x0800 // <  A/D CH0 pos i/p sel for SAMPLE B is AN08  
#define ADC_CH0_POS_SAMPLEB_AN7        0x0700 // <  A/D CH0 pos i/p sel for SAMPLE B is AN07  
#define ADC_CH0_POS_SAMPLEB_AN6        0x0600 // <  A/D CH0 pos i/p sel for SAMPLE B is AN06  
#define ADC_CH0_POS_SAMPLEB_AN5        0x0500 // <  A/D CH0 pos i/p sel for SAMPLE B is AN05  
#define ADC_CH0_POS_SAMPLEB_AN4        0x0400 // <  A/D CH0 pos i/p sel for SAMPLE B is AN04  
#define ADC_CH0_POS_SAMPLEB_AN3        0x0300 // <  A/D CH0 pos i/p sel for SAMPLE B is AN03  
#define ADC_CH0_POS_SAMPLEB_AN2        0x0200 // <  A/D CH0 pos i/p sel for SAMPLE B is AN02  
#define ADC_CH0_POS_SAMPLEB_AN1        0x0100 // <  A/D CH0 pos i/p sel for SAMPLE B is AN01  
#define ADC_CH0_POS_SAMPLEB_AN0        0x0000 // <  A/D CH0 pos i/p sel for SAMPLE B is AN00  

#define ADC_CH0_NEG_SAMPLEA_AN1        0x0080 // < A/D CH0 neg I/P sel for SAMPLE A is AN01  
#define ADC_CH0_NEG_SAMPLEA_NVREF      0x0000 // < A/D CH0 neg I/P sel for SAMPLE A is nVref  

#define ADC_CH0_POS_SAMPLEA_AN31       0x001F // <  A/D CH0 pos i/p sel for SAMPLE A is AN31  
#define ADC_CH0_POS_SAMPLEA_AN30       0x001E // <  A/D CH0 pos i/p sel for SAMPLE A is AN30  
#define ADC_CH0_POS_SAMPLEA_AN29       0x001D // <  A/D CH0 pos i/p sel for SAMPLE A is AN29  
#define ADC_CH0_POS_SAMPLEA_AN28       0x001C // <  A/D CH0 pos i/p sel for SAMPLE A is AN28  
#define ADC_CH0_POS_SAMPLEA_AN27       0x001B // <  A/D CH0 pos i/p sel for SAMPLE A is AN27  
#define ADC_CH0_POS_SAMPLEA_AN26       0x001A // <  A/D CH0 pos i/p sel for SAMPLE A is AN26  
#define ADC_CH0_POS_SAMPLEA_AN25       0x0019 // <  A/D CH0 pos i/p sel for SAMPLE A is AN25  
#define ADC_CH0_POS_SAMPLEA_AN24       0x0018 // <  A/D CH0 pos i/p sel for SAMPLE A is AN24  
#define ADC_CH0_POS_SAMPLEA_AN23       0x0017 // <  A/D CH0 pos i/p sel for SAMPLE A is AN23  
#define ADC_CH0_POS_SAMPLEA_AN22       0x0016 // <  A/D CH0 pos i/p sel for SAMPLE A is AN22  
#define ADC_CH0_POS_SAMPLEA_AN21       0x0015 // <  A/D CH0 pos i/p sel for SAMPLE A is AN21  
#define ADC_CH0_POS_SAMPLEA_AN20       0x0014 // <  A/D CH0 pos i/p sel for SAMPLE A is AN20  
#define ADC_CH0_POS_SAMPLEA_AN19       0x0013 // <  A/D CH0 pos i/p sel for SAMPLE A is AN19  
#define ADC_CH0_POS_SAMPLEA_AN18       0x0012 // <  A/D CH0 pos i/p sel for SAMPLE A is AN18  
#define ADC_CH0_POS_SAMPLEA_AN17       0x0011 // <  A/D CH0 pos i/p sel for SAMPLE A is AN17  
#define ADC_CH0_POS_SAMPLEA_AN16       0x0010 // <  A/D CH0 pos i/p sel for SAMPLE A is AN16  
#define ADC_CH0_POS_SAMPLEA_AN15       0x000F // <  A/D CH0 pos i/p sel for SAMPLE A is AN15  
#define ADC_CH0_POS_SAMPLEA_AN14       0x000E // <  A/D CH0 pos i/p sel for SAMPLE A is AN14  
#define ADC_CH0_POS_SAMPLEA_AN13       0x000D // <  A/D CH0 pos i/p sel for SAMPLE A is AN13  
#define ADC_CH0_POS_SAMPLEA_AN12       0x000C // <  A/D CH0 pos i/p sel for SAMPLE A is AN12  
#define ADC_CH0_POS_SAMPLEA_AN11       0x000B // <  A/D CH0 pos i/p sel for SAMPLE A is AN11  
#define ADC_CH0_POS_SAMPLEA_AN10       0x000A // <  A/D CH0 pos i/p sel for SAMPLE A is AN10  
#define ADC_CH0_POS_SAMPLEA_AN9        0x0009 // <  A/D CH0 pos i/p sel for SAMPLE A is AN09  
#define ADC_CH0_POS_SAMPLEA_AN8        0x0008 // <  A/D CH0 pos i/p sel for SAMPLE A is AN08  
#define ADC_CH0_POS_SAMPLEA_AN7        0x0007 // <  A/D CH0 pos i/p sel for SAMPLE A is AN07  
#define ADC_CH0_POS_SAMPLEA_AN6        0x0006 // <  A/D CH0 pos i/p sel for SAMPLE A is AN06  
#define ADC_CH0_POS_SAMPLEA_AN5        0x0005 // <  A/D CH0 pos i/p sel for SAMPLE A is AN05  
#define ADC_CH0_POS_SAMPLEA_AN4        0x0004 // <  A/D CH0 pos i/p sel for SAMPLE A is AN04  
#define ADC_CH0_POS_SAMPLEA_AN3        0x0003 // <  A/D CH0 pos i/p sel for SAMPLE A is AN03  
#define ADC_CH0_POS_SAMPLEA_AN2        0x0002 // <  A/D CH0 pos i/p sel for SAMPLE A is AN02  
#define ADC_CH0_POS_SAMPLEA_AN1        0x0001 // <  A/D CH0 pos i/p sel for SAMPLE A is AN01  
#define ADC_CH0_POS_SAMPLEA_AN0        0x0000 // <  A/D CH0 pos i/p sel for SAMPLE A is AN00  

// < Definicion ::: Configuracion 7 :: ADC_Convert : AD1CSSL >  
#define SELECT_SCAN_AN0                0x0001 // <  Select AN00 for Input Scan  
#define SELECT_SCAN_AN1                0x0002 // <  Select AN01 for Input Scan      
#define SELECT_SCAN_AN2                0x0004 // <  Select AN02 for Input Scan  
#define SELECT_SCAN_AN3                0x0008 // <  Select AN03 for Input Scan  
#define SELECT_SCAN_AN4                0x0010 // <  Select AN04 for Input Scan  
#define SELECT_SCAN_AN5                0x0020 // <  Select AN05 for Input Scan      
#define SELECT_SCAN_AN6                0x0040 // <  Select AN06 for Input Scan  
#define SELECT_SCAN_AN7                0x0080 // <  Select AN07 for Input Scan  
#define SELECT_SCAN_AN8                0x0100 // <  Select AN08 for Input Scan  
#define SELECT_SCAN_AN9                0x0200 // <  Select AN09 for Input Scan      
#define SELECT_SCAN_AN10               0x0400 // <  Select AN10 for Input Scan  
#define SELECT_SCAN_AN11               0x0800 // <  Select AN11 for Input Scan  
#define SELECT_SCAN_AN12               0x1000 // <  Select AN12 for Input Scan  

#define SKIP_SCAN_AN0                  0x0000 // <  Skip AN0 for Input Scan  
#define SKIP_SCAN_AN1                  0x0000 // <  Skip AN1 for Input Scan      
#define SKIP_SCAN_AN2                  0x0000 // <  Skip AN2 for Input Scan  
#define SKIP_SCAN_AN3                  0x0000 // <  Skip AN3 for Input Scan  
#define SKIP_SCAN_AN4                  0x0000 // <  Skip AN4 for Input Scan  
#define SKIP_SCAN_AN5                  0x0000 // <  Skip AN5 for Input Scan      
#define SKIP_SCAN_AN6                  0x0000 // <  Skip AN6 for Input Scan  
#define SKIP_SCAN_AN7                  0x0000 // <  Skip AN7 for Input Scan  
#define SKIP_SCAN_AN8                  0x0000 // <  Skip AN8 for Input Scan  
#define SKIP_SCAN_AN9                  0x0000 // <  Skip AN9 for Input Scan      
#define SKIP_SCAN_AN10                 0x0000 // <  Skip AN10 for Input Scan  
#define SKIP_SCAN_AN11                 0x0000 // <  Skip AN11 for Input Scan  
#define SKIP_SCAN_AN12                 0x0000 // <  Skip AN12 for Input Scan  

#define SCAN_NONE                      0x0000  // < Skip AN0-AN15 for Input Scan  
#define SCAN_ALL                       0x1FFF  // < Enable AN0-AN15 for Input Scan  

// < Definicion ::: Configuracion 8 :: ADC_Convert : AD1PCFGL > */
#define ANALOG_AN00_ANA                0x1FFE  // < Analog AN00 in analog mode  
#define ANALOG_AN01_ANA                0x1FFD  // < Analog AN01 in analog mode  
#define ANALOG_AN02_ANA                0x1FFB  // < Analog AN02 in analog mode  
#define ANALOG_AN03_ANA                0x1FF7  // < Analog AN03 in analog mode  
#define ANALOG_AN04_ANA                0x1FEF  // < Analog AN04 in analog mode  
#define ANALOG_AN05_ANA                0x1FDF  // < Analog AN05 in analog mode  
#define ANALOG_AN06_ANA                0x1FBF  // < Analog AN06 in analog mode  
#define ANALOG_AN07_ANA                0x1F7F  // < Analog AN07 in analog mode  
#define ANALOG_AN08_ANA                0x1EFF  // < Analog AN08 in analog mode  
#define ANALOG_AN09_ANA                0x1DFF  // < Analog AN09 in analog mode  
#define ANALOG_AN10_ANA                0x1BFF  // < Analog AN10 in analog mode  
#define ANALOG_AN11_ANA                0x17FF  // < Analog AN11 in analog mode  
#define ANALOG_AN12_ANA                0x0FFF  // < Analog AN12 in analog mode 

#define DIGITAL_AN00_ANA               0x0001  // < Digital AN00 in analog mode  
#define DIGITAL_AN01_ANA               0x0002  // < Digital AN01 in analog mode  
#define DIGITAL_AN02_ANA               0x0004  // < Digital AN02 in analog mode  
#define DIGITAL_AN03_ANA               0x0008  // < Digital AN03 in analog mode  
#define DIGITAL_AN04_ANA               0x0010  // < Digital AN04 in analog mode  
#define DIGITAL_AN05_ANA               0x0020  // < Digital AN05 in analog mode  
#define DIGITAL_AN06_ANA               0x0040  // < Digital AN06 in analog mode  
#define DIGITAL_AN07_ANA               0x0080  // < Digital AN07 in analog mode  
#define DIGITAL_AN08_ANA               0x0100  // < Digital AN08 in analog mode  
#define DIGITAL_AN09_ANA               0x0200  // < Digital AN09 in analog mode  
#define DIGITAL_AN10_ANA               0x0400  // < Digital AN10 in analog mode  
#define DIGITAL_AN11_ANA               0x0800  // < Digital AN11 in analog mode  
#define DIGITAL_AN12_ANA               0x1000  // < Digital AN12 in analog mode 

#define MASK_INPUTS_ALL_DIGITAL        0x1FFF // < All Inputs Digitals 
#define MAKS_ANALOG_ALL_ANALOG         0x0000 // < All Inputs Digitals

/* < Prototipo ::: Funciones de Control ::: ADC_Convert > */
void vConfigureADCConverter(uint8_t Config_INT, uint16_t Config_1, uint16_t Config_2, uint16_t Config_3, uint16_t Config_4, uint16_t Config_5, uint16_t Config_6, uint16_t Config_7, uint16_t Config_8);
void vConvertADCConverter(void);
void vSetChanADCConverter(uint16_t Channel123, uint16_t Channel0);
uint16_t xReadADCConverter(void);
uint8_t xBusyADCConverter(void);

#endif	/* < DRIVER_ANALOG_DIGITAL_CONVERTER_H > */

