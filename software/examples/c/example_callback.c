
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_humidity.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

// Callback function for humidity callback (parameter has unit %RH/10)
void cb_humidity(uint16_t humidity) {
	printf("Relative Humidity: %f %%RH\n", humidity/10.0);
}

int main() {
	// Create IP connection to brickd
	IPConnection ipcon;
	if(ipcon_create(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not create connection\n");
		exit(1);
	}

	// Create device object
	Humidity h;
	humidity_create(&h, UID); 

	// Add device to IP connection
	if(ipcon_add_device(&ipcon, &h) < 0) {
		fprintf(stderr, "Could not connect to Bricklet\n");
		exit(1);
	}
	// Don't use device before it is added to a connection

	// Set Period for humidity callback to 1s (1000ms)
	// Note: The callback is only called every second if the 
	//       humidity has changed since the last call!
	humidity_set_humidity_callback_period(&h, 1000);

	// Register humidity callback to function cb_humidity
	humidity_register_callback(&h, HUMIDITY_CALLBACK_HUMIDITY, cb_humidity);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon);
}
