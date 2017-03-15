# Linux dependencies

You will need the following dependencies (Ubuntu, Debian):

    sudo apt-get update -qq
    sudo apt-get install -y build-essential g++ qt5-default qt5-qmake qtmultimedia5-dev libqt5xmlpatterns5-dev libqt5svg5-dev qttools5-dev-tools

# Compiling on Linux

1. Change into the out-of-tree build subdirectory of the source tree:

        mkdir IMP/build; cd IMP/build

2. Create the makefile via qmake:

        qmake ../src/imp.pro

3. Build the binary:

        make

4. For the easiest install, just run make install to automatically set up the shared data and desktop launcher.

        sudo make install

   If you prefer to run from a user directory, you can copy the imp binary from the build directory, as well as the audio, themes, and dictionaries folders from the data directory to your preferred location.

