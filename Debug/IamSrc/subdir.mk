################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../IamSrc/InputPin.cpp 

C_SRCS += \
../IamSrc/lit.c 

C_DEPS += \
./IamSrc/lit.d 

OBJS += \
./IamSrc/InputPin.o \
./IamSrc/lit.o 

CPP_DEPS += \
./IamSrc/InputPin.d 


# Each subdirectory must supply rules for building sources it contributes
IamSrc/%.o IamSrc/%.su IamSrc/%.cyclo: ../IamSrc/%.cpp IamSrc/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
IamSrc/%.o IamSrc/%.su IamSrc/%.cyclo: ../IamSrc/%.c IamSrc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-IamSrc

clean-IamSrc:
	-$(RM) ./IamSrc/InputPin.cyclo ./IamSrc/InputPin.d ./IamSrc/InputPin.o ./IamSrc/InputPin.su ./IamSrc/lit.cyclo ./IamSrc/lit.d ./IamSrc/lit.o ./IamSrc/lit.su

.PHONY: clean-IamSrc

