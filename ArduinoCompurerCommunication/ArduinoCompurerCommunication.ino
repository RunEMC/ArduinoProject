static char endMarker = '\n'; // message separator
static char startMarker = '!'; // message separator
String inputString = "";
boolean stringComplete = false;
//const byte DATA_MAX_SIZE = 32;
//char data[DATA_MAX_SIZE];   // an array to store the received data

void setup() {
  Serial.begin(9600);
  Serial.println(startMarker);
}

void loop() {
  receiveData();
//  Serial.println("Hello from arduino!");
//  delay(1000);
  if (stringComplete) {
    stringComplete = false;
    Serial.println(inputString);
  }
}

void receiveData() {
  char receivedChar;     // read char from serial port
  
  // read while we have data available and we are
  // still receiving the same message.
  while(Serial.available()) {
    receivedChar = (char)Serial.read();
    
    inputString += receivedChar;
    
    if (receivedChar == endMarker) {
        stringComplete = true;
    }
  }
}
