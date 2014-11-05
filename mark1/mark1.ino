
int MOTORSPEED_PIN = 6;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  
  analogWrite(MOTORSPEED_PIN,127);
  digitalWrite(0,LOW);

  digitalWrite(1,HIGH);

  digitalWrite(2,LOW);

  digitalWrite(3,HIGH);  
}

void loop() {
   if (stringComplete) {
    int value = inputString.toInt();
    Serial.println(value);
    analogWrite(MOTORSPEED_PIN,((value % 4) * 64));
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
