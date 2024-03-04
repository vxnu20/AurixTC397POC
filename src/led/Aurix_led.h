/* Includes */
#include <IfxPort.h>
#include <Bsp.h>

/* Macros */
/* LED D107: Port, Pin definition       */

// #define LED1   &MODULE_P33,4
// #define LED2   &MODULE_P33,5
// #define LED3   &MODULE_P33,6
// #define LED4   &MODULE_P33,7
// #define LED5   &MODULE_P20,11
// #define LED6   &MODULE_P20,12
// #define LED7   &MODULE_P20,13
#define LED8   &MODULE_P20,14

/* Delay wait time */
                                          
#define WAIT_TIME   500

/* Function Declarations */
void LED_init();
void LED_Toggle();