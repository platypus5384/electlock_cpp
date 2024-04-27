/*
 * Application.hpp
 *
 *  Created on: Apr 16, 2024
 *      Author: owner
 */

#ifndef INC_APPLICATION_HPP_
#define INC_APPLICATION_HPP_


#include "AppArg.hpp"

class Application
{
public:
  Application(AppArg *apparg);
  ~Application();

  virtual void run(AppArg* apparg);
};

#endif /* INC_APPLICATION_HPP_ */
