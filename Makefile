.PHONY: build

BUILD_TYPE=Debug
build:
	cmake -Bbuild -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -C CMakeLists-sdl1.txt
	cmake --build build

run:
	./build/OpenMugen

clean:
	rm -rf build