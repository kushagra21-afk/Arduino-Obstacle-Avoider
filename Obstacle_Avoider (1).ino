//The bot on encountering an obstacle first moves back and then moves in a particular direction.This is completely arbitrary,you can modify the same if you want
#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
void setup() {
  Serial.begin(9600);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
}

void loop() {
int sR = analogRead(A0);//Right sensor
int sL = analogRead(A2);//Left sensor 
int sM = analogRead(A5);//Middle sensor
  if(sR>600 && sL>600 && sM>600)//In the event of no obstacle being detected by any of the sensors
  {   
      motor1.run(FORWARD);
      motor2.run(FORWARD);
  }
  else if(sR<600 && sL>600)//If the right sensor is near an obstacle
  {   
      motor1.run(BACKWARD);//First move back for 1 second
      motor2.run(BACKWARD);
      delay(1000);
      motor1.run(FORWARD);//Then turn left for 1.5 seconds
      motor2.run(RELEASE);
      delay(1500);
  }
  else if(sR>600 && sL<600)//If the left sensor is near an obstacle
  {   
      motor1.run(BACKWARD);//First move back for 1 second
      motor2.run(BACKWARD);
      delay(1000);
      motor2.run(FORWARD);//Then turn right for 1.5 seconds
      motor1.run(RELEASE);
      delay(1500);
  }
  else if(sM<600)//If the middle sensor is near an obstacle
  {   
      motor1.run(BACKWARD);//First move back for 2 seconds
      motor2.run(BACKWARD);
      delay(2000);
       motor2.run(FORWARD);//Then turn right(arbitrary,you could go left too)
      motor1.run(RELEASE);//For 1.5 seconds
      delay(1500);
      
  }
  else//If its none of the above,just move backwards for 2 seconds
  {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    delay(2000);
  }
  delay(100);
}
