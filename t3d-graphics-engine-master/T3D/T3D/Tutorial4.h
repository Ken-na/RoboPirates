#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"
//tut 6 =<
#include "AnimationTest.h"
#include "LookAtBehaviour.h"
#include "LampBehaviour.h"
#include "Animation.h"

namespace T3D {

	class Tutorial4 :
		public WinGLApplication		
	{
	public:
		Tutorial4(void);
		~Tutorial4(void);

		bool init();
	/*public:
		Tutorial1(void);
		~Tutorial1(void);

		bool init();


	private:
		Texture * drawArea;
		DrawTask *drawTask;*/
	};

}