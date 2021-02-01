#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"

#include "gameobject.h"
#include "CompositeGun.h"

namespace T3D {

	class Person : public GameObject
	{
	public:
		Person(T3DApplication *app);
		~Person(void);

		bool init();

		GameObject *sphere;

		GameObject *jSpineBody;
		GameObject *jSpinePelvis;
		GameObject *jPelvisRight;
		GameObject *jPelvisLeft;
		GameObject *jRightKnee;
		GameObject *jRightAnkle;
		GameObject *jLeftKnee;
		GameObject *jLeftAnkle;

		GameObject *jNeckBody;
		GameObject *jNeckHead;


		GameObject *jRightShoulder;
		GameObject *jRightElbow;
		GameObject *jRightWrist;
		GameObject *jRightFingerBase;
		GameObject *jRightFingerMid;

		GameObject *jLeftShoulder;
		GameObject *jLeftElbow;
		GameObject *jLeftWrist;

		GameObject *body;
		GameObject *spine;
		GameObject *pelvis;

		GameObject *upperBody;
		GameObject *neck;
		GameObject *head;

		GameObject *rightUpArm;
		GameObject *rightBotArm;
		GameObject *rightHand;
		GameObject *rightPFingerStart;
		GameObject *rightPFingerEnd;

		GameObject *leftUpArm;
		GameObject *leftBotArm;
		GameObject *leftHand;
		GameObject *leftPFingerStart;
		GameObject *leftPFingerEnd;

		GameObject *rightUpLeg;
		GameObject *rightBotLeg;
		GameObject *rightFoot;

		GameObject *leftUpLeg;
		GameObject *leftBotLeg;
		GameObject *leftFoot;

		CompositeGun *gun;

		GameObject *hat;
	};

}