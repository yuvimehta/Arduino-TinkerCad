#include <LiquidCrystal.h>

long duration;
float m;

int trig =9;
int echo = 9;
LiquidCrystal lcd(12, 11, 5,4,3,2);


void setup() {
 
  lcd.begin(16, 2);
  
  lcd.print(".......");
  pinMode(9,INPUT);
  
  
}

void loop() 
{
    pinMode(trig,OUTPUT);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  pinMode(echo,INPUT);
  duration = pulseIn(echo,HIGH);
  m = (duration * 0.01723)* 0.01;
 if (m <2)
  {
    lcd.clear();
   
    lcd.print("CLEAR");
  }
  else{
  lcd.clear();
    delay(100);
  lcd.print("POTHOLE");
  }
  delay (200);
  
}
