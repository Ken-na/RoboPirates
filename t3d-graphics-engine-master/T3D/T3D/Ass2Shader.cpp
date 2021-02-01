#include "Ass2Shader.h"
#include "Camera.h"
#include "Material.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "KeyboardController.h"
#include "Lamp.h"
#include "Sphere.h"

#include "HouseBoat.h"

using namespace T3D;

Ass2Shader::Ass2Shader(void)
{
	//drawArea = new Texture(1025, 650, false);
	//drawArea->clear(Colour(255, 255, 255, 255));
}


Ass2Shader::~Ass2Shader(void)
{





}


bool Ass2Shader::init() {

	WinGLApplication::init();

	GameObject *lightObj = new GameObject(this);
	Light *light = new Light(Light::DIRECTIONAL);
	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);
	lightObj->getTransform()->setLocalRotation(Vector3(-45 * Math::DEG2RAD, -45 * Math::DEG2RAD, -45 * Math::DEG2RAD));

	GameObject *camObj = new GameObject(this);
	renderer->camera = new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0, 0.5, 3));
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());

	Material *mountBrown = renderer->createMaterial(Renderer::PR_OPAQUE);
	mountBrown->setDiffuse(0.6, 0.6, 0, 1);
	mountBrown->setShininess(20);

	Material *houseC = renderer->createMaterial(Renderer::PR_OPAQUE);
	houseC->setDiffuse(0.6, 0, 0, 1);


	//GLShader *snowShader = new GLShader("Resources/snowVert.shader", "Resources/snowFrag.shader");
	GLShader *snowShader = new GLShader("Resources/snow2Vert.shader", "Resources/snow2Frag.shader");
	snowShader->compileShader();
	mountBrown->setShader(snowShader);

	mount1 = new GameObject(this);
	mount1->setMesh(new Pyramid(4));
	mount1->setMaterial(mountBrown);
	mount1->getTransform()->setLocalPosition(Vector3(-7, 4, -2));
	mount1->getTransform()->setParent(root);
	mount1->getTransform()->name = "Mount1";
	mount1->getTransform()->setLocalRotation(Vector3(0, -45 * Math::DEG2RAD, 0));

	mount2 = new GameObject(this);
	mount2->setMesh(new Pyramid(5));
	mount2->setMaterial(mountBrown);
	mount2->getTransform()->setLocalPosition(Vector3(0, 5, -2.5));
	mount2->getTransform()->setParent(root);
	mount2->getTransform()->name = "Mount1";
	mount2->getTransform()->setLocalRotation(Vector3(0, 10 * Math::DEG2RAD, 0));

	mount3 = new GameObject(this);
	mount3->setMesh(new Pyramid(7));
	mount3->setMaterial(mountBrown);
	mount3->getTransform()->setLocalPosition(Vector3(-10, 7, -12));
	mount3->getTransform()->setParent(root);
	mount3->getTransform()->name = "Mount1";
	mount3->getTransform()->setLocalRotation(Vector3(0, 20 * Math::DEG2RAD, 0));

	Texture *boattex = new Texture("Resources/HouseBoatTexture.jpg", true, true);
	renderer->loadTexture(boattex);
	Material *boatmat = renderer->createMaterial(Renderer::PR_OPAQUE);
	boatmat->setTexture(boattex);

	GameObject *boat = new GameObject(this);
	boat->getTransform()->setParent(root);
	boat->setMesh(new HouseBoat(2));
	boat->setMaterial(boatmat);
	boat->getTransform()->setLocalPosition(Vector3(30, 2, 2));
	boat->getTransform()->setLocalRotation(Vector3(0, 180 * Math::DEG2RAD, 0));
	boat->getTransform()->name = "Boat";

	GameObject *boat2 = new GameObject(this);
	boat2->getTransform()->setParent(root);
	boat2->setMesh(new HouseBoat(2));
	boat2->setMaterial(boatmat);
	boat2->getTransform()->setLocalPosition(Vector3(40, 2, 20));
	boat2->getTransform()->setLocalRotation(Vector3(0, 180 * Math::DEG2RAD, 0));
	boat2->getTransform()->name = "Boat2";

	Animation *anim = new Animation(20.0);
	boat->addComponent(anim);
	anim->addKey("Boat", 0, Quaternion(Vector3(0, 180 * Math::DEG2RAD, 0)), boat->getTransform()->getLocalPosition());
	anim->addKey("Boat", 10, Quaternion(Vector3(0, 0 * Math::DEG2RAD, 0)), boat->getTransform()->getLocalPosition());
	anim->addKey("Boat", 20, Quaternion(Vector3(0, -180 * Math::DEG2RAD, 0)), boat->getTransform()->getLocalPosition());
	anim->loop(true);
	anim->play();

	Animation *anim2 = new Animation(20.0);
	boat2->addComponent(anim2);
	anim2->addKey("Boat2", 0, Quaternion(Vector3(0, 0, 180 * Math::DEG2RAD)), boat2->getTransform()->getLocalPosition());
	anim2->addKey("Boat2", 10, Quaternion(Vector3(0, 0, 0 * Math::DEG2RAD)), boat2->getTransform()->getLocalPosition());
	anim2->addKey("Boat2", 20, Quaternion(Vector3(0, 0, -180 * Math::DEG2RAD)), boat2->getTransform()->getLocalPosition());
	anim2->loop(true);
	anim2->play();


	return true;
}