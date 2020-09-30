int main(void)
{
  DDRD=0x01;
  DDRC=0x08;
  while(1)
  {
    if(PIND&0x04)
    { 
    PORTD=0x00;
    PORTC=0x08;
  }
  if(PIND&0x08)
  {
      PORTC=0x00;
    PORTD=0x01;
  
  }
  else
  {
     PORTC=0x00;
     PORTD=0x00;
  }
}
}
