void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(10, OUTPUT);  
  pinMode(13, INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int senseValue = digitalRead(13);
  if (senseValue == HIGH){
    digitalWrite(10, HIGH);
    digitalWrite(9,LOW);
    Serial.println("TOUCHED");
     delay(5000);
  
  }
  else{
    digitalWrite(10,LOW);
    Serial.println("not touched");
     digitalWrite(9,HIGH);
    delay(300);
    digitalWrite(9,LOW);
    delay(30);
   Serial.println("not touched");
  } 
  
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
