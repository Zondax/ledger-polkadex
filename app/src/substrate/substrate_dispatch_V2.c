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

#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_utility_batch_V2(
    parser_context_t* c, pd_utility_batch_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V2(
    parser_context_t* c, pd_utility_batch_all_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V2(
    parser_context_t* c, pd_balances_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V2(
    parser_context_t* c, pd_balances_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V2(
    parser_context_t* c, pd_balances_transfer_keep_alive_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V2(
    parser_context_t* c, pd_balances_transfer_all_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V2(
    parser_context_t* c, pd_staking_bond_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->controller))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V2(
    parser_context_t* c, pd_staking_bond_extra_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V2(
    parser_context_t* c, pd_staking_unbond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V2(
    parser_context_t* c, pd_staking_withdraw_unbonded_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V2(
    parser_context_t* c, pd_staking_validate_V2_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V2(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V2(
    parser_context_t* c, pd_staking_nominate_V2_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V2(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V2(
    parser_context_t* c, pd_staking_chill_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V2(
    parser_context_t* c, pd_staking_set_payee_V2_t* m)
{
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V2(
    parser_context_t* c, pd_staking_set_controller_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V2(
    parser_context_t* c, pd_staking_payout_stakers_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V2(
    parser_context_t* c, pd_staking_rebond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V2(
    parser_context_t* c, pd_session_set_keys_V2_t* m)
{
    CHECK_ERROR(_readKeys_V2(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V2(
    parser_context_t* c, pd_session_purge_keys_V2_t* m)
{
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V2(
    parser_context_t* c, pd_system_fill_block_V2_t* m)
{
    CHECK_ERROR(_readPerbill_V2(c, &m->ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V2(
    parser_context_t* c, pd_system_remark_V2_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V2(
    parser_context_t* c, pd_system_set_heap_pages_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V2(
    parser_context_t* c, pd_system_set_code_V2_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V2(
    parser_context_t* c, pd_system_set_code_without_checks_V2_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V2(
    parser_context_t* c, pd_system_remark_with_event_V2_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V2(
    parser_context_t* c, pd_timestamp_set_V2_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V2(
    parser_context_t* c, pd_indices_claim_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V2(
    parser_context_t* c, pd_indices_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V2(
    parser_context_t* c, pd_indices_free_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V2(
    parser_context_t* c, pd_indices_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V2(
    parser_context_t* c, pd_indices_freeze_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V2(
    parser_context_t* c, pd_balances_set_balance_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V2(
    parser_context_t* c, pd_balances_force_unreserve_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V2(
    parser_context_t* c, pd_staking_set_validator_count_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V2(
    parser_context_t* c, pd_staking_increase_validator_count_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V2(
    parser_context_t* c, pd_staking_force_no_eras_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V2(
    parser_context_t* c, pd_staking_force_new_era_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V2(
    parser_context_t* c, pd_staking_set_invulnerables_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V2(
    parser_context_t* c, pd_staking_force_unstake_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V2(
    parser_context_t* c, pd_staking_force_new_era_always_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V2(
    parser_context_t* c, pd_staking_set_history_depth_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V2(
    parser_context_t* c, pd_staking_reap_stash_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V2(
    parser_context_t* c, pd_staking_kick_V2_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V2(
    parser_context_t* c, pd_staking_chill_other_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V2(
    parser_context_t* c, pd_council_set_members_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V2(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V2(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V2(
    parser_context_t* c, pd_council_execute_V2_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V2(
    parser_context_t* c, pd_council_propose_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V2(
    parser_context_t* c, pd_council_vote_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V2(
    parser_context_t* c, pd_council_close_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V2(
    parser_context_t* c, pd_council_disapprove_proposal_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V2(
    parser_context_t* c, pd_technicalcommittee_set_members_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V2(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V2(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V2(
    parser_context_t* c, pd_technicalcommittee_execute_V2_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V2(
    parser_context_t* c, pd_technicalcommittee_propose_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V2(
    parser_context_t* c, pd_technicalcommittee_vote_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V2(
    parser_context_t* c, pd_technicalcommittee_close_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V2(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_vote_V2(
    parser_context_t* c, pd_elections_vote_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->votes))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_remove_voter_V2(
    parser_context_t* c, pd_elections_remove_voter_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_submit_candidacy_V2(
    parser_context_t* c, pd_elections_submit_candidacy_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_remove_member_V2(
    parser_context_t* c, pd_elections_remove_member_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->has_replacement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_clean_defunct_voters_V2(
    parser_context_t* c, pd_elections_clean_defunct_voters_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_voters))
    CHECK_ERROR(_readu32(c, &m->num_defunct))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member_V2(
    parser_context_t* c, pd_technicalmembership_add_member_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V2(
    parser_context_t* c, pd_technicalmembership_remove_member_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V2(
    parser_context_t* c, pd_technicalmembership_swap_member_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->remove))
    CHECK_ERROR(_readAccountId_V2(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V2(
    parser_context_t* c, pd_technicalmembership_reset_members_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V2(
    parser_context_t* c, pd_technicalmembership_change_key_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V2(
    parser_context_t* c, pd_technicalmembership_set_prime_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V2(
    parser_context_t* c, pd_technicalmembership_clear_prime_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V2(
    parser_context_t* c, pd_grandpa_note_stalled_V2_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V2(
    parser_context_t* c, pd_treasury_propose_spend_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V2(
    parser_context_t* c, pd_treasury_reject_proposal_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V2(
    parser_context_t* c, pd_treasury_approve_proposal_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V2(
    parser_context_t* c, pd_sudo_sudo_V2_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V2(
    parser_context_t* c, pd_sudo_sudo_unchecked_weight_V2_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight_V2(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V2(
    parser_context_t* c, pd_sudo_set_key_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V2(
    parser_context_t* c, pd_sudo_sudo_as_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V2(
    parser_context_t* c, pd_identity_add_registrar_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V2(
    parser_context_t* c, pd_identity_clear_identity_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V2(
    parser_context_t* c, pd_identity_request_judgement_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V2(
    parser_context_t* c, pd_identity_cancel_request_V2_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V2(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V2(
    parser_context_t* c, pd_identity_set_fee_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V2(
    parser_context_t* c, pd_identity_set_account_id_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V2(
    parser_context_t* c, pd_identity_kill_identity_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V2(
    parser_context_t* c, pd_identity_remove_sub_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V2(
    parser_context_t* c, pd_identity_quit_sub_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_set_recovered_V2(
    parser_context_t* c, pd_recovery_set_recovered_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->lost))
    CHECK_ERROR(_readAccountId_V2(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_initiate_recovery_V2(
    parser_context_t* c, pd_recovery_initiate_recovery_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_vouch_recovery_V2(
    parser_context_t* c, pd_recovery_vouch_recovery_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->lost))
    CHECK_ERROR(_readAccountId_V2(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_claim_recovery_V2(
    parser_context_t* c, pd_recovery_claim_recovery_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_close_recovery_V2(
    parser_context_t* c, pd_recovery_close_recovery_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_remove_recovery_V2(
    parser_context_t* c, pd_recovery_remove_recovery_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_cancel_recovered_V2(
    parser_context_t* c, pd_recovery_cancel_recovered_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V2(
    parser_context_t* c, pd_proxy_proxy_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V2(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V2(
    parser_context_t* c, pd_proxy_add_proxy_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V2(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V2(
    parser_context_t* c, pd_proxy_remove_proxy_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V2(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V2(
    parser_context_t* c, pd_proxy_remove_proxies_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V2(
    parser_context_t* c, pd_proxy_anonymous_V2_t* m)
{
    CHECK_ERROR(_readProxyType_V2(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V2(
    parser_context_t* c, pd_proxy_kill_anonymous_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V2(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V2(
    parser_context_t* c, pd_proxy_announce_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V2(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V2(
    parser_context_t* c, pd_proxy_remove_announcement_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V2(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V2(
    parser_context_t* c, pd_proxy_reject_announcement_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf_V2(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V2(
    parser_context_t* c, pd_proxy_proxy_announced_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V2(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V2(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V2(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V2(
    parser_context_t* c, pd_multisig_as_multi_V2_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V2(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V2(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V2(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V2(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V2(
    parser_context_t* c, pd_multisig_approve_as_multi_V2_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V2(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V2(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V2(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V2(
    parser_context_t* c, pd_multisig_cancel_as_multi_V2_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V2(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V2(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_bounty_V2(
    parser_context_t* c, pd_bounties_propose_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V2(
    parser_context_t* c, pd_bounties_approve_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V2(
    parser_context_t* c, pd_bounties_propose_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->curator))
    CHECK_ERROR(_readCompactBalance(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V2(
    parser_context_t* c, pd_bounties_unassign_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V2(
    parser_context_t* c, pd_bounties_accept_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V2(
    parser_context_t* c, pd_bounties_award_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V2(
    parser_context_t* c, pd_bounties_claim_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V2(
    parser_context_t* c, pd_bounties_close_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V2(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_cancel_approval_V2(
    parser_context_t* c, pd_assets_cancel_approval_V2_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bagslist_rebag_V2(
    parser_context_t* c, pd_bagslist_rebag_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->dislocated))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tokenfaucet_credit_account_with_tokens_unsigned_V2(
    parser_context_t* c, pd_tokenfaucet_credit_account_with_tokens_unsigned_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->account))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V2(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V2_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V2(c, &method->basic.utility_batch_V2))
        break;
    case 258: /* module 1 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V2(c, &method->basic.utility_batch_all_V2))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V2(c, &method->nested.balances_transfer_V2))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V2(c, &method->nested.balances_force_transfer_V2))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V2(c, &method->nested.balances_transfer_keep_alive_V2))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V2(c, &method->basic.balances_transfer_all_V2))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V2(c, &method->basic.staking_bond_V2))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V2(c, &method->basic.staking_bond_extra_V2))
        break;
    case 2306: /* module 9 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V2(c, &method->basic.staking_unbond_V2))
        break;
    case 2307: /* module 9 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V2(c, &method->basic.staking_withdraw_unbonded_V2))
        break;
    case 2308: /* module 9 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V2(c, &method->basic.staking_validate_V2))
        break;
    case 2309: /* module 9 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V2(c, &method->basic.staking_nominate_V2))
        break;
    case 2310: /* module 9 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V2(c, &method->basic.staking_chill_V2))
        break;
    case 2311: /* module 9 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V2(c, &method->basic.staking_set_payee_V2))
        break;
    case 2312: /* module 9 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V2(c, &method->basic.staking_set_controller_V2))
        break;
    case 2322: /* module 9 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V2(c, &method->basic.staking_payout_stakers_V2))
        break;
    case 2323: /* module 9 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V2(c, &method->basic.staking_rebond_V2))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V2(c, &method->basic.session_set_keys_V2))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V2(c, &method->basic.session_purge_keys_V2))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V2(c, &method->nested.system_fill_block_V2))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V2(c, &method->nested.system_remark_V2))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V2(c, &method->nested.system_set_heap_pages_V2))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V2(c, &method->nested.system_set_code_V2))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V2(c, &method->nested.system_set_code_without_checks_V2))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V2(c, &method->nested.system_remark_with_event_V2))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V2(c, &method->basic.timestamp_set_V2))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V2(c, &method->basic.indices_claim_V2))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V2(c, &method->basic.indices_transfer_V2))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V2(c, &method->basic.indices_free_V2))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V2(c, &method->basic.indices_force_transfer_V2))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V2(c, &method->basic.indices_freeze_V2))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V2(c, &method->nested.balances_set_balance_V2))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V2(c, &method->basic.balances_force_unreserve_V2))
        break;
    case 2313: /* module 9 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V2(c, &method->basic.staking_set_validator_count_V2))
        break;
    case 2314: /* module 9 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V2(c, &method->basic.staking_increase_validator_count_V2))
        break;
    case 2316: /* module 9 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V2(c, &method->basic.staking_force_no_eras_V2))
        break;
    case 2317: /* module 9 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V2(c, &method->basic.staking_force_new_era_V2))
        break;
    case 2318: /* module 9 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V2(c, &method->basic.staking_set_invulnerables_V2))
        break;
    case 2319: /* module 9 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V2(c, &method->basic.staking_force_unstake_V2))
        break;
    case 2320: /* module 9 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V2(c, &method->basic.staking_force_new_era_always_V2))
        break;
    case 2324: /* module 9 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V2(c, &method->basic.staking_set_history_depth_V2))
        break;
    case 2325: /* module 9 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V2(c, &method->basic.staking_reap_stash_V2))
        break;
    case 2326: /* module 9 call 22 */
        CHECK_ERROR(_readMethod_staking_kick_V2(c, &method->basic.staking_kick_V2))
        break;
    case 2328: /* module 9 call 24 */
        CHECK_ERROR(_readMethod_staking_chill_other_V2(c, &method->basic.staking_chill_other_V2))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V2(c, &method->basic.council_set_members_V2))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V2(c, &method->basic.council_execute_V2))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V2(c, &method->basic.council_propose_V2))
        break;
    case 2819: /* module 11 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V2(c, &method->basic.council_vote_V2))
        break;
    case 2820: /* module 11 call 4 */
        CHECK_ERROR(_readMethod_council_close_V2(c, &method->basic.council_close_V2))
        break;
    case 2821: /* module 11 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V2(c, &method->basic.council_disapprove_proposal_V2))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V2(c, &method->basic.technicalcommittee_set_members_V2))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V2(c, &method->basic.technicalcommittee_execute_V2))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V2(c, &method->basic.technicalcommittee_propose_V2))
        break;
    case 3075: /* module 12 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V2(c, &method->basic.technicalcommittee_vote_V2))
        break;
    case 3076: /* module 12 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V2(c, &method->basic.technicalcommittee_close_V2))
        break;
    case 3077: /* module 12 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V2(c, &method->basic.technicalcommittee_disapprove_proposal_V2))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_elections_vote_V2(c, &method->basic.elections_vote_V2))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_elections_remove_voter_V2(c, &method->basic.elections_remove_voter_V2))
        break;
    case 3330: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_elections_submit_candidacy_V2(c, &method->basic.elections_submit_candidacy_V2))
        break;
    case 3332: /* module 13 call 4 */
        CHECK_ERROR(_readMethod_elections_remove_member_V2(c, &method->basic.elections_remove_member_V2))
        break;
    case 3333: /* module 13 call 5 */
        CHECK_ERROR(_readMethod_elections_clean_defunct_voters_V2(c, &method->basic.elections_clean_defunct_voters_V2))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V2(c, &method->basic.technicalmembership_add_member_V2))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V2(c, &method->basic.technicalmembership_remove_member_V2))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V2(c, &method->basic.technicalmembership_swap_member_V2))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V2(c, &method->basic.technicalmembership_reset_members_V2))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V2(c, &method->basic.technicalmembership_change_key_V2))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V2(c, &method->basic.technicalmembership_set_prime_V2))
        break;
    case 3590: /* module 14 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V2(c, &method->basic.technicalmembership_clear_prime_V2))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V2(c, &method->basic.grandpa_note_stalled_V2))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V2(c, &method->basic.treasury_propose_spend_V2))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V2(c, &method->basic.treasury_reject_proposal_V2))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V2(c, &method->basic.treasury_approve_proposal_V2))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V2(c, &method->basic.sudo_sudo_V2))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V2(c, &method->basic.sudo_sudo_unchecked_weight_V2))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V2(c, &method->basic.sudo_set_key_V2))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_sudo_sudo_as_V2(c, &method->basic.sudo_sudo_as_V2))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V2(c, &method->basic.identity_add_registrar_V2))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V2(c, &method->basic.identity_clear_identity_V2))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V2(c, &method->basic.identity_request_judgement_V2))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V2(c, &method->basic.identity_cancel_request_V2))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V2(c, &method->basic.identity_set_fee_V2))
        break;
    case 5895: /* module 23 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V2(c, &method->basic.identity_set_account_id_V2))
        break;
    case 5898: /* module 23 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V2(c, &method->basic.identity_kill_identity_V2))
        break;
    case 5901: /* module 23 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V2(c, &method->basic.identity_remove_sub_V2))
        break;
    case 5902: /* module 23 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V2(c, &method->basic.identity_quit_sub_V2))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_recovery_set_recovered_V2(c, &method->basic.recovery_set_recovered_V2))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_recovery_initiate_recovery_V2(c, &method->basic.recovery_initiate_recovery_V2))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_recovery_vouch_recovery_V2(c, &method->basic.recovery_vouch_recovery_V2))
        break;
    case 6149: /* module 24 call 5 */
        CHECK_ERROR(_readMethod_recovery_claim_recovery_V2(c, &method->basic.recovery_claim_recovery_V2))
        break;
    case 6150: /* module 24 call 6 */
        CHECK_ERROR(_readMethod_recovery_close_recovery_V2(c, &method->basic.recovery_close_recovery_V2))
        break;
    case 6151: /* module 24 call 7 */
        CHECK_ERROR(_readMethod_recovery_remove_recovery_V2(c, &method->basic.recovery_remove_recovery_V2))
        break;
    case 6152: /* module 24 call 8 */
        CHECK_ERROR(_readMethod_recovery_cancel_recovered_V2(c, &method->basic.recovery_cancel_recovered_V2))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V2(c, &method->nested.proxy_proxy_V2))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V2(c, &method->basic.proxy_add_proxy_V2))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V2(c, &method->basic.proxy_remove_proxy_V2))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V2(c, &method->basic.proxy_remove_proxies_V2))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V2(c, &method->basic.proxy_anonymous_V2))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V2(c, &method->basic.proxy_kill_anonymous_V2))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V2(c, &method->basic.proxy_announce_V2))
        break;
    case 6663: /* module 26 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V2(c, &method->basic.proxy_remove_announcement_V2))
        break;
    case 6664: /* module 26 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V2(c, &method->basic.proxy_reject_announcement_V2))
        break;
    case 6665: /* module 26 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V2(c, &method->basic.proxy_proxy_announced_V2))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V2(c, &method->nested.multisig_as_multi_threshold_1_V2))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V2(c, &method->nested.multisig_as_multi_V2))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V2(c, &method->nested.multisig_approve_as_multi_V2))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V2(c, &method->nested.multisig_cancel_as_multi_V2))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V2(c, &method->basic.bounties_propose_bounty_V2))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V2(c, &method->basic.bounties_approve_bounty_V2))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V2(c, &method->basic.bounties_propose_curator_V2))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V2(c, &method->basic.bounties_unassign_curator_V2))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V2(c, &method->basic.bounties_accept_curator_V2))
        break;
    case 7173: /* module 28 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V2(c, &method->basic.bounties_award_bounty_V2))
        break;
    case 7174: /* module 28 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V2(c, &method->basic.bounties_claim_bounty_V2))
        break;
    case 7175: /* module 28 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V2(c, &method->basic.bounties_close_bounty_V2))
        break;
    case 7176: /* module 28 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V2(c, &method->basic.bounties_extend_bounty_expiry_V2))
        break;
    case 10004: /* module 39 call 20 */
        CHECK_ERROR(_readMethod_assets_cancel_approval_V2(c, &method->basic.assets_cancel_approval_V2))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_bagslist_rebag_V2(c, &method->basic.bagslist_rebag_V2))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_tokenfaucet_credit_account_with_tokens_unsigned_V2(c, &method->basic.tokenfaucet_credit_account_with_tokens_unsigned_V2))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V2(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 1:
        return STR_MO_UTILITY;
    case 6:
        return STR_MO_BALANCES;
    case 9:
        return STR_MO_STAKING;
    case 10:
        return STR_MO_SESSION;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 3:
        return STR_MO_TIMESTAMP;
    case 5:
        return STR_MO_INDICES;
    case 11:
        return STR_MO_COUNCIL;
    case 12:
        return STR_MO_TECHNICALCOMMITTEE;
    case 13:
        return STR_MO_ELECTIONS;
    case 14:
        return STR_MO_TECHNICALMEMBERSHIP;
    case 15:
        return STR_MO_GRANDPA;
    case 16:
        return STR_MO_TREASURY;
    case 17:
        return STR_MO_SUDO;
    case 23:
        return STR_MO_IDENTITY;
    case 24:
        return STR_MO_RECOVERY;
    case 26:
        return STR_MO_PROXY;
    case 27:
        return STR_MO_MULTISIG;
    case 28:
        return STR_MO_BOUNTIES;
    case 39:
        return STR_MO_ASSETS;
    case 40:
        return STR_MO_BAGSLIST;
    case 41:
        return STR_MO_TOKENFAUCET;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        return STR_ME_BATCH;
    case 258: /* module 1 call 2 */
        return STR_ME_BATCH_ALL;
    case 1536: /* module 6 call 0 */
        return STR_ME_TRANSFER;
    case 1538: /* module 6 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1539: /* module 6 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1540: /* module 6 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 2304: /* module 9 call 0 */
        return STR_ME_BOND;
    case 2305: /* module 9 call 1 */
        return STR_ME_BOND_EXTRA;
    case 2306: /* module 9 call 2 */
        return STR_ME_UNBOND;
    case 2307: /* module 9 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 2308: /* module 9 call 4 */
        return STR_ME_VALIDATE;
    case 2309: /* module 9 call 5 */
        return STR_ME_NOMINATE;
    case 2310: /* module 9 call 6 */
        return STR_ME_CHILL;
    case 2311: /* module 9 call 7 */
        return STR_ME_SET_PAYEE;
    case 2312: /* module 9 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 2322: /* module 9 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 2323: /* module 9 call 19 */
        return STR_ME_REBOND;
    case 2560: /* module 10 call 0 */
        return STR_ME_SET_KEYS;
    case 2561: /* module 10 call 1 */
        return STR_ME_PURGE_KEYS;
    default:
        return _getMethod_Name_V2_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V2_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 8: /* module 0 call 8 */
        return STR_ME_REMARK_WITH_EVENT;
    case 768: /* module 3 call 0 */
        return STR_ME_SET;
    case 1280: /* module 5 call 0 */
        return STR_ME_CLAIM;
    case 1281: /* module 5 call 1 */
        return STR_ME_TRANSFER;
    case 1282: /* module 5 call 2 */
        return STR_ME_FREE;
    case 1283: /* module 5 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 1284: /* module 5 call 4 */
        return STR_ME_FREEZE;
    case 1537: /* module 6 call 1 */
        return STR_ME_SET_BALANCE;
    case 1541: /* module 6 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 2313: /* module 9 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 2314: /* module 9 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 2316: /* module 9 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 2317: /* module 9 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 2318: /* module 9 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 2319: /* module 9 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 2320: /* module 9 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 2324: /* module 9 call 20 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 2325: /* module 9 call 21 */
        return STR_ME_REAP_STASH;
    case 2326: /* module 9 call 22 */
        return STR_ME_KICK;
    case 2328: /* module 9 call 24 */
        return STR_ME_CHILL_OTHER;
    case 2816: /* module 11 call 0 */
        return STR_ME_SET_MEMBERS;
    case 2817: /* module 11 call 1 */
        return STR_ME_EXECUTE;
    case 2818: /* module 11 call 2 */
        return STR_ME_PROPOSE;
    case 2819: /* module 11 call 3 */
        return STR_ME_VOTE;
    case 2820: /* module 11 call 4 */
        return STR_ME_CLOSE;
    case 2821: /* module 11 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3072: /* module 12 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3073: /* module 12 call 1 */
        return STR_ME_EXECUTE;
    case 3074: /* module 12 call 2 */
        return STR_ME_PROPOSE;
    case 3075: /* module 12 call 3 */
        return STR_ME_VOTE;
    case 3076: /* module 12 call 4 */
        return STR_ME_CLOSE;
    case 3077: /* module 12 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3328: /* module 13 call 0 */
        return STR_ME_VOTE;
    case 3329: /* module 13 call 1 */
        return STR_ME_REMOVE_VOTER;
    case 3330: /* module 13 call 2 */
        return STR_ME_SUBMIT_CANDIDACY;
    case 3332: /* module 13 call 4 */
        return STR_ME_REMOVE_MEMBER;
    case 3333: /* module 13 call 5 */
        return STR_ME_CLEAN_DEFUNCT_VOTERS;
    case 3584: /* module 14 call 0 */
        return STR_ME_ADD_MEMBER;
    case 3585: /* module 14 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 3586: /* module 14 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 3587: /* module 14 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 3588: /* module 14 call 4 */
        return STR_ME_CHANGE_KEY;
    case 3589: /* module 14 call 5 */
        return STR_ME_SET_PRIME;
    case 3590: /* module 14 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 3842: /* module 15 call 2 */
        return STR_ME_NOTE_STALLED;
    case 4096: /* module 16 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 4097: /* module 16 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 4098: /* module 16 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 4352: /* module 17 call 0 */
        return STR_ME_SUDO;
    case 4353: /* module 17 call 1 */
        return STR_ME_SUDO_UNCHECKED_WEIGHT;
    case 4354: /* module 17 call 2 */
        return STR_ME_SET_KEY;
    case 4355: /* module 17 call 3 */
        return STR_ME_SUDO_AS;
    case 5888: /* module 23 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 5891: /* module 23 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 5892: /* module 23 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 5893: /* module 23 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 5894: /* module 23 call 6 */
        return STR_ME_SET_FEE;
    case 5895: /* module 23 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 5898: /* module 23 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 5901: /* module 23 call 13 */
        return STR_ME_REMOVE_SUB;
    case 5902: /* module 23 call 14 */
        return STR_ME_QUIT_SUB;
    case 6145: /* module 24 call 1 */
        return STR_ME_SET_RECOVERED;
    case 6147: /* module 24 call 3 */
        return STR_ME_INITIATE_RECOVERY;
    case 6148: /* module 24 call 4 */
        return STR_ME_VOUCH_RECOVERY;
    case 6149: /* module 24 call 5 */
        return STR_ME_CLAIM_RECOVERY;
    case 6150: /* module 24 call 6 */
        return STR_ME_CLOSE_RECOVERY;
    case 6151: /* module 24 call 7 */
        return STR_ME_REMOVE_RECOVERY;
    case 6152: /* module 24 call 8 */
        return STR_ME_CANCEL_RECOVERED;
    case 6656: /* module 26 call 0 */
        return STR_ME_PROXY;
    case 6657: /* module 26 call 1 */
        return STR_ME_ADD_PROXY;
    case 6658: /* module 26 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 6659: /* module 26 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 6660: /* module 26 call 4 */
        return STR_ME_ANONYMOUS;
    case 6661: /* module 26 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 6662: /* module 26 call 6 */
        return STR_ME_ANNOUNCE;
    case 6663: /* module 26 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 6664: /* module 26 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 6665: /* module 26 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 6912: /* module 27 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 6913: /* module 27 call 1 */
        return STR_ME_AS_MULTI;
    case 6914: /* module 27 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 6915: /* module 27 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 7168: /* module 28 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 7169: /* module 28 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 7170: /* module 28 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 7171: /* module 28 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 7172: /* module 28 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 7173: /* module 28 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 7174: /* module 28 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 7175: /* module 28 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 7176: /* module 28 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 10004: /* module 39 call 20 */
        return STR_ME_CANCEL_APPROVAL;
    case 10240: /* module 40 call 0 */
        return STR_ME_REBAG;
    case 10496: /* module 41 call 0 */
        return STR_ME_CREDIT_ACCOUNT_WITH_TOKENS_UNSIGNED;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        return 1;
    case 258: /* module 1 call 2 */
        return 1;
    case 1536: /* module 6 call 0 */
        return 2;
    case 1538: /* module 6 call 2 */
        return 3;
    case 1539: /* module 6 call 3 */
        return 2;
    case 1540: /* module 6 call 4 */
        return 2;
    case 2304: /* module 9 call 0 */
        return 3;
    case 2305: /* module 9 call 1 */
        return 1;
    case 2306: /* module 9 call 2 */
        return 1;
    case 2307: /* module 9 call 3 */
        return 1;
    case 2308: /* module 9 call 4 */
        return 1;
    case 2309: /* module 9 call 5 */
        return 1;
    case 2310: /* module 9 call 6 */
        return 0;
    case 2311: /* module 9 call 7 */
        return 1;
    case 2312: /* module 9 call 8 */
        return 1;
    case 2322: /* module 9 call 18 */
        return 2;
    case 2323: /* module 9 call 19 */
        return 1;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 0;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 8: /* module 0 call 8 */
        return 1;
    case 768: /* module 3 call 0 */
        return 1;
    case 1280: /* module 5 call 0 */
        return 1;
    case 1281: /* module 5 call 1 */
        return 2;
    case 1282: /* module 5 call 2 */
        return 1;
    case 1283: /* module 5 call 3 */
        return 3;
    case 1284: /* module 5 call 4 */
        return 1;
    case 1537: /* module 6 call 1 */
        return 3;
    case 1541: /* module 6 call 5 */
        return 2;
    case 2313: /* module 9 call 9 */
        return 1;
    case 2314: /* module 9 call 10 */
        return 1;
    case 2316: /* module 9 call 12 */
        return 0;
    case 2317: /* module 9 call 13 */
        return 0;
    case 2318: /* module 9 call 14 */
        return 1;
    case 2319: /* module 9 call 15 */
        return 2;
    case 2320: /* module 9 call 16 */
        return 0;
    case 2324: /* module 9 call 20 */
        return 2;
    case 2325: /* module 9 call 21 */
        return 2;
    case 2326: /* module 9 call 22 */
        return 1;
    case 2328: /* module 9 call 24 */
        return 1;
    case 2816: /* module 11 call 0 */
        return 3;
    case 2817: /* module 11 call 1 */
        return 2;
    case 2818: /* module 11 call 2 */
        return 3;
    case 2819: /* module 11 call 3 */
        return 3;
    case 2820: /* module 11 call 4 */
        return 4;
    case 2821: /* module 11 call 5 */
        return 1;
    case 3072: /* module 12 call 0 */
        return 3;
    case 3073: /* module 12 call 1 */
        return 2;
    case 3074: /* module 12 call 2 */
        return 3;
    case 3075: /* module 12 call 3 */
        return 3;
    case 3076: /* module 12 call 4 */
        return 4;
    case 3077: /* module 12 call 5 */
        return 1;
    case 3328: /* module 13 call 0 */
        return 2;
    case 3329: /* module 13 call 1 */
        return 0;
    case 3330: /* module 13 call 2 */
        return 1;
    case 3332: /* module 13 call 4 */
        return 2;
    case 3333: /* module 13 call 5 */
        return 2;
    case 3584: /* module 14 call 0 */
        return 1;
    case 3585: /* module 14 call 1 */
        return 1;
    case 3586: /* module 14 call 2 */
        return 2;
    case 3587: /* module 14 call 3 */
        return 1;
    case 3588: /* module 14 call 4 */
        return 1;
    case 3589: /* module 14 call 5 */
        return 1;
    case 3590: /* module 14 call 6 */
        return 0;
    case 3842: /* module 15 call 2 */
        return 2;
    case 4096: /* module 16 call 0 */
        return 2;
    case 4097: /* module 16 call 1 */
        return 1;
    case 4098: /* module 16 call 2 */
        return 1;
    case 4352: /* module 17 call 0 */
        return 1;
    case 4353: /* module 17 call 1 */
        return 2;
    case 4354: /* module 17 call 2 */
        return 1;
    case 4355: /* module 17 call 3 */
        return 2;
    case 5888: /* module 23 call 0 */
        return 1;
    case 5891: /* module 23 call 3 */
        return 0;
    case 5892: /* module 23 call 4 */
        return 2;
    case 5893: /* module 23 call 5 */
        return 1;
    case 5894: /* module 23 call 6 */
        return 2;
    case 5895: /* module 23 call 7 */
        return 2;
    case 5898: /* module 23 call 10 */
        return 1;
    case 5901: /* module 23 call 13 */
        return 1;
    case 5902: /* module 23 call 14 */
        return 0;
    case 6145: /* module 24 call 1 */
        return 2;
    case 6147: /* module 24 call 3 */
        return 1;
    case 6148: /* module 24 call 4 */
        return 2;
    case 6149: /* module 24 call 5 */
        return 1;
    case 6150: /* module 24 call 6 */
        return 1;
    case 6151: /* module 24 call 7 */
        return 0;
    case 6152: /* module 24 call 8 */
        return 1;
    case 6656: /* module 26 call 0 */
        return 3;
    case 6657: /* module 26 call 1 */
        return 3;
    case 6658: /* module 26 call 2 */
        return 3;
    case 6659: /* module 26 call 3 */
        return 0;
    case 6660: /* module 26 call 4 */
        return 3;
    case 6661: /* module 26 call 5 */
        return 5;
    case 6662: /* module 26 call 6 */
        return 2;
    case 6663: /* module 26 call 7 */
        return 2;
    case 6664: /* module 26 call 8 */
        return 2;
    case 6665: /* module 26 call 9 */
        return 4;
    case 6912: /* module 27 call 0 */
        return 2;
    case 6913: /* module 27 call 1 */
        return 6;
    case 6914: /* module 27 call 2 */
        return 5;
    case 6915: /* module 27 call 3 */
        return 4;
    case 7168: /* module 28 call 0 */
        return 2;
    case 7169: /* module 28 call 1 */
        return 1;
    case 7170: /* module 28 call 2 */
        return 3;
    case 7171: /* module 28 call 3 */
        return 1;
    case 7172: /* module 28 call 4 */
        return 1;
    case 7173: /* module 28 call 5 */
        return 2;
    case 7174: /* module 28 call 6 */
        return 1;
    case 7175: /* module 28 call 7 */
        return 1;
    case 7176: /* module 28 call 8 */
        return 2;
    case 10004: /* module 39 call 20 */
        return 2;
    case 10240: /* module 40 call 0 */
        return 1;
    case 10496: /* module 41 call 0 */
        return 1;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 2309: /* module 9 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 2310: /* module 9 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2311: /* module 9 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2312: /* module 9 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2322: /* module 9 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 2323: /* module 9 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2313: /* module 9 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 2314: /* module 9 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 2316: /* module 9 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2317: /* module 9 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2318: /* module 9 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 2319: /* module 9 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2320: /* module 9 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2324: /* module 9 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT_era_items_deleted;
        default:
            return NULL;
        }
    case 2325: /* module 9 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2326: /* module 9 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2328: /* module 9 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3077: /* module 12 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_votes;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate_count;
        default:
            return NULL;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_has_replacement;
        default:
            return NULL;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_voters;
        case 1:
            return STR_IT_num_defunct;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5898: /* module 23 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 5901: /* module 23 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 5902: /* module 23 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6150: /* module 24 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6151: /* module 24 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6152: /* module 24 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_curator;
        case 2:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 7175: /* module 28 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 7176: /* module 28 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 10004: /* module 39 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dislocated;
        default:
            return NULL;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V2(
    pd_Method_V2_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V2 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V2 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V2 - dest */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->nested.balances_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V2 - source */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->nested.balances_force_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V2 - dest */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->nested.balances_force_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V2 - dest */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->nested.balances_transfer_keep_alive_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V2 - dest */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.balances_transfer_all_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V2 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V2.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V2 - controller */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.staking_bond_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V2 - payee */;
            return _toStringRewardDestination_V2(
                &m->basic.staking_bond_V2.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_extra_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_unbond_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V2 - prefs */;
            return _toStringValidatorPrefs_V2(
                &m->basic.staking_validate_V2.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2309: /* module 9 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V2 - targets */;
            return _toStringVecLookupasStaticLookupSource_V2(
                &m->basic.staking_nominate_V2.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2310: /* module 9 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2311: /* module 9 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V2 - payee */;
            return _toStringRewardDestination_V2(
                &m->basic.staking_set_payee_V2.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2312: /* module 9 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V2 - controller */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.staking_set_controller_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2322: /* module 9 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V2 - validator_stash */;
            return _toStringAccountId_V2(
                &m->basic.staking_payout_stakers_V2.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V2 - era */;
            return _toStringEraIndex_V2(
                &m->basic.staking_payout_stakers_V2.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2323: /* module 9 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_rebond_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V2 - keys */;
            return _toStringKeys_V2(
                &m->basic.session_set_keys_V2.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V2 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V2.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V2 - ratio */;
            return _toStringPerbill_V2(
                &m->nested.system_fill_block_V2.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V2 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V2 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V2.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V2 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V2 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V2 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_with_event_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V2 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V2.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_claim_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->basic.indices_transfer_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_transfer_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_free_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->basic.indices_force_transfer_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_force_transfer_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V2 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V2.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_freeze_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V2 - who */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->nested.balances_set_balance_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V2 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V2.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V2 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V2.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V2 - who */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.balances_force_unreserve_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V2 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2313: /* module 9 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V2 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2314: /* module 9 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V2 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V2.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2316: /* module 9 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2317: /* module 9 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2318: /* module 9 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V2 - invulnerables */;
            return _toStringVecAccountId_V2(
                &m->basic.staking_set_invulnerables_V2.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2319: /* module 9 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V2 - stash */;
            return _toStringAccountId_V2(
                &m->basic.staking_force_unstake_V2.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2320: /* module 9 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2324: /* module 9 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V2 - new_history_depth */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V2.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V2 - era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V2.era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2325: /* module 9 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V2 - stash */;
            return _toStringAccountId_V2(
                &m->basic.staking_reap_stash_V2.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2326: /* module 9 call 22 */
        switch (itemIdx) {
        case 0: /* staking_kick_V2 - who */;
            return _toStringVecLookupasStaticLookupSource_V2(
                &m->basic.staking_kick_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2328: /* module 9 call 24 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V2 - controller */;
            return _toStringAccountId_V2(
                &m->basic.staking_chill_other_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V2 - new_members */;
            return _toStringVecAccountId_V2(
                &m->basic.council_set_members_V2.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V2 - prime */;
            return _toStringOptionAccountId_V2(
                &m->basic.council_set_members_V2.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V2 - old_count */;
            return _toStringMemberCount_V2(
                &m->basic.council_set_members_V2.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V2 - proposal */;
            return _toStringProposal(
                &m->basic.council_execute_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V2 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_execute_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V2 - threshold */;
            return _toStringCompactu32(
                &m->basic.council_propose_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V2 - proposal */;
            return _toStringProposal(
                &m->basic.council_propose_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V2 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_propose_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V2 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V2 - index */;
            return _toStringCompactu32(
                &m->basic.council_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V2 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V2.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V2 - index */;
            return _toStringCompactu32(
                &m->basic.council_close_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V2 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.council_close_V2.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V2 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V2 - new_members */;
            return _toStringVecAccountId_V2(
                &m->basic.technicalcommittee_set_members_V2.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V2 - prime */;
            return _toStringOptionAccountId_V2(
                &m->basic.technicalcommittee_set_members_V2.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V2 - old_count */;
            return _toStringMemberCount_V2(
                &m->basic.technicalcommittee_set_members_V2.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V2 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_execute_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V2 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_execute_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V2 - threshold */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V2 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_propose_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V2 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V2 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V2 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V2 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V2.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V2 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V2 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.technicalcommittee_close_V2.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V2 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3077: /* module 12 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* elections_vote_V2 - votes */;
            return _toStringVecAccountId_V2(
                &m->basic.elections_vote_V2.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_vote_V2 - amount */;
            return _toStringCompactu128(
                &m->basic.elections_vote_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0: /* elections_submit_candidacy_V2 - candidate_count */;
            return _toStringCompactu32(
                &m->basic.elections_submit_candidacy_V2.candidate_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0: /* elections_remove_member_V2 - who */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.elections_remove_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_remove_member_V2 - has_replacement */;
            return _toStringbool(
                &m->basic.elections_remove_member_V2.has_replacement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0: /* elections_clean_defunct_voters_V2 - num_voters */;
            return _toStringu32(
                &m->basic.elections_clean_defunct_voters_V2.num_voters,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_clean_defunct_voters_V2 - num_defunct */;
            return _toStringu32(
                &m->basic.elections_clean_defunct_voters_V2.num_defunct,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V2 - who */;
            return _toStringAccountId_V2(
                &m->basic.technicalmembership_add_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V2 - who */;
            return _toStringAccountId_V2(
                &m->basic.technicalmembership_remove_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* technicalmembership_swap_member_V2 - remove */;
            return _toStringAccountId_V2(
                &m->basic.technicalmembership_swap_member_V2.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalmembership_swap_member_V2 - add */;
            return _toStringAccountId_V2(
                &m->basic.technicalmembership_swap_member_V2.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V2 - members */;
            return _toStringVecAccountId_V2(
                &m->basic.technicalmembership_reset_members_V2.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->basic.technicalmembership_change_key_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V2 - who */;
            return _toStringAccountId_V2(
                &m->basic.technicalmembership_set_prime_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V2 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V2 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V2.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V2 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.treasury_propose_spend_V2.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V2 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V2.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V2 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V2.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_V2 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_unchecked_weight_V2 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_unchecked_weight_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_unchecked_weight_V2 - weight */;
            return _toStringWeight_V2(
                &m->basic.sudo_sudo_unchecked_weight_V2.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V2 - new_ */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.sudo_set_key_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V2 - who */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.sudo_sudo_as_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_as_V2 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_as_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.identity_add_registrar_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V2 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V2.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V2 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V2.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V2 - reg_index */;
            return _toStringRegistrarIndex_V2(
                &m->basic.identity_cancel_request_V2.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V2 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V2 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V2.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V2 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->basic.identity_set_account_id_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5898: /* module 23 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V2 - target */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.identity_kill_identity_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5901: /* module 23 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V2 - sub */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.identity_remove_sub_V2.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5902: /* module 23 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0: /* recovery_set_recovered_V2 - lost */;
            return _toStringAccountId_V2(
                &m->basic.recovery_set_recovered_V2.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_set_recovered_V2 - rescuer */;
            return _toStringAccountId_V2(
                &m->basic.recovery_set_recovered_V2.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0: /* recovery_initiate_recovery_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.recovery_initiate_recovery_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* recovery_vouch_recovery_V2 - lost */;
            return _toStringAccountId_V2(
                &m->basic.recovery_vouch_recovery_V2.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_vouch_recovery_V2 - rescuer */;
            return _toStringAccountId_V2(
                &m->basic.recovery_vouch_recovery_V2.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0: /* recovery_claim_recovery_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.recovery_claim_recovery_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6150: /* module 24 call 6 */
        switch (itemIdx) {
        case 0: /* recovery_close_recovery_V2 - rescuer */;
            return _toStringAccountId_V2(
                &m->basic.recovery_close_recovery_V2.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6151: /* module 24 call 7 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6152: /* module 24 call 8 */
        switch (itemIdx) {
        case 0: /* recovery_cancel_recovered_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.recovery_cancel_recovered_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V2 - real */;
            return _toStringAccountId_V2(
                &m->nested.proxy_proxy_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V2 - force_proxy_type */;
            return _toStringOptionProxyType_V2(
                &m->nested.proxy_proxy_V2.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V2 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V2 - delegate */;
            return _toStringAccountId_V2(
                &m->basic.proxy_add_proxy_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V2 - proxy_type */;
            return _toStringProxyType_V2(
                &m->basic.proxy_add_proxy_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V2 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V2 - delegate */;
            return _toStringAccountId_V2(
                &m->basic.proxy_remove_proxy_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V2 - proxy_type */;
            return _toStringProxyType_V2(
                &m->basic.proxy_remove_proxy_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V2 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_anonymous_V2 - proxy_type */;
            return _toStringProxyType_V2(
                &m->basic.proxy_anonymous_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V2 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V2 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V2 - spawner */;
            return _toStringAccountId_V2(
                &m->basic.proxy_kill_anonymous_V2.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V2 - proxy_type */;
            return _toStringProxyType_V2(
                &m->basic.proxy_kill_anonymous_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V2 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V2 - height */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V2.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V2 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V2.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V2 - real */;
            return _toStringAccountId_V2(
                &m->basic.proxy_announce_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V2 - call_hash */;
            return _toStringCallHashOf_V2(
                &m->basic.proxy_announce_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V2 - real */;
            return _toStringAccountId_V2(
                &m->basic.proxy_remove_announcement_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V2 - call_hash */;
            return _toStringCallHashOf_V2(
                &m->basic.proxy_remove_announcement_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V2 - delegate */;
            return _toStringAccountId_V2(
                &m->basic.proxy_reject_announcement_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V2 - call_hash */;
            return _toStringCallHashOf_V2(
                &m->basic.proxy_reject_announcement_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V2 - delegate */;
            return _toStringAccountId_V2(
                &m->basic.proxy_proxy_announced_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V2 - real */;
            return _toStringAccountId_V2(
                &m->basic.proxy_proxy_announced_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V2 - force_proxy_type */;
            return _toStringOptionProxyType_V2(
                &m->basic.proxy_proxy_announced_V2.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V2 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V2 - other_signatories */;
            return _toStringVecAccountId_V2(
                &m->nested.multisig_as_multi_threshold_1_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V2 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V2 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V2 - other_signatories */;
            return _toStringVecAccountId_V2(
                &m->nested.multisig_as_multi_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V2 - maybe_timepoint */;
            return _toStringOptionTimepoint_V2(
                &m->nested.multisig_as_multi_V2.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V2 - call */;
            return _toStringOpaqueCall_V2(
                &m->nested.multisig_as_multi_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V2 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V2.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V2 - max_weight */;
            return _toStringWeight_V2(
                &m->nested.multisig_as_multi_V2.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V2 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V2 - other_signatories */;
            return _toStringVecAccountId_V2(
                &m->nested.multisig_approve_as_multi_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V2 - maybe_timepoint */;
            return _toStringOptionTimepoint_V2(
                &m->nested.multisig_approve_as_multi_V2.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V2 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V2 - max_weight */;
            return _toStringWeight_V2(
                &m->nested.multisig_approve_as_multi_V2.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V2 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V2 - other_signatories */;
            return _toStringVecAccountId_V2(
                &m->nested.multisig_cancel_as_multi_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V2 - timepoint */;
            return _toStringTimepoint_V2(
                &m->nested.multisig_cancel_as_multi_V2.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V2 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_bounty_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_bounty_V2 - description */;
            return _toStringBytes(
                &m->basic.bounties_propose_bounty_V2.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_approve_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_propose_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V2 - curator */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.bounties_propose_curator_V2.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V2 - fee */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_curator_V2.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_unassign_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_accept_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_award_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V2 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.bounties_award_bounty_V2.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_claim_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7175: /* module 28 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_close_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7176: /* module 28 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_extend_bounty_expiry_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V2 - remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10004: /* module 39 call 20 */
        switch (itemIdx) {
        case 0: /* assets_cancel_approval_V2 - id */;
            return _toStringCompactu128(
                &m->basic.assets_cancel_approval_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_cancel_approval_V2 - delegate */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.assets_cancel_approval_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* bagslist_rebag_V2 - dislocated */;
            return _toStringAccountId_V2(
                &m->basic.bagslist_rebag_V2.dislocated,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* tokenfaucet_credit_account_with_tokens_unsigned_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.tokenfaucet_credit_account_with_tokens_unsigned_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2307: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2319: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2325: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: // Utility:Batch
    case 258: // Utility:Batch all
    case 768: // Timestamp:Set
    case 1280: // Indices:Claim
    case 1281: // Indices:Transfer
    case 1282: // Indices:Free
    case 1283: // Indices:Force transfer
    case 1284: // Indices:Freeze
    case 1540: // Balances:Transfer all
    case 1541: // Balances:Force unreserve
    case 2304: // Staking:Bond
    case 2305: // Staking:Bond extra
    case 2306: // Staking:Unbond
    case 2307: // Staking:Withdraw Unbonded
    case 2308: // Staking:Validate
    case 2309: // Staking:Nominate
    case 2310: // Staking:Chill
    case 2311: // Staking:Set payee
    case 2312: // Staking:Set controller
    case 2313: // Staking:Set validator count
    case 2314: // Staking:Increase validator count
    case 2316: // Staking:Force no eras
    case 2317: // Staking:Force new era
    case 2318: // Staking:Set invulnerables
    case 2319: // Staking:Force unstake
    case 2320: // Staking:Force new era always
    case 2322: // Staking:Payout stakers
    case 2323: // Staking:Rebond
    case 2324: // Staking:Set history depth
    case 2325: // Staking:Reap stash
    case 2326: // Staking:Kick
    case 2328: // Staking:Chill other
    case 2560: // Session:Set keys
    case 2561: // Session:Purge keys
    case 2816: // Council:Set members
    case 2817: // Council:Execute
    case 2818: // Council:Propose
    case 2819: // Council:Vote
    case 2820: // Council:Close
    case 2821: // Council:Disapprove proposal
    case 3072: // TechnicalCommittee:Set members
    case 3073: // TechnicalCommittee:Execute
    case 3074: // TechnicalCommittee:Propose
    case 3075: // TechnicalCommittee:Vote
    case 3076: // TechnicalCommittee:Close
    case 3077: // TechnicalCommittee:Disapprove proposal
    case 3328: // Elections:Vote
    case 3329: // Elections:Remove voter
    case 3330: // Elections:Submit candidacy
    case 3332: // Elections:Remove member
    case 3333: // Elections:Clean defunct voters
    case 3584: // TechnicalMembership:Add member
    case 3585: // TechnicalMembership:Remove member
    case 3586: // TechnicalMembership:Swap member
    case 3587: // TechnicalMembership:Reset members
    case 3588: // TechnicalMembership:Change key
    case 3589: // TechnicalMembership:Set prime
    case 3590: // TechnicalMembership:Clear prime
    case 3842: // Grandpa:Note stalled
    case 4096: // Treasury:Propose spend
    case 4097: // Treasury:Reject proposal
    case 4098: // Treasury:Approve proposal
    case 4352: // Sudo:Sudo
    case 4353: // Sudo:Sudo unchecked weight
    case 4354: // Sudo:Set key
    case 4355: // Sudo:Sudo as
    case 5888: // Identity:Add registrar
    case 5891: // Identity:Clear identity
    case 5892: // Identity:Request judgement
    case 5893: // Identity:Cancel request
    case 5894: // Identity:Set fee
    case 5895: // Identity:Set account id
    case 5898: // Identity:Kill identity
    case 5901: // Identity:Remove sub
    case 5902: // Identity:Quit sub
    case 6145: // Recovery:Set recovered
    case 6147: // Recovery:Initiate recovery
    case 6148: // Recovery:Vouch recovery
    case 6149: // Recovery:Claim recovery
    case 6150: // Recovery:Close recovery
    case 6151: // Recovery:Remove recovery
    case 6152: // Recovery:Cancel recovered
    case 6657: // Proxy:Add proxy
    case 6658: // Proxy:Remove proxy
    case 6659: // Proxy:Remove proxies
    case 6660: // Proxy:Anonymous
    case 6661: // Proxy:Kill anonymous
    case 6662: // Proxy:Announce
    case 6663: // Proxy:Remove announcement
    case 6664: // Proxy:Reject announcement
    case 6665: // Proxy:Proxy announced
    case 7168: // Bounties:Propose bounty
    case 7169: // Bounties:Approve bounty
    case 7170: // Bounties:Propose curator
    case 7171: // Bounties:Unassign curator
    case 7172: // Bounties:Accept curator
    case 7173: // Bounties:Award bounty
    case 7174: // Bounties:Claim bounty
    case 7175: // Bounties:Close bounty
    case 7176: // Bounties:Extend bounty expiry
    case 10004: // Assets:Cancel approval
    case 10240: // BagsList:Rebag
    case 10496: // TokenFaucet:Credit account with tokens unsigned
        return false;
    default:
        return true;
    }
}
