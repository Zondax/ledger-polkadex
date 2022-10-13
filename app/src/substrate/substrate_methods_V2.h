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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V2.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V2 0
#define PD_CALL_UTILITY_V2 1
#define PD_CALL_TIMESTAMP_V2 3
#define PD_CALL_INDICES_V2 5
#define PD_CALL_BALANCES_V2 6
#define PD_CALL_STAKING_V2 9
#define PD_CALL_SESSION_V2 10
#define PD_CALL_COUNCIL_V2 11
#define PD_CALL_TECHNICALCOMMITTEE_V2 12
#define PD_CALL_ELECTIONS_V2 13
#define PD_CALL_TECHNICALMEMBERSHIP_V2 14
#define PD_CALL_GRANDPA_V2 15
#define PD_CALL_TREASURY_V2 16
#define PD_CALL_SUDO_V2 17
#define PD_CALL_IDENTITY_V2 22
#define PD_CALL_RECOVERY_V2 23
#define PD_CALL_PROXY_V2 25
#define PD_CALL_MULTISIG_V2 26
#define PD_CALL_BOUNTIES_V2 27

#define PD_CALL_UTILITY_BATCH_V2 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V2_t;

#define PD_CALL_UTILITY_BATCH_ALL_V2 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V2_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V2 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V2_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V2 4
typedef struct {
    pd_LookupasStaticLookupSource_V2_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V2_t;

#define PD_CALL_STAKING_BOND_V2 0
typedef struct {
    pd_LookupasStaticLookupSource_V2_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_V2_t payee;
} pd_staking_bond_V2_t;

#define PD_CALL_STAKING_BOND_EXTRA_V2 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V2_t;

#define PD_CALL_STAKING_UNBOND_V2 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V2_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V2 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V2_t;

#define PD_CALL_STAKING_VALIDATE_V2 4
typedef struct {
    pd_ValidatorPrefs_V2_t prefs;
} pd_staking_validate_V2_t;

#define PD_CALL_STAKING_NOMINATE_V2 5
typedef struct {
    pd_VecLookupasStaticLookupSource_V2_t targets;
} pd_staking_nominate_V2_t;

#define PD_CALL_STAKING_CHILL_V2 6
typedef struct {
} pd_staking_chill_V2_t;

#define PD_CALL_STAKING_SET_PAYEE_V2 7
typedef struct {
    pd_RewardDestination_V2_t payee;
} pd_staking_set_payee_V2_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V2 8
typedef struct {
    pd_LookupasStaticLookupSource_V2_t controller;
} pd_staking_set_controller_V2_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V2 18
typedef struct {
    pd_AccountId_V2_t validator_stash;
    pd_EraIndex_V2_t era;
} pd_staking_payout_stakers_V2_t;

#define PD_CALL_STAKING_REBOND_V2 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V2_t;

#define PD_CALL_SESSION_SET_KEYS_V2 0
typedef struct {
    pd_Keys_V2_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V2_t;

#define PD_CALL_SESSION_PURGE_KEYS_V2 1
typedef struct {
} pd_session_purge_keys_V2_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V2 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V2_t;

#define PD_CALL_INDICES_CLAIM_V2 0
typedef struct {
    pd_AccountIndex_V2_t index;
} pd_indices_claim_V2_t;

#define PD_CALL_INDICES_TRANSFER_V2 1
typedef struct {
    pd_AccountId_V2_t new_;
    pd_AccountIndex_V2_t index;
} pd_indices_transfer_V2_t;

#define PD_CALL_INDICES_FREE_V2 2
typedef struct {
    pd_AccountIndex_V2_t index;
} pd_indices_free_V2_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V2 3
typedef struct {
    pd_AccountId_V2_t new_;
    pd_AccountIndex_V2_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V2_t;

#define PD_CALL_INDICES_FREEZE_V2 4
typedef struct {
    pd_AccountIndex_V2_t index;
} pd_indices_freeze_V2_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V2 5
typedef struct {
    pd_LookupasStaticLookupSource_V2_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V2_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V2 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V2_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V2 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V2_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V2 12
typedef struct {
} pd_staking_force_no_eras_V2_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V2 13
typedef struct {
} pd_staking_force_new_era_V2_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V2 14
typedef struct {
    pd_VecAccountId_V2_t invulnerables;
} pd_staking_set_invulnerables_V2_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V2 15
typedef struct {
    pd_AccountId_V2_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V2_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V2 16
typedef struct {
} pd_staking_force_new_era_always_V2_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V2 17
typedef struct {
    pd_EraIndex_V2_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V2_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V2 20
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t era_items_deleted;
} pd_staking_set_history_depth_V2_t;

#define PD_CALL_STAKING_REAP_STASH_V2 21
typedef struct {
    pd_AccountId_V2_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V2_t;

#define PD_CALL_STAKING_KICK_V2 22
typedef struct {
    pd_VecLookupasStaticLookupSource_V2_t who;
} pd_staking_kick_V2_t;

#define PD_CALL_STAKING_SET_STAKING_CONFIGS_V2 23
typedef struct {
    pd_ConfigOpBalanceOfT_V2_t min_nominator_bond;
    pd_ConfigOpBalanceOfT_V2_t min_validator_bond;
    pd_ConfigOpu32_V2_t max_nominator_count;
    pd_ConfigOpu32_V2_t max_validator_count;
    pd_ConfigOpPercent_V2_t chill_threshold;
    pd_ConfigOpPerbill_V2_t min_commission;
} pd_staking_set_staking_configs_V2_t;

#define PD_CALL_STAKING_CHILL_OTHER_V2 24
typedef struct {
    pd_AccountId_V2_t controller;
} pd_staking_chill_other_V2_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V2 25
typedef struct {
    pd_AccountId_V2_t validator_stash;
} pd_staking_force_apply_min_commission_V2_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V2 0
typedef struct {
    pd_VecAccountId_V2_t new_members;
    pd_OptionAccountId_V2_t prime;
    pd_MemberCount_V2_t old_count;
} pd_council_set_members_V2_t;

#define PD_CALL_COUNCIL_EXECUTE_V2 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V2_t;

#define PD_CALL_COUNCIL_PROPOSE_V2 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V2_t;

#define PD_CALL_COUNCIL_VOTE_V2 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V2_t;

#define PD_CALL_COUNCIL_CLOSE_V2 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V2_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V2 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V2 0
typedef struct {
    pd_VecAccountId_V2_t new_members;
    pd_OptionAccountId_V2_t prime;
    pd_MemberCount_V2_t old_count;
} pd_technicalcommittee_set_members_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V2 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V2 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V2 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V2 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V2 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V2_t;

#define PD_CALL_ELECTIONS_VOTE_V2 0
typedef struct {
    pd_VecAccountId_V2_t votes;
    pd_Compactu128_t amount;
} pd_elections_vote_V2_t;

#define PD_CALL_ELECTIONS_REMOVE_VOTER_V2 1
typedef struct {
} pd_elections_remove_voter_V2_t;

#define PD_CALL_ELECTIONS_SUBMIT_CANDIDACY_V2 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_elections_submit_candidacy_V2_t;

#define PD_CALL_ELECTIONS_REMOVE_MEMBER_V2 4
typedef struct {
    pd_LookupasStaticLookupSource_V2_t who;
    pd_bool_t slash_bond;
    pd_bool_t rerun_election;
} pd_elections_remove_member_V2_t;

#define PD_CALL_ELECTIONS_CLEAN_DEFUNCT_VOTERS_V2 5
typedef struct {
    pd_u32_t num_voters;
    pd_u32_t num_defunct;
} pd_elections_clean_defunct_voters_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V2 0
typedef struct {
    pd_AccountId_V2_t who;
} pd_technicalmembership_add_member_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V2 1
typedef struct {
    pd_AccountId_V2_t who;
} pd_technicalmembership_remove_member_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V2 2
typedef struct {
    pd_AccountId_V2_t remove;
    pd_AccountId_V2_t add;
} pd_technicalmembership_swap_member_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V2 3
typedef struct {
    pd_VecAccountId_V2_t members;
} pd_technicalmembership_reset_members_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V2 4
typedef struct {
    pd_AccountId_V2_t new_;
} pd_technicalmembership_change_key_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V2 5
typedef struct {
    pd_AccountId_V2_t who;
} pd_technicalmembership_set_prime_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V2 6
typedef struct {
} pd_technicalmembership_clear_prime_V2_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V2 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V2_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V2 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V2_t beneficiary;
} pd_treasury_propose_spend_V2_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V2 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V2_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V2 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V2_t;

#define PD_CALL_TREASURY_SPEND_V2 3
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V2_t beneficiary;
} pd_treasury_spend_V2_t;

#define PD_CALL_TREASURY_REMOVE_APPROVAL_V2 4
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_remove_approval_V2_t;

#define PD_CALL_SUDO_SUDO_V2 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V2_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V2 1
typedef struct {
    pd_Call_t call;
    pd_Weight_V2_t weight;
} pd_sudo_sudo_unchecked_weight_V2_t;

#define PD_CALL_SUDO_SET_KEY_V2 2
typedef struct {
    pd_LookupasStaticLookupSource_V2_t new_;
} pd_sudo_set_key_V2_t;

#define PD_CALL_SUDO_SUDO_AS_V2 3
typedef struct {
    pd_LookupasStaticLookupSource_V2_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V2_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V2 0
typedef struct {
    pd_AccountId_V2_t account;
} pd_identity_add_registrar_V2_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V2 3
typedef struct {
} pd_identity_clear_identity_V2_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V2 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V2_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V2 5
typedef struct {
    pd_RegistrarIndex_V2_t reg_index;
} pd_identity_cancel_request_V2_t;

#define PD_CALL_IDENTITY_SET_FEE_V2 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V2_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V2 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V2_t new_;
} pd_identity_set_account_id_V2_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V2 10
typedef struct {
    pd_LookupasStaticLookupSource_V2_t target;
} pd_identity_kill_identity_V2_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V2 13
typedef struct {
    pd_LookupasStaticLookupSource_V2_t sub;
} pd_identity_remove_sub_V2_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V2 14
typedef struct {
} pd_identity_quit_sub_V2_t;

#define PD_CALL_RECOVERY_SET_RECOVERED_V2 1
typedef struct {
    pd_AccountId_V2_t lost;
    pd_AccountId_V2_t rescuer;
} pd_recovery_set_recovered_V2_t;

#define PD_CALL_RECOVERY_INITIATE_RECOVERY_V2 3
typedef struct {
    pd_AccountId_V2_t account;
} pd_recovery_initiate_recovery_V2_t;

#define PD_CALL_RECOVERY_VOUCH_RECOVERY_V2 4
typedef struct {
    pd_AccountId_V2_t lost;
    pd_AccountId_V2_t rescuer;
} pd_recovery_vouch_recovery_V2_t;

#define PD_CALL_RECOVERY_CLAIM_RECOVERY_V2 5
typedef struct {
    pd_AccountId_V2_t account;
} pd_recovery_claim_recovery_V2_t;

#define PD_CALL_RECOVERY_CLOSE_RECOVERY_V2 6
typedef struct {
    pd_AccountId_V2_t rescuer;
} pd_recovery_close_recovery_V2_t;

#define PD_CALL_RECOVERY_REMOVE_RECOVERY_V2 7
typedef struct {
} pd_recovery_remove_recovery_V2_t;

#define PD_CALL_RECOVERY_CANCEL_RECOVERED_V2 8
typedef struct {
    pd_AccountId_V2_t account;
} pd_recovery_cancel_recovered_V2_t;

#define PD_CALL_PROXY_ADD_PROXY_V2 1
typedef struct {
    pd_AccountId_V2_t delegate;
    pd_ProxyType_V2_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V2_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V2 2
typedef struct {
    pd_AccountId_V2_t delegate;
    pd_ProxyType_V2_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V2_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V2 3
typedef struct {
} pd_proxy_remove_proxies_V2_t;

#define PD_CALL_PROXY_ANONYMOUS_V2 4
typedef struct {
    pd_ProxyType_V2_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V2_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V2 5
typedef struct {
    pd_AccountId_V2_t spawner;
    pd_ProxyType_V2_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V2_t;

#define PD_CALL_PROXY_ANNOUNCE_V2 6
typedef struct {
    pd_AccountId_V2_t real;
    pd_CallHashOf_V2_t call_hash;
} pd_proxy_announce_V2_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V2 7
typedef struct {
    pd_AccountId_V2_t real;
    pd_CallHashOf_V2_t call_hash;
} pd_proxy_remove_announcement_V2_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V2 8
typedef struct {
    pd_AccountId_V2_t delegate;
    pd_CallHashOf_V2_t call_hash;
} pd_proxy_reject_announcement_V2_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V2 9
typedef struct {
    pd_AccountId_V2_t delegate;
    pd_AccountId_V2_t real;
    pd_OptionProxyType_V2_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V2_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V2 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V2_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V2 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V2_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V2 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V2_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V2_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V2 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V2_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V2 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V2_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V2 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V2_t beneficiary;
} pd_bounties_award_bounty_V2_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V2 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V2_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V2 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V2_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V2 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V2_t;

#endif

typedef union {
    pd_utility_batch_V2_t utility_batch_V2;
    pd_utility_batch_all_V2_t utility_batch_all_V2;
    pd_utility_force_batch_V2_t utility_force_batch_V2;
    pd_balances_transfer_all_V2_t balances_transfer_all_V2;
    pd_staking_bond_V2_t staking_bond_V2;
    pd_staking_bond_extra_V2_t staking_bond_extra_V2;
    pd_staking_unbond_V2_t staking_unbond_V2;
    pd_staking_withdraw_unbonded_V2_t staking_withdraw_unbonded_V2;
    pd_staking_validate_V2_t staking_validate_V2;
    pd_staking_nominate_V2_t staking_nominate_V2;
    pd_staking_chill_V2_t staking_chill_V2;
    pd_staking_set_payee_V2_t staking_set_payee_V2;
    pd_staking_set_controller_V2_t staking_set_controller_V2;
    pd_staking_payout_stakers_V2_t staking_payout_stakers_V2;
    pd_staking_rebond_V2_t staking_rebond_V2;
    pd_session_set_keys_V2_t session_set_keys_V2;
    pd_session_purge_keys_V2_t session_purge_keys_V2;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V2_t timestamp_set_V2;
    pd_indices_claim_V2_t indices_claim_V2;
    pd_indices_transfer_V2_t indices_transfer_V2;
    pd_indices_free_V2_t indices_free_V2;
    pd_indices_force_transfer_V2_t indices_force_transfer_V2;
    pd_indices_freeze_V2_t indices_freeze_V2;
    pd_balances_force_unreserve_V2_t balances_force_unreserve_V2;
    pd_staking_set_validator_count_V2_t staking_set_validator_count_V2;
    pd_staking_increase_validator_count_V2_t staking_increase_validator_count_V2;
    pd_staking_force_no_eras_V2_t staking_force_no_eras_V2;
    pd_staking_force_new_era_V2_t staking_force_new_era_V2;
    pd_staking_set_invulnerables_V2_t staking_set_invulnerables_V2;
    pd_staking_force_unstake_V2_t staking_force_unstake_V2;
    pd_staking_force_new_era_always_V2_t staking_force_new_era_always_V2;
    pd_staking_cancel_deferred_slash_V2_t staking_cancel_deferred_slash_V2;
    pd_staking_set_history_depth_V2_t staking_set_history_depth_V2;
    pd_staking_reap_stash_V2_t staking_reap_stash_V2;
    pd_staking_kick_V2_t staking_kick_V2;
    pd_staking_set_staking_configs_V2_t staking_set_staking_configs_V2;
    pd_staking_chill_other_V2_t staking_chill_other_V2;
    pd_staking_force_apply_min_commission_V2_t staking_force_apply_min_commission_V2;
    pd_council_set_members_V2_t council_set_members_V2;
    pd_council_execute_V2_t council_execute_V2;
    pd_council_propose_V2_t council_propose_V2;
    pd_council_vote_V2_t council_vote_V2;
    pd_council_close_V2_t council_close_V2;
    pd_council_disapprove_proposal_V2_t council_disapprove_proposal_V2;
    pd_technicalcommittee_set_members_V2_t technicalcommittee_set_members_V2;
    pd_technicalcommittee_execute_V2_t technicalcommittee_execute_V2;
    pd_technicalcommittee_propose_V2_t technicalcommittee_propose_V2;
    pd_technicalcommittee_vote_V2_t technicalcommittee_vote_V2;
    pd_technicalcommittee_close_V2_t technicalcommittee_close_V2;
    pd_technicalcommittee_disapprove_proposal_V2_t technicalcommittee_disapprove_proposal_V2;
    pd_elections_vote_V2_t elections_vote_V2;
    pd_elections_remove_voter_V2_t elections_remove_voter_V2;
    pd_elections_submit_candidacy_V2_t elections_submit_candidacy_V2;
    pd_elections_remove_member_V2_t elections_remove_member_V2;
    pd_elections_clean_defunct_voters_V2_t elections_clean_defunct_voters_V2;
    pd_technicalmembership_add_member_V2_t technicalmembership_add_member_V2;
    pd_technicalmembership_remove_member_V2_t technicalmembership_remove_member_V2;
    pd_technicalmembership_swap_member_V2_t technicalmembership_swap_member_V2;
    pd_technicalmembership_reset_members_V2_t technicalmembership_reset_members_V2;
    pd_technicalmembership_change_key_V2_t technicalmembership_change_key_V2;
    pd_technicalmembership_set_prime_V2_t technicalmembership_set_prime_V2;
    pd_technicalmembership_clear_prime_V2_t technicalmembership_clear_prime_V2;
    pd_grandpa_note_stalled_V2_t grandpa_note_stalled_V2;
    pd_treasury_propose_spend_V2_t treasury_propose_spend_V2;
    pd_treasury_reject_proposal_V2_t treasury_reject_proposal_V2;
    pd_treasury_approve_proposal_V2_t treasury_approve_proposal_V2;
    pd_treasury_spend_V2_t treasury_spend_V2;
    pd_treasury_remove_approval_V2_t treasury_remove_approval_V2;
    pd_sudo_sudo_V2_t sudo_sudo_V2;
    pd_sudo_sudo_unchecked_weight_V2_t sudo_sudo_unchecked_weight_V2;
    pd_sudo_set_key_V2_t sudo_set_key_V2;
    pd_sudo_sudo_as_V2_t sudo_sudo_as_V2;
    pd_identity_add_registrar_V2_t identity_add_registrar_V2;
    pd_identity_clear_identity_V2_t identity_clear_identity_V2;
    pd_identity_request_judgement_V2_t identity_request_judgement_V2;
    pd_identity_cancel_request_V2_t identity_cancel_request_V2;
    pd_identity_set_fee_V2_t identity_set_fee_V2;
    pd_identity_set_account_id_V2_t identity_set_account_id_V2;
    pd_identity_kill_identity_V2_t identity_kill_identity_V2;
    pd_identity_remove_sub_V2_t identity_remove_sub_V2;
    pd_identity_quit_sub_V2_t identity_quit_sub_V2;
    pd_recovery_set_recovered_V2_t recovery_set_recovered_V2;
    pd_recovery_initiate_recovery_V2_t recovery_initiate_recovery_V2;
    pd_recovery_vouch_recovery_V2_t recovery_vouch_recovery_V2;
    pd_recovery_claim_recovery_V2_t recovery_claim_recovery_V2;
    pd_recovery_close_recovery_V2_t recovery_close_recovery_V2;
    pd_recovery_remove_recovery_V2_t recovery_remove_recovery_V2;
    pd_recovery_cancel_recovered_V2_t recovery_cancel_recovered_V2;
    pd_proxy_add_proxy_V2_t proxy_add_proxy_V2;
    pd_proxy_remove_proxy_V2_t proxy_remove_proxy_V2;
    pd_proxy_remove_proxies_V2_t proxy_remove_proxies_V2;
    pd_proxy_anonymous_V2_t proxy_anonymous_V2;
    pd_proxy_kill_anonymous_V2_t proxy_kill_anonymous_V2;
    pd_proxy_announce_V2_t proxy_announce_V2;
    pd_proxy_remove_announcement_V2_t proxy_remove_announcement_V2;
    pd_proxy_reject_announcement_V2_t proxy_reject_announcement_V2;
    pd_proxy_proxy_announced_V2_t proxy_proxy_announced_V2;
    pd_bounties_propose_bounty_V2_t bounties_propose_bounty_V2;
    pd_bounties_approve_bounty_V2_t bounties_approve_bounty_V2;
    pd_bounties_propose_curator_V2_t bounties_propose_curator_V2;
    pd_bounties_unassign_curator_V2_t bounties_unassign_curator_V2;
    pd_bounties_accept_curator_V2_t bounties_accept_curator_V2;
    pd_bounties_award_bounty_V2_t bounties_award_bounty_V2;
    pd_bounties_claim_bounty_V2_t bounties_claim_bounty_V2;
    pd_bounties_close_bounty_V2_t bounties_close_bounty_V2;
    pd_bounties_extend_bounty_expiry_V2_t bounties_extend_bounty_expiry_V2;
#endif
} pd_MethodBasic_V2_t;

#define PD_CALL_BALANCES_TRANSFER_V2 0
typedef struct {
    pd_LookupasStaticLookupSource_V2_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V2_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V2 2
typedef struct {
    pd_LookupasStaticLookupSource_V2_t source;
    pd_LookupasStaticLookupSource_V2_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V2_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V2 3
typedef struct {
    pd_LookupasStaticLookupSource_V2_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V2_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V2 0
typedef struct {
    pd_Perbill_V2_t ratio;
} pd_system_fill_block_V2_t;

#define PD_CALL_SYSTEM_REMARK_V2 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V2_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V2 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V2_t;

#define PD_CALL_SYSTEM_SET_CODE_V2 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V2_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V2 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V2_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V2 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V2_t;

#define PD_CALL_BALANCES_SET_BALANCE_V2 1
typedef struct {
    pd_LookupasStaticLookupSource_V2_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V2_t;

#define PD_CALL_PROXY_PROXY_V2 0
typedef struct {
    pd_AccountId_V2_t real;
    pd_OptionProxyType_V2_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V2_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V2 0
typedef struct {
    pd_VecAccountId_V2_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V2_t;

#define PD_CALL_MULTISIG_AS_MULTI_V2 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V2_t other_signatories;
    pd_OptionTimepoint_V2_t maybe_timepoint;
    pd_OpaqueCall_V2_t call;
    pd_bool_t store_call;
    pd_Weight_V2_t max_weight;
} pd_multisig_as_multi_V2_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V2 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V2_t other_signatories;
    pd_OptionTimepoint_V2_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V2_t max_weight;
} pd_multisig_approve_as_multi_V2_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V2 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V2_t other_signatories;
    pd_Timepoint_V2_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V2_t;

#endif

typedef union {
    pd_balances_transfer_V2_t balances_transfer_V2;
    pd_balances_force_transfer_V2_t balances_force_transfer_V2;
    pd_balances_transfer_keep_alive_V2_t balances_transfer_keep_alive_V2;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V2_t system_fill_block_V2;
    pd_system_remark_V2_t system_remark_V2;
    pd_system_set_heap_pages_V2_t system_set_heap_pages_V2;
    pd_system_set_code_V2_t system_set_code_V2;
    pd_system_set_code_without_checks_V2_t system_set_code_without_checks_V2;
    pd_system_remark_with_event_V2_t system_remark_with_event_V2;
    pd_balances_set_balance_V2_t balances_set_balance_V2;
    pd_proxy_proxy_V2_t proxy_proxy_V2;
    pd_multisig_as_multi_threshold_1_V2_t multisig_as_multi_threshold_1_V2;
    pd_multisig_as_multi_V2_t multisig_as_multi_V2;
    pd_multisig_approve_as_multi_V2_t multisig_approve_as_multi_V2;
    pd_multisig_cancel_as_multi_V2_t multisig_cancel_as_multi_V2;
#endif
} pd_MethodNested_V2_t;

typedef union {
    pd_MethodBasic_V2_t basic;
    pd_MethodNested_V2_t nested;
} pd_Method_V2_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
