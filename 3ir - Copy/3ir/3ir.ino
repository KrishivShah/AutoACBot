//left motor d6 pos d7 neg
//right motor positive d4 neg d5
//l threshold of left
//r threshold of right
//c threshold of centre
//less then threshold white
//ir 1 threshold 50
//ir 2 threshold 50222
//ir 3 threshold 50
int main(void)

{

int leftv = 22;
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
      Serial.println(right);
 
    
    ADMUX=0x43;

    ADCSRA=0xC7;

    while(ADCSRA&0x40){}

    int centre=ADCW;

    if(centre>22&&left<22&&right<22)   

    {
      Serial.println("Forward");
      PORTD=0x90;

    }
     else if(left>22&&right>22&&centre>22)
    

    {

      Serial.println("Forward1");

      PORTD=0x90;  //Serial.println(centre);

    }
//
//    else if(left<22&&right<22&&centre<22)
//
//    {
//
//      Serial.println("Backward");
//
//      PORTD=0x60;
//      _delay_ms(100);
//      PORTD=0xA0;
//      
//      Serial.println(centre);
//    }   

   else if(left<22&&right>22&&centre>22)

    { 
      
      Serial.println(centre);
      Serial.println("Right");
      PORTD=0xA0;

    } 
      else if(left<22&&right>22&&centre<22)

    {
    Serial.println("Right");

      PORTD=0xA0;

     Serial.println(centre);
    } 

    else if(left>22&&right<22&&centre>22)

    {

      

      Serial.println("Left");  Serial.println(centre);

      PORTD=0x50;

    }   
    else if(left>22&&right<22&&centre<22)

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
