/*
 * InputPin.cpp
 *
 *  Created on: Feb 23, 2024
 *      Author: csmpp
 */


#include "InputPin.hpp"

InputPin::InputPin(GPIO_TypeDef *ptrPort, uint16_t pin, bool logic_invert){
	_ptrPort = ptrPort;
	_pin = pin;
	_logic_invert = logic_invert;

	_HOLD_MS = 1000;

	_pin_state = (HAL_GPIO_ReadPin(_ptrPort, _pin) == GPIO_PIN_SET);
	_pin_state ^= _logic_invert;
	_b_pin_state = _pin_state;

	_state = INPUTPIN_STATE_IDLE;
}

void InputPin::fetch(){
	_b_pin_state = _pin_state;
	_pin_state = (HAL_GPIO_ReadPin(_ptrPort, _pin) == GPIO_PIN_SET);
	_pin_state ^= _logic_invert;
}

void InputPin::update(){
	uint32_t time_now = HAL_GetTick();

	switch(_state){
	case INPUTPIN_FIRST_RELEASE:
	case INPUTPIN_FIRST_HOLD_RELEASE:
		_state = INPUTPIN_STATE_IDLE;
		break;
	}
	if (_pin_state == true){
		switch(_state){
		case INPUTPIN_STATE_IDLE:
			_state = INPUTPIN_FIRST_PRESS;
			_time_press = time_now;
			break;
		case INPUTPIN_FIRST_PRESS:
			_state = INPUTPIN_STATE_PRESS;
			break;
		case INPUTPIN_STATE_PRESS:
			if ((time_now - _time_press) > _HOLD_MS){
				_state = INPUTPIN_FIRST_HOLD;
			}
			break;
		case INPUTPIN_FIRST_HOLD:
			_state = INPUTPIN_STATE_HOLD;
			break;
		case INPUTPIN_STATE_HOLD:
			break;
		}
	}else{
		switch(_state){
		case INPUTPIN_FIRST_PRESS:
		case INPUTPIN_STATE_PRESS:
			_state = INPUTPIN_FIRST_RELEASE;
			break;
		case INPUTPIN_FIRST_HOLD:
		case INPUTPIN_STATE_HOLD:
			_state = INPUTPIN_FIRST_HOLD_RELEASE;
			break;
		}
	}
	_b_pin_state = _pin_state;
}

bool InputPin::get(){
  return _pin_state;
}

bool InputPin::getFirstPress(){
	return _state == INPUTPIN_FIRST_PRESS;
}

bool InputPin::getPress(){
	return _state == INPUTPIN_STATE_PRESS;
}

bool InputPin::getFirstHold(){
	return _state == INPUTPIN_FIRST_HOLD;
}

bool InputPin::getHold(){
	return _state == INPUTPIN_STATE_HOLD;
}

bool InputPin::getFirstRelease(){
	return _state == INPUTPIN_FIRST_RELEASE;
}

bool InputPin::getFirstHoldRelease(){
	return _state == INPUTPIN_FIRST_HOLD_RELEASE;
}
