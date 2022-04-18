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
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V2(
    parser_context_t* c, pd_balances_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->source))
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V2(
    parser_context_t* c, pd_balances_transfer_keep_alive_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V2(
    parser_context_t* c, pd_balances_transfer_all_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V2(
    parser_context_t* c, pd_staking_bond_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V2(
    parser_context_t* c, pd_staking_bond_extra_V2_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V2(
    parser_context_t* c, pd_staking_unbond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
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
    CHECK_ERROR(_readVecLookupSource_V2(c, &m->targets))
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
    CHECK_ERROR(_readLookupSource_V2(c, &m->controller))
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
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
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
    CHECK_ERROR(_readPerbill_V2(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V2(
    parser_context_t* c, pd_system_remark_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
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
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V2(
    parser_context_t* c, pd_system_set_code_without_checks_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V2(
    parser_context_t* c, pd_system_remark_with_event_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V2(
    parser_context_t* c, pd_timestamp_set_V2_t* m)
{
    CHECK_ERROR(_readCompactMoment_V2(c, &m->now))
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
    CHECK_ERROR(_readLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
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

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V2(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V2_t* m)
{
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V2(
    parser_context_t* c, pd_staking_set_history_depth_V2_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V2(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
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
    CHECK_ERROR(_readVecLookupSource_V2(c, &m->who))
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
    CHECK_ERROR(_readCompactMemberCount_V2(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V2(
    parser_context_t* c, pd_council_vote_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V2(
    parser_context_t* c, pd_council_close_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V2(c, &m->proposal_weight_bound))
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
    CHECK_ERROR(_readCompactMemberCount_V2(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V2(
    parser_context_t* c, pd_technicalcommittee_vote_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V2(
    parser_context_t* c, pd_technicalcommittee_close_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V2(c, &m->proposal_weight_bound))
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
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
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
    CHECK_ERROR(_readLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->has_replacement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_clean_defunct_voters_V2(
    parser_context_t* c, pd_elections_clean_defunct_voters_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->_num_voters))
    CHECK_ERROR(_readu32(c, &m->_num_defunct))
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
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    CHECK_ERROR(_readLookupSource_V2(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V2(
    parser_context_t* c, pd_treasury_reject_proposal_V2_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V2(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V2(
    parser_context_t* c, pd_treasury_approve_proposal_V2_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V2(c, &m->proposal_id))
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
    CHECK_ERROR(_readWeight_V2(c, &m->_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V2(
    parser_context_t* c, pd_sudo_set_key_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V2(
    parser_context_t* c, pd_sudo_sudo_as_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->who))
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
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->reg_index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_fee))
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
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V2(
    parser_context_t* c, pd_identity_set_account_id_V2_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->index))
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V2(
    parser_context_t* c, pd_identity_kill_identity_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V2(
    parser_context_t* c, pd_identity_remove_sub_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->sub))
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
    CHECK_ERROR(_readCompactBlockNumber(c, &m->height))
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
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V2(
    parser_context_t* c, pd_bounties_approve_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V2(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V2(
    parser_context_t* c, pd_bounties_propose_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V2(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource_V2(c, &m->curator))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V2(
    parser_context_t* c, pd_bounties_unassign_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V2(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V2(
    parser_context_t* c, pd_bounties_accept_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V2(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V2(
    parser_context_t* c, pd_bounties_award_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V2(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource_V2(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V2(
    parser_context_t* c, pd_bounties_claim_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V2(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V2(
    parser_context_t* c, pd_bounties_close_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V2(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V2(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V2_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V2(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V2(
    parser_context_t* c, pd_democracy_propose_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V2(
    parser_context_t* c, pd_democracy_second_V2_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V2(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote_V2(
    parser_context_t* c, pd_democracy_vote_V2_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V2(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote_V2(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V2(
    parser_context_t* c, pd_democracy_emergency_cancel_V2_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V2(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V2(
    parser_context_t* c, pd_democracy_external_propose_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V2(
    parser_context_t* c, pd_democracy_external_propose_majority_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V2(
    parser_context_t* c, pd_democracy_external_propose_default_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V2(
    parser_context_t* c, pd_democracy_fast_track_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V2(
    parser_context_t* c, pd_democracy_veto_external_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V2(
    parser_context_t* c, pd_democracy_cancel_referendum_V2_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V2(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V2(
    parser_context_t* c, pd_democracy_cancel_queued_V2_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V2(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V2(
    parser_context_t* c, pd_democracy_delegate_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->to))
    CHECK_ERROR(_readConviction_V2(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V2(
    parser_context_t* c, pd_democracy_undelegate_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V2(
    parser_context_t* c, pd_democracy_clear_public_proposals_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V2(
    parser_context_t* c, pd_democracy_note_preimage_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V2(
    parser_context_t* c, pd_democracy_note_preimage_operational_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V2(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V2(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V2(
    parser_context_t* c, pd_democracy_reap_preimage_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V2(
    parser_context_t* c, pd_democracy_unlock_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V2(
    parser_context_t* c, pd_democracy_remove_vote_V2_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V2(
    parser_context_t* c, pd_democracy_remove_other_vote_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V2(
    parser_context_t* c, pd_democracy_enact_proposal_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V2(
    parser_context_t* c, pd_democracy_cancel_proposal_V2_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V2(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_ormlvesting_claim_V2(
    parser_context_t* c, pd_ormlvesting_claim_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pdexmigration_set_migration_operational_status_V2(
    parser_context_t* c, pd_pdexmigration_set_migration_operational_status_V2_t* m)
{
    CHECK_ERROR(_readbool(c, &m->status))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pdexmigration_set_relayer_status_V2(
    parser_context_t* c, pd_pdexmigration_set_relayer_status_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->relayer))
    CHECK_ERROR(_readbool(c, &m->status))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pdexmigration_mint_V2(
    parser_context_t* c, pd_pdexmigration_mint_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->beneficiary))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readHash(c, &m->eth_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pdexmigration_unlock_V2(
    parser_context_t* c, pd_pdexmigration_unlock_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pdexmigration_remove_minted_tokens_V2(
    parser_context_t* c, pd_pdexmigration_remove_minted_tokens_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->beneficiary))
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
    case 9: /* module 0 call 9 */
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
    case 2321: /* module 9 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V2(c, &method->basic.staking_cancel_deferred_slash_V2))
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
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V2(c, &method->basic.identity_add_registrar_V2))
        break;
    case 5635: /* module 22 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V2(c, &method->basic.identity_clear_identity_V2))
        break;
    case 5636: /* module 22 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V2(c, &method->basic.identity_request_judgement_V2))
        break;
    case 5637: /* module 22 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V2(c, &method->basic.identity_cancel_request_V2))
        break;
    case 5638: /* module 22 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V2(c, &method->basic.identity_set_fee_V2))
        break;
    case 5639: /* module 22 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V2(c, &method->basic.identity_set_account_id_V2))
        break;
    case 5642: /* module 22 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V2(c, &method->basic.identity_kill_identity_V2))
        break;
    case 5645: /* module 22 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V2(c, &method->basic.identity_remove_sub_V2))
        break;
    case 5646: /* module 22 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V2(c, &method->basic.identity_quit_sub_V2))
        break;
    case 5889: /* module 23 call 1 */
        CHECK_ERROR(_readMethod_recovery_set_recovered_V2(c, &method->basic.recovery_set_recovered_V2))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_recovery_initiate_recovery_V2(c, &method->basic.recovery_initiate_recovery_V2))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_recovery_vouch_recovery_V2(c, &method->basic.recovery_vouch_recovery_V2))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_recovery_claim_recovery_V2(c, &method->basic.recovery_claim_recovery_V2))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_recovery_close_recovery_V2(c, &method->basic.recovery_close_recovery_V2))
        break;
    case 5895: /* module 23 call 7 */
        CHECK_ERROR(_readMethod_recovery_remove_recovery_V2(c, &method->basic.recovery_remove_recovery_V2))
        break;
    case 5896: /* module 23 call 8 */
        CHECK_ERROR(_readMethod_recovery_cancel_recovered_V2(c, &method->basic.recovery_cancel_recovered_V2))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V2(c, &method->nested.proxy_proxy_V2))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V2(c, &method->basic.proxy_add_proxy_V2))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V2(c, &method->basic.proxy_remove_proxy_V2))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V2(c, &method->basic.proxy_remove_proxies_V2))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V2(c, &method->basic.proxy_anonymous_V2))
        break;
    case 6405: /* module 25 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V2(c, &method->basic.proxy_kill_anonymous_V2))
        break;
    case 6406: /* module 25 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V2(c, &method->basic.proxy_announce_V2))
        break;
    case 6407: /* module 25 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V2(c, &method->basic.proxy_remove_announcement_V2))
        break;
    case 6408: /* module 25 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V2(c, &method->basic.proxy_reject_announcement_V2))
        break;
    case 6409: /* module 25 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V2(c, &method->basic.proxy_proxy_announced_V2))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V2(c, &method->nested.multisig_as_multi_threshold_1_V2))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V2(c, &method->nested.multisig_as_multi_V2))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V2(c, &method->nested.multisig_approve_as_multi_V2))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V2(c, &method->nested.multisig_cancel_as_multi_V2))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V2(c, &method->basic.bounties_propose_bounty_V2))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V2(c, &method->basic.bounties_approve_bounty_V2))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V2(c, &method->basic.bounties_propose_curator_V2))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V2(c, &method->basic.bounties_unassign_curator_V2))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V2(c, &method->basic.bounties_accept_curator_V2))
        break;
    case 6917: /* module 27 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V2(c, &method->basic.bounties_award_bounty_V2))
        break;
    case 6918: /* module 27 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V2(c, &method->basic.bounties_claim_bounty_V2))
        break;
    case 6919: /* module 27 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V2(c, &method->basic.bounties_close_bounty_V2))
        break;
    case 6920: /* module 27 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V2(c, &method->basic.bounties_extend_bounty_expiry_V2))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V2(c, &method->basic.democracy_propose_V2))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V2(c, &method->basic.democracy_second_V2))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V2(c, &method->basic.democracy_vote_V2))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V2(c, &method->basic.democracy_emergency_cancel_V2))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V2(c, &method->basic.democracy_external_propose_V2))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V2(c, &method->basic.democracy_external_propose_majority_V2))
        break;
    case 7686: /* module 30 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V2(c, &method->basic.democracy_external_propose_default_V2))
        break;
    case 7687: /* module 30 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V2(c, &method->basic.democracy_fast_track_V2))
        break;
    case 7688: /* module 30 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V2(c, &method->basic.democracy_veto_external_V2))
        break;
    case 7689: /* module 30 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V2(c, &method->basic.democracy_cancel_referendum_V2))
        break;
    case 7690: /* module 30 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V2(c, &method->basic.democracy_cancel_queued_V2))
        break;
    case 7691: /* module 30 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V2(c, &method->basic.democracy_delegate_V2))
        break;
    case 7692: /* module 30 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V2(c, &method->basic.democracy_undelegate_V2))
        break;
    case 7693: /* module 30 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V2(c, &method->basic.democracy_clear_public_proposals_V2))
        break;
    case 7694: /* module 30 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V2(c, &method->basic.democracy_note_preimage_V2))
        break;
    case 7695: /* module 30 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V2(c, &method->basic.democracy_note_preimage_operational_V2))
        break;
    case 7696: /* module 30 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V2(c, &method->basic.democracy_note_imminent_preimage_V2))
        break;
    case 7697: /* module 30 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V2(c, &method->basic.democracy_note_imminent_preimage_operational_V2))
        break;
    case 7698: /* module 30 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V2(c, &method->basic.democracy_reap_preimage_V2))
        break;
    case 7699: /* module 30 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V2(c, &method->basic.democracy_unlock_V2))
        break;
    case 7700: /* module 30 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V2(c, &method->basic.democracy_remove_vote_V2))
        break;
    case 7701: /* module 30 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V2(c, &method->basic.democracy_remove_other_vote_V2))
        break;
    case 7702: /* module 30 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V2(c, &method->basic.democracy_enact_proposal_V2))
        break;
    case 7704: /* module 30 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V2(c, &method->basic.democracy_cancel_proposal_V2))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_ormlvesting_claim_V2(c, &method->basic.ormlvesting_claim_V2))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_pdexmigration_set_migration_operational_status_V2(c, &method->basic.pdexmigration_set_migration_operational_status_V2))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_pdexmigration_set_relayer_status_V2(c, &method->basic.pdexmigration_set_relayer_status_V2))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_pdexmigration_mint_V2(c, &method->basic.pdexmigration_mint_V2))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_pdexmigration_unlock_V2(c, &method->basic.pdexmigration_unlock_V2))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_pdexmigration_remove_minted_tokens_V2(c, &method->basic.pdexmigration_remove_minted_tokens_V2))
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
    case 22:
        return STR_MO_IDENTITY;
    case 23:
        return STR_MO_RECOVERY;
    case 25:
        return STR_MO_PROXY;
    case 26:
        return STR_MO_MULTISIG;
    case 27:
        return STR_MO_BOUNTIES;
    case 30:
        return STR_MO_DEMOCRACY;
    case 28:
        return STR_MO_ORMLVESTING;
    case 29:
        return STR_MO_PDEXMIGRATION;
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
    case 9: /* module 0 call 9 */
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
    case 2321: /* module 9 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
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
    case 5632: /* module 22 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 5635: /* module 22 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 5636: /* module 22 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 5637: /* module 22 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 5638: /* module 22 call 6 */
        return STR_ME_SET_FEE;
    case 5639: /* module 22 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 5642: /* module 22 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 5645: /* module 22 call 13 */
        return STR_ME_REMOVE_SUB;
    case 5646: /* module 22 call 14 */
        return STR_ME_QUIT_SUB;
    case 5889: /* module 23 call 1 */
        return STR_ME_SET_RECOVERED;
    case 5891: /* module 23 call 3 */
        return STR_ME_INITIATE_RECOVERY;
    case 5892: /* module 23 call 4 */
        return STR_ME_VOUCH_RECOVERY;
    case 5893: /* module 23 call 5 */
        return STR_ME_CLAIM_RECOVERY;
    case 5894: /* module 23 call 6 */
        return STR_ME_CLOSE_RECOVERY;
    case 5895: /* module 23 call 7 */
        return STR_ME_REMOVE_RECOVERY;
    case 5896: /* module 23 call 8 */
        return STR_ME_CANCEL_RECOVERED;
    case 6400: /* module 25 call 0 */
        return STR_ME_PROXY;
    case 6401: /* module 25 call 1 */
        return STR_ME_ADD_PROXY;
    case 6402: /* module 25 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 6403: /* module 25 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 6404: /* module 25 call 4 */
        return STR_ME_ANONYMOUS;
    case 6405: /* module 25 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 6406: /* module 25 call 6 */
        return STR_ME_ANNOUNCE;
    case 6407: /* module 25 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 6408: /* module 25 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 6409: /* module 25 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 6656: /* module 26 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 6657: /* module 26 call 1 */
        return STR_ME_AS_MULTI;
    case 6658: /* module 26 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 6659: /* module 26 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 6912: /* module 27 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 6913: /* module 27 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 6914: /* module 27 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 6915: /* module 27 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 6916: /* module 27 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 6917: /* module 27 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 6918: /* module 27 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 6919: /* module 27 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 6920: /* module 27 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 7680: /* module 30 call 0 */
        return STR_ME_PROPOSE;
    case 7681: /* module 30 call 1 */
        return STR_ME_SECOND;
    case 7682: /* module 30 call 2 */
        return STR_ME_VOTE;
    case 7683: /* module 30 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 7684: /* module 30 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 7685: /* module 30 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 7686: /* module 30 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 7687: /* module 30 call 7 */
        return STR_ME_FAST_TRACK;
    case 7688: /* module 30 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 7689: /* module 30 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 7690: /* module 30 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 7691: /* module 30 call 11 */
        return STR_ME_DELEGATE;
    case 7692: /* module 30 call 12 */
        return STR_ME_UNDELEGATE;
    case 7693: /* module 30 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 7694: /* module 30 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 7695: /* module 30 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 7696: /* module 30 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 7697: /* module 30 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 7698: /* module 30 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 7699: /* module 30 call 19 */
        return STR_ME_UNLOCK;
    case 7700: /* module 30 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 7701: /* module 30 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 7702: /* module 30 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 7704: /* module 30 call 24 */
        return STR_ME_CANCEL_PROPOSAL;
    case 7168: /* module 28 call 0 */
        return STR_ME_CLAIM;
    case 7424: /* module 29 call 0 */
        return STR_ME_SET_MIGRATION_OPERATIONAL_STATUS;
    case 7425: /* module 29 call 1 */
        return STR_ME_SET_RELAYER_STATUS;
    case 7426: /* module 29 call 2 */
        return STR_ME_MINT;
    case 7427: /* module 29 call 3 */
        return STR_ME_UNLOCK;
    case 7428: /* module 29 call 4 */
        return STR_ME_REMOVE_MINTED_TOKENS;
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
    case 9: /* module 0 call 9 */
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
    case 2321: /* module 9 call 17 */
        return 2;
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
    case 5632: /* module 22 call 0 */
        return 1;
    case 5635: /* module 22 call 3 */
        return 0;
    case 5636: /* module 22 call 4 */
        return 2;
    case 5637: /* module 22 call 5 */
        return 1;
    case 5638: /* module 22 call 6 */
        return 2;
    case 5639: /* module 22 call 7 */
        return 2;
    case 5642: /* module 22 call 10 */
        return 1;
    case 5645: /* module 22 call 13 */
        return 1;
    case 5646: /* module 22 call 14 */
        return 0;
    case 5889: /* module 23 call 1 */
        return 2;
    case 5891: /* module 23 call 3 */
        return 1;
    case 5892: /* module 23 call 4 */
        return 2;
    case 5893: /* module 23 call 5 */
        return 1;
    case 5894: /* module 23 call 6 */
        return 1;
    case 5895: /* module 23 call 7 */
        return 0;
    case 5896: /* module 23 call 8 */
        return 1;
    case 6400: /* module 25 call 0 */
        return 3;
    case 6401: /* module 25 call 1 */
        return 3;
    case 6402: /* module 25 call 2 */
        return 3;
    case 6403: /* module 25 call 3 */
        return 0;
    case 6404: /* module 25 call 4 */
        return 3;
    case 6405: /* module 25 call 5 */
        return 5;
    case 6406: /* module 25 call 6 */
        return 2;
    case 6407: /* module 25 call 7 */
        return 2;
    case 6408: /* module 25 call 8 */
        return 2;
    case 6409: /* module 25 call 9 */
        return 4;
    case 6656: /* module 26 call 0 */
        return 2;
    case 6657: /* module 26 call 1 */
        return 6;
    case 6658: /* module 26 call 2 */
        return 5;
    case 6659: /* module 26 call 3 */
        return 4;
    case 6912: /* module 27 call 0 */
        return 2;
    case 6913: /* module 27 call 1 */
        return 1;
    case 6914: /* module 27 call 2 */
        return 3;
    case 6915: /* module 27 call 3 */
        return 1;
    case 6916: /* module 27 call 4 */
        return 1;
    case 6917: /* module 27 call 5 */
        return 2;
    case 6918: /* module 27 call 6 */
        return 1;
    case 6919: /* module 27 call 7 */
        return 1;
    case 6920: /* module 27 call 8 */
        return 2;
    case 7680: /* module 30 call 0 */
        return 2;
    case 7681: /* module 30 call 1 */
        return 2;
    case 7682: /* module 30 call 2 */
        return 2;
    case 7683: /* module 30 call 3 */
        return 1;
    case 7684: /* module 30 call 4 */
        return 1;
    case 7685: /* module 30 call 5 */
        return 1;
    case 7686: /* module 30 call 6 */
        return 1;
    case 7687: /* module 30 call 7 */
        return 3;
    case 7688: /* module 30 call 8 */
        return 1;
    case 7689: /* module 30 call 9 */
        return 1;
    case 7690: /* module 30 call 10 */
        return 1;
    case 7691: /* module 30 call 11 */
        return 3;
    case 7692: /* module 30 call 12 */
        return 0;
    case 7693: /* module 30 call 13 */
        return 0;
    case 7694: /* module 30 call 14 */
        return 1;
    case 7695: /* module 30 call 15 */
        return 1;
    case 7696: /* module 30 call 16 */
        return 1;
    case 7697: /* module 30 call 17 */
        return 1;
    case 7698: /* module 30 call 18 */
        return 2;
    case 7699: /* module 30 call 19 */
        return 1;
    case 7700: /* module 30 call 20 */
        return 1;
    case 7701: /* module 30 call 21 */
        return 2;
    case 7702: /* module 30 call 22 */
        return 2;
    case 7704: /* module 30 call 24 */
        return 1;
    case 7168: /* module 28 call 0 */
        return 0;
    case 7424: /* module 29 call 0 */
        return 1;
    case 7425: /* module 29 call 1 */
        return 2;
    case 7426: /* module 29 call 2 */
        return 3;
    case 7427: /* module 29 call 3 */
        return 0;
    case 7428: /* module 29 call 4 */
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
            return STR_IT__ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT__remark;
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
    case 9: /* module 0 call 9 */
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
    case 2321: /* module 9 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 2324: /* module 9 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT__era_items_deleted;
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
            return STR_IT__num_voters;
        case 1:
            return STR_IT__num_defunct;
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
            return STR_IT__weight;
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
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 5638: /* module 22 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 5639: /* module 22 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5642: /* module 22 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 5645: /* module 22 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 5646: /* module 22 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
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
    case 6401: /* module 25 call 1 */
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
    case 6402: /* module 25 call 2 */
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
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
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
    case 6405: /* module 25 call 5 */
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
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 6408: /* module 25 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 6409: /* module 25 call 9 */
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
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
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
    case 6658: /* module 26 call 2 */
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
    case 6659: /* module 26 call 3 */
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
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
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
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 6919: /* module 27 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 6920: /* module 27 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 7690: /* module 30 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_which;
        default:
            return NULL;
        }
    case 7691: /* module 30 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_conviction;
        case 2:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 7692: /* module 30 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7693: /* module 30 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7694: /* module 30 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 7695: /* module 30 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 7696: /* module 30 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 7697: /* module 30 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 7698: /* module 30 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
    case 7699: /* module 30 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 7700: /* module 30 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 7701: /* module 30 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 7702: /* module 30 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 7704: /* module 30 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prop_index;
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_status;
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_relayer;
        case 1:
            return STR_IT_status;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_beneficiary;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_eth_tx;
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_beneficiary;
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
            return _toStringLookupSource_V2(
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
            return _toStringLookupSource_V2(
                &m->nested.balances_force_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V2 - dest */;
            return _toStringLookupSource_V2(
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
            return _toStringLookupSource_V2(
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
            return _toStringLookupSource_V2(
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
            return _toStringLookupSource_V2(
                &m->basic.staking_bond_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V2 - amount */;
            return _toStringCompactBalanceOf(
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
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_extra_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V2 - amount */;
            return _toStringCompactBalanceOf(
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
            return _toStringVecLookupSource_V2(
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
            return _toStringLookupSource_V2(
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
            return _toStringCompactBalanceOf(
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
        case 0: /* system_fill_block_V2 - _ratio */;
            return _toStringPerbill_V2(
                &m->nested.system_fill_block_V2._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V2 - _remark */;
            return _toStringBytes(
                &m->nested.system_remark_V2._remark,
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
            return _toStringBytes(
                &m->nested.system_set_code_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V2 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_without_checks_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V2 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V2 - now */;
            return _toStringCompactMoment_V2(
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
            return _toStringLookupSource_V2(
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
    case 2321: /* module 9 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V2 - era */;
            return _toStringEraIndex_V2(
                &m->basic.staking_cancel_deferred_slash_V2.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V2 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V2.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2324: /* module 9 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V2 - new_history_depth */;
            return _toStringCompactEraIndex_V2(
                &m->basic.staking_set_history_depth_V2.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V2 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V2._era_items_deleted,
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
            return _toStringVecLookupSource_V2(
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
            return _toStringCompactMemberCount_V2(
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
            return _toStringCompactProposalIndex_V2(
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
            return _toStringCompactProposalIndex_V2(
                &m->basic.council_close_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V2 - proposal_weight_bound */;
            return _toStringCompactWeight_V2(
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
            return _toStringCompactMemberCount_V2(
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
            return _toStringCompactProposalIndex_V2(
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
            return _toStringCompactProposalIndex_V2(
                &m->basic.technicalcommittee_close_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V2 - proposal_weight_bound */;
            return _toStringCompactWeight_V2(
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
            return _toStringCompactBalanceOf(
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
            return _toStringLookupSource_V2(
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
        case 0: /* elections_clean_defunct_voters_V2 - _num_voters */;
            return _toStringu32(
                &m->basic.elections_clean_defunct_voters_V2._num_voters,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_clean_defunct_voters_V2 - _num_defunct */;
            return _toStringu32(
                &m->basic.elections_clean_defunct_voters_V2._num_defunct,
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
            return _toStringCompactBalanceOf(
                &m->basic.treasury_propose_spend_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V2 - beneficiary */;
            return _toStringLookupSource_V2(
                &m->basic.treasury_propose_spend_V2.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V2 - proposal_id */;
            return _toStringCompactProposalIndex_V2(
                &m->basic.treasury_reject_proposal_V2.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V2 - proposal_id */;
            return _toStringCompactProposalIndex_V2(
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
        case 1: /* sudo_sudo_unchecked_weight_V2 - _weight */;
            return _toStringWeight_V2(
                &m->basic.sudo_sudo_unchecked_weight_V2._weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V2 - new_ */;
            return _toStringLookupSource_V2(
                &m->basic.sudo_set_key_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V2 - who */;
            return _toStringLookupSource_V2(
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
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.identity_add_registrar_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V2 - reg_index */;
            return _toStringCompactRegistrarIndex_V2(
                &m->basic.identity_request_judgement_V2.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V2 - max_fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_request_judgement_V2.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V2 - reg_index */;
            return _toStringRegistrarIndex_V2(
                &m->basic.identity_cancel_request_V2.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5638: /* module 22 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V2 - index */;
            return _toStringCompactRegistrarIndex_V2(
                &m->basic.identity_set_fee_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V2 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_set_fee_V2.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5639: /* module 22 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V2 - index */;
            return _toStringCompactRegistrarIndex_V2(
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
    case 5642: /* module 22 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V2 - target */;
            return _toStringLookupSource_V2(
                &m->basic.identity_kill_identity_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5645: /* module 22 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V2 - sub */;
            return _toStringLookupSource_V2(
                &m->basic.identity_remove_sub_V2.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5646: /* module 22 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5889: /* module 23 call 1 */
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
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0: /* recovery_initiate_recovery_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.recovery_initiate_recovery_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5892: /* module 23 call 4 */
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
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0: /* recovery_claim_recovery_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.recovery_claim_recovery_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0: /* recovery_close_recovery_V2 - rescuer */;
            return _toStringAccountId_V2(
                &m->basic.recovery_close_recovery_V2.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0: /* recovery_cancel_recovered_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.recovery_cancel_recovered_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
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
    case 6401: /* module 25 call 1 */
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
    case 6402: /* module 25 call 2 */
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
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6404: /* module 25 call 4 */
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
    case 6405: /* module 25 call 5 */
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
            return _toStringCompactBlockNumber(
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
    case 6406: /* module 25 call 6 */
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
    case 6407: /* module 25 call 7 */
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
    case 6408: /* module 25 call 8 */
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
    case 6409: /* module 25 call 9 */
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
    case 6656: /* module 26 call 0 */
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
    case 6657: /* module 26 call 1 */
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
    case 6658: /* module 26 call 2 */
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
    case 6659: /* module 26 call 3 */
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
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V2 - amount */;
            return _toStringCompactBalanceOf(
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
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V2 - bounty_id */;
            return _toStringCompactBountyIndex_V2(
                &m->basic.bounties_approve_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V2 - bounty_id */;
            return _toStringCompactBountyIndex_V2(
                &m->basic.bounties_propose_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V2 - curator */;
            return _toStringLookupSource_V2(
                &m->basic.bounties_propose_curator_V2.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V2 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.bounties_propose_curator_V2.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V2 - bounty_id */;
            return _toStringCompactBountyIndex_V2(
                &m->basic.bounties_unassign_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V2 - bounty_id */;
            return _toStringCompactBountyIndex_V2(
                &m->basic.bounties_accept_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V2 - bounty_id */;
            return _toStringCompactBountyIndex_V2(
                &m->basic.bounties_award_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V2 - beneficiary */;
            return _toStringLookupSource_V2(
                &m->basic.bounties_award_bounty_V2.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V2 - bounty_id */;
            return _toStringCompactBountyIndex_V2(
                &m->basic.bounties_claim_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6919: /* module 27 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V2 - bounty_id */;
            return _toStringCompactBountyIndex_V2(
                &m->basic.bounties_close_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6920: /* module 27 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V2 - bounty_id */;
            return _toStringCompactBountyIndex_V2(
                &m->basic.bounties_extend_bounty_expiry_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V2 - _remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V2._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V2 - amount */;
            return _toStringCompactBalanceOf(
                &m->basic.democracy_propose_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V2 - proposal */;
            return _toStringCompactPropIndex_V2(
                &m->basic.democracy_second_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V2 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V2.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* democracy_vote_V2 - ref_index */;
            return _toStringCompactReferendumIndex_V2(
                &m->basic.democracy_vote_V2.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_vote_V2 - vote */;
            return _toStringAccountVote_V2(
                &m->basic.democracy_vote_V2.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V2 - ref_index */;
            return _toStringReferendumIndex_V2(
                &m->basic.democracy_emergency_cancel_V2.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V2 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V2.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V2 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V2 - ref_index */;
            return _toStringCompactReferendumIndex_V2(
                &m->basic.democracy_cancel_referendum_V2.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7690: /* module 30 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V2 - which */;
            return _toStringReferendumIndex_V2(
                &m->basic.democracy_cancel_queued_V2.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7691: /* module 30 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V2 - to */;
            return _toStringAccountId_V2(
                &m->basic.democracy_delegate_V2.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V2 - conviction */;
            return _toStringConviction_V2(
                &m->basic.democracy_delegate_V2.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V2 - balance */;
            return _toStringBalanceOf(
                &m->basic.democracy_delegate_V2.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7692: /* module 30 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7693: /* module 30 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7694: /* module 30 call 14 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_V2 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V2.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7695: /* module 30 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V2 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V2.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7696: /* module 30 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V2 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V2.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7697: /* module 30 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V2 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V2.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7698: /* module 30 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V2 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V2.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7699: /* module 30 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V2 - target */;
            return _toStringAccountId_V2(
                &m->basic.democracy_unlock_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7700: /* module 30 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V2 - index */;
            return _toStringReferendumIndex_V2(
                &m->basic.democracy_remove_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7701: /* module 30 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V2 - target */;
            return _toStringAccountId_V2(
                &m->basic.democracy_remove_other_vote_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V2 - index */;
            return _toStringReferendumIndex_V2(
                &m->basic.democracy_remove_other_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7702: /* module 30 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_enact_proposal_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V2 - index */;
            return _toStringReferendumIndex_V2(
                &m->basic.democracy_enact_proposal_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7704: /* module 30 call 24 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V2 - prop_index */;
            return _toStringCompactPropIndex_V2(
                &m->basic.democracy_cancel_proposal_V2.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* pdexmigration_set_migration_operational_status_V2 - status */;
            return _toStringbool(
                &m->basic.pdexmigration_set_migration_operational_status_V2.status,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* pdexmigration_set_relayer_status_V2 - relayer */;
            return _toStringAccountId_V2(
                &m->basic.pdexmigration_set_relayer_status_V2.relayer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pdexmigration_set_relayer_status_V2 - status */;
            return _toStringbool(
                &m->basic.pdexmigration_set_relayer_status_V2.status,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* pdexmigration_mint_V2 - beneficiary */;
            return _toStringAccountId_V2(
                &m->basic.pdexmigration_mint_V2.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pdexmigration_mint_V2 - amount */;
            return _toStringBalance(
                &m->basic.pdexmigration_mint_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* pdexmigration_mint_V2 - eth_tx */;
            return _toStringHash(
                &m->basic.pdexmigration_mint_V2.eth_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0: /* pdexmigration_remove_minted_tokens_V2 - beneficiary */;
            return _toStringAccountId_V2(
                &m->basic.pdexmigration_remove_minted_tokens_V2.beneficiary,
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
    case 2321: // Staking:Cancel deferred slash
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
    case 5632: // Identity:Add registrar
    case 5635: // Identity:Clear identity
    case 5636: // Identity:Request judgement
    case 5637: // Identity:Cancel request
    case 5638: // Identity:Set fee
    case 5639: // Identity:Set account id
    case 5642: // Identity:Kill identity
    case 5645: // Identity:Remove sub
    case 5646: // Identity:Quit sub
    case 5889: // Recovery:Set recovered
    case 5891: // Recovery:Initiate recovery
    case 5892: // Recovery:Vouch recovery
    case 5893: // Recovery:Claim recovery
    case 5894: // Recovery:Close recovery
    case 5895: // Recovery:Remove recovery
    case 5896: // Recovery:Cancel recovered
    case 6401: // Proxy:Add proxy
    case 6402: // Proxy:Remove proxy
    case 6403: // Proxy:Remove proxies
    case 6404: // Proxy:Anonymous
    case 6405: // Proxy:Kill anonymous
    case 6406: // Proxy:Announce
    case 6407: // Proxy:Remove announcement
    case 6408: // Proxy:Reject announcement
    case 6409: // Proxy:Proxy announced
    case 6912: // Bounties:Propose bounty
    case 6913: // Bounties:Approve bounty
    case 6914: // Bounties:Propose curator
    case 6915: // Bounties:Unassign curator
    case 6916: // Bounties:Accept curator
    case 6917: // Bounties:Award bounty
    case 6918: // Bounties:Claim bounty
    case 6919: // Bounties:Close bounty
    case 6920: // Bounties:Extend bounty expiry
    case 7680: // Democracy:Propose
    case 7681: // Democracy:Second
    case 7682: // Democracy:Vote
    case 7683: // Democracy:Emergency cancel
    case 7684: // Democracy:External propose
    case 7685: // Democracy:External propose majority
    case 7686: // Democracy:External propose default
    case 7687: // Democracy:Fast track
    case 7688: // Democracy:Veto external
    case 7689: // Democracy:Cancel referendum
    case 7690: // Democracy:Cancel queued
    case 7691: // Democracy:Delegate
    case 7692: // Democracy:Undelegate
    case 7693: // Democracy:Clear public proposals
    case 7694: // Democracy:Note preimage
    case 7695: // Democracy:Note preimage operational
    case 7696: // Democracy:Note imminent preimage
    case 7697: // Democracy:Note imminent preimage operational
    case 7698: // Democracy:Reap preimage
    case 7699: // Democracy:Unlock
    case 7700: // Democracy:Remove vote
    case 7701: // Democracy:Remove other vote
    case 7702: // Democracy:Enact proposal
    case 7704: // Democracy:Cancel proposal
    case 7168: // OrmlVesting:Claim
    case 7424: // PDEXMigration:Set migration operational status
    case 7425: // PDEXMigration:Set relayer status
    case 7426: // PDEXMigration:Mint
    case 7427: // PDEXMigration:Unlock
    case 7428: // PDEXMigration:Remove minted tokens
        return false;
    default:
        return true;
    }
}
