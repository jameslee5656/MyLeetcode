(function (exports, require, module, __filename, __dirname){
    
    // Node does not execute the function directly,
    // Instead it wraps it up with function above
    // ==> Module Wrapper Function
})

console.log('Hello World');

function log(message){
    // Send an HTTP request
    console.log(message);
}
module.exports = log;
// module.exports.log = log;    same as above
// exports.log = log;           same as above
// Error
// exports = log;

console.log(__filename);
console.log(__dirname);

// /Users/jameslee/program/leetcode/leetcode-code/Interview Problem/node/first-app/SyntaxError.js
// /Users/jameslee/program/leetcode/leetcode-code/Interview Problem/node/first-app
 
