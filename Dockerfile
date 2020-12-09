 # Point at any base image that you find suitable to extend.
 FROM emscripten/emsdk:latest

 RUN apt update && apt install -y ninja-build

 CMD ["/bin/sh", "/app/build_tools/emscripten_build.sh"]