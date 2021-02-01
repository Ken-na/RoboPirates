#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"

#include "gameobject.h"

namespace T3D {

	class Lamp : public GameObject
	{
	public:
		Lamp(T3DApplication *app);
		~Lamp(void);

		bool init();
		
		GameObject *base;
		GameObject *arm1;
		GameObject *arm2;
		GameObject *shade;
		GameObject *baseJoint;
		GameObject *elbowJoint;
		GameObject *shadeJoint;
	};

}