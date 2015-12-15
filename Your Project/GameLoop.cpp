#include "GameLoop.h"







Vector4<float> V4BallColor1;
 
Vector2<float> V2BallSize1(50, 50);
Vector2<float> V2BallSize2(50, 50);
Vector2<float> V2BallSize3(5, 5);
Vector2<float> V2BallSize4( 0, 0);

Vector3<float> V3BallLocation1(900,450, 200);
Vector3<float> V3BallLocation2(750, 450, 200);
Vector3<float> V3BallLocation3(0, 0, 0);
int iHorizontel = 0, iVertical = 0, fDeltaTime = 0, iTally = 0;
void GameLoop::Loop()
{
	if (control)
		std::cout << "Collide Confimed GO HOME" << std::endl;
	else
		std::cout << std::endl;
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
	Vector2 <float> p1(V3BallLocation2.XX, (V3BallLocation2.YY + 100));
	Vector2 <float> p4((V3BallLocation2.XX + 100), V3BallLocation2.YY);


	Vector2<float> z1(V3BallLocation1.XX, (V3BallLocation1.YY + 100));
	Vector2<float> z4((V3BallLocation1.XX + 100), V3BallLocation1.YY);

	control = false;
	if ((p4.XX >= z1.XX && z1.XX <= p4.XX) && p4.YY )
		control = true;
	if (z4.YY >= p1.YY && z1.YY <= p4.YY)
		control = true;
	


	if (Intropolation)
		V3BallLocation3  = V3BallLocation1 % V3BallLocation1;
	if (Add) 
		V3BallLocation3 = V3BallLocation1 + V3BallLocation2;
	if(Sub)
		V3BallLocation3 = V3BallLocation1 - V3BallLocation2;
	if(Cross)
		V3BallLocation3 = V3BallLocation1 ^ V3BallLocation2;
	if (bRest)
	{
		
		V3BallLocation1.XX = 900;
		V3BallLocation1.YY = 450;
		V3BallLocation2.XX = 750;
		V3BallLocation2.YY = 450;
		V3BallLocation3.XX = 0;
		V3BallLocation3.YY = 0;
		V2BallSize1.Radions();


		Color = "#FFABFF";
		V2BallSize1.XX = 50;
		V2BallSize1.YY = 50;
		V2BallSize2.XX = 50;
		V2BallSize2.YY = 50;

		bRest = false;
		Intropolation = false;
		Add = false;
		Sub = false;
		Cross = false;

	}
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

	Graphics::DrawRect({ V3BallLocation1.XX  , V3BallLocation1.YY }, { 100, 100 }, { 255, 0, 255, 100 });
	Graphics::DrawRect({ V3BallLocation2.XX , V3BallLocation2.YY }, { 100, 100 }, { 0, 0, 255, 100 });

	Graphics::DrawCircle({ 1000,550 },  1,450, { 225,225,225,225 });

	for (float line = 5; line < 1800; line+=5 )
	{
		for (float liner = 10; liner < 900;liner+=5)
			Graphics::DrawLine({ line, liner }, { 100, 100 }, { 255, 255, 255, 255 });
	}
		
	//Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

	//Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
	//Graphics::DrawCircle({ (800 + iHorizontel), (450 + iVertical) }, 200, 50, { 0, 100, 255, 150 });

	/*Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });*/

//if (Paint)
//{
//	std::cout << "Enter Hexa Color value(Most start in with #): "; 
//	std::cin >> Color;
//	Paint = false;
//}
//		
	//Graphics::DrawCircle({ V3BallLocation1.XX , V3BallLocation1.YY },
	//V2BallSize1.XX, V2BallSize1.YY, { V4BallColor1.Hexadecimal(Color).RR,
	//V4BallColor1.Hexadecimal(Color).GG, V4BallColor1.Hexadecimal(Color).BB,
	//V4BallColor1.Hexadecimal(Color).AA });
//
	Graphics::DrawCircle({ V3BallLocation2.XX + 50 , V3BallLocation2.YY + 50 },V2BallSize2.XX, V2BallSize2.YY , { 255, 0, 0,100 });
//
//	Graphics::DrawCircle({ V3BallLocation3.XX , V3BallLocation3.YY },
//	V2BallSize1.XX, V2BallSize1.YY, { V4BallColor1.Hexadecimal("#FFABFF").RR,
//	V4BallColor1.Hexadecimal("#FFABFF").GG, V4BallColor1.Hexadecimal("#FFABFF").BB,
//	V4BallColor1.Hexadecimal("#FFABFF").AA });
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	printf("%s\n", SDL_GetKeyName(ac_sdlSym));
	switch (ac_sdlSym)
	{
	default: printf("%s\n", SDL_GetKeyName(ac_sdlSym)); break;
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop
	case SDLK_LEFT:if (Choose) { V3BallLocation1.XX -= iSPEED; }
	else V3BallLocation2.XX -= iSPEED; break;
	case SDLK_RIGHT: if (Choose) { V3BallLocation1.XX += iSPEED; }
	else V3BallLocation2.XX += iSPEED; break;
	case SDLK_DOWN: if (Choose) { V3BallLocation1.YY += iSPEED; }
	else V3BallLocation2.YY += iSPEED; break;
	case SDLK_UP: if (Choose) { V3BallLocation1.YY -= iSPEED; }
	else V3BallLocation2.YY -= iSPEED; break;
	case SDLK_a: if (Choose) { V2BallSize2.XX += 10; }
	else V2BallSize1.XX += 10; break;
	case SDLK_d:if (Choose) { V2BallSize2.XX -= 10; }
	else V2BallSize1.XX -= 10; break;
	case SDLK_SPACE: control = true; break;
	case SDLK_w: bUpDownL = true; break;
	case SDLK_s: Sub = true; break;
	case SDLK_t: Add = true; break;
	case SDLK_c: Choose = false; break; 
	case SDLK_r: bRest = true; break;
	case SDLK_i: Intropolation = true; break;
	case SDLK_p: Paint = true; break;
	case SDLK_6: Cross = true; break;
	case SDLK_EQUALS: Add = true; break;
	case SDLK_MINUS: Sub = true; break;
	



	}

}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	case SDLK_DOWN: bDownUpR = false;  break;
	case SDLK_UP: bUpDownR = false; break;
	case SDLK_w: bUpDownL = false; break;
	case SDLK_s: bDownUpL = false; break;
	case SDLK_SPACE: iTally = 10; break;
	case SDLK_c: Choose = true; break;
	case SDLK_r: bRest = false; break;
	case SDLK_i: Intropolation = false; break;
	case SDLK_p: Paint = false; break;
	case SDLK_6: Cross = false; break;
	case SDLK_EQUALS: Add = false; break;
	case SDLK_MINUS: Sub = false; break;
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
