cd Release
make all
avrdude -c arduino -p m328p -P /dev/ttyUSB0 -b 57600 -U flash:w:kaiju_program.hex:i
