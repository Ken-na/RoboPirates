
#include "TCylinder.h"
#include"Math.h"

using namespace T3D;


TCylinder::TCylinder(double radius, double height, int density) {
	// Init vertex and index arrays
	initArrays(4 * density + 2, //(density * 2) + (density + 1) * 2,	// num vertices //throws error that is fixed by switching between + 5 and 2.
		density * 2,		// num tris
		density);		// num quads

						// Set vertices

	int pos = 0;
	float dTheta = Math::TWO_PI / density;
	float theta = 0;
	int dp1 = density + 1;
	for (int i = 0; i<=density; i++) {
		float theta = float(i) / density * Math::TWO_PI;
		theta = i * dTheta;
		float x = radius * cos(theta);
		float z = radius * sin(theta);
		// top vertex
		setVertex(i, x, height, z);
		setUV(i, float(i) / density, 0);
		// bottom vertex
		setVertex(dp1 + i, x, -height, z);
		setUV(dp1 + i, float(i) / density, .6);
		//top vertex copy
		setVertex(2 * dp1 + i, x, height, z);
		//setUV(2 * dp1 + i, x, z);
		//setUV(2 * dp1 + i, (x*.1), (z*.1));
		setUV(2 * dp1 + i, float(i) / density, 0);
		//bottom vertex copy
		setVertex(3 * dp1 + i, x, -height, z);
		//setUV(3 * dp1 + i, x, z);
		setUV(3 * dp1 + i, float(i) / density, .6);
		/*setVertex(i, radius*cos(theta), height, radius*sin(theta));
		setVertex((density + 1) + i, radius*cos(theta), -height, radius*sin(theta));
		
		/*theta = i * dTheta;
		float x = radius * cos(theta);
		float z = radius * sin(theta);

		// top vertex
		setVertex(i, x, height, z);

		// bottom vertex
		setVertex(density + i, x, -height, z);
		//printf(density + i+"/n");
		/**//*
		//top centre.
		//setVertex((density * 2) + i, 0, height, 0);
		setVertex((density * 2) + i, x, height, radius * sin(theta));
		//bottom centre
		setVertex((density * 3) + i, radius*cos(theta), -height, radius * sin(theta));*/
	}
	setVertex(4*dp1, 0, height, 0);
	//setUV(4 * dp1, float(i) / density, .6);
	setVertex((4 * dp1) + 1, 0, -height, 0);


	for (int i = 0; i<density; i++) {
		//been change
		setFace(i,   // face id
			i,         // current top vertex
			i + 1,   // next top vertex (wrapping)
			dp1 + i + 1, // next bottom vertex (wrapping) 
			dp1 + i        // current bottom vertex			
		);
		//cap' (triangle)
		//setVertex(density * 2, 0, height, 0);
		setFace(i,
			dp1 * 4,//(density * 2)+i
			(dp1 * 2) + i + 1,
			(dp1 * 2) + i
		);
		//bottom cap
		setFace(density + i,
			(dp1 * 3) + i,
			(dp1 * 3) + i+1,
			(dp1 * 4) + 1//(density * 2)+i
		);
	}


	// Check vertex and index arrays
	checkArrays();

	// Calculate normals
	calcNormals();
}

TCylinder::~TCylinder(void)
{
	// Mesh delete arrays if they have been created, not need to do anything here
}
