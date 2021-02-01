#pragma once
#include "component.h"
#include "Vector3.h"
#include "Transform.h"

namespace T3D
{
	class OarPaddle :
		public Component
	{
	public:

		OarPaddle();
		~OarPaddle(void);

		virtual void update(float dt);

		float elapsedTime;
		Transform *target;
	};
}