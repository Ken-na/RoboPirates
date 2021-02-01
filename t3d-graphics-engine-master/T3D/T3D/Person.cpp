#include "Cube.h"
#include "Cylinder.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Person.h"
#include "Sphere.h"
#include "Pyramid.h"

#include "Rectangle.h"
using namespace T3D;

Person::Person(T3DApplication *app) :GameObject(app) {

	

	//allows the gun to move independantly of the target. 
	body = new GameObject(app);
	body->setMesh(new Rectangle(2, 2, 1));
	body->getTransform()->setParent(getTransform());
	body->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	body->getTransform()->name = "Body";
	
	upperBody = new GameObject(app);
	upperBody->setMesh(new Rectangle(3.5, .5, 1.25));
	upperBody->getTransform()->setParent(body->getTransform());
	upperBody->getTransform()->setLocalPosition(Vector3(0, 2, 0));
	upperBody->getTransform()->name = "UpperBody";

	jNeckBody = new GameObject(app);
	jNeckBody->getTransform()->setParent(upperBody->getTransform());
	jNeckBody->getTransform()->setLocalPosition(Vector3(0, .5, 0));
	jNeckBody->getTransform()->name = "jNeckBody";

	neck = new GameObject(app);
	neck->setMesh(new Rectangle(.5, .5, .5));
	neck->getTransform()->setParent(jNeckBody->getTransform());
	neck->getTransform()->setLocalPosition(Vector3(0, .5, 0));
	neck->getTransform()->name = "Neck";

	jNeckHead = new GameObject(app);
	jNeckHead->getTransform()->setParent(neck->getTransform());
	jNeckHead->getTransform()->setLocalPosition(Vector3(0, .5, 0));
	jNeckHead->getTransform()->name = "jNeckHead";

	head = new GameObject(app);
	head->setMesh(new Rectangle(1, 1, 1));
	head->getTransform()->setParent(jNeckHead->getTransform());
	head->getTransform()->setLocalPosition(Vector3(0, 1, 0));
	head->getTransform()->name = "Head";

	jSpineBody = new GameObject(app);
	jSpineBody->getTransform()->setParent(body->getTransform());
	jSpineBody->getTransform()->setLocalPosition(Vector3(0, -2, 0));
	jSpineBody->getTransform()->name = "jSpineBody";

	spine = new GameObject(app);
	spine->setMesh(new Rectangle(.90, .90, .45));
	spine->getTransform()->setParent(jSpineBody->getTransform());
	spine->getTransform()->setLocalPosition(Vector3(0, -.5, 0));
	spine->getTransform()->name = "Spine";

	jSpinePelvis = new GameObject(app);
	jSpinePelvis->getTransform()->setParent(spine->getTransform());
	jSpinePelvis->getTransform()->setLocalPosition(Vector3(0, -1, 0));
	jSpinePelvis->getTransform()->name = "jSpinePelvis";

	pelvis = new GameObject(app);
	pelvis->setMesh(new Rectangle(2, 1, 1));
	pelvis->getTransform()->setParent(jSpinePelvis->getTransform());
	pelvis->getTransform()->setLocalPosition(Vector3(0, -1, 0));
	pelvis->getTransform()->name = "Pelvis";
	//right leg
	jPelvisRight = new GameObject(app);
	jPelvisRight->getTransform()->setParent(pelvis->getTransform());
	jPelvisRight->getTransform()->setLocalPosition(Vector3(-1, -1, 0));
	jPelvisRight->getTransform()->name = "jRightPelvis";

	rightUpLeg = new GameObject(app);
	rightUpLeg->setMesh(new Rectangle(.5, 1.5, .5));
	rightUpLeg->getTransform()->setParent(jPelvisRight->getTransform());
	rightUpLeg->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	rightUpLeg->getTransform()->name = "RightUpLeg";

	jRightKnee = new GameObject(app);
	jRightKnee->getTransform()->setParent(rightUpLeg->getTransform());
	jRightKnee->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	jRightKnee->getTransform()->name = "jRightKnee";

	rightBotLeg = new GameObject(app);
	rightBotLeg->setMesh(new Rectangle(.5, 1.5, .5));
	rightBotLeg->getTransform()->setParent(jRightKnee->getTransform());
	rightBotLeg->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	rightBotLeg->getTransform()->name = "RightBotLeg";

	jRightAnkle = new GameObject(app);
	jRightAnkle->getTransform()->setParent(rightBotLeg->getTransform());
	jRightAnkle->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	jRightAnkle->getTransform()->name = "jRightAnkle";

	rightFoot = new GameObject(app);
	rightFoot->setMesh(new Rectangle(.5, .25, 1.5));
	rightFoot->getTransform()->setParent(jRightAnkle->getTransform());
	rightFoot->getTransform()->setLocalPosition(Vector3(0, -.25, .75));
	rightFoot->getTransform()->name = "RightFoot";
	//left leg
	jPelvisLeft = new GameObject(app);
	jPelvisLeft->getTransform()->setParent(pelvis->getTransform());
	jPelvisLeft->getTransform()->setLocalPosition(Vector3(1, -1, 0));
	jPelvisLeft->getTransform()->name = "jLeftPelvis";

	leftUpLeg = new GameObject(app);
	leftUpLeg->setMesh(new Rectangle(.5, 1.5, .5));
	leftUpLeg->getTransform()->setParent(jPelvisLeft->getTransform());
	leftUpLeg->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	leftUpLeg->getTransform()->name = "LeftUpLeg";

	jLeftKnee = new GameObject(app);
	jLeftKnee->getTransform()->setParent(leftUpLeg->getTransform());
	jLeftKnee->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	jLeftKnee->getTransform()->name = "jLeftKnee";

	leftBotLeg = new GameObject(app);
	leftBotLeg->setMesh(new Rectangle(.5, 1.5, .5));
	leftBotLeg->getTransform()->setParent(jLeftKnee->getTransform());
	leftBotLeg->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	leftBotLeg->getTransform()->name = "LeftBotLeg";

	jLeftAnkle = new GameObject(app);
	jLeftAnkle->getTransform()->setParent(leftBotLeg->getTransform());
	jLeftAnkle->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	jLeftAnkle->getTransform()->name = "jLeftAnkle";

	leftFoot = new GameObject(app);
	leftFoot->setMesh(new Rectangle(.5, .25, 1.5));
	leftFoot->getTransform()->setParent(jLeftAnkle->getTransform());
	leftFoot->getTransform()->setLocalPosition(Vector3(0, -.25, .75));
	leftFoot->getTransform()->name = "LeftFoot";
	//right arm, the one that will hold the gun
	jRightShoulder = new GameObject(app);
	jRightShoulder->getTransform()->setParent(upperBody->getTransform());
	jRightShoulder->getTransform()->setLocalPosition(Vector3(-3, 0, 0)); //y was -.5
	jRightShoulder->getTransform()->name = "jRightShoulder";

	rightUpArm = new GameObject(app);
	rightUpArm->setMesh(new Rectangle(.5, 1.5, .5));
	rightUpArm->getTransform()->setParent(jRightShoulder->getTransform());
	rightUpArm->getTransform()->setLocalPosition(Vector3(0,-1.5, 0));
	rightUpArm->getTransform()->name = "LeftUpLeg";

	jRightElbow = new GameObject(app);
	jRightElbow->getTransform()->setParent(rightUpArm->getTransform());
	jRightElbow->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	jRightElbow->getTransform()->name = "jRightElbow";

	rightBotArm = new GameObject(app);
	rightBotArm->setMesh(new Rectangle(.5, 1.5, .5));
	rightBotArm->getTransform()->setParent(jRightElbow->getTransform());
	rightBotArm->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	rightBotArm->getTransform()->name = "RightBotLeg";

	jRightWrist = new GameObject(app);
	jRightWrist->getTransform()->setParent(rightBotArm->getTransform());
	jRightWrist->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	jRightWrist->getTransform()->name = "jRightWrist";

	rightHand = new GameObject(app);
	rightHand->setMesh(new Rectangle(.5, .75, .75));
	rightHand->getTransform()->setParent(jRightWrist->getTransform());
	rightHand->getTransform()->setLocalPosition(Vector3(0, -.75, 0));
	rightHand->getTransform()->name = "RightHand";
	//left arm, the one that will hold the gun
	jLeftShoulder = new GameObject(app);
	jLeftShoulder->setMesh(new Sphere(1,8));
	jLeftShoulder->getTransform()->setParent(upperBody->getTransform());
	jLeftShoulder->getTransform()->setLocalPosition(Vector3(3, 0, 0)); //y was -.5
	jLeftShoulder->getTransform()->name = "jLeftShoulder";

	leftUpArm = new GameObject(app);
	leftUpArm->setMesh(new Rectangle(.5, 1.5, .5));
	leftUpArm->getTransform()->setParent(jLeftShoulder->getTransform());
	leftUpArm->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	leftUpArm->getTransform()->name = "LeftUpLeg";

	jLeftElbow = new GameObject(app);
	jLeftElbow->getTransform()->setParent(leftUpArm->getTransform());
	jLeftElbow->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	jLeftElbow->getTransform()->name = "jLeftElbow";

	leftBotArm = new GameObject(app);
	leftBotArm->setMesh(new Rectangle(.5, 1.5, .5));
	leftBotArm->getTransform()->setParent(jLeftElbow->getTransform());
	leftBotArm->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	leftBotArm->getTransform()->name = "LeftBotLeg";

	jLeftWrist = new GameObject(app);
	jLeftWrist->getTransform()->setParent(leftBotArm->getTransform());
	jLeftWrist->getTransform()->setLocalPosition(Vector3(0, -1.5, 0));
	jLeftWrist->getTransform()->name = "jLeftWrist";

	leftHand = new GameObject(app);
	leftHand->setMesh(new Rectangle(.5, .75, .75));
	leftHand->getTransform()->setParent(jLeftWrist->getTransform());
	leftHand->getTransform()->setLocalPosition(Vector3(0, -.75, 0));
	leftHand->getTransform()->name = "LeftHand";

	std::vector<Vector3> hatProfile;

	hatProfile.push_back(Vector3(.4f, .7f, 0.0f));
	hatProfile.push_back(Vector3(.3f, .5f, 0.0f));
	hatProfile.push_back(Vector3(.2f, .3f, 0.0f));
	hatProfile.push_back(Vector3(.2f, .1f, 0.0f));
	hatProfile.push_back(Vector3(.4f, .1f, 0.0f));
	hatProfile.push_back(Vector3(.4f, .2f, 0.0f));
	hatProfile.push_back(Vector3(.8f, .2f, 0.0f));
	hatProfile.push_back(Vector3(.8f, .1f, 0.0f));
	hatProfile.push_back(Vector3(1.3f, .1f, 0.0f));
	hatProfile.push_back(Vector3(1.3f, .2f, 0.0f));
	hatProfile.push_back(Vector3(1.7f, .2f, 0.0f));
	hatProfile.push_back(Vector3(1.7f, .1f, 0.0f));
	hatProfile.push_back(Vector3(1.9f, .1f, 0.0f));
	hatProfile.push_back(Vector3(1.9f, .3f, 0.0f));
	hatProfile.push_back(Vector3(1.8f, .5f, 0.0f));
	hatProfile.push_back(Vector3(1.7f, .7f, 0.0f));
	hatProfile.push_back(Vector3(1.4f, 1.f, 0.0f));
	hatProfile.push_back(Vector3(0.7f, 1.f, 0.0f));

	
	SweepPath hatsp;
	Transform t;

	t.setLocalPosition(Vector3(.23, .8, 1));//t.setLocalPosition(Vector3(.2, .2, 0));
	t.setLocalScale(Vector3(0, 0, 1.0)); // no need to scale the z-direction because the profile is in the XY plane
	t.setLocalRotation(Quaternion(Vector3(0, 3 * Math::PI / 2, 0)));
	hatsp.addTransform(t);
	hatsp.addTransform(t);
	t.setLocalPosition(Vector3(.23, 0, .05));//(.11, -.3, -.2));
	t.setLocalScale(Vector3(.95, .95, 1.));
	hatsp.addTransform(t);
	hatsp.addTransform(t);

	t.setLocalPosition(Vector3(.22, 0, 0));//(.11, -.3, -.2));
	t.setLocalScale(Vector3(1, 1, 1.));
	hatsp.addTransform(t);
	hatsp.addTransform(t);

	t.setLocalPosition(Vector3(.12, 0, 0));//t.setLocalPosition(Vector3(-.2, -.50, 0));
	t.setLocalScale(Vector3(1., .9, 1.0));
	hatsp.addTransform(t);

	t.setLocalPosition(Vector3(.07, 0.025, 0));//t.setLocalPosition(Vector3(-.2, -.50, 0));
	t.setLocalScale(Vector3(1., .5, 1.0));
	hatsp.addTransform(t);

	t.setLocalPosition(Vector3(0.02, 0.025, 0));//t.setLocalPosition(Vector3(-.2, -.50, 0));
	t.setLocalScale(Vector3(1., .55, 1.0));
	hatsp.addTransform(t);

	//reverse
	t.setLocalPosition(Vector3(-0.02, 0.025, 0));//t.setLocalPosition(Vector3(-.2, -.50, 0));
	t.setLocalScale(Vector3(1., .55, 1.0));
	hatsp.addTransform(t);

	t.setLocalPosition(Vector3(-.07, 0.025, 0));//t.setLocalPosition(Vector3(-.2, -.50, 0));
	t.setLocalScale(Vector3(1., .5, 1.0));
	hatsp.addTransform(t);

	t.setLocalPosition(Vector3(-.12, 0, 0));//t.setLocalPosition(Vector3(-.2, -.50, 0));
	t.setLocalScale(Vector3(1., .9, 1.0));
	hatsp.addTransform(t);

	t.setLocalPosition(Vector3(-.22, 0, 0));//(.11, -.3, -.2));
	t.setLocalScale(Vector3(1, 1, 1.));
	hatsp.addTransform(t);
	hatsp.addTransform(t);

	t.setLocalPosition(Vector3(-.23, 0, .05));//(.11, -.3, -.2));
	t.setLocalScale(Vector3(.95, .95, 1.));
	hatsp.addTransform(t);
	hatsp.addTransform(t);

	t.setLocalPosition(Vector3(-.23, .8, 1));//t.setLocalPosition(Vector3(.2, .2, 0));
	t.setLocalScale(Vector3(0, 0, 1.0)); // no need to scale the z-direction because the profile is in the XY plane
	t.setLocalRotation(Quaternion(Vector3(0, 3 * Math::PI / 2, 0)));
	hatsp.addTransform(t);
	hatsp.addTransform(t);

	hat = new GameObject(app);
	hat->setMesh(new Sweep(hatProfile, hatsp, true));
	hat->getTransform()->setLocalPosition(Vector3(-6, -1.7, 0)); 
	hat->getTransform()->setLocalScale(Vector3(6, 6, 6)); //honestly 555 would probably work better but 666 is here for the meme 
	hat->getTransform()->setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, Math::PI / 11)));
	hat->getTransform()->setParent(head->getTransform());
	hat->getTransform()->name = "Hat";

	//gun	
	gun = new CompositeGun(app);
	gun->handleJoint->getTransform()->setParent(rightHand->getTransform());
	gun->handleJoint->getTransform()->setLocalScale(Vector3(2, 2, 2));
	gun->handleJoint->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	gun->handleJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	gun->getTransform()->name = "Gun";

	sphere = new GameObject(app);
	sphere->setMesh(new Sphere(.5, 32));
	sphere->getTransform()->setParent(jRightElbow->getTransform());
}


Person::~Person(void)
{

}
bool Person::init() {


	return true;
}