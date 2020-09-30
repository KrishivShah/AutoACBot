#include<LCD.h>
int main(void)
{
  LCD lcd;
  lcd.init();
 for(int i=0;i<16;i++)
 {
  lcd.cmd(0x01);
  lcd.gotoxy1(i);
  lcd.string("EDuprime");  
 }
 for(int i=16;i>=0;i--)
 {
  lcd.cmd(0x01);
  lcd.gotoxy2(i);
  lcd.string("EDuprime");
  
 }
 
}
