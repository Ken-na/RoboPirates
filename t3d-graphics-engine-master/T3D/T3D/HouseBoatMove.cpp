#include "HouseBoatMove.h"
//#include "T3DApplication.h"


using namespace T3D;

HouseBoatMove::HouseBoatMove(T3DApplication *app) : Task(app)
{
	elapsedTime = 0;
	obj = NULL;
}
void HouseBoatMove::update(float dt) {
	elapsedTime += dt;
	if (elapsedTime > 30){
		//obj->setLocalPosition(Vector3::lerp(Vector3(-90, 8, 70), Vector3(-70, 8, 50), elapsedTime / 10.0));
		obj->setLocalPosition(Vector3(Math::smoothedLerp(-100, -70, (elapsedTime-30) / 20.0, 0.2), 8, Math::smoothedLerp(80, 50, (elapsedTime-30) / 20.0, 0.2)));
		
	}
	//lamp->setLocalPosition(Vector3(Math::smoothedLerp(0, 10, elapsedTime / 10.0, 0.2), 0, 0));
//printf("%f", elapsedTime);
}
/*void HouseBoatMove::init() {

}*/
HouseBoatMove::~HouseBoatMove(void)
{
}

