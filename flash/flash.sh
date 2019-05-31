cd ..
cd build_target
make
cd ..
cd flash
avrdude -C /etc/avrdude.conf -v -p atmega328p -c arduino -P /dev/ttyACM0 -b 115200 -D -U flash:w:../build_target/avr_specific_files/toggle-led-cpp-atmega32.hex:i
