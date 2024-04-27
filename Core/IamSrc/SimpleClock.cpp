/*
 * SimpleClock.cpp
 *
 *  Created on: Apr 16, 2024
 *      Author: owner
 */

#include "SimpleClock.hpp"

SimpleClock::SimpleClock(AppArg *apparg) : Application(apparg)
{
  setHour(0);
  setMinute(0);
  setSecond(0);

  disp_mode = false;
};

SimpleClock::~SimpleClock(){};

void SimpleClock::run(AppArg *apparg)
{
  HAL_RTC_GetTime(apparg->hrtc.get(), &gTime, RTC_FORMAT_BIN);
  HAL_RTC_GetDate(apparg->hrtc.get(), &gDate, RTC_FORMAT_BIN);

  if (apparg->sw2->getFirstHold())
  {
    disp_mode = !disp_mode;
  }

  if (disp_mode)
  {
    start_ms = HAL_GetTick();
  }


  setHour(gTime.Hours);
  setMinute(gTime.Minutes);
  setSecond(gTime.Seconds);
};
