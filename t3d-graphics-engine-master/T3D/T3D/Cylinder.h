#pragma once

#include "mesh.h"

namespace T3D
{
	class Cylinder :
		public Mesh
	{
	public:
		Cylinder(double radius, double height, int density);
		virtual ~Cylinder(void);
	};
}