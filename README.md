OpenMugen
=========

Open source King of Fighters code

![openmugen](https://github.com/user-attachments/assets/5df94bec-4126-4a3e-b138-b7d426504ed8)


### Requisites
* sdl2
* sdl2-image
* sdl2-gfx

Ubuntu
```shell
sudo apt install -y libsdl2-dev libsdl-image2-dev libsdl-gfx2-dev
```
Build
```shell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```
Run
```shell
./build/OpenMugen
```
