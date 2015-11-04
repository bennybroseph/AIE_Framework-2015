//////////////////////////////////////////////////////////////
// Project: Student Graphics Engine
// Author: Ben Odom
//////////////////////////////////////////////////////////////

#include "GameLoop.h"

int wmain()
{
	Graphics::Init();

	Graphics::NewWindow({ 1600, 900 }, false, { 1600, 900 }, "Graphics Engine");

	GameLoop oGameLoop;

	oGameLoop.Loop();

	Graphics::Quit();

	

	


	return 0;
}  