#include "Game.h"
#include "Controls.h"
#include "StrengthAttributes.h"
#include "raylib.h"
#include "format"
#include <entt/entt.hpp>

enum PlayerState {
	IDLE,
	RUNNING
};


struct Position {
	int x, y;
};

struct Velocity {
	int dx, dy;
};

struct Sprite {
	Texture2D idleTexture;
	Texture2D runningTexture;
};

struct Animation {
	int currentFrame = 0;
	int framesCounter = 0;
	int framesSpeed = 8;
	Rectangle frameRec;
	PlayerState state = IDLE;
	int runCurrentFrame = 0;
	int runFramesCounter = 0;
	Rectangle runFrameRec;
};

Game::Game() {
	// Create player entity
	auto player = registry.create();
	registry.emplace<Position>(player, 190, 200);
	registry.emplace<Velocity>(player, 2, 2);
}

Game::~Game()
{

}

void Game::Load() {
	// Load player texture
	Texture2D playerTexture = LoadTexture("../assets/sprites/Heroes/Knight/Idle/Idle-Sheet.png");
	Texture2D runningTexture = LoadTexture("../assets/sprites/Heroes/Knight/Run/Run-Sheet.png");


	// Attach Sprite and Animation components to the player
	registry.emplace<Sprite>(player, playerTexture, runningTexture);
	Animation animComp;
	animComp.frameRec = { 0.0f, 0.0f, 32, 128 / 4 };
	animComp.runFrameRec = { 0.0f, 0.0f, 64, 64 };
	registry.emplace<Animation>(player, animComp);
}

void Game::UnLoad()
{
	// Iterate through each entity with a Sprite component and unload its texture
	registry.view<Sprite>().each([](auto& sprite) {
		UnloadTexture(sprite.idleTexture);
		UnloadTexture(sprite.runningTexture);
		});
}

void Game::Update() {

	auto& pos = registry.get<Position>(player);
	auto& vel = registry.get<Velocity>(player);
	auto& anim = registry.get<Animation>(player);
	
	// Update player position based on input
	bool isMoving = false;
	if (IsKeyDown(KEY_RIGHT)) { pos.x += vel.dx; isMoving = true; }
	if (IsKeyDown(KEY_LEFT)) { pos.x -= vel.dx; isMoving = true; }
	if (IsKeyDown(KEY_UP)) { pos.y -= vel.dy; isMoving = true; }
	if (IsKeyDown(KEY_DOWN)) { pos.y += vel.dy; isMoving = true; }

	// Update player state
	if (isMoving) {
		anim.state = RUNNING;
	}
	else {
		anim.state = IDLE;
	}

	registry.view<Animation, Sprite>().each([](Animation& anim, const Sprite& sprite)
		{
			if (anim.state == IDLE)
			{
				anim.framesCounter++;

				if (anim.framesCounter >= (60 / anim.framesSpeed))
				{
					anim.framesCounter = 0;
					anim.currentFrame++;
					int maxFrames = 4;  // The number of frames in your sprite sheet.

					if (anim.currentFrame >= maxFrames)
					{
						anim.currentFrame = 0;
					}

					anim.frameRec.x = (float)anim.currentFrame * 32.0f;
				}

			}
			else if (anim.state == RUNNING)
			{
				// Animation logic for running
				anim.runFramesCounter++;
				if (anim.runFramesCounter >= (60 / anim.framesSpeed))
				{
					anim.runFramesCounter = 0;
					anim.runCurrentFrame++;
					int maxRunFrames = 6;  // The number of frames in your sprite sheet.
					// reset to the first frame if we've gone past the last
					if (anim.runCurrentFrame >= maxRunFrames)
					{
						anim.runCurrentFrame = 0;
					}

					anim.runFrameRec.x = (float)anim.runCurrentFrame * 64.0f;
				}
			}
		}
	);
		
}

void Game::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	registry.view<Position, Sprite, Animation>().each([](const Position& pos, const Sprite& sprite, const Animation& anim) {
		Vector2 drawPos = { (float)pos.x, (float)pos.y };

		if (anim.state == IDLE) {
			DrawTextureRec(sprite.idleTexture, anim.frameRec, drawPos, WHITE);
		}
		else if (anim.state == RUNNING) {
			drawPos.y -= 30;  // Adjust the Y-position. You may have to tune this value.
			drawPos.x -= 16;  // Adjust the X-position. You may have to tune this value.
			DrawTextureRec(sprite.runningTexture, anim.runFrameRec, drawPos, WHITE);
		}
		});

	EndDrawing();
}
