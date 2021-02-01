// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// TCube.h
//
// Simple TCube mesh with coloured sides

#include "mesh.h"

namespace T3D
{
	class TCube :
		public Mesh
	{
	public:
		TCube(float size);
		virtual ~TCube(void);
	};
}


