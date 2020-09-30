//Right Motor Positive-D6 and Negative-D7
//Left Motor Positive-D4 and Negative-D5
// Right IR on A3
// Left IR on A2
// Centre IR on A4
//Forward=0b01100000
//Right=0b10100000
//Backward=0b10010000
//Left=0b01010000
//less than threshold white and more than threshold means black
//left-500
//right-370
//centre-400
//t=225
int count =0;
int pinstate=0;
double distance=0;
int tl=500;
int tr=370;
int tc=400;
String ll="Left - ";
String lr="Right- ";
String lc="Centre- ";
int main(void)
{
  Serial.begin(2000000);
  DDRD=0xFF;
  while(true)
  {
    int leftdepth=getleftirdepth();
    int rightdepth = getrightirdepth();
    int centre=getcentre();
    linefollow(leftdepth,rightdepth,centre,tl);
  } 
}
void forward()
{
  PORTD=0b01100000;
  
}
void backward()
{
  PORTD=0b10010000;
}
void rightturn()
{
  PORTD=0b00100000;
}
void leftturn()
{
  PORTD=0b01000000;
}
void completestop()
{
  PORTD=0b00000000;
}
int getleftirdepth()
{
   ADMUX=0x42;
   ADCSRA=0xC7;
    while(ADCSRA&0x40);
    int v=ADCW;
    return v;
}
int getrightirdepth()
{
   ADMUX=0x43;
   ADCSRA=0xC7;
    while(ADCSRA&0x40);
    int y=ADCW;
    return y;
}
int getcentre()
{
   ADMUX=0x44;
   ADCSRA=0xC7;
    while(ADCSRA&0x40);
    int u=ADCW;
    return u;
}
void printdata(String p,int data)
{
  Serial.print(p);
  Serial.println(data);
}
void linefollow(int left,int right,int centre,int tl)
{
//printdata(ll,left);
  printdata(lr,right);
  //printdata(lc,centre);
  if(left<tl&&right<tr&&centre>tc)
  { 
    Serial.println("Forward");
    forward();
    
  }
  else if(left>tl&&right<tr&&centre>tc)
  {
    Serial.println("Left");
    leftturn();
    _delay_ms(100); 
    while(!(right>tr))
    {
      right=getrightirdepth();
      Serial.println("Taking Left");
    }                                                                 
  }
  
  else if(left<tl&&right>tr&&centre>tc)
  {
    Serial.println("Right");
    rightturn();
    _delay_ms(100);
    while(!(left>tl))
    {
      left=getleftirdepth();
      Serial.println("Taking Right");
    }  
    while(!(center>tc&&left<tl))
    {
      center=getcentre();
      left=getleftirdepth();
      leftturn();
      Serial.println("Taking correction left");
    }
   }
  else
  {
    forward();
    Serial.println("ELSE");
  }
 }
