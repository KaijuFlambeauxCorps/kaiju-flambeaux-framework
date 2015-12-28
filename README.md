# Kaiju Flambeaux Corps lightsuits

GPLv2-licenced goodness for bootstrapping your radio-synchronised LED project. Includes the patterns displayed in the [2015 Chewbacchus parade][1].

**Note for parade krewe members**: This is *not* the program we will be running in Chewbacchus 2016! This is the open-source framework for LED control which that project uses, and contains the 2015 patterns as an example of implementation.

## Getting started

### Prerequisite software

#### All platforms

- [Arduino Software][2] (1.6.4 or later)
- Your preferred IDE or text editor (makefile support encouraged)

#### Windows

I've had a lot of trouble getting GNU Make to work on Windows -- it often complains about missing files when the file exists. If you get this project to build using Arduino-Makefile as it is designed, please document your process, and submit any necessary changes to the source in a pull request.

### Initial setup

You'll need to configure a handful of options in the makefile before the project will build and upload. Open `kaiju_program/makefile` and make these changes:

- Set `PROJECT_DIR` to an absolute path to your `kaiju_program` directory
- Set `ARDUINO_DIR` to an absolute path to your Arduino Software installation (for example, `C:\Arduino`)
- Set `MONITOR_PORT` to the port you use to communicate with your programmer.
  - On Windows, this will be a COM port.
  - On Linux, this will be `/dev/ttyUSB*` or `/dev/ttyACM*` depending on the type of programmer you have.
  - I don't have a Mac handy, but I think it shows up as `/dev/tty.usbmodem*`.
- **If you are using different hardware than the [Anarduino MiniWireless][3]**, you may need to update `BOARD_TAG` and `BOARD_SUB`. These correspond to the *Board* and *Processor* settings in the Arduino Software's *Tools* menu, but are not the same as the displayed text in that menu. The correct values can be found in the `boards.txt` file in your Arduino Software installation.

### Building the project

From a console, enter the `kaiju_program` directory and execute `make all`. If the build succeeds, the static memory usage of the program will be displayed.

### Uploading the program

From a console, enter the `kaiju_program` directory and execute `make upload`. If your build succeeds, `avrdude done.  Thank you.` will be displayed.

[1]: https://www.youtube.com/watch?v=r27eCkilbfY
[2]: https://arduino.cc/en/Main/Software
[3]: http://www.anarduino.com/miniwireless/
