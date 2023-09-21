/**
 * @file AnimationHelper.h
 * @brief Defines the UpdateAnimation function for managing animation states.
 *
 * This header file contains the UpdateAnimation function, which is responsible for
 * updating the animation frames and related properties for the game entities. The function
 * works closely with the Animation and Sprite components.
 */

#pragma once

#include "Animation.h"
#include "Sprite.h"
#include "raylib.h"

 /**
  * @brief Updates the animation state for a given entity.
  *
  * UpdateAnimation takes in the Animation and Sprite components of an entity, along with
  * the maxFrames, and updates the Rectangle frameRec based on the current animation state.
  * This function is typically called every frame during the game loop to update the animation.
  *
  * @param anim    Reference to the Animation component.
  * @param sprite  Reference to the Sprite component containing the textures.
  * @param maxFrames The maximum number of frames in the current animation sequence.
  * @param frameRec Reference to the Rectangle struct defining the portion of the texture to draw.
  *
  * Example:
  * @code
  * UpdateAnimation(entityAnimation, entitySprite, MAX_IDLE_FRAMES, entityAnimation.frameRec);
  * @endcode
  */
void UpdateAnimation(Animation& anim, const Sprite& sprite, int maxFrames, Rectangle& frameRec);
