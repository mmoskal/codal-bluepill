#!/bin/sh
arm-none-eabi-gdb --eval "target remote | openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg -f debug.cfg" build/STM32
