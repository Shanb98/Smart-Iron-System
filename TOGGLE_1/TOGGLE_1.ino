const int tiltPin = 7;     // the number of the tilt switch pin
const int ledPin =  10;      // the number of the LED pin
 
// variables will change:
int tiltState = 0;         // variable for reading the tilt switch status
 
void setup() 
{
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the tilt switch pin as an input:
  pinMode(tiltPin, INPUT);
 // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(10, OUTPUT);  
  pinMode(13, INPUT);
  pinMode(9, OUTPUT);
  pinMode(7, INPUT); 
}
 
void loop() 
{
  // read the state of the tilt switch value:
  tiltState = digitalRead(tiltPin);
 int senseValue = digitalRead(13);
  // check if the tilt switch is activated.
  // if it is, the tiltState is HIGH:
  if (tiltState == HIGH) 
  (senseValue == HIGH);
  digitalWrite(10, HIGH);
    digitalWrite(9,LOW);
    Serial.println("TOUCHED");
     delay(5000);
   digitalWrite(13, HIGH);
    delay (5000);
 
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } 

    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

    digitalWrite(10,LOW);
    Serial.println("not touched");
     digitalWrite(9,HIGH);
    delay(300);
    digitalWrite(9,LOW);
    delay(30);
   Serial.println("not touched");
  } 
  digitalRead(7);
 
    // turn LED off:
    digitalWrite(13, LOW);
  }
}

 
