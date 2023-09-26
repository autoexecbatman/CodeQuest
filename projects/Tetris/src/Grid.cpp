#include "Grid.h"
#include <iostream>
#include "Colors.h"

Grid::Grid()
{
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	Initialize();
	colors = GetCellColors();
}

Grid::~Grid()
{

}

void Grid::Initialize()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			grid[row][col] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < numRows; row++)
	{
		std::cout << "|";
		for (int col = 0; col < numCols; col++)
		{
			std::cout << grid[row][col];
		}
		std::cout << "|" << std::endl;
	}
}

void Grid::Draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			int cellValue = grid[row][col];
			Color cellColor = colors[cellValue];
			DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, cellColor);
		}
	}
}

bool Grid::IsCellOutside(int row, int column)
{
	if (row >= 0 && row < numRows && column >= 0 && column < numCols)
	{
		return false;
	}
	return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
	if (grid[row][column] == 0)
	{
		return true;
	}
	return false;
}

// returns the number of rows cleared.
int Grid::ClearFullRows()
{
	int completed = 0;
	for (int row = numRows - 1; row >= 0; row--)
	{
		if (IsRowFull(row))
		{
			ClearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			MoveRowsDown(row, completed);
		}
	}
	return completed;
}

// check if any of the cells in a row are empty (empty = value of 0)
bool Grid::IsRowFull(int row)
{
	for (int column = 0; column < numCols; column++)
	{
		if (grid[row][column] == 0)
		{
			return false;
		}
	}
	return true;
}

// clear a row by setting all the cells to 0
void Grid::ClearRow(int row)
{
	for (int column = 0; column < numCols; column++)
	{
		grid[row][column] = 0;
	}
}

void Grid::MoveRowsDown(int row, int numRows)
{
	for (int column = 0; column < numCols; column++)
	{
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}
