/** Task & REFERENCES
 Read the temperature from a DHT22 sensor using a particle Argon
 and publish to ThingSpeak via Particle webhook, 
 code put together and modified from the following sources
 
 * https://docs.particle.io/tutorials/device-cloud/webhooks/
 * https://www.electronicwings.com/particle/connecting-dht11-sensor-to-thingspeak-cloud-using-particle-photon
 * https://community.particle.io/t/float-to-string/13599
*/

#include "Adafruit_DHT.h" // Include the Adafruit DHT sensor

DHT dht(D2, DHT22); // Set pin D2 to DHT22 sensor
int led = D7;  // The on-board LED

void setup() {
  pinMode(led, OUTPUT);
  dht.begin(); // begin communication with DHT22 sensor
}

void loop() {
  
  digitalWrite(led, HIGH);   // Turn ON the LED, indicate data send
  float temp = dht.getTempCelcius(); // read temp in degrees celsius
  delay(5000); // wait 5 seconds ... dht22 takes 2 to update reading
  Particle.publish("Temperature", String(temp), PRIVATE);
  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(15000);               // Wait for 30 seconds
}
