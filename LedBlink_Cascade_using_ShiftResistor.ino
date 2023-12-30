//arduino pin 4 is HC595 DataIN pin 14
//arduino pin 2 is HC595 (shift clock) pin 11
//arduino pin 3 is HC595 (latch clock) pin 12

int datapin = 4;
int ShiftClock = 2;
int LatchClock = 3;
int delayTime = 500;

float volume; //This is the value from potentiometer
int design; //This is the pattern type 
int pattern0[] = {0,0,0,0,0,0,0,0};
int pattern1[] = {1,2,4,8,16,32,64,128};
int pattern2[] = {64,80,40,20,10,5,2,1};
int pattern3[] = {24,36,66,129,24,36,66,129};
int pattern4[] = {129,66,36,24,129,66,36,24};
int pattern5[] = {136,17,68,34,17,34,68,136};

void setup()
{
 pinMode(datapin,OUTPUT);
 pinMode(ShiftClock,OUTPUT);
 pinMode(LatchClock,OUTPUT);
 pinMode(A0,INPUT);
 Serial.begin(9600);
}

void loop()
{
 //Reading value from potentiometer
 volume = analogRead(A0); 
 design = (5./1022)*volume; //Different design values on a scale of (0-5)
  
 switch(design)
 {
  case 1: //This is the first volume running values from string pattern1.
   
   for(int j=0; j<=7; j++)
   {
    for(int ShiftCount=pattern1[j]; ShiftCount<=pattern1[j]; ShiftCount++)
    {
     digitalWrite(LatchClock,LOW);
     shiftOut(datapin, ShiftClock, MSBFIRST, ShiftCount);
     digitalWrite(LatchClock,HIGH);
     delay(delayTime);
    }
   }
  
    for(int j=0; j<=7; j++)
    {
     for(int ShiftCount=pattern1[j]; ShiftCount<=pattern1[j]; ShiftCount++)
     {
      digitalWrite(LatchClock,LOW);
      shiftOut(datapin, ShiftClock, LSBFIRST, ShiftCount);
      digitalWrite(LatchClock,HIGH);
      delay(delayTime);
     }
    }
  break;
   
  case 2: //This is the second volume running values from string pattern2.
   for(int j=0; j<=7; j++)
   {
    for(int ShiftCount=pattern2[j]; ShiftCount<=pattern2[j]; ShiftCount++)
    {
     digitalWrite(LatchClock,LOW);
     shiftOut(datapin, ShiftClock, MSBFIRST, ShiftCount);
     digitalWrite(LatchClock,HIGH);
     delay(delayTime);
    }
   }
  
    for(int j=0; j<=7; j++)
    {
     for(int ShiftCount=pattern2[j]; ShiftCount<=pattern2[j]; ShiftCount++)
     {
      digitalWrite(LatchClock,LOW);
      shiftOut(datapin, ShiftClock, LSBFIRST, ShiftCount);
      digitalWrite(LatchClock,HIGH);
      delay(delayTime);
     }
    }
  break;
   
  case 3: //This is the third volume running values from string pattern3.
   for(int j=0; j<=7; j++)
   {
    for(int ShiftCount=pattern3[j]; ShiftCount<=pattern3[j]; ShiftCount++)
    {
     digitalWrite(LatchClock,LOW);
     shiftOut(datapin, ShiftClock, MSBFIRST, ShiftCount);
     digitalWrite(LatchClock,HIGH);
     delay(delayTime);
    }
   }
  
    for(int j=0; j<=7; j++)
    {
     for(int ShiftCount=pattern3[j]; ShiftCount<=pattern3[j]; ShiftCount++)
     {
      digitalWrite(LatchClock,LOW);
      shiftOut(datapin, ShiftClock, LSBFIRST, ShiftCount);
      digitalWrite(LatchClock,HIGH);
      delay(delayTime);
     }
    }
  break;
  
  case 4: //This is the fourth volume running values from string pattern4.
   for(int j=0; j<=7; j++)
   {
    for(int ShiftCount=pattern4[j]; ShiftCount<=pattern4[j]; ShiftCount++)
    {
     digitalWrite(LatchClock,LOW);
     shiftOut(datapin, ShiftClock, MSBFIRST, ShiftCount);
     digitalWrite(LatchClock,HIGH);
     delay(delayTime);
    }
   }
  
    for(int j=0; j<=7; j++)
    {
     for(int ShiftCount=pattern4[j]; ShiftCount<=pattern4[j]; ShiftCount++)
     {
      digitalWrite(LatchClock,LOW);
      shiftOut(datapin, ShiftClock, LSBFIRST, ShiftCount);
      digitalWrite(LatchClock,HIGH);
      delay(delayTime);
     }
    }
  break; 
   
  case 5: //This is the fifth volume running values from string pattern5.
   for(int j=0; j<=7; j++)
   {
    for(int ShiftCount=pattern5[j]; ShiftCount<=pattern5[j]; ShiftCount++)
    {
     digitalWrite(LatchClock,LOW);
     shiftOut(datapin, ShiftClock, MSBFIRST, ShiftCount);
     digitalWrite(LatchClock,HIGH);
     delay(delayTime);
    }
   }
  
    for(int j=0; j<=7; j++)
    {
     for(int ShiftCount=pattern5[j]; ShiftCount<=pattern5[j]; ShiftCount++)
     {
      digitalWrite(LatchClock,LOW);
      shiftOut(datapin, ShiftClock, LSBFIRST, ShiftCount);
      digitalWrite(LatchClock,HIGH);
      delay(delayTime);
     }
    }
  break; 
   
  default: //This is the Zeroth volume running values from string pattern0.
   for(int j=0; j<=7; j++)
   {
    for(int ShiftCount=pattern0[j]; ShiftCount<=pattern0[j]; ShiftCount++)
    {
     digitalWrite(LatchClock,LOW);
     shiftOut(datapin, ShiftClock, MSBFIRST, ShiftCount);
     digitalWrite(LatchClock,HIGH);
     delay(delayTime);
    }
   } 
   
  }   //Switch end
}  //Loop end
   