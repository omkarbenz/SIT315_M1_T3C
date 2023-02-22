int ledPin = 9;         // assign the first LED pin number to a variable
int inputPin = 2;       // assign the first PIR sensor input pin number to a variable
int pirState = LOW;     // initialize the first PIR state as LOW (no motion detected)
int ledPin2 = 10;        // assign the second LED pin number to a variable
int inputPin2 = 3;       // assign the second PIR sensor input pin number to a variable
int pirState2 = LOW;     // initialize the second PIR state as LOW (no motion detected)


void setup() {
  pinMode(ledPin, OUTPUT);    // set the first LED pin as an output
  pinMode(inputPin, INPUT);   // set the first PIR sensor pin as an input
  pinMode(ledPin2, OUTPUT);    // set the second LED pin as an output
pinMode(inputPin2, INPUT);   // set the second PIR sensor pin as an input

  Serial.begin(9600);         // initialize serial communication at 9600 baud
  
  attachInterrupt(digitalPinToInterrupt(inputPin), motionDetected, CHANGE); // attach interrupt to detect motion
  attachInterrupt(digitalPinToInterrupt(inputPin2), motionDetected2, CHANGE); // attach interrupt to detect motion

}

void loop() {
  // nothing to do in the loop function
}

void motionDetected() {
  int val = digitalRead(inputPin); // read the first PIR sensor input and store the value in val
  if (val == HIGH) {           // check if motion is detected
    digitalWrite(ledPin, HIGH);  // turn on the first LED
    if (pirState == LOW) {       // check if motion was not detected previously
      Serial.println("Motion detected on first sensor!"); // print message to serial monitor
      pirState = HIGH;          // set the first PIR state to HIGH (motion detected)
    }
  } else {
    digitalWrite(ledPin, LOW);   // turn off the first LED
    if (pirState == HIGH) {       // check if motion was detected previously
      Serial.println("Motion ended on first sensor!");  // print message to serial monitor
      pirState = LOW;           // set the first PIR state to LOW (no motion detected)
    }
  }
  
  motionDetected2();  // call the function to handle motion detection on the second PIR sensor
}


void motionDetected2() {
  int val2 = digitalRead(inputPin2); // read the second PIR sensor input and store the value in val2
  if (val2 == HIGH) {           // check if motion is detected
    digitalWrite(ledPin2, HIGH);  // turn on the second LED
    if (pirState2 == LOW) {       // check if motion was not detected previously
      Serial.println("Motion detected on second sensor!"); // print message to serial monitor
      pirState2 = HIGH;          // set the second PIR state to HIGH (motion detected)
    }
  } else {
    digitalWrite(ledPin2, LOW);   // turn off the second LED
    if (pirState2 == HIGH) {       // check if motion was detected previously
      Serial.println("Motion ended on second sensor!");  // print message to serial monitor
      pirState2 = LOW;           // set the second PIR state to LOW (no motion detected)
    }
  }
}

