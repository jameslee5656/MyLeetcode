// Remote login services

const EventEmitter = require('events');
const emitter = new EventEmitter();

class Logger extends EventEmitter {
    // function in a class is a method
    log(message){
    // Send an HTTP request
    console.log(message);
    this.emit('messageLogged', {message : 'The logging event has been called'});
        
    }
}


var url = 'http://mylogger.io/log';
function log(message){
    // Send an HTTP request
    console.log(message);
    emitter.emit('messageLogged', {message : 'The logging event has been called'});
    
}
module.exports = Logger;
// module.exports.url = url;