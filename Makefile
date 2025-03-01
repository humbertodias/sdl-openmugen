OS   := $(shell uname -s)
ARCH := $(shell uname -m)
# if there is no current tag use the git commit hash
TAG_NAME := $(shell git describe --tags --exact-match 2>/dev/null || git rev-parse --short HEAD)


.PHONY: build
BUILD_TYPE=Debug
BUILD_TYPE=Release
build:
	cmake -Bbuild -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
	cmake --build build -v

run:
	./build/OpenMugen

clean:
	rm -rf build *.tar.gz data.zip

copy-release-files:
	echo "OS: ${OS}"
ifeq ($(OS),Linux)
	cp release/lin/* build/
else ifeq ($(OS),Darwin)
	cp release/mac/* build/
else
	echo "unknown"
endif

targz/openmugen:	copy-release-files
	cd build && \
	tar -czvf "../OpenMugen-${TAG_NAME}-${OS}-${ARCH}.tar.gz" OpenMugen launcher.*

targz/data:
	zip -9 -r data.zip data

ci:
	docker build -t openmugen .
	docker run -v ${PWD}:/app -w /app openmugen sh -c "make clean build"