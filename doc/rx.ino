#define signal_pin A0
int value;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(signal_pin);
  Serial.println(value);
  delay(500);

}
