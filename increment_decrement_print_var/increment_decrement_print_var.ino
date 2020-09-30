
int main(void)
{
  int i;
  Serial.begin(2000000);
DDRB=0x04;
while(1)
{
if(PIND&0x04)
{
  i+=10;
 Serial.println(i);
  _delay_ms(1000);
}
 if(PIND&0x08)
{
  i++;
  Serial.println(i);
    _delay_ms(1000);
}

}
}
