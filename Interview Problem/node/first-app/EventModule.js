const EventEmitter = require('events');
const emitter = new EventEmitter();

// Register a listener
emitter.on('messagelogged', function(){
    console.log("message 1 is logged");
});

// Making a noise, produce a signal
// Raise an event
emitter.emit('messagelogged');


// Register a listener
// Nothing will happended here
emitter.on('messagelogged', function(){
    console.log("message 2 is logged");
});


emitter.on('messagelogged', function(arg){ // e, eventArg
    console.log("message 3 is logged", arg);
});
emitter.emit('messagelogged', {id: 1, url: 'http://test.org'});
// Result:
// message 1 is logged
// message 1 is logged
// message 2 is logged
// message 3 is logged { id: 1, url: 'http://test.org' }

// Practice
emitter.on('logging', function(message){ // e, eventArg
    console.log(message);
});
emitter.emit('logging', {message : 'This is a practice'});


emitter.on('messageLogged', function(arg){ // e, eventArg
    console.log("message 3 is logged", arg);
});



const log = require('./logger');
// log('message');

const Logger = require('./logger');
const logger = new Logger();

logger.on('messageLogged', (arg) =>{
    console.log('Listener is called', arg);
});

logger.log('test message');


