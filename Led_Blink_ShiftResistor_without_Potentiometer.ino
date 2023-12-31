int datapin = 4;
int clockpin = 5;
int latchpin = 6;
int masterReset = 3;
int outputEnable = 2;
int delayTime = 250;
int offLED = 250;
int pattern1[15] = {1,2,4,8,16,32,64,128,64,32,16,8,4,2,1};
int pattern2[15] = {1,2,4,8,16,32,64,128,129,65,33,17,9,5,3};

void setup()
{
  pinMode(datapin,OUTPUT);
  pinMode(clockpin,OUTPUT);
  pinMode(latchpin,OUTPUT);
  pinMode(masterReset,OUTPUT);
  
  digitalWrite(masterReset,HIGH);
  digitalWrite(outputEnable,LOW);
}

void loop()
{ //Loop Open
 
  //First Loop
  for(int i=0; i<=15; i++) 
  {
    //digitalWrite(masterReset,HIGH);
    digitalWrite(latchpin,LOW);
    shiftOut(datapin,clockpin,MSBFIRST,pattern1[i]);
    digitalWrite(latchpin,HIGH);
    delay(delayTime);
  }
  
  //Turn off all LEDs after the loop ends.
  /*
  digitalWrite(outputEnable,HIGH);
  delay(offLED);
  digitalWrite(outputEnable,LOW);
  */
  /*
  //Second Loop
  for(int i=7; i>=0; i--)
  {
    digitalWrite(latchpin,LOW);
    shiftOut(datapin,clockpin,MSBFIRST,pattern1F[i]);
    digitalWrite(latchpin,HIGH);
    delay(delayTime);
  }
 
  //Turn off all LEDs after the loop ends.
  /*
  digitalWrite(outputEnable,HIGH);
  delay(offLED);
  digitalWrite(outputEnable,LOW);
  */

} //Loop Ends