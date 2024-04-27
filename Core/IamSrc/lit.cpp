/*
 * lit.c
 *
 *  Created on: Apr 16, 2024
 *      Author: owner
 */

#include <lit.hpp>



uint8_t hour = 0;
uint8_t minute = 0;
uint8_t second = 0;

GPIO_TypeDef* gpio_port[11] = {LED1_GPIO_Port, LED2_GPIO_Port, LED3_GPIO_Port, LED4_GPIO_Port, LED5_GPIO_Port, LED6_GPIO_Port, LED7_GPIO_Port, LED8_GPIO_Port, LED9_GPIO_Port, LED10_GPIO_Port, LED11_GPIO_Port};
uint16_t gpio_pin[11] = {LED1_Pin, LED2_Pin, LED3_Pin, LED4_Pin, LED5_Pin, LED6_Pin, LED7_Pin, LED8_Pin, LED9_Pin, LED10_Pin, LED11_Pin};
uint8_t led_wiring[72][2] = {
		{ LD3, LD1},
		{ LD1, LD7},
		{ LD1, LD6},
		{ LD1, LD5},
		{ LD1, LD4},
		{ LD1, LD3},
		{ LD7, LD0},
		{ LD6, LD0},
		{ LD5, LD0},
		{ LD4, LD0},
		{ LD3, LD0},

		{ LD0, LD7},
		{ LD0, LD6},
		{ LD0, LD5},
		{ LD0, LD4},
		{ LD0, LD3},
		{ LD8, LD6},
		{ LD8, LD5},
		{ LD8, LD4},
		{ LD8, LD3},
		{ LD8, LD7},

		{ LD6, LD8},
		{ LD5, LD8},
		{ LD4, LD8},
		{ LD3, LD8},
		{ LD7, LD8},
		{ LD9, LD6},
		{ LD9, LD5},
		{ LD9, LD4},
		{ LD9, LD3},
		{ LD9, LD7},

		{ LD6, LD9},
		{ LD5, LD9},
		{ LD4, LD9},
		{ LD3, LD9},
		{ LD7, LD9},
		{LD10, LD6},
		{LD10, LD5},
		{LD10, LD4},
		{LD10, LD3},
		{LD10, LD7},

		{ LD6,LD10},
		{ LD5,LD10},
		{ LD4,LD10},
		{ LD3,LD10},
		{ LD7,LD10},
		{ LD7, LD2},
		{ LD6, LD2},
		{ LD5, LD2},
		{ LD4, LD2},
		{ LD3, LD2},

		{ LD2, LD7},
		{ LD2, LD6},
		{ LD2, LD5},
		{ LD2, LD4},
		{ LD2, LD3},
		{ LD7, LD1},
		{ LD6, LD1},
		{ LD5, LD1},
		{ LD4, LD1},


		//-------------------------
		{ LD5, LD3},
		{ LD3, LD5},
		{ LD4, LD3},
		{ LD3, LD4},
		{ LD7, LD4},
		{ LD4, LD7},

		{ LD7, LD5},
		{ LD5, LD7},
		{ LD7, LD6},
		{ LD6, LD7},
		{ LD6, LD3},
		{ LD3, LD6},
};



void setHiZ(GPIO_TypeDef* port, uint16_t pin){
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(port , &GPIO_InitStruct);
}

void output(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState state){
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(port, &GPIO_InitStruct);

	HAL_GPIO_WritePin(port, pin, state);
}

void unlit(){
	for (uint8_t i=0; i<11; i++){
		setHiZ(gpio_port[i], gpio_pin[i]);
	}
}

void litLED(uint8_t num){
	GPIO_TypeDef* p_port, *n_port;
	uint16_t p_pin, n_pin;

	unlit();

	p_port = gpio_port[led_wiring[num][1]];
	p_pin = gpio_pin[led_wiring[num][1]];
	n_port = gpio_port[led_wiring[num][0]];
	n_pin = gpio_pin[led_wiring[num][0]];
	output(p_port, p_pin, GPIO_PIN_SET);
	output(n_port, n_pin, GPIO_PIN_RESET);
}


void setHour(uint8_t _hour)
{
  static uint8_t _b = 0xff;
  if (_b == _hour)
    return;
  _hour = _hour < 0 ? 0 : _hour;
  _hour = _hour > 23 ? 23 : _hour;
  hour = _hour % 12;
  _b = _hour;
}

void setMinute(uint8_t _minute)
{
  static uint8_t _b = 0xff;
  if (_b == _minute)
    return;
  _minute = _minute < 0 ? 0 : _minute;
  _minute = _minute > 59 ? 59 : _minute;
  minute = _minute;
  _b = _minute;
}

void setSecond(uint8_t _second)
{
  static uint8_t _b = 0xff;
  if (_b == _second)
    return;
  _second = _second < 0 ? 0 : _second;
  _second = _second > 59 ? 59 : _second;
  second = _second;
  _b = _second;
}

#include <lit.hpp>
