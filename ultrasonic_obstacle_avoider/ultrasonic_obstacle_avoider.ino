int count=0;
double distance=0;
int pinstate=0;
void trigger()
{
 PORTB=0x01;
 _delay_us(10);
 PORTB=0x00;
 _delay_us(10);
}


int main(void)
{
  
Serial.begin(2000000);
  DDRB=0X01;
  DDRD=0xFF;

  while(1)
  {
     trigger();
    while(PINB&0x02)
    {
       TCCR1A=0;
  TCCR1B=0x02;
  pinstate=1;
    }
    while(!(PINB&0x02)&& pinstate ==1)
    {
      TCCR1B=0;
      count=TCNT1;
      distance=count*0.0085;
      Serial.println(distance);

      if(distance<10)
      {
        PORTD=0b10100000;
         _delay_ms(200);
         PORTD=0b10010000;
         _delay_ms(10m00);
      }
      else
      {

   
           PORTD=0b01100000;  
      }
      pinstate=0;
      TCNT1=0;
      
    }
  
  }


 
 
}
  
 


 
