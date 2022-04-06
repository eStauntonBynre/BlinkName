int led1 = D7;
int morse[10] = {1,3,1,1,1,1,1,3,3,1}; //ethan : . - .... .- -.

void setup() {

  pinMode(led1, OUTPUT);

}

void loop() {
  //dots = 500ms, dash = 1500ms
  for (int i = 0; i < 10; i++) {
    digitalWrite(led1, HIGH);
    delay(morse[i]*500);
    digitalWrite(led1, LOW);
    delay(500);   
  }
  delay(3000);
}
