#include <xc.h>
#include "mcc_generated_files/system/system.h"
#include "application.h"

/*
 ***********************************************************
 *                                                         *
 *          User Defined Function Definitions              *
 *                                                         *
 ***********************************************************
*/
void Application(void)
{
    uint8_t sevenSegArrIndex;                         // Seven Segment Array Index variable
    uint8_t input_command;
    
    if(SS_GetValue()==LOW)                              // SS line is LOW 
    {
        input_command = SPI1_ByteRead();             // Read command received on SPI from host
        
        if(input_command == START_0_9_DISPLAY_LOOP)                  
        {
            for (sevenSegArrIndex = 0; sevenSegArrIndex < SEVEN_SEG_COUNT; sevenSegArrIndex++)     // Loop to display 0-9 on SSD
            {
                
                LATB = sevenSegHexCodePortB[sevenSegArrIndex]; 
                LATD = sevenSegHexCodePortD[sevenSegArrIndex]; 
                __delay_ms(DELAY);
                LED_Toggle();                          // Toggle the on board LED after every count          
            }
            LATB = sevenSegHexCodePortB[0];                 // Reset display on 7 Segment Display to zero
            LATD = sevenSegHexCodePortD[0];                 // Reset display on 7 Segment Display to zero
        }
    }         
}

