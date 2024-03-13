#include "Aurix_uart.h"

/*
 * IFX_INTERRUPT(isr, vectabNum, priority)
 *  - isr: Name of the ISR function.
 *  - vectabNum: Vector table number.
 *  - priority: Interrupt priority. Refer Usage of Interrupt Macro for more details.
*/

IFX_INTERRUPT(asclin0_Tx_ISR, 0, ISR_PRIORITY_ASCLIN_TX);

void asclin0_Tx_ISR(void)
{
    IfxAsclin_Asc_isrTransmit(&g_asc);
}

IFX_INTERRUPT(asclin0_Rx_ISR, 0, ISR_PRIORITY_ASCLIN_RX);

void asclin0_Rx_ISR(void)
{
    IfxAsclin_Asc_isrTransmit(&g_asc);
}

IFX_INTERRUPT(asc0ErrISR, 0, ISR_PRIORITY_ASCLIN_ER);

void asc0ErrISR(void)
{
    IfxStdIf_DPipe_onError(&g_asc);
}

void init_UART(void)
{
    /* Initialize an instance of IfxAsclin_Asc_Config with default values */
    IfxAsclin_Asc_Config ascConfig;
    IfxAsclin_Asc_initModuleConfig(&ascConfig, SERIAL_PIN_TX.module);

    /* Set the desired baud rate */
    ascConfig.baudrate.baudrate = SERIAL_BAUDRATE;
    /* Set the oversampling factor      */
    ascConfig.baudrate.oversampling = IfxAsclin_OversamplingFactor_16;    

    /* Configure the sampling mode */
    ascConfig.bitTiming.medianFilter = IfxAsclin_SamplesPerBit_three;             /* Set the number of samples per bit*/
    ascConfig.bitTiming.samplePointPosition = IfxAsclin_SamplePointPosition_8;    /* Set the first sample position    */


    /* ISR priorities and interrupt target */
    ascConfig.interrupt.txPriority = ISR_PRIORITY_ASCLIN_TX;
    ascConfig.interrupt.rxPriority = ISR_PRIORITY_ASCLIN_RX;
    ascConfig.interrupt.erPriority = ISR_PRIORITY_ASCLIN_ER;
    ascConfig.interrupt.typeOfService = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());

    /* FIFO configuration */
    ascConfig.txBuffer = &g_ascTxBuffer;
    ascConfig.txBufferSize = ASC_TX_BUFFER_SIZE;
    ascConfig.rxBuffer = &g_ascRxBuffer;
    ascConfig.rxBufferSize = ASC_RX_BUFFER_SIZE;

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

    /* Initialize module with above parameters  */
    IfxAsclin_Asc_initModule(&g_asc, &ascConfig);     
}

void process_UART(void)
{
    IfxAsclin_Asc_write(&g_asc, g_txData, &g_count, TIME_INFINITE);   /* Transmit data via TX */
    //IfxAsclin_Asc_read(&g_asc, g_rxData, &g_count, TIME_INFINITE); 
}