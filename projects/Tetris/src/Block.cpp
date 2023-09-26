#include "Block.h"
#include <raylib.h>
#include "Position.h"

Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rowOffset = 0;
	columnOffset = 0;
}

// this method will draw the block on the screen.
// it will loop through all the cells in the current rotation state
// and draw a rectangle for each one.
void Block::Draw(int offsetX, int offsetY)
{
	// get the default cell positions for the current rotation state.
	std::vector<Position> tiles = GetCellPositions();
	for (Position item : tiles)
	{
		DrawRectangle(
			item.column * cellSize + offsetX, // x (+11 to offset the grid)
			item.row * cellSize + offsetY, // y (+11 to offset the grid)
			cellSize - 1, // width (-1 to leave a 1px gap between cells)
			cellSize - 1, // height (-1 to leave a 1px gap between cells)
			colors[id] // color
		);
	}
}

void Block::Move(int rows, int columns)
{
	rowOffset += rows;
	columnOffset += columns;
}

// this method will return a std::vector 
// with the positions of the occupied cells 
// after applying the offset.
std::vector<Position> Block::GetCellPositions()
{
	// get the default cell positions for the current rotation state.
	std::vector<Position> tiles = cells[rotationState];
	// new empty vector to hold the moved tiles.
	std::vector<Position> movedTiles;
	// loop through all the tiles and add the offset to their positions.
	for (Position item : tiles)
	{
		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}

void Block::Rotate()
{
	rotationState++;
	if (rotationState >= static_cast<int>(cells.size()))
	{
		rotationState = 0;
	}
}

void Block::UndoRotation()
{
	rotationState--;
	if (rotationState < 0)
	{
		rotationState = static_cast<int>(cells.size()) - 1;
	}
}
