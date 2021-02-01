#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"

#include "gameobject.h"

namespace T3D {

	class Bullet : public GameObject
	{
	public:
		Bullet(T3DApplication *app);
		~Bullet(void);

		bool init();

		GameObject *bullet;/*
		GameObject *arm1;
		GameObject *arm2;
		GameObject *shade;
		GameObject *baseJoint;
		GameObject *elbowJoint;
		GameObject *shadeJoint;*/
	};

}
