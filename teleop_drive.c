#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorA,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorB,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define MAX_RADIUS 95
#define MAX_ROTATION 5
#define MAX_RADIUS_INPUT 141
#define MIN_DELTA 5


int HIGH_SPEED = 65; //high speed setting
int LOW_SPEED = 25; //low speed setting
int MAX_SPEED = 65; //starting speed not max

#include "JoystickDriver.c"

void drive( float radius, float angle, float rotation );

bool pressed;

task main() {
	HIGH_SPEED=HIGH_SPEED/100;
	LOW_SPEED=LOW_SPEED/100;
	MAX_SPEED=MAX_SPEED/100;
	while( true ) {

	getJoystickSettings( joystick );

		if(joy1Btn(11)==1){
			pressed=true;           //speed button setings
			}else if(pressed==true){
			if(MAX_SPEED==HIGH_SPEED){
				MAX_SPEED=LOW_SPEED;
				pressed=false;
				}else{
				MAX_SPEED=HIGH_SPEED;
				pressed=false;
			}
		}

		float x = joystick.joy1_x1;//reads left joystick values y/x
		float y = joystick.joy1_y1;
		if( abs(x) < MIN_DELTA ){//thresholds
			x = 0;
		}
		if(abs(y) < MIN_DELTA){//thresholds
			y = 0;
		}
		float radius = sqrt(( x*x )+( y*y ));//finds radius from origin
		float angle = atan2( y, x );//finds angle pheta

		float rotation = joystick.joy1_x2;//reads right joystick values x

		if(abs(rotation)< MIN_DELTA){//thresholds
			rotation = 0;
		}


		drive( radius, angle, rotation );
	}
}

void drive( float radius, /* 0 - 141 */
float angle, /* 0 - 2PI ( Radians ) */
float rotation ) { /* -100 - 100 */
	if ( radius < 0 ) {//prevents negative radius
		radius = 0;
		} else if ( radius > MAX_RADIUS_INPUT ) {//threshold of radius
		radius = MAX_RADIUS_INPUT;
	}

	while ( angle < 0 ) { //if angle is less than 0 keep adding 360 till greater than 0
		angle += 2 * PI;   //360 = 2PI
	}

	while ( angle > 2 * PI ) {//if angle is more than 360 keep subtract 360 till less that 360
		angle -= 2 * PI;//360 = 2 PI
	}
	//rotation = rotation * .75;//so values dont exeed 127
	if ( rotation < -100 ) {
		rotation = -100;
	}

	if ( rotation > 100 ) {
		rotation = 100;
	}

	rotation = MAX_ROTATION * rotation; // max rotation number conversion *.05
	rotation = rotation/100;

	radius = MAX_RADIUS * radius; // max rotation munber
	radius = radius/141;

	angle -= PI / 4; // turns omni axis 45 into joystick axis

	int y = (sin( angle ) * radius );//finds y value from polar
	int x = (cos( angle ) * radius );//finds x value from polar

	int a = x + rotation;//adds rotation
	int b = x - rotation;
	int c = y + rotation;
	int d = y - rotation;

	motor[ motorB ]= a * MAX_SPEED;//speed conversions
	motor[ motorD ]= b * MAX_SPEED;
	motor[ motorA ]= c * MAX_SPEED;
	motor[ motorC ]= d * MAX_SPEED;
}
