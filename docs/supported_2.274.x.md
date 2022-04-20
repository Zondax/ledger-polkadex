# Polkadex  2.274.x

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
|Submit unsigned |    |   |   | `BoxRawSolutionSolutionOfT` raw_solution <br/>`SolutionOrSnapshotSize` witness <br/> |
|Set minimum untrusted score |    |   |   | `OptionElectionScore` maybe_next_score <br/> |
|Set emergency election result |    |   |   | `SupportsAccountId` supports <br/> |
|Submit |    |   |   | `BoxRawSolutionSolutionOfT` raw_solution <br/>`u32` num_signed_submissions <br/> |

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
|Cancel deferred slash |    |   |   | `EraIndex` era <br/>`Bytes` slash_indices <br/> |
|Payout stakers | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> |
|Rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> |
|Set history depth |    | :heavy_check_mark: |   | `Compactu32` new_history_depth <br/>`Compactu32` era_items_deleted <br/> |
|Reap stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Kick |    | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` who <br/> |
|Set staking limits |    |   |   | `Balance` min_nominator_bond <br/>`Balance` min_validator_bond <br/>`Optionu32` max_nominator_count <br/>`Optionu32` max_validator_count <br/>`OptionPercent` threshold <br/> |
|Chill other |    | :heavy_check_mark: |   | `AccountId` controller <br/> |

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
|Remove member |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`bool` has_replacement <br/> |
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
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |
|Cancel named |    |   |   | `Vecu8` id <br/> |
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |

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

## Contracts

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Call |    |   |   | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/>`Compactu64` gas_limit <br/>`Vecu8` data <br/> |
|Instantiate with code |    |   |   | `CompactBalance` endowment <br/>`Compactu64` gas_limit <br/>`Vecu8` code <br/>`Vecu8` data <br/>`Vecu8` salt <br/> |
|Instantiate |    |   |   | `CompactBalance` endowment <br/>`Compactu64` gas_limit <br/>`CodeHashT` code_hash <br/>`Bytes` data <br/>`Bytes` salt <br/> |

## Currencies

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer |    |   |   | `LookupasStaticLookupSource` dest <br/>`CurrencyId` currency_id <br/>`Compactu128` amount <br/> |
|Transfer native currency |    |   |   | `LookupasStaticLookupSource` dest <br/>`Compactu128` amount <br/> |
|Update balance |    |   |   | `LookupasStaticLookupSource` who <br/>`CurrencyId` currency_id <br/>`Amount` amount <br/> |

## PolkadexIdo

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Register investor |    |   |   |  |
|Investor unlock fund |    |   |   |  |
|Attest investor |    |   |   | `AccountId` investor <br/>`KYCStatus` kyc_status <br/> |
|Register round |    |   |   | `Vecu8` cid <br/>`OptionAssetId` token_a <br/>`Balance` amount <br/>`AssetId` token_b <br/>`Balance` vesting_per_block <br/>`BlockNumber` funding_period <br/>`Balance` min_allocation <br/>`Balance` max_allocation <br/>`Balance` token_a_priceper_token_b <br/> |
|Whitelist investor |    |   |   | `Hash` round_id <br/>`AccountId` investor_address <br/>`Balance` amount <br/> |
|Claim tokens |    |   |   | `Hash` round_id <br/> |
|Show interest in round |    |   |   | `Hash` round_id <br/>`Balance` amount <br/> |
|Withdraw raise |    |   |   | `Hash` round_id <br/>`AccountId` beneficiary <br/> |
|Vote |    |   |   | `Hash` round_id <br/>`Balance` amount <br/>`u8` vote_multiplier <br/>`bool` approve <br/> |
|Set vote period |    |   |   | `BlockNumber` period <br/> |
|Set investor lock fund period |    |   |   | `BlockNumber` period <br/> |
|Approve ido round |    |   |   | `Hash` round_id <br/> |
|Withdraw token |    |   |   | `Hash` round_id <br/>`AccountId` beneficiary <br/> |

## Thea

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Submit keygen message |    |   |   | `TheaPayloadTheaIdKeygenRound` payload <br/>`TheaIdasRuntimeAppPublicSignature` signature <br/>`u64` rng <br/> |
|Clean keygen messages |    |   |   | `AuthorityIndex` auth_idx <br/>`TheaIdasRuntimeAppPublicSignature` signature <br/>`u64` rng <br/> |
|Submit offline message |    |   |   | `TheaPayloadTheaIdOfflineStageRound` payload <br/>`H256` payload_array <br/>`TheaIdasRuntimeAppPublicSignature` signature <br/>`u64` rng <br/> |
|Submit signing message |    |   |   | `BlockNumber` at <br/>`SigningSessionPayloadTheaId` payload <br/>`TheaIdasRuntimeAppPublicSignature` signature <br/>`u64` rng <br/> |
|Submit signed payload |    |   |   | `SignedTheaPayload` payload <br/>`u64` rng <br/> |
|Submit ecdsa public key |    |   |   | `thea_primitivesValidatorSetId` set_id <br/>`Public` public_key <br/> |
|Register deposit address |    |   |   |  |
|Register offense |    |   |   | `OffenseReportAccountIdKeygenRound` offence <br/> |

## Ethereum

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create asset |    |   |   | `H160` asset <br/> |
|Transfer claim |    |   |   | `H256` transaction_hash <br/>`u64` ethereum_block_no <br/>`Vecu8` signature <br/>`Vecu8` public_key_bytes <br/>`H160` asset <br/>`Tasframe_systemConfigAccountId` pdex_address <br/>`Balance` amount <br/> |
|Submit new ethereum block |    |   |   | `EthereumBlockWithApprovalsEthereumId` block <br/>`EthereumIdasRuntimeAppPublicSignature` signature <br/> |
|Submit unprocessed ethereum block |    |   |   | `BoxUnprocessedEthereumBlock` block <br/> |
|Withdraw |    |   |   | `H160` token_id <br/>`Balance` amount <br/>`H160` recipient <br/> |

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
|Cancel approval |    | :heavy_check_mark: |   | `Compactu128` id <br/>`LookupasStaticLookupSource` delegate <br/> |
|Force cancel approval |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` delegate <br/> |
|Transfer approved |    |   |   | `Compactu128` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` destination <br/>`Compactu128` amount <br/> |

## BagsList

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Rebag |    | :heavy_check_mark: |   | `AccountId` dislocated <br/> |

## TokenFaucet

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Credit account with tokens unsigned |    | :heavy_check_mark: |   | `AccountId` account <br/> |

