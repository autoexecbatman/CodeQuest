/**
 * @file Velocity.h
 * @brief Defines the Velocity structure for controlling entity movement.
 *
 * This header file contains the Velocity struct, which serves as a container for the rate
 * of change in spatial attributes for game entities. It holds two integer variables, dx and dy,
 * representing the change in x and y coordinates over time. The struct is crucial for updating
 * entities' positions during the game loop.
 */

#pragma once

 /**
  * @brief Struct to hold the rate of change in x and y coordinates for an entity.
  *
  * The Velocity struct is a straightforward data structure that contains two integer variables,
  * dx and dy, which store the rate of change for an entity's x and y coordinates. These variables
  * are used for updating the entity's position during each iteration of the game loop.
  *
  * @param dx  The rate of change along the x-axis.
  * @param dy  The rate of change along the y-axis.
  *
  * Example:
  * @code
  * Velocity playerVelocity;
  * playerVelocity.dx = 5;
  * playerVelocity.dy = 3;
  * @endcode
  */
struct Velocity
{
	int dx; ///< The rate of change along the x-axis.
	int dy; ///< The rate of change along the y-axis.
};
