#include "AnimationTest.h"
//#include "T3DApplication.h"


using namespace T3D;

	AnimationTest::AnimationTest(T3DApplication *app) : Task(app)
	{
		elapsedTime = 0;
		lamp = NULL;
	}
	void AnimationTest::update(float dt) {
		elapsedTime += dt;
		/*if (elapsedTime < 5) {
			lamp->setLocalPosition(Vector3::lerp(Vector3(0, 0, 0), Vector3(1, 0, 0), elapsedTime / 5.0));
		}
		else if (elapsedTime < 10){
			lamp->setLocalPosition(Vector3::lerp(Vector3(1, 0, 0), Vector3(0, 1, 0), (elapsedTime - 5) / 5.0));
		}*/
			//lamp->setLocalPosition(Vector3(Math::smoothedLerp(0, 10, elapsedTime / 10.0, 0.2), 0, 0));
		//printf("%f", elapsedTime);
	}
	/*void AnimationTest::init() {

	}*/
	AnimationTest::~AnimationTest(void)
	{
	}
	
