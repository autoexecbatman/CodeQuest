#pragma once

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

	Game* m_game = nullptr;
};

