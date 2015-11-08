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
		assert(mutex.release());
	});
	
	it('should release twice successfully', function () {
		var mutex = new Mutex("demo-mutex");
		assert(mutex.release());
		assert(!mutex.release());
	});
	
	describe('isActive', function () {
		it('should work', function () {
			var mutex = new Mutex("demo-mutex");
			assert(mutex.isActive());
			mutex.release();
			assert(!mutex.isActive());
		});
	});
});