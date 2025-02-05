BUILD_TYPE=Debug
build:
	cmake -Bbuild -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
	cmake --build build

run:
	./build/OpenMugen