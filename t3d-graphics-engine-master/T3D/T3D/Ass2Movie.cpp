#include "Ass2Movie.h"
#include "Camera.h"
#include "Material.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "KeyboardController.h"
#include "Lamp.h"
#include "Rectangle.h"

#include "Task2Comp.h"
#include "OarPaddle.h"
#include "Person.h"
#include "Target.h"

#include "Math.h"
#include "HouseBoat.h"
#include "HouseBoatMove.h"
#include "HatFloat.h"

#include "LiamBillboard.h"
#include "CameraMovement.h"
#include "SoundTestTask.h"

using namespace T3D;

Ass2Movie::Ass2Movie(void)
{
	//drawArea = new Texture(1024, 640, false);
	//drawArea->clear(Colour(255, 255, 255, 255));
}


Ass2Movie::~Ass2Movie(void)
{
}


bool Ass2Movie::init() {
	WinGLApplication::init();
	// more code to come...
	GameObject *lightObj = new GameObject(this);
	Light *light = new Light(Light::DIRECTIONAL);
	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);
	//lightObj->getTransform()->setLocalRotation(Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0 * Math::DEG2RAD));
	lightObj->getTransform()->setLocalRotation(Vector3(-135 * Math::DEG2RAD, -100 * Math::DEG2RAD, 45 * Math::DEG2RAD)); //-135
	lightObj->getTransform()->setParent(root);

	SoundTestTask *sss = new SoundTestTask(this);
	addTask(sss);

	/*Light *light2 = new Light(Light::DIRECTIONAL);
	light2->setAmbient(.25, .25, .25);
	//light2->setDiffuse(.25, .25, .25);
	//light2->setSpecular(.25, .25, .25);
	GameObject *lightObj2 = new GameObject(this);
	lightObj2->setLight(light);
	lightObj2->getTransform()->setLocalRotation(Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0 * Math::DEG2RAD));/**/
	//attempting to lamp
	//tutorial 5
	//create an instance of your Lamp:
	Material *yellow = renderer->createMaterial(Renderer::PR_OPAQUE);
	yellow->setDiffuse(1, 1, 0, 1);
	Material *black = renderer->createMaterial(Renderer::PR_OPAQUE);
	black->setDiffuse(0.1, .1, .1, 1);
	Material *silver = renderer->createMaterial(Renderer::PR_OPAQUE);
	silver->setDiffuse(.9, .9, .9, 1);
	Material *darkSilver = renderer->createMaterial(Renderer::PR_OPAQUE);
	darkSilver->setDiffuse(.3, .3, .3, 1);
	Material *cream = renderer->createMaterial(Renderer::PR_OPAQUE);
	cream->setDiffuse(1, 0, 0, 1);

	Material *shallowWater = renderer->createMaterial(Renderer::PR_OPAQUE);
	shallowWater->setDiffuse(0, 0, 1, .5);
	/*shallowWater->setShininess(20);

	GLShader *phongShader = new GLShader("Resources/phongVert.shader", "Resources/phongFrag.shader");
	phongShader->compileShader();
	shallowWater->setShader(phongShader);*/

	
	//fakeCam->getTransform()->setLocalRotation(Vector3(0, 0, 115 * Math::DEG2RAD));



	Material *deepWater = renderer->createMaterial(Renderer::PR_OPAQUE);
	deepWater->setDiffuse(0, 0, 1, 1);
	//add a camera to the scene
	//This camera is super fast... you have been warned
	GameObject *camObj = new GameObject(this);
	renderer->camera = new Camera(Camera::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	//camObj->addComponent(new KeyboardController());
	renderer->loadSkybox("Resources/robo");
	

	GameObject *water1 = new GameObject(this);
	water1->getTransform()->setParent(root);
	water1->setMesh(new Rectangle(300, 3, 300));
	water1->setMaterial(shallowWater);
	water1->getTransform()->setLocalPosition(Vector3(0, -2, 0));
	water1->getTransform()->name = "Water1";

	GameObject *water2 = new GameObject(this);
	water2->getTransform()->setParent(root);
	water2->setMesh(new Rectangle(300, 1, 300));
	water2->setMaterial(deepWater);
	water2->getTransform()->setLocalPosition(Vector3(0, -4, 0));
	water2->getTransform()->name = "Water2";

	Texture *boattex = new Texture("Resources/HouseBoatTexture.jpg", true, true);
	renderer->loadTexture(boattex);
	Material *boatmat = renderer->createMaterial(Renderer::PR_OPAQUE);
	boatmat->setTexture(boattex);

	
	

	GameObject *houseBoat = new GameObject(this);
	houseBoat->getTransform()->setParent(root);
	houseBoat->setMesh(new HouseBoat(6));
	houseBoat->setMaterial(boatmat);
	houseBoat->getTransform()->setLocalPosition(Vector3(-100, 8, 80));
	houseBoat->getTransform()->setLocalRotation(Vector3(0, -45 * Math::DEG2RAD, 0));
	houseBoat->getTransform()->name = "Boat2";

	HouseBoatMove *houseBoatMove = new HouseBoatMove(this);
	houseBoatMove->obj = houseBoat->getTransform();
	addTask(houseBoatMove);

	
	Person *boatPerson = new Person(this);
	boatPerson->getTransform()->setParent(houseBoat->getTransform());//(boat->getTransform());
	boatPerson->getTransform()->setLocalPosition(Vector3(00, 0, -12));
	boatPerson->getTransform()->setLocalRotation(Vector3(0, 180 * Math::DEG2RAD, 0));//225 * Math::DEG2RAD
	boatPerson->getTransform()->setLocalScale(Vector3(0.5, 0.5, 0.5));
	boatPerson->body->setMaterial(cream);
	boatPerson->upperBody->setMaterial(cream);
	boatPerson->spine->setMaterial(cream);
	boatPerson->pelvis->setMaterial(cream);
	boatPerson->rightUpLeg->setMaterial(cream);
	boatPerson->rightBotLeg->setMaterial(cream);
	boatPerson->rightFoot->setMaterial(cream);
	boatPerson->leftUpLeg->setMaterial(cream);
	boatPerson->leftBotLeg->setMaterial(cream);
	boatPerson->leftFoot->setMaterial(cream);
	//boatPerson->sphere->setMaterial(yellow);
	boatPerson->neck->setMaterial(cream);
	boatPerson->head->setMaterial(cream);
	boatPerson->rightUpArm->setMaterial(cream);
	boatPerson->rightBotArm->setMaterial(cream);
	boatPerson->rightHand->setMaterial(cream);
	boatPerson->leftUpArm->setMaterial(cream);
	boatPerson->leftBotArm->setMaterial(cream);
	boatPerson->leftHand->setMaterial(cream);
	boatPerson->gun->lowerBody->setMaterial(yellow);
	boatPerson->gun->middleBody->setMaterial(yellow);
	boatPerson->gun->upperBody->setMaterial(yellow);
	boatPerson->gun->frontBody->setMaterial(yellow);
	boatPerson->gun->chamberArm->setMaterial(yellow);
	boatPerson->gun->chamber->setMaterial(yellow);
	boatPerson->gun->barrel->setMaterial(yellow);
	boatPerson->gun->ironSight->setMaterial(yellow);
	boatPerson->gun->lever->setMaterial(yellow);
	boatPerson->gun->trigger->setMaterial(yellow);
	boatPerson->gun->triggerGuardFront->setMaterial(yellow);
	boatPerson->gun->triggerGuardBack->setMaterial(yellow);
	boatPerson->gun->nuHandle->setMaterial(yellow);
	boatPerson->hat->setMaterial(black);



	Texture *boatPictex = new Texture("Resources/BoatPersonHat.jpg", true, true);
	renderer->loadTexture(boatPictex);
	Material *boatPicmat = renderer->createMaterial(Renderer::PR_OPAQUE);
	boatPicmat->setTexture(boatPictex);

	GameObject *boatPersonPic = new GameObject(this);
	boatPersonPic->setMesh(new LiamBillboard(.3));
	boatPersonPic->getTransform()->setParent(boatPerson->hat->getTransform());
	boatPersonPic->getTransform()->setLocalPosition(Vector3(.05, .5, 1));
	boatPersonPic->getTransform()->setLocalRotation(Vector3(0 * Math::DEG2RAD, 90 * Math::DEG2RAD, -90 * Math::DEG2RAD));
	boatPersonPic->setMaterial(boatPicmat);

	Task2Comp *boat = new Task2Comp(this);	
	boat->getTransform()->setParent(root);
	boat->getTransform()->setLocalScale(Vector3(.5, .5, .5));
	boat->getTransform()->setLocalPosition(Vector3(-30, 0, 0));
	boat->boat->setMaterial(darkSilver);
	boat->oar1->setMaterial(silver);
	boat->oarTip1->setMaterial(darkSilver);
	boat->oar2->setMaterial(silver);
	boat->oarTip2->setMaterial(darkSilver);
	boat->oar3->setMaterial(silver);
	boat->oarTip3->setMaterial(darkSilver);
	boat->oar4->setMaterial(silver);
	boat->oarTip4->setMaterial(darkSilver);

	Person *endHat = new Person(this);
	endHat->getTransform()->setParent(boat->getTransform());
	endHat->getTransform()->setLocalPosition(Vector3(35, 100, -45));
	endHat->getTransform()->setLocalRotation(Vector3(90 * Math::DEG2RAD, 0 * Math::DEG2RAD, 0));
	endHat->hat->setMaterial(black);

	HatFloat *hatMove = new HatFloat(this);
	hatMove->obj = endHat->getTransform();
	addTask(hatMove);

	Texture *endHattex = new Texture("Resources/TitleCardHat.jpg", true, true);
	renderer->loadTexture(endHattex);
	Material *endPicmat = renderer->createMaterial(Renderer::PR_OPAQUE);
	endPicmat->setTexture(endHattex);

	GameObject *endHatPic = new GameObject(this);
	endHatPic->setMesh(new LiamBillboard(.3));
	endHatPic->getTransform()->setParent(endHat->hat->getTransform());
	endHatPic->getTransform()->setLocalPosition(Vector3(.05, .5, 1));
	endHatPic->getTransform()->setLocalRotation(Vector3(0 * Math::DEG2RAD, 90 * Math::DEG2RAD, -90 * Math::DEG2RAD));
	endHatPic->setMaterial(endPicmat);

	Target *targ1 = new Target(this);
	targ1->getTransform()->setParent(root);//(boat->getTransform());
	targ1->getTransform()->setLocalPosition(Vector3(-6, 10, 20));
	targ1->target->setMaterial(yellow);
	targ1->innerTarget->setMaterial(cream);
	targ1->inner2Target->setMaterial(yellow);
	targ1->targetStand->setMaterial(cream);
	
	Target *targ2 = new Target(this);
	targ2->getTransform()->setParent(root);//(boat->getTransform());
	targ2->getTransform()->setLocalPosition(Vector3(-12, 10, 20));
	targ2->target->setMaterial(yellow);
	targ2->innerTarget->setMaterial(cream);
	targ2->inner2Target->setMaterial(yellow);
	targ2->targetStand->setMaterial(cream);

	Target *targ3 = new Target(this);
	targ3->getTransform()->setParent(root);//(boat->getTransform());
	targ3->getTransform()->setLocalPosition(Vector3(-16, 20, 20));
	targ3->target->setMaterial(yellow);
	targ3->innerTarget->setMaterial(cream);
	targ3->inner2Target->setMaterial(yellow);
	targ3->targetStand->setMaterial(cream);

	//man targets
	Target *targ4 = new Target(this);
	targ4->getTransform()->setParent(root);//(boat->getTransform());
	targ4->getTransform()->setLocalPosition(Vector3(-20, 5, 20));
	targ4->target->setMaterial(yellow);
	targ4->innerTarget->setMaterial(cream);
	targ4->inner2Target->setMaterial(yellow);
	targ4->targetStand->setMaterial(cream);

	Target *targ5 = new Target(this);
	targ5->getTransform()->setParent(root);//(boat->getTransform());
	targ5->getTransform()->setLocalPosition(Vector3(-24, 10, 20));
	targ5->target->setMaterial(yellow);
	targ5->innerTarget->setMaterial(cream);
	targ5->inner2Target->setMaterial(yellow);
	targ5->targetStand->setMaterial(cream);

	Target *targ6 = new Target(this);
	targ6->getTransform()->setParent(root);//(boat->getTransform());
	targ6->getTransform()->setLocalPosition(Vector3(-28, 7.5, 20));
	targ6->target->setMaterial(yellow);
	targ6->innerTarget->setMaterial(cream);
	targ6->inner2Target->setMaterial(yellow);
	targ6->targetStand->setMaterial(cream);
	
	Person *person = new Person(this);
	person->getTransform()->setParent(boat->boat->getTransform());//(boat->getTransform());
	person->getTransform()->setLocalPosition(Vector3(24, 17.75, 1));
	person->jPelvisLeft->getTransform()->setLocalRotation(Quaternion(Vector3( Math::PI / 11, 0, 0)));
	person->jLeftKnee->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 8, 0, 0)));
	person->jLeftAnkle->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 11, 0, 0)));
	person->jPelvisRight->getTransform()->setLocalRotation(Quaternion(Vector3(11 * Math::PI / 6, 0, 0)));
	person->jRightKnee->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 6, 0, 0)));
	person->jRightAnkle->getTransform()->setLocalRotation(Quaternion(Vector3(11 * Math::PI / 6, 0, 0)));

	person->body->getTransform()->setLocalRotation(Quaternion(Vector3(0, Math::PI / 12, 0))); //Math::DEG2RAD(30);
	person->jSpinePelvis->getTransform()->setLocalRotation(Quaternion(Vector3(0, -1 * Math::PI / 12, 0)));

	person->body->setMaterial(silver);
	person->upperBody->setMaterial(silver);
	person->spine->setMaterial(darkSilver);
	person->pelvis->setMaterial(silver);
	person->rightUpLeg->setMaterial(silver);
	person->rightBotLeg->setMaterial(silver);
	person->rightFoot->setMaterial(silver);
	person->leftUpLeg->setMaterial(silver);
	person->leftBotLeg->setMaterial(silver);
	person->leftFoot->setMaterial(silver);
	//person->sphere->setMaterial(yellow);

	person->neck->setMaterial(silver);
	person->head->setMaterial(silver);
	person->rightUpArm->setMaterial(silver);
	person->rightBotArm->setMaterial(silver);
	person->rightHand->setMaterial(silver);
	person->leftUpArm->setMaterial(silver);
	person->leftBotArm->setMaterial(silver);
	person->leftHand->setMaterial(silver);

	person->gun->lowerBody->setMaterial(yellow);
	person->gun->middleBody->setMaterial(yellow);
	person->gun->upperBody->setMaterial(yellow);
	person->gun->frontBody->setMaterial(yellow);
	person->gun->chamberArm->setMaterial(yellow);
	person->gun->chamber->setMaterial(yellow);
	person->gun->barrel->setMaterial(yellow);
	person->gun->ironSight->setMaterial(yellow);
	person->gun->lever->setMaterial(yellow);
	person->gun->trigger->setMaterial(yellow);
	person->gun->triggerGuardFront->setMaterial(yellow);
	person->gun->triggerGuardBack->setMaterial(yellow);
	person->gun->nuHandle->setMaterial(yellow);
	person->hat->setMaterial(black);

	Texture *roboPictex = new Texture("Resources/RoboPersonHat.jpg", true, true);
	renderer->loadTexture(roboPictex);
	Material *roboPicmat = renderer->createMaterial(Renderer::PR_OPAQUE);
	roboPicmat->setTexture(roboPictex);

	GameObject *personPic = new GameObject(this);
	personPic->setMesh(new LiamBillboard(.3));
	personPic->getTransform()->setParent(person->hat->getTransform());
	personPic->getTransform()->setLocalPosition(Vector3(.05, .5, 1));
	personPic->getTransform()->setLocalRotation(Vector3(0 * Math::DEG2RAD, 90 * Math::DEG2RAD, -90 * Math::DEG2RAD));
	personPic->setMaterial(roboPicmat);

	//camera shits
	GameObject *cameraDolly = new GameObject(this);
	cameraDolly->getTransform()->setParent(root);
	//cameraDolly->getTransform()->setLocalPosition(Vector3(0, 14, 10)); //works well for dive shot
	GameObject *fakeCam = new GameObject(this);
	fakeCam->getTransform()->setParent(cameraDolly->getTransform());
	fakeCam->setMesh(new Pyramid(2));
	//fakeCam->setMaterial(yellow);
	fakeCam->getTransform()->setLocalRotation(Vector3(90 * Math::DEG2RAD, 0, 0));
	camObj->getTransform()->setParent(cameraDolly->getTransform());

	CameraMovement *theMagic = new CameraMovement(this);
	theMagic->lookat1 = person->hat->getTransform();
	theMagic->lookat2 = person->gun->barrel->getTransform();//targ1->target->getTransform();
	theMagic->lookat3 = targ4->target->getTransform();
	theMagic->lookat4 = targ5->target->getTransform();
	theMagic->lookat5 = targ6->target->getTransform();
	theMagic->lookat6 = boatPerson->gun->barrel->getTransform();
	theMagic->lookat7 = endHatPic->getTransform();
	theMagic->obj = cameraDolly->getTransform();
	theMagic->objGameobj = cameraDolly;
	addTask(theMagic);

	//boat->oarJoint1->addComponent(oarPad);
	Animation *animOar = new Animation(10.0);
	boat->addComponent(animOar);	
	//frontleft
	animOar->addKey("OarJoint1", 0, Quaternion(Vector3(3 * Math::PI / 2, 0, 0)), boat->oarJoint1->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint1", 3, Quaternion(Vector3(7 * Math::PI / 4, 11 * Math::PI / 6, 0)), boat->oarJoint1->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint1", 5, Quaternion(Vector3(11 * Math::PI / 6, 0, 0)), boat->oarJoint1->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint1", 7, Quaternion(Vector3(7 * Math::PI / 4, Math::PI / 6, 0)), boat->oarJoint1->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint1", 10, Quaternion(Vector3(3 * Math::PI / 2, 0, 0)), boat->oarJoint1->getTransform()->getLocalPosition());
	//right
	animOar->addKey("OarJoint2", 0, Quaternion(Vector3(Math::PI / 2, 0, 0)), boat->oarJoint2->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint2", 3, Quaternion(Vector3(Math::PI / 4,  Math::PI / 6, 0)), boat->oarJoint2->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint2", 5, Quaternion(Vector3(Math::PI / 6, 0, 0)), boat->oarJoint2->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint2", 7, Quaternion(Vector3(Math::PI / 4, 11 * Math::PI / 6, 0)), boat->oarJoint2->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint2", 10, Quaternion(Vector3(Math::PI / 2, 0, 0)), boat->oarJoint2->getTransform()->getLocalPosition());
	//backleft
	animOar->addKey("OarJoint3", 0, Quaternion(Vector3(3 * Math::PI / 2, 0, 0)), boat->oarJoint3->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint3", 3, Quaternion(Vector3(7 * Math::PI / 4, 11 * Math::PI / 6, 0)), boat->oarJoint3->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint3", 5, Quaternion(Vector3(11 * Math::PI / 6, 0, 0)), boat->oarJoint3->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint3", 7, Quaternion(Vector3(7 * Math::PI / 4, Math::PI / 6, 0)), boat->oarJoint3->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint3", 10, Quaternion(Vector3(3 * Math::PI / 2, 0, 0)), boat->oarJoint3->getTransform()->getLocalPosition());
	//right
	animOar->addKey("OarJoint4", 0, Quaternion(Vector3(Math::PI / 2, 0, 0)), boat->oarJoint4->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint4", 3, Quaternion(Vector3(Math::PI / 4, Math::PI / 6, 0)), boat->oarJoint4->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint4", 5, Quaternion(Vector3(Math::PI / 6, 0, 0)), boat->oarJoint4->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint4", 7, Quaternion(Vector3(Math::PI / 4, 11 * Math::PI / 6, 0)), boat->oarJoint4->getTransform()->getLocalPosition());
	animOar->addKey("OarJoint4", 10, Quaternion(Vector3(Math::PI / 2, 0, 0)), boat->oarJoint4->getTransform()->getLocalPosition());

	animOar->loop(true);
	animOar->play();
	Animation *boatMove = new Animation(30);
	boat->addComponent(boatMove);
	boatMove->addKey("BoatWithOars", 0, Quaternion(Vector3(0, 0, 0)), Vector3(60, 0, 0));
	boatMove->addKey("BoatWithOars", 30, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0, 0));
	boatMove->play();
	Animation *personMove = new Animation(80);
	person->addComponent(personMove);
	Animation *targetMove = new Animation(80);
	targ1->addComponent(targetMove);
	Animation *target2Move = new Animation(80);
	targ2->addComponent(target2Move);
	Animation *target3Move = new Animation(80);
	targ3->addComponent(target3Move);
	Animation *target4Move = new Animation(80);
	targ4->addComponent(target4Move);
	Animation *target5Move = new Animation(80);
	targ5->addComponent(target5Move);
	Animation *target6Move = new Animation(80);
	targ6->addComponent(target6Move);
	Animation *boatPersonMove = new Animation(80);
	boatPerson->addComponent(boatPersonMove);


	personMove->addKey("Body", 0, Quaternion(Vector3(0, 25 * Math::DEG2RAD, 25 * Math::DEG2RAD)), person->body->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jSpineBody", 0, Quaternion(Vector3(0, -25 * Math::DEG2RAD, -25 * Math::DEG2RAD)), person->jSpineBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightShoulder", 0, Quaternion(Vector3(0, 0, -115 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftShoulder", 0, Quaternion(Vector3(0, 0, 65 * Math::DEG2RAD)), person->jLeftShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 0, Quaternion(Vector3(0, 0, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jRightElbow", 0, Quaternion(Vector3(0, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 0, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftElbow", 0, Quaternion(Vector3(0, 0, 0)), person->jLeftElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jNeckBody", 0, Quaternion(Vector3(0, 0, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	//gunMove->addKey("LowerBody", 0, Quaternion(Vector3(0, 0, 0)), person->gun->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	//gunMove->addKey("LowerBody", 5, Quaternion(Vector3(0, 0, -25 * Math::DEG2RAD)), person->gun->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("Body", 5, Quaternion(Vector3(0, 0, -25 * Math::DEG2RAD)), person->body->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jSpineBody", 5, Quaternion(Vector3(0, 0, 25 * Math::DEG2RAD)), person->jSpineBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightShoulder", 5, Quaternion(Vector3(0, 0, -65 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftShoulder", 5, Quaternion(Vector3(0, 0, 115 * Math::DEG2RAD)), person->jLeftShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	
	personMove->addKey("Body", 10, Quaternion(Vector3(0, 45 * Math::DEG2RAD,0)), person->body->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jSpineBody", 10, Quaternion(Vector3(0, -45 * Math::DEG2RAD, 0)), person->jSpineBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightShoulder", 10, Quaternion(Vector3(0, -90 * Math::DEG2RAD, -65 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	//personMove->addKey("jLeftShoulder", 10, Quaternion(Vector3(0, 0, 115 * Math::DEG2RAD)), person->jLeftShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightElbow", 10, Quaternion(Vector3(0, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftElbow", 10, Quaternion(Vector3(0, 0, 0)), person->jLeftElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jNeckBody", 10, Quaternion(Vector3(0, 0, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jLeftShoulder", 11, Quaternion(Vector3(0, 90 * Math::DEG2RAD, 65 * Math::DEG2RAD)), person->jLeftShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftElbow", 12, Quaternion(Vector3(65 * Math::DEG2RAD,0,0)), person->jLeftElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	//personMove->addKey("jRightShoulder", 12, Quaternion(Vector3(0, -90 * Math::DEG2RAD, -65 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("Body", 12, Quaternion(Vector3(0, 90 * Math::DEG2RAD, 0)), person->body->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jSpineBody", 12, Quaternion(Vector3(0, -90 * Math::DEG2RAD, 0)), person->jSpineBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jRightElbow", 13, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jNeckBody", 15, Quaternion(Vector3(15 * Math::DEG2RAD, -50 * Math::DEG2RAD, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	//20 first shot
	personMove->addKey("jRightElbow", 18, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 18, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	//gunMove->addKey("HandleJoint", 17, Quaternion(Vector3(0, 0, 0)), person->gun->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	targetMove->addKey("TargetJoint", 0, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ1->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	targetMove->addKey("TargetJoint", 19, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ1->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("LeverJoint", 0, Quaternion(Vector3(110 * Math::DEG2RAD, 0, 0)), person->gun->leverJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("LeverJoint", 18, Quaternion(Vector3(110 * Math::DEG2RAD, 0, 0)), person->gun->leverJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	
	personMove->addKey("LeverJoint", 19, Quaternion(Vector3(180 * Math::DEG2RAD, 0, 0)), person->gun->leverJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 19, Quaternion(Vector3(-15 * Math::DEG2RAD, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightElbow", 20, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	targetMove->addKey("TargetJoint", 20, Quaternion(Vector3(180* Math::DEG2RAD, 0, 0)), targ1->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightShoulder", 20, Quaternion(Vector3(0, -90 * Math::DEG2RAD, -65 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	//shot 2
	personMove->addKey("jRightShoulder", 21, Quaternion(Vector3(0, -105 * Math::DEG2RAD, -65 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightElbow", 21, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 21, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("LeverJoint", 20, Quaternion(Vector3(110 * Math::DEG2RAD, 0, 0)), person->gun->leverJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("LeverJoint", 21, Quaternion(Vector3(110 * Math::DEG2RAD, 0, 0)), person->gun->leverJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightElbow", 21, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 21, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target2Move->addKey("TargetJoint", 0, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ2->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target2Move->addKey("TargetJoint", 21, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ2->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("LeverJoint", 22, Quaternion(Vector3(180 * Math::DEG2RAD, 0, 0)), person->gun->leverJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("LeverJoint", 23, Quaternion(Vector3(110 * Math::DEG2RAD, 0, 0)), person->gun->leverJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jRightWrist", 22, Quaternion(Vector3(-15 * Math::DEG2RAD, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightElbow", 23, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target2Move->addKey("TargetJoint", 23, Quaternion(Vector3(180 * Math::DEG2RAD, 0, 0)), targ2->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	//shot 3
	personMove->addKey("jRightShoulder", 24, Quaternion(Vector3(0, -90 * Math::DEG2RAD, -65 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightElbow", 24, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 24, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jNeckBody", 24, Quaternion(Vector3(15 * Math::DEG2RAD, -50 * Math::DEG2RAD, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jRightShoulder", 26, Quaternion(Vector3(0, -90 * Math::DEG2RAD, -87 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jNeckBody", 26, Quaternion(Vector3(-10 * Math::DEG2RAD, -50 * Math::DEG2RAD, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	//hold still
	personMove->addKey("jRightShoulder", 29, Quaternion(Vector3(0, -90 * Math::DEG2RAD, -87 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jNeckBody", 29, Quaternion(Vector3(-10 * Math::DEG2RAD, -50 * Math::DEG2RAD, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target3Move->addKey("TargetJoint", 0, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ2->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target3Move->addKey("TargetJoint", 27, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ2->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightElbow", 29, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 27, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("LeverJoint", 27, Quaternion(Vector3(110 * Math::DEG2RAD, 0, 0)), person->gun->leverJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("LeverJoint", 28, Quaternion(Vector3(180 * Math::DEG2RAD, 0, 0)), person->gun->leverJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("LeverJoint", 29, Quaternion(Vector3(110 * Math::DEG2RAD, 0, 0)), person->gun->leverJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	//hold till after flick
	personMove->addKey("jRightWrist", 28, Quaternion(Vector3(-15 * Math::DEG2RAD, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target3Move->addKey("TargetJoint", 28, Quaternion(Vector3(180 * Math::DEG2RAD, 0, 0)), targ2->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jRightShoulder", 31, Quaternion(Vector3(0, -90 * Math::DEG2RAD, -65 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightElbow", 31, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 29, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jNeckBody", 31, Quaternion(Vector3(15 * Math::DEG2RAD, -50 * Math::DEG2RAD, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	//check ammo
	personMove->addKey("Body", 32, Quaternion(Vector3(0, 90 * Math::DEG2RAD, 0)), person->body->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jSpineBody", 32, Quaternion(Vector3(0, -90 * Math::DEG2RAD, 0)), person->jSpineBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jNeckBody", 32, Quaternion(Vector3(15 * Math::DEG2RAD, -50 * Math::DEG2RAD, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightShoulder", 32, Quaternion(Vector3(0, -90 * Math::DEG2RAD, -65 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftShoulder", 38, Quaternion(Vector3(0, 90 * Math::DEG2RAD, 65 * Math::DEG2RAD)), person->jLeftShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftElbow", 38, Quaternion(Vector3(65 * Math::DEG2RAD, 0, 0)), person->jLeftElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));


	//move 2
	personMove->addKey("Body", 35, Quaternion(Vector3(0, 0, 0)), person->body->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jSpineBody", 35, Quaternion(Vector3(0, 0, 0)), person->jSpineBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jNeckBody", 35, Quaternion(Vector3(20 * Math::DEG2RAD, 0 * Math::DEG2RAD, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightShoulder", 36, Quaternion(Vector3(-30 * Math::DEG2RAD, 20 * Math::DEG2RAD, -0 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 35, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jRightWrist", 37, Quaternion(Vector3(0, 20 * Math::DEG2RAD, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	
	personMove->addKey("jLeftShoulder", 40, Quaternion(Vector3(40 * Math::DEG2RAD, -220 * Math::DEG2RAD, 25 * Math::DEG2RAD)), person->jLeftShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftElbow", 40, Quaternion(Vector3(45 * Math::DEG2RAD, 0, 0)), person->jLeftElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	//personMove->addKey("jLeftElbow", 40, Quaternion(Vector3(65 * Math::DEG2RAD, 0, 0)), person->jLeftElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 40, Quaternion(Vector3(0, 0, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jLeftWrist", 41, Quaternion(Vector3(-15 * Math::DEG2RAD, -15 * Math::DEG2RAD, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 42, Quaternion(Vector3(0, 0, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 43, Quaternion(Vector3(-15 * Math::DEG2RAD, -15 * Math::DEG2RAD, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 44, Quaternion(Vector3(0, 0, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 45, Quaternion(Vector3(-15 * Math::DEG2RAD, -15 * Math::DEG2RAD, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 46, Quaternion(Vector3(0, 0, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 47, Quaternion(Vector3(-15 * Math::DEG2RAD, -15 * Math::DEG2RAD, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 48, Quaternion(Vector3(0, 0, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 49, Quaternion(Vector3(-15 * Math::DEG2RAD, -15 * Math::DEG2RAD, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftWrist", 50, Quaternion(Vector3(0, 0, 0)), person->jLeftWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	
	personMove->addKey("jNeckBody", 45, Quaternion(Vector3(20 * Math::DEG2RAD, 0 * Math::DEG2RAD, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jNeckBody", 50, Quaternion(Vector3(0, -30 * Math::DEG2RAD, 0)), person->jNeckBody->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	//jump off boat

	personMove->addKey("Body", 58, Quaternion(Vector3(0, 0, 0)), person->body->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	Vector3 moveTo = person->body->getTransform()->getLocalPosition() + Vector3(0, -7, -20);
	personMove->addKey("Body", 64, Quaternion(Vector3(180 * Math::DEG2RAD, 0, 0)), moveTo);// Vector3(0, 0, 0));
	//Vector3 moveThree = person->body->getTransform()->getLocalPosition() + Vector3(0, -15, -20);
	personMove->addKey("Body", 67, Quaternion(Vector3(180 * Math::DEG2RAD, 0, 0)), moveTo+ Vector3(0, -45, -10));// Vector3(0, 0, 0));
	personMove->addKey("Body", 67.0001, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), Vector3(100,100,100));// Vector3(0, 0, 0));

	personMove->addKey("Hat", 0, person->hat->getTransform()->getQuaternion(), person->hat->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("Hat", 67, person->hat->getTransform()->getQuaternion(), person->hat->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("Hat", 67.01, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), (boat->getTransform()->getWorldPosition() + Vector3(0, 0, -20)));//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7

	//straighten legs
	personMove->addKey("jLeftPelvis", 0, Quaternion(Vector3(Math::PI / 11, 0, 0)), person->jPelvisLeft->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jLeftKnee", 0, Quaternion(Vector3(Math::PI / 8, 0, 0)), person->jLeftKnee->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jLeftAnkle", 0, Quaternion(Vector3(Math::PI / 11, 0, 0)), person->jLeftAnkle->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jRightPelvis", 0, Quaternion(Vector3(11 * Math::PI / 6, 0, 0)), person->jPelvisRight->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jRightKnee", 0, Quaternion(Vector3(Math::PI / 6, 0, 0)), person->jRightKnee->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jRightAnkle", 0, Quaternion(Vector3(11 * Math::PI / 6, 0, 0)), person->jRightAnkle->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7

	personMove->addKey("jLeftPelvis", 61, Quaternion(Vector3(Math::PI / 11, 0, 0)), person->jPelvisLeft->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jLeftKnee", 61, Quaternion(Vector3(Math::PI / 8, 0, 0)), person->jLeftKnee->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jLeftAnkle", 61, Quaternion(Vector3(Math::PI / 11, 0, 0)), person->jLeftAnkle->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jRightPelvis", 61, Quaternion(Vector3(11 * Math::PI / 6, 0, 0)), person->jPelvisRight->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jRightKnee", 61, Quaternion(Vector3(Math::PI / 6, 0, 0)), person->jRightKnee->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jRightAnkle", 61, Quaternion(Vector3(11 * Math::PI / 6, 0, 0)), person->jRightAnkle->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7

	personMove->addKey("jLeftShoulder", 61, Quaternion(Vector3(40 * Math::DEG2RAD, -220 * Math::DEG2RAD, 25 * Math::DEG2RAD)), person->jLeftShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftElbow", 61, Quaternion(Vector3(45 * Math::DEG2RAD, 0, 0)), person->jLeftElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightShoulder", 61, Quaternion(Vector3(-30 * Math::DEG2RAD, 20 * Math::DEG2RAD, -0 * Math::DEG2RAD)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightElbow", 61, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 61, Quaternion(Vector3(0, 20 * Math::DEG2RAD, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jRightShoulder", 64, Quaternion(Vector3(0, 0, 0)), person->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightElbow", 62, Quaternion(Vector3(0, 0, 0)), person->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jRightWrist", 64, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftShoulder", 64, Quaternion(Vector3(0, 0, 0)), person->jLeftShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("jLeftElbow", 64, Quaternion(Vector3(0, 0, 0)), person->jLeftElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->addKey("jLeftPelvis", 64, Quaternion(Vector3(0, 0, 0)), person->jPelvisLeft->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jLeftKnee", 64, Quaternion(Vector3(0, 0, 0)), person->jLeftKnee->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jLeftAnkle", 64, Quaternion(Vector3(45 * Math::DEG2RAD, 0, 0)), person->jLeftAnkle->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jRightPelvis", 64, Quaternion(Vector3(0, 0, 0)), person->jPelvisRight->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jRightKnee", 64, Quaternion(Vector3(0, 0, 0)), person->jRightKnee->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	personMove->addKey("jRightAnkle", 64, Quaternion(Vector3(45 * Math::DEG2RAD, 0, 0)), person->jRightAnkle->getTransform()->getLocalPosition());//moveTo + Vector3(0, -45, -10));// Vector3(0, 0, 0));7
	
	//man target shootdown
	target4Move->addKey("TargetJoint", 0, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ4->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target4Move->addKey("TargetJoint", 44, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ4->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target4Move->addKey("TargetJoint", 45, Quaternion(Vector3(0 * Math::DEG2RAD, 0, 0)), targ4->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target6Move->addKey("TargetJoint", 0, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ6->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target6Move->addKey("TargetJoint", 46, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ6->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target6Move->addKey("TargetJoint", 47, Quaternion(Vector3(0 * Math::DEG2RAD, 0, 0)), targ6->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target5Move->addKey("TargetJoint", 0, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ5->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target5Move->addKey("TargetJoint", 48, Quaternion(Vector3(90 * Math::DEG2RAD, 0, 0)), targ5->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	target5Move->addKey("TargetJoint", 49, Quaternion(Vector3(0 * Math::DEG2RAD, 0, 0)), targ5->targetJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	//boat person movements
	boatPersonMove->addKey("jLeftPelvis", 0, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, 20 * Math::DEG2RAD)), boatPerson->jPelvisLeft->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jLeftKnee", 0, Quaternion(Vector3(30 * Math::DEG2RAD, 0 * Math::DEG2RAD, -20 * Math::DEG2RAD)), boatPerson->jLeftKnee->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jLeftAnkle", 0, Quaternion(Vector3(0 * Math::DEG2RAD, 15 * Math::DEG2RAD, 0 * Math::DEG2RAD)), boatPerson->jLeftAnkle->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	boatPersonMove->addKey("jRightPelvis", 0, Quaternion(Vector3(-30 * Math::DEG2RAD, 0, -20 * Math::DEG2RAD)), boatPerson->jPelvisRight->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightKnee", 0, Quaternion(Vector3(30 * Math::DEG2RAD, 0 * Math::DEG2RAD, 20 * Math::DEG2RAD)), boatPerson->jRightKnee->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightAnkle", 0, Quaternion(Vector3( 0 * Math::DEG2RAD, -15 * Math::DEG2RAD, 0 * Math::DEG2RAD)), boatPerson->jRightAnkle->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	
	boatPersonMove->addKey("jRightShoulder", 0, Quaternion(Vector3( -90 * Math::DEG2RAD, 0 * Math::DEG2RAD, 0 * Math::DEG2RAD)), boatPerson->jRightShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jLeftShoulder", 0, Quaternion(Vector3( 0 * Math::DEG2RAD, 0 * Math::DEG2RAD, 20 * Math::DEG2RAD)), boatPerson->jLeftShoulder->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jLeftElbow", 0, Quaternion(Vector3( 0 * Math::DEG2RAD, 0 * Math::DEG2RAD, -40 * Math::DEG2RAD)), boatPerson->jLeftElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	boatPersonMove->addKey("jRightElbow", 0, Quaternion(Vector3(0 * Math::DEG2RAD, 0 * Math::DEG2RAD, 0 * Math::DEG2RAD)), boatPerson->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightElbow", 49, Quaternion(Vector3(0 * Math::DEG2RAD, 0 * Math::DEG2RAD, 0 * Math::DEG2RAD)), boatPerson->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightElbow", 52, Quaternion(Vector3(-70 * Math::DEG2RAD, 0 * Math::DEG2RAD, 0 * Math::DEG2RAD)), boatPerson->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	
	boatPersonMove->addKey("jRightElbow", 52, Quaternion(Vector3(-70 * Math::DEG2RAD, 0 * Math::DEG2RAD, 0 * Math::DEG2RAD)), boatPerson->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	
	boatPersonMove->addKey("jRightWrist", 0, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 52, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 53, Quaternion(Vector3(-15 * Math::DEG2RAD, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 54, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 55, Quaternion(Vector3(-15 * Math::DEG2RAD, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 56, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	
	boatPersonMove->addKey("jRightWrist", 59, Quaternion(Vector3(-15 * Math::DEG2RAD, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 60, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 61, Quaternion(Vector3(-15 * Math::DEG2RAD, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 62, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 63, Quaternion(Vector3(-15 * Math::DEG2RAD, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 64, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 65, Quaternion(Vector3(-15 * Math::DEG2RAD, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 66, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 67, Quaternion(Vector3(-15 * Math::DEG2RAD, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightWrist", 68, Quaternion(Vector3(0, 0, 0)), person->jRightWrist->getTransform()->getLocalPosition());// Vector3(0, 0, 0));


	boatPersonMove->addKey("jRightElbow", 55, Quaternion(Vector3(-70 * Math::DEG2RAD, 0 * Math::DEG2RAD, 0 * Math::DEG2RAD)), boatPerson->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	boatPersonMove->addKey("jRightElbow", 58, Quaternion(Vector3(0 * Math::DEG2RAD, 0 * Math::DEG2RAD, 0 * Math::DEG2RAD)), boatPerson->jRightElbow->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	//gun movements
	personMove->addKey("ChamberJoint", 0, Quaternion(Vector3(0, 0 , 0)), person->gun->chamberJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("ChamberJoint", 36, Quaternion(Vector3(0, 0, 0)), person->gun->chamberJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("ChamberJoint", 37.5, Quaternion(Vector3(0, 0 , 180 * Math::DEG2RAD)), person->gun->chamberJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("ChamberJoint", 39, Quaternion(Vector3(0, 0 , 360 * Math::DEG2RAD)), person->gun->chamberJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	
	personMove->addKey("ChamberArmJoint", 0, Quaternion(Vector3(Math::PI / 2, 0 , 0)), person->gun->chamberArmJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("ChamberArmJoint", 36, Quaternion(Vector3(Math::PI / 2, 0 , 0)), person->gun->chamberArmJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));
	personMove->addKey("ChamberArmJoint", 37, Quaternion(Vector3(Math::PI / 2,-1 *  Math::PI / 3, 0)), person->gun->chamberArmJoint->getTransform()->getLocalPosition());// Vector3(0, 0, 0));

	personMove->play();
	boatPersonMove->play();
	targetMove->play();
	target2Move->play();
	target3Move->play();
	target4Move->play();
	target5Move->play();
	target6Move->play();


	return true;
}