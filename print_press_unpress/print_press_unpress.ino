
int main(void)
{
  Serial.begin(2000000);
DDRB=0x04;
while(1)
{
if(PIND&0x04)
{
  Serial.println(" first switch presse");
  _delay_ms(10);
}
else if(PIND&0x08)
{
  Serial.println(" second switch pressed");
}
else
{

  Serial.println(" ");
}
}
}
