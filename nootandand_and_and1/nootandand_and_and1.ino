int main(void)
{
  DDRD=0x01;
  while(1)
  {
    if(!((PIND&0x04)||(PIND&0x08)))
    {
      PORTD=0x01;
    }
    else
    {
      PORTD=0x00;
    }
  }

}
