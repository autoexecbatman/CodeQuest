#include "HelperFunctions.h"

// Helper function for updating animations
void UpdateAnimation(Animation& anim, const Sprite& sprite, int maxFrames, Rectangle& frameRec)
{
	anim.framesCounter++;
	if (anim.framesCounter >= (60 / anim.framesSpeed))
	{
		anim.framesCounter = 0;
		anim.currentFrame++;
		if (anim.currentFrame >= maxFrames)
		{
			anim.currentFrame = 0;
		}
		frameRec.x = (float)anim.currentFrame * frameRec.width;
	}
}