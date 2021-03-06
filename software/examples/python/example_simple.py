#!/usr/bin/env python
# -*- coding: utf-8 -*-  

HOST = "localhost"
PORT = 4223
UID = "ABC" # Change to your UID

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_humidity import Humidity

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    h = Humidity(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Get current humidity (unit is %RH/10)
    rh = h.get_humidity()/10.0

    print('Relative Humidity: ' + str(rh) + ' %RH')

    raw_input('Press key to exit\n') # Use input() in Python 3
    ipcon.disconnect()
