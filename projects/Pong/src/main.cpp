#include <nlohmann/json.hpp>
#include <iostream>
#include "Application.h"
#include "Game.h"

Game game;

int main(int argc, char** argv)
{
	{
		Application app;
		app.Run();
	}

	return 0;
}
