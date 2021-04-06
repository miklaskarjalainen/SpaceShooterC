
#  <p align=center> Space Shooter

This is a simple game made in approximetly in 2 hours in plain' C, with [SDL2](https://www.libsdl.org/).
This was my first try making anything "big" in C without classes or std libraries, and i think it shows.

![picture](screenshot.png "")

# Compiling
## Window:
Make sure you have c/c++ development tools installed for Visual Studio 2019  
Open game.sln with Visual Studio 2019 and compile.

## Linux:
With linux you have to install all dependencies with  
**Debian/Ubuntu**: "sudo apt update && sudo apt install gcc libsdl2-dev libsdl2-image-dev make"   
**Manjaro**: "sudo pamac update && sudo pamac install gcc lib32-sdl2 lib32-sdl2_image make"  

Compile by typing "make" in the projects root directory, and the compiled game will be in "/bin/Release/space_shooter"

# Design
The "engine" is SDL2 wrapper located in game/engine, the wrapper is desgined to be similar in style to [Raylib](https://www.raylib.com/).
