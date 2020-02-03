"use strict";

// Expect module.
const expect = require("chai").expect;

// Import source.
const crypt = require("../src/index");

// apache-md5 tests.
describe("apache-crypt", () => {
  // Test for valid password.
  it("valid password", () => {
    const encrypted = crypt("validPass", "B5xBYM2HbnPqI");
    expect(encrypted).to.equal("B5xBYM2HbnPqI");
  });

  // Test for invalid password.
  it("invalid password", () => {
    const encrypted = crypt("invalidPass", "B5xBYM2HbnPqI");
    expect(encrypted).to.not.equal("B5xBYM2HbnPqI");
  });
});
