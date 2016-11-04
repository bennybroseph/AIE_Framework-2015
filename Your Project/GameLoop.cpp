#include "GameLoop.h"



void GameLoop::Run()
{
	SDL_Event sdlEvent; // Will hold the next event to be parsed

	while (m_Running)
	{
		// Events get called one at a time, so if multiple things happen in one frame, they get parsed individually through 'SDL_PollEvent'
		// The next event to parse gets stored into 'sdlEvent', and then passed to the 'EventHandler' class which will call it's appropriate function here
		// 'SDL_PollEvent' returns 0 when there are no more events to parse
		while (SDL_PollEvent(&sdlEvent))
		{
			// Calls the redefined event function for the EventHandler class
			// Refer to its header file and cpp for more information on what each inherited function is capable of
			// and its syntax
			OnEvent(sdlEvent);
		}
		Update();

		LateUpdate();

		Draw();
		Graphics::Draw();

		Graphics::Flip(); // Required to update the window with all the newly drawn content
	}
}

void GameLoop::Update()
{

}
void GameLoop::LateUpdate()
{

}

void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas

	Graphics::DrawRect(Vector2(300.f, 300.f), Vector2(450.f, 450.f), Vector4(160.f, 65.f, 255.f, 255.f));
	Graphics::DrawRect(Vector2(10.f, 100.f), Vector2(200.f, 200.f), Vector4(0.f, 255.f, 0.f, 255.f));

	Graphics::DrawLine(Vector2(10.f, 10.f), Vector2(100.f, 100.f), Vector4(255.f, 255.f, 255.f, 255.f));
	Graphics::DrawPoint(Vector2(5.f, 5.f), Vector4(255.f, 255.f, 255.f, 255.f));

	Graphics::DrawRing(Vector2(140.f, 140.f), 50.f, 25.f, Vector4(50.f, 0.f, 200.f, 255.f));
	Graphics::DrawCircle(Vector2(800.f, 450.f), 200.f, 50.f, Vector4(0.f, 255.f, 255.f, 150.f));
}

void GameLoop::OnKeyDown(SDL_Keycode symbol, Uint16 modifier, SDL_Scancode scanecode)
{
	switch (symbol)
	{
	case SDLK_ESCAPE: m_Running = false; // End the loop
		break;

	default: printf("%s\n", SDL_GetKeyName(symbol)); // Prints the key the user Hits to the console
		break;
	}
}
void GameLoop::OnKeyUp(SDL_Keycode symbol, Uint16 modifier, SDL_Scancode scancode)
{
	switch (symbol)
	{
	default: break;
	}
}
void GameLoop::OnExit()
{
	m_Running = false; // End the loop
}

GameLoop::GameLoop()
{
	m_Running = true;
}
GameLoop::~GameLoop()
{

}
