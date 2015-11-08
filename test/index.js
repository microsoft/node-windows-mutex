var assert = require('assert');
var Mutex = require('../').Mutex;

describe('Mutex constructor', function () {
	it('should throw with bad arguments', function () {
		assert.throws(function () {
			new Mutex();
		});
	});
});