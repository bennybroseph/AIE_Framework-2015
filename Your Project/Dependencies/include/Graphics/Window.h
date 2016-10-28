//////////////////////////////////////////////////////////////
// File: Window.h
// Author: Ben Odom
// Brief: This class contains all the necessary variables for
//		  the OpenGL context and SDL Window. Multiple
//		  instances of this class will exist at any given
//		  time, and each has functions that the 'Graphics'
//		  namespace can use to handle it internally
//////////////////////////////////////////////////////////////

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <GLFW/glfw3.h>
#include <SDL/SDL.h>

#include "MasterHeader.h"

namespace Graphics
{
	class Window
	{
	public:

		bool Resize(const UVector2 &newDimensions, unsigned monitorIndex);
		bool Rename(const char *newTitle);

		bool ToggleFullscreen();

		const UVector2& GetDimensions() const;
		const UVector2& GetWindowedDimensions() const;
		const UVector2 & GetResolution() const;

		SDL_Window * GetWindow() const;
		const SDL_GLContext & GetContext() const;

		bool GetIsFullscreen() const;

		void Flip() const;

		// This is the only usable constructor
		Window(
			const UVector2 &				resolution,		// The window's internal resolution
			bool							isFullscreen,	// Whether or not the window should be full screen on creation
			const UVector2 &				dimensions,		// The window's width and height
			const char *					title,			// The window's title
			unsigned						monitorIndex,	// Which monitor the window should be created on
			const List<SDL_DisplayMode> &	displayModes);	// A reference to all the current displays dimensions and specifications
		// The default constructor does not exist on purpose
		Window() = delete; // Make sure the default constructor cannot be called
		~Window();

	private:

		SDL_Window *m_SDLWindow;
		SDL_GLContext m_SDLGLContext;

		const List<SDL_DisplayMode> &m_SDLDisplayModes;

		UVector2PtrU m_Dimensions			= make_unique<UVector2>();
		UVector2PtrU m_WindowedDimensions	= make_unique<UVector2>();
		UVector2PtrU m_Resolution			= make_unique<UVector2>();

		UVector2PtrU m_Viewport		= make_unique<UVector2>();
		UVector2PtrU m_ViewOffset	= make_unique<UVector2>();

		string m_Title;

		bool m_IsFullscreen;

		unsigned m_MonitorIndex;

	};
}

#endif // _WINDOW_H_