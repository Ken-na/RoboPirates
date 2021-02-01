#include "CameraMovement.h"
//#include "T3DApplication.h"


using namespace T3D;

CameraMovement::CameraMovement(T3DApplication *app) : Task(app)
{
	elapsedTime = 0;
	obj = NULL;
	lookat1 = NULL;
	lookat2 = NULL;
	objGameobj = NULL;

}
void CameraMovement::update(float dt) {
	elapsedTime += dt;
	if (elapsedTime < 10) {
		looky = new LookAtBehaviour(lookat1);
		objGameobj->addComponent(looky);
		obj->setLocalPosition(Vector3(Math::smoothedLerp(-10, 10, elapsedTime / 10.0, 0.2), 12, 16));
		//lamp->setLocalPosition(Vector3::lerp(Vector3(0, 0, 0), Vector3(1, 0, 0), elapsedTime / 5.0));
	}
	//else if (elapsedTime < 12) {
		//obj->setLocalRotation(Vector3::lerp(Vector3(10, 12, 16), Vector3(1, 0, 0), elapsedTime / 5.0));
	//}
	else if (elapsedTime < 15){
		/*GameObject *blank = new GameObject(app);
		blank->setTransform(obj);
		LookAtBehaviour *blankBe = new LookAtBehaviour(lookat2);
		blank->addComponent(blankBe);*/
		//looky = new LookAtBehaviour(lookat2);
		//objGameobj->addComponent(looky);
		obj->setLocalPosition(Vector3::lerp(Vector3(10, 12, 16), Vector3(10, 12, -4), (elapsedTime-10) / 5.0));
		//obj->setLocalRotation(Vector3::lerp(obj->getEulerAngles(), blank->getTransform()->getEulerAngles(), (elapsedTime-10) / 2.0));
		//obj->setLocalPosition(Vector3::lerp(Vector3(10, 12, 16), Vector3(10, 12, 0), (elapsedTime-10) / 2.0));
		/*obj->setLocalPosition(Vector3(Math::smoothedLerp(10, 5, (elapsedTime - 10) / 5.0, 0.2),
			Math::smoothedLerp(12, 12, (elapsedTime - 10) / 5.0, 0.2), 
			Math::smoothedLerp(16, 0, (elapsedTime - 10) / 5.0, 0.2)));*/

	}
	/*else if (elapsedTime < 15.5) {
		GameObject *blank = new GameObject(app);
		//blank->setTransform(obj);
		blank->getTransform()->setParent(obj);
		LookAtBehaviour *blankBe = new LookAtBehaviour(lookat2);
		blank->addComponent(blankBe);
		obj->setLocalRotation(Quaternion::lerp(obj->getQuaternion(), blank->getTransform()->getQuaternion(), (elapsedTime-15) / .5));
	}*/
	else if (elapsedTime < 30) {
		//obj->setParent(lookat1);
		looky = new LookAtBehaviour(lookat2);
		objGameobj->addComponent(looky);
		//obj->setLocalPosition(Vector3(0, -2, 0));
		obj->setLocalPosition(Vector3::lerp(Vector3(10, 12, -4), Vector3(-13, 10, 0), (elapsedTime - 15) / 15));
	}
	else if (elapsedTime > 31 && elapsedTime < 34) {
		obj->setLocalPosition(Vector3::lerp(Vector3(-13, 10, 0), Vector3(-13, 12, 4), (elapsedTime - 31) / 3));
		//obj->setLocalPosition(Vector3::lerp(Vector3(-36, 10, 0), Vector3(-36, 10, 4), (elapsedTime - 30) / 34.0));
		//obj->setLocalPosition(Vector3::lerp(Vector3(-36, 10, 0), Vector3(-36, 10, 4), (elapsedTime - 30) / 4.0));
	}
	else if (elapsedTime > 36 && elapsedTime < 40) {
		obj->setLocalPosition(Vector3::lerp(Vector3(-13, 12, 4), Vector3(-23, 11, 5), (elapsedTime - 36) / 4));
		//obj->setLocalPosition(Vector3::lerp(Vector3(-36, 10, 0), Vector3(-36, 10, 4), (elapsedTime - 30) / 34.0));
		//obj->setLocalPosition(Vector3::lerp(Vector3(-36, 10, 0), Vector3(-36, 10, 4), (elapsedTime - 30) / 4.0));
	}
	else if (elapsedTime > 43 && elapsedTime < 46) {
		//GameObject *bb = new GameObject(app);
		//bb->getTransform()->setLocalPosition(Vector3(-23, 11, 5));
		//LookAtBehaviour *blankBe = new LookAtBehaviour(lookat3);
		//bb->addComponent(blankBe);
		looky = new LookAtBehaviour(lookat3);
		objGameobj->addComponent(looky);
		//objGameobj->removeComponent();
		//bb->getTransform()->setLocalPosition(obj->getLocalPosition);
		//bb->getTransform()->lookAt(lookat3->getWorldPosition());
		//obj->setLocalRotation(Quaternion::lerp(obj->getQuaternion(), bb->getTransform()->getQuaternion(), (elapsedTime - 43) / 46));
		//obj->setLocalRotation(Quaternion::lerp(obj->getQuaternion(), bb->getTransform()->getQuaternion(), (elapsedTime - 43) / 46));
	}
	else if (elapsedTime > 46 && elapsedTime < 48) {
		looky = new LookAtBehaviour(lookat5);
		objGameobj->addComponent(looky);
	}
	else if (elapsedTime > 48 && elapsedTime < 50) {
		looky = new LookAtBehaviour(lookat4);
		objGameobj->addComponent(looky);
	}
	else if (elapsedTime > 50 && elapsedTime < 56) {
		looky = new LookAtBehaviour(lookat6);
		objGameobj->addComponent(looky);
		obj->setLocalPosition(Vector3::lerp(Vector3(-23, 11, 5), Vector3(-45, 11, 25), (elapsedTime - 50) / 6));
	}
	else if (elapsedTime > 61 && elapsedTime < 67) {
		looky = new LookAtBehaviour(lookat1);
		objGameobj->addComponent(looky);
		obj->setLocalPosition(Vector3::lerp(Vector3(-45, 11, 25), Vector3(-23, 11, 5), (elapsedTime - 61) / 6));
	}
	else if (elapsedTime > 67 && elapsedTime < 70) {
		looky = new LookAtBehaviour(lookat7);
		objGameobj->addComponent(looky);
		//obj->setLocalPosition(Vector3::lerp(Vector3(-45, 11, 25), Vector3(-23, 11, 5), (elapsedTime - 56) / 6));
	}
	else if (elapsedTime > 70 && elapsedTime < 74) {
		
		obj->setLocalPosition(Vector3::lerp(Vector3(-23, 11, 5), (lookat7->getWorldPosition() + Vector3(-1.5, 5, -1.5)), (elapsedTime - 70) / 4)); //-3,-3 besst so far
	}
	//lamp->setLocalPosition(Vector3(Math::smoothedLerp(0, 10, elapsedTime / 10.0, 0.2), 0, 0));
//printf("%f", elapsedTime);
}
/*void CameraMovement::init() {

}*/
CameraMovement::~CameraMovement(void)
{
}

