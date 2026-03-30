iint mr1=4;  //motor right 1
int mr2=5;  //motor right 2
int ml1=6;  //motor left 1
int ml2=7; //motor left 2
int sr=9;   //sensor right
int  sl=10;   //sensor left
int svr=0;
int svl=0;
int led=13;
int enr=3; 
int  enl=8;

int vspeed=100;    
int tspeed=255;
int tdelay=20;

void  setup()
{
  Serial.begin(9600);
 pinMode(mr1,OUTPUT);
 pinMode(mr2,OUTPUT);
 pinMode(ml1,OUTPUT);
  pinMode(ml2,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(sr,INPUT);
 pinMode(sl,INPUT);
  
 delay(5000);
}

void loop()
{
 svr=digitalRead(sr);
 svl=digitalRead(sl);
  
  if(svl==HIGH && svr==HIGH)
  {
    Serial.println("forward");
  forward(); //maju
  }

  if(svl==LOW  && svr==HIGH)
  {
      Serial.println("left");
  left(); //belok kiri
  }
 
  if(svl==HIGH && svr==LOW)
  { 
      Serial.println("right");
  right(); //belok kanan
  }
  
  if(svl==LOW && svr==LOW)
  {
      Serial.println("stop");
  stop(); //berhenti
  }
}

void forward()
 {
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  analogWrite (enr,vspeed);
  analogWrite (enl,vspeed);
 } 

void backward()
  {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
  analogWrite (enr,vspeed);
  analogWrite (enl,vspeed);
  }

void right()
 {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
  delay(tdelay);
 } 

void left()
 {
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
  delay(tdelay);
}  

void stop()
 {
  analogWrite (enr,0);
  analogWrite  (enl,0);
 }