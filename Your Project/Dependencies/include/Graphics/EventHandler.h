//////////////////////////////////////////////////////////////
// File: EventHandler.h
// Author: Ben Odom
// Brief: You're not meant to create an object of this class
//		  This class is created to simply be inherited.
//		  By making all virtual functions, each object
//        can redefine what happens on that event
//////////////////////////////////////////////////////////////

#ifndef _EVENTHANDLER_H_
#define _EVENTHANDLER_H_

#include <SDL/SDL.h>

class EventHandler
{
protected:
	//////Constructor - Destructor//////

	EventHandler() { }
	//This should be virtual if any member function is virtual
	virtual ~EventHandler() { }

	//////Functions//////

	// All of these functions are virtual and empty so that they do not need to be defined in the derived class
	// But may be redefined if needed

	//Takes in the event, and then calls the appropriate function
	virtual void OnEvent(const SDL_Event& event);

	//Deals with window focus (alt-tab)
	virtual void OnInputFocus() { }
	virtual void OnInputBlur() { }

	//Takes in sym (The enum naming the key) the mod (if any, like shift), and unicode (in case of typing)
	virtual void OnKeyDown(const SDL_Keycode symbol, const Uint16 modifier, const SDL_Scancode scancode) { }
	virtual void OnKeyUp(const SDL_Keycode symbol, const Uint16 modifier, const SDL_Scancode scancode) { }

	//Deals with window focus (clicking in and out)
	virtual void OnMouseFocus() { }
	virtual void OnMouseBlur() { }

	//Passes mouse_x mouse_y x_velocity,  y_velocity, buttonL, buttonR, buttonM (scroll wheel)
	virtual void OnMouseMove(
		const int mouseX,
		const int mouseY,
		const int velocityX,
		const int velocityY,
		const bool leftIsPressed,
		const bool rightIsPressed,
		const bool middleIsPressed) { }

	//Passes which way the mouse wheel is spun
	virtual void OnMouseWheel(const bool scrollUp, const bool scrollDown) { }

	//If mouse buttons down/up
	virtual void OnLButtonDown(const int mouseX, const int mouseY) { }
	virtual void OnLButtonUp(const int mouseX, const int mouseY) { }
	virtual void OnRButtonDown(const int mouseX, const int mouseY) { }
	virtual void OnRButtonUp(const int mouseX, const int mouseY) { }
	virtual void OnMButtonDown(const int mouseX, const int mouseY) { }
	virtual void OnMButtonUp(const int mouseX, const int mouseY) { }

	//Checks for joystick events, but there's an SDL_Joystick object that I didn't implement which is much better
	//Don't recommend using these functions
	virtual void OnJoyAxis(const Uint8 which, const Uint8 axis, const Sint16 value) { }
	virtual void OnJoyButtonDown(const Uint8 which, const Uint8 button) { }
	virtual void OnJoyButtonUp(const Uint8 which, const Uint8 button) { }
	virtual void OnJoyHat(const Uint8 which, const Uint8 hat, const Uint8 value) { }
	virtual void OnJoyBall(
		const Uint8 which, const Uint8 ball, const Sint16 relativeX, const Sint16 relativeY) { }

	//Minimize and maximize of window
	virtual void OnMinimize() { }
	virtual void OnRestore() { }

	//When the window gets resized, returns the new W and H
	virtual void OnResize(const int width, const int height) { }

	//Most likely when the window is restored from being minimized?
	virtual void OnExpose() { }

	//Can be different for each class that defines it
	virtual void OnExit() { }

	//No clue
	virtual void OnUser(const Uint8 type, const int code, const void* data1, const void* data2) { }
};

#endif // _EVENTHANDLER_H_
