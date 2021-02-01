#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"
#include "mesh.h"
#include "gameobject.h"

namespace T3D {

	class Task1Sweep : public GameObject
	{
	public:
		Task1Sweep(T3DApplication *app);
		~Task1Sweep(void);

		bool init();

		GameObject *boat;
	};

}
