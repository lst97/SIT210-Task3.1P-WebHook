#include "Adafruit_DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11		// DHT 11 


DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600); 
	Serial.println("DHTxx test!");

	dht.begin();
}

void loop() {
// Wait a few seconds between measurements.
	delay(10000);
	float h = dht.getHumidity();

// Check if any reads failed and exit early (to try again).
	if (isnan(h)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}
	
	Particle.publish("Humidity", String(h), PRIVATE);
	Serial.println("Data Send.");
}

