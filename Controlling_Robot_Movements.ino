#define m11 25
#define m12 26
#define m21 32 
#define m22 33 

#define LEN   2   //Left pin Enable
#define REN   4  //Right pin Enable

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(LEN,OUTPUT);
  pinMode(REN,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 analogWrite(LEN,255);
 analogWrite(REN,255);

 forward();
 delay(5000);
 backward();
 delay(5000);
 left();
 delay(5000);
 right();
 delay(5000);
 halt();
delay(5000);
}

void forward()
{
   digitalWrite(m11,HIGH);
   digitalWrite(m12,LOW);
   digitalWrite(m21,HIGH);
   digitalWrite(m22,LOW);
   
}
void backward()
{
   digitalWrite(m11,LOW);
   digitalWrite(m12,HIGH);
   digitalWrite(m21,LOW);
   digitalWrite(m22,HIGH);
}
void left()
{
   digitalWrite(m11,HIGH);
   digitalWrite(m12,LOW);
   digitalWrite(m21,LOW);
   digitalWrite(m22,LOW);
}
void right()
{
   digitalWrite(m11,LOW);
   digitalWrite(m12,LOW);
   digitalWrite(m21,HIGH);
   digitalWrite(m22,LOW);
}
void halt()
{
  digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
}
