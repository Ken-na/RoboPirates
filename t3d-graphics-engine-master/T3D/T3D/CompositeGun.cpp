#include "Cube.h"
#include "Cylinder.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "CompositeGun.h"
#include "Sphere.h"
#include "Pyramid.h"

#include "Rectangle.h"
using namespace T3D;

CompositeGun::CompositeGun(T3DApplication *app) :GameObject(app) {

	//getTransform()->name = "Hand";

	
	handleJoint = new GameObject(app);
	handleJoint->getTransform()->setParent(getTransform());
	handleJoint->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	handleJoint->getTransform()->setLocalRotation(Quaternion(Vector3(11 * Math::PI / 6, 0, 0)));
	handleJoint->getTransform()->name = "HandleJoint";


	lowerBody = new GameObject(app);
	lowerBody->setMesh(new Rectangle(.1, .3, .08));//.2, .15));
	lowerBody->getTransform()->setLocalPosition(Vector3(0, .65, .6));
	lowerBody->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	lowerBody->getTransform()->setParent(handleJoint->getTransform());
	lowerBody->getTransform()->name = "LowerBody";

	middleBody = new GameObject(app);
	middleBody->setMesh(new Rectangle(.105, .20, .075));//.2, .15));
	middleBody->getTransform()->setLocalPosition(Vector3(0, .9, .32));
	middleBody->getTransform()->setParent(handleJoint->getTransform());
	middleBody->getTransform()->name = "MiddleBody";
	//the base of the chamber arm
	chamberArmJoint = new GameObject(app);
	chamberArmJoint->getTransform()->setParent(lowerBody->getTransform());
	chamberArmJoint->getTransform()->setLocalPosition(Vector3(0, -.17, -.025));// .01 looks better when upright, .07 looks better when loading, maybe an animation where it slides out could be cool.
	chamberArmJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0))); //when y = 0, upright chamber, when y = Math::PI / 3, loading chamber. 
	chamberArmJoint->getTransform()->name = "ChamberArmJoint";

	chamberArm = new GameObject(app);
	chamberArm->setMesh(new Rectangle(.02, .2, .02));
	chamberArm->getTransform()->setParent(chamberArmJoint->getTransform());
	chamberArm->getTransform()->setLocalPosition(Vector3(0, -.175, 0));
	chamberArm->getTransform()->name = "ChamberArm";
	//where the chamber will pivot at the end of the chamber arm
	chamberJoint = new GameObject(app);
	chamberJoint->getTransform()->setParent(chamberArm->getTransform());
	chamberJoint->getTransform()->setLocalPosition(Vector3(0, -.09, 0));
	chamberJoint->getTransform()->name = "ChamberJoint";

	chamber = new GameObject(app);
	chamber->setMesh(new Cylinder(.15, .2, 6));
	chamber->getTransform()->setParent(chamberJoint->getTransform());
	chamber->getTransform()->setLocalRotation(Quaternion(Vector3(3 * Math::PI / 2, 0, 0)));
	chamber->getTransform()->setLocalPosition(Vector3(0, 0, -.22));
	chamber->getTransform()->name = "Chamber";

	upperBody = new GameObject(app);
	upperBody->setMesh(new Rectangle(.075, .275, .03));//.2, .15));
	upperBody->getTransform()->setLocalPosition(Vector3(0, 1.12, .6));
	upperBody->getTransform()->setLocalRotation(Quaternion(Vector3(3 * Math::PI / 2, 0, 0)));
	upperBody->getTransform()->setParent(handleJoint->getTransform());
	upperBody->getTransform()->name = "UpperBody";

	frontBody = new GameObject(app);
	frontBody->setMesh(new Rectangle(.075, .03, .15));//.2, .15));
	frontBody->getTransform()->setLocalPosition(Vector3(0, .8, .9));
	frontBody->getTransform()->setLocalRotation(Quaternion(Vector3(3 * Math::PI / 2, 0, 0)));
	frontBody->getTransform()->setParent(handleJoint->getTransform());
	frontBody->getTransform()->name = "FrontBody";

	barrel = new GameObject(app);
	barrel->setMesh(new Cylinder(.10, .5, 12));//.2, .15));
	barrel->getTransform()->setLocalPosition(Vector3(0, 1.0, 1.35));
	barrel->getTransform()->setLocalRotation(Quaternion(Vector3(3 * Math::PI / 2, 0, 0)));
	barrel->getTransform()->setParent(handleJoint->getTransform());
	barrel->getTransform()->name = "Barrel";

	ironSight = new GameObject(app);
	ironSight->setMesh(new Pyramid(.05));//.2, .15));
	ironSight->getTransform()->setLocalPosition(Vector3(0, -.35, .11));
	ironSight->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	ironSight->getTransform()->setParent(barrel->getTransform());
	ironSight->getTransform()->name = "IronSight";
	//trigger 
	triggerJoint = new GameObject(app);
	triggerJoint->getTransform()->setParent(handleJoint->getTransform());
	triggerJoint->getTransform()->setLocalPosition(Vector3(0, .6, .5));
	triggerJoint->getTransform()->setLocalRotation(Quaternion(Vector3(330 * Math::DEG2RAD, 0, 0)));
	triggerJoint->getTransform()->name = "TriggerJoint";

	trigger = new GameObject(app);
	trigger->setMesh(new Rectangle(.02, .1, .03));
	trigger->getTransform()->setLocalPosition(Vector3(0, -.05, 0));
	trigger->getTransform()->setParent(triggerJoint->getTransform());
	trigger->getTransform()->name = "Trigger";

	triggerGuardFront = new GameObject(app);
	triggerGuardFront->setMesh(new Rectangle(.045, .185, .03));
	triggerGuardFront->getTransform()->setParent(handleJoint->getTransform());
	triggerGuardFront->getTransform()->setLocalPosition(Vector3(0, .5, .72));
	triggerGuardFront->getTransform()->setLocalRotation(Quaternion(Vector3(1 * Math::PI / 10, 0, 0)));
	triggerGuardFront->getTransform()->name = "TriggerGuardFront";

	triggerGuardBack = new GameObject(app);
	triggerGuardBack->setMesh(new Rectangle(.04, .15, .03));
	triggerGuardBack->getTransform()->setParent(handleJoint->getTransform());
	triggerGuardBack->getTransform()->setLocalPosition(Vector3(0, .4, .5));
	triggerGuardBack->getTransform()->setLocalRotation(Quaternion(Vector3(7 * Math::PI / 12, 0, 0)));
	triggerGuardBack->getTransform()->name = "TriggerGuardBack";

	//lever
	leverJoint = new GameObject(app);
	leverJoint->getTransform()->setParent(handleJoint->getTransform());
	leverJoint->getTransform()->setLocalPosition(Vector3(0, 1.12, .3));
	leverJoint->getTransform()->setLocalRotation(Quaternion(Vector3(135 * Math::DEG2RAD, 0, 0)));
	leverJoint->setMesh(new Sphere(.1, 8));
	leverJoint->getTransform()->name = "LeverJoint";

	lever = new GameObject(app);
	lever->setMesh(new Rectangle(.02, .1, .03));
	lever->getTransform()->setLocalPosition(Vector3(0, -.05, 0));
	lever->getTransform()->setParent(leverJoint->getTransform());
	lever->getTransform()->name = "Lever";

	//building the handle. 
		//it's a new gameobject 
	std::vector<Vector3> handleProfile;
	handleProfile.push_back(Vector3(0.9f, .95f, 0.0f));
	handleProfile.push_back(Vector3(0.55f, 0.95f, 0.0f));
	handleProfile.push_back(Vector3(0.45f, 0.775f, 0.0f));
	handleProfile.push_back(Vector3(0.3f, 0.6f, 0.0f));
	handleProfile.push_back(Vector3(0.2f, .325f, 0.0f));
	handleProfile.push_back(Vector3(0.1f, .1f, 0.0f));
	handleProfile.push_back(Vector3(0.775f, .1f, 0.0f));
	handleProfile.push_back(Vector3(0.65f, 0.275f, 0.0f));
	handleProfile.push_back(Vector3(0.65f, 0.45f, 0.0f));
	handleProfile.push_back(Vector3(0.775f, 0.65f, 0.0f));
	handleProfile.push_back(Vector3(0.85f, 0.7f, 0.0f));
	handleProfile.push_back(Vector3(0.9f, 0.7f, 0.0f));

	//creating the sweep path
	SweepPath handlesp;
	Transform t;

	t.setLocalPosition(Vector3(.11, .17, .07));//t.setLocalPosition(Vector3(.11, .2, .06));
	t.setLocalScale(Vector3(0, 0, 1.0)); // no need to scale the z-direction because the profile is in the XY plane
	t.setLocalRotation(Quaternion(Vector3(0, 3 * Math::PI / 2, 0)));
	handlesp.addTransform(t);
	handlesp.addTransform(t);
	t.setLocalPosition(Vector3(.11, -.3, -.2));//(.11, -.3, -.2));
	t.setLocalScale(Vector3(.6, .6, 1.));
	handlesp.addTransform(t);
	handlesp.addTransform(t);
	t.setLocalPosition(Vector3(.08, -.45, -.35));
	t.setLocalScale(Vector3(.8, .8, 1.0));
	handlesp.addTransform(t);
	t.setLocalPosition(Vector3(.05, -.55, -.55));
	t.setLocalScale(Vector3(1., 1., 1.0));
	handlesp.addTransform(t);
	//reverse
	t.setLocalPosition(Vector3(-.05, -.55, -.55));
	//t.setLocalScale(Vector3(1., 1., 1.0));
	handlesp.addTransform(t);
	t.setLocalPosition(Vector3(-.08, -.45, -.35));
	t.setLocalScale(Vector3(.8, .8, 1.0));
	handlesp.addTransform(t);
	t.setLocalPosition(Vector3(-.11, -.3, -.2));
	t.setLocalScale(Vector3(.6, .6, 1.0));
	handlesp.addTransform(t);
	handlesp.addTransform(t);

	t.setLocalPosition(Vector3(-.11, .17, .07));
	t.setLocalScale(Vector3(0, 0, 1.0)); // no need to scale the z-direction because the profile is in the XY plane
	handlesp.addTransform(t);
	handlesp.addTransform(t);

	nuHandle = new GameObject(app);
	nuHandle->setMesh(new Sweep(handleProfile, handlesp, true));
	nuHandle->getTransform()->setLocalPosition(Vector3(0, .3, .1));
	nuHandle->getTransform()->setParent(handleJoint->getTransform());
	nuHandle->getTransform()->name = "nuHandle";

	//target 
	targetStand = new GameObject(app);
	targetStand->setMesh(new Cylinder(.1, 1, 8));
	targetStand->getTransform()->setLocalPosition(Vector3(0, -1, 8));
	targetStand->getTransform()->setParent(getTransform());
	targetStand->getTransform()->name = "Target";

	targetJoint = new GameObject(app);
	targetJoint->setMesh(new Sphere(.1, 8));
	targetJoint->getTransform()->setParent(targetStand->getTransform());
	targetJoint->getTransform()->setLocalPosition(Vector3(0, 1, 0));
	targetJoint->getTransform()->setLocalRotation(Quaternion(Vector3(2 * Math::PI / 3, 0, 0)));
	targetJoint->getTransform()->name = "TargetJoint";

	target = new GameObject(app);
	target->setMesh(new Cylinder(1, .1, 8));
	target->getTransform()->setLocalPosition(Vector3(0, 0, -1));
	target->getTransform()->setParent(targetJoint->getTransform());
	target->getTransform()->name = "Target";
}


CompositeGun::~CompositeGun(void)
{

}
bool CompositeGun::init() {


	return true;
}