#pragma once

class Game
{
public:
	const int windowWidth = 800;
	const int windowHeight = 450;
	const char* windowTitle = "Hello Raylib";
	bool shouldQuit = false;

public:

	Game();
	~Game();

	void Load();
	void UnLoad();

	void Update();
	void Draw();

protected:
private:
};