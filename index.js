const http  = require('http');

const port = process.env.PORT || 80;

http.createServer(function (req, res) {
    res.end("Hello!");
}).listen(port);
