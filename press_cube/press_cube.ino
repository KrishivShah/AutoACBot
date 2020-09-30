int main(void)
{
  int var;
  
  while(1);
  for(int i=0;i<=9;i++)
  {

    if(i<=4)
    {
     var=i*i;
    }
    else if(i<=8&&i>4)
    {
      var=i*i*i*i;
    }
    else
    {
      var=i*i*i*i;
      Serial.println(var);
    }
    
  }
}
