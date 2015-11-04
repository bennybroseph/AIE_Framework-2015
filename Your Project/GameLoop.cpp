#include "GameLoop.h"



void GameLoop::Loop()
{
	SDL_Event sdlEvent; // Will hold the next event to be parsed

	while (m_bRunning)
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


		if (!(iVer == (0 + iRadios) || iHor == (0 + iRadios)))
			if (control)
				iCount -= 10;
 
		LateUpdate();

		Draw(); 
		/*if (iHor == 0 )
			iCount += 20;*/
		Graphics::Flip(); // Required to update the window with all the newly drawn content
	}
}

//void GameLoop::OnHorizontel(const SDL_Keycode ac_sdl5ym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
//{
//	switch (ac_sdl5ym)
//	{
//	case SDLK_LEFT: iHorizontel += 10 ; break;
//	case SDLK_RIGHT: iHorizontel -= 10; break;
//	default:
//		break;
//	}
//}
//void GameLoop::OnVertical(const SDL_Keycode ac_sdl5ym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
//{
//	switch (ac_sdl5ym)
//	{
//	case SDLK_DOWN: iVertical += 10; break;
//	case SDLK_UP: iVertical -= 10; break;
//	default:
//		break;
//	}
//}
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

	//Graphics::DrawRect({ 400, 400 }, { 450, 400 }, { 160, 65, 255, 255 });
	Graphics::DrawRect({ 400, 300 }, { 500, 500 }, { 350,0, 0, 400 });

	Graphics::DrawRect({ 600, 150}, { 500, 500 }, { 0,0, 350, 400 });

	//Graphics::DrawLine({ 10, 10 }, { 100, 100 }, { 255, 255, 255, 255 });
	//Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

	/*Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
	Graphics::DrawCircle({ (800 + iHorizontel), (450 + iVertical) }, 200, 50, { 0, 100, 255, 150 });*/

	/*Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });*/
	/*Graphics::DrawCircle({ (iHor = (800 + iCount)), (iVer = (450)) }, iRadios, 50 + iHorizontel, { 100, 255, 255, 150 });*/
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	printf("%s\n", SDL_GetKeyName(ac_sdlSym));
	Vecter3<int> Dude(2, 34, 5);
	Vecter3<int> Dude2(2, 34, 5);
	Vecter3<int> Dude3(0, 0, 0);
	Dude3 = Dude2 + Dude;
	std::cout << Dude3.num1;
	switch (ac_sdlSym)
	{
	default: printf("%s\n", SDL_GetKeyName(ac_sdlSym)); break;
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop
	case SDLK_LEFT: iHorizontel += 1; break;
	case SDLK_RIGHT: iHorizontel -= 1; break; 
	case SDLK_DOWN: iVertical += 10; break;
	case SDLK_UP: iVertical -= 10; break;
	case SDLK_SPACE: control = true; break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	case SDLK_SPACE: 
	default: break;
	}
}
void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop   
}

GameLoop::GameLoop()
{
	m_bRunning = true;
}
GameLoop::~GameLoop()
{

}
