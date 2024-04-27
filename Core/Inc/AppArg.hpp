/*
 * AppArg.hpp
 *
 *  Created on: Apr 16, 2024
 *      Author: owner
 */

#ifndef INC_APPARG_HPP_
#define INC_APPARG_HPP_

#include <memory>
#include "InputPin.hpp"

typedef struct {
  std::unique_ptr<InputPin> sw1;
  std::unique_ptr<InputPin> sw2;
  std::unique_ptr<InputPin> sw3;


  std::unique_ptr<RTC_HandleTypeDef> hrtc;

  
}AppArg;


#endif /* INC_APPARG_HPP_ */
