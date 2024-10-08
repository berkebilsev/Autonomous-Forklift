#include "MeOrion.h"
//#include <Arduino.h>
#include "SoftwareSerial.h"
#include <Wire.h>

MeUSBHost usbhost(PORT_3);

MeEncoderNew motor1(0x09, SLOT1); 
MeEncoderNew motor2(0x09, SLOT2); 
MeEncoderNew motor3(0x0a, SLOT1); 
MeEncoderNew motor4(0x0a, SLOT2); 

#define PORT1_MOTOR1  11    //PWM Control Pin
#define PORT1_MOTOR2  10
#define PORT2_MOTOR1  3
#define PORT2_MOTOR2  9

int moveSpeed = 90;
uint8_t moveSpeed_FW =0;
uint8_t moveSpeed_BW =0;
unsigned char stop_flag=0;

void setup()
{
  usbhost.init(USB1_0);   //USB Remote Control Handle Initialization
  Serial.begin(9600);
  motor1.begin();
  motor2.begin();
  motor3.begin();
  motor4.begin();
  
  motor1.reset();
  motor2.reset();
  motor3.reset();
  motor4.reset();

  motor1.setMode(1);  //0:I2C_MODE;1:PWM_MODE;2:PWM_I2C_PWM;
  motor2.setMode(1);
  motor3.setMode(1);  //0:I2C_MODE;1:PWM_MODE;2:PWM_I2C_PWM;
  motor4.setMode(1);

  pinMode(PORT1_MOTOR1, OUTPUT);
  pinMode(PORT1_MOTOR2, OUTPUT);
  pinMode(PORT2_MOTOR1, OUTPUT);
  pinMode(PORT2_MOTOR2, OUTPUT);

  analogWrite(PORT1_MOTOR1, 127);
  analogWrite(PORT1_MOTOR2, 127);
  analogWrite(PORT2_MOTOR1, 127);
  analogWrite(PORT2_MOTOR2, 127);
}

void loop()
{
 moveSpeed_FW=moveSpeed/2+125;    //Speed conversion
 moveSpeed_BW=125-moveSpeed/2;
 Forward_run();
 delay(3000);
 Backward_rum();
 delay(3000);
 Right_run();
 delay(3000);
 Left_run();
 delay(3000); 
 RightDown_run();
 delay(3000); 
 LeftDown_run();
 delay(3000); 
 RightUp_run();
 delay(3000); 
 LeftUp_run();
 delay(3000); 

}




void Forward_run() 
{  
  analogWrite(PORT1_MOTOR1, moveSpeed_FW);
  analogWrite(PORT1_MOTOR2, moveSpeed_BW);
  analogWrite(PORT2_MOTOR1, moveSpeed_BW);
  analogWrite(PORT2_MOTOR2, moveSpeed_FW);
}
void Backward_rum() 
{
  analogWrite(PORT1_MOTOR1, moveSpeed_BW);
  analogWrite(PORT1_MOTOR2, moveSpeed_FW);
  analogWrite(PORT2_MOTOR1, moveSpeed_FW);
  analogWrite(PORT2_MOTOR2, moveSpeed_BW);
}
void Right_run()  
{
  analogWrite(PORT1_MOTOR1, moveSpeed_BW);
  analogWrite(PORT1_MOTOR2, moveSpeed_BW);
  analogWrite(PORT2_MOTOR1, moveSpeed_FW);
  analogWrite(PORT2_MOTOR2, moveSpeed_FW);
}
void Left_run()  
{
//  analogWrite(PORT1_MOTOR1, moveSpeed_BW);
//  analogWrite(PORT1_MOTOR2, moveSpeed_BW);
//  analogWrite(PORT2_MOTOR1, moveSpeed_FW);
//  analogWrite(PORT2_MOTOR2, moveSpeed_FW);
  analogWrite(PORT1_MOTOR1, moveSpeed_FW);
  analogWrite(PORT1_MOTOR2, moveSpeed_FW);
  analogWrite(PORT2_MOTOR1, moveSpeed_BW);
  analogWrite(PORT2_MOTOR2, moveSpeed_BW);
}
void RightDown_run()
{
  analogWrite(PORT1_MOTOR1, moveSpeed_BW);
  analogWrite(PORT1_MOTOR2, 127);
  analogWrite(PORT2_MOTOR1, moveSpeed_FW);
  analogWrite(PORT2_MOTOR2, 127);
}
void RightUp_run()
{
  analogWrite(PORT1_MOTOR1, 127);
  analogWrite(PORT1_MOTOR2, moveSpeed_BW);
  analogWrite(PORT2_MOTOR1, 127);
  analogWrite(PORT2_MOTOR2, moveSpeed_FW);
}
void LeftDown_run()
{
  analogWrite(PORT1_MOTOR1, 127);
  analogWrite(PORT1_MOTOR2, moveSpeed_FW);
  analogWrite(PORT2_MOTOR1, 127);
  analogWrite(PORT2_MOTOR2, moveSpeed_BW);
}
void LeftUp_run()
{
  analogWrite(PORT1_MOTOR1, moveSpeed_FW);
  analogWrite(PORT1_MOTOR2, 127);
  analogWrite(PORT2_MOTOR1, moveSpeed_BW);
  analogWrite(PORT2_MOTOR2, 127);
}
void TurnRight_run()
{
  analogWrite(PORT1_MOTOR1, moveSpeed_BW);
  analogWrite(PORT1_MOTOR2, moveSpeed_BW);
  analogWrite(PORT2_MOTOR1, moveSpeed_BW);
  analogWrite(PORT2_MOTOR2, moveSpeed_BW);
}
void TurnLeft_run()
{
  analogWrite(PORT1_MOTOR1, moveSpeed_FW);
  analogWrite(PORT1_MOTOR2, moveSpeed_FW);
  analogWrite(PORT2_MOTOR1, moveSpeed_FW);
  analogWrite(PORT2_MOTOR2, moveSpeed_FW);
}

void Speed_up()
{
  moveSpeed=moveSpeed+3;
  if(moveSpeed>250)  moveSpeed=250;
}
void Speed_down()
{
   moveSpeed=moveSpeed-3;
  if(moveSpeed<0)  moveSpeed=0;
}
void Stop_run()
{
  analogWrite(PORT1_MOTOR1, 127);
  analogWrite(PORT1_MOTOR2, 127);
  analogWrite(PORT2_MOTOR1, 127);
  analogWrite(PORT2_MOTOR2, 127);
}



