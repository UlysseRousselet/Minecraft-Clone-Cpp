# Minecraft-Clone-Cpp
Minecraft clone in 3D created with opengl in c++

You can move around the world, placing and removing blocks.
The world is infinite and is generated with the perlin noise technique.
Chunks are 10 blocks long, 10 blocks wide, and 20 blocks high.
I would like to implement a seed system and online multiplayer later.

Linux prerequisites: install a C/C++ toolchain and OpenGL dependencies.

On Debian/Ubuntu:

sudo apt update && sudo apt install -y build-essential libglfw3-dev libgl1-mesa-dev

Then build and run with:

make && make run

![Capture d’écran (13)](https://github.com/UlysseRousselet/Minecraft-Clone-Cpp/assets/114906835/87e87a03-45a9-4e10-ae94-0303c5a6a19e)
