KFC 2014
========

Initial setup
-------------

### Prerequisite software

To work collaboratively on this project, you will need the [Git source control software][5] installed. On Windows, you can also use the graphical tool [Git Extensions][4] to simplify working with Git.

You will need [Eclipse][1], the [Eclipse AVR plugin][2], and the [AVR GCC toolchain][3] installed to build this project. 

- If you're on Windows, avr-gcc is available as [WinAVR](http://sourceforge.net/projects/winavr/files/)
- If you run Linux, gcc variants are available via your package manager, e.g. on Ubuntu/Debian use `sudo apt-get install gcc-avr binutils-avr gdb-avr avr-libc avrdude`.
- I've never done it on MacOS, so if you're using a Mac, read the instructions and good luck :)

### Importing the projects

1. Clone the git repository into a directory. This can be done via the command line by typing `git clone https://github.com/tullo-x86/kaiju2014.git kfc2014` (This will create a folder called `kfc2014` in your working directory)
2. In Eclipse, choose *File > Import* from the menu bar
3. Choose *Existing projects into Workspace* and click Next
4. Make sure *Select root directory* is selected, click *Browse...*, and navigate to the kfc2014 directory that git created for you
5. Verify that two projects are listed and both are checked (you should see `arduino_core` and `kaiju2014`), and click *Finish*
6. Once that closes, verify that it builds by selecting *Project > Build All* from the menu bar

### Setting up AVRDude for uploading

TODO: Write this section once a chip is available and I've uploaded a program

[1]: http://eclipse.org/downloads/packages/eclipse-ide-cc-developers/lunasr1
[2]: http://avr-eclipse.sourceforge.net/wiki/index.php/Plugin_Download
[3]: http://avr-eclipse.sourceforge.net/wiki/index.php/The_AVR_GCC_Toolchain
[4]: https://code.google.com/p/gitextensions/
[5]: http://git-scm.com/downloads