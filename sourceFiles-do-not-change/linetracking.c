#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S3,     lightSensor,    sensorLightActive)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*--------------------------------------------------------------------------------------------------------*\
|*                                                                                                        *|
|*                                           - Line Tracker -                                             *|
|*                                            ROBOTC on NXT                                               *|
|*                                                                                                        *|
|*  This program allows your taskbot to follow a line in reverse.                                         *|
|*                                                                                                        *|
|*                                        ROBOT CONFIGURATION                                             *|
|*    NOTES:                                                                                              *|
|*    1)  The Light Sensor is attached to the back of the robot.                                          *|
|*    2)  Be sure to take readings of your Light Sensor over the light and dark areas.  Once you have     *|
|*        the values, add them and divide by 2 to find your threshold.  Then, use your threshold as a     *|
|*        comparison in your program.                                                                     *|
|*                                                                                                        *|
|*    MOTORS & SENSORS:                                                                                   *|
|*    [I/O Port]              [Name]              [Type]              [Description]                       *|
|*    Port B                  motorB              NXT                 Right motor                         *|
|*    Port C                  motorC              NXT                 Left motor                          *|
|*    Port 1                  lightSensor         Light Sensor        Back mounted                        *|
\*---------------------------------------------------------------------------------------------------4246-*/


task main()
{motor[motorD]=50;
	motor[motorE]=50;
	wait1Msec(4);
	wait1Msec(50);                        // The program waits 50 milliseconds to initialize the light sensor.

	{
		motor[motorD] = 50;
		motor[motorE] = 50;
		wait1Msec(4);
		if(SensorValue[lightSensor] < 45)  // If the Light Sensor reads a value less than 45:
		{
			motor[motorD] = 60;                  // Motor B is run at a 60 power level.
			motor[motorE] = 20;                  // Motor C is run at a 20 power level.
			wait1Msec(50);
		}
		else                               // If the Light Sensor reads a value greater than or equal to 45:
		{
			motor[motorD] = 20;                  // Motor B is run at a 20 power level.
			motor[motorE] = 60;                  // Motor C is run at a 60 power level.
			wait1Msec(50);
		}
	}
}