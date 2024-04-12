#include <Arduino.h>

const int sensorPowerPin = 13;
const int analogPin = A0;  // Analog input pin
const int digitalPin = 14; // Digital input pin
const int redPin = 4; //red pin
const int yellowPin = 5; //yellow pin
const int greenPin = 16; //green pin
const int pumpPin = 12; //to activate the pump, GPIO12/D6

void setup() {
  Serial.begin(9600);
  pinMode(sensorPowerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);



}

void loop() {
  //turn on the sensor
  digitalWrite(sensorPowerPin, HIGH);
  delay(1000);
  // Read analog value from A0
  int analogValue = analogRead(analogPin);
  // Read digital value from GPIO14
  int digitalValue = digitalRead(digitalPin);

  if(digitalValue==1) {
    //Turn on red light
    digitalWrite(redPin, HIGH);
    // Turn on yellow light and pump for 2 seconds
    digitalWrite(yellowPin, HIGH);
    
    

  } else {
    //Turn on green light, ground is humid
    digitalWrite(greenPin, HIGH);
  }


  // Print the read values to the serial monitor
  Serial.print("Analog Value: ");
  Serial.println(analogValue);
  
  Serial.print("Digital Value: ");
  Serial.println(digitalValue);

  delay(2000);

//turn off the sensor
digitalWrite(redPin, LOW);
digitalWrite(yellowPin, LOW);
digitalWrite(greenPin, LOW);

digitalWrite(sensorPowerPin, LOW);
delay(2000);
}

