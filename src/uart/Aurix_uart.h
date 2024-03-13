#ifndef UART_VCOM_H_
#define UART_VCOM_H_

/* Includes */
#include <IfxAsclin_Asc.h>
#include <IfxCpu_Irq.h>
#include <Bsp.h>
#include <Ifx_Shell.h>
#include <IfxStdIf_DPipe.h>
#include <Ifx_Console.h>

/* Macros */
#define SERIAL_BAUDRATE         115200                     /* Baud rate in bit/s                   */

#define SERIAL_PIN_RX           IfxAsclin0_RXA_P14_1_IN    /* RX pin of the board                  */
#define SERIAL_PIN_TX           IfxAsclin0_TX_P14_0_OUT    /* TX pin of the board                  */

#define ISR_PRIORITY_ASCLIN_TX      8                      /* Priority for interrupt ISR Transmit  */
#define ISR_PRIORITY_ASCLIN_RX      4                      /* Priority for interrupt ISR Receive   */
#define ISR_PRIORITY_ASCLIN_ER      12                     /* Priority for interrupt ISR Errors    */

#define ASC_TX_BUFFER_SIZE      256                         /* Definition of the TX buffer size        */
#define ASC_RX_BUFFER_SIZE      256                         /* Definition of the RX buffer size        */
#define STRING_SIZE             13                          /* Size of the string                       */

#define WAIT_TIME   2000                                    /* Wait time for the delay function */

/* Global variables */
IfxAsclin_Asc   g_asc;                                           /* Declaration of the ASC handle        */

uint8 g_ascTxBuffer[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];   /* Declaration of the TX FIFOs parameters  */
uint8 g_ascRxBuffer[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];   /* Declaration of the RX FIFOs parameters  */

/* Definition of txData and rxData */
uint8 g_txData[] = "Hello World!\n";

/* Size of the message */
Ifx_SizeT g_count = sizeof(g_txData);

/* Function Declarations */
void init_UART(void);           /* Initialization function  */
void process_UART(void);

#endif /* UART_VCOM_H_ */
