#include "Assignment1Test.h"
#include "Camera.h"
#include "Material.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "KeyboardController.h"
#include "Lamp.h"
#include "Bullet.h"

#include "HoleInTheWall.h"
#include "Task1Sweep.h"
#include "Task2Comp.h"
#include "CompositeGun.h"
#include "Rectangle.h"
#include "GunHandle.h"

using namespace T3D;

Assignment1Test::Assignment1Test(void)
{
	//drawArea = new Texture(1024, 640, false);
	//drawArea->clear(Colour(255, 255, 255, 255));
}


Assignment1Test::~Assignment1Test(void)
{
}


bool Assignment1Test::init() {
	
	//To test your code, you should create a new application called Assignment1Test that is a subclass of WinGLApplication. The init method should create:
	WinGLApplication::init();
	//1) a single directional light
	GameObject *lightObj = new GameObject(this);   
	Light *light = new Light(Light::DIRECTIONAL);   
	light->setAmbient(10, 10, 10);   
	light->setDiffuse(1, 1, 1);   
	light->setSpecular(1, 1, 1);    
	lightObj->setLight(light);   
	lightObj->getTransform()->setLocalRotation(Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0));   
	lightObj->getTransform()->setParent(root);
	//2. a camera
	GameObject *camObj = new   GameObject(this);    
	renderer->camera = new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);   
	camObj->getTransform()->setLocalPosition(Vector3(0, 0, 20));   
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));   
	camObj->setCamera(renderer->camera);   
	camObj->getTransform()->setParent(root);   
	camObj->addComponent(new KeyboardController());

	// Set the light source to come from the camera
	// I've commented this out since it's not in the assignment spec but like, you know, uncomment if you want. 
	//lightObj->getTransform()->setParent(camObj->getTransform());

	//In addition, add one of each object you want to be marked with appropriate separation between objects.  
	//It may also be useful to use different material colours for the objects to make it easier to distinguish between them

	//Task 1 "CANOE"
	Material *yellow = renderer->createMaterial(Renderer::PR_OPAQUE);
	yellow->setDiffuse(1, 1, 0, 1);
	//10/9/2019 adding the hotdog boat sweep
	Task1Sweep *sweep = new Task1Sweep(this);
	sweep->setMaterial(yellow);
	sweep->getTransform()->setLocalPosition(Vector3(0, 0, 20));
	sweep->getTransform()->setParent(root);
	sweep->boat->setMaterial(yellow);

	//Task 2 "CANOE WITH OARS"
	Material *cream = renderer->createMaterial(Renderer::PR_OPAQUE);
	cream->setDiffuse(1, .8, 0, 1);
	Task2Comp *comp = new Task2Comp(this);
	comp->setMaterial(yellow);
	comp->getTransform()->setLocalPosition(Vector3(0, 0, -20));
	comp->getTransform()->setParent(root);
	comp->boat->setMaterial(cream);
	//comp->oarJoint1->setMaterial(yellow);
	comp->oar1->setMaterial(yellow);
	comp->oarTip1->setMaterial(cream);
	comp->oar2->setMaterial(yellow);
	comp->oarTip2->setMaterial(cream);
	comp->oar3->setMaterial(yellow);
	comp->oarTip3->setMaterial(cream);
	comp->oar4->setMaterial(yellow);
	comp->oarTip4->setMaterial(cream);

	//Task 3 Hole in the wall.
	//only works with even density.
	Material *green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0, 1, 0, 1);
	
	GameObject *holeInTheWall = new GameObject(this);
	holeInTheWall->setMesh(new HoleInTheWall(Vector3(5,5,1),
		2, 2,
		1, 8));
	holeInTheWall->setMaterial(green);
	holeInTheWall->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	holeInTheWall->getTransform()->setParent(root);

	GameObject *bigHoleInTheWall = new GameObject(this);
	bigHoleInTheWall->setMesh(new HoleInTheWall(Vector3(5, 5, 1),
		2.75, 2.75,
		2, 16));
	bigHoleInTheWall->setMaterial(green);
	bigHoleInTheWall->getTransform()->setLocalPosition(Vector3(10, 0, 1));
	bigHoleInTheWall->getTransform()->setParent(root);

	GameObject *mediumHoleInTheWall = new GameObject(this);
	mediumHoleInTheWall->setMesh(new HoleInTheWall(Vector3(5, 5, 1),
		2.75, 2.75,
		2, 32));
	mediumHoleInTheWall->setMaterial(green);
	mediumHoleInTheWall->getTransform()->setLocalPosition(Vector3(-10, 0, -1));
	mediumHoleInTheWall->getTransform()->setParent(root);

	

	//task 5 "REVOLVER AND TARGET"
	Material *grey = renderer->createMaterial(Renderer::PR_OPAQUE);
	grey->setDiffuse(1, 1, 1, 1);	
	
	CompositeGun *gun = new CompositeGun(this);
	gun->setMaterial(grey);
	gun->getTransform()->setLocalPosition(Vector3(0, .5, 12));
	gun->getTransform()->setParent(root);
	gun->getTransform()->setLocalRotation(Quaternion(Vector3(0, (Math::PI) / 2, 0)));
	
	gun->lowerBody->setMaterial(grey);
	gun->middleBody->setMaterial(grey);
	gun->upperBody->setMaterial(grey);
	gun->frontBody->setMaterial(grey);
	gun->chamberArm->setMaterial(grey);
	gun->chamber->setMaterial(grey);
	gun->barrel->setMaterial(grey);
	gun->ironSight->setMaterial(grey);
	gun->lever->setMaterial(grey);
	gun->trigger->setMaterial(grey);
	gun->triggerGuardFront->setMaterial(grey);
	gun->triggerGuardBack->setMaterial(grey);
	gun->nuHandle->setMaterial(yellow);
	
	gun->targetStand->setMaterial(grey);
	gun->target->setMaterial(yellow);
	
	return true;
}