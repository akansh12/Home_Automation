//Declaring libraris
#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);


int bulb1=11;
int bulb2=12;
int bulb3=13;                
int pir_sensor = 10; 
int ldr = A0;             
int state = LOW;             
int val = 0;
void setup() {
  lcd.begin(16,2);
  pinMode(pir_sensor, INPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);  
  pinMode(bulb3, OUTPUT);
  pinMode(bulb2,OUTPUT);

  //Initial Display
  lcd.setCursor(0,0);
  lcd.print("Home Automation");
  delay(2000);
  lcd.clear();
  lcd.print("OUT1  OUT3  OUT4");
  lcd.setCursor(0,1);
  lcd.print("OFF    OFF   OFF");

}

void loop() {

  lcd.setCursor(0,0);
  lcd.print("OUT1  OUT3  OUT4");
 
  // PIR_Sensor_operated_switch
  
  val = digitalRead(pir_sensor);   
  if (val == HIGH) {           
    digitalWrite(bulb3, HIGH);
     lcd.setCursor(7,1); 
      lcd.print("ON    ");
   //LDR_sensor
  int val = analogRead(ldr);
  analogWrite(bulb2, val / 10 );
  Serial.println(val);
    delay(5000);                 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       
    }
    delay(5000);
  }

   if (val==LOW){
    digitalWrite(bulb3, LOW);
     lcd.setCursor(7,1); 
     lcd.print("OFF   ");
  //LDR_sensor
  int val = analogRead(ldr);
  analogWrite(bulb2, val / 10 );
  Serial.println(val);
    
   }

  
 

  
  

}
