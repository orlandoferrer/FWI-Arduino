/* Analog Read to LED
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13. The amount of time the LED will be on and off depends on
 * the value obtained by analogRead(). In the easiest case we connect
 * a potentiometer to analog pin 2.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */

int potPin = 2;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int potentiometerValue = 0;       // variable to store the value coming from the sensor
int weight = 0;   // convert resistance to weight

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  //Initiate Serial communication.
  Serial.begin(9600);
}

void loop() {
  potentiometerValue = analogRead(potPin);    // read the value from the sensor
  weight = (potentiometerValue * 0.83) + 500;     
  //Serial.println(potentiometerValue);           // print the potentiometer value to console
  Serial.println(weight);
  digitalWrite(ledPin, HIGH);  // turn the ledPin on
  delay(1000);                  // stop the program for some time
  digitalWrite(ledPin, LOW);   // turn the ledPin off
  delay(1000);                  // stop the program for some time
}
