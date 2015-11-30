#include "GameLoop.h"


int iHorizontel = 0, iVertical = 0, iVer = 450, iHor = 800, fDeltaTime = 0, iTally = 0;
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
		//if (!(iVer == (0 + iRadios) || iHor == (0 + iRadios)))
			if (control)
			{
				int iIncramet = iTally + fDeltaTime * iSPEED;
				std::cout << iHor << std::endl;
				iVer  += -iTally * fDeltaTime;
			/*	srand(time(NULL));
				int iRandNum = rand() % 3;*/
				if (iHor < 20)
				{
					bCollisionL = true; bCollisionR = false; bCollisionDown = false; bCollisionUp = false;
				}
				
				if (iHor > 1580)
				{
					bCollisionR = true; bCollisionL = false; bCollisionDown = false; bCollisionUp = false;
				}
				if (iVer < 10)
				{
					bCollisionUp = true; bCollisionL = false; bCollisionR = false; bCollisionDown = false;
				}
				if( iVer > 900) 
				{
					bCollisionDown = true; bCollisionUp = false; bCollisionL = false; bCollisionR = false; 
				}
				
				if (bCollisionL)
				{
					
					srand(time(NULL));
					iRandNumL = rand() % 3;
					std::cout << "LEFT ACTIVE: " <<  iRandNumD << std::endl;
					
					switch(iRandNumL)
					{ 
					case 0:
						iHor += iIncramet;
						break;
					case 1:
					
						iHor += iIncramet;
						iVer += iIncramet;
						break;
					case 2:
						iHor += iIncramet;
						iVer += -iIncramet;
						break;
					}

				}
				else if (bCollisionR)
				{

					srand(time(NULL));
					iRandNumR = rand() % 3;
					std::cout << "RIGHT ACTIVE: " << iRandNumR << std::endl;

					switch(iRandNumR)
					{
						iHor += -iIncramet;
						break;
					
					case 1:
					
						iHor += -iIncramet;
						iVer += -iIncramet;
						break;
					case 2:
					
						iHor += -iIncramet;
						iVer += iIncramet;
						break;
					}
				}

				else if (bCollisionUp)
				{
					
					srand(time(NULL));
					iRandNumU = rand() % 3;
					std::cout << "UP ACTIVE: " << iRandNumD << std::endl;

					switch (iRandNumU)
					{
					case 0:
						iVer += iTally + fDeltaTime * iSPEED;
						break;
					case 1:
						iHor += iIncramet;
						iVer += iIncramet;
						break;
					case 2:
						iHor += -iIncramet;
						iVer += iIncramet;
						break;
					}
				}

				else if (bCollisionDown)
				{
					
					srand(time(NULL));
					iRandNumD = rand() % 3;
					std::cout << "DOWN ACTIVE: " << iRandNumD << std::endl;

					switch(iRandNumD)
					{
					case 0:
						iVer += -iIncramet;
						break;
					case 1:
						iHor += -iIncramet;
						iVer += iIncramet;
						break;
					case 2:
						iHor += -iIncramet;
						iVer += -iIncramet;
						break;
					}
				}
					
			}
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
	Graphics::DrawRect({ 1585,  fPaddleR = (5 + fUpDownR )}, { 10, 300 }, { 350 ,0, 0, 255 });

	Graphics::DrawRect({ 5, fPaddleL = (5 + fUpDownL) }, { 10, 300 }, { 100,0, 350, 255 });

	/*Graphics::DrawLine({ 10, 10 }, { 100, 100 }, { 255, 255, 255, 255 });*/
	//Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

	/*Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
	Graphics::DrawCircle({ (800 + iHorizontel), (450 + iVertical) }, 200, 50, { 0, 100, 255, 150 })*/;

	/*Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });*/
	Graphics::DrawCircle({ iHor , iVer }, iRadios, 50 + iHorizontel, { 100, 255, 255, 150 });
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	printf("%s\n", SDL_GetKeyName(ac_sdlSym));
	Vector3<int> Dude(2, 34, 5);
	Vector3<int> Dude2(2, 34, 5);
	Vector3<int> Dude3(0, 0, 0);

	
	Dude3 = Dude2 ^ Dude;
	/*std::cout << iRandNum << std::endl;*/
	

	switch (ac_sdlSym)
	{
	default: printf("%s\n", SDL_GetKeyName(ac_sdlSym)); break;
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop
	case SDLK_LEFT: iHorizontel += 1; break;
	case SDLK_RIGHT: iHorizontel -= 1; break; 
	case SDLK_DOWN: bDownUpR = true; break;
	case SDLK_UP: bUpDownR = true; break;
	case SDLK_SPACE: control = true; break;
	case SDLK_w: bUpDownL = true; break;
	case SDLK_s: bDownUpL = true; break;
	case SDLK_r: control = false; iHor = 800; iVer = 450; bCollisionL = false; bCollisionR = false; bCollisionDown = false; bCollisionUp = false; break;



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
