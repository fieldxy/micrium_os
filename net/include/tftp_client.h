/***************************************************************************//**
 * @file
 * @brief Network - Tftp Client Module
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc.  Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.
 * The software is governed by the sections of the MSLA applicable to Micrium
 * Software.
 *
 ******************************************************************************/

/****************************************************************************************************//**
 * @defgroup NET_TFTPc TFTP Client API
 * @ingroup  NET
 * @brief    TFTP Client API
 *
 * @addtogroup NET_TFTPc
 * @{
 *******************************************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                               MODULE
 ********************************************************************************************************
 *******************************************************************************************************/

#ifndef  _TFTP_CLIENT_H_
#define  _TFTP_CLIENT_H_

/********************************************************************************************************
 ********************************************************************************************************
 *                                            INCLUDE FILES
 ********************************************************************************************************
 *******************************************************************************************************/

#include  <net/include/net_ip.h>
#include  <net/include/net_type.h>
#include  <net/include/net_fs.h>

#include  <cpu/include/cpu.h>
#include  <common/include/rtos_err.h>

/********************************************************************************************************
 ********************************************************************************************************
 *                                               DEFINES
 ********************************************************************************************************
 *******************************************************************************************************/

/********************************************************************************************************
 *                                    DEFAULT CONFIGURATION VALUES
 *******************************************************************************************************/

#define  TFTP_CLIENT_CFG_PORT_NBR_DFLT                          69

#define  TFTP_CLIENT_CFG_RX_TIMEOUT_MS_DFLT                     5000u
#define  TFTP_CLIENT_CFG_TX_TIMEOUT_MS_DFLT                     5000u

/********************************************************************************************************
 ********************************************************************************************************
 *                                             DATA TYPES
 ********************************************************************************************************
 *******************************************************************************************************/

/*
 ********************************************************************************************************
 *                                        TFTPc MODE DATA TYPE
 *******************************************************************************************************/

typedef  enum tftc_mode {
  TFTPc_MODE_NETASCII = 1,
  TFTPc_MODE_OCTET,
  TFTPc_MODE_MAIL,
} TFTPc_MODE;

/*
 ********************************************************************************************************
 *                                    TFTPc CONFIGURATION DATA TYPE
 *******************************************************************************************************/

typedef  struct  tftpc_cfg {
  NET_PORT_NBR ServerPortNbr;
  CPU_INT32U   RxInactivityTimeout_ms;
  CPU_INT32U   TxInactivityTimeout_ms;
} TFTPc_CFG;

/********************************************************************************************************
 ********************************************************************************************************
 *                                          GLOBAL VARIABLES
 ********************************************************************************************************
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

extern const TFTPc_CFG TFTPc_CfgDflt;

/********************************************************************************************************
 ********************************************************************************************************
 *                                         FUNCTION PROTOTYPES
 ********************************************************************************************************
 *******************************************************************************************************/

void TFTPc_Get(CPU_CHAR        *p_host_server,
               const TFTPc_CFG *p_cfg,
               CPU_CHAR        *p_filename_local,
               CPU_CHAR        *p_filename_remote,
               TFTPc_MODE      mode,
               RTOS_ERR        *p_err);

void TFTPc_Put(CPU_CHAR        *p_host_server,
               const TFTPc_CFG *p_cfg,
               CPU_CHAR        *p_filename_local,
               CPU_CHAR        *p_filename_remote,
               TFTPc_MODE      mode,
               RTOS_ERR        *p_err);

#ifdef __cplusplus
}
#endif

/****************************************************************************************************//**
 ********************************************************************************************************
 * @}                                          MODULE END
 ********************************************************************************************************
 *******************************************************************************************************/

#endif  // _TFTP_CLIENT_H_
