#pragma once

#include "mesh.h"

namespace T3D
{
	class TCylinder :
		public Mesh
	{
	public:
		TCylinder(double radius, double height, int density);
		virtual ~TCylinder(void);
	};
}