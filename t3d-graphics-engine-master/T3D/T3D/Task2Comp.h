#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"
#include "mesh.h"
#include "gameobject.h"
//#include "Oar.h"

namespace T3D {

	class Task2Comp : public GameObject
	{
	public:
		Task2Comp(T3DApplication *app);
		~Task2Comp(void);

		bool init();

		GameObject *boat;

		GameObject *oarJoint1;
		GameObject *oar1;
		GameObject *oarTip1;

		GameObject *oarJoint2;
		GameObject *oar2;
		GameObject *oarTip2;

		GameObject *oarJoint3;
		GameObject *oar3;
		GameObject *oarTip3;

		GameObject *oarJoint4;
		GameObject *oar4;
		GameObject *oarTip4;

	};

}
