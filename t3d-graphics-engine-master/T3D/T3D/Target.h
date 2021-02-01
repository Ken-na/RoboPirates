#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"

#include "gameobject.h"

namespace T3D {

	class Target : public GameObject
	{
	public:
		Target(T3DApplication *app);
		~Target(void);

		bool init();

		GameObject *target;
		GameObject *innerTarget;
		GameObject *inner2Target;
		GameObject *targetStand;

		GameObject *targetJoint;
	};

}