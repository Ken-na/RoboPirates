#pragma once
#include "winglapplication.h"
#include "Texture.h"
#include "DrawTask.h"
#include "GLShader.h"

#include "Animation.h"

namespace T3D {

	class Ass2Shader :
		public WinGLApplication
	{
	public:
		Ass2Shader(void);
		~Ass2Shader(void);

		bool init();
		/*public:
		Tutorial1(void);
		~Tutorial1(void);

		bool init();


		private:
		Texture * drawArea;
		DrawTask *drawTask;*/
		GameObject *mount1;
		GameObject *mount2;
		GameObject *mount3;

	};

}
