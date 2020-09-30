//left motor d6 pos d7 neg
//right motor positive d4 neg d5
//l threshold of left
//r threshold of right
//c threshold of centre
//less then threshold white
//ir 1 threshold 50
//ir 2 threshold 50
//ir 3 threshold 50
int main(void)

{

int leftv = 25;
 DDRD=0xFF;

  Serial.begin(2000000);

  while(true)

  {

    ADMUX=0x41;

    ADCSRA=0xC7;

    while(ADCSRA&0x40){}

    int left=ADCW;
  
 

    ADMUX=0x42;

    ADCSRA=0xC7;

    while(ADCSRA&0x40){}

    int right=ADCW;
    
    ADMUX=0x43;

    ADCSRA=0xC7;

    while(ADCSRA&0x40){}

    int centre=ADCW;

    if(left>25&&right>25)   

    {
      //Serial.println("Forward");
      PORTD=0x90;

    }
     
   else if(left<25&&right>25)

    {  
      
      
     // Serial.println(centre);
      //Serial.println("Right");
      PORTD=0x80;
      while (!(left<25 && right <25));
     // _delay_ms(500);

    } 
      
    else if(left>25&&right<25)

    {

      //Serial.println("Left");  Serial.println(centre);

      
      PORTD=0x10;
      while (!(left<25 && right <25));
      //_delay_ms(500);
    }
   
    /*else if(left>25&&right<25&&centre<=24)

    {

      Serial.println("Left");  Serial.println(centre);

      PORTD=0x50;

    } */  
    else
    {
      PORTD = 0x90;
    }

 }

}
