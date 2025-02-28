OpenMugen
=========

Open source King of Fighters code

![openmugen](https://github.com/user-attachments/assets/5df94bec-4126-4a3e-b138-b7d426504ed8)


### Requisites
* sdl2
* sdl-1.2-compat
* sdl-image
* sdl-gfx

Ubuntu
```shell
sudo apt install libsdl2-dev libsdl-image1.2-dev libsdl-gfx1.2-dev libsdl1.2-compat
```
Build
```shell
cmake -Bbuild -DCMAKE_BUILD_TYPE=Release
cmake --build build
```
Run
```shell
./build/OpenMugen
```
