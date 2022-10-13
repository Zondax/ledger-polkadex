# Ledger Polkadex App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-polkadex/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-polkadex/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Polkadex app (https://www.polkadex.trade/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
# Polkadex  2.277.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> |
|Remark |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |
|Set heap pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> |
|Set code |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set code without checks |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set storage |    |   |   | `VecKeyValue` items <br/> |
|Kill storage |    |   |   | `VecKey` keys <br/> |
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> |
|Remark with event |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |

## Utility

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> |
|Batch all | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> |
|Force batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |

## Babe

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHeader` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHeader` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Plan config change |    |   |   | `NextConfigDescriptor` config <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `Compactu64` now <br/> |

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> |

## Indices

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   | `AccountIndex` index <br/> |
|Transfer |    | :heavy_check_mark: |   | `AccountId` new_ <br/>`AccountIndex` index <br/> |
|Free |    | :heavy_check_mark: |   | `AccountIndex` index <br/> |
|Force transfer |    | :heavy_check_mark: |   | `AccountId` new_ <br/>`AccountIndex` index <br/>`bool` freeze <br/> |
|Freeze |    | :heavy_check_mark: |   | `AccountIndex` index <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> |
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> |
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> |

## ElectionProviderMultiPhase

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Submit unsigned |    |   |   | `BoxRawSolutionSolutionOfMinerConfig` raw_solution <br/>`SolutionOrSnapshotSize` witness <br/> |
|Set minimum untrusted score |    |   |   | `OptionElectionScore` maybe_next_score <br/> |
|Set emergency election result |    |   |   | `SupportsAccountId` supports <br/> |
|Submit |    |   |   | `BoxRawSolutionSolutionOfMinerConfig` raw_solution <br/> |
|Governance fallback |    |   |   | `Optionu32` maybe_max_voters <br/>`Optionu32` maybe_max_targets <br/> |

## Staking

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bond | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/>`CompactBalance` amount <br/>`RewardDestination` payee <br/> |
|Bond extra | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> |
|Unbond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> |
|Withdraw Unbonded | :heavy_check_mark:  | :heavy_check_mark: |   | `u32` num_slashing_spans <br/> |
|Validate | :heavy_check_mark:  | :heavy_check_mark: |   | `ValidatorPrefs` prefs <br/> |
|Nominate | :heavy_check_mark:  | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` targets <br/> |
|Chill | :heavy_check_mark:  | :heavy_check_mark: |   |  |
|Set payee | :heavy_check_mark:  | :heavy_check_mark: |   | `RewardDestination` payee <br/> |
|Set controller | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/> |
|Set validator count |    | :heavy_check_mark: |   | `Compactu32` new_ <br/> |
|Increase validator count |    | :heavy_check_mark: |   | `Compactu32` additional <br/> |
|Scale validator count |    |   |   | `Percent` factor <br/> |
|Force no eras |    | :heavy_check_mark: |   |  |
|Force new era |    | :heavy_check_mark: |   |  |
|Set invulnerables |    | :heavy_check_mark: |   | `VecAccountId` invulnerables <br/> |
|Force unstake |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Force new era always |    | :heavy_check_mark: |   |  |
|Cancel deferred slash |    | :heavy_check_mark: |   | `EraIndex` era <br/>`Vecu32` slash_indices <br/> |
|Payout stakers | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> |
|Rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> |
|Set history depth |    | :heavy_check_mark: |   | `Compactu32` new_history_depth <br/>`Compactu32` era_items_deleted <br/> |
|Reap stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Kick |    | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` who <br/> |
|Set staking configs |    | :heavy_check_mark: |   | `ConfigOpBalanceOfT` min_nominator_bond <br/>`ConfigOpBalanceOfT` min_validator_bond <br/>`ConfigOpu32` max_nominator_count <br/>`ConfigOpu32` max_validator_count <br/>`ConfigOpPercent` chill_threshold <br/>`ConfigOpPerbill` min_commission <br/> |
|Chill other |    | :heavy_check_mark: |   | `AccountId` controller <br/> |
|Force apply min commission |    | :heavy_check_mark: |   | `AccountId` validator_stash <br/> |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  |

## Council

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    | :heavy_check_mark: |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    | :heavy_check_mark: |   | `Compactu32` threshold <br/>`Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    | :heavy_check_mark: |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    | :heavy_check_mark: |   | `Compactu32` threshold <br/>`Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |

## Elections

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vote |    | :heavy_check_mark: |   | `VecAccountId` votes <br/>`Compactu128` amount <br/> |
|Remove voter |    | :heavy_check_mark: |   |  |
|Submit candidacy |    | :heavy_check_mark: |   | `Compactu32` candidate_count <br/> |
|Renounce candidacy |    |   |   | `Renouncing` renouncing <br/> |
|Remove member |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`bool` slash_bond <br/>`bool` rerun_election <br/> |
|Clean defunct voters |    | :heavy_check_mark: |   | `u32` num_voters <br/>`u32` num_defunct <br/> |

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## Grandpa

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Note stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> |

## Treasury

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Reject proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |
|Approve proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |
|Spend |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Remove approval |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |

## Sudo

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Sudo |    | :heavy_check_mark: |   | `Call` call <br/> |
|Sudo unchecked weight |    | :heavy_check_mark: |   | `Call` call <br/>`Weight` weight <br/> |
|Set key |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` new_ <br/> |
|Sudo as |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Call` call <br/> |

## ImOnline

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Heartbeat |    |   |   | `HeartbeatBlockNumber` heartbeat <br/>`AuthorityIdasRuntimeAppPublicSignature` signature <br/> |

## Identity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add registrar |    | :heavy_check_mark: |   | `AccountId` account <br/> |
|Set identity |    |   |   | `BoxIdentityInfoMaxAdditionalFields` info <br/> |
|Set subs |    |   |   | `VecTupleAccountIdData` subs <br/> |
|Clear identity |    | :heavy_check_mark: |   |  |
|Request judgement |    | :heavy_check_mark: |   | `Compactu32` reg_index <br/>`Compactu128` max_fee <br/> |
|Cancel request |    | :heavy_check_mark: |   | `RegistrarIndex` reg_index <br/> |
|Set fee |    | :heavy_check_mark: |   | `Compactu32` index <br/>`Compactu128` fee <br/> |
|Set account id |    | :heavy_check_mark: |   | `Compactu32` index <br/>`AccountId` new_ <br/> |
|Set fields |    |   |   | `Compactu32` index <br/>`IdentityFields` fields <br/> |
|Provide judgement |    |   |   | `Compactu32` reg_index <br/>`LookupasStaticLookupSource` target <br/>`JudgementBalanceOfT` judgement <br/> |
|Kill identity |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> |
|Add sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Rename sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Remove sub |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` sub <br/> |
|Quit sub |    | :heavy_check_mark: |   |  |

## Recovery

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As recovered |    |   |   | `AccountId` account <br/>`Call` call <br/> |
|Set recovered |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> |
|Create recovery |    |   |   | `VecAccountId` friends <br/>`u16` threshold <br/>`BlockNumber` delay_period <br/> |
|Initiate recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> |
|Vouch recovery |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> |
|Claim recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> |
|Close recovery |    | :heavy_check_mark: |   | `AccountId` rescuer <br/> |
|Remove recovery |    | :heavy_check_mark: |   |  |
|Cancel recovered |    | :heavy_check_mark: |   | `AccountId` account <br/> |

## Scheduler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel named |    |   |   | `Vecu8` id <br/> |
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |

## Proxy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |
|Add proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxies |    | :heavy_check_mark: |   |  |
|Anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> |
|Kill anonymous |    | :heavy_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compactu32` height <br/>`Compactu32` ext_index <br/> |
|Announce |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|Remove announcement |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|Reject announcement |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> |
|Proxy announced |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |

## Multisig

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId` other_signatories <br/>`Call` call <br/> |
|As multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|Approve as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> |
|Cancel as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> |

## Bounties

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose bounty |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`Bytes` description <br/> |
|Approve bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Propose curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`LookupasStaticLookupSource` curator <br/>`CompactBalance` fee <br/> |
|Unassign curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Accept curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Award bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Claim bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Close bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Extend bounty expiry |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`Bytes` remark <br/> |

## OrmlVesting

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    |   |   |  |
|Vested transfer |    |   |   | `LookupasStaticLookupSource` dest <br/>`VestingScheduleOf` schedule <br/> |
|Update vesting schedules |    |   |   | `LookupasStaticLookupSource` who <br/>`VecVestingScheduleOf` vesting_schedules <br/> |
|Claim for |    |   |   | `LookupasStaticLookupSource` dest <br/> |

## PDEXMigration

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set migration operational status |    |   |   | `bool` status <br/> |
|Set relayer status |    |   |   | `AccountId` relayer <br/>`bool` status <br/> |
|Mint |    |   |   | `AccountId` beneficiary <br/>`Balance` amount <br/>`Hash` eth_tx <br/> |
|Unlock |    |   |   |  |
|Remove minted tokens |    |   |   | `AccountId` beneficiary <br/> |

## Democracy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose |    |   |   | `Hash` proposal_hash <br/>`CompactBalance` amount <br/> |
|Second |    |   |   | `Compactu32` proposal <br/>`Compactu32` seconds_upper_bound <br/> |
|Vote |    |   |   | `Compactu32` ref_index <br/>`AccountVote` vote <br/> |
|Emergency cancel |    |   |   | `ReferendumIndex` ref_index <br/> |
|External propose |    |   |   | `Hash` proposal_hash <br/> |
|External propose majority |    |   |   | `Hash` proposal_hash <br/> |
|External propose default |    |   |   | `Hash` proposal_hash <br/> |
|Fast track |    |   |   | `Hash` proposal_hash <br/>`BlockNumber` voting_period <br/>`BlockNumber` delay <br/> |
|Veto external |    |   |   | `Hash` proposal_hash <br/> |
|Cancel referendum |    |   |   | `Compactu32` ref_index <br/> |
|Cancel queued |    |   |   | `ReferendumIndex` which <br/> |
|Delegate |    |   |   | `AccountId` to <br/>`Conviction` conviction <br/>`Balance` balance <br/> |
|Undelegate |    |   |   |  |
|Clear public proposals |    |   |   |  |
|Note preimage |    |   |   | `Bytes` encoded_proposal <br/> |
|Note preimage operational |    |   |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage |    |   |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage operational |    |   |   | `Bytes` encoded_proposal <br/> |
|Reap preimage |    |   |   | `Hash` proposal_hash <br/>`Compactu32` proposal_len_upper_bound <br/> |
|Unlock |    |   |   | `AccountId` target <br/> |
|Remove vote |    |   |   | `ReferendumIndex` index <br/> |
|Remove other vote |    |   |   | `AccountId` target <br/>`ReferendumIndex` index <br/> |
|Enact proposal |    |   |   | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> |
|Blacklist |    |   |   | `Hash` proposal_hash <br/>`OptionReferendumIndex` maybe_ref_index <br/> |
|Cancel proposal |    |   |   | `Compactu32` prop_index <br/> |

## Preimage

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Note preimage |    |   |   | `Vecu8` bytes <br/> |
|Unnote preimage |    |   |   | `Hash` hash <br/> |
|Request preimage |    |   |   | `Hash` hash <br/> |
|Unrequest preimage |    |   |   | `Hash` hash <br/> |

## ChildBounties

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add child bounty |    |   |   | `Compactu32` parent_bounty_id <br/>`CompactBalance` amount <br/>`Vecu8` description <br/> |
|Propose curator |    |   |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/>`LookupasStaticLookupSource` curator <br/>`CompactBalance` fee <br/> |
|Accept curator |    |   |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/> |
|Unassign curator |    |   |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/> |
|Award child bounty |    |   |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Claim child bounty |    |   |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/> |
|Close child bounty |    |   |   | `Compactu32` parent_bounty_id <br/>`Compactu32` child_bounty_id <br/> |

## Assets

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` admin <br/>`Balance` min_balance <br/> |
|Force create |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` owner <br/>`bool` is_sufficient <br/>`Compactu128` min_balance <br/> |
|Destroy |    |   |   | `Compactu128` id <br/>`DestroyWitness` witness <br/> |
|Mint |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` beneficiary <br/>`Compactu128` amount <br/> |
|Burn |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` who <br/>`Compactu128` amount <br/> |
|Transfer |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` target <br/>`Compactu128` amount <br/> |
|Transfer keep alive |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` target <br/>`Compactu128` amount <br/> |
|Force transfer |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`Compactu128` amount <br/> |
|Freeze |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` who <br/> |
|Thaw |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` who <br/> |
|Freeze asset |    |   |   | `Compactu128` id <br/> |
|Thaw asset |    |   |   | `Compactu128` id <br/> |
|Transfer ownership |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` owner <br/> |
|Set team |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/> |
|Set metadata |    |   |   | `Compactu128` id <br/>`Vecu8` name <br/>`Vecu8` symbol <br/>`u8` decimals <br/> |
|Clear metadata |    |   |   | `Compactu128` id <br/> |
|Force set metadata |    |   |   | `Compactu128` id <br/>`Vecu8` name <br/>`Vecu8` symbol <br/>`u8` decimals <br/>`bool` is_frozen <br/> |
|Force clear metadata |    |   |   | `Compactu128` id <br/> |
|Force asset status |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/>`Compactu128` min_balance <br/>`bool` is_sufficient <br/>`bool` is_frozen <br/> |
|Approve transfer |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` delegate <br/>`Compactu128` amount <br/> |
|Cancel approval |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` delegate <br/> |
|Force cancel approval |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` delegate <br/> |
|Transfer approved |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` destination <br/>`Compactu128` amount <br/> |
|Touch |    |   |   | `Compactu128` id <br/> |
|Refund |    |   |   | `Compactu128` id <br/>`bool` allow_burn <br/> |

## OCEX

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Register main account |    |   |   | `AccountId` proxy <br/> |
|Add proxy account |    |   |   | `AccountId` proxy <br/> |
|Close trading pair |    |   |   | `AssetId` base <br/>`AssetId` quote <br/> |
|Open trading pair |    |   |   | `AssetId` base <br/>`AssetId` quote <br/> |
|Register trading pair |    |   |   | `AssetId` base <br/>`AssetId` quote <br/>`Balance` min_order_price <br/>`Balance` max_order_price <br/>`Balance` min_order_qty <br/>`Balance` max_order_qty <br/>`Balance` price_tick_size <br/>`Balance` qty_step_size <br/> |
|Update trading pair |    |   |   | `AssetId` base <br/>`AssetId` quote <br/>`Balance` min_order_price <br/>`Balance` max_order_price <br/>`Balance` min_order_qty <br/>`Balance` max_order_qty <br/>`Balance` price_tick_size <br/>`Balance` qty_step_size <br/> |
|Deposit |    |   |   | `AssetId` asset <br/>`Balance` amount <br/> |
|Remove proxy account |    |   |   | `AccountId` proxy <br/> |
|Submit snapshot |    |   |   | `EnclaveSnapshotAccountIdWithdrawalLimitAssetsLimitSnapshotAccLimit` snapshot <br/>`Signature` signature <br/> |
|Insert enclave |    |   |   | `AccountId` encalve <br/> |
|Collect fees |    |   |   | `u32` snapshot_id <br/>`AccountId` beneficiary <br/> |
|Shutdown |    |   |   |  |
|Set exchange state |    |   |   | `bool` state <br/> |
|Set balances |    |   |   | `BoundedVecpolkadex_primitivesingressHandleBalanceAccountIdpolkadex_primitivesingressHandleBalanceLimit` change_in_balances <br/> |
|Claim withdraw |    |   |   | `u32` snapshot_id <br/>`AccountId` account <br/> |
|Register enclave |    |   |   | `Vecu8` ias_report <br/> |
|Allowlist token |    |   |   | `AssetId` token_add <br/> |
|Remove allowlisted token |    |   |   | `AssetId` token <br/> |
|Allowlist enclave |    |   |   | `AccountId` enclave_account_id <br/> |
|Update certificate |    |   |   | `u64` certificate_valid_until <br/> |

## OrderbookCommittee

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    |   |   | `Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    |   |   | `Compactu32` threshold <br/>`Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    |   |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    |   |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    |   |   | `Hash` proposal_hash <br/> |

## ChainBridge

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set threshold |    |   |   | `u32` threshold <br/> |
|Set resource |    |   |   | `H256` id <br/>`Vecu8` method <br/> |
|Remove resource |    |   |   | `H256` id <br/> |
|Allowlist chain |    |   |   | `BridgeChainId` id <br/> |
|Add relayer |    |   |   | `AccountId` v <br/> |
|Remove relayer |    |   |   | `AccountId` v <br/> |
|Acknowledge proposal |    |   |   | `DepositNonce` nonce <br/>`BridgeChainId` src_id <br/>`H256` r_id <br/>`BoxTasConfigProposal` call <br/> |
|Reject proposal |    |   |   | `DepositNonce` nonce <br/>`BridgeChainId` src_id <br/>`H256` r_id <br/>`BoxTasConfigProposal` call <br/> |
|Eval vote state |    |   |   | `DepositNonce` nonce <br/>`BridgeChainId` src_id <br/>`BoxTasConfigProposal` prop <br/> |

## AssetHandler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create asset |    |   |   | `BridgeChainId` chain_id <br/>`H160` contract_add <br/> |
|Mint asset |    |   |   | `Vecu8` destination_add <br/>`u128` amount <br/>`H256` rid <br/> |
|Set bridge status |    |   |   | `bool` status <br/> |
|Set block delay |    |   |   | `BlockNumber` no_of_blocks <br/> |
|Withdraw |    |   |   | `BridgeChainId` chain_id <br/>`H160` contract_add <br/>`Balance` amount <br/>`H160` recipient <br/> |
|Update fee |    |   |   | `BridgeChainId` chain_id <br/>`Balance` min_fee <br/>`u32` fee_scale <br/> |
|Allowlist token |    |   |   | `H160` token_add <br/> |
|Remove allowlisted token |    |   |   | `H160` token_add <br/> |

