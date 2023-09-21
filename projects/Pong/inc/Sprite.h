/**
 * @file Sprite.h
 * @brief Defines the Sprite structure for managing textures.
 *
 * This header file contains the Sprite struct, which serves as a container for the textures
 * related to different states of an entity. It holds the Texture2D variables for both idle
 * and running states, which are drawn depending on the entity's current state.
 */

#pragma once

#include "raylib.h"

 /**
  * @brief Struct to hold the textures for different entity states.
  *
  * The Sprite struct holds the Texture2D objects for an entity's idle and running states.
  * This allows for easy switching between textures depending on the current state of the entity.
  * It is essential for managing the graphical representations of entities in the game.
  *
  * @param idleTexture  The texture used when the entity is in an idle state.
  * @param runningTexture The texture used when the entity is in a running/moving state.
  *
  * Example:
  * @code
  * Sprite playerSprite;
  * playerSprite.idleTexture = LoadTexture("path/to/idle_texture.png");
  * playerSprite.runningTexture = LoadTexture("path/to/running_texture.png");
  * @endcode
  */
struct Sprite {
    Texture2D idleTexture;      ///< The texture for the idle state.
    Texture2D runningTexture;   ///< The texture for the running state.
};
