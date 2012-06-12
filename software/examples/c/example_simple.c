
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_humidity.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

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

	// Get current humidity (unit is %RH/10)
	uint16_t humidity;
	if(humidity_get_humidity(&h, &humidity) < 0) {
		fprintf(stderr, "Could not get value, probably timeout\n");
		exit(1);
	}

	printf("Relative Humidity: %f %%RH\n", humidity/10.0);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon);
}
