################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/IamSrc/AdjustClock.cpp \
../Core/IamSrc/Application.cpp \
../Core/IamSrc/InputPin.cpp \
../Core/IamSrc/SimpleClock.cpp \
../Core/IamSrc/lit.cpp 

OBJS += \
./Core/IamSrc/AdjustClock.o \
./Core/IamSrc/Application.o \
./Core/IamSrc/InputPin.o \
./Core/IamSrc/SimpleClock.o \
./Core/IamSrc/lit.o 

CPP_DEPS += \
./Core/IamSrc/AdjustClock.d \
./Core/IamSrc/Application.d \
./Core/IamSrc/InputPin.d \
./Core/IamSrc/SimpleClock.d \
./Core/IamSrc/lit.d 


# Each subdirectory must supply rules for building sources it contributes
Core/IamSrc/%.o Core/IamSrc/%.su Core/IamSrc/%.cyclo: ../Core/IamSrc/%.cpp Core/IamSrc/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-IamSrc

clean-Core-2f-IamSrc:
	-$(RM) ./Core/IamSrc/AdjustClock.cyclo ./Core/IamSrc/AdjustClock.d ./Core/IamSrc/AdjustClock.o ./Core/IamSrc/AdjustClock.su ./Core/IamSrc/Application.cyclo ./Core/IamSrc/Application.d ./Core/IamSrc/Application.o ./Core/IamSrc/Application.su ./Core/IamSrc/InputPin.cyclo ./Core/IamSrc/InputPin.d ./Core/IamSrc/InputPin.o ./Core/IamSrc/InputPin.su ./Core/IamSrc/SimpleClock.cyclo ./Core/IamSrc/SimpleClock.d ./Core/IamSrc/SimpleClock.o ./Core/IamSrc/SimpleClock.su ./Core/IamSrc/lit.cyclo ./Core/IamSrc/lit.d ./Core/IamSrc/lit.o ./Core/IamSrc/lit.su

.PHONY: clean-Core-2f-IamSrc

