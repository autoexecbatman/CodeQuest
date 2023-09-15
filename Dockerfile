FROM emscripten/emsdk:latest

RUN apt update && apt install -y ninja-build

CMD ["/bin/sh", "./emscripten_build.sh"]
