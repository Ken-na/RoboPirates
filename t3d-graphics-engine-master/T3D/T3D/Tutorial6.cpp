#include "Tutorial6.h"
#include "Camera.h"
#include "Material.h"

#include "TCube.h"
#include "TCylinder.h"

#include "Pyramid.h"
#include "Cylinder.h"
#include "KeyboardController.h"
#include "Lamp.h"
#include "Sphere.h"

using namespace T3D;

Tutorial6::Tutorial6(void)
{
	//drawArea = new Texture(1025, 650, false);
	//drawArea->clear(Colour(255, 255, 255, 255));
}


Tutorial6::~Tutorial6(void)
{





}


bool Tutorial6::init() {

	WinGLApplication::init();

	GameObject *lightObj = new GameObject(this);
	Light *light = new Light(Light::DIRECTIONAL);
	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);
	lightObj->getTransform()->setLocalRotation(Quaternion(Vector3(7 * Math::PI / 4, 7 * Math::PI / 4, 0)));
	

	GameObject *camObj = new GameObject(this);
	renderer->camera = new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0, 0.5, 3));
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());

	Material *fixedGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
	fixedGreen->setDiffuse(0.0, 0.6, 0, 1);
	fixedGreen->setShininess(20);

	/*Texture *cratetex = new Texture("Resources/crate013jc.jpg", true, true);
	renderer->loadTexture(cratetex);
	Material *cratemat = renderer->createMaterial(Renderer::PR_OPAQUE);
	cratemat->setTexture(cratetex);*/

	Texture *barreltex = new Texture("Resources/ExplosiveBarrel.jpg", true, true);
	renderer->loadTexture(barreltex);
	Material *barrelmat = renderer->createMaterial(Renderer::PR_OPAQUE);
	barrelmat->setTexture(barreltex);

	/*GameObject *cube = new GameObject(this);
	cube->setMesh(new TCube(2));
	cube->setMaterial(cratemat);
	cube->getTransform()->setLocalPosition(Vector3(10, 1, 1));
	cube->getTransform()->setParent(root);
	cube->getTransform()->name = "Cube";*/

	GameObject *cyl = new GameObject(this);
	cyl->setMesh(new TCylinder(1,2,8));
	cyl->setMaterial(barrelmat);
	cyl->getTransform()->setLocalPosition(Vector3(5, 1, 1));
	cyl->getTransform()->setParent(root);
	cyl->getTransform()->name = "Cyl";

	return true;
}