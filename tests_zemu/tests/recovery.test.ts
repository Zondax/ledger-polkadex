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

  let reviewSteps = 7
  if (sim.startOptions.model === 'nanox') {
    reviewSteps = 6
  }

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

      const polkadex_expected_address = 'JMdbWK5cy3Bm4oCyhWNLQJoC4cczNgJsyk7nLZHMqFT7z7R'
      const polkadex_expected_pk = 'ffbc10f71d63e0da1b9e7ee2eb4037466551dc32b9d4641aafd73a65970fae42'
      const polkadot_expected_address = 'HgG1gzDdu16uEQYpjM2P6DMDVJBfqHtrneNUg476XZxbFnW'
      const polkadot_expected_pk = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'

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
