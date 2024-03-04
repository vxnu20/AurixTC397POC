#ifndef UART_VCOM_H_
#define UART_VCOM_H_

/* Includes */
#include <IfxAsclin_Asc.h>
#include <IfxCpu_Irq.h>
#include <Bsp.h>

/* Macros */
#define SERIAL_BAUDRATE         115200                     /* Baud rate in bit/s                   */

#define SERIAL_PIN_RX           IfxAsclin0_RXA_P14_1_IN    /* RX pin of the board                  */
#define SERIAL_PIN_TX           IfxAsclin0_TX_P14_0_OUT    /* TX pin of the board                  */

#define INTPRIO_ASCLIN0_TX      19                         /* Priority of the ISR                  */

#define ASC_TX_BUFFER_SIZE      64                         /* Definition of the buffer size        */

#define WAIT_TIME   2000                                    /* Wait time for the delay function */

/* Global variables */
IfxAsclin_Asc g_asc;                                       /* Declaration of the ASC handle        */

uint8 g_ascTxBuffer[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];   /* Declaration of the FIFOs parameters  */


/* Function Declarations */
void init_UART(void);           /* Initialization function  */
void send_UART_message(void);   /* Send function            */

#endif /* UART_VCOM_H_ */
