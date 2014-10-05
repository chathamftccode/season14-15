#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S2,     lightSensor,    sensorLightActive)
#pragma config(Sensor, S3,     sonarSensor,    sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

int servoPos = 0;

void autonomous() {

	wait1Msec(50);
	while(SensorValue[sonarSensor] > 30)                           // Infinite loop
	{
		motor[motorD] = 50;
		motor[motorE] = 50;
		wait1Msec(4);

		if(SensorValue[lightSensor] < 286 )  // If the Light Sensor reads a value less than 300:
		{

			motor[motorD] = 60;
			motor[motorE] = 20;
			wait1Msec(50);
		}
		else                               // If the Light Sensor reads a value greater than or equal to 45:
		{
			motor[motorD] = 20;                  // Motor B is run at a 20 power level.
			motor[motorE] = 60;                  // Motor C is run at a 60 power level.
			wait1Msec(50);
		}
	}
	motor[motorE] = 50;
	motor[motorD] = -50;
  wait1Msec(500);
  motor[motorD] = 0;
  motor[motorE] = 0;
	servo[servo1] = 255;
}

void getControls() {
	while(true) {
		getJoystickSettings(joystick);
		if(abs(joystick.joy1_y1) < 5)
		{
			motor[motorD] = 0;
		}
		else
		{
			motor[motorD] = joystick.joy1_y1;
		}

		if(abs(joystick.joy1_y2) < 5)
		{
			motor[motorE] = 0;
		}
		else
		{
			motor[motorE] = joystick.joy1_y2;
		}

		if(joy1Btn(1) == 1)
		{
			servo[servo2] = 255;
		}

		if(joy1Btn(3) == 1)
		{
			servo[servo2] = 110;
		}

		if(joy1Btn(2) == 1)
		{
			servo[servo2] = 193;
		}

		if(joy1Btn(6) == 1)
		{
			servo[servo1] = 1;
		}

		if(joy1Btn(5) == 1)
		{
			servo[servo1] = 180;
		}

	}
}


//IMPORTANT: minimize number of called functions in task main()
task main() {
	waitForStart();
	//autonomous();
	getControls();
}
