
#include "Cylinder.h"
#include"Math.h"

using namespace T3D;


Cylinder::Cylinder(double radius, double height, int density) {
	// Init vertex and index arrays
	initArrays((density * 2)+ (density + 1) * 2,	// num vertices
		density * 2,		// num tris
		density);		// num quads

				// Set vertices

	int pos = 0;
	float dTheta = Math::TWO_PI / density;
	float theta = 0;
	for (int i = 0; i<density; i++) {
		theta = i * dTheta;
		float x = radius * cos(theta);
		float z = radius * sin(theta);

		// top vertex
		setVertex(i, x, height, z);

		// bottom vertex
		setVertex(density + i, x, -height, z);
		//printf(density + i+"/n");

		//top centre.
		//setVertex((density * 2) + i, 0, height, 0);
		setVertex((density * 2) + i, x, height, z);
		//bottom centre
		setVertex((density * 3) + i, x, -height, z);
	}
	setVertex(density * 4, 0, height, 0);
	setVertex((density * 4) + 1, 0, -height, 0);
	/* pyramid
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
	*//* cube
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

	for (int i = 0; i<density; i++) {
		setFace(i,   // face id
			i,         // current top vertex
			(i + 1) % density,   // next top vertex (wrapping)
			density + (i + 1) % density, // next bottom vertex (wrapping) 
			density + i        // current bottom vertex			
		);
		//cap' (triangle)
		//setVertex(density * 2, 0, height, 0);
		setFace(i, 			
			density*4,//(density * 2)+i
			(density * 2) + (i + 1) % density,
			(density * 2) + i
		);
		//bottom cap
		setFace(density+i,
			(density * 3) + i,			
			(density * 3) + (i + 1) % density,
			(density * 4) + 1//(density * 2)+i
		);
	}
	
		

	// Build quads
	//pos = 0;
	/*pyramid
	//tri 1
	//setFace(pos++, 2, 1, 0);
	setFace(pos++, 0, 1, 2);
	//tri 2
	setFace(pos++, 3, 4, 5);
	//tri 3
	//setFace(pos++, 8,7,6);
	setFace(pos++, 6, 7, 8);
	//tri 4
	setFace(pos++, 9, 10, 11);
	//base
	//does not render but ill come back to that
	setFace(pos++, 12, 13, 14, 15);
	//setFace(pos++, 15,14,13,12);
	*/
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

Cylinder::~Cylinder(void)
{
	// Mesh delete arrays if they have been created, not need to do anything here
}
