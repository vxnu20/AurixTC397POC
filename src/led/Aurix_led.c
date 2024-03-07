#include "Aurix_led.h"



void LED_init()
{
    /* INIT GPIO PINS FOR LEDs */
    IfxPort_setPinModeOutput(LED8, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    // IfxPort_setPinModeOutput(LED7, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    // IfxPort_setPinModeOutput(LED6, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    // IfxPort_setPinModeOutput(LED5, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

    /* SET ALL LED TO HIGH */
    IfxPort_setPinState(LED8, IfxPort_State_high);
    // IfxPort_setPinState(LED6, IfxPort_State_high);
    // IfxPort_setPinState(LED6, IfxPort_State_high);
    // IfxPort_setPinState(LED5, IfxPort_State_high);

}

void LED_Toggle()
{
    /* TOGGLE THE STATE OF LEDs */
    IfxPort_setPinState(LED8, IfxPort_State_toggled);

    /* Wait 500 milliseconds */
    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME));    
}