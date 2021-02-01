#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"

#include "gameobject.h"

namespace T3D {

	class CompositeGun : public GameObject
	{
	public:
		CompositeGun(T3DApplication *app);
		~CompositeGun(void);

		bool init();

		GameObject *trigger;
		GameObject *lowerBody;
		GameObject *middleBody;
		GameObject *upperBody;
		GameObject *frontBody;
		GameObject *chamber;
		GameObject *chamberArm;
		GameObject *barrel;
		GameObject *bullet;
		GameObject *lever;
		GameObject *triggerGuardFront;
		GameObject *triggerGuardBack;
		GameObject *ironSight;


		GameObject *chamberArmJoint;
		GameObject *chamberJoint;
		GameObject *triggerJoint;
		GameObject *leverJoint;
		GameObject *handleJoint; //where gripping would occur, allows the gun to move independant of the target. 

		GameObject *target;
		GameObject *targetStand;

		GameObject *targetJoint;

		GameObject *nuHandle;
	};

}