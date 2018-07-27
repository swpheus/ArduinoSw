int buttonPin = 4;
int mod = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonVal = digitalRead(buttonPin);
  Serial.println(buttonVal);
  if (buttonVal == 0) {
    Serial.println(mod);
    if (mod == 0) {
      analogWrite(9, 255); //Red
      delay(500);
      analogWrite(9, 0);
    } else if (mod == 1) {
      analogWrite(10, 255); //Green
      delay(500);
      analogWrite(10, 0);
    } else {
      analogWrite(11, 255); //Red
      delay(500);
      analogWrite(11, 0);
    }
    if (mod >= 2) {
      mod = 0;
    }
    else {
      mod++;
    }
  }

}
