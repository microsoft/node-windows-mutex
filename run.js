var CreateMutex = require('./index');

console.log(CreateMutex('ElectronMeetup'));
console.log(CreateMutex('ElectronMeetup'));

setTimeout(null, 1000000);