#include <Servo.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);  
Servo myservo;
Servo myservo1;
int pos = 0; 
int entry = A0;
int exit1 = A1;
int slot1 = A2;
int slot2 = A3;
#define led 13
#define indicator1 11
#define indicator2 12

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  myservo.attach(3);
  myservo1.attach(4);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

}
void loop() {
  // put your main code here, to run repeatedly:
  entry = analogRead(A0);
  exit1 = analogRead(A1);
  slot1 = analogRead(A2);
  slot2 = analogRead(A3);
  if(entry<400)
  {
     digitalWrite(13, HIGH);
     lcd.clear();
     lcd.setCursor(0, 0); 
     lcd.print("Smart Parking");
     lcd.setCursor(0, 1); 
     lcd.print("ENTRY");
     Serial.print("ENTRY");
     for (pos = 0; pos <= 90; pos += 1) { 
     myservo.write(pos);              
     delay(10);                    
     }
  delay(2000); 
  for (pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);             
    delay(10); 
       }
  }
   else{
  digitalWrite(led, LOW);
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Smart Parking");
  Serial.print("Smart Parking");
  myservo.write(0);
  delay(2000);
   }  
 
   if(exit1<400)
   {
    digitalWrite(led, HIGH);
     lcd.clear();
     lcd.setCursor(0, 0); 
     lcd.print("Smart Parking");
     lcd.setCursor(0, 1); 
     lcd.print("EXIT");
     for (pos = 0; pos <= 90; pos += 1) { 
     myservo1.write(pos);              
     delay(10);                    
     }
   delay(2000);
  for (pos = 90; pos >= 0; pos -= 1) { 
    myservo1.write(pos);             
    delay(10); 
  }  
   }
    else{
  digitalWrite(led, LOW);
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Smart Parking");
  myservo1.write(0);
  delay(2000);
   }  

if(slot1<400)
 {   
     digitalWrite(indicator1,HIGH);
     lcd.clear();
     lcd.setCursor(0, 0); 
     lcd.print("Smart Parking");
     lcd.setCursor(0, 1); 
     lcd.print("SLOT1: Occupied ");
     delay(2000);
     
 }
 else{
  digitalWrite(indicator1, LOW);
     lcd.clear();
     lcd.setCursor(0, 0); 
     lcd.print("Smart Parking");
     lcd.setCursor(0, 1);
     lcd.print("SLOT1: Empty");     
     delay(2000);
 }

if(slot2<400)
 {   
    digitalWrite(indicator2, HIGH);
     lcd.clear();
     lcd.setCursor(0, 0); 
     lcd.print("Smart Parking");
     lcd.setCursor(0, 1); 
     lcd.print("SLOT2: Occupied");
     delay(2000);
 }
 else{
  digitalWrite(indicator2, LOW);
     lcd.clear();
     lcd.setCursor(0, 0); 
     lcd.print("Smart Parking");
     lcd.setCursor(0, 1);
     lcd.print("SLOT2: Empty");
     delay(2000);
 }
 if(slot1<400 && slot2<400)
 {
     myservo.write(0);              
     delay(10); 
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Car Park FULL");
     delay(2000);                   
     }
     
 }
