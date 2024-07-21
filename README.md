# How to set everything up for this project
## All
- install cmake
## Mac
- install make
- install clang++ compiler
- install brew
- install SDL2: brew install SDL2, brew install SDL2_image etc.
## Windows
- install vsc++ compiler
- download SDL2, SDL2_image etc. for vsc++ compiler and put in e.g. C:\Program Files\SDL2\ etc.
- add all SDL dll's to system32 dir.
- install MS build tools
- add msbuild.exe to path
- add all your SDL to path: e.g. if SDL_image is in C:\Program Files\SDL2_ttf add that to your path, so cmake can find the include and lib locations

# Build
## All
mkdir build
cd build
cmake ../
## Windows
msbuild .\main.vcxproj
## Mac
make

# Run
## Mac
cd bin
./main
## Windows
goto Explorer <project>/build/bin/Debug
open main.exe
