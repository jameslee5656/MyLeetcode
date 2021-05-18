function sayHello(name){
    console.log('Hello ' + name);
}

sayHello('James');
// console.log(window);
// ^

// ReferenceError: window is not defined
//     at Object.<anonymous> (/Users/jameslee/program/leetcode/leetcode-code/Interview Problem/node/first-app/app.js:6:13)
//     at Module._compile (node:internal/modules/cjs/loader:1108:14)
//     at Object.Module._extensions..js (node:internal/modules/cjs/loader:1137:10)
//     at Module.load (node:internal/modules/cjs/loader:973:32)
//     at Function.Module._load (node:internal/modules/cjs/loader:813:14)
//     at Function.executeUserEntryPoint [as runMain] (node:internal/modules/run_main:76:12)


