// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// main.cpp
//
// Main entry point. Creates and runs a T3DApplication

#include "T3DTest.h"
#include "Tutorial1.h"
#include "Tutorial4.h"
#include "Tutorial5.h"
#include "Tutorial6.h"
#include "Assignment1Test.h"
#include "Lamp.h"
#include "ShaderTest.h"
#include "GLTestApplication.h"

#include "Ass2Shader.h"
#include "Ass2Movie.h"


#ifdef main
#undef main
#endif


using namespace T3D;

int main(int argc, char* argv[]){
	
	//ASSIGNMENT 2!!!!!!

	//THIS IS THE CLEAR COMMENT ABOUT THE SHADER
	//T3DApplication *theApp = new Ass2Shader();

	//THIS IS THE CLEAR COMMENT ABOUT THE MOVIE
	T3DApplication *theApp = new Ass2Movie();

	theApp->run();
	delete theApp;

	return 0;
}