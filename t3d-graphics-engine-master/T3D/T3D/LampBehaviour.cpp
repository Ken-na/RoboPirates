#include "LampBehaviour.h"
#include "GameObject.h"

namespace T3D
{
	LampBehaviour::LampBehaviour() {
		elapsedTime = 0;
	}
	LampBehaviour::~LampBehaviour(void)
	{
	}

	void LampBehaviour::update(float dt) {
		elapsedTime += dt;
		if (elapsedTime < 5) {
			
			gameObject->getTransform()->setLocalPosition(Vector3::lerp(Vector3(0, 0, 0), Vector3(1, 0, 0), elapsedTime / 5.0));
		}
		else if (elapsedTime < 10){
			gameObject->getTransform()->setLocalPosition(Vector3::lerp(Vector3(1, 0, 0), Vector3(0, 1, 0), (elapsedTime - 5) / 5.0));
		}
	}

}