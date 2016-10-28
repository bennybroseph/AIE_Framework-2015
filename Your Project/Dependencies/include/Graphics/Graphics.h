#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "Window.h"
#include "Camera.h"
#include "GLSurface.h"

namespace Graphics
{
	extern List<Camera*> cameras; // The vector that holds each type of 'Camera' object
	extern List<Window*> windows; // The vector that holds each 'Window' object

	// - Sets up the Graphics namespace to be used. Must be called before using any free functions
	bool Init();

	/* - Creates a 'new Window' and pushes it into the 'voWindows' vector
	   Parameters:
	   - The window's internal resolution
	   - Whether or not the window should be full screen on creation
	   - The window's width and height
	   - The window's title -- Default = "New Window"
	   - Which monitor the window should be created on -- Default = 0
	*/
	bool NewWindow(
		const UVector2 &	resolution,				// Whether or not the window should be full screen on creation
		const UVector2 &	dimensions,				// The window's internal resolution
		bool				isFullscreen = false,	// The window's width and height
		const char *		title = "New Window",	// The window's title
		unsigned			monitorIndex = 0u);		// Which monitor the window should be created on

	// - Allows a window in the 'voWindows' vector to change Size
	void Resize(
		const UVector2 &	newDimensions,			// The new Size of the Window
		unsigned 			index = 0u,				// Which window to change
		unsigned			newMonitorIndex = 0u);	// The monitor the Window should be placed on

	// - Toggles the window from it's current state of full screen
	void ToggleFullscreen(unsigned index = 0u);

	// - Creates a 'new Camera' object and passes it the following parameters
	void NewCamera(
		const Vector2 &	screenPosition		={ 0.f, 0.f },		// Where the 'Camera' object should be placed relative to the screen
		const Vector2 &	worldPosition		={ 0.f, 0.f },		// Where in the World the 'Camera' object should start in the world. Serves as an offset to 'm_RelativePos'
		const Vector2 &	relativePosition	={ 0.f, 0.f },		// What point if any the 'Camera' should be anchored to, such as a player object's 'Point2D'
		const Vector2 &	size				={ 100.f, 100.f },	// The size of the 'Camera' object relative to the window size
		const Vector2 &	zoom				={ 1.f, 1.f },		// The zoom in of the 'Camera' object
		float			rotation			= 0.f,				// The rotation of the 'Camera' object
		bool			isScrolling			= false,			// Whether or not the 'Camera' object scrolls
		const Vector2 &	velocity			={ 0.f, 0.f },		// If the 'Camera' object scrolls, it needs a velocity as well
		unsigned 		windowIndex			= 0u,				// Which window the 'Camera' object should affect
		unsigned 		worldSpace			= 0u);				// Which world space the 'Camera' object exists in. This can be any positive number

	// - Makes sure when the window is resized that all 'Camera' objects resize to match it
	void ResizeCameras(const UVector2 &size, unsigned index);

	// - Draws all surfaces currently in the 'vglSurfaces' vector
	void Draw();

	// - Updates the view-port to match the current 'Camera' object used to draw and then draws all surfaces in its world space
	void UpdateCameras();

	// - Draws a 'GLSurface' in relation to a 'Camera' object
	void DrawSurface(const GLSurface& glSurface, const Camera& camera);

	// - Sorts each surface based on its layer order
	bool SortLayer(GLSurface* left, GLSurface* right);
	// - Sorts each surface based on its camera order
	bool SortCamera(GLSurface* left, GLSurface* right);

	// - Loads a 'GLSurface' from a filename
	GLSurface* LoadSurface(const char* filename);
	// - Loads a 'GLSurface' from an existing 'SDL_Surface'
	GLSurface* LoadSurface(SDL_Surface& sdlSurface);

	// - Pushes a 'GLSurface' of type int into the 'vglSurfaces' vector
	void PushSurface(GLSurface* glSurface);

	// - Pushes a 'Camera' of type int into the 'voCamera' vector
	void PushCamera(Camera* camera);

	// - Draws a colored rectangle at the specified position with a given width and height
	void DrawRect(const Vector2 &position, const Vector2 &size, const Vector4 &colour);
	// - Draws a colored line at with a given beginning and end
	void DrawLine(const Vector2 &head, const Vector2 &tail, const Vector4 &colour);
	// - Draws a colored pixel with a given beginning and end
	void DrawPoint(const Vector2& position, const Vector4 &ac_Color);
	// - Draws a colored ring with a given center, radius, and quality modifier
	void DrawRing(const Vector2 &center, float radius, float points, const Vector4 &colour);
	// - Draws a colored circle with a given center, radius, and quality modifier
	void DrawCircle(const Vector2 &center, float radius, float points, const Vector4 &colour);

	void Flip(); // Clears the buffer of all windows to allow all the new information to be displayed

	void Quit();
}

#endif // _GRAPHICS_H_
