#include "Task1Sweep.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Material.h"
#include "Cylinder.h"

using namespace T3D;

Task1Sweep::Task1Sweep(T3DApplication *app) :GameObject(app) {
	
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
	t.setLocalPosition(Vector3(-10, 10 , 0));
	t.setLocalScale(Vector3(.01, .01, 1));// (i / 30), 1.0));
	//boatsp.addTransform(t);
	boatsp.addTransform(t);	
		//post shrink
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
		//tip of left side
	t.setLocalPosition(Vector3(60, 10, 0)); //x from .01
	t.setLocalScale(Vector3(.01, .01, 1.0));
	//boatsp.addTransform(t);
	boatsp.addTransform(t);
		//cap
	t.setLocalPosition(Vector3(60.1, 10.1, 0)); //x from .01
	t.setLocalScale(Vector3(0, 0, 1)); //was 0,0,1
	boatsp.addTransform(t);
	

	//2.
	boat = new GameObject(app);
	boat->setMesh(new Sweep(boatProfile, boatsp, false));
	boat->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
	boat->getTransform()->setParent(getTransform());
	boat->getTransform()->name = "Boat";

}


Task1Sweep::~Task1Sweep(void)
{

}
bool Task1Sweep::init() {


	return true;
}