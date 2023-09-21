/**
 * @file Game.h
 * @brief Defines the Game class responsible for game state management.
 *
 * This header file contains the Game class that is central to the game's execution,
 * encapsulating the game loop components like loading, updating, and drawing of elements.
 *
 * @note This class makes extensive use of the EnTT library to manage game entities, components,
 *       and systems, making it easier to extend and maintain the game.
 */

#pragma once

#include <iostream>
#include <string>
#include <entt/entt.hpp> // Include EnTT for entity-component-system functionality
#include "Position.h"
#include "Velocity.h"
#include "Sprite.h"
#include "Animation.h"
#include "HelperFunctions.h"
#include "Controls.h"

 /**
  * @brief Class to manage the core game state and game loop.
  *
  * The Game class serves as the main hub for managing the game state, loading and unloading resources,
  * updating the game logic, and rendering to the screen.
  *
  * @note The Game class is built around the EnTT entity-component-system framework to organize the game's
  *       internal state, making it easier to add new features or refactor existing ones.
  */
class Game
{
public:
	// Constants for the game window properties
	const int windowWidth = 800;
	const int windowHeight = 450;
	const char* windowTitle = "CppRL";

	// Flag to indicate if the game should quit
	bool shouldQuit = false;

public:
	/**
	 * @brief Default constructor for the Game class.
	 *
	 * Initializes the game state and resources, including setting up EnTT registry
	 * and creating initial game entities like player and enemy.
	 */
	Game();

	/**
	 * @brief Destructor for the Game class.
	 *
	 * Cleans up resources and deallocates memory.
	 */
	~Game();

	/**
	 * @brief Load game resources.
	 *
	 * Loads textures, sounds, and other game resources into memory.
	 */
	void Load();

	/**
	 * @brief Unload game resources.
	 *
	 * Unloads and deallocates any resources loaded into memory.
	 */
	void UnLoad();

	/**
	 * @brief Update game logic.
	 *
	 * Responsible for updating game entities, checking for collisions, and other
	 * gameplay logic.
	 */
	void Update();

	/**
	 * @brief Draw elements to the screen.
	 *
	 * Draws all game elements including entities and UI to the screen.
	 */
	void Draw();

	/**
	 * @brief Logs a message to the console.
	 *
	 * Utility function to print debug or informational messages.
	 *
	 * @param message The string message to be logged.
	 */
	void log(const std::string& message) {
		std::cout << message << std::endl;
	}

private:
	// EnTT registry for managing entities and components
	entt::registry registry;

	// Entities representing the player and enemy
	entt::entity player;
	entt::entity enemy;
};

// Extern declaration to allow other modules to access the Game instance
extern Game game;
