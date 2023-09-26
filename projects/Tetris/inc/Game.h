#pragma once
#include "raylib.h"
#include "Grid.h"
#include "Blocks.cpp"
#include <string>
#include <vector>

class Game
{
public:
	const int windowWidth{ 500 }, windowHeight{ 620 };
	std::string windowTitle{ "Tetris" };
	bool shouldQuit{ false };
	Color darkBlue{ 0, 121, 241, 255 };
	Font font{}; // TODO : check if the font is loading correctly
	Music music{};
	int score{ 0 };
	bool gameOver{ false };
public:
	Game();
	~Game();
	void Load();
	void UnLoad();

	void Update();
	void Draw();

	void HandleInput();
	void Reset();
	void MoveBlockDown();
	bool EventTriggered(double interval);
private:
	Grid grid;
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
	double lastUpdateTime;
	Sound rotateSound;
	Sound clearSound;
private:
	void MoveBlockLeft();
	void MoveBlockRight();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void RotateBlock();
	bool isBlockOutside();
	void LockBlock();
	bool BlockFits();
	void UpdateScore(int linesCleared, int movedDownPoints);
};