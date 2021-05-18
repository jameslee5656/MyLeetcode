// Loading module
var logger = require('./logger'); // same folder
console.log(logger);

logger = 1;
// logger.log('James');
//        ^

// TypeError: logger.log is not a function
//     at Object.<anonymous> (/Users/jameslee/program/leetcode/leetcode-code/Interview Problem/node/first-app/loadingModule.js:7:8)
//     at Module._compile (node:internal/modules/cjs/loader:1108:14)
//     at Object.Module._extensions..js (node:internal/modules/cjs/loader:1137:10)
//     at Module.load (node:internal/modules/cjs/loader:973:32)
//     at Function.Module._load (node:internal/modules/cjs/loader:813:14)
//     at Function.executeUserEntryPoint [as runMain] (node:internal/modules/run_main:76:12)
//     at node:internal/main/run_main_module:17:47
// %        
//  

// To prevent overwrite the variable;
const logger2 = require('./logger'); // same folder
// logger2 = 1;
//         ^

// TypeError: Assignment to constant variable.
//     at Object.<anonymous> (/Users/jameslee/program/leetcode/leetcode-code/Interview Problem/node/first-app/loadingModule.js:22:9)
//     at Module._compile (node:internal/modules/cjs/loader:1108:14)
//     at Object.Module._extensions..js (node:internal/modules/cjs/loader:1137:10)
//     at Module.load (node:internal/modules/cjs/loader:973:32)
//     at Function.Module._load (node:internal/modules/cjs/loader:813:14)
//     at Function.executeUserEntryPoint [as runMain] (node:internal/modules/run_main:76:12)
//     at node:internal/main/run_main_module:17:47
// %     

