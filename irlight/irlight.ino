#include<LCD.h>
int main(void)
{
 int g;

  int var=0;
  LCD lcd;
  lcd.init();
 lcd.gotoxy1(2);
   lcd.string("lol");
   lcd.gotoxy2(4);
   lcd.string("UnikIts");

}
