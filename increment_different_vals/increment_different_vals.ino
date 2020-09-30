
int main(void)
{
  int i;
  Serial.begin(2000000);
DDRB=0x04;
while(1)
{
if(PIND&0x04)
{

}
 else
{
  i++;
  Serial.println(i);
    _delay_ms(20);
}

}
}
