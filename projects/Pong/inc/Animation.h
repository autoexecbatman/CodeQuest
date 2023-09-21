/**
 * @file Animation.h
 * @brief Defines the Animation component and PlayerState enumeration.
 *
 * This header file contains the Animation struct used for controlling
 * sprite animations and the PlayerState enumeration to define possible
 * states a player can be in.
 */

#pragma once
#include "raylib.h"

 /**
  * @brief Enum defining possible player states.
  *
  * PlayerState is an enumeration that lists the various states a player
  * can be in. Currently, this includes IDLE and RUNNING.
  */
enum PlayerState {
    IDLE,    ///< The player is idle (not moving).
    RUNNING  ///< The player is running (moving).
};

/**
 * @brief Structure to hold animation details for sprites.
 *
 * The Animation struct is used for controlling sprite animations. It contains
 * various properties to track the animation's current frame, speed, and state.
 */
struct Animation {
    PlayerState state = IDLE; ///< The current state of the animation. Default is IDLE.

    int currentFrame = 0;     ///< The current frame of the animation.
    int framesCounter = 0;    ///< Counter to track frame changes.
    int framesSpeed = 8;      ///< Speed of the animation frames.
    Rectangle frameRec{};     ///< Rectangle struct to specify which part of the sprite sheet to draw.

    int runCurrentFrame = 0;  ///< The current frame of the running animation.
    int runFramesCounter = 0; ///< Counter to track running frame changes.
    Rectangle runFrameRec{};  ///< Rectangle struct for running frames.
};
