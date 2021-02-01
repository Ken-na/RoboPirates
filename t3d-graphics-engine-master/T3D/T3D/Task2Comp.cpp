#include "Task2Comp.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Material.h"
#include "Cylinder.h"

#include "Sphere.h"
#include "Rectangle.h"
//#include "Oar.h"

using namespace T3D;

Task2Comp::Task2Comp(T3DApplication *app) :GameObject(app) {

	std::vector<Vector3> boatProfile;


	boatProfile.push_back(Vector3(-3.5f, 7.5f, 0.0f));
	boatProfile.push_back(Vector3(-5.5f, 6.f, 0.0f));
	boatProfile.push_back(Vector3(-6.5f, 4.25f, 0.0f));
	boatProfile.push_back(Vector3(-7.5f, 2.f, 0.0f));
	boatProfile.push_back(Vector3(-5.5f, -1.f, 0.0f));
	boatProfile.push_back(Vector3(-2.75f, -2.f, 0.0f));
	boatProfile.push_back(Vector3(0.f, -2.f, 0.0f));
	boatProfile.push_back(Vector3(1.25f, -2.25f, 0.0f));
	boatProfile.push_back(Vector3(4.f, -1.f, 0.0f));
	boatProfile.push_back(Vector3(6.f, 2.f, 0.0f));
	boatProfile.push_back(Vector3(5.f, 4.25f, 0.0f));
	boatProfile.push_back(Vector3(4.f, 6.f, 0.0f));
	boatProfile.push_back(Vector3(2.f, 7.5f, 0.0f));
	boatProfile.push_back(Vector3(1.25f, 6.f, 0.0f));
	boatProfile.push_back(Vector3(-1.25f, 4.f, 0.0f));
	boatProfile.push_back(Vector3(-2.75f, 6.f, 0.0f));

	//creating the sweep path
	SweepPath boatsp;
	Transform t;

	//cap
	t.setLocalPosition(Vector3(-10.1, 10.1, 0));
	t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
	t.setLocalScale(Vector3(0, 0, 1.0));
	boatsp.addTransform(t);
	//tip of right side
	t.setLocalPosition(Vector3(-10, 10, 0));
	t.setLocalScale(Vector3(.01, .01, 1));// (i / 30), 1.0));
	boatsp.addTransform(t);
	//boatsp.addTransform(t);
	//post shrink
	t.setLocalPosition(Vector3(-5, 7.5, 0));
	t.setLocalScale(Vector3(.25, .25, .25));
	boatsp.addTransform(t);
	t.setLocalPosition(Vector3(0, 5, 0));
	t.setLocalScale(Vector3(.5, .5, .5));
	boatsp.addTransform(t);
	t.setLocalPosition(Vector3(10, 0, 0));
	t.setLocalScale(Vector3(1, 1, 1.0));
	boatsp.addTransform(t);
	//budlge
	t.setLocalPosition(Vector3(25, -2, 0));
	t.setLocalScale(Vector3(1.2, 1.2, 1.0));
	boatsp.addTransform(t);
	//pre shrink
	t.setLocalPosition(Vector3(40, 0, 0));
	t.setLocalScale(Vector3(1, 1, 1.0));
	boatsp.addTransform(t);
	t.setLocalPosition(Vector3(50, 5, 0));
	t.setLocalScale(Vector3(.5, .5, .5));
	boatsp.addTransform(t);
	t.setLocalPosition(Vector3(55, 7.5, 0));
	t.setLocalScale(Vector3(.25, .25, .25));
	boatsp.addTransform(t);
	//tip of left side
	t.setLocalPosition(Vector3(60, 10, 0)); //x from .01
	t.setLocalScale(Vector3(.01, .01, 1.0));
	boatsp.addTransform(t);
	//boatsp.addTransform(t);
	//cap
	t.setLocalPosition(Vector3(60.1, 10.1, 0)); //x from .01
	t.setLocalScale(Vector3(0, 0, 1)); //was 0,0,1
	boatsp.addTransform(t);


	//2.
	boat = new GameObject(app);
	boat->setMesh(new Sweep(boatProfile, boatsp, false));
	boat->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
	boat->getTransform()->setParent(getTransform());
	boat->getTransform()->name = "BoatWithOars";

	oarJoint1 = new GameObject(app);
	//oarJoint1->setMesh(new Sphere(1, 8));
	oarJoint1->getTransform()->setParent(boat->getTransform());
	oarJoint1->getTransform()->setLocalPosition(Vector3(15, 8, 5));
	oarJoint1->getTransform()->setLocalRotation(Quaternion(Vector3(3 * Math::PI / 2, 0, 0)));
	oarJoint1->getTransform()->name = "OarJoint1";

	oar1 = new GameObject(app);
	oar1->setMesh(new Cylinder(.2, 10,5));
	oar1->getTransform()->setParent(oarJoint1->getTransform());
	oar1->getTransform()->setLocalPosition(Vector3(0,-8,0));

	oarTip1 = new GameObject(app);
	oarTip1->setMesh(new Rectangle(.2, .8, .4));
	oarTip1->getTransform()->setParent(oar1->getTransform());
	oarTip1->getTransform()->setLocalPosition(Vector3(0, -10, 0));

	oarJoint2 = new GameObject(app);
	oarJoint2->getTransform()->setParent(boat->getTransform());
	oarJoint2->getTransform()->setLocalPosition(Vector3(15, 8, -5));
	oarJoint2->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	oarJoint2->getTransform()->name = "OarJoint2";

	oar2 = new GameObject(app);
	oar2->setMesh(new Cylinder(.2, 10, 5));
	oar2->getTransform()->setParent(oarJoint2->getTransform());
	oar2->getTransform()->setLocalPosition(Vector3(0, -8, 0));

	oarTip2 = new GameObject(app);
	oarTip2->setMesh(new Rectangle(.2, .8, .4));
	oarTip2->getTransform()->setParent(oar2->getTransform());
	oarTip2->getTransform()->setLocalPosition(Vector3(0, -10, 0));

	//Back two
	oarJoint3 = new GameObject(app);
	oarJoint3->getTransform()->setParent(boat->getTransform());
	oarJoint3->getTransform()->setLocalPosition(Vector3(30, 8, 5));
	oarJoint3->getTransform()->setLocalRotation(Quaternion(Vector3(3 * Math::PI / 2, 0, 0)));
	oarJoint3->getTransform()->name = "OarJoint3";

	oar3 = new GameObject(app);
	oar3->setMesh(new Cylinder(.2, 10, 5));
	oar3->getTransform()->setParent(oarJoint3->getTransform());
	oar3->getTransform()->setLocalPosition(Vector3(0, -8, 0));

	oarTip3 = new GameObject(app);
	oarTip3->setMesh(new Rectangle(.2, .8, .4));
	oarTip3->getTransform()->setParent(oar3->getTransform());
	oarTip3->getTransform()->setLocalPosition(Vector3(0, -10, 0));/**/

	oarJoint4 = new GameObject(app);
	oarJoint4->getTransform()->setParent(boat->getTransform());
	oarJoint4->getTransform()->setLocalPosition(Vector3(30, 8, -5));
	oarJoint4->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	oarJoint4->getTransform()->name = "OarJoint4";

	oar4 = new GameObject(app);
	oar4->setMesh(new Cylinder(.2, 10, 5));
	oar4->getTransform()->setParent(oarJoint4->getTransform());
	oar4->getTransform()->setLocalPosition(Vector3(0, -8, 0));

	oarTip4 = new GameObject(app);
	oarTip4->setMesh(new Rectangle(.2, .8, .4));
	oarTip4->getTransform()->setParent(oar4->getTransform());
	oarTip4->getTransform()->setLocalPosition(Vector3(0, -10, 0));


}


Task2Comp::~Task2Comp(void)
{

}
bool Task2Comp::init() {


	return true;
}