cd ..
cd build_target
make
cd ..
cd flash
avrdude -C /etc/avrdude.conf -v -p atmega328p -c arduino -P /dev/ttyACM0 -b 115200 -D -U flash:w:../build_target/avr_code/Quadcopter-atmega32.hex:i
