#ifndef _GLSURFACE_H_
#define _GLSURFACE_H_
#pragma once

#include <GLFW/glfw3.h>

#include "MasterHeader.h"

enum LayerType
{
	BACKGROUND, // Lowest Layer
	INLINEFORE,	// Layer is behind the Mid-ground, but acts as if it is in line with the Foreground (currently not working)
	MIDGROUND,
	FOREGROUND,

	FOUNDATION,
	STRUCTURE,
	OVERLAY,

	ALWAYS_TOP // Highest Layer
};

struct GLSurface;

typedef unique_ptr<GLSurface> GLSurfacePtrU;
typedef shared_ptr<GLSurface> GLSurfacePtrS;
typedef weak_ptr<GLSurface> GLSurfacePtrW;

struct GLSurface
{
	GLuint handle;

	Vector2 position;
	Vector2 offsetPosition;
	Vector2 center;

	Vector2 size;
	Vector2 offsetSize;
	Vector2 scale;

	float rotation;

	Vector4 colour;

	LayerType layer;

	unsigned int worldSpace;

	bool isActive;

};


#endif // !_GLSURFACE_H_
