# windows-mutex

[![Build Status](https://dev.azure.com/vscode/node-windows-mutex/_apis/build/status/microsoft.node-windows-mutex?branchName=master)](https://dev.azure.com/vscode/node-windows-mutex/_build/latest?definitionId=23&branchName=master)

Expose the Windows CreateMutex API to Node.JS.

## Installation

`windows-mutex` will only compile in Windows machines, so it is advisable
to use the `--save-optional` flag and wrap the
`require('windows-mutex')` call in a `try {} catch {}` block, in case your
code also runs on other platforms.

```
npm install --save-optional windows-mutex
```

## Usage

```javascript
import { Mutex } from 'windows-mutex';

var mutex = new Mutex('my-mutex');
console.log(mutex.isActive());
mutex.release();
```

## Development

Publishing to NPM is automated via CI. As soon as a tag is pushed to the repo, that version will be built and published to NPM.