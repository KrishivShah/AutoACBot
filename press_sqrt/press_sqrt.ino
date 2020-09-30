
int main(void)
{
  int i=0;
  Serial.begin(2000000);
DDRB=0x04;
while(1)
{
if(PIND&0x04)
{
  i++;
Serial.println(i*i*i);
  _delay_ms(1000);
}
else
{
  
}

}
}
