int xyzPins[] = {27, 26, 25};
float xPos = 0;
float yPos = 0;

void setup(){
  
  Serial.begin(115200);
  pinMode(xyzPins[2], INPUT_PULLUP);  //z axis is a button.
  pinMode(25, INPUT_PULLUP);  //button.
 
}
void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.print(xVal, DEC);
  Serial.print(",");
  Serial.print(yVal, DEC);
  Serial.print(",");
  Serial.print(zVal, DEC);
  Serial.print(",");
  Serial.print("\n");
  delay(100);
}
