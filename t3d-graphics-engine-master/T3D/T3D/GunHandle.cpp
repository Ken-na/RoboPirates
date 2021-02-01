#include "Cube.h"
#include "Cylinder.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "GunHandle.h"
#include "Sphere.h"

#include "Rectangle.h"
using namespace T3D;

GunHandle::GunHandle(T3DApplication *app) :GameObject(app) {
	//add the following code to the constructor
	std::vector<Vector3> handleProfile;
	handleProfile.push_back(Vector3(0.0f, -0.12f, 0.0f));
	handleProfile.push_back(Vector3(0.014f, -0.114f, 0.0f));
	handleProfile.push_back(Vector3(0.02f, -0.1f, 0.0f));
	handleProfile.push_back(Vector3(0.02f, 0.1f, 0.0f));
	handleProfile.push_back(Vector3(0.014f, 0.114f, 0.0f));
	handleProfile.push_back(Vector3(0.0f, 0.12f, 0.0f));
	handleProfile.push_back(Vector3(-0.014f, 0.114f, 0.0f));
	handleProfile.push_back(Vector3(-0.02f, 0.1f, 0.0f));
	handleProfile.push_back(Vector3(-0.02f, -0.1f, 0.0f));
	handleProfile.push_back(Vector3(-0.014f, -0.114f, 0.0f));

	//creating the sweep path
	SweepPath handlesp;
	Transform t;

	t.setLocalPosition(Vector3(-0.01, 0, 0));
	t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
	t.setLocalScale(Vector3(0, 0, 1.0)); // no need to scale the z-direction because the profile is in the XY plane
	handlesp.addTransform(t);
	handlesp.addTransform(t);
	t.setLocalScale(Vector3(0.9, 1, 1.0));
	handlesp.addTransform(t);
	handlesp.addTransform(t);
	t.setLocalPosition(Vector3(-0.0075, 0, 0));
	t.setLocalScale(Vector3(1, 1, 1.0));
	handlesp.addTransform(t);
	handlesp.addTransform(t);
	t.setLocalPosition(Vector3(0.0075, 0, 0));
	handlesp.addTransform(t);
	handlesp.addTransform(t);
	t.setLocalPosition(Vector3(0.01, 0, 0));
	t.setLocalScale(Vector3(0.9, 1, 1.0));
	handlesp.addTransform(t);
	handlesp.addTransform(t);
	t.setLocalScale(Vector3(0, 0, 1.0));
	handlesp.addTransform(t);
	handlesp.addTransform(t);
	
}


GunHandle::~GunHandle(void)
{

}
bool GunHandle::init() {


	return true;
}