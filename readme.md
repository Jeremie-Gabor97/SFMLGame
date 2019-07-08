#Setup
https://www.gamefromscratch.com/page/Game-From-Scratch-CPP-Edition-Part-3.aspx

1. Download SFML: https://www.sfml-dev.org/download/sfml/2.5.1/
    I downloaded "GCC 7.3.0 MinGW (DW2) - 32-bit"
2. Download corresponding MinGW: https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download
    Need to make sure that the MinGW compiler version matches exactly with what is needed for SFML library.
    The currently has the link to the corresponding library.
3. Place downloaded MinGW folder in C:\MinGW
4. Add C:\MinGW to your PATH env variable
    Can check if this was done correctly by running "g++" in cmd prompt. If command is recognized, you are good.
5. Create a folder for your project which I will now refer to as "the folder"
6. Extract the SFML library to "the folder"
7. Copy the SFML-2.4.0\include\SFML (may change depending on version) to C:\MinGW\include
8. From SFML-2.4.0\bin, copy all the dlls that you will need for your project to "the folder"

#to compile
g++ -c pang.cpp Game.cpp MainMenu.cpp SplashScreen.cpp  -Ic:\MinGW\include

#to link
g++ pang.o Game.o MainMenu.o SplashScreen.o -o sfml-app -L"C:\Users\jerem\Documents\Git_projects\Gaming\Tutorial - C++\SFML-2.4.0\lib" -lsfml-window -lsfml-system -lsfml-window -lsfml-graphics

#to run
.\sfml-app.exe

