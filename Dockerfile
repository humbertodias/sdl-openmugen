FROM ubuntu
ENV DEBIAN_FRONTEND=noninteractive

RUN apt update -y && apt install -y libsdl2-dev libsdl2-image-dev libsdl-gfx1.2-dev libsdl1.2-compat build-essential cmake make