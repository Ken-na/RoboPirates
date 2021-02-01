#pragma once
//#include "T3DApplication.h"
#include "task.h"

namespace T3D {
	class AnimationTest:
		public Task
	{
	public:
		AnimationTest(T3DApplication *app);
		~AnimationTest(void);
		virtual void update(float dt);
		//void init();
		//~AnimationTask(T3DApplication *app);

		float elapsedTime;
		Transform *lamp;
	};
}