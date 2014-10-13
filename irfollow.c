#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     HTIRS2,         sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//#include "HTDIR-driver.h"
#include "drivers/hitechnic-irseeker-v2.h"

int _dirEnh;
int _strEnh;

task main(){
	//HTDIRsetDSPMode(HTDIR, DSP_600);
	tHTIRS2DSPMode _mode = DSP_600;
	motor[motorD]=20;
	motor[motorE]=20;
	wait1Msec(3000);
	while(true){
		HTIRS2readEnhanced(HTIRS2, _dirEnh, _strEnh);
		nxtDisplayCenteredTextLine(3, "%d", _dirEnh);
		while(_dirEnh<5&&_dirEnh!=0){
			motor[motorD]=0;
			motor[motorE]=20;
			HTIRS2readEnhanced(HTIRS2, _dirEnh, _strEnh);
			nxtDisplayCenteredTextLine(3, "%d", _dirEnh);
			}while(_dirEnh>5){
			motor[motorE]=0;
			motor[motorD]=20;
			HTIRS2readEnhanced(HTIRS2, _dirEnh, _strEnh);
			nxtDisplayCenteredTextLine(3, "%d", _dirEnh);
			}while(_dirEnh==5){
			HTIRS2readEnhanced(HTIRS2, _dirEnh, _strEnh);
			if(_strEnh>=80){
				motor[motorE]=0;
				motor[motorD]=0;
				nxtDisplayCenteredTextLine(3, "%d", _strEnh);
				}else{
				motor[motorE]=10;
				motor[motorD]=10;
				nxtDisplayCenteredTextLine(3, "%d", _strEnh);
				}while(_dirEnh==0){
				motor[motorE]=20;
				motor[motorD]=20;
			}
		}
	}
}
