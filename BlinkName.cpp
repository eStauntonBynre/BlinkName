#include <string>
using namespace std;

int led1 = D7; //select embedded LED
int morse[10] = {1,3,1,1,1,1,1,3,3,1}; //ethan : . - .... .- -.
string alpha[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                    "U", "V", "W", "X", "Y", "Z"};
string morseCode = {".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
                   "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                   "..-", "...-", ".--", "-..-", "-.--", "--.."}; //letters in morse

string convertToMorse(string word) {
  string translation = "";
  for (auto &letter : word) {
    for (int i; i < 26; i++) {
      if (alpha[i] == letter) {
        translation += alpha[i]
        break;
      }
    }
  }
  return translation;
}

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
