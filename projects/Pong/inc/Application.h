/**
 * @file Application.h
 * @brief Defines the Application class responsible for managing the game loop.
 *
 * This header file contains the Application class that encapsulates the game loop
 * and serves as the entry point for running the application.
 *
 * @note This class structure is Emscripten-friendly. By encapsulating the game loop
 *       in a dedicated class and function, it is easier to adapt this structure for
 *       Emscripten's main loop mechanism.
 */

#pragma once

 /**
  * @brief Class to manage the game loop and application execution.
  *
  * The Application class is responsible for initializing the game,
  * running the game loop, and cleaning up when the game closes.
  *
  * @note When compiling with Emscripten, this class structure allows for easier
  *       integration with Emscripten's emscripten_set_main_loop or emscripten_set_main_loop_arg
  *       functions.
  */
class Application
{
public:

    /**
     * @brief Default constructor for the Application class.
     *
     * Initializes any required resources for running the game.
     *
     * @note Emscripten-compatible: This function can be called before setting up Emscripten's main loop.
     */
    Application();

    /**
     * @brief Destructor for the Application class.
     *
     * Frees any resources that were acquired during the application's
     * lifetime.
     *
     * @note Emscripten-compatible: This function will be called when the Emscripten runtime is exiting.
     */
    ~Application();

    /**
     * @brief Starts the application.
     *
     * Runs the game loop and manages the state of the game.
     *
     * @note Emscripten-compatible: This function could act as a bridge to Emscripten's main loop mechanism.
     */
    void Run();

    /**
     * @brief The main game loop.
     *
     * Executes the core game loop which handles updates, drawing,
     * and any required logic.
     *
     * @note Emscripten-compatible: This function can be used as the callback function for Emscripten's main loop.
     */
    void GameLoop();
};
