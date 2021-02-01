#include "Cube.h"
#include "Cylinder.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Target.h"
#include "Sphere.h"
#include "Pyramid.h"

#include "Rectangle.h"
using namespace T3D;

Target::Target(T3DApplication *app) :GameObject(app) {
	//target 
	

	targetStand = new GameObject(app);
	targetStand->setMesh(new Cylinder(.1, 20, 8));
	targetStand->getTransform()->setLocalPosition(Vector3(0, -20, 0));
	targetStand->getTransform()->setParent(getTransform());
	targetStand->getTransform()->name = "Target";

	targetJoint = new GameObject(app);
	targetJoint->setMesh(new Sphere(.1, 8));
	targetJoint->getTransform()->setParent(targetStand->getTransform());
	targetJoint->getTransform()->setLocalPosition(Vector3(0, 20, 0));
	//targetJoint->getTransform()->setLocalRotation(Quaternion(Vector3(2 * Math::PI / 3, 0, 0)));
	targetJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	targetJoint->getTransform()->name = "TargetJoint";

	target = new GameObject(app);
	target->setMesh(new Cylinder(1.5, .1, 8));
	target->getTransform()->setLocalPosition(Vector3(0, 0, -1));
	target->getTransform()->setParent(targetJoint->getTransform());
	target->getTransform()->name = "Target";
	innerTarget = new GameObject(app);
	innerTarget->setMesh(new Cylinder(1., .13, 8));
	innerTarget->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	innerTarget->getTransform()->setParent(target->getTransform());
	innerTarget->getTransform()->name = "InnerTarget";
	inner2Target = new GameObject(app);
	inner2Target->setMesh(new Cylinder(.5, .15, 8));
	inner2Target->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	inner2Target->getTransform()->setParent(target->getTransform());
	inner2Target->getTransform()->name = "Inner2Target";

	Light *light = new Light(Light::AMBIENT);
	GameObject *lightObj = new GameObject(app);
	lightObj->getTransform()->setParent(target->getTransform());
	lightObj->getTransform()->setLocalPosition(Vector3(0, -.3, 0));
	light->setAmbient(.12, .12, .12);
	light->setDiffuse(.12, .12, .12);
	light->setSpecular(.12, .12, .12);
	lightObj->setLight(light);
}


Target::~Target(void)
{

}
bool Target::init() {


	return true;
}