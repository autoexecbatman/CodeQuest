#include "Colors.h"
#include <raylib.h>
#include <vector>

const Color empty = { 0, 0, 0, 255 };
const Color greendark = { 0, 200, 0, 255 };
const Color greenlight = { 0, 255, 0, 255 };
const Color red = { 255, 0, 0, 255 };
const Color yellow = { 255, 255, 0, 255 };
const Color blue = { 0, 0, 255, 255 };
const Color purple = { 255, 0, 255, 255 };
const Color orange = { 255, 165, 0, 255 };
const Color lightBlue = { 0, 209, 241, 255 };
const Color darkBlue = { 0, 80, 160, 255 };

std::vector<Color> GetCellColors()
{
	return { empty, greendark, greenlight, red, yellow, blue, purple, orange };
}