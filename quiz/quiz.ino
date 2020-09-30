int main(void)
{DDRC=0XFF;
  UCSRB=0X18;
UCSRC=0X06;
UBRRL=0X67;
UBRRH=0x00;
while(1)
{
  while(!(UCSRA&0x80));
 
 if(UDR=='3')
 {
PORTC=0xFF;
 }
 else
 {
  PORTC=0x00;
 }
}
}
  
  
  
  
  



 
