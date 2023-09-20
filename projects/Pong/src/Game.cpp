#include "Game.h"
#include "Controls.h"
#include "StrengthAttributes.h"
#include "raylib.h"
#include "format"
#include <entt/entt.hpp>

constexpr int MAX_IDLE_FRAMES = 4;
constexpr int MAX_RUN_FRAMES = 6;

enum PlayerState
{
	IDLE,
	RUNNING
};

struct Position
{
	int x, y;
};

struct Velocity
{
	int dx, dy;
};

struct Sprite
{
	Texture2D idleTexture;
	Texture2D runningTexture;
};

struct Animation
{
	PlayerState state = IDLE;

	int currentFrame = 0;
	int framesCounter = 0;
	int framesSpeed = 8;
	Rectangle frameRec{};

	int runCurrentFrame = 0;
	int runFramesCounter = 0;
	Rectangle runFrameRec{};
};

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

Game::Game()
{
	// Initialize player entity using the member variable
	player = registry.create();
	registry.emplace<Position>(player, 190, 200);
	registry.emplace<Velocity>(player, 2, 2);

	// Initialize enemy entity using the member variable
	enemy = registry.create();
	registry.emplace<Position>(enemy, 400, 200);
	registry.emplace<Velocity>(enemy, 1, 1);
}

Game::~Game()
{

}

void Game::Load()
{
	// Load player texture
	Texture2D playerTexture = LoadTexture("../assets/sprites/Heroes/Knight/Idle/Idle-Sheet.png");
	Texture2D runningTexture = LoadTexture("../assets/sprites/Heroes/Knight/Run/Run-Sheet.png");

	// Attach Sprite and Animation components to the player
	registry.emplace<Sprite>(player, playerTexture, runningTexture);
	Animation animComp;
	animComp.frameRec = { 0.0f, 0.0f, 32, 128 / 4 };
	animComp.runFrameRec = { 0.0f, 0.0f, 64, 64 };
	registry.emplace<Animation>(player, animComp);

	// Load enemy texture
	Texture2D enemyTexture = LoadTexture("../assets/sprites/Enemy/Orc Crew/Orc/Idle/Idle-Sheet.png");
	Texture2D enemyRunningTexture = LoadTexture("../assets/sprites/Enemy/Orc Crew/Orc/Run/Run-Sheet.png");
	
	// Attach Sprite and Animation components to the enemy
	registry.emplace<Sprite>(enemy, enemyTexture, enemyRunningTexture);
	Animation enemyAnimComp;
	enemyAnimComp.frameRec = {
		0.0f, // x (starting at the first frame)
		0.0f, // y (starting at the top)
		32.0f, // width (since there are 4 frames across a 128 pixel width, each is 32 pixels wide)
		128/4 // height (since the total height is 32 pixels)
	};
	enemyAnimComp.runFrameRec = {
		0.0f,
		0.0f,
		64,
		64
	};
	registry.emplace<Animation>(enemy, enemyAnimComp);

}

void Game::UnLoad()
{
	// Iterate through each entity with a Sprite component and unload its texture
	registry.view<Sprite>().each([](auto& sprite) {
		UnloadTexture(sprite.idleTexture);
		UnloadTexture(sprite.runningTexture);
		});
}

void Game::Update()
{
	// Iterate over all entities with Position, Velocity, Animation, and Sprite components
	registry.view<Position, Velocity, Animation, Sprite>().each(
		[this](auto entity, auto& pos, auto& vel, auto& anim, const auto& sprite)
		{
			bool isMoving = false;

			// Custom behavior based on entity (player or enemy)
			if (entity == player)
			{
				// Update position based on input for player
				if (IsKeyDown(KEY_RIGHT)) { pos.x += vel.dx; isMoving = true; }
				if (IsKeyDown(KEY_LEFT)) { pos.x -= vel.dx; isMoving = true; }
				if (IsKeyDown(KEY_UP)) { pos.y -= vel.dy; isMoving = true; }
				if (IsKeyDown(KEY_DOWN)) { pos.y += vel.dy; isMoving = true; }

				// Wrap around screen
				if (pos.x > 800) { pos.x = 0; }
				if (pos.x < 0) { pos.x = 800; }
				if (pos.y > 450) { pos.y = 0; }
				if (pos.y < 0) { pos.y = 450; }
			}
			else if (entity == enemy)
			{
				// Update enemy behavior (you can fill this part)
				// For example, move the enemy slowly to the right
				pos.x += vel.dx;
				isMoving = true;
				if (pos.x > 800)
				{
					pos.x = 0;
					isMoving = false;
				}
				
			}

			// Update animation state
			if (isMoving)
			{
				anim.state = RUNNING;
			}
			else
			{
				anim.state = IDLE;
			}

			// Update animation based on state
			if (anim.state == IDLE)
			{
				UpdateAnimation(anim, sprite, MAX_IDLE_FRAMES, anim.frameRec);
			}
			else if (anim.state == RUNNING)
			{
				UpdateAnimation(anim, sprite, MAX_RUN_FRAMES, anim.runFrameRec);
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

		if (anim.state == IDLE)
		{
			DrawTextureRec(sprite.idleTexture, anim.frameRec, drawPos, WHITE);
		}
		else if (anim.state == RUNNING)
		{
			drawPos.y -= 30;  // Adjust the Y-position
			drawPos.x -= 16;  // Adjust the X-position
			DrawTextureRec(sprite.runningTexture, anim.runFrameRec, drawPos, WHITE);
		}
		});

	EndDrawing();
}
