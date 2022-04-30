String wordToBlink = "ethan";

//translate phrase to morse
String transToMorse(String phrase)
{
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'}; //alphabet
    String morseCode[26] = {".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
                   "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                   "..-", "...-", ".--", "-..-", "-.--", "--.."}; //letters in morse
                   
    
    
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
void morseToBlink(String phrase, int tickTime = 500, int led = D7) { //default tick time is half a second and default LED is embedded LED
    
    pinMode(led, OUTPUT);
    
    String blinkMorse = transToMorse(phrase); //translate phrase into morse
    
    for (int i = 0; i < blinkMorse.length(); i++) //iterate through morse
    {
        digitalWrite(led, HIGH); //turn on LED
        //dot, 1 tick; dash, 3 ticks;
        if (blinkMorse[i] == '.') 
        {
            delay(tickTime);
        }
        else 
        {
            delay(tickTime*3);
        }
        digitalWrite(led, LOW); //turn off LED
        delay(tickTime); //Wait one tick between morse blinks
    }
}

//Initialise
void setup() {

}

//Loop run on argon
void loop() {
  //dots = 500ms, dash = 1500ms
  morseToBlink(wordToBlink);
  
  delay(3000); //wait 3 seconds
  //repeat
}
