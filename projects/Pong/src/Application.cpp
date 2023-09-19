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
	InitWindow(game.windowWidth, game.windowHeight, game.windowTitle);
	SetTargetFPS(60);

	game.Load();

	#ifdef __EMSCRIPTEN__
		// The browser requires the main loop to be executed in a callback
		// this way infinite loops do not crash the browser
		EmscriptenGameLoopFunc::app = this;
		emscripten_set_main_loop(EmscriptenGameLoopFunc::Execute, 0, 1);
	#else
		// On windows, we control our own main loop
		// run until the m_quitApplication has been set to true
		while (!game.shouldQuit)
			GameLoop();
	#endif

	game.UnLoad();

	// clearnup
	CloseWindow();
}

void Application::GameLoop()
{
	game.shouldQuit = game.shouldQuit || WindowShouldClose();

	game.Update();
	game.Draw();
}
