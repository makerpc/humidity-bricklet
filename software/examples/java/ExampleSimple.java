import com.tinkerforge.BrickletHumidity;
import com.tinkerforge.IPConnection;

public class ExampleSimple {
	private static final String host = "localhost";
	private static final int port = 4223;
	private static final String UID = "ABC"; // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		// Create connection to brickd
		IPConnection ipcon = new IPConnection(host, port); // Can throw IOException
		BrickletHumidity hum = new BrickletHumidity(UID); // Create device object

		// Add device to IP connection
		ipcon.addDevice(hum); // Can throw IPConnection.TimeoutException
		// Don't use device before it is added to a connection

		// Get current humidity (unit is %RH/10)
		int humidity = hum.getHumidity(); // Can throw IPConnection.TimeoutException

		System.out.println("Relative Humidity: " + humidity/10.0 + " %RH");

		System.console().readLine("Press key to exit\n");
		ipcon.destroy();
	}
}
