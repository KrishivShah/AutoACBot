int main(void)
{
 DDRB=0XFF;
Serial.begin(2000000);
while(1)
{
  ADMUX=0x40;
ADCSRA=0xC7;
while (ADCSRA&0x40);
  int left=ADCW;
 ADMUX=0x41;
 ADCSRA=0xC7;
  
  while(ADCSRA&0x40);
  
    int right=ADCW;
    if(left<500&&right<500)
    {
      PORTC=0x00;
      PORTB=0x00;
      Serial.println("backward");
      _delay_ms(1000);
    }
     if(left<500&&right>500)
    {
        PORTC=0x00;
      PORTB=0xFF;
      Serial.println(" skid right");
      _delay_ms(1000);
    }
 if(left>500&&right<500)
    {
        PORTC=0xFF;
      PORTB=0x00;
      Serial.println("skid left");
      _delay_ms(1000);
    }
 if(left>500&&right>500)
    {
        PORTC=0xFF;
      PORTB=0xFF;
      Serial.println("forward");
      _delay_ms(1000);
    }
}   
}
