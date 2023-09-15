//
//#include <iostream>
//#include "Application.h"
//
//
//
//int main(int argc, char** argv)
//{
//	{
//		Application app;
//		app.Run();
//	}
//
//	return 0;
//}

#include "raylib.h"
#include <stdlib.h>
#include <time.h>

const int screenWidth = 1920 / 2;
const int screenHeight = 1080 / 2;

const int numParticles = 100;
const float particleRadius = 5.0f;
const float maxVelocity = 50.0f;

struct Particle {
	Vector2 position;
	Vector2 velocity;
};

struct InverseParticle {
	Vector2 position;
	Vector2 velocity;
};

Particle particles[numParticles];
InverseParticle inverseParticles[numParticles];

float randomFloat(float min, float max) {
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

// inverse random float
float randomFloatInverse(float min, float max) {
	return max - static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

void initializeParticles() {
	for (int i = 0; i < numParticles; i++) {
		particles[i].position = { randomFloat(0, screenWidth), randomFloat(0, screenHeight) };
		particles[i].velocity = { randomFloat(-maxVelocity, maxVelocity), randomFloat(-maxVelocity, maxVelocity) };
	}
}

// inverse initialize particles
void initializeParticlesInverse() {
	for (int i = 0; i < numParticles; i++) {
		inverseParticles[i].position = { randomFloatInverse(0, screenWidth), randomFloatInverse(0, screenHeight) };
		inverseParticles[i].velocity = { randomFloatInverse(-maxVelocity, maxVelocity), randomFloatInverse(-maxVelocity, maxVelocity) };
	}
}

void updateParticles(float deltaTime) {
	for (int i = 0; i < numParticles; i++) {
		particles[i].position.x += particles[i].velocity.x * deltaTime;
		particles[i].position.y += particles[i].velocity.y * deltaTime;

		if (particles[i].position.x < 0) {
			particles[i].position.x = 0;
			particles[i].velocity.x = -particles[i].velocity.x;
		}
		if (particles[i].position.x > screenWidth) {
			particles[i].position.x = screenWidth;
			particles[i].velocity.x = -particles[i].velocity.x;
		}
		if (particles[i].position.y < 0) {
			particles[i].position.y = 0;
			particles[i].velocity.y = -particles[i].velocity.y;
		}
		if (particles[i].position.y > screenHeight) {
			particles[i].position.y = screenHeight;
			particles[i].velocity.y = -particles[i].velocity.y;
		}
	}
}

// inverse update particles
void updateParticlesInverse(float deltaTime) {
	for (int i = 0; i < numParticles; i++) {
		inverseParticles[i].position.x += inverseParticles[i].velocity.x * deltaTime;
		inverseParticles[i].position.y += inverseParticles[i].velocity.y * deltaTime;
		if (inverseParticles[i].position.x < 0) {
			inverseParticles[i].position.x = 0;
			inverseParticles[i].velocity.x = -inverseParticles[i].velocity.x;
		}
		if (inverseParticles[i].position.x > screenWidth) {
			inverseParticles[i].position.x = screenWidth;
			inverseParticles[i].velocity.x = -inverseParticles[i].velocity.x;
		}
		if (inverseParticles[i].position.y < 0) {
			inverseParticles[i].position.y = 0;
			inverseParticles[i].velocity.y = -inverseParticles[i].velocity.y;
		}
		if (inverseParticles[i].position.y > screenHeight) {
			inverseParticles[i].position.y = screenHeight;
			inverseParticles[i].velocity.y = -inverseParticles[i].velocity.y;
		}
	}
}

float calculateEntropy() {
	float sumVelocityX = 0;
	float sumVelocityY = 0;

	for (int i = 0; i < numParticles; i++) {
		sumVelocityX += particles[i].velocity.x;
		sumVelocityY += particles[i].velocity.y;
	}

	float averageVelocityX = sumVelocityX / numParticles;
	float averageVelocityY = sumVelocityY / numParticles;

	float entropyX = 0;
	float entropyY = 0;

	for (int i = 0; i < numParticles; i++) {
		entropyX += (particles[i].velocity.x - averageVelocityX) * (particles[i].velocity.x - averageVelocityX);
		entropyY += (particles[i].velocity.y - averageVelocityY) * (particles[i].velocity.y - averageVelocityY);
	}

	entropyX /= numParticles;
	entropyY /= numParticles;

	return entropyX + entropyY;
}

// inverse calculate entropy
float calculateEntropyInverse() {
	float sumVelocityX = 0;
	float sumVelocityY = 0;
	for (int i = 0; i < numParticles; i++) {
		sumVelocityX += inverseParticles[i].velocity.x;
		sumVelocityY += inverseParticles[i].velocity.y;
	}
	float averageVelocityX = sumVelocityX / numParticles;
	float averageVelocityY = sumVelocityY / numParticles;
	float entropyX = 0;
	float entropyY = 0;
	for (int i = 0; i < numParticles; i++) {
		entropyX += (inverseParticles[i].velocity.x - averageVelocityX) * (inverseParticles[i].velocity.x - averageVelocityX);
		entropyY += (inverseParticles[i].velocity.y - averageVelocityY) * (inverseParticles[i].velocity.y - averageVelocityY);
	}
	entropyX /= numParticles;
	entropyY /= numParticles;
	return entropyX + entropyY;
}

void entropyReducer() {
	for (int i = 0; i < numParticles; i++) {
		if (particles[i].velocity.x > 0) {
			particles[i].velocity.x -= 0.1f;
		}
		else {
			particles[i].velocity.x += 0.1f;
		}
		if (particles[i].velocity.y > 0) {
			particles[i].velocity.y -= 0.1f;
		}
		else {
			particles[i].velocity.y += 0.1f;
		}
	}
}

// inverse entropy reducer
void entropyReducerInverse() {
	for (int i = 0; i < numParticles; i++)
	{
		if (inverseParticles[i].velocity.x)
		{
			inverseParticles[i].velocity.x -= 0.1f;
		}
		else
		{
			inverseParticles[i].velocity.x += 0.1f;
		}

		if (inverseParticles[i].velocity.y)
		{
			inverseParticles[i].velocity.y -= 0.1f;
		}
		else
		{
			inverseParticles[i].velocity.y += 0.1f;
		}
	}
}

// attractor function
void attractor() {
	for (int i = 0; i < numParticles; i++) {
		if (particles[i].position.x < screenWidth / 2) {
			particles[i].velocity.x += 0.1f;
		}
		else {
			particles[i].velocity.x -= 0.1f;
		}
		if (particles[i].position.y < screenHeight / 2) {
			particles[i].velocity.y += 0.1f;
		}
		else {
			particles[i].velocity.y -= 0.1f;
		}
	}
}

// powerfull attractor function
void attractorPowerfull() {
	for (int i = 0; i < numParticles; i++) {
		if (particles[i].position.x < screenWidth / 2) {
			particles[i].velocity.x += 10.f;
		}
		else {
			particles[i].velocity.x -= 10.f;
		}
		if (particles[i].position.y < screenHeight / 2) {
			particles[i].velocity.y += 10.f;
		}
		else {
			particles[i].velocity.y -= 10.f;
		}
	}
}

// show the attractor path on the screen
void drawAttractor() {
	DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, RED);
	DrawLine(0, screenHeight / 2, screenWidth, screenHeight / 2, RED);
}

// show the path of the particles on the screen
void drawParticles() {
	for (int i = 0; i < numParticles; i++) {
		DrawLine(particles[i].position.x, particles[i].position.y, particles[i].position.x + particles[i].velocity.x, particles[i].position.y + particles[i].velocity.y, RED);
	}
}

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "Entropy Simulation");

	srand(time(nullptr));

	initializeParticles();
	/*initializeParticlesInverse();*/

	float elapsedTime = 0;
	float entropy = 0;
	float inverseEntropy = 0;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{

		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();
		elapsedTime += deltaTime;

		updateParticles(deltaTime);
		/*updateParticlesInverse(deltaTime);*/

		entropyReducer();
		//entropyReducerInverse();
		/*attractor();*/
		attractorPowerfull();
		/*drawParticles();*/

		entropy = calculateEntropy();


		inverseEntropy = calculateEntropyInverse();


		// how to make the inverse entropy go up?

		//----------------------------------------------------------------------------------

		// Draw
		//--------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (int i = 0; i < numParticles; i++) {
			DrawCircleV(particles[i].position, particleRadius, BLACK);
		}
		//      for (int i = 0; i < numParticles; i++) {
			  //	DrawCircleV(inverseParticles[i].position, particleRadius, BLUE);
			  //}
		DrawText(TextFormat("Entropy: %f", entropy), 10, 10, 20, BLACK);
		DrawText(TextFormat("Elapsed Time: %f", elapsedTime), 10, 40, 20, BLACK);
		//DrawText(TextFormat("Inverse Entropy: %f", inverseEntropy), 10, 70, 20, BLACK);
		/*drawAttractor();*/

		/*inverseEntropy++;*/

		EndDrawing();
		//----------------------------------------------------------------------------------
	}
	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}