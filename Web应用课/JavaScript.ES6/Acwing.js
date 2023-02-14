let fs = require('fs');
let buf = '';

process.stdin.on('readable', function() {
    let chunk = process.stdin.read();
    if (chunk) buf += chunk.toString();
});

process.stdin.on('end', function() {
       
});
