FROM ubuntu
ENV DEBIAN_FRONTEND=noninteractive

COPY . /app
WORKDIR /app

RUN apt update -y && apt install -y libsdl2-dev libsdl-image1.2-dev libsdl-gfx1.2-dev libsdl1.2-compat build-essential cmake make
ARG CMAKE_BUILD_TYPE=Release
RUN cmake -Bbuild -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} && \
    cmake --build build