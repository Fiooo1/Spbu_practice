const WebSocket = require('ws');
const wsServer = new WebSocket.Server({ port: 9000 });

wsServer.on('connection', onConnect);

function onConnect(wsClient) {
    console.log('New user');
    wsClient.send('Hello');

    wsClient.on('close', function() {
        console.log('User disconnected');
    });

    wsClient.on('message', function(message) {
        console.log(message);
        try {
            const jsonMessage = JSON.parse(message);
            switch (jsonMessage.action) {
                case 'ECHO':
                    wsClient.send(jsonMessage.data);
                    break;
                case 'PING':
                    setTimeout(function() {
                        wsClient.send('PONG');
                    }, 2000);
                    break;
                default:
                    console.log('Unknown command');
                    break;
            }
        } catch (error) {
            console.log('Error', error);
        }
    });
}

console.log('Server started at 9000 port');
