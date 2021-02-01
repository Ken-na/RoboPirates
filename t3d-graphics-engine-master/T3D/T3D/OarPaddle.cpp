#include "OarPaddle.h"
#include "GameObject.h"

namespace T3D
{
	OarPaddle::OarPaddle() {
		elapsedTime = 0;
	}
	OarPaddle::~OarPaddle(void)
	{
	}

	void OarPaddle::update(float dt) {
		elapsedTime += dt;
		if (elapsedTime < 5) {
			//gameObject->getTransform()->setLocalPosition(Vector3::lerp(Vector3(0, 0, 0), Vector3(1, 0, 0), elapsedTime / 5.0));
			//gameObject->getTransform()->setLocalRotation(Quaternion(Math::smoothedLerp((//Quaternion(Vector3::lerp(Vector3(3 * Math::PI / 2, 0, 0), Vector3(11 * Math::PI / 6, 0, 0), elapsedTime / 5.0)));
		}
		else if (elapsedTime < 10) {
			gameObject->getTransform()->setLocalRotation(Quaternion(Vector3::lerp(Vector3(11 * Math::PI / 2, 0, 0), Vector3(3 * Math::PI / 2, 0, 0), elapsedTime / 5.0)));
			//gameObject->getTransform()->setLocalPosition(Vector3::lerp(Vector3(1, 0, 0), Vector3(0, 1, 0), (elapsedTime - 5) / 5.0));
		}
		else {
			elapsedTime = 0;
		}
	}

}