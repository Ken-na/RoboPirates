
#include "Pyramid.h"

using namespace T3D;


Pyramid::Pyramid(float size) {
	// Init vertex and index arrays
	initArrays(4+3*4,	// num vertices
		4,		// num tris
		1);		// num quads

				// Set vertices

	int pos = 0;
	//triangle 1 
	setVertex(pos++, -size, -size, -size);
	setVertex(pos++, -size, -size, size);
	setVertex(pos++, 0, size, 0); //size, 0, or size/2?
	//triangle 2 
	setVertex(pos++, -size, -size, size);
	setVertex(pos++, size, -size, size);
	setVertex(pos++, 0, size, 0); //size, 0, or size/2?
	//triangle 3
	setVertex(pos++, size, -size, size);
	setVertex(pos++, size, -size, -size);
	setVertex(pos++, 0, size, 0); //size, 0, or size/2?
	//triangle 4
	setVertex(pos++, size, -size, -size);
	setVertex(pos++, -size, -size, -size);
	setVertex(pos++, 0, size, 0); //size, 0, or size/2?
	//base
	setVertex(pos++, -size, -size, -size);
	setVertex(pos++, -size, -size, size);
	setVertex(pos++, size, -size, size);
	setVertex(pos++, size, -size, -size);
	/* cube
	//front
	setVertex(pos++, -size, -size, -size);
	setVertex(pos++, size, -size, -size);
	setVertex(pos++, size, size, -size);
	setVertex(pos++, -size, size, -size);
	//back
	setVertex(pos++, -size, -size, size);
	setVertex(pos++, size, -size, size);
	setVertex(pos++, size, size, size);
	setVertex(pos++, -size, size, size);
	//left
	setVertex(pos++, -size, -size, -size);
	setVertex(pos++, -size, size, -size);
	setVertex(pos++, -size, size, size);
	setVertex(pos++, -size, -size, size);
	//right
	setVertex(pos++, size, -size, -size);
	setVertex(pos++, size, size, -size);
	setVertex(pos++, size, size, size);
	setVertex(pos++, size, -size, size);
	//bottom
	setVertex(pos++, -size, -size, -size);
	setVertex(pos++, -size, -size, size);
	setVertex(pos++, size, -size, size);
	setVertex(pos++, size, -size, -size);
	//top
	setVertex(pos++, -size, size, -size);
	setVertex(pos++, -size, size, size);
	setVertex(pos++, size, size, size);
	setVertex(pos++, size, size, -size);
	*/

	// Build quads
	pos = 0;
	//tri 1
	//setFace(pos++, 2, 1, 0);
	setFace(pos++, 0,1,2);
	//tri 2
	setFace(pos++, 3,4,5);
	//tri 3
	//setFace(pos++, 8,7,6);
	setFace(pos++, 6,7,8);
	//tri 4
	setFace(pos++, 9,10,11);
	//base
	//setFace(0, 12,13,14,15);
	setFace(0, 15,14,13,12);

	/*cube
	//front
	setFace(pos++, 3, 2, 1, 0);
	//back
	setFace(pos++, 4, 5, 6, 7);
	//left
	setFace(pos++, 11, 10, 9, 8);
	//right
	setFace(pos++, 12, 13, 14, 15);
	//bottom
	setFace(pos++, 19, 18, 17, 16);
	//top
	setFace(pos++, 20, 21, 22, 23);*/

	// Check vertex and index arrays
	checkArrays();

	// Calculate normals
	calcNormals();
}

Pyramid::~Pyramid(void)
{
	// Mesh delete arrays if they have been created, not need to do anything here
}
