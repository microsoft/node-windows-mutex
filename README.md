# windows-mutex

[![Build Status](https://dev.azure.com/vscode/node-windows-mutex/_apis/build/status/microsoft.node-windows-mutex?branchName=main)](https://dev.azure.com/vscode/node-windows-mutex/_build/latest?definitionId=23&branchName=main)

[![Build Status](https://dev.azure.com/monacotools/Monaco/_apis/build/status/npm/windows-mutex?repoName=microsoft%2Fnode-windows-mutex&branchName=main)](https://dev.azure.com/monacotools/Monaco/_build/latest?definitionId=464&repoName=microsoft%2Fnode-windows-mutex&branchName=main)

[![npm version](https://badge.fury.io/js/@vscode/windows-mutex.svg)](https://badge.fury.io/js/@vscode/windows-mutex)

Expose the Windows CreateMutex API to Node.JS.

## Installation

`@vscode/windows-mutex` will only compile in Windows machines, so it is advisable
to use the `--save-optional` flag and wrap the
`require('@vscode/windows-mutex')` call in a `try {} catch {}` block, in case your
code also runs on other platforms.

```
npm install --save-optional @vscode/windows-mutex
```

## Usage

```javascript
import { Mutex } from '@vscode/windows-mutex';

var mutex = new Mutex('my-mutex');
console.log(mutex.isActive());
mutex.release();
```

## Development

Publishing to NPM is automated via CI. As soon as a tag is pushed to the repo, that version will be built and published to NPM.