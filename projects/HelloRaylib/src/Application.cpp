#include "Application.h"
#include "raylib.h"

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
	InitWindow(m_windowWidth, m_windowHeight, m_windowTitle);
	SetTargetFPS(60);

	#ifdef __EMSCRIPTEN__
		// The browser requires the main loop to be executed in a callback
		// this way infinite loops do not crash the browser
		EmscriptenGameLoopFunc::app = this;
		emscripten_set_main_loop(EmscriptenGameLoopFunc::Execute, 0, 1);
	#else
		// On windows, we control our own main loop
		// run until the m_quitApplication has been set to true
		while (!m_shouldQuit)
			GameLoop();
	#endif

	// clearnup
	CloseWindow();
}

void Application::GameLoop()
{
	m_shouldQuit = m_shouldQuit | WindowShouldClose();

	Update();
	Render();
}

void Application::Update()
{

}

void Application::Render()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawRectangle(10, 10, 100, 100, RED);

	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
}