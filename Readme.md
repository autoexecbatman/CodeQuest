# Raylib Emscripten FAQ-Style Starter Guide

## Quick Links
- [What is This Repo?](#what-is-this-repo)
- [How to Create a New Project?](#how-to-create-a-new-project)
- [Windows Build Steps](#windows-build-steps)
- [Web Build Steps](#web-build-steps)
- [Automatic Deployment](#automatic-deployment)
- [Viewing Your Published Project](#viewing-your-published-project)
- [Further Resources](#further-resources)

---

### What is This Repo?
This repository is designed to jumpstart your Raylib projects, offering pre-configurations for Windows and Web builds. The libraries are already pre-compiled for Visual Studio 2022 and Emscripten. GitHub Actions handle web builds and deployments automatically.

---

### How to Create a New Project?
1. Copy the `HelloRaylib` folder from the `projects` directory.
2. Rename this copied folder to your project's name.
3. Modify the `CMakeLists.txt` within your newly named folder.
    ```CMake
    project("Your_Project_Name")
    ```
4. Include your project in the root `CMakeLists.txt`.
    ```CMake
    add_subdirectory("projects/Your_Project_Name")
    ```

---

### Windows Build Steps
1. Create a directory named `vs`.
    ```shell
    mkdir vs
    ```
2. Move into that directory.
    ```shell
    cd vs
    ```
3. Generate the build files.
    ```shell
    cmake .. -G "Visual Studio 17 2022"
    ```
4. When building don't forget to set the **working library** for your build.
   - Right-click on **your project** in the Solution Explorer.
   - Select `Properties`.
   - Under `Configuration Properties` > `Debugging` > `Working Directory`, set the path to the directory containing your project's executable.
   - it should be located at `bin/<project-name>/Debug` or `bin/<project-name>/Release`
5. Make sure you select a single startup project in the Solution Explorer.
   - Right-click on your solution in the Solution Explorer.
   - Select `Set Startup Projects...`.
   - Select `Single startup project` and select your project from the dropdown menu.

---

### Web Build Steps
1. Install [Docker for Windows](https://hub.docker.com/editions/community/docker-ce-desktop-windows/).
2. Run `windows_docker_build_web.bat`.
3. Locate your build in `bin/Emscripten/Your_Project_Name/`.
4. To serve the project locally, use the following commands:
   - Navigate to emscripten build location folder
     - `cd bin/Emscripten/Your_Project_Name/`
   - Invoke `emrun`  
     - `emrun Your_Project_Name.html`

---

### Automatic Deployment
Make sure to enable GitHub Pages in your repository settings to benefit from automatic deployments through GitHub Actions.

---

### Viewing Your Published Project
After enabling GitHub Pages and once the GitHub Actions build is complete, your project can be accessed at:
**`https://<github-username>.github.io/RepositoryName/Project/Project.html`**
[Example Game](https://autoexecbatman.github.io/CodeQuest/Pong/Pong.html)

---

### Further Resources
- [Originally copied from this repo](https://github.com/aaronrcox/EmscriptenHelloRaylib)
- [Raylib GitHub](https://github.com/raysan5/raylib)
- [Emscripten's site](https://emscripten.org/)
- [Visual Studio's Documentation](https://docs.microsoft.com/en-us/visualstudio/?view=vs-2022)
