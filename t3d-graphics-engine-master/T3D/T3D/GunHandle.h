#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"

#include "gameobject.h"

namespace T3D {

	class GunHandle : public GameObject
	{
	public:
		GunHandle(T3DApplication *app);
		~GunHandle(void);

		bool init();

		GameObject *gunHandle;
	};

}