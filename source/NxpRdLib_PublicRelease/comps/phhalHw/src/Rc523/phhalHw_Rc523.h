/*
*         Copyright (c), NXP Semiconductors Gratkorn / Austria
*
*                     (C)NXP Semiconductors
*       All rights are reserved. Reproduction in whole or in part is 
*      prohibited without the written consent of the copyright owner.
*  NXP reserves the right to make changes without notice at any time.
* NXP makes no warranty, expressed, implied or statutory, including but
* not limited to any implied warranty of merchantability or fitness for any
*particular purpose, or that the use will not infringe any third party patent,
* copyright or trademark. NXP must not be liable for any loss or damage
*                          arising from its use.
*/

/** \file
* RC523 specific HAL-Component of Reader Library Framework.
* $Author: jayaprakash.desai $
* $Revision: 1.44 $
* $Date: Mon May 14 08:21:00 2012 $
*
* History:
*  CHu: Generated 19. May 2009
*
*/

#ifndef PHHALHW_RC523_H
#define PHHALHW_RC523_H

#include <ph_Status.h>
#include <phhalHw.h>

#define PHHAL_HW_RC523_FIFOSIZE         64U         /**< Size of RC internal FiFo buffer */
#define PHHAL_HW_RC523_DEFAULT_TIMEOUT  150U        /**< Default timeout in microseconds */

phStatus_t phhalHw_Rc523_Exchange(
                                  phhalHw_Rc523_DataParams_t * pDataParams,
                                  uint16_t wOption,
                                  uint8_t * pTxBuffer,
                                  uint16_t wTxLength,
                                  uint8_t ** ppRxBuffer,
                                  uint16_t * pRxLength
                                  );

phStatus_t phhalHw_Rc523_WriteRegister(
                                       phhalHw_Rc523_DataParams_t * pDataParams,
                                       uint8_t bAddress,
                                       uint8_t bValue
                                       );

phStatus_t phhalHw_Rc523_ReadRegister(
                                      phhalHw_Rc523_DataParams_t * pDataParams,
                                      uint8_t bAddress,
                                      uint8_t * pValue
                                      );

phStatus_t phhalHw_Rc523_ApplyProtocolSettings(
    phhalHw_Rc523_DataParams_t * pDataParams,
    uint8_t bCardType
    );

phStatus_t phhalHw_Rc523_MfcAuthenticateKeyNo(
    phhalHw_Rc523_DataParams_t * pDataParams,
    uint8_t bBlockNo,
    uint8_t bKeyType,
    uint16_t wKeyNo,
    uint16_t wKeyVersion,
    uint8_t * pUid
    );

phStatus_t phhalHw_Rc523_MfcAuthenticate(
    phhalHw_Rc523_DataParams_t * pDataParams,
    uint8_t bBlockNo,
    uint8_t bKeyType,
    uint8_t * pKey,
    uint8_t * pUid
    );

phStatus_t phhalHw_Rc523_SetConfig(
                                   phhalHw_Rc523_DataParams_t * pDataParams,
                                   uint16_t wConfig,
                                   uint16_t wValue
                                   );

phStatus_t phhalHw_Rc523_GetConfig(
                                   phhalHw_Rc523_DataParams_t * pDataParams,
                                   uint16_t wConfig,
                                   uint16_t * pValue
                                   );

phStatus_t phhalHw_Rc523_FieldOn(
                                 phhalHw_Rc523_DataParams_t * pDataParams
                                 );

phStatus_t phhalHw_Rc523_FieldOff(
                                  phhalHw_Rc523_DataParams_t * pDataParams
                                  );

phStatus_t phhalHw_Rc523_FieldReset(
                                    phhalHw_Rc523_DataParams_t * pDataParams
                                    );

phStatus_t phhalHw_Rc523_Wait(
                              phhalHw_Rc523_DataParams_t * pDataParams,
                              uint8_t bUnit,
                              uint16_t wTimeout
                              );

phStatus_t phhalHw_Rc523_SetMinFDT(
                                  phhalHw_Rc523_DataParams_t * pDataParams,
                                  uint16_t wValue
                                  );

#endif /* PHHALHW_RC523_H */
