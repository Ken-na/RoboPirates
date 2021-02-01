#pragma once

#include "mesh.h"

namespace T3D
{
	class HoleInTheWall :
		public Mesh
	{
	public:
		HoleInTheWall(Vector3 wallSize, float holeX, float holeY, float radius, int density);
		virtual ~HoleInTheWall(void);
	};
}


