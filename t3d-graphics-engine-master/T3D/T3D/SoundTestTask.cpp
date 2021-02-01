// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// SoundTestTask.cpp
//
// Class to manage test the sound system

#include "SoundTestTask.h"
#include "Input.h"

namespace T3D{

	SoundTestTask::SoundTestTask(T3DApplication *app) : Task(app)
	{
		music = app->soundManager->createMusic("Resources/PirateMusic.mp3");
		sound = app->soundManager->createSound("Resources/Shot.wav");
		elapsedTime = 0;
	}


	SoundTestTask::~SoundTestTask(void)
	{
	}

	void SoundTestTask::update(float dt){
		elapsedTime += dt;
		if (elapsedTime > 18 && elapsedTime < 18.1){
			sound->play();
		}else if(elapsedTime > 21 && elapsedTime < 21.1) {
			sound->play();
		}
		else if (elapsedTime > 27 && elapsedTime < 27.1) {
			sound->play();
		}
		
		else if (elapsedTime > 44 && elapsedTime < 44.1) {
			sound->play();
		}
		else if (elapsedTime > 46 && elapsedTime < 46.1) {
			sound->play();
		}
		else if (elapsedTime > 48 && elapsedTime < 48.1) {
			sound->play();
		}
		/*else if (elapsedTime > 50 && elapsedTime < 50.1) {
			sound->play();
		}
		else if (elapsedTime > 54 && elapsedTime < 54.1) {
			sound->play();
		}*/
		/*else if (elapsedTime > 56 && elapsedTime < 56.1) {
			sound->play();
		}*/
		else if (elapsedTime > 58 && elapsedTime < 58.1) {
			sound->play();
		}
		else if (elapsedTime > 60 && elapsedTime < 60.1) {
			sound->play();
		}
		/*else if (elapsedTime > 62 && elapsedTime < 62.1) {
			sound->play();
		}
		else if (elapsedTime > 64 && elapsedTime < 64.1) {
			sound->play();
		}*/

		music->play();
		
	}

}
