#include "Lamp.h"
#include "Camera.h"
#include "Material.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "KeyboardController.h"
#include "SweepPath.h"
#include "Sweep.h"
//#include "Renderer.h"

using namespace T3D;

Lamp::Lamp(T3DApplication *app):GameObject(app) {
	//this will create a cylinder that is 20cm across and 2cm thick
	setMesh(new Cylinder(.1, .01, 16));
	getTransform()->name = "Lamp";

	base = new GameObject(app); // note the use of 'app' not 'this' - you should understand why
	base->setMesh(new Cylinder(.02, .01, 16));
	base->getTransform()->setParent(getTransform()); // attaching this piece to the Lamp object's transform
	base->getTransform()->setLocalPosition(Vector3(0, .02, 0));
	base->getTransform()->name = "Base";

	//add the following code to the constructor
	std::vector<Vector3> armProfile;
	armProfile.push_back(Vector3(0.0f, -0.12f, 0.0f));
	armProfile.push_back(Vector3(0.014f, -0.114f, 0.0f));
	armProfile.push_back(Vector3(0.02f, -0.1f, 0.0f));
	armProfile.push_back(Vector3(0.02f, 0.1f, 0.0f));
	armProfile.push_back(Vector3(0.014f, 0.114f, 0.0f));
	armProfile.push_back(Vector3(0.0f, 0.12f, 0.0f));
	armProfile.push_back(Vector3(-0.014f, 0.114f, 0.0f));
	armProfile.push_back(Vector3(-0.02f, 0.1f, 0.0f));
	armProfile.push_back(Vector3(-0.02f, -0.1f, 0.0f));
	armProfile.push_back(Vector3(-0.014f, -0.114f, 0.0f));

	//creating the sweep path
	SweepPath armsp;
	Transform t;

	t.setLocalPosition(Vector3(-0.01, 0, 0));
	t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
	t.setLocalScale(Vector3(0, 0, 1.0)); // no need to scale the z-direction because the profile is in the XY plane
	armsp.addTransform(t);
	armsp.addTransform(t);
	t.setLocalScale(Vector3(0.9, 1, 1.0));
	armsp.addTransform(t);
	armsp.addTransform(t);
	t.setLocalPosition(Vector3(-0.0075, 0, 0));
	t.setLocalScale(Vector3(1, 1, 1.0));
	armsp.addTransform(t);
	armsp.addTransform(t);
	t.setLocalPosition(Vector3(0.0075, 0, 0));
	armsp.addTransform(t);
	armsp.addTransform(t);
	t.setLocalPosition(Vector3(0.01, 0, 0));
	t.setLocalScale(Vector3(0.9, 1, 1.0));
	armsp.addTransform(t);
	armsp.addTransform(t);
	t.setLocalScale(Vector3(0, 0, 1.0));
	armsp.addTransform(t);
	armsp.addTransform(t);
	/*arm1 = new GameObject(app);
	arm1->setMesh(new Sweep(armProfile, armsp, false));
	arm1->getTransform()->setLocalPosition(Vector3(0, 0.1, 0)); // not correctly positioned yet
	arm1->getTransform()->setParent(base->getTransform()); // not correct attachment yet
	arm1->getTransform()->name = "Arm1";*/

	//add the following code to create the joints
	baseJoint = new GameObject(app);
	baseJoint->getTransform()->setParent(base->getTransform());
	baseJoint->getTransform()->name = "BaseJoint";

	elbowJoint = new GameObject(app);
	elbowJoint->getTransform()->setLocalPosition(Vector3(0, 0.2, 0));
	elbowJoint->getTransform()->setParent(baseJoint->getTransform());
	elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0))); // this rotation is just to make a good starting pose
	elbowJoint->getTransform()->name = "ElbowJoint";

	shadeJoint = new GameObject(app);
	shadeJoint->getTransform()->setLocalPosition(Vector3(0, 0.2, 0));
	shadeJoint->getTransform()->setParent(elbowJoint->getTransform());
	shadeJoint->getTransform()->name = "ShadeJoint";

	//2.
	arm1 = new GameObject(app);
	arm1->setMesh(new Sweep(armProfile, armsp, false));
	arm1->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
	arm1->getTransform()->setParent(baseJoint->getTransform());
	arm1->getTransform()->name = "Arm1";

	arm2 = new GameObject(app);
	arm2->setMesh(new Sweep(armProfile, armsp, false));
	arm2->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
	arm2->getTransform()->setParent(elbowJoint->getTransform());
	arm2->getTransform()->name = "Arm2";

	//make lampshade
	std::vector<Vector3> shadeProfile;
	
	shadeProfile.push_back(Vector3(0.0f, -0.02f, 0.0f));	
	shadeProfile.push_back(Vector3(0.01f, -0.01f, 0.0f));	
	shadeProfile.push_back(Vector3(0.03f, 0.02f, 0.0f));	
	shadeProfile.push_back(Vector3(0.05f, 0.04f, 0.0f));	
	shadeProfile.push_back(Vector3(0.05f, 0.06f, 0.0f));	
	shadeProfile.push_back(Vector3(0.04f, 0.06f, 0.0f));	
	shadeProfile.push_back(Vector3(0.04f, 0.04f, 0.0f));	
	shadeProfile.push_back(Vector3(0.02f, 0.02f, 0.0f));
	shadeProfile.push_back(Vector3(-.05f, 0.02f, 0.0f)); //changed to -.05 from 0 as to close te gap.

	SweepPath sweepsp;
	Transform t2;
	
	//got to figure out how to transform it.
	/*t2.setLocalPosition(Vector3(-0.01, 0, 0));
	t2.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
	t2.setLocalScale(Vector3(0, 0, 1.0)); // no need to scale the z-direction because the profile is in the XY plane
	sweepsp.addTransform(t2);
	sweepsp.addTransform(t2);
	t2.setLocalScale(Vector3(0.9, 1, 1.0));
	sweepsp.addTransform(t2);
	sweepsp.addTransform(t2);
	t2.setLocalPosition(Vector3(-0.0075, 0, 0));
	t2.setLocalScale(Vector3(1, 1, 1.0));
	sweepsp.addTransform(t2);
	sweepsp.addTransform(t2);
	t2.setLocalPosition(Vector3(0.0075, 0, 0));
	sweepsp.addTransform(t2);
	sweepsp.addTransform(t2);
	t2.setLocalPosition(Vector3(0.01, 0, 0));
	t2.setLocalScale(Vector3(0.9, 1, 1.0));
	sweepsp.addTransform(t2);
	sweepsp.addTransform(t2);
	t2.setLocalScale(Vector3(0, 0, 1.0));
	sweepsp.addTransform(t2);
	sweepsp.addTransform(t2);
	/**/
	//t2.setLocalRotation(Quaternion(Vector3(0, Math::PI, 0)));
	//sweepsp.addTransform(t2);
	sweepsp.makeCirclePath(.05,7);


	shade = new GameObject(app);
	shade->setMesh(new Sweep(shadeProfile, sweepsp, true));
	shade->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	//shade->getro
	shade->getTransform()->setParent(shadeJoint->getTransform());
	shade->getTransform()->name = "Shade";

}


Lamp::~Lamp(void)
{

}
bool Lamp::init() {
	

	return true;
}