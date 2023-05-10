/*global describe,it*/

const assert = require('assert');
const lib = require('../');
const Mutex = lib.Mutex;
const isWindows = process.platform === 'win32';

describe('Mutex', function () {
	it('constructor should throw with bad arguments', function () {
		assert.throws(function () {
			new Mutex();
		});
	});
	
	if (isWindows) {
		it('should release', function () {
			const mutex = new Mutex("demo-mutex");
			assert(mutex.release());
		});
		
		it('should release twice successfully', function () {
			const mutex = new Mutex("demo-mutex");
			assert(mutex.release());
			assert(!mutex.release());
		});
		
		describe('isActive', function () {
			it('should work', function () {
				const mutex = new Mutex("demo-mutex");
				assert(mutex.isActive());
				mutex.release();
				assert(!mutex.isActive());
			});
		});
	} else {
		it('should throw', function () {
			assert.throws(function () {
				new Mutex("demo-mutex");
			});
		});
	}
});

describe('isActive', function () {
	it('should throw on bad argument', function () {
		assert.throws(function () {
			lib.isActive();
		});
	});
	
	if (isWindows) {
		it('should work', function () {
			assert(!lib.isActive("demo-mutex"));
			
			const mutex = new Mutex("demo-mutex");
			assert(mutex.isActive());
			assert(lib.isActive("demo-mutex"));
			
			mutex.release();
			assert(!mutex.isActive());
			assert(!lib.isActive("demo-mutex"));
		});
	} else {
		it('should throw', function () {
			assert.throws(function () {
				lib.isActive("demo-mutex");
			})
		});
	}
});