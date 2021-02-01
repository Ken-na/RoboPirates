
#pragma once

#include "mesh.h"

namespace T3D
{
	class Rectangle :
		public Mesh
	{
	public:
		Rectangle(float w, float h, float d);
		virtual ~Rectangle(void);
	};
}

