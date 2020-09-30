//Right Motor Positive-D6 and Negative-D7
//Left Motor Positive-D4 and Negative-D5
// Right IR on A3
// Left\ IR on A2
//Forward=0b01100000
//Right=0b10100000
//Backward=0b10010000
//Left=0b01010000
int count =0;
int pinstate=0;
double distance=0;
int tl=60;
int tc=200;
String ll="Left - ";
String lr="Right- ";
String lc="Centre- ";
int main(void)
{
  DDRC=0xFF;
  UCSRB=0x18;
  UCSRC =0x06;
  UBRRL=0x67;
  UBRRH=0x00;
  Serial.begin(2000000);
  int count =0;
  DDRB=0x01;
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
  PORTD=0b10100000;
}
void leftturn()
{
  PORTD=0b01010000;
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
  printdata(ll,left);
  printdata(lr,right);
  printdata(lc,centre);
  if(left<tl&&right<tl&&centre<tl)
    forward();
  else if(left<tc&&right>tl&&centre>tc)
  {
    rightturn();
    _delay_ms(100);
  }
  else if(left>tc&&right<tl&&centre>tc)
  {
    leftturn();
    _delay_ms(100);
  }

   else if(left<tc&&right>tl&&centre<tc)
  {
    leftturn();
    _delay_ms(100);
  }
//  else
//  { 
//    _delay_ms(300);
//    backward();
//  }
}
