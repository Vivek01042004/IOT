const int switch1Pin = 12; 
const int switch2Pin = 13;  
const int switch3Pin = 14;  
const int switch4Pin = 15;
void setup() {
  pinMode(switch1Pin, INPUT_PULLUP);
  pinMode(switch2Pin, INPUT_PULLUP);
  pinMode(switch3Pin, INPUT_PULLUP);
  pinMode(switch4Pin, INPUT_PULLUP);
  analogWrite(2, 255);
  analogWrite(4, 255);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
}

void loop() {

  if (digitalRead(switch1Pin) == LOW)
  {
    forward();
  }
   else if (digitalRead(switch2Pin) == LOW) 
  {
    backward();
  } 
  else if (digitalRead(switch3Pin) == LOW)
 {
    right();
 }
  else if (digitalRead(switch4Pin) == LOW) 
  {
    left(); 
  } 
  else
  {
    low();
  }
  delay(1000); 
}

void forward()
{
  digitalWrite(25,LOW);
  digitalWrite(26,HIGH);
  digitalWrite(32,HIGH);
  digitalWrite(33,LOW);

}

void backward()
{
  digitalWrite(25,HIGH);
  digitalWrite(26,LOW);
  digitalWrite(32,LOW);
  digitalWrite(33,HIGH);
}


void left()
{
  digitalWrite(25,LOW);
  digitalWrite(26,HIGH);
  digitalWrite(32,LOW);
  digitalWrite(33,LOW);
}

void right()
{
  digitalWrite(25,LOW);
  digitalWrite(26,LOW);
  digitalWrite(32,HIGH);
  digitalWrite(33,LOW);
}
void hold()
{
  digitalWrite(25,LOW);
  digitalWrite(26,LOW);
  digitalWrite(32,LOW);
  digitalWrite(33,LOW);
}