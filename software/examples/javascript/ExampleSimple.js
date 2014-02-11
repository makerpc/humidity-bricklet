var IPConnection = require('Tinkerforge/IPConnection');
var BrickletHumidity = require('Tinkerforge/BrickletHumidity');

var HOST = 'localhost';
var PORT = 4223;
var UID = '7bA'; // Change to your UID

var ipcon = new IPConnection(); // Create IP connection
var h = new BrickletHumidity(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function(error) {
        if(error === IPConnection.ERROR_ALREADY_CONNECTED) {
            console.log('Error: Already connected');        
        }
    }
);// Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(IPConnection.CALLBACK_CONNECTED,
    function(connectReason) {
        // Get current humidity (unit is %RH/10)
        h.getHumidity(
            function(rh) {
                console.log('Relative Humidity: '+rh/10+' %RH');
            },
            function(error) {
                if(error === IPConnection.RESPONSE_TIMED_OUT) {
                  console.log('Error: The request timed out');
                }
            }
        );
    }
);

console.log("Press any key to exit ...");
process.stdin.on('data', function(data) {
	    ipcon.disconnect(
            function(error) {
                if(error === IPConnection.ERROR_NOT_CONNECTED) {
                    console.log('Error: Already disconnected');        
                }
            }
        );
process.exit(0);
});

