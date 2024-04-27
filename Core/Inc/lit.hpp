/*
 * lit.h
 *
 *  Created on: Apr 16, 2024
 *      Author: owner
 */

#ifndef INC_LIT_HPP_
#define INC_LIT_HPP_


#include "main.h"

#include "stm32l4xx_hal.h"

#define LD0  0
#define LD1  1
#define LD2  2
#define LD3  3
#define LD4  4
#define LD5  5
#define LD6  6
#define LD7  7
#define LD8  8
#define LD9  9
#define LD10  10



extern uint8_t hour;
extern uint8_t minute;
extern uint8_t second;


extern GPIO_TypeDef* gpio_port[11];
extern uint16_t gpio_pin[11];
extern uint8_t led_wiring[72][2];




void setHiZ(GPIO_TypeDef* port, uint16_t pin);
void output(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState state);
void unlit();
void litLED(uint8_t num);

void setHour(uint8_t _hour);
void setMinute(uint8_t _minute);
void setSecond(uint8_t _second);


#endif /* INC_LIT_HPP_ */
