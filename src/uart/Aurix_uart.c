#include "Aurix_uart.h"

IFX_INTERRUPT(asclin0_Tx_ISR, 0, INTPRIO_ASCLIN0_TX);                         /* Adding the Interrupt Service Routine */

void asclin0_Tx_ISR(void)
{
    IfxAsclin_Asc_isrTransmit(&g_asc);
}

void init_UART(void)
{
    /* Initialize an instance of IfxAsclin_Asc_Config with default values */
    IfxAsclin_Asc_Config ascConfig;
    IfxAsclin_Asc_initModuleConfig(&ascConfig, SERIAL_PIN_TX.module);

    /* Set the desired baud rate */
    ascConfig.baudrate.baudrate = SERIAL_BAUDRATE;

    /* ISR priorities and interrupt target */
    ascConfig.interrupt.txPriority = INTPRIO_ASCLIN0_TX;
    ascConfig.interrupt.typeOfService = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());

    /* FIFO configuration */
    ascConfig.txBuffer = &g_ascTxBuffer;
    ascConfig.txBufferSize = ASC_TX_BUFFER_SIZE;

    /* Port pins configuration */
    const IfxAsclin_Asc_Pins pins =
    {
        NULL_PTR,         IfxPort_InputMode_pullUp,     /* CTS pin not used     */
        &SERIAL_PIN_RX,   IfxPort_InputMode_pullUp,     /* RX pin not used      */
        NULL_PTR,         IfxPort_OutputMode_pushPull,  /* RTS pin not used     */
        &SERIAL_PIN_TX,   IfxPort_OutputMode_pushPull,  /* TX pin               */
        IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
    ascConfig.pins = &pins;

    IfxAsclin_Asc_initModule(&g_asc, &ascConfig);                       /* Initialize module with above parameters  */
}

void send_UART_message(void)
{
    uint8 txData[] = "Hello World!";                                            /* Message to send      */
    Ifx_SizeT count = 12;                                                       /* Size of the message  */
    IfxAsclin_Asc_write(&g_asc, txData, &count, TIME_INFINITE);                 /* Transfer of data     */
    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME));    /* Wait 2 seconds       */
}