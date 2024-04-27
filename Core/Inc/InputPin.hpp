/*
 * InputPin.hpp
 *
 *  Created on: Feb 23, 2024
 *      Author: csmpp
 */

#ifndef IAMHEADER_INPUTPIN_HPP_
#define IAMHEADER_INPUTPIN_HPP_

#include "stm32l4xx_hal.h"
#include "main.h"


#define INPUTPIN_NEGATIVE_LOGIC true
#define INPUTPIN_POSITIVE_LOGIC false


typedef enum{
	INPUTPIN_STATE_IDLE,
	INPUTPIN_FIRST_PRESS,
	INPUTPIN_STATE_PRESS,
	INPUTPIN_FIRST_HOLD,
	INPUTPIN_STATE_HOLD,
	INPUTPIN_FIRST_RELEASE,
	INPUTPIN_FIRST_HOLD_RELEASE,
}INPUTPIN_STATE;

typedef struct{
	bool idle;
	bool first_press;
	bool state_press;
	bool first_hold;
	bool state_hold;
	bool first_release;
	bool first_hold_release;
	bool first_longhold_release;
}InputPinStateBit;


class InputPin{
private:
	GPIO_TypeDef *_ptrPort;
	uint16_t _pin;
	bool _logic_invert;
	uint16_t _HOLD_MS;
	uint32_t _time_press;

	INPUTPIN_STATE _state;
	bool _pin_state;
	bool _b_pin_state;


public:
	InputPin(GPIO_TypeDef *ptrPort, uint16_t pin, bool logic_invert=false);

	void fetch();
	void update();

  bool get();

	bool getFirstPress();
	bool getPress();
	bool getFirstHold();
	bool getHold();
	bool getFirstRelease();
	bool getFirstHoldRelease();


};

#endif /* IAMHEADER_INPUTPIN_HPP_ */
