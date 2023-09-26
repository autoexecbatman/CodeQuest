#include "Game.h"
#include "raylib.h"
#include "Grid.h"
#include <random>
#include <iostream>

Game::Game()
{
	std::cout << "Game constructor" << std::endl;
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	
	score = 0;

	InitAudioDevice();

	PlayMusicStream(music);
}

Game::~Game()
{
	UnLoad();
	CloseAudioDevice();
}

void Game::Load()
{
	font = LoadFontEx("../assets/font/monogram.ttf", 64, 0, 0);
	music = LoadMusicStream("../assets/audio/music.mp3");
	rotateSound = LoadSound("../assets/audio/rotate.mp3");
	clearSound = LoadSound("../assets/audio/clear.mp3");
	PlayMusicStream(music);
	std::cout << "Game load" << std::endl;
}

void Game::UnLoad()
{
}

void Game::Update()
{
	UpdateMusicStream(music);
	if (EventTriggered(0.2))
	{
		MoveBlockDown();
	}
}

void Game::Draw()
{

	BeginDrawing();

	ClearBackground(darkBlue);
	grid.Draw();
	currentBlock.Draw(11, 11);
	

	DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
	DrawTextEx(font, "Next", { 375, 175 }, 38, 2, WHITE);
	if (gameOver)
	{
		DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
	}
	DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);
	
	char scoreText[10];
	sprintf_s(scoreText, "%d", score);
	Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

	DrawTextEx(
		font,
		std::to_string(score).c_str(),
		{ 320 + ( 170 - textSize.x)/2, 65},
		38,
		2,
		WHITE
	);

	DrawRectangleRounded({ 320, 235, 170, 180 }, 0.3, 6, lightBlue);
	switch (nextBlock.id)
	{
	case 3:
		nextBlock.Draw(255, 290);
		break;
	case 4:
		nextBlock.Draw(255, 280);
		break;
	default:
		nextBlock.Draw(255, 270);
		break;
	}
	EndDrawing();
}

Block Game::GetRandomBlock()
{
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0)
	{
		gameOver = false;
		Reset();
	}
	switch (keyPressed)
	{
	case KEY_LEFT:
	{
		MoveBlockLeft();
		break;
	}
	case KEY_RIGHT:
	{
		MoveBlockRight();
		UpdateScore(0, 1);
		break;
	}
	case KEY_DOWN:
	{
		MoveBlockDown();
		break;
	}
	case KEY_UP:
	{
		RotateBlock();
		break;
	}
	case KEY_SPACE:
	{
		// pause the music
		StopMusicStream(music);
		break;
	}
	case KEY_ENTER:
	{
		// resume the music
		PlayMusicStream(music);
		break;
	}
	}
}

void Game::Reset()
{
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

std::vector<Block> Game::GetAllBlocks()
{
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::MoveBlockLeft()
{
	if (!gameOver)
	{
		currentBlock.Move(0, -1);
		if (isBlockOutside() || BlockFits() == false)
		{
			currentBlock.Move(0, 1);
		}
	}
}

void Game::MoveBlockRight()
{
	if (!gameOver)
	{
		currentBlock.Move(0, 1);
		if (isBlockOutside() || BlockFits() == false)
		{
			currentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown()
{
	if (!gameOver)
	{
		currentBlock.Move(1, 0);
		if (isBlockOutside() || BlockFits() == false)
		{
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
	UpdateScore(0, 1);
}

bool Game::EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime > interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

void Game::RotateBlock()
{
	if (!gameOver)
	{
		currentBlock.Rotate();
		if (isBlockOutside() || BlockFits() == false)
		{
			currentBlock.UndoRotation();
		}
		else
		{
			PlaySound(rotateSound);
			std::cout << "rotate sound !" << std::endl;
		}
	}
}

bool Game::isBlockOutside()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (grid.IsCellOutside(item.row, item.column))
		{
			return true;
		}
	}
	return false;
}

void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (BlockFits() == false)
	{
		// game over
		gameOver = true;
	}
	nextBlock = GetRandomBlock();
	int rowsCleared = grid.ClearFullRows();	

	// play sound if rows were cleared
	if (rowsCleared > 0)
	{
		PlaySound(clearSound);
		std::cout << "clear sound !" << std::endl;
		UpdateScore(rowsCleared, 0);
	}
}

// check every cell of a block to see 
// if it is on top of an empty cell of the grid or not
bool Game::BlockFits()
{
	// get the current block's tiles
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	// loop through all the tiles
	for (Position item : tiles)
	{
		// if the cell is not empty, return false
		if (grid.IsCellEmpty(item.row, item.column) == false)
		{
			return false;
		}
	}
	// if the cells are not occupied, return true
	return true;
}

void Game::UpdateScore(int linesCleared, int movedDownPoints)
{
	// cases for different number of lines cleared
	switch (linesCleared)
	{
	case 1:
		score += 100; // 100 points for 1 line
		break;
	case 2:
		score += 300; // 300 points for 2 lines
		break;
	case 3:
		score += 500; // 500 points for 3 lines
		break;
	default:
		break;
	}
	// add 1 point for moving down
	score += movedDownPoints;
}
