#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"
#include "GLShader.h"

namespace T3D {

	class Tutorial5 :
		public WinGLApplication
	{
	public:
		Tutorial5(void);
		~Tutorial5(void);

		bool init();
		/*public:
		Tutorial1(void);
		~Tutorial1(void);

		bool init();


		private:
		Texture * drawArea;
		DrawTask *drawTask;*/
		GameObject *sphere1;
		GameObject *sphere2;
		GameObject *sphere3;

	};

}
