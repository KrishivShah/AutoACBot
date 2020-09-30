
int main(void)
{
DDRD=0b00000110;
DDRB=0xFF;
while(1)
{
if(PIND&0b00000100)
{
  PORTB=0xFF;
}
else if(PIND&0b00001000)
{
  PORTB=0xFF;
}
else
{
  PORTB=0x00;
}
 
}
}
