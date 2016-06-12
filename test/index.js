"use strict";

// Expect module.
import {expect} from 'chai'

// Import source.
import crypt from '../src/index'

// apache-md5 tests.
describe('apache-crypt', function () {
    // Test for valid password.
    it('valid password', function () {
        let encrypted = crypt("validPass", "B5xBYM2HbnPqI");
        expect(encrypted).to.equal("B5xBYM2HbnPqI");
    });

    // Test for invalid password.
    it('invalid password', function () {
        let encrypted = crypt("invalidPass", "B5xBYM2HbnPqI");
        expect(encrypted).to.not.equal("B5xBYM2HbnPqI");
    });
});