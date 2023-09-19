# Emscripten Raylib Projects: A Yodamancer's Guide

## The Force Behind The Code

A repository this is, not just for storing code, but for embarking on a quest of mastering Raylib projects. Automatically, GitHub Actions will construct your web builds and place them upon the land of GitHub Pages they shall be.

Prepared the libraries are for:
- The Temple of Visual Studio 2022
- The Emscripten Mysteries

## The Beginning of Your Quest

1. A twin to the `HelloRaylib` chamber in the `projects` realm, you must create.
2. A new identity for this chamber, bestow.
3. The sacred scroll `CMakeLists.txt` within your newfound domain, consult and chant:
    ```CMake
    project("<name_of_your_quest>")
    ```
4. A broader scroll, `CMakeLists.txt`, found at the root of all realms, must also hear your voice:
    ```CMake
    # The Council of Projects
    # ====================
    add_subdirectory("projects/HelloRaylib")
    add_subdirectory("projects/<name_of_your_quest>")
    # ====================
    ```

## Conjure the Windows Spirit

1. A sanctuary named `vs` for Visual Studio scrolls, craft.
2. Into this sanctuary, step:
    - `cd vs`
3. Powershell, the trusted oracle, summon (or perhaps another shell you prefer).
4. The incantation to conjure the Visual Studio solution, utter:
    - `cmake .. -G "Visual Studio 17 2022"`

## The Web: A Far Away Galaxy

**NOTE: Optional, this path is, yet rewarding.**

To travel to this galaxy, [Docker for Windows](https://hub.docker.com/editions/community/docker-ce-desktop-windows/), the space vessel, must you have.

1. Ascertain the vessel is awakened.
2. The `windows_docker_build_web.bat` talisman, invoke.
3. Successful you are, locate your game in the `bin/Emscripten/<name_of_your_quest>/` sanctuary.
4. A local web server, summon:
    - `cd bin/Emscripten/<name_of_your_quest>/`
    - `emrun <name_of_your_quest>.html`

## The Scroll of Automation

Automated it is, by the GitHub Action, to publish your quests to the `gh-pages` realm.

To gaze upon your published quests, GitHub Pages, activate in your repository.

**Witness a Sample Quest:**  
[Behold the Sample](https://autoexecbatman.github.io/EmscriptenHelloRaylib---Copy-2-/Pong/Pong.html)  
**The Map to your Quests:**  
`https://<your_github_name>.github.io/RepositoryName/Quest/Quest.html`

---

## A Yodamancer's Wisdom: How To Be One With The Code

1. **Practice, You Must:** A master does not in a day, become. Multiple quests, you must undertake.
2. **Read The Scrolls:** Documentation and source code, ignore you should not. Wisdom, they contain.
3. **Seek The Elders:** Online communities and forums, treasures they are. Wisdom from others, one can glean.
4. **Code Reviews, Undergo:** Proud you may be, of your code. Yet flaws, even Yodamancers have. Humble yourself, seek feedback.
5. **Time Away, Take:** Obsessed with coding, you must not become. Life's other quests, too, need you.
