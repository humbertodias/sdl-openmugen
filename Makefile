OS   := $(shell uname -s)
ARCH := $(shell uname -m)

.PHONY: build

BUILD_TYPE=Debug
BUILD_TYPE=Release
build:
	cmake -Bbuild -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
	cmake --build build -v

run:
	./build/OpenMugen

clean:
	rm -rf build *.tar.gz

targz/openmugen:
	tar -czvf OpenMugen-${OS}-${ARCH}.tar.gz -C build OpenMugen

targz/data:
	tar -czvf data.tar.gz data