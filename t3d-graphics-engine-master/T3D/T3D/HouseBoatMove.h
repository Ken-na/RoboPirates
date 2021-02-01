#pragma once
//#include "T3DApplication.h"
#include "task.h"

namespace T3D {
	class HouseBoatMove :
		public Task
	{
	public:
		HouseBoatMove(T3DApplication *app);
		~HouseBoatMove(void);
		virtual void update(float dt);
		//void init();
		//~AnimationTask(T3DApplication *app);

		float elapsedTime;
		Transform *obj;
	};
}