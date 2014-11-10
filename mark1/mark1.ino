
int MOTORSPEED_PIN_1 = 3;
int MOTORSPEED_PIN_2 = 9;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  
  setMotorSpeed(127);
  digitalWrite(4,LOW);

  digitalWrite(5,HIGH);

  digitalWrite(11,LOW);

  digitalWrite(10,HIGH);  
}

void loop() {
   if (stringComplete) {
    int value = inputString.toInt();
    Serial.println(value);
    setMotorSpeed(((value % 4) * 64));
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void setMotorSpeed(int motor_speed) {
  analogWrite(MOTORSPEED_PIN_1, motor_speed);
  analogWrite(MOTORSPEED_PIN_2, motor_speed); 
}
