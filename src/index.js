"use strict";

// Des module.
import des from 'unix-crypt-td-js'

// Hash generation string.
const itoa64 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

// Salt generation method.
function getSalt() {
    return itoa64[ parseInt(Math.random() * 64) ] +
           itoa64[ parseInt(Math.random() * 64) ];
}

// Exporting old style.
module.exports = function(password, salt) {
    return salt ? des(password, salt) : des(password, getSalt());
};
