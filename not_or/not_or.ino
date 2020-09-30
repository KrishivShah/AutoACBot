//left motor d6 pos d7 neg
//right motor positive d4 neg d5
//l threshold of left
//r threshold of right
//c threshold of centre
//less then threshold white
int main(void)

{


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


    if((left<500&&right<500)&&centre>500)
    

    {

      Serial.println("Forward");
      
      Serial.println(centre);


      PORTD=0x90;

    }
      else if((left>500&&right>500)&&centre>500)
    

    {

      Serial.println("Forward");

      PORTD=0x90;  Serial.println(centre);

    }

    else if((left<500&&right<500)&&centre<500)

    {

      Serial.println("Backward");

      PORTD=0x60;
      Serial.println(centre);
    }   

   else if((left<500&&right>500)&&centre>500)

    {  
      
      Serial.println(centre);
      Serial.println("Right");
      PORTD=0xA0;

    } 
      else if((left<500&&right>500)&&centre<500)

    {
 
      Serial.println("Right");
      PORTD=0xA0;
     Serial.println(centre);
    } 

    else if((left>500&&right<500)&&centre>500)

    {

      Serial.println("Left");  Serial.println(centre);

      PORTD=0x50;

    }   
else if((left>500&&right<500)&&centre<500)

    {

      Serial.println("Left");  Serial.println(centre);

      PORTD=0x50;

    }   
    else
    {
      Serial.println("Forward");
      
      Serial.println(centre);


      PORTD=0x90;

    }

 }

}
