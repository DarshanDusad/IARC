int maxspeedleft = 150; //163
int maxspeedright = 150; //140
int m11 = 6;  //for left tyre moving backward when high
int m12 = 5;  //for left tyre moving forward when high
int m21 = 3;  //for right tyre moving backward when high
int m22 = 9;  //for right tyre moving forward when high
int junc = 7; //junction pulse
long botPosition;
int proportional;// 577 to 440 or 44 to 33   on line
int c=0;//  55==723  and 15==197
int previousproportional;
int derivative,rightSpeed,leftSpeed;
double kp = 0.24 ;
int error;
double kd = 0.26;
double setPoint = 459.8;
void pidCalc() {
         
  proportional = botPosition - setPoint ;
  
  derivative = proportional - previousproportional;
  
  error = (proportional * kp) + (derivative * kd);
  
  previousproportional = proportional;
}
void errorAdj()
{
 if(error < -150)
  {
    error = -150;
  }
  if(error > 150)
  {
    error = 150;
  }
  // If error_value is less than zero calculate right turn speed values
  if(error <0)
  {
    rightSpeed = maxspeedright;
    leftSpeed = maxspeedleft+error;
  }
  // If error_value is greater than zero calculate left turn values
  else
  { 
    rightSpeed = maxspeedright-error;
    leftSpeed = maxspeedleft ;
  }
}
void motorRun()
{ // Drive motors according to the calculated values for a turn
  analogWrite(m12, leftSpeed);
  analogWrite(m22, rightSpeed);
 }
void read_leds() {
  botPosition=analogRead(A4);
  Serial.print(botPosition);
  Serial.println();
  Serial.print(junc);
}
void setup()
{ pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
  pinMode(A4,INPUT);
  Serial.begin(9600);
  pinMode(junc,INPUT);
}
void right()
  {        Serial.print("right");       
           analogWrite(m11,0);
           analogWrite(m12,0);
           analogWrite(m21,0);
           analogWrite(m22,0);
           delay(100);    
      
        {  analogWrite(m11,0);
           analogWrite(m12,maxspeedleft-80);
           analogWrite(m21,0);
           analogWrite(m22,maxspeedright-80);    
           delay(150);
           read_leds();
        }
   
           analogWrite(m11,0);
           analogWrite(m12,0);
           analogWrite(m21,0);
           analogWrite(m22,0); 
           delay(100);
            
        while(!(botPosition>440 && botPosition<577))
         {  analogWrite(m11,0);
            analogWrite(m12,maxspeedleft-80);
            analogWrite(m21,maxspeedright-80);
            analogWrite(m22,0);
           
            read_leds();    
        }
           analogWrite(m11,0);
           analogWrite(m12,0);
           analogWrite(m21,0);
           analogWrite(m22,0);
           delay(100);
           Pstraight();
  }
 void specialleft()
  {   Serial.print("special left"); 
       analogWrite(m11,0);
      analogWrite(m12,0);
      analogWrite(m21,0);
      analogWrite(m22,0);
      delay(100);
      analogWrite(m11,0);
      analogWrite(m12,maxspeedleft-80);
      analogWrite(m21,0);
      analogWrite(m22,maxspeedright-80);
      delay(200);  
       analogWrite(m11,0);
      analogWrite(m12,0);
      analogWrite(m21,0);
      analogWrite(m22,0);
      delay(100);
      read_leds();
  if(botPosition>440 && botPosition<577)
  {
    while((botPosition>440 && botPosition<577))
    { analogWrite(m11,maxspeedleft-80);
      analogWrite(m12,0);
      analogWrite(m21,0);
      analogWrite(m22,maxspeedright-80);  
      read_leds();
    }
    while(!(botPosition>440 && botPosition<577))
    { analogWrite(m11,maxspeedleft-80);
      analogWrite(m12,0);
      analogWrite(m21,0);
      analogWrite(m22,maxspeedright-80);     
      read_leds();  
    }
  }
  else if(botPosition<=440 && botPosition>=197)
   {  while(!(botPosition>440 && botPosition<577))
      { analogWrite(m11,maxspeedleft-80);
        analogWrite(m12,0);
        analogWrite(m21,0);
        analogWrite(m22,maxspeedright-80);
        read_leds();  
      }
      while((botPosition>440 && botPosition<577))
      { analogWrite(m11,maxspeedleft-80);
        analogWrite(m12,0);
        analogWrite(m21,0);
        analogWrite(m22,maxspeedright-80);  
        read_leds();
      }
      while(!(botPosition>440 && botPosition<577))
      {analogWrite(m11,maxspeedleft-80);
        analogWrite(m12,0);
        analogWrite(m21,0);
        analogWrite(m22,maxspeedright-80);  
        read_leds(); 
      }
   }
   else 
    {  while(!(botPosition>440 && botPosition<577))
      {analogWrite(m11,maxspeedleft-80);
        analogWrite(m12,0);
        analogWrite(m21,0);
        analogWrite(m22,maxspeedright-80);  
        read_leds(); 
      }
   }
           analogWrite(m11,0);
           analogWrite(m12,0);
           analogWrite(m21,0);
           analogWrite(m22,0);
           delay(100);
       Pstraight();
  }
void specialright()
  {   Serial.print("special right");
      analogWrite(m11,0);
      analogWrite(m12,0);
      analogWrite(m21,0);
      analogWrite(m22,0);
      delay(100);
      analogWrite(m11,0);
      analogWrite(m12,maxspeedleft-80);
      analogWrite(m21,0);
      analogWrite(m22,maxspeedright-80);
         delay(350);   
      analogWrite(m11,0);
      analogWrite(m12,0);
      analogWrite(m21,0);
      analogWrite(m22,0);
      delay(200);
      read_leds();
  if((botPosition>440 && botPosition<577))
  {
    while((botPosition>440 && botPosition<577))
    { analogWrite(m11,0);
      analogWrite(m12,maxspeedleft-80);
      analogWrite(m21,maxspeedright-80);
      analogWrite(m22,0);  
      read_leds();
    }
    while(!(botPosition>440 && botPosition<577))
    { analogWrite(m11,0);
      analogWrite(m12,maxspeedleft-80);
      analogWrite(m21,maxspeedright-80);
      analogWrite(m22,0);     
      read_leds();  
    }
  }
    else if(botPosition<=440 && botPosition>=197)
   {  while(!(botPosition>440 && botPosition<577))
      { analogWrite(m11,0);
        analogWrite(m12,maxspeedleft-80);
        analogWrite(m21,maxspeedright-80);
        analogWrite(m22,0);
        read_leds();  
      }
      while((botPosition>440 && botPosition<577))
      { analogWrite(m11,0);
        analogWrite(m12,maxspeedleft-80);
        analogWrite(m21,maxspeedright-80);
        analogWrite(m22,0);  
        read_leds();
      }
      while(!(botPosition>440 && botPosition<577))
      { analogWrite(m11,0);
        analogWrite(m12,maxspeedleft-80);
        analogWrite(m21,maxspeedright-80);
        analogWrite(m22,0);
        read_leds();  
      }
   }
   else
   {  while(!(botPosition>440 && botPosition<577))
      { analogWrite(m11,0);
        analogWrite(m12,maxspeedleft-80);
        analogWrite(m21,maxspeedright-80);
        analogWrite(m22,0);
        read_leds();  
      }
   } 
           analogWrite(m11,0);
           analogWrite(m12,0);
           analogWrite(m21,0);
           analogWrite(m22,0);
           delay(300);
           Pstraight();
  }  
void left()
{      read_leds();
           Serial.print("leftturn");
           analogWrite(m11,0);
           analogWrite(m12,0);
           analogWrite(m21,0);
           analogWrite(m22,0);    
           delay(100);
          
        {  analogWrite(m11,0);
           analogWrite(m12,maxspeedleft-80);
           analogWrite(m21,0);
           analogWrite(m22,maxspeedright-80);   
           delay(200);
           read_leds(); 
        }
           analogWrite(m11,0);
           analogWrite(m12,0);
           analogWrite(m21,0);
           analogWrite(m22,0); 
           delay(100);
        while(!(botPosition>440 && botPosition<577))
         {  analogWrite(m11,maxspeedleft-80);
            analogWrite(m12,0);
            analogWrite(m21,0);
            analogWrite(m22,maxspeedright-80); 
            read_leds();   
        }
           analogWrite(m11,0);
           analogWrite(m12,0);
           analogWrite(m21,0);
           analogWrite(m22,0);
           delay(100);
          Pstraight();
  }
void Pstraight(){
 pidCalc();
 errorAdj();
 motorRun();
}
void loop(){
  read_leds();
//  analogWrite(m11,0);
//  analogWrite(m12,150);
//  analogWrite(m21,0);
//  analogWrite(m22,150);
if(digitalRead(junc)==HIGH)
 { c++;
if(c==1 || c==5)
specialleft();
else if(c==3 || c==9)
right();    
else if(c==10)
left();
 else
  {
   while(digitalRead(junc)==HIGH)
    { Pstraight();
      read_leds();
    }
  }
}
else
 { Pstraight();
   read_leds();
 }

}
