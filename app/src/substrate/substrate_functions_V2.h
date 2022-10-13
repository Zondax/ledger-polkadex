/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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
parser_error_t _readCallHashOf_V2(parser_context_t* c, pd_CallHashOf_V2_t* v);
parser_error_t _readCompactAccountIndex_V2(parser_context_t* c, pd_CompactAccountIndex_V2_t* v);
parser_error_t _readCompactPerBill_V2(parser_context_t* c, pd_CompactPerBill_V2_t* v);
parser_error_t _readConfigOpBalanceOfT_V2(parser_context_t* c, pd_ConfigOpBalanceOfT_V2_t* v);
parser_error_t _readConfigOpPerbill_V2(parser_context_t* c, pd_ConfigOpPerbill_V2_t* v);
parser_error_t _readConfigOpPercent_V2(parser_context_t* c, pd_ConfigOpPercent_V2_t* v);
parser_error_t _readConfigOpu32_V2(parser_context_t* c, pd_ConfigOpu32_V2_t* v);
parser_error_t _readEraIndex_V2(parser_context_t* c, pd_EraIndex_V2_t* v);
parser_error_t _readKeys_V2(parser_context_t* c, pd_Keys_V2_t* v);
parser_error_t _readLookupasStaticLookupSource_V2(parser_context_t* c, pd_LookupasStaticLookupSource_V2_t* v);
parser_error_t _readMemberCount_V2(parser_context_t* c, pd_MemberCount_V2_t* v);
parser_error_t _readOpaqueCall_V2(parser_context_t* c, pd_OpaqueCall_V2_t* v);
parser_error_t _readOptionAccountId_V2(parser_context_t* c, pd_OptionAccountId_V2_t* v);
parser_error_t _readOptionProxyType_V2(parser_context_t* c, pd_OptionProxyType_V2_t* v);
parser_error_t _readOptionTimepoint_V2(parser_context_t* c, pd_OptionTimepoint_V2_t* v);
parser_error_t _readPerbill_V2(parser_context_t* c, pd_Perbill_V2_t* v);
parser_error_t _readPercent_V2(parser_context_t* c, pd_Percent_V2_t* v);
parser_error_t _readProxyType_V2(parser_context_t* c, pd_ProxyType_V2_t* v);
parser_error_t _readRegistrarIndex_V2(parser_context_t* c, pd_RegistrarIndex_V2_t* v);
parser_error_t _readRewardDestination_V2(parser_context_t* c, pd_RewardDestination_V2_t* v);
parser_error_t _readTimepoint_V2(parser_context_t* c, pd_Timepoint_V2_t* v);
parser_error_t _readValidatorPrefs_V2(parser_context_t* c, pd_ValidatorPrefs_V2_t* v);
parser_error_t _readVecAccountId_V2(parser_context_t* c, pd_VecAccountId_V2_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V2(parser_context_t* c, pd_VecLookupasStaticLookupSource_V2_t* v);
parser_error_t _readWeight_V2(parser_context_t* c, pd_Weight_V2_t* v);

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

parser_error_t _toStringCallHashOf_V2(
    const pd_CallHashOf_V2_t* v,
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

parser_error_t _toStringConfigOpBalanceOfT_V2(
    const pd_ConfigOpBalanceOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPerbill_V2(
    const pd_ConfigOpPerbill_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPercent_V2(
    const pd_ConfigOpPercent_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpu32_V2(
    const pd_ConfigOpu32_V2_t* v,
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

parser_error_t _toStringRegistrarIndex_V2(
    const pd_RegistrarIndex_V2_t* v,
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

parser_error_t _toStringTimepoint_V2(
    const pd_Timepoint_V2_t* v,
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

parser_error_t _toStringVecLookupasStaticLookupSource_V2(
    const pd_VecLookupasStaticLookupSource_V2_t* v,
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

#ifdef __cplusplus
}
#endif
