#include <IRremote.h>
int RECV_PIN = 13;//IR receiver pin
IRrecv irrecv(RECV_PIN);
decode_results results;
int inp1m1=9;//for motor 1
int inp2m1=8;
int inp1m2=7;//for motor 2
int inp2m2=6;
void setup()
{
  pinMode(inp1m1,OUTPUT);
  pinMode(inp2m1,OUTPUT);
  pinMode(inp1m2,OUTPUT);
  pinMode(inp2m2,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
void stop()
{
  digitalWrite(inp1m1,LOW);
  digitalWrite(inp2m1,LOW);
  digitalWrite(inp1m2,LOW);
  digitalWrite(inp2m2,LOW);
}
void backward()
{
  digitalWrite(inp1m1,HIGH);
  digitalWrite(inp2m1,LOW);
  digitalWrite(inp1m2,LOW);
  digitalWrite(inp2m2,HIGH);
  delay(2000);
}
void forward()
{
  digitalWrite(inp1m1,LOW);
  digitalWrite(inp2m1,HIGH);
  digitalWrite(inp1m2,HIGH);
  digitalWrite(inp2m2,LOW);
  delay(2000);
}
void RIGHT()
{
  digitalWrite(inp1m1,HIGH);
  digitalWrite(inp2m1,LOW);
  digitalWrite(inp1m2,LOW);
  digitalWrite(inp2m2,LOW);
  delay(200);
}
void LEFT()
{
  digitalWrite(inp1m1,LOW);
  digitalWrite(inp2m1,LOW);
  digitalWrite(inp1m2,HIGH);
  digitalWrite(inp2m2,LOW);
  delay(200);
}
void loop()
{
  if (irrecv.decode(&results))// if receiver recive any input than it is TRUE
    {
     Serial.println(results.value);// for print receiver input
      switch(results.value)
       {
        case 16740495:
          forward();
          break;
        
        case 16734375:
          backward();
          break;
          
        case 16732335:
          LEFT();
          break;
          
        case 16742535:
          RIGHT();
          break;
        default:
          stop();
        }
     irrecv.resume(); // Receive the next value
    }
}
