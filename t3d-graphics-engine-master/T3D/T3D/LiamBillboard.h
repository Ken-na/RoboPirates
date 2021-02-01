// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// LiamBillboard.h
//
// Simple LiamBillboard mesh with coloured sides

#include "mesh.h"

namespace T3D
{
	class LiamBillboard :
		public Mesh
	{
	public:
		LiamBillboard(float size);
		virtual ~LiamBillboard(void);
	};
}


