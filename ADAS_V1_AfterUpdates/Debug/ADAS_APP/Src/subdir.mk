################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADAS_APP/Src/AB.c \
../ADAS_APP/Src/FCA.c \
../ADAS_APP/Src/FCW.c 

OBJS += \
./ADAS_APP/Src/AB.o \
./ADAS_APP/Src/FCA.o \
./ADAS_APP/Src/FCW.o 

C_DEPS += \
./ADAS_APP/Src/AB.d \
./ADAS_APP/Src/FCA.d \
./ADAS_APP/Src/FCW.d 


# Each subdirectory must supply rules for building sources it contributes
ADAS_APP/Src/%.o ADAS_APP/Src/%.su ADAS_APP/Src/%.cyclo: ../ADAS_APP/Src/%.c ADAS_APP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I"D:/Courses/1.NTI embedded automotive/Graduation project/ADAS_V1_AfterUpdates/ECUL/Inc" -I"D:/Courses/1.NTI embedded automotive/Graduation project/ADAS_V1_AfterUpdates/ADAS_APP/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ADAS_APP-2f-Src

clean-ADAS_APP-2f-Src:
	-$(RM) ./ADAS_APP/Src/AB.cyclo ./ADAS_APP/Src/AB.d ./ADAS_APP/Src/AB.o ./ADAS_APP/Src/AB.su ./ADAS_APP/Src/FCA.cyclo ./ADAS_APP/Src/FCA.d ./ADAS_APP/Src/FCA.o ./ADAS_APP/Src/FCA.su ./ADAS_APP/Src/FCW.cyclo ./ADAS_APP/Src/FCW.d ./ADAS_APP/Src/FCW.o ./ADAS_APP/Src/FCW.su

.PHONY: clean-ADAS_APP-2f-Src

