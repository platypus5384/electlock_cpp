/*
 * SimpleClock.hpp
 *
 *  Created on: Apr 16, 2024
 *      Author: owner
 */

#ifndef INC_SIMPLECLOCK_HPP_
#define INC_SIMPLECLOCK_HPP_

#include "stm32l4xx_hal.h"
#include "Application.hpp"

#include "AppArg.hpp"

#include "lit.hpp"

extern uint32_t start_ms;

class SimpleClock : public Application
{
private:
  RTC_TimeTypeDef gTime;
  RTC_DateTypeDef gDate;

  bool disp_mode;
  
public:
//

  SimpleClock(AppArg *apparg);


  ~SimpleClock();

  void run(AppArg *apparg);
};

#endif /* INC_SIMPLECLOCK_HPP_ */
