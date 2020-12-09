#pragma once


class Application
{
public:

	Application();
	~Application();

	void Run();

	void GameLoop();

	void Update();
	void Render();

protected:
private:

	const char* m_windowTitle = "Hello World";
	int m_windowWidth = 800;
	int m_windowHeight = 450;

	bool m_shouldQuit = false;
};

