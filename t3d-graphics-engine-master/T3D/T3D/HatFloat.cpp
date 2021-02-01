#include "HatFloat.h"
//#include "T3DApplication.h"


using namespace T3D;

HatFloat::HatFloat(T3DApplication *app) : Task(app)
{
	elapsedTime = 0;
	obj = NULL;
}
void HatFloat::update(float dt) {
	elapsedTime += dt;
	
	if (elapsedTime > 67 && elapsedTime < 70) {
		//printf("s");
		//obj->setLocalPosition(Vector3::lerp(Vector3(-90, 8, 70), Vector3(-70, 8, 50), elapsedTime / 10.0));
		obj->setLocalPosition(Vector3(35, Math::smoothedLerp(-10, 1, (elapsedTime - 67) / 3, 0.2), -45));
		obj->setLocalRotation(Vector3(-90 * Math::DEG2RAD, Math::smoothedLerp(0, 180, (elapsedTime - 67) / 3, 0.2) * Math::DEG2RAD, 0));

	}
	//lamp->setLocalPosition(Vector3(Math::smoothedLerp(0, 10, elapsedTime / 10.0, 0.2), 0, 0));
//printf("%f", elapsedTime);
}
/*void HatFloat::init() {

}*/
HatFloat::~HatFloat(void)
{
}

