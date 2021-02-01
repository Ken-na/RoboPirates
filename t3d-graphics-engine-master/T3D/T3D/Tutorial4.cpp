#include "Tutorial4.h"
#include "Camera.h"
#include "Material.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "KeyboardController.h"
#include "Lamp.h"

using namespace T3D;

Tutorial4::Tutorial4(void)
{
	//drawArea = new Texture(1024, 640, false);
	//drawArea->clear(Colour(255, 255, 255, 255));
}


Tutorial4::~Tutorial4(void)
{
}


bool Tutorial4::init() {
	/*
	//printf("G");
	WinGLApplication::init();
	// more code to come...
	GameObject *lightObj = new GameObject(this);
	Light *light = new Light(Light::DIRECTIONAL);
	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);
	//lightObj->getTransform()->
	//	setLocalRotation(Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0));
	//lightObj->getTransform()->setParent(root);
	
	//add a light and a camera controller
	GameObject *camObj = new GameObject(this);
	renderer->camera =
		new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0, 0, 20));
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());
	//and a material
	Material *green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0, 1, 0, 1);
	Material *red = renderer->createMaterial(Renderer::PR_OPAQUE);
	red->setDiffuse(1, 0, 0, 1);
	//finally add a cube mesh for testing 
	GameObject *cube = new GameObject(this);
	cube->setMesh(new Pyramid(1));
	cube->setMaterial(green);
	cube->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	cube->getTransform()->setParent(root);
	cube->getTransform()->name = "Cube";

	GameObject *cyl = new GameObject(this);
	cyl->setMesh(new Cylinder(1,2,7));
	cyl->setMaterial(red);
	cyl->getTransform()->setLocalPosition(Vector3(3, 0, 0));
	cyl->getTransform()->setParent(root);
	cyl->getTransform()->name = "Cylinder";


	//Set the light source to come from the camera
	lightObj->getTransform()->setParent(camObj->getTransform());
	return true;*/
		
	WinGLApplication::init();
	// more code to come...
	GameObject *lightObj = new GameObject(this);
	Light *light = new Light(Light::DIRECTIONAL);
	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);
	//attempting to lamp
	//tutorial 5
	//create an instance of your Lamp:
	Material *grey = renderer->createMaterial(Renderer::PR_OPAQUE);
	grey->setDiffuse(0, 1, 0, 1);

	Lamp *lamp = new Lamp(this);
	lamp->setMaterial(grey);
	lamp->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	lamp->getTransform()->setParent(root);
	lamp->base->setMaterial(grey);
	lamp->arm1->setMaterial(grey);
	lamp->arm2->setMaterial(grey);
	lamp->shade->setMaterial(grey);

	

	//add a camera to the scene
	//This camera is super fast... you have been warned
	GameObject *camObj = new GameObject(this);
	renderer->camera = new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0, 0.5, 3));
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());

	//look ma it mvoes
	lamp->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
	lamp->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	lamp->shadeJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	
	//Everything from here down was a part of tutorial 6

	AnimationTest *animTask = new AnimationTest(this);
	animTask->lamp = lamp->getTransform();
	//addTask(animTask);

	GameObject *lookAtMeYuh = new GameObject(this);
	lookAtMeYuh->getTransform()->setLocalPosition(Vector3(3, 0, 3));
	LookAtBehaviour *looky = new LookAtBehaviour(lookAtMeYuh->getTransform());

	//lamp->addComponent(looky);

	LampBehaviour *lampBamp = new LampBehaviour();

	lamp->addComponent(lampBamp);

	Animation *anim = new Animation(10.0);
	lamp->addComponent(anim);
	anim->addKey("ElbowJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
	anim->addKey("ElbowJoint", 5.0, Quaternion(Vector3(-Math::HALF_PI, 0, 0)), Vector3(0, 0.2, 0));
	anim->addKey("ElbowJoint", 7.0, Quaternion(Vector3(Math::HALF_PI, 0, 0)), Vector3(0, 0.2, 0));
	anim->addKey("ElbowJoint", 10.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
	anim->addKey("ShadeJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
	anim->addKey("ShadeJoint", 5.0, Quaternion(Vector3(0, 0, -Math::HALF_PI)), Vector3(0, 0.2, 0));
	anim->addKey("ShadeJoint", 7.0, Quaternion(Vector3(0, 0, Math::HALF_PI)), Vector3(0, 0.2, 0));
	anim->addKey("ShadeJoint", 10.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
	anim->loop(true);
	anim->play();

	return true;
}