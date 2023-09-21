/**
 * @file Controls.h
 * @brief Defines control utility functions.
 *
 * This header file contains functions encapsulated in the Controls namespace
 * that are designed to handle player input and control behavior.
 */

#pragma once

#include "raylib.h"

 /**
  * @namespace Controls
  * @brief Namespace encapsulating control-related functions.
  *
  * The Controls namespace provides utility functions to handle player input and update
  * player position based on that input. These functions are designed to be modular and can
  * be easily integrated into the main game loop or other game mechanisms.
  */
namespace Controls {

    /**
     * @brief Checks if the player is moving.
     *
     * This function reads the current state of the relevant control keys to determine if
     * the player character is intended to be moving.
     *
     * @return bool True if the player is moving, false otherwise.
     */
    bool IsPlayerMoving();

    /**
     * @brief Updates the position of the player.
     *
     * This function updates the player's x and y position based on the provided velocity
     * components (dx, dy). The function reads the current state of the control keys to
     * adjust the position accordingly.
     *
     * @param x Reference to the x-coordinate of the player.
     * @param y Reference to the y-coordinate of the player.
     * @param dx The velocity component in the x-direction.
     * @param dy The velocity component in the y-direction.
     */
    void UpdatePlayerPosition(int& x, int& y, int dx, int dy);
}
