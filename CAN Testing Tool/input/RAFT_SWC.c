/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  RAFT_SWC.c
 *           Config:  StartApplication.dpa
 *        SW-C Type:  RAFT_SWC
 *
 *        Generator:  MICROSAR RTE Generator Version 4.28.0
 *                    RTE Core Version 1.28.0
 *          License:  CBD2200270
 *
 *      Description:  C-Code implementation template for SW-C <RAFT_SWC>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Ascc_Esdd_St_Req_Struct
 *   Motor Control Operation Request
 *
 * Ascc_St_Req_Na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Asmc_1000Hz_F_Cmd_AlvCtr
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Asmc_1000Hz_F_Cmd_Crc
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Asmc_100Hz_Sts_VehStaty_AlvCtr
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Asmc_100Hz_Sts_VehStaty_Crc
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Asmc_100Hz_Zl_Mofr_AlvCtr
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Asmc_25Hz_Sts_AlvCtr
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Asmc_Req_DaHlthTest_Na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Faa_Sts_F_Qfr_Na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Faa_Sts_ZlMofr_Fn_Qfr_Na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Faa_Sts_ZlMofr_Re_Qfr_Na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Fas_Sts_VehSpdLo_Na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Fas_Sts_VehStaty_Na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Fas_Sts_VehStsSpdLo_Qfr_Na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Fas_Sts_VehStsStaty_Qfr_Na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Mode Declaration Groups:
 * ========================
 * Bsw_Control_Debug_Msg_Tx_Enum
 *   Enumeration to control transmission of debug CAN Messages
 *
 * Bsw_Shdn_Req_Enum
 *   Enumeration to request shutdown of EMM.
 *
 * Bsw_Timeout_Enum
 *   Enumeration to request shutdown of EMM.
 *
 *********************************************************************************************************************/

#include "Rte_RAFT_SWC.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "RAFT_SWC.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Asmc_1000Hz_F_Cmd_AlvCtr: Integer in interval [0...14]
 * Asmc_1000Hz_F_Cmd_Crc: Integer in interval [0...255]
 * Asmc_100Hz_Sts_VehStaty_AlvCtr: Integer in interval [0...14]
 * Asmc_100Hz_Sts_VehStaty_Crc: Integer in interval [0...255]
 * Asmc_100Hz_Zl_Mofr_AlvCtr: Integer in interval [0...14]
 * Asmc_25Hz_Sts_AlvCtr: Integer in interval [0...14]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Ascc_St_Req_Na: Enumeration of integer in interval [0...2] with enumerators
 *   Cx0_Uninitialized (0U)
 *   Cx1_Go_To_Corner_Sleep_State (1U)
 *   Cx2_Go_To_Corner_Active_State (2U)
 * Asmc_Req_DaHlthTest_Na: Enumeration of integer in interval [0...2] with enumerators
 *   Cx0_Do_not_Derive_Health_Test_Diagnostic_Data (0U)
 *   Cx1_Derive_Health_Test_Diagnostic_Data (1U)
 *   Cx2_RESERVED (2U)
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_AUTHENTICATIONREQUIRED (52U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_CVF_INVALIDTIMEPERIOD (80U)
 *   DCM_E_CVF_INVALIDSIGNATURE (81U)
 *   DCM_E_CVF_INVALIDCHAINOFTRUST (82U)
 *   DCM_E_CVF_INVALIDTYPE (83U)
 *   DCM_E_CVF_INVALIDFORMAT (84U)
 *   DCM_E_CVF_INVALIDCONTENT (85U)
 *   DCM_E_CVF_INVALIDSCOPE (86U)
 *   DCM_E_CVF_INVALIDCERTIFICATEREVOKED (87U)
 *   DCM_E_OWNERSHIPVERIFICATIONFAILED (88U)
 *   DCM_E_CHALLENGECALCULATIONFAILED (89U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * Dcm_OpStatusType: Enumeration of integer in interval [0...64] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 *   DCM_FORCE_RCRRP_NOT_OK (64U)
 * EmoCtl_Req_Enum: Enumeration of integer in interval [0...255] with enumerators
 *   EmoCtl_Req_Enum_GOTO_MOTOR_DRIVE_SUSPENDED (0U)
 *   EmoCtl_Req_Enum_GOTO_MOTOR_DRIVE_ON (1U)
 *   EmoCtl_Req_Enum_GOTO_MOTOR_DRIVE_OFF (2U)
 * EmoCtl_Sts_Enum: Enumeration of integer in interval [0...255] with enumerators
 *   EmoCtl_Sts_Enum_UNINITIALIZED (0U)
 *   EmoCtl_Sts_Enum_MOTOR_DRIVE_ON (1U)
 *   EmoCtl_Sts_Enum_MOTOR_DRIVE_OFF (2U)
 *   EmoCtl_Sts_Enum_MOTOR_DRIVE_SUSPENDED_INTERNAL (3U)
 *   EmoCtl_Sts_Enum_MOTOR_DRIVE_SUSPENDED_EXTERNAL (4U)
 * Faa_Sts_F_Qfr_Na: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Uninitialized (0U)
 *   Cx1_Healthy (1U)
 *   Cx2_Degraded (2U)
 *   Cx3_Unhealthy (3U)
 * Faa_Sts_ZlMofr_Fn_Qfr_Na: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Uninitialized (0U)
 *   Cx1_Healthy (1U)
 *   Cx2_Degraded (2U)
 *   Cx3_Unhealthy (3U)
 * Faa_Sts_ZlMofr_Re_Qfr_Na: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Uninitialized (0U)
 *   Cx1_Healthy (1U)
 *   Cx2_Degraded (2U)
 *   Cx3_Unhealthy (3U)
 * Fas_Sts_VehSpdLo_Na: Enumeration of integer in interval [0...2] with enumerators
 *   Cx0_Unknown (0U)
 *   Cx1_Low_Speed (1U)
 *   Cx2_Medium_to_High_Speed (2U)
 * Fas_Sts_VehStaty_Na: Enumeration of integer in interval [0...2] with enumerators
 *   Cx0_Unknown (0U)
 *   Cx1_Non_Stationary (1U)
 *   Cx2_Stationary (2U)
 * Fas_Sts_VehStsSpdLo_Qfr_Na: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Uninitialized (0U)
 *   Cx1_Healthy (1U)
 *   Cx2_NA (2U)
 *   Cx3_Unhealthy (3U)
 * Fas_Sts_VehStsStaty_Qfr_Na: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Uninitialized (0U)
 *   Cx1_Healthy (1U)
 *   Cx2_NA (2U)
 *   Cx3_Unhealthy (3U)
 * Shdn_Fb_Enum: Enumeration of integer in interval [0...255] with enumerators
 *   Shdn_Fb_Enum_NOT_REQUESTED (0U)
 *   Shdn_Fb_Enum_SHUTDOWN_READINESS_IN_PROGRESS (1U)
 *   Shdn_Fb_Enum_READY_TO_SHUTDOWN (2U)
 * Shdn_Req_Enum: Enumeration of integer in interval [0...255] with enumerators
 *   Shdn_Req_Enum_NO_SHUTDOWN_REQ (0U)
 *   Shdn_Req_Enum_PREPARE_FOR_SHUTDOWN (1U)
 *
 * Array Types:
 * ============
 * Dcm_Data8ByteType: Array with 8 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Ascc_Esdd_St_Req_Struct: Record with elements
 *   Ascc_EmoCtl_Req_Na of type EmoCtl_Req_Enum
 *   Ascc_Shdn_Req_Na of type Shdn_Req_Enum
 * Esdd_Ascc_St_Fb_Struct: Record with elements
 *   Esdd_EmoCtl_Sts_Na of type EmoCtl_Sts_Enum
 *   Esdd_Shdn_Fb_Na of type Shdn_Fb_Enum
 *
 *********************************************************************************************************************/


#define RAFT_SWC_START_SEC_CODE
#include "RAFT_SWC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_RAFT_TestDataIndetifier_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_RAFT_TestDataIndetifier>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_RAFT_TestDataIndetifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_RAFT_TestDataIndetifier_DCM_E_PENDING
 *   RTE_E_DataServices_RAFT_TestDataIndetifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_RAFT_TestDataIndetifier_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RAFT_SWC_CODE) DataServices_RAFT_TestDataIndetifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RAFT_SWC_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_RAFT_TestDataIndetifier_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_RAFT_TestDataIndetifier_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_RAFT_TestDataIndetifier>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_RAFT_TestDataIndetifier_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_RAFT_TestDataIndetifier_DCM_E_PENDING
 *   RTE_E_DataServices_RAFT_TestDataIndetifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_RAFT_TestDataIndetifier_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RAFT_SWC_CODE) DataServices_RAFT_TestDataIndetifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_RAFT_SWC_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_RAFT_TestDataIndetifier_ReadData (returns application error)
 *********************************************************************************************************************/


  return RTE_E_OK;
    


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RAFT_SWC_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RAFT_SWC_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, RAFT_SWC_CODE) RAFT_SWC_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RAFT_SWC_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RAFT_SWC_Main
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Ascc_St_Req_Na Rte_IRead_RAFT_SWC_Main_Ascc_St_Req_Na_Ascc_St_Req_Na(void)
 *   Asmc_1000Hz_F_Cmd_AlvCtr Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_AlvCtr_Asmc_1000Hz_F_Cmd_AlvCtr(void)
 *   Asmc_1000Hz_F_Cmd_Crc Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_Crc_Asmc_1000Hz_F_Cmd_Crc(void)
 *   Asmc_100Hz_Sts_VehStaty_AlvCtr Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_AlvCtr_Asmc_100Hz_Sts_VehStaty_AlvCtr(void)
 *   Asmc_100Hz_Sts_VehStaty_Crc Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_Crc_Asmc_100Hz_Sts_VehStaty_Crc(void)
 *   Asmc_100Hz_Zl_Mofr_AlvCtr Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Zl_Mofr_AlvCtr_Asmc_100Hz_Zl_Mofr_AlvCtr(void)
 *   Asmc_25Hz_Sts_AlvCtr Rte_IRead_RAFT_SWC_Main_Asmc_25Hz_Sts_AlvCtr_Asmc_25Hz_Sts_AlvCtr(void)
 *   Asmc_Req_DaHlthTest_Na Rte_IRead_RAFT_SWC_Main_Asmc_Req_DaHlthTest_Na_Asmc_Req_DaHlthTest_Na(void)
 *   sint16 Rte_IRead_RAFT_SWC_Main_Faa_F_Fl_AtActr_Cmd_Nwt_Faa_F_Fl_AtActr_Cmd_Nwt(void)
 *   sint16 Rte_IRead_RAFT_SWC_Main_Faa_F_Fr_AtActr_Cmd_Nwt_Faa_F_Fr_AtActr_Cmd_Nwt(void)
 *   sint16 Rte_IRead_RAFT_SWC_Main_Faa_F_Rl_AtActr_Cmd_Nwt_Faa_F_Rl_AtActr_Cmd_Nwt(void)
 *   sint16 Rte_IRead_RAFT_SWC_Main_Faa_F_Rr_AtActr_Cmd_Nwt_Faa_F_Rr_AtActr_Cmd_Nwt(void)
 *   uint8 Rte_IRead_RAFT_SWC_Main_Faa_Frq_Fn_ZlFil_Ce_Hz_Faa_Frq_Fn_ZlFil_Ce_Hz(void)
 *   uint8 Rte_IRead_RAFT_SWC_Main_Faa_Frq_Re_ZlFil_Ce_Hz_Faa_Frq_Re_ZlFil_Ce_Hz(void)
 *   uint8 Rte_IRead_RAFT_SWC_Main_Faa_Gain_Fn_ZlFil_Na_Faa_Gain_Fn_ZlFil_Na(void)
 *   uint8 Rte_IRead_RAFT_SWC_Main_Faa_Gain_Re_ZlFil_Na_Faa_Gain_Re_ZlFil_Na(void)
 *   uint8 Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Fn_ZlGain_Na_Faa_Mofr_Fn_ZlGain_Na(void)
 *   uint8 Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Re_ZlGain_Na_Faa_Mofr_Re_ZlGain_Na(void)
 *   Faa_Sts_F_Qfr_Na Rte_IRead_RAFT_SWC_Main_Faa_Sts_F_Qfr_Na_Faa_Sts_F_Qfr_Na(void)
 *   Faa_Sts_ZlMofr_Fn_Qfr_Na Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Fn_Qfr_Na_Faa_Sts_ZlMofr_Fn_Qfr_Na(void)
 *   Faa_Sts_ZlMofr_Re_Qfr_Na Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Re_Qfr_Na_Faa_Sts_ZlMofr_Re_Qfr_Na(void)
 *   uint8 Rte_IRead_RAFT_SWC_Main_Faa_Wi_Fn_ZlFil_Na_Faa_Wi_Fn_ZlFil_Na(void)
 *   uint8 Rte_IRead_RAFT_SWC_Main_Faa_Wi_Re_ZlFil_Na_Faa_Wi_Re_ZlFil_Na(void)
 *   Fas_Sts_VehSpdLo_Na Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehSpdLo_Na_Fas_Sts_VehSpdLo_Na(void)
 *   Fas_Sts_VehStaty_Na Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStaty_Na_Fas_Sts_VehStaty_Na(void)
 *   Fas_Sts_VehStsSpdLo_Qfr_Na Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsSpdLo_Qfr_Na_Fas_Sts_VehStsSpdLo_Qfr_Na(void)
 *   Fas_Sts_VehStsStaty_Qfr_Na Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsStaty_Qfr_Na_Fas_Sts_VehStsStaty_Qfr_Na(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RAFT_SWC_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, RAFT_SWC_CODE) RAFT_SWC_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RAFT_SWC_Main
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RAFT_SWC_STOP_SEC_CODE
#include "RAFT_SWC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
