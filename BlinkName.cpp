String blinkMorse = "";
int led1 = D7; //select embedded LED
int tickTime = 500; //base time for morse blink
String phrase = "ethan"; //ethan : . - .... .- -.

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'}; //alphabet
String morseCode[26] = {".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
                   "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                   "..-", "...-", ".--", "-..-", "-.--", "--.."}; //letters in morse

//translate phrase to morse
String transToMorse(String phrase)
{
    String translation = "";
    for (int i = 0; i < phrase.length(); i++) //iterate through letters of phrase
    {
        for (int j = 0; j < 26; j++) //iterate through alphabet array
        {
            if (phrase[i] == alpha[j]) 
            {
                translation += morseCode[j]; //add morse to translation
                break;
            }
        }
        
    }
    return translation;
}

//blink morse code
void morseToBlink(String blinkMorse) {
    for (int i = 0; i < blinkMorse.length(); i++) 
    {
        digitalWrite(led1, HIGH); //turn on LED
        //dot, 1 tick; dash, 3 ticks;
        if (blinkMorse[i] == '.') 
        {
            delay(tickTime);
        }
        else 
        {
            delay(tickTime*3);
        }
        digitalWrite(led1, LOW); //turn off LED
        delay(tickTime); //Wait wait standard time
    }
}

//Initialise
void setup() {

  pinMode(led1, OUTPUT);
  blinkMorse = transToMorse(phrase);

}

//Loop run on argon
void loop() {
  //dots = 500ms, dash = 1500ms
  morseToBlink(blinkMorse);
  
  delay(3000); //wait 3 seconds
  //repeat
}
