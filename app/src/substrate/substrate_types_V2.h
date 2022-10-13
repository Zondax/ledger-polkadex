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

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V2_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V2_t;

typedef struct {
    uint8_t value;
} pd_Vote_V2_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_V2_t;

typedef struct {
    pd_Vote_V2_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_V2_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_V2_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V2_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V2_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V2_t id;
        pd_CompactAccountIndex_V2_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V2_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V2_t;

typedef struct {
    uint8_t value;
} pd_Percent_V2_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V2_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V2_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_VestingScheduleOf_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePeriodBlockNumber_V2_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_V2_t voteStandard;
        pd_AccountVoteSplit_V2_t voteSplit;
    };
} pd_AccountVote_V2_t;

typedef struct {
    uint8_t value;
    pd_Balance_t set;
} pd_ConfigOpBalanceOfT_V2_t;

typedef struct {
    uint8_t value;
    pd_Perbill_V2_t set;
} pd_ConfigOpPerbill_V2_t;

typedef struct {
    uint8_t value;
    pd_Percent_V2_t set;
} pd_ConfigOpPercent_V2_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V2_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V2_t contained;
} pd_OptionTimepoint_V2_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V2_t accountId;
} pd_RewardDestination_V2_t;

typedef struct {
    pd_CompactPerBill_V2_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupasStaticLookupSource_V2_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AuthorityIdasRuntimeAppPublicSignature_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxCallOrHashOfT_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxEquivocationProofHashBlockNumber_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxEquivocationProofHeader_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxIdentityInfoMaxAdditionalFields_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxPalletsOrigin_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxRawSolutionSolutionOfT_V2_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V2_t;

typedef struct {
    uint8_t value;
    uint32_t set;
} pd_ConfigOpu32_V2_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V2_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_HeartbeatBlockNumber_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_JudgementBalanceOfT_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V2_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V2_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_NextConfigDescriptor_V2_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V2_t contained;
} pd_OptionAccountId_V2_t;

typedef struct {
    uint8_t some;
    pd_ElectionScore_V2_t contained;
} pd_OptionElectionScore_V2_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V2_t contained;
} pd_OptionProxyType_V2_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_V2_t contained;
} pd_OptionReferendumIndex_V2_t;

typedef struct {
    uint8_t some;
    pd_schedulePeriodBlockNumber_V2_t contained;
} pd_OptionschedulePeriodBlockNumber_V2_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Renouncing_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SolutionOrSnapshotSize_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SupportsAccountId_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecVestingScheduleOf_V2_t;

typedef struct {
    uint64_t value;
} pd_Weight_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_schedulePriority_V2_t;

#ifdef __cplusplus
}
#endif
