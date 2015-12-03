#include "GameLoop.h"








Vector2<int> V2BallSize1(50, 50);
Vector2<int> V2BallSize2(50, 50);

Vector3<int> V3BallLocation1(900,450, 200);
Vector3<int> V3BallLocation2(750, 450, 200);
int iHorizontel = 0, iVertical = 0, fDeltaTime = 0, iTally = 0;
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
		//delta time 
		fCurrentT = clock();
		fDeltaTime = (fCurrentT - fPreviouseT)/10;
		
		// bad collision detection
		//if (!(iVer == (0 + iRadios) || iHor == (0 + iRadios)))
		//	if (control)
		//	{
		//		int iIncramet = iTally + fDeltaTime * iSPEED;
		//		std::cout << iHor << std::endl;
		//		iVer  += -iTally * fDeltaTime;
		//	/*	srand(time(NULL));
		//		int iRandNum = rand() % 3;*/
		
		fPreviouseT = fCurrentT;

		if (bUpDownL)
			fUpDownL -= 10;
		if (bUpDownR)
			fUpDownR -= 10;
		if (bDownUpL)
			fUpDownL += 10;
		if (bDownUpR)
			fUpDownR += 10;


		/*if(!())*/
	/*	std::cout << fDeltaTime << std::endl;*/
	
				//e/*lse if()*/
 
		LateUpdate();

		Draw(); 
		/*if (iHor == 0 )
			iHor  += 20;*/
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

	//Graphics::DrawRect({ 400, 400 }, { 450, 400 }, { 160, 65, 255, 255 });
	//Graphics::DrawRect({ 1585,  fPaddleR = (5 + fUpDownR )}, { 10, 300 }, { 255 ,0, 0, 255 });

	//Graphics::DrawRect({ 5, fPaddleL = (5 + fUpDownL) }, { 10, 300 }, { 0, 0, 255, 255 });

	/*Graphics::DrawLine({ 10, 10 }, { 100, 100 }, { 255, 255, 255, 255 });*/
	//Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

	/*Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
	Graphics::DrawCircle({ (800 + iHorizontel), (450 + iVertical) }, 200, 50, { 0, 100, 255, 150 })*/;

	/*Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });*/
	if (Intropolation) {
		V3BallLocation1 =   V3BallLocation1%V3BallLocation1;
		V3BallLocation2 = V3BallLocation1 % V3BallLocation1;
	}
	if (bRest)
	{
		Intropolation = false;
		V3BallLocation1.XX = 900;
		V3BallLocation1.YY = 450;
		V3BallLocation2.XX = 750;
		V3BallLocation2.YY = 450;

		Vector2<int> V2BallSize1(50, 50);
		Vector2<int> V2BallSize2(50, 50);
		bRest = false;
	}
	Graphics::DrawCircle({ V3BallLocation1.XX , V3BallLocation1.YY }, V2BallSize1.XX, V2BallSize1.YY, { 0, 255, 0, V3BallLocation1.ZZ });

	Graphics::DrawCircle({ V3BallLocation2.XX , V3BallLocation2.YY }, V2BallSize2.XX, V2BallSize2.YY , { 255, 0, 0, V3BallLocation2.ZZ });
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	printf("%s\n", SDL_GetKeyName(ac_sdlSym));


	
	 
	switch (ac_sdlSym)
	{
	default: printf("%s\n", SDL_GetKeyName(ac_sdlSym)); break;
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop
	case SDLK_LEFT: V3BallLocation1.XX += 1; break;
	case SDLK_RIGHT: V3BallLocation1.XX -= 1; break; 
	case SDLK_DOWN: V3BallLocation1.YY += 1; break;
	case SDLK_UP: V3BallLocation1.YY -= 1; break;
	case SDLK_a: if (Choose)
	{
		V2BallSize1.XX += 10;
	}
	else V2BallSize2.XX += 10; break;
	case SDLK_d: V2BallSize1.XX -= 10; break;
	case SDLK_SPACE: control = true; break;
	case SDLK_w: bUpDownL = true; break;
	case SDLK_s: bDownUpL = true; break;
	case SDLK_t: Add = true; break;
	case SDLK_c: Choose = true; break; 
	case SDLK_r: bRest = true; break;
	case SDLK_i: Intropolation = true; break;
	



	}
	//if(ac_sdlSym == SDLK_DOWN)
	//	fUpDownR += 10;
	//if(ac_sdlSym == SDLK_UP)
	//	fUpDownR -= 10;
	//if(ac_sdlSym == SDLK_w)
	//	fUpDownL -= 10;
	//if(ac_sdlSym == SDLK_s)
	//	fUpDownL += 10;



}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	case SDLK_DOWN: bDownUpR = false; break;
	case SDLK_UP: bUpDownR = false; break;
	case SDLK_w: bUpDownL = false; break;
	case SDLK_s: bDownUpL = false; break;
	case SDLK_SPACE: iTally = 10; break;
	case SDLK_c: Choose = false; break;
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
