#pragma once
//#include "T3DApplication.h"
#include "task.h"

namespace T3D {
	class HatFloat :
		public Task
	{
	public:
		HatFloat(T3DApplication *app);
		~HatFloat(void);
		virtual void update(float dt);
		//void init();
		//~AnimationTask(T3DApplication *app);

		float elapsedTime;
		Transform *obj;
	};
}