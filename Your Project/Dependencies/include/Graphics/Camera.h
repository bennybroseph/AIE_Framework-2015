//////////////////////////////////////////////////////////////
// File: Window.h
// Author: Ben Odom
// Brief: This class contains all the necessary variables for
//		  a viewport in OpenGL. It also includes some
//		  functionality for scrolling cameras, as well as
//		  zoom and rotation for single instances of a camera.
//////////////////////////////////////////////////////////////

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "MasterHeader.h"

namespace Graphics
{
	class Camera
	{

	public:

		void Resize(const Vector2 &newDimensions);
		void RePosition(const Vector2 &screenPosition);
		void ReBind(const Vector2 &newRelativePosition);

		void Update();

		const Vector2 & GetScreenPos() const;
		const Vector2 & GetWorldPos() const;
		const Vector2 & GetDimensions() const;
		const Vector2 & GetResolution() const;
		const Vector2 & GetZoom() const;
		float GetRotation() const;
		unsigned int GetWindowIndex() const;
		unsigned int GetWorldSpace() const;

		Camera(
			const Vector2 &	screenPosition,
			const Vector2 &	worldPosition,
			const Vector2 &	relativePosition,
			const Vector2 &	size,
			const Vector2 &	resolution,
			const Vector2 &	zoom,
			float			rotation,
			bool			isScrolling,
			const Vector2 &	velocity,
			unsigned		windowIndex,
			unsigned		worldSpace);
		Camera() = delete;
		~Camera();

	private:

		Vector2 m_ScreenPos;
		Vector2 m_WorldPos;
		const Vector2 *	m_RelativePos;

		Vector2 m_Dimensions;
		Vector2 m_Resolution;

		Vector2 m_Zoom;
		float m_Rotation;

		bool m_IsScrolling;

		Vector2 m_Velocity;

		unsigned int m_WindowIndex;
		unsigned int m_WorldSpace;

	};
}

#endif // _CAMERA_H_