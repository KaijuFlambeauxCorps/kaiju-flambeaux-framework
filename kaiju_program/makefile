### PROJECT_DIR
### This is the root of the kaiju_program directory. It must be a fully-qualified path, not a relative directory.
PROJECT_DIR       = /home/tully/projects/kaiju-flambeaux-corps/kaiju_program

### ARDMK_DIR
### Path to the Arduino-Makefile directory. Leave this alone unless you're hacking with the build process.
ARDMK_DIR         = $(PROJECT_DIR)/../arduino-makefile

### ARDUINO_DIR
### Path to the Arduino application and resources directory. It should point to the extracted contents of the Arduino Software download.
### On Windows, this would be something like `C:\Arduino`. 
ARDUINO_DIR       = /home/tully/ArduinoSDK/1.6.5

### USER_LIB_PATH
### Path to where the project's libraries are stored. I've opted to place this directory beside, not inside, the src/ directory. Libraries included with the Arduino Software don't need to be included here.
USER_LIB_PATH    :=  $(PROJECT_DIR)/lib

### ARDUINO_LIBS
### If you are using an extra library, be sure to name it here. This includes libraries included with the Arduino Software like `SPI` and `Wire`.
ARDUINO_LIBS      = SPI FastLED RadioHead

### BOARD_TAG
### It must be set to the board you are currently using. (i.e uno, mega2560, etc.)
### The Kaiju Flambeaux Corps recommended hardware is the Anarduino MiniWireless which uses the following:
#ARCHITECTURE  = avr
#BOARD_TAG     = diecimila
#BOARD_SUB     = atmega328
ARCHITECTURE  = avr
BOARD_TAG     = diecimila
BOARD_SUB     = atmega328

### MONITOR_BAUDRATE
### It must be set to Serial baudrate value you are using.
MONITOR_BAUDRATE  = 57600

### AVR_TOOLS_DIR
### Path to the AVR tools directory such as avr-gcc, avr-g++, etc.
### By default, this automatically resolves using ARDMK_DIR, so you shouldn't have to set this unless you're hacking on the build process
#AVR_TOOLS_DIR     = /home/tully/ArduinoSDK/1.6.4/hardware/tools/avr

### AVRDUDE
### Path to avrdude directory.
### This also automatically resolves using ARDMK_DIR.
#AVRDUDE          = /home/tully/ArduinoSDK/1.6.4/hardware/tools/avr/bin/avrdude

### CFLAGS_STD
### Set the C standard to be used during compilation. Documentation (https://github.com/WeAreLeka/Arduino-Makefile/blob/std-flags/arduino-mk-vars.md#cflags_std)
CFLAGS_STD        = -std=gnu99

### CXXFLAGS_STD
### Set the C++ standard to be used during compilation. Documentation (https://github.com/WeAreLeka/Arduino-Makefile/blob/std-flags/arduino-mk-vars.md#cxxflags_std)
CXXFLAGS_STD      = -std=gnu++11

### CXXFLAGS
### Flags you might want to set for debugging purpose. Uncomment if you like lots of compiler warnings.
#CXXFLAGS         += -pedantic -Wall -Wextra

### MONITOR_PORT
### The port your board is connected to. Using an '*' tries all the ports and finds the right one.
### On Windows, this would be (for example) COM4.
### On MacOS, this would be /dev/tty.usbmodem*
MONITOR_PORT      = /dev/ttyUSB*

### CURRENT_DIR
### Do not touch - used for binaries path
CURRENT_DIR       = $(shell basename $(CURDIR))

### OBJDIR
### This is where to put the binaries you just compile using 'make'. You probably don't need to touch this.
OBJDIR            = $(PROJECT_DIR)/bin/$(BOARD_TAG)

### Do not touch - the path to Arduino.mk, inside the ARDMK_DIR
include $(ARDMK_DIR)/Arduino.mk

