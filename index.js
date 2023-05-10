const isWindows = process.platform === 'win32';
if (isWindows) {
    module.exports = require('bindings')('CreateMutex');
} else {
    function platformThrow(functionName) {
        throw new Error(`The node-windows-mutex function ${functionName} has only been implemented on Windows.`);
    }
    class Mutex {
        constructor(name) { platformThrow("Mutex#constructor"); }
        isActive() { }
        release() { }
    }
    function isActive(name) { platformThrow("isActive"); }
    module.exports = { Mutex, isActive }
}