# Emscripten Raylib Projects

## About

This repository serves as a "starter kit" for Raylib projects. Web builds are automatically triggered through GitHub Actions and deployed to GitHub Pages.

The libraries come pre-compiled for:
- Visual Studio 2022
- Emscripten

## Creating a New Project

1. Duplicate the `HelloRaylib` folder within the `projects` directory.
2. Rename this folder to match the name of your new project.
3. Open the `CMakeLists.txt` file in your new project folder and edit it as follows:
    ```CMake
    project("<your_project_name>")
    ```
4. Open the `CMakeLists.txt` file in the **root directory** and add your new project there:
    ```CMake
    # Include sub-projects
    # ====================
    add_subdirectory("projects/HelloRaylib")
    add_subdirectory("projects/<your_project_name>")
    # ====================
    ```

## Building on Windows

1. Create a folder for the Visual Studio files:
    - `mkdir vs`
2. Navigate to that folder:
    - `cd vs`
3. Open a PowerShell window in this folder (or use another shell).
4. Run the following command to build the solution with CMake:
    - `cmake .. -G "Visual Studio 17 2022"`

## Building for Web (Locally)
**NOTE: This step is optional.**

To build the project locally, you'll need to install [Docker for Windows](https://hub.docker.com/editions/community/docker-ce-desktop-windows/).

1. Ensure `Docker Desktop` is running.
2. Double-click on `windows_docker_build_web.bat`. This will compile your project using the Emscripten toolchain.
3. If the build is successful, your game will be located in the `bin/Emscripten/<your_project_name>/` folder.
4. Serve the generated files via a local web server:
    - Navigate to the Emscripten build folder:
        - `cd bin/Emscripten/<your_project_name>/`
    - Open PowerShell (make sure Emscripten is set up):
        - `emrun <your_project_name>.html`

## Automated Build and Deploy to GitHub Pages

This repository includes a GitHub Action that will automatically build and publish your projects to the `gh-pages` branch. 

To view your published projects, enable GitHub Pages in your repository settings.

**Sample Project on GitHub Pages:**  
[Link to a Sample Project](https://autoexecbatman.github.io/EmscriptenHelloRaylib---Copy-2-/Pong/Pong.html)  
**URL Format:**  
`https://<github-username>.github.io/RepositoryName/Project/Project.html`
