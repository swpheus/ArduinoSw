int sensor_value = 0;
int led_pin = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_value = analogRead(A0);
  Serial.println(sensor_value);

  if (sensor_value < 50)
  {
    digitalWrite(led_pin, HIGH);
  }
  else {
    digitalWrite(led_pin, LOW);
  }
  delay(100);
}
