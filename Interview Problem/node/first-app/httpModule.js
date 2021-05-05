// const http = require('http');
// const server = http.createServer();

// server.on('connection', (socket) =>{
//     console.log('New connection...');
// });
// server.listen(3000);
// console.log('Listen on port 3000....');

// (base) jameslee@James’s-MacBook-Pro first-app % node httpModule.js
// Listen on port 3000....
// New connection...

const http = require('http');
const server = http.createServer((req,res) =>{
    if (req.url === '/'){
        res.write('Hello World');
        res.end();
    }
    if (req.url === '/api/courses'){
        res.write(JSON.stringify([1,2,3]));
        res.end();
    }
});

server.listen(3000);
console.log('Listen on port 3000....');