#include "Game.h"
#include "raylib.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Load()
{

}

void Game::UnLoad()
{

}

void Game::Update()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
}

void Game::Draw()
{

}

