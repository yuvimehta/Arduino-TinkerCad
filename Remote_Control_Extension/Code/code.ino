#include <IRremote.h>     

#define code1  16582903  
#define code2  16615543   
#define code3  16580863   



int RECV_PIN = 11;        
IRrecv irrecv(RECV_PIN);
decode_results results;

int motor = 9;         
int bulb = 10;  
int power = 8;
int indicator = 12;
int status[] = {0,0,0,0};


void setup()
{
 Serial.begin(9600);
         
  irrecv.enableIRIn();       
  
  pinMode(motor, OUTPUT);
  pinMode(bulb, OUTPUT);
  pinMode(power,OUTPUT);
  
  
}
 
void loop() 
{
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
              
       case code3:
         if(status[3] == 0) 
         {
            digitalWrite(power, HIGH); 
            digitalWrite(indicator, HIGH);
            status[3] = 1;              
         }

         else {
               digitalWrite(power, LOW);
            digitalWrite(indicator,LOW);
               status[3] = 0;            
              }
      
       case code2:
         if(status[1] == 0) {           
            digitalWrite(motor, LOW);    
            status[1] = 1;              
            
          }
      
        else {                          
              digitalWrite(motor, HIGH);   
              status[1] = 0;           
              
           }
              break;
      
      
       case code1:
         if(status[2] == 1) {
            digitalWrite(bulb, LOW);
            status[2] = 0;
            
         } 
      
        else {
              digitalWrite(bulb, HIGH);
              status[2] = 1;
             
           }
              break;
              
      
    }
    Serial.println(value);      
    irrecv.resume();       
  }
}