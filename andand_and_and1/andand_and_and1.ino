int main(void)
{
 
Serial.begin(2000000);
while(1)
{
DDRB=0xFF;
ADMUX=0x40;
ADCSRA=0xC7;
while(ADCSRA&0x40);
int a=ADCW;
if(a<500)
{
  PORTB=0xFF;
}
Serial.print("a is");
Serial.println(a);

ADMUX=0x41;
 ADCSRA=0xC7;
while(ADCSRA&0x40);
int b=ADCW;
if(b<500)
{
  PORTB=0x00;
}
Serial.print("b is");
Serial.println(b);
}
}
