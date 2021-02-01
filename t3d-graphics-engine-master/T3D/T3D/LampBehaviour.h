#pragma once
#include "component.h"
#include "Vector3.h"
#include "Transform.h"

namespace T3D
{
	class LampBehaviour :
		public Component
	{
	public:
		
		LampBehaviour();
		~LampBehaviour(void);

		virtual void update(float dt);

		float elapsedTime;
		Transform *target;
	};
}