//  PROJECT NAME: SMART IRON
//  AUTHOR: SHAN
 
// Define the pins being used

// OUT PUT PINS
int pin_LEDgreen = 8;  int pin_LEDblue = 9;  int pin_LEDred = 10;  int pin_Buzzer = 11;  int pin_power = 12;

//inputa 
int pin_switch = 2;  int pin_Touch  =3;  int pin_tilt  = 4;
 
// variables to hold the new and old switch states
boolean oldSwitchState = LOW;
boolean newSwitchState1 = LOW;
boolean newSwitchState2 = LOW;
boolean newSwitchState3 = LOW;
 
byte state = 0;
int silk_count=0;
int time1; int time2; 
 
void setup() 
{  
    Serial.begin(9600);
    pinMode(pin_LEDgreen, OUTPUT);    digitalWrite(pin_LEDgreen,LOW); 
    pinMode(pin_LEDblue, OUTPUT);     digitalWrite(pin_LEDblue,LOW); 
    pinMode(pin_LEDred, OUTPUT);      digitalWrite(pin_LEDred,LOW);
    pinMode(pin_Buzzer, OUTPUT);      digitalWrite(pin_LEDred,LOW); 
    pinMode(pin_power, OUTPUT);       digitalWrite(pin_power,LOW);
 
    pinMode(pin_switch, INPUT); 
    pinMode(pin_Touch, INPUT);
    pinMode(pin_tilt, INPUT);
}


 
void loop()
{
   int senseValue = digitalRead(pin_Touch);    // this variable for switch
   int tiltValue = digitalRead(pin_tilt);

   
  if (tiltValue==HIGH) 
  {
    time2=0;
    //digitalWrite(pin_Buzzer,LOW);digitalWrite(pin_power,HIGH);
    Serial.println(" NOT TILT");
    Serial.println(time2);
    
   
  if ((senseValue == LOW)&& (state!=0))
  {
    Serial.println(" NOT TOUCHED");
    time1++;
    Serial.println(time1);
    
    if (state==1) 
    {     if (time1>200) { Serial.println(" LOW TIME LIMIT");  Serial.println(time1);  digitalWrite(pin_Buzzer,HIGH); digitalWrite(pin_power,LOW) ;}
    }

     if (state==2) 
    {     if (time1>400) { Serial.println(" MEDIUM TIME LIMIT");  Serial.println(time1);  digitalWrite(pin_Buzzer,HIGH); digitalWrite(pin_power,LOW) ; }
    }

    if (state==3) 
    {     if (time1>800) { Serial.println(" HIGH TIME LIMIT");  Serial.println(time1);  digitalWrite(pin_Buzzer,HIGH);digitalWrite(pin_power,LOW) ; }
    }
    
  }

    else
    {
     time1=0; 
     digitalWrite(pin_Buzzer,LOW); digitalWrite(pin_power,HIGH) ;
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
                digitalWrite(pin_LEDblue, LOW);
                digitalWrite(pin_LEDred, LOW);
                digitalWrite(pin_Buzzer,LOW);
 
                // Turn on the next LED
                // Because the value of state does not change while we are testing it we don't need to use else if
                if (state==1) { digitalWrite(pin_LEDgreen, HIGH);  Serial.println("RED : SILK"); }
                if (state==2) { digitalWrite(pin_LEDblue, HIGH);   Serial.println("BLUE : COTTON"); }
                if (state==3) { digitalWrite(pin_LEDred, HIGH);   Serial.println("GREEN : MAX "); }
                time1=0;
 
           }
           oldSwitchState = newSwitchState1;
        }  
    }

  }

  if(tiltValue==LOW){

    time2++;
    Serial.println(time2);
       if(time2>1600)        // TIlT TIME 1600=8 seconds)
       {
        Serial.println(" TILT"); digitalWrite(pin_Buzzer,HIGH);digitalWrite(pin_power,LOW) ;
    
        }


  }
}
