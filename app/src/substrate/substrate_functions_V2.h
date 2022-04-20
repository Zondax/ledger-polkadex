/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V2.h"
#include "substrate_types_V2.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V2(parser_context_t* c, pd_AccountId_V2_t* v);
parser_error_t _readAccountIndex_V2(parser_context_t* c, pd_AccountIndex_V2_t* v);
parser_error_t _readAmount_V2(parser_context_t* c, pd_Amount_V2_t* v);
parser_error_t _readAssetId_V2(parser_context_t* c, pd_AssetId_V2_t* v);
parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V2(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V2_t* v);
parser_error_t _readAuthorityIndex_V2(parser_context_t* c, pd_AuthorityIndex_V2_t* v);
parser_error_t _readBoxEquivocationProofHashBlockNumber_V2(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V2_t* v);
parser_error_t _readBoxEquivocationProofHeader_V2(parser_context_t* c, pd_BoxEquivocationProofHeader_V2_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V2(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V2_t* v);
parser_error_t _readBoxPalletsOrigin_V2(parser_context_t* c, pd_BoxPalletsOrigin_V2_t* v);
parser_error_t _readBoxRawSolutionSolutionOfT_V2(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V2_t* v);
parser_error_t _readBoxUnprocessedEthereumBlock_V2(parser_context_t* c, pd_BoxUnprocessedEthereumBlock_V2_t* v);
parser_error_t _readCallHashOf_V2(parser_context_t* c, pd_CallHashOf_V2_t* v);
parser_error_t _readCodeHashT_V2(parser_context_t* c, pd_CodeHashT_V2_t* v);
parser_error_t _readCompactAccountIndex_V2(parser_context_t* c, pd_CompactAccountIndex_V2_t* v);
parser_error_t _readCompactPerBill_V2(parser_context_t* c, pd_CompactPerBill_V2_t* v);
parser_error_t _readCurrencyId_V2(parser_context_t* c, pd_CurrencyId_V2_t* v);
parser_error_t _readDestroyWitness_V2(parser_context_t* c, pd_DestroyWitness_V2_t* v);
parser_error_t _readElectionScore_V2(parser_context_t* c, pd_ElectionScore_V2_t* v);
parser_error_t _readEraIndex_V2(parser_context_t* c, pd_EraIndex_V2_t* v);
parser_error_t _readEthereumBlockWithApprovalsEthereumId_V2(parser_context_t* c, pd_EthereumBlockWithApprovalsEthereumId_V2_t* v);
parser_error_t _readEthereumIdasRuntimeAppPublicSignature_V2(parser_context_t* c, pd_EthereumIdasRuntimeAppPublicSignature_V2_t* v);
parser_error_t _readH160_V2(parser_context_t* c, pd_H160_V2_t* v);
parser_error_t _readHeartbeatBlockNumber_V2(parser_context_t* c, pd_HeartbeatBlockNumber_V2_t* v);
parser_error_t _readIdentityFields_V2(parser_context_t* c, pd_IdentityFields_V2_t* v);
parser_error_t _readJudgementBalanceOfT_V2(parser_context_t* c, pd_JudgementBalanceOfT_V2_t* v);
parser_error_t _readKYCStatus_V2(parser_context_t* c, pd_KYCStatus_V2_t* v);
parser_error_t _readKeyOwnerProof_V2(parser_context_t* c, pd_KeyOwnerProof_V2_t* v);
parser_error_t _readKeyValue_V2(parser_context_t* c, pd_KeyValue_V2_t* v);
parser_error_t _readKey_V2(parser_context_t* c, pd_Key_V2_t* v);
parser_error_t _readKeys_V2(parser_context_t* c, pd_Keys_V2_t* v);
parser_error_t _readLookupasStaticLookupSource_V2(parser_context_t* c, pd_LookupasStaticLookupSource_V2_t* v);
parser_error_t _readMemberCount_V2(parser_context_t* c, pd_MemberCount_V2_t* v);
parser_error_t _readNextConfigDescriptor_V2(parser_context_t* c, pd_NextConfigDescriptor_V2_t* v);
parser_error_t _readOffenseReportAccountIdKeygenRound_V2(parser_context_t* c, pd_OffenseReportAccountIdKeygenRound_V2_t* v);
parser_error_t _readOpaqueCall_V2(parser_context_t* c, pd_OpaqueCall_V2_t* v);
parser_error_t _readOptionAccountId_V2(parser_context_t* c, pd_OptionAccountId_V2_t* v);
parser_error_t _readOptionAssetId_V2(parser_context_t* c, pd_OptionAssetId_V2_t* v);
parser_error_t _readOptionElectionScore_V2(parser_context_t* c, pd_OptionElectionScore_V2_t* v);
parser_error_t _readOptionPercent_V2(parser_context_t* c, pd_OptionPercent_V2_t* v);
parser_error_t _readOptionProxyType_V2(parser_context_t* c, pd_OptionProxyType_V2_t* v);
parser_error_t _readOptionTimepoint_V2(parser_context_t* c, pd_OptionTimepoint_V2_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V2(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V2_t* v);
parser_error_t _readPerbill_V2(parser_context_t* c, pd_Perbill_V2_t* v);
parser_error_t _readPercent_V2(parser_context_t* c, pd_Percent_V2_t* v);
parser_error_t _readProxyType_V2(parser_context_t* c, pd_ProxyType_V2_t* v);
parser_error_t _readPublic_V2(parser_context_t* c, pd_Public_V2_t* v);
parser_error_t _readRegistrarIndex_V2(parser_context_t* c, pd_RegistrarIndex_V2_t* v);
parser_error_t _readRenouncing_V2(parser_context_t* c, pd_Renouncing_V2_t* v);
parser_error_t _readRewardDestination_V2(parser_context_t* c, pd_RewardDestination_V2_t* v);
parser_error_t _readSignedTheaPayload_V2(parser_context_t* c, pd_SignedTheaPayload_V2_t* v);
parser_error_t _readSigningSessionPayloadTheaId_V2(parser_context_t* c, pd_SigningSessionPayloadTheaId_V2_t* v);
parser_error_t _readSolutionOrSnapshotSize_V2(parser_context_t* c, pd_SolutionOrSnapshotSize_V2_t* v);
parser_error_t _readSupportsAccountId_V2(parser_context_t* c, pd_SupportsAccountId_V2_t* v);
parser_error_t _readTasframe_systemConfigAccountId_V2(parser_context_t* c, pd_Tasframe_systemConfigAccountId_V2_t* v);
parser_error_t _readTheaIdasRuntimeAppPublicSignature_V2(parser_context_t* c, pd_TheaIdasRuntimeAppPublicSignature_V2_t* v);
parser_error_t _readTheaPayloadTheaIdKeygenRound_V2(parser_context_t* c, pd_TheaPayloadTheaIdKeygenRound_V2_t* v);
parser_error_t _readTheaPayloadTheaIdOfflineStageRound_V2(parser_context_t* c, pd_TheaPayloadTheaIdOfflineStageRound_V2_t* v);
parser_error_t _readTimepoint_V2(parser_context_t* c, pd_Timepoint_V2_t* v);
parser_error_t _readTupleAccountIdData_V2(parser_context_t* c, pd_TupleAccountIdData_V2_t* v);
parser_error_t _readValidatorPrefs_V2(parser_context_t* c, pd_ValidatorPrefs_V2_t* v);
parser_error_t _readVecAccountId_V2(parser_context_t* c, pd_VecAccountId_V2_t* v);
parser_error_t _readVecKeyValue_V2(parser_context_t* c, pd_VecKeyValue_V2_t* v);
parser_error_t _readVecKey_V2(parser_context_t* c, pd_VecKey_V2_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V2(parser_context_t* c, pd_VecLookupasStaticLookupSource_V2_t* v);
parser_error_t _readVecTupleAccountIdData_V2(parser_context_t* c, pd_VecTupleAccountIdData_V2_t* v);
parser_error_t _readVecVestingScheduleOf_V2(parser_context_t* c, pd_VecVestingScheduleOf_V2_t* v);
parser_error_t _readVestingScheduleOf_V2(parser_context_t* c, pd_VestingScheduleOf_V2_t* v);
parser_error_t _readWeight_V2(parser_context_t* c, pd_Weight_V2_t* v);
parser_error_t _readschedulePeriodBlockNumber_V2(parser_context_t* c, pd_schedulePeriodBlockNumber_V2_t* v);
parser_error_t _readschedulePriority_V2(parser_context_t* c, pd_schedulePriority_V2_t* v);
parser_error_t _readthea_primitivesValidatorSetId_V2(parser_context_t* c, pd_V2_thea_primitivesValidatorSetId_t* v);

// toString functions
parser_error_t _toStringAccountId_V2(
    const pd_AccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V2(
    const pd_AccountIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAmount_V2(
    const pd_Amount_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetId_V2(
    const pd_AssetId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V2(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorityIndex_V2(
    const pd_AuthorityIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V2(
    const pd_BoxEquivocationProofHashBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHeader_V2(
    const pd_BoxEquivocationProofHeader_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V2(
    const pd_BoxIdentityInfoMaxAdditionalFields_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V2(
    const pd_BoxPalletsOrigin_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxRawSolutionSolutionOfT_V2(
    const pd_BoxRawSolutionSolutionOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxUnprocessedEthereumBlock_V2(
    const pd_BoxUnprocessedEthereumBlock_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V2(
    const pd_CallHashOf_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCodeHashT_V2(
    const pd_CodeHashT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V2(
    const pd_CompactAccountIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V2(
    const pd_CompactPerBill_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCurrencyId_V2(
    const pd_CurrencyId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V2(
    const pd_DestroyWitness_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V2(
    const pd_ElectionScore_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V2(
    const pd_EraIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumBlockWithApprovalsEthereumId_V2(
    const pd_EthereumBlockWithApprovalsEthereumId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumIdasRuntimeAppPublicSignature_V2(
    const pd_EthereumIdasRuntimeAppPublicSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringH160_V2(
    const pd_H160_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeartbeatBlockNumber_V2(
    const pd_HeartbeatBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V2(
    const pd_IdentityFields_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V2(
    const pd_JudgementBalanceOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKYCStatus_V2(
    const pd_KYCStatus_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V2(
    const pd_KeyOwnerProof_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V2(
    const pd_KeyValue_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V2(
    const pd_Key_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V2(
    const pd_Keys_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V2(
    const pd_LookupasStaticLookupSource_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V2(
    const pd_MemberCount_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNextConfigDescriptor_V2(
    const pd_NextConfigDescriptor_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOffenseReportAccountIdKeygenRound_V2(
    const pd_OffenseReportAccountIdKeygenRound_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V2(
    const pd_OpaqueCall_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V2(
    const pd_OptionAccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAssetId_V2(
    const pd_OptionAssetId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionElectionScore_V2(
    const pd_OptionElectionScore_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPercent_V2(
    const pd_OptionPercent_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V2(
    const pd_OptionProxyType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V2(
    const pd_OptionTimepoint_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V2(
    const pd_OptionschedulePeriodBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V2(
    const pd_Perbill_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V2(
    const pd_Percent_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V2(
    const pd_ProxyType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPublic_V2(
    const pd_Public_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V2(
    const pd_RegistrarIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V2(
    const pd_Renouncing_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V2(
    const pd_RewardDestination_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignedTheaPayload_V2(
    const pd_SignedTheaPayload_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSigningSessionPayloadTheaId_V2(
    const pd_SigningSessionPayloadTheaId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSolutionOrSnapshotSize_V2(
    const pd_SolutionOrSnapshotSize_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSupportsAccountId_V2(
    const pd_SupportsAccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTasframe_systemConfigAccountId_V2(
    const pd_Tasframe_systemConfigAccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTheaIdasRuntimeAppPublicSignature_V2(
    const pd_TheaIdasRuntimeAppPublicSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTheaPayloadTheaIdKeygenRound_V2(
    const pd_TheaPayloadTheaIdKeygenRound_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTheaPayloadTheaIdOfflineStageRound_V2(
    const pd_TheaPayloadTheaIdOfflineStageRound_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V2(
    const pd_Timepoint_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V2(
    const pd_TupleAccountIdData_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V2(
    const pd_ValidatorPrefs_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V2(
    const pd_VecAccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V2(
    const pd_VecKeyValue_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V2(
    const pd_VecKey_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V2(
    const pd_VecLookupasStaticLookupSource_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V2(
    const pd_VecTupleAccountIdData_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVestingScheduleOf_V2(
    const pd_VecVestingScheduleOf_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingScheduleOf_V2(
    const pd_VestingScheduleOf_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V2(
    const pd_Weight_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V2(
    const pd_schedulePeriodBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V2(
    const pd_schedulePriority_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringthea_primitivesValidatorSetId_V2(
    const pd_V2_thea_primitivesValidatorSetId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
