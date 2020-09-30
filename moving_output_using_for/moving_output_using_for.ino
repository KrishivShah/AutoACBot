#include<LCD.h>
int main(void)
{
  LCD lcd;
  lcd.init();
 lcd.gotoxy1(0);
 lcd.string("what is the");
 lcd.gotoxy2(0);
lcd.string("capital of india");
 while(!(PIND&0x04));
lcd.cmd(0x01);
_delay_ms(3000);
lcd.string("1)mumbai");
lcd.gotoxy2(0);
lcd.string("2)Delhi");
 while(!(PIND&0x04));
 _delay_ms(3000);
lcd.cmd(0x01);

lcd.string("for op 1 sw 1");
lcd.gotoxy2(0);
lcd.string("for op 2  sw 2");
_delay_ms(3000);
lcd.cmd(0x01);
if(PIND&0x04)
{
  lcd.string("ans is wrong");
  _delay_ms(1000);
}
if(PIND&0x08)
{
  lcd.string("ans is correct");
  _delay_ms(1000);
}
lcd.cmd(0x01);
}




 
