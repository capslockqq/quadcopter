#!/bin/bash
cd ..
cd build_target
make
cd ..
cd flash

avrdude -c arduino -p m328p -P /dev/ttyACM0 -U flash:w:../build_target/avr_code/Quadcopter-atmega328p.hex
