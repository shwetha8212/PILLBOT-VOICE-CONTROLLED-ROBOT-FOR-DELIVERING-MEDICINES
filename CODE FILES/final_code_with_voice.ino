

#include <AFMotor.h>

String voice;
AF_DCMotor motor1 (1, MOTOR12_1KHZ);  //create motor #1 using M1 output on Motor Driver Shield, set to 1Khz PWM frequency
AF_DCMotor motor2 (2, MOTOR12_1KHZ);  //create motor #2 using M1 output on Motor Driver Shield, set to 1Khz PWM frequency
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor1.setSpeed(255); //Define maximum velocity
  motor2.setSpeed(255); //Define maximum velocity
}

void loop() {
  if(Serial.available()>0)
  {
    voice=Serial.readStringUntil('\n');
    Serial.println(voice);
    if(voice=="room 1" or voice=="ROOM 1" or voice=="Roman" or voice=="room one" or voice=="ROOM ONE")
    {
     line_follower();
      //turn left if node detected
          motor2.run(FORWARD); 
    motor1.run(FORWARD);
    delay(300);
    motor2.run(BACKWARD); 
    motor1.run(FORWARD);
    delay(500);
    line_follower();
    //Reached Node
    delay(2000);
    //Take 180 degree turn
    motor2.run(FORWARD); 
    motor1.run(BACKWARD);
    delay(1000);

    line_follower();

    //Turn right if node detected 
              motor2.run(FORWARD); 
    motor1.run(FORWARD);
    delay(300);
        motor2.run(FORWARD); 
    motor1.run(BACKWARD);
    delay(500);

    line_follower();
    //HOME NODE DETECTED , 180 degree turn right and stop
    motor2.run(FORWARD); 
    motor1.run(BACKWARD);
    delay(1500);
    motor1.run(RELEASE); 
    motor2.run(RELEASE);
    
    }
    else if(voice=="room 2" or voice=="ROOM 2" or voice=="room to" or voice=="room too" or voice=="ROOM TWO")
    {
       line_follower();
      //GO FORWARD if node detected
    motor2.run(FORWARD); 
    motor1.run(FORWARD);
    delay(500);
    line_follower();
    //Reached Node
    delay(2000);
    //Take 180 degree turn
    motor2.run(FORWARD); 
    motor1.run(BACKWARD);
    delay(1000);

    line_follower();

    //GO FORWARD if node detected 
        motor2.run(FORWARD); 
    motor1.run(FORWARD);
    delay(500);

    line_follower();
    //HOME NODE DETECTED , 180 degree turn right and stop
    motor2.run(FORWARD); 
    motor1.run(BACKWARD);
    delay(1500);
    motor2.run(RELEASE); 
    motor1.run(RELEASE);
    }
    else if(voice=="room 3" or voice=="ROOM 3" or voice=="Dhoom 3" or voice=="room three" or voice=="ROOM THREE")
    {
    line_follower();
              motor2.run(FORWARD); 
    motor1.run(FORWARD);
    delay(300);
      //Turn right if node detected
    motor2.run(FORWARD); 
    motor1.run(BACKWARD);
    delay(500);
    line_follower();
    //Reached Node
    delay(2000);
    //Take 180 degree turn
    motor2.run(FORWARD); 
    motor1.run(BACKWARD);
    delay(1000);

    line_follower();

    //TURN LEFT if node detected 
              motor2.run(FORWARD); 
    motor1.run(FORWARD);
    delay(300);
        motor2.run(BACKWARD); 
    motor1.run(FORWARD);
    delay(500);

    line_follower();
    //HOME NODE DETECTED , 180 degree turn right and stop
    motor2.run(FORWARD); 
    motor1.run(BACKWARD);
    delay(1500);
    motor1.run(RELEASE); 
    motor2.run(RELEASE);
    }
  }
}

void line_follower()
{
  int a0,a1,a2;
  a0=analogRead(A0);
  a1=analogRead(A1);
  a2=analogRead(A2);

  
  while(true)
  {
  a0=analogRead(A0);
  a1=analogRead(A1);
  a2=analogRead(A2);
    Serial.print(a0);
    Serial.print("\t");
        Serial.print(a1);
    Serial.print("\t");
        Serial.println(a2);
  if(a0<100 && a1>900 && a2<100)
  {
    //Forward

    motor1.run(FORWARD); 

    motor2.run(FORWARD);  
    Serial.println("Forward"); 
  }
  else if(a0>900 && a2<100)
  {
    //Left
    Serial.println("Left");

    motor2.run(BACKWARD); 

    motor1.run(FORWARD); 
  }
    else if(a2>900 && a0<100)
  {
    //Right
        Serial.println("Right");

    motor2.run(FORWARD);
    motor1.run(BACKWARD); 
  }
  else if(a0>900 && a1>900 && a2>900)
  {
    //stop 
    motor1.run(RELEASE); 
    motor2.run(RELEASE); 
    break;
  }
  }
}
