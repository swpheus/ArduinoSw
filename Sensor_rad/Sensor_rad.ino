int trigPin = 7;
int echoPin = 8;
int piezo = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long pulseinTime;
  int cm;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000); //백만 분의 천초 =천분의 1초 1마이크로초 =0.001 밀리초 =0.000001초 입니다.
  digitalWrite(trigPin, LOW);

  pulseinTime = pulseIn(echoPin, HIGH);
  if (pulseinTime < 1) {
    return;
  }
  cm = (pulseinTime / 2) / 29.4;
  if (cm <= 10)
  {
    tone(piezo, 1000, 20);
    delay(20);
    noTone(piezo);
    delay(20 * cm);
  }
  else {
    delay(100);
  }
  Serial.print(cm);
  Serial.println(" cm");
}
