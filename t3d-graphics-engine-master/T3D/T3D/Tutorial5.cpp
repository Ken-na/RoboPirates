#include "Tutorial5.h"
#include "Camera.h"
#include "Material.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "KeyboardController.h"
#include "Lamp.h"
#include "Sphere.h"

using namespace T3D;

Tutorial5::Tutorial5(void)
{
	//drawArea = new Texture(1025, 650, false);
	//drawArea->clear(Colour(255, 255, 255, 255));
}


Tutorial5::~Tutorial5(void)
{

	



}


bool Tutorial5::init() {
	
	WinGLApplication::init();

	GameObject *lightObj = new GameObject(this);
	Light *light = new Light(Light::DIRECTIONAL);
	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);

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

	Material *gouraudGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
	gouraudGreen->setDiffuse(0.0, 0.6, 0, 1);
	gouraudGreen->setShininess(20);

	GLShader *gouraudShader = new GLShader("Resources/vspecular.shader", "Resources/frag.shader");
	gouraudShader->compileShader();
	gouraudGreen->setShader(gouraudShader);

	Material *phongGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
	phongGreen->setDiffuse(0.0, 0.6, 0, 1);
	phongGreen->setShininess(20);

	GLShader *phongShader = new GLShader("Resources/phongVert.shader", "Resources/phongFrag.shader");
	phongShader->compileShader();
	phongGreen->setShader(phongShader);

	sphere1 = new GameObject(this);
	sphere1->setMesh(new Sphere(1, 32));
	sphere1->setMaterial(fixedGreen);
	sphere1->getTransform()->setLocalPosition(Vector3(3, 0, 0));
	sphere1->getTransform()->setParent(root);
	sphere1->getTransform()->name = "Sphere1";

	sphere2 = new GameObject(this);
	sphere2->setMesh(new Sphere(1, 32));
	sphere2->setMaterial(gouraudGreen);
	sphere2->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	sphere2->getTransform()->setParent(root);
	sphere2->getTransform()->name = "Sphere2";

	sphere3 = new GameObject(this);
	sphere3->setMesh(new Sphere(1, 32));
	sphere3->setMaterial(phongGreen);
	sphere3->getTransform()->setLocalPosition(Vector3(-3, 0, 0));
	sphere3->getTransform()->setParent(root);
	sphere3->getTransform()->name = "Sphere3";
	return true;
}