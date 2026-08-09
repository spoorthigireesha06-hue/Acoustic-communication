#define TX_PIN 11
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("TX ready");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Sending: 0(2khz)");
  tone(TX_PIN,2000);
  delay(3000);

  noTone(TX_PIN);
  delay(500);

  Serial.println("Sending: 1(3khz)");
  tone(TX_PIN,3000);
  delay(3000);
  
  noTone(TX_PIN);
  delay(500);

}
