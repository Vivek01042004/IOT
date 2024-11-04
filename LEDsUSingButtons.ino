const int led1=25;
const int led2=26;
const int led3=32;
const int led4=33;

const int switch1=12;
const int switch2=13;
const int switch3=14;
const int switch4=15;
void setup() {
  pinMode(switch1,INPUT_PULLUP);
  pinMode(switch2,INPUT_PULLUP);
  pinMode(switch3,INPUT_PULLUP);
  pinMode(switch4,INPUT_PULLUP);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);
}

void loop() {
  if(digitalRead(switch1)==LOW){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
  }
  else if(digitalRead(switch2)==LOW){
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
  }
  else if(digitalRead(switch3)==LOW){
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
  }
  else if(digitalRead(switch4)==LOW)
  {
    digitalWrite(led4,HIGH);
  }
  else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
}

