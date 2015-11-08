var assert = require('assert');
var lib = require('../');
var Mutex = lib.Mutex;

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

describe('isActive', function () {
	it('should throw on bad argument', function () {
		assert.throws(function () {
			lib.isActive();
		});
	});
	
	it('should work', function () {
		assert(!lib.isActive("demo-mutex"));
		
		var mutex = new Mutex("demo-mutex");
		assert(mutex.isActive());
		assert(lib.isActive("demo-mutex"));
		
		mutex.release();
		assert(!mutex.isActive());
		assert(!lib.isActive("demo-mutex"));
	});
});