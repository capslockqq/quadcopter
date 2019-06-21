[![Build Status](http://quadcopter-build-server.duckdns.org:8080/job/Quadcopter-pipeline/badge/icon)](http://quadcopter-build-server.duckdns.org:8080/job/Quadcopter-pipeline/)
# Quadcopter
Quadcopter controller code for both hardware and application layer. The MCU used for this particular project is an arduino uno (atmega328p). The project is primarily written in C++.

## How to setup the project:
### Prerequisites
* Install WSL(https://docs.microsoft.com/en-us/windows/wsl/install-win10)
* Install latest version of CMake.
* Install GCC, G++, AVR-GCC, LIBC

### Setup
* Clone the project
* ``` cd quadcopter ```
* ```sudo chmod +x setup.sh```
* ```./setup.sh``` This will create build folders, and build the project (pc code, unittests and target code)

### Flashing the arduino uno
There has been created a flashing script which will program your arduino with the C++ code. The code that will be flashed is the code found in the folder ```avr_code```. To flash the code you should do the following:
* ```cd flash```
* ```./output_script.sh``` (You might need to change your USB device being used. This can be done by seeing which USB port your arduino is connected to, and replace ```/dev/ttyACM0``` with that. Your arduino should now be programmed

### Continue developing
If you want to compile and run the application code on your computer you should do the following:
*  ```cd build_pc ```
*  ```cmake -DBUILD_TYPE=PC```
*  ```make ```
*  ```cd pc ```
*  ```./pc_program ```

