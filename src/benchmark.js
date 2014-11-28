var jslib = require('libcrypt.js');

var apacheCrypt = require('../lib/apache-crypt');
var res1 = jslib.crypt("passwd", '$5$dd');
var res2 = apacheCrypt("passwd", '$5$dd');

console.log(res1, res2);
if(res1 !== res2) { console.error("JS and native do not match"); process.exit(1); }

var t = new Date().getTime();;
for(i = 0;i < 1000;++i) {  
  jslib.crypt("passwd", '$5$dd');
}
console.log("JS took", (new Date()).getTime() - t);

t = new Date().getTime();;
for(i = 0;i < 1000;++i) {  
  apacheCrypt("passwd", '$5$dd');
}
console.log("Native took", (new Date()).getTime() - t);