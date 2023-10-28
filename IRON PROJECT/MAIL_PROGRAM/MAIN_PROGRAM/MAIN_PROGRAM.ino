//  Sketch: SwitchingThings_04
//
//  An  example of using a single button switch to set multiple states or conditions
//
//  Pins
//  D10 to resister and green LED
//  D9 to resister and yellow LED
//  D8 to resister and red LED
//  D2 to push button switch
//  
//  state holds the current status.
//  0 = all off.
//  1 = green LED
//  2 = yellow LED
//  3 = red LED
 
// Define the pins being used
int pin_LEDgreen = 10;
int pin_LEDyellow = 11;
int pin_LEDred = 8;
int pin_Buzzer = 9;
 
int pin_switch = 2;
int pin_Touch  =3;
 
// variables to hold the new and old switch states
boolean oldSwitchState = LOW;
boolean newSwitchState1 = LOW;
boolean newSwitchState2 = LOW;
boolean newSwitchState3 = LOW;
 
byte state = 0;
int silk_count=0;
 
void setup() 
{
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");
 
    pinMode(pin_LEDgreen, OUTPUT);    digitalWrite(pin_LEDgreen,LOW); 
    pinMode(pin_LEDyellow, OUTPUT);   digitalWrite(pin_LEDyellow,LOW); 
    pinMode(pin_LEDred, OUTPUT);      digitalWrite(pin_LEDred,LOW);
    pinMode(pin_Buzzer, OUTPUT);      digitalWrite(pin_LEDred,LOW); 
 
    pinMode(pin_switch, INPUT); 
    pinMode(pin_Touch, INPUT);
}
 
void loop()
{
   int senseValue = digitalRead(pin_Touch);
  if ((senseValue == HIGH)&& (state!=0)){
 
 
    digitalWrite(pin_Buzzer,HIGH);
    Serial.println("TOUCHED");
    
  
  }

  if ( (state == 1) && (senseValue==LOW)){

        silk_count++;
        if(silk_count>1500){
        digitalWrite(pin_Buzzer,HIGH);
        Serial.println("Silk Over heat");
        silk_count=1501;
        
        }
        Serial.println(silk_count);
    
  }
  else{
      
     digitalWrite(pin_Buzzer,LOW);
     //Serial.println("not touched");
  } 
    
   // END Busser 
    
    
    newSwitchState1 = digitalRead(pin_switch);
    delay(1);
    newSwitchState2 = digitalRead(pin_switch);
    delay(1);
    newSwitchState3 = digitalRead(pin_switch);
 
    // if all 3 values are the same we can continue
    if (  (newSwitchState1==newSwitchState2) && (newSwitchState1==newSwitchState3) )
    {
 
        if ( newSwitchState1 != oldSwitchState ) 
        {
 
           // has the button switch been closed?
           if ( newSwitchState1 == HIGH )
           {
                // increase the value of state
                state++;
                if (state > 3) { state = 0; }
 
                // turn all LEDs off. Doing it this way means we do not need to care about the individual LEDs
                // simply turn them all off and then turn on the correct one. 
                digitalWrite(pin_LEDgreen, LOW);
                digitalWrite(pin_LEDyellow, LOW);
                digitalWrite(pin_LEDred, LOW);
                digitalWrite(pin_Buzzer,LOW);
 
                // Turn on the next LED
                // Because the value of state does not change while we are testing it we don't need to use else if
                if (state==1) { digitalWrite(pin_LEDgreen, HIGH);
                
                
                delay(100);
               
                Serial.println("RED : SILK"); }
                if (state==2) { digitalWrite(pin_LEDyellow, HIGH);
                silk_count=0;
                delay(100);
                Serial.println("BLUE : COTTON"); }
                if (state==3) { digitalWrite(pin_LEDred, HIGH); 
                silk_count=0;
                delay(100);
                Serial.println("GREEN : MAX "); }
 
           }
           oldSwitchState = newSwitchState1;
        }  
    }


}
