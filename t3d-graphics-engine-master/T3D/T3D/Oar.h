#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"
#include "mesh.h"
#include "gameobject.h"


namespace T3D
{
	class Oar :
		public Mesh
	{
	public:
		Oar();
		virtual ~Oar(void);
		GameObject *stick;
	};
}

