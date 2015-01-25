/*
*                  Copyright (c), NXP Semiconductors
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

/**
 * \file  phFriNfc_LlcpUtils.h
 * \brief NFC LLCP utils
 *
 * Project: NFC-FRI
 *
 */

#ifndef PHFRINFC_LLCPUTILS_H
#define PHFRINFC_LLCPUTILS_H

/*include files*/
#include "phNfcHalTypes.h"
#include "phNfcTypes.h"
#include <ph_Status.h>
#include "phFriNfc.h"
#include "phFriNfc_Llcp.h"

/** 
 * \name NFC Forum Logical Link Control Protocol Utils
 *
 * File: \ref phFriNfc_LlcpUtils.h
 *
 */

/**
 * UTIL_FIFO_BUFFER - A Cyclic FIFO buffer
 * If pIn == pOut the buffer is empty.
 */
typedef struct UTIL_FIFO_BUFFER
{
   uint8_t          *pBuffStart;    /* Points to first valid location in buffer */
   uint8_t          *pBuffEnd;      /* Points to last valid location in buffer */
   volatile uint8_t *pIn;           /* Points to 1 before where the next TU1 will enter buffer */
   volatile uint8_t *pOut;          /* Points to 1 before where the next TU1 will leave buffer */
   volatile bool_t  bFull;         /* TRUE if buffer is full */
}UTIL_FIFO_BUFFER, *P_UTIL_FIFO_BUFFER;


/** \defgroup grp_fri_nfc_llcp NFC Forum Logical Link Control Protocol Component
 *
 *  TODO
 *
 */

NFCSTATUS phFriNfc_Llcp_DecodeTLV( phNfc_sData_t  *psRawData,
                                   uint32_t       *pOffset,
                                   uint8_t        *pType,
                                   phNfc_sData_t  *psValueBuffer );

NFCSTATUS phFriNfc_Llcp_EncodeTLV( phNfc_sData_t  *psValueBuffer,
                                   uint32_t       *pOffset,
                                   uint8_t        type,
                                   uint8_t        length,
                                   uint8_t        *pValue);

NFCSTATUS phFriNfc_Llcp_AppendTLV( phNfc_sData_t  *psValueBuffer,
                                   uint32_t       nTlvOffset,
                                   uint32_t       *pCurrentOffset,
                                   uint8_t        length,
                                   uint8_t        *pValue);

void phFriNfc_Llcp_EncodeRW(uint8_t *pRw);

/**
 * Initializes a Fifo Cyclic Buffer to point to some allocated memory.
 */
void phFriNfc_Llcp_CyclicFifoInit(P_UTIL_FIFO_BUFFER     sUtilFifo,
                                  const uint8_t        *pBuffStart,
                                  uint32_t             buffLength);

/**
 * Clears the Fifo Cyclic Buffer - loosing any data that was in it.
 */
void phFriNfc_Llcp_CyclicFifoClear(P_UTIL_FIFO_BUFFER sUtilFifo);


/**
 * Attempts to write dataLength bytes to the specified Fifo Cyclic Buffer.
 */
uint32_t phFriNfc_Llcp_CyclicFifoWrite(P_UTIL_FIFO_BUFFER     sUtilFifo,
                                       uint8_t              *pData,
                                       uint32_t             dataLength);

/**
 * Attempts to read dataLength bytes from the specified  Fifo Cyclic Buffer.
 */
uint32_t phFriNfc_Llcp_CyclicFifoFifoRead(P_UTIL_FIFO_BUFFER     sUtilFifo,
                                          uint8_t              *pBuffer,
                                          uint32_t             dataLength);

/**
 * Returns the number of bytes currently stored in Fifo Cyclic Buffer.
 */
uint32_t phFriNfc_Llcp_CyclicFifoUsage(P_UTIL_FIFO_BUFFER sUtilFifo);

/**
 * Returns the available room for writing in Fifo Cyclic Buffer.
 */
uint32_t phFriNfc_Llcp_CyclicFifoAvailable(P_UTIL_FIFO_BUFFER sUtilFifo);

uint32_t phFriNfc_Llcp_Header2Buffer( phFriNfc_Llcp_sPacketHeader_t *psHeader,
                                      uint8_t *pBuffer,
                                      uint32_t nOffset );

uint32_t phFriNfc_Llcp_Sequence2Buffer( phFriNfc_Llcp_sPacketSequence_t *psSequence,
                                        uint8_t *pBuffer,
                                        uint32_t nOffset );

uint32_t phFriNfc_Llcp_Buffer2Header( uint8_t *pBuffer,
                                      uint32_t nOffset,
                                      phFriNfc_Llcp_sPacketHeader_t *psHeader );

uint32_t phFriNfc_Llcp_Buffer2Sequence( uint8_t *pBuffer,
                                        uint32_t nOffset,
                                        phFriNfc_Llcp_sPacketSequence_t *psSequence );


#endif /* PHFRINFC_LLCPUTILS_H */
