#include "Bullet.h"
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

Bullet::Bullet(T3DApplication *app) :GameObject(app) {
	//make Bulletbullet
	std::vector<Vector3> bulletProfile;

	bulletProfile.push_back(Vector3(0.0f, -0.02f, 0.0f));
	bulletProfile.push_back(Vector3(0.01f, -0.01f, 0.0f));
	bulletProfile.push_back(Vector3(0.03f, 0.02f, 0.0f));
	bulletProfile.push_back(Vector3(0.05f, 0.04f, 0.0f));
	bulletProfile.push_back(Vector3(0.05f, 0.06f, 0.0f));
	bulletProfile.push_back(Vector3(0.04f, 0.06f, 0.0f));
	bulletProfile.push_back(Vector3(0.04f, 0.04f, 0.0f));
	bulletProfile.push_back(Vector3(0.02f, 0.02f, 0.0f));
	bulletProfile.push_back(Vector3(-.05f, 0.02f, 0.0f)); //changed to -.05 from 0 as to close te gap.

	SweepPath sweepsp;
	Transform t2;
	sweepsp.makeCirclePath(.05, 7);


	bullet = new GameObject(app);
	bullet->setMesh(new Sweep(bulletProfile, sweepsp, true));
	bullet->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	
	bullet->getTransform()->name = "bullet";

}


Bullet::~Bullet(void)
{

}
bool Bullet::init() {


	return true;
}