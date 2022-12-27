#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mapping_interface.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "TIMERS_interface.h"

#include "Servo_interface.h"
#include "Servo_config.h"
#include "Servo_private.h"

MAP_T ServoAngleMap = {0, 100, 4000, 13500};

Servo_t servo1 = {SERVO_1_PORT, SERVO_1_PIN, SERVO_1_TIMER, SERVO_1_CHANNEL,SERVO_1_ENABLE};
Servo_t servo2 = {SERVO_2_PORT, SERVO_2_PIN, SERVO_2_TIMER, SERVO_2_CHANNEL,SERVO_2_ENABLE};
Servo_t servo3 = {SERVO_3_PORT, SERVO_3_PIN, SERVO_3_TIMER, SERVO_3_CHANNEL,SERVO_3_ENABLE};
Servo_t servo4 = {SERVO_4_PORT, SERVO_4_PIN, SERVO_4_TIMER, SERVO_4_CHANNEL,SERVO_4_ENABLE};
Servo_t servo5 = {SERVO_5_PORT, SERVO_5_PIN, SERVO_5_TIMER, SERVO_5_CHANNEL,SERVO_5_ENABLE};
Servo_t servo6 = {SERVO_6_PORT, SERVO_6_PIN, SERVO_6_TIMER, SERVO_6_CHANNEL,SERVO_6_ENABLE};
Servo_t servo7 = {SERVO_7_PORT, SERVO_7_PIN, SERVO_7_TIMER, SERVO_7_CHANNEL,SERVO_7_ENABLE};

Servo_t  Servo_attach(u8 Copy_u8Port,u8 Copy_u8Pin) {

	Servo_t servo = {Copy_u8Port, Copy_u8Pin, 0, 0, YES};
	GPIO_u8SetPinMode(servo.ServoPort, servo.ServoPin, GPIO_PIN_MODE_AF_PP_10MHZ);


	switch(Copy_u8Port) {
	case(GPIO_PORTA):
			switch(Copy_u8Pin){
			case(GPIO_PIN1): servo.ServoTimer = TIMER2; servo.ServoChannel = CHANNEL2; break;
			case(GPIO_PIN2): servo.ServoTimer = TIMER2; servo.ServoChannel = CHANNEL3; break;
			case(GPIO_PIN3): servo.ServoTimer = TIMER2; servo.ServoChannel = CHANNEL4; break;
			case(GPIO_PIN6): servo.ServoTimer = TIMER3; servo.ServoChannel = CHANNEL1; break;
			case(GPIO_PIN7): servo.ServoTimer = TIMER3; servo.ServoChannel = CHANNEL2; break;
			default: break;
			}
			break;
	case(GPIO_PORTB):
			switch(Copy_u8Pin){
			case(GPIO_PIN0): servo.ServoTimer = TIMER3; servo.ServoChannel = CHANNEL3; break;
			case(GPIO_PIN1): servo.ServoTimer = TIMER3; servo.ServoChannel = CHANNEL4; break;
			case(GPIO_PIN3): servo.ServoTimer = TIMER2; servo.ServoChannel = CHANNEL2; break;
			case(GPIO_PIN4): servo.ServoTimer = TIMER3; servo.ServoChannel = CHANNEL1; break;
			case(GPIO_PIN5): servo.ServoTimer = TIMER2; servo.ServoChannel = CHANNEL2; break;
			default: break;
			}
			break;
	}

	return servo;

}



void Servo_init(void) {

	TIMER2_init();
	TIMER3_init();

}


void Servo_setAngle(Servo_t Servo, u16 Copy_u16Angle) {

	u16 Local_u16MappedValue = Map_s32(&ServoAngleMap, Copy_u16Angle);
	TIMERS_setCompareMatchValue(Servo.ServoTimer, Servo.ServoChannel, Local_u16MappedValue);

}



