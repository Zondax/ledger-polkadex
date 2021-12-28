/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
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
 ******************************************************************************* */

import Zemu, { DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { newPolkadexApp } from '@zondax/ledger-substrate'
import { APP_SEED, models } from './common'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(60000)

beforeAll(async () => {
  await Zemu.checkAndPullImage()
})

async function activateSecretMode(sim: any) {
  // Get to Zondax.ch menu
  for (let i = 0; i < 3; i += 1) {
    await sim.clickRight()
  }

  // Activate secret features
  for (let i = 0; i < 10; i += 1) {
    await sim.clickBoth()
  }

  let reviewSteps = 1

  // Review warning message
  for (let i = 0; i < reviewSteps; i += 1) {
    await sim.clickRight()
  }

  // Accept
  await sim.clickBoth()
}

describe('Standard', function () {
  test.each(models)('main secret menu (%s)', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolkadexApp(sim.getTransport())

      const polkadex_expected_address = 'esqUXfjDQV1P5jPtqrrL6MvF2KFjJWtk45TmVdAHWRGv9Efim'
      const polkadex_expected_pk = 'd05081ebecf4f0c61e7e992696fc6c8b537533630c15642599f3c23f8d6db83d'
      const polkadot_expected_address = 'esqUXfjDQV1P5jPtqrrL6MvF2KFjJWtk45TmVdAHWRGv9Efim'
      const polkadot_expected_pk = 'd05081ebecf4f0c61e7e992696fc6c8b537533630c15642599f3c23f8d6db83d'

      let resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)
      console.log(resp)
      expect(resp.address).toEqual(polkadex_expected_address)
      expect(resp.pubKey).toEqual(polkadex_expected_pk)

      await activateSecretMode(sim)

      resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)
      console.log(resp)
      expect(resp.address).toEqual(polkadot_expected_address)
      expect(resp.pubKey).toEqual(polkadot_expected_pk)
    } finally {
      await sim.close()
    }
  })
})
