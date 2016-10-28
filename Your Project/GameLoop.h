//////////////////////////////////////////////////////////////
// File: GameLoop.h
// Author: Ben Odom
// Brief: A short and simple game loop object which will allow
//		  a base layout for how you should organize your game
//		  functions.
//////////////////////////////////////////////////////////////

#ifndef _GAMELOOP_H_
#define _GAMELOOP_H_

#include <Graphics.h>
#include <EventHandler.h>

// This is called inheritance
// The GameLoop class inherits every member variable and function from 'EventHandler'
// Think of it like a car. All trucks are cars, but not all cars are trucks.
// A van is also a car. Both truck and van inherit values from car, but they are
// both unique. The 'GameLoop' class can use all the functions from 'EventHandler' but
// it also has its own which are defined below. See the header and source file
// of EvenHandler if you're feeling brave and want to see what other user input
// you can receive using this Engine
class GameLoop : EventHandler
{

public:
	// The game loop
	void Loop();

	// An update function that gets called directly after input is parsed
	void Update();
	// An update function that gets called directly after 'Update()'
	void LateUpdate();

	// An update-like function that gets called directly after 'LateUpdate'
	void Draw();

	// Gets called automatically by 'EventHandler' when a key is pressed
	void OnKeyDown(SDL_Keycode symbol, Uint16 modifier, SDL_Scancode sdlScancode) override;
	// Gets called automatically by 'EventHandler' when a key is released
	void OnKeyUp(SDL_Keycode symbol, Uint16 modifier, SDL_Scancode sdlScancode) override;
	// Gets called automatically by 'EventHandler' when the user clicks the 'x' on the window
	void OnExit() override;

	// The default constructor
	GameLoop();
	// The default de-constructor
	~GameLoop();

private:

	bool m_Running; // If this is true, the game loop will continue to run

};


#endif // _GAMELOOP_H_