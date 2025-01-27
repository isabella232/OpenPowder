#include <TMC2208Stepper.h> 
#define EN_PIN    4  // LOW: Driver enabled. HIGH: Driver disabled
#define STEP_PIN  3  // Step on rising edge
int sensor= 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);    // Enable driver in hardware
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  
  if (Serial.available() > 0) {
    // read the incoming byte:
    sensor = Serial.read()*6;
    
    // say what you got:
    Serial.print("I received: ");
    Serial.println(sensor, DEC);
    }

  if (sensor<70) {
  digitalWrite(EN_PIN, HIGH);  
  }
  else digitalWrite(EN_PIN, LOW); 
  
  
  digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
  delayMicroseconds(sensor);
  
}
