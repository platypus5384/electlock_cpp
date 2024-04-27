/*
 * AdjustClock.hpp
 *
 *  Created on: Apr 17, 2024
 *      Author: owner
 */

#ifndef INC_ADJUSTCLOCK_HPP_
#define INC_ADJUSTCLOCK_HPP_


#include "Application.hpp"
#include "AppArg.hpp"
#include "lit.hpp"

class AdjustClock : public Application
{
private:
  RTC_TimeTypeDef gTime;
  RTC_DateTypeDef gDate;

  int8_t hour;
  int8_t min;
  int8_t sec;

  int8_t move_num;
  uint8_t mode_hms;

public:
  AdjustClock(AppArg *apparg);
  ~AdjustClock();

  void run(AppArg *apparg);
};



#endif /* INC_ADJUSTCLOCK_HPP_ */
