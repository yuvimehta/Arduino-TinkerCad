long duration;
float m;

int trig =9;
int echo = 9;
void setup()
{
  pinMode(9,INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //digitalWrite(11,HIGH);
  pinMode(trig,OUTPUT);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  pinMode(echo,INPUT);
  duration = pulseIn(echo,HIGH);
  m = (duration * 0.01723);
  Serial.println(m);
 
  if( m < 40)
  {
    digitalWrite(11,HIGH);
  }
  else
  { 
    digitalWrite(11,LOW);
  }
  delay(1000);
}