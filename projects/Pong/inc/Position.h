/**
 * @file Position.h
 * @brief Defines the Position structure for spatial attributes.
 *
 * This header file contains the Position struct, which serves as a container for the spatial
 * attributes of game entities. It holds two integer variables, x and y, representing the
 * Cartesian coordinates of an entity in the game world. The struct is pivotal for rendering
 * and updating entities based on their location.
 */

#pragma once

 /**
  * @brief Struct to hold the x and y coordinates for an entity.
  *
  * The Position struct is a simple data structure that contains two integer variables, x and y,
  * for storing the Cartesian coordinates of a game entity. These coordinates are used in rendering
  * the entity on the screen and also for other spatial calculations.
  *
  * @param x  The x-coordinate of the entity.
  * @param y  The y-coordinate of the entity.
  *
  * Example:
  * @code
  * Position playerPosition;
  * playerPosition.x = 100;
  * playerPosition.y = 200;
  * @endcode
  */
struct Position
{
	int x; ///< The x-coordinate of the entity.
	int y; ///< The y-coordinate of the entity.
};
