int buttonInput = 2;
int lightOutput = 10;
int buttonState = 0;

void setup() {
    pinMode(lightOutput, OUTPUT);
    pinMode(buttonInput, INPUT);
    digitalWrite(buttonInput, HIGH);
}


void loop() {
    buttonState = digitalRead(buttonInput);
    if (buttonState == HIGH) {
     // digitalWrite(lightOutput, HIGH);
      digitalWrite(lightOutput, LOW);
    } 
    
    else {
      digitalWrite(lightOutput, HIGH);
    }

   
}
