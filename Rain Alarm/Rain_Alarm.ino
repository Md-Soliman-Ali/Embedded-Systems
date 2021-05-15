int rainsense= A0; // analog sensor input pin 0
int buzzerout= 10; // digital output pin 10 - buzzer output
int countval= 0; // counter value starting from 0 and goes up by 1 every second
int ledout= 11; // digital output pin 11 - led output
 
void setup(){
   Serial.begin(9600);
   pinMode(buzzerout, OUTPUT);
   pinMode(ledout, OUTPUT); 
   pinMode(rainsense, INPUT);
}
void loop(){
   int rainSenseReading = analogRead(rainsense);
   Serial.println(rainSenseReading); // serial monitoring message 
   delay(250);// rain sensing value from 0 to 1023.
   // from heavy rain - no rain.
   if (countval >= 35){ 
      Serial.print("Heavy rain");
      digitalWrite(buzzerout, HIGH);  //raise an alert after x time
      digitalWrite(ledout, HIGH);  // led glow
   }
   //raining for long duration rise buzzer sound
   // there is no rain then reset the counter value
   if (rainSenseReading <500){ 
      countval++; // increment count value
   }
   else if (rainSenseReading >500) { // if not raining
      digitalWrite(buzzerout, LOW); // turn off buzzer 
      digitalWrite(ledout, LOW); // turn off led
      countval = 0; // reset count to 0
   }
   delay(1000);
}
