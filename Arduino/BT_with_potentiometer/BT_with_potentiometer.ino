// Basic Bluetooth sketch HC-06_01
// Connect the Hc-06 module and communicate using the serial monitor
//
// The HC-06 defaults to AT mode when first powered on.
// The default baud rate is 9600
// The Hc-06 requires all AT commands to be in uppercase. NL+CR should not be added to the command string
//
 
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-06 TX to the Arduino RX on pin 2. 
// Connect the HC-06 RX to the Arduino TX on pin 3 through a voltage divider.
// 
 

int potPin = 2;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int potentiometerValue = 0;       // variable to store the value coming from the sensor
int weight = 0;   // convert resistance to weight
 
void setup() 
{
    Serial.begin(9600);
    //Serial.println("Enter AT commands:");
    pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
    // HC-06 default serial speed is 9600
    BTserial.begin(9600);  
}
 
void loop()
{
 
  potentiometerValue = analogRead(potPin);    // read the value from the sensor
  //weight = (potentiometerValue * 0.83) + 500; 
  BTserial.println(potentiometerValue);
  delay(2000);
 
}
