@echo off
docker build . -t build_emscripten
docker run -v "%cd%:/src" -it build_emscripten
pause