#pragma once
//#include "T3DApplication.h"
#include "task.h"
#include "LookAtBehaviour.h"
#include "GameObject.h"

namespace T3D {
	class CameraMovement :
		public Task
	{
	public:
		CameraMovement(T3DApplication *app);
		~CameraMovement(void);
		virtual void update(float dt);
		//void init();
		//~AnimationTask(T3DApplication *app);

		float elapsedTime;
		Transform *obj;
		GameObject *objGameobj;
		Transform *lookat1;
		Transform *lookat2;
		Transform *lookat3;
		Transform *lookat4;
		Transform *lookat5;
		Transform *lookat6;
		Transform *lookat7;
		LookAtBehaviour *looky;
	};
}