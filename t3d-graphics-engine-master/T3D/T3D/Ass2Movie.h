#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"
//tut 6 =<
#include "AnimationTest.h"
#include "LookAtBehaviour.h"
#include "LampBehaviour.h"
#include "Animation.h"

#include "Task2Comp.h"
#include "GLShader.h"

namespace T3D {

	class Ass2Movie :
		public WinGLApplication
	{
	public:
		Ass2Movie(void);
		~Ass2Movie(void);

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