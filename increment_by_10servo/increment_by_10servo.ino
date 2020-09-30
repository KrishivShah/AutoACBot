int var=0;int angle=0;
int main(void)
{
  DDRB=0xFF;
  DDRD=0x00;
  TCCR0=0x03;
  while(1)
  {
    if(PIND&0x04)
    {
     angle+=10;
    Servo();
    _delay_ms(1000); 
    }
     if(PIND&0x08)
    {
     
    angle-=10;
    Servo();
    _delay_ms(1000);
    }
   
    
  }
}
void Servo()
{
 for(int i=1;i<20;i++)
 {
  int temp=5+(angle/10);
  while(var<200)
  {
    if(TCNT0==25)
    {
      var++;
      TCNT0=0;
    }
    if(var==temp)
    {
      PORTB=0x00;
    }}
    if(var==200)
    {
      PORTB=0xFF;
      var=0;
    }
  
 }
}
