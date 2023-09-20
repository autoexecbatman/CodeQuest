#pragma once
#include <iostream>
#include <string>
#include <entt/entt.hpp> // Include EnTT

class Game
{
public:
	const int windowWidth = 800;
	const int windowHeight = 450;
	const char* windowTitle = "CppRL";
	bool shouldQuit = false;

public:

	Game();
	~Game();

	void Load();
	void UnLoad();

	void Update();
	void Draw();
	void log(const std::string& message) {
		std::cout << message << std::endl;
	}

protected:
private:
	entt::registry registry{}; // Initialize EnTT registry
	entt::entity player; // Declare player entity
	entt::entity enemy; // Declare enemy entity
};

extern Game game;