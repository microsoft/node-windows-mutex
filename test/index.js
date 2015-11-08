var assert = require('assert');
var Mutex = require('../').Mutex;

describe('Mutex', function () {
	it('constructor should throw with bad arguments', function () {
		assert.throws(function () {
			new Mutex();
		});
	});
	
	it('should release', function () {
		var mutex = new Mutex("demo-mutex");
		mutex.release();
	});
});