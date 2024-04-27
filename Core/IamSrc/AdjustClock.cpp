/*
 * AdjustClock.cpp
 *
 *  Created on: Apr 17, 2024
 *      Author: owner
 */

#include "AdjustClock.hpp"

AdjustClock::AdjustClock(AppArg *apparg):
    Application(apparg)
{
  HAL_RTC_GetTime(apparg->hrtc.get(), &gTime, RTC_FORMAT_BIN);
  HAL_RTC_GetDate(apparg->hrtc.get(), &gDate, RTC_FORMAT_BIN);

  gTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  gTime.StoreOperation = RTC_STOREOPERATION_RESET;

  hour = gTime.Hours;
  min = gTime.Minutes;
  sec = gTime.Seconds;

  setHour(hour);
  setMinute(min);
  setSecond(sec);

  mode_hms = 0;
}

AdjustClock::~AdjustClock(){};

void AdjustClock::run(AppArg *apparg)
{
  move_num = 0;
  if (apparg->sw2->getFirstPress() || apparg->sw2->getHold())
  {
    move_num = 1;
  }

  if (apparg->sw3->getFirstPress() || apparg->sw3->getHold())
  {
    move_num = -1;
  }

  if (apparg->sw1->getFirstPress())
  {
    mode_hms++;
    if (mode_hms > 2)
    {
      mode_hms = 0;
      gTime.Hours = hour;
      gTime.Minutes = min;
      gTime.Seconds = sec;
      if (HAL_RTC_SetTime(apparg->hrtc.get(), &gTime, RTC_FORMAT_BIN) != HAL_OK)
      {
        // エラーハンドリング
        Error_Handler();
      }
    }
  }

  switch (mode_hms)
  {
  case 0:
    hour += move_num;
    hour = hour < 0 ? 11 : hour;
    hour = hour % 24;
    break;
  case 1:
    min += move_num;
    min = min < 0 ? 59 : min;
    min = min % 60;
    break;
  case 2:
    sec += move_num;
    sec = sec < 0 ? 59 : sec;
    sec = sec % 60;
    break;
  default:
    break;
  }

  setHour(hour);
  setMinute(min);
  setSecond(sec);
};