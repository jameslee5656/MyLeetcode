const path  = require('path');
var pathObj = path.parse(__filename);

console.log(pathObj);
// {
//     root: '/',
//     dir: '/Users/jameslee/program/leetcode/leetcode-code/Interview Problem/node/first-app',
//     base: 'PathModule.js',
//     ext: '.js',
//     name: 'PathModule'
//   }