int led1 = D7; //select embedded LED
int morse[10] = {1,3,1,1,1,1,1,3,3,1}; //ethan : . - .... .- -.

//Initialise
void setup() {

  pinMode(led1, OUTPUT);

}

//Loop run on argon
void loop() {
  //dots = 500ms, dash = 1500ms
  for (int i = 0; i < 10; i++) { //iterate through morse[]
    digitalWrite(led1, HIGH); //turn on LED
    delay(morse[i]*500); //wait 500*i miliseconds
    digitalWrite(led1, LOW); //turn off LED
    delay(500); //Wait 500 miliseconds   
  }
  delay(3000); //wait 3 seconds
  //repeat
}
