/**
 * \file IfxGpt12_PinMap.h
 * \brief GPT12 I/O map
 * \ingroup IfxLld_Gpt12
 *
 * \version iLLD_1_0_1_17_0_1
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxLld_Gpt12_pinmap GPT12 Pin Mapping
 * \ingroup IfxLld_Gpt12
 */

#ifndef IFXGPT12_PINMAP_H
#define IFXGPT12_PINMAP_H

#include <IfxGpt12_reg.h>
#include <_Impl/IfxGpt12_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Gpt12_pinmap
 * \{ */

/** \brief CAPIN pin mapping structure */
typedef const struct
{
    Ifx_GPT12*        module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxGpt12_Capin_In;

/** \brief TxEUD pin mapping structure */
typedef const struct
{
    Ifx_GPT12*        module;   /**< \brief Base address */
    uint8             timer;    /**< \brief Timer number */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxGpt12_TxEud_In;

/** \brief TxIN pin mapping structure */
typedef const struct
{
    Ifx_GPT12*        module;   /**< \brief Base address */
    uint8             timer;    /**< \brief Timer number */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxGpt12_TxIn_In;

/** \brief TxOUT pin mapping structure */
typedef const struct
{
    Ifx_GPT12*        module;   /**< \brief Base address */
    uint8             timer;    /**< \brief Timer number */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxGpt12_TxOut_Out;

IFX_EXTERN IfxGpt12_Capin_In IfxGpt120_CAPINA_P13_2_IN;  /**< \brief Trigger input to capture value of timer T5 into CAPREL register */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T2EUDA_P00_8_IN;  /**< \brief Count direction control input of timer T2 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T2EUDB_P33_6_IN;  /**< \brief Count direction control input of timer T2 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T3EUDA_P02_7_IN;  /**< \brief Count direction control input of core timer T3 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T3EUDB_P10_7_IN;  /**< \brief Count direction control input of core timer T3 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T4EUDA_P00_9_IN;  /**< \brief Count direction control input of timer T4 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T4EUDB_P33_5_IN;  /**< \brief Count direction control input of timer T4 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T5EUDA_P21_6_IN;  /**< \brief Count direction control input of timer T5 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T5EUDB_P10_1_IN;  /**< \brief Count direction control input of timer T5 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T6EUDA_P20_0_IN;  /**< \brief Count direction control input of core timer T6 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T6EUDB_P10_0_IN;  /**< \brief Count direction control input of core timer T6 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T2INA_P00_7_IN;  /**< \brief Trigger/gate input of timer T2 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T2INB_P33_7_IN;  /**< \brief Trigger/gate input of timer T2 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T3INA_P02_6_IN;  /**< \brief Trigger/gate input of core timer T3 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T3INB_P10_4_IN;  /**< \brief Trigger/gate input of core timer T3 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T4INA_P02_8_IN;  /**< \brief Trigger/gate input of timer T4 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T4INB_P10_8_IN;  /**< \brief Trigger/gate input of timer T4 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T5INA_P21_7_IN;  /**< \brief Trigger/gate input of timer T5 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T5INB_P10_3_IN;  /**< \brief Trigger/gate input of timer T5 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T6INA_P20_3_IN;  /**< \brief Trigger/gate input of core timer T6 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T6INB_P10_2_IN;  /**< \brief Trigger/gate input of core timer T6 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T3OUT_P10_6_OUT;  /**< \brief External output for overflow/underflow detection of core timer T3 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T3OUT_P21_6_OUT;  /**< \brief External output for overflow/underflow detection of core timer T3 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T6OUT_P10_5_OUT;  /**< \brief External output for overflow/underflow detection of core timer T6 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T6OUT_P21_7_OUT;  /**< \brief External output for overflow/underflow detection of core timer T6 */

/** \brief Table dimensions */
#define IFXGPT12_PINMAP_NUM_MODULES 1
#define IFXGPT12_PINMAP_NUM_TIMERS 7
#define IFXGPT12_PINMAP_CAPIN_IN_NUM_ITEMS 1
#define IFXGPT12_PINMAP_TXEUD_IN_NUM_ITEMS 2
#define IFXGPT12_PINMAP_TXIN_IN_NUM_ITEMS 2
#define IFXGPT12_PINMAP_TXOUT_OUT_NUM_ITEMS 2


/** \brief IfxGpt12_Capin_In table */
IFX_EXTERN const IfxGpt12_Capin_In *IfxGpt12_Capin_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_CAPIN_IN_NUM_ITEMS];

/** \brief IfxGpt12_TxEud_In table */
IFX_EXTERN const IfxGpt12_TxEud_In *IfxGpt12_TxEud_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXEUD_IN_NUM_ITEMS];

/** \brief IfxGpt12_TxIn_In table */
IFX_EXTERN const IfxGpt12_TxIn_In *IfxGpt12_TxIn_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXIN_IN_NUM_ITEMS];

/** \brief IfxGpt12_TxOut_Out table */
IFX_EXTERN const IfxGpt12_TxOut_Out *IfxGpt12_TxOut_Out_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXOUT_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXGPT12_PINMAP_H */
