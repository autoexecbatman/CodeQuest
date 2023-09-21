#include "Application.h"
#include "raylib.h"
#include "Game.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>

struct EmscriptenGameLoopFunc
{
	static void Execute() { app->GameLoop(); }
	static Application* app;
};
Application* EmscriptenGameLoopFunc::app = nullptr;

#endif

Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	m_game = new Game();

	InitWindow(m_game->windowWidth, m_game->windowHeight, m_game->windowTitle);
	SetTargetFPS(60);

	m_game->Load();

	#ifdef __EMSCRIPTEN__
		// The browser requires the main loop to be executed in a callback
		// this way infinite loops do not crash the browser
		EmscriptenGameLoopFunc::app = this;
		emscripten_set_main_loop(EmscriptenGameLoopFunc::Execute, 0, 1);
	#else
		// On windows, we control our own main loop
		// run until the m_quitApplication has been set to true
		while (!m_game->shouldQuit)
			GameLoop();
	#endif

	m_game->UnLoad();

	// clearnup
	CloseWindow();

	delete m_game;
	m_game = nullptr;
}

void Application::GameLoop()
{
	m_game->shouldQuit = m_game->shouldQuit || WindowShouldClose();

	m_game->Update();
	m_game->Draw();

}
