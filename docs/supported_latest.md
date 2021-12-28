# Polkadex  2.271.x

## System

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|fill_block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` _ratio <br/> | 
|remark |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` _remark <br/> | 
|set_heap_pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> | 
|set_code |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> | 
|set_code_without_checks |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> | 
|set_changes_trie_config |    |   |   | `Option<ChangesTrieConfiguration>` changes_trie_config <br/> | 
|set_storage |    |   |   | `Vec<KeyValue>` items <br/> | 
|kill_storage |    |   |   | `Vec<Key>` keys <br/> | 
|kill_prefix |    |   |   | `Key` prefix <br/>`u32` _subkeys <br/> | 
|remark_with_event |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` remark <br/> | 

## Utility

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|batch | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<Call>` calls <br/> | 
|as_derivative |    |   |   | `u16` index <br/>`Call` call <br/> | 
|batch_all | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<Call>` calls <br/> | 

## Babe

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|report_equivocation_unsigned |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|plan_config_change |    |   |   | `NextConfigDescriptor` config <br/> | 

## Timestamp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set |    | :heavy_check_mark: |   | `Compact<Moment>` now <br/> | 

## Authorship

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_uncles |    |   |   | `Vec<Header>` new_uncles <br/> | 

## Indices

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 
|transfer |    |   |   | `AccountId` new <br/>`AccountIndex` index <br/> | 
|free |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 
|force_transfer |    | :heavy_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/>`bool` freeze <br/> | 
|freeze |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 

## Balances

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|set_balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` who <br/>`Compact<Balance>` new_free <br/>`Compact<Balance>` new_reserved <br/> | 
|force_transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` source <br/>`LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|transfer_keep_alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|transfer_all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupSource` dest <br/>`bool` keep_alive <br/> | 

## TransactionPayment

Empty

## ElectionProviderMultiPhase

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|submit_unsigned |    |   |   | `RawSolution` raw_solution <br/>`SolutionOrSnapshotSize` witness <br/> | 
|set_minimum_untrusted_score |    |   |   | `Option<ElectionScore>` maybe_next_score <br/> | 
|set_emergency_election_result |    |   |   | `Supports` supports <br/> | 
|submit |    |   |   | `RawSolution` raw_solution <br/>`u32` num_signed_submissions <br/> | 

## Staking

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|bond | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupSource` controller <br/>`Compact<BalanceOf>` value <br/>`RewardDestination` payee <br/> | 
|bond_extra | :heavy_check_mark:  | :heavy_check_mark: |   | `Compact<BalanceOf>` max_additional <br/> | 
|unbond | :heavy_check_mark:  | :heavy_check_mark: |   | `Compact<BalanceOf>` value <br/> | 
|withdraw_unbonded | :heavy_check_mark:  | :heavy_check_mark: |   | `u32` num_slashing_spans <br/> | 
|validate | :heavy_check_mark:  | :heavy_check_mark: |   | `ValidatorPrefs` prefs <br/> | 
|nominate | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<LookupSource>` targets <br/> | 
|chill | :heavy_check_mark:  | :heavy_check_mark: |   |  | 
|set_payee | :heavy_check_mark:  | :heavy_check_mark: |   | `RewardDestination` payee <br/> | 
|set_controller | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupSource` controller <br/> | 
|set_validator_count |    | :heavy_check_mark: |   | `Compact<u32>` new <br/> | 
|increase_validator_count |    | :heavy_check_mark: |   | `Compact<u32>` additional <br/> | 
|scale_validator_count |    |   |   | `Percent` factor <br/> | 
|force_no_eras |    | :heavy_check_mark: |   |  | 
|force_new_era |    | :heavy_check_mark: |   |  | 
|set_invulnerables |    |   |   | `Vec<AccountId>` invulnerables <br/> | 
|force_unstake |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|force_new_era_always |    | :heavy_check_mark: |   |  | 
|cancel_deferred_slash |    | :heavy_check_mark: |   | `EraIndex` era <br/>`Vec<u32>` slash_indices <br/> | 
|payout_stakers | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> | 
|rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `Compact<BalanceOf>` value <br/> | 
|set_history_depth |    | :heavy_check_mark: |   | `Compact<EraIndex>` new_history_depth <br/>`Compact<u32>` _era_items_deleted <br/> | 
|reap_stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|kick |    |   |   | `Vec<LookupSource>` who <br/> | 
|set_staking_limits |    |   |   | `BalanceOf` min_nominator_bond <br/>`BalanceOf` min_validator_bond <br/>`Option<u32>` max_nominator_count <br/>`Option<u32>` max_validator_count <br/>`Option<Percent>` threshold <br/> | 
|chill_other |    | :heavy_check_mark: |   | `AccountId` controller <br/> | 

## Session

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> | 
|purge_keys | :heavy_check_mark:  | :heavy_check_mark: |   |  | 

## Council

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :heavy_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose |    | :heavy_check_mark: |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :heavy_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose |    | :heavy_check_mark: |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 

## Elections

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|vote |    | :heavy_check_mark: |   | `Vec<AccountId>` votes <br/>`Compact<BalanceOf>` value <br/> | 
|remove_voter |    | :heavy_check_mark: |   |  | 
|submit_candidacy |    | :heavy_check_mark: |   | `Compact<u32>` candidate_count <br/> | 
|renounce_candidacy |    |   |   | `Renouncing` renouncing <br/> | 
|remove_member |    | :heavy_check_mark: |   | `LookupSource` who <br/>`bool` has_replacement <br/> | 
|clean_defunct_voters |    | :heavy_check_mark: |   | `u32` _num_voters <br/>`u32` _num_defunct <br/> | 

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|remove_member |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|swap_member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :heavy_check_mark: |   | `Vec<AccountId>` members <br/> | 
|change_key |    | :heavy_check_mark: |   | `AccountId` new <br/> | 
|set_prime |    | :heavy_check_mark: |   | `AccountId` who <br/> | 
|clear_prime |    | :heavy_check_mark: |   |  | 

## Grandpa

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|report_equivocation_unsigned |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|note_stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> | 

## Treasury

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|propose_spend |    | :heavy_check_mark: |   | `Compact<BalanceOf>` value <br/>`LookupSource` beneficiary <br/> | 
|reject_proposal |    | :heavy_check_mark: |   | `Compact<ProposalIndex>` proposal_id <br/> | 
|approve_proposal |    | :heavy_check_mark: |   | `Compact<ProposalIndex>` proposal_id <br/> | 

## Sudo

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|sudo |    | :heavy_check_mark: |   | `Call` call <br/> | 
|sudo_unchecked_weight |    | :heavy_check_mark: |   | `Call` call <br/>`Weight` _weight <br/> | 
|set_key |    | :heavy_check_mark: |   | `LookupSource` new <br/> | 
|sudo_as |    | :heavy_check_mark: |   | `LookupSource` who <br/>`Call` call <br/> | 

## ImOnline

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|heartbeat |    |   |   | `Heartbeat` heartbeat <br/>`Signature` _signature <br/> | 

## AuthorityDiscovery

Empty

## Offences

Empty

## Historical

Empty

## Identity

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_registrar |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|set_identity |    |   |   | `IdentityInfo` info <br/> | 
|set_subs |    |   |   | `Vec<(AccountId,Data)>` subs <br/> | 
|clear_identity |    | :heavy_check_mark: |   |  | 
|request_judgement |    | :heavy_check_mark: |   | `Compact<RegistrarIndex>` reg_index <br/>`Compact<BalanceOf>` max_fee <br/> | 
|cancel_request |    | :heavy_check_mark: |   | `RegistrarIndex` reg_index <br/> | 
|set_fee |    | :heavy_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`Compact<BalanceOf>` fee <br/> | 
|set_account_id |    | :heavy_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`AccountId` new <br/> | 
|set_fields |    |   |   | `Compact<RegistrarIndex>` index <br/>`IdentityFields` fields <br/> | 
|provide_judgement |    |   |   | `Compact<RegistrarIndex>` reg_index <br/>`LookupSource` target <br/>`IdentityJudgement` judgement <br/> | 
|kill_identity |    | :heavy_check_mark: |   | `LookupSource` target <br/> | 
|add_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> | 
|rename_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> | 
|remove_sub |    | :heavy_check_mark: |   | `LookupSource` sub <br/> | 
|quit_sub |    | :heavy_check_mark: |   |  | 

## Recovery

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_recovered |    |   |   | `AccountId` account <br/>`Call` call <br/> | 
|set_recovered |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|create_recovery |    |   |   | `Vec<AccountId>` friends <br/>`u16` threshold <br/>`BlockNumber` delay_period <br/> | 
|initiate_recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|vouch_recovery |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|claim_recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|close_recovery |    | :heavy_check_mark: |   | `AccountId` rescuer <br/> | 
|remove_recovery |    | :heavy_check_mark: |   |  | 
|cancel_recovered |    | :heavy_check_mark: |   | `AccountId` account <br/> | 

## Scheduler

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|schedule |    |   |   | `BlockNumber` when <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> | 
|schedule_named |    |   |   | `Bytes` id <br/>`BlockNumber` when <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|cancel_named |    |   |   | `Bytes` id <br/> | 
|schedule_after |    |   |   | `BlockNumber` after <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|schedule_named_after |    |   |   | `Bytes` id <br/>`BlockNumber` after <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 

## Proxy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 
|add_proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|remove_proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|remove_proxies |    | :heavy_check_mark: |   |  | 
|anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> | 
|kill_anonymous |    | :heavy_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compact<BlockNumber>` height <br/>`Compact<u32>` ext_index <br/> | 
|announce |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|remove_announcement |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|reject_announcement |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> | 
|proxy_announced |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 

## Multisig

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_multi_threshold_1 |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` other_signatories <br/>`Call` call <br/> | 
|as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> | 
|approve_as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`[u8;32]` call_hash <br/>`Weight` max_weight <br/> | 
|cancel_as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Timepoint` timepoint <br/>`[u8;32]` call_hash <br/> | 

## Bounties

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|propose_bounty |    | :heavy_check_mark: |   | `Compact<BalanceOf>` value <br/>`Bytes` description <br/> | 
|approve_bounty |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> | 
|propose_curator |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/>`LookupSource` curator <br/>`Compact<BalanceOf>` fee <br/> | 
|unassign_curator |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> | 
|accept_curator |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> | 
|award_bounty |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/>`LookupSource` beneficiary <br/> | 
|claim_bounty |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> | 
|close_bounty |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/> | 
|extend_bounty_expiry |    | :heavy_check_mark: |   | `Compact<BountyIndex>` bounty_id <br/>`Bytes` _remark <br/> | 

## OrmlVesting

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :heavy_check_mark: |   |  | 
|vested_transfer |    |   |   | `LookupSource` dest <br/>`VestingScheduleOf` schedule <br/> | 
|update_vesting_schedules |    |   |   | `LookupSource` who <br/>`Vec<VestingScheduleOf>` vesting_schedules <br/> | 
|claim_for |    |   |   | `LookupSource` dest <br/> | 

## PDEXMigration

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_migration_operational_status |    | :heavy_check_mark: |   | `bool` status <br/> | 
|set_relayer_status |    | :heavy_check_mark: |   | `AccountId` relayer <br/>`bool` status <br/> | 
|mint |    | :heavy_check_mark: |   | `AccountId` beneficiary <br/>`Balance` amount <br/>`Hash` eth_tx <br/> | 
|unlock |    | :heavy_check_mark: |   |  | 
|remove_minted_tokens |    | :heavy_check_mark: |   | `AccountId` beneficiary <br/> | 

