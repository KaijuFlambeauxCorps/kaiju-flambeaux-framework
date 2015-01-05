KFC 2014
========

Initial setup
-------------

### Prerequisite software

To work collaboratively on this project, you will need the [Git source control software][5] installed. On Windows, you can also use the graphical tool [Git Extensions][4] to simplify working with Git.

At the very least you will need the [Arduino Software][3] installed. I recommend using [Eclipse][1] (the C++ variant), and the [Arduino Eclipse plugin][2] (which requires the Arduino Software as well) to avoid going insane while writing code, because IDEs are important tools, and the Arduino Software on its own is a terrible IDE.

### Setting up the Arduino Eclipse Plugin

1. Follow the instructions on the [Arduino Eclipse "how-to" page][6]: particularly the sections **Install V2 plugin** and **Configure**

### Importing FastLED

1. Download [FastLED 3.0.3][https://github.com/FastLED/FastLED/archive/3.0.3.zip].
2. Rename the downloaded .zip file to "FastLED.zip" (the Arduino software will hiccup otherwise)
3. Start the Arduino Software
4. From the menu bar, choose *Sketch > Import Library > Add Library...*
5. Locate the .zip file you downloaded
6. Verify that FastLED was imported by choosing *Sketch > Import Library* and inspecting the bottom of the menu (there should be a `FastLED` entry)

### Opening the sketch (if using the Arduino Software)

1. Clone the git repository into a directory. This can be done via the command line by typing `git clone https://github.com/tullo-x86/kaiju2014.git kfc2014` (This will create a folder called `kfc2014` in your working directory)
2. Open the `kaiju_2014.ino` file inside the `kfc2014/kaiju_2014` directory.
3. Try not to let editing code inside a pure text editor kill your paassion for coding.

### Importing the projects (if using the Eclipse plugin)

1. Clone the git repository into a directory. This can be done via the command line by typing `git clone https://github.com/tullo-x86/kaiju2014.git kfc2014` (This will create a folder called `kfc2014` in your working directory)
2. In Eclipse, choose *File > Import* from the menu bar
3. Choose *Existing projects into Workspace* and click Next
4. Make sure *Select root directory* is selected, click *Browse...*, and navigate to the kfc2014 directory that git created for you
5. Verify that the project is listed and checked (you should see `kaiju-2014`), and click *Finish*
6. Once that closes, verify that it builds by selecting *Project > Build All* from the menu bar
7. Use the Arduino-like buttons in the toolbar to upload the program to your board.

[1]: http://eclipse.org/downloads/packages/eclipse-ide-cc-developers/lunasr1
[2]: http://eclipse.baeyens.it/rlogiacco/index.html
[3]: http://arduino.cc/en/Main/Software
[4]: https://code.google.com/p/gitextensions/
[5]: http://git-scm.com/downloads
[6]: http://eclipse.baeyens.it/rlogiacco/how_to.shtml