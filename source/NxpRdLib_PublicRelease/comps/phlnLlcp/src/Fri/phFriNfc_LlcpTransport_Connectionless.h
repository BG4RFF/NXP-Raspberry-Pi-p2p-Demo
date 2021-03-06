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
 * \file  phFriNfc_LlcpTransport_Connectionless.h
 * \brief 
 *
 * Project: NFC-FRI
 *
 */
#ifndef PHFRINFC_LLCP_TRANSPORT_CONNECTIONLESS_H
#define PHFRINFC_LLCP_TRANSPORT_CONNECTIONLESS_H
/*include files*/
#include "phNfcTypes.h"
#include <ph_Status.h>
#include "phFriNfc.h"

#include "phFriNfc_Llcp.h"


void Handle_Connectionless_IncommingFrame(phFriNfc_LlcpTransport_t      *pLlcpTransport,
                                          phNfc_sData_t                 *psData,
                                          uint8_t                       dsap,
                                          uint8_t                       ssap);

NFCSTATUS phFriNfc_LlcpTransport_Connectionless_HandlePendingOperations(phFriNfc_LlcpTransport_Socket_t *pSocket);

/**
* \ingroup grp_fri_nfc
* \brief <b>Close a socket on a LLCP-connectionless device</b>.
*
* This function closes a LLCP socket previously created using phFriNfc_LlcpTransport_Socket.
*
* \param[in]  pLlcpSocket                    A pointer to a phFriNfc_LlcpTransport_Socket_t.

* \retval NFCSTATUS_SUCCESS                  Operation successful.
* \retval NFCSTATUS_INVALID_PARAMETER        One or more of the supplied parameters
*                                            could not be properly interpreted.
* \retval NFCSTATUS_FAILED                   Operation failed.
*/
NFCSTATUS phFriNfc_LlcpTransport_Connectionless_Close(phFriNfc_LlcpTransport_Socket_t*   pLlcpSocket);

/**
* \ingroup grp_fri_nfc
* \brief <b>Send data on a socket to a given destination SAP</b>.
*
* This function is used to write data on a socket to a given destination SAP.
* This function can only be called on a connectionless socket.
* 
*
* \param[in]  pLlcpSocket        A pointer to a LlcpSocket created.
* \param[in]  nSap               The destination SAP.
* \param[in]  psBuffer           The buffer containing the data to send.
* \param[in]  pSend_RspCb        The callback to be called when the 
*                                operation is completed.
* \param[in]  pContext           Upper layer context to be returned in
*                                the callback.
*
* \retval NFCSTATUS_SUCCESS                  Operation successful.
* \retval NFCSTATUS_INVALID_PARAMETER        One or more of the supplied parameters
*                                            could not be properly interpreted.
* \retval NFCSTATUS_PENDING                  Reception operation is in progress,
*                                            pSend_RspCb will be called upon completion.
* \retval NFCSTATUS_INVALID_STATE            The socket is not in a valid state, or not of 
*                                            a valid type to perform the requsted operation.
* \retval NFCSTATUS_NOT_INITIALISED          Indicates stack is not yet initialized.
* \retval NFCSTATUS_SHUTDOWN                 Shutdown in progress.
* \retval NFCSTATUS_FAILED                   Operation failed.
*/
NFCSTATUS phFriNfc_LlcpTransport_Connectionless_SendTo(phFriNfc_LlcpTransport_Socket_t             *pLlcpSocket,
                                                       uint8_t                                     nSap,
                                                       phNfc_sData_t*                              psBuffer,
                                                       pphFriNfc_LlcpTransportSocketSendCb_t       pSend_RspCb,
                                                       void*                                       pContext);

 /**
* \ingroup grp_lib_nfc
* \brief <b>Read data on a socket and get the source SAP</b>.
*
* This function is the same as phLibNfc_Llcp_Recv, except that the callback includes
* the source SAP. This functions can only be called on a connectionless socket.
* 
*
* \param[in]  pLlcpSocket        A pointer to a LlcpSocket created.
* \param[in]  psBuffer           The buffer receiving the data.
* \param[in]  pRecv_RspCb        The callback to be called when the 
*                                operation is completed.
* \param[in]  pContext           Upper layer context to be returned in
*                                the callback.
*
* \retval NFCSTATUS_SUCCESS                  Operation successful.
* \retval NFCSTATUS_INVALID_PARAMETER        One or more of the supplied parameters
*                                            could not be properly interpreted.
* \retval NFCSTATUS_PENDING                  Reception operation is in progress,
*                                            pRecv_RspCb will be called upon completion.
* \retval NFCSTATUS_INVALID_STATE            The socket is not in a valid state, or not of 
*                                            a valid type to perform the requsted operation.
* \retval NFCSTATUS_NOT_INITIALISED          Indicates stack is not yet initialized.
* \retval NFCSTATUS_SHUTDOWN                 Shutdown in progress.
* \retval NFCSTATUS_FAILED                   Operation failed.
*/
NFCSTATUS phLibNfc_LlcpTransport_Connectionless_RecvFrom(phFriNfc_LlcpTransport_Socket_t                   *pLlcpSocket,
                                                         phNfc_sData_t*                                    psBuffer,
                                                         pphFriNfc_LlcpTransportSocketRecvFromCb_t         pRecv_Cb,
                                                         void*                                             pContext);

#endif /* PHFRINFC_LLCP_TRANSPORT_CONNECTIONLESS_H */