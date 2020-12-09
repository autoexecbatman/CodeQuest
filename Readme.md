# Emscripten Raylib Projects

## About

This is a "Starter" repo for Raylib projects build with CMake for Windows and Web. 
Raylib libraries are Pre-Compiled:

 - Visual Studio 2019
 - Emscripten

## Creating a new Project
1. Duplicate the `HelloRaylib` from the `projects` folder
2. Rename the folder to match your project name
3. Edit the `CMakeLists.txt` file in your new project folder
    ```CMake
    project("<your_project_name>")
    ```
4. Edit CMakeLists.txt in the root director to include the new project
    ```CMake
    # Include sub-projects
    # ====================
    add_subdirectory ("projects/HelloRaylib")
    add_subdirectory ("projects/<your_project_name>")
    # ====================
    ```

## Building on windows
Open the solution directory in visual studio.
Right click in windows explorer `Open in Visual Studio`
After visual studio has opened, select the project to run from the `play` dropdowm menu in the toolbar.

## Building for web (locially) 
**this step is optional**

To build the project locially you will need to install `docker for windows` https://hub.docker.com/editions/community/docker-ce-desktop-windows/

1. make sure `docker desktop` is running.
2. double click on `build_tools/windows_docker_build_web.bat` <br/>
this will compile your project with the emscripten toolchain.
3. If no errors have occured - Your game will be available in the `bin/Emscripten/<your_project_name>/` folder.
4. You will need to serve the generated files via a local webserver
I recomend using visual studio code's `live server` extension.

# Automated Build and Deploy to GHPages
This repo contains a github action that will automaticly build and publish your projects to the gh-pages branch.

To view your published projects, Github Pages will need to be enabled via your repository settings.