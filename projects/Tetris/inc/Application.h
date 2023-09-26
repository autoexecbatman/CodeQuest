#pragma once
#include <memory>

class Game;

class Application
{
public:

	Application();
	~Application();

	void Run();

	void GameLoop();

protected:
private:

	std::unique_ptr<Game> m_game{ nullptr };
};

