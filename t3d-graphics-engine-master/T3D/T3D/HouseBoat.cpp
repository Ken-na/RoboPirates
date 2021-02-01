
#include "HouseBoat.h"



namespace T3D
{
	HouseBoat::HouseBoat(float size)
	{
		// Init vertex and index arrays
		initArrays(4 * 7 + 2*3 + 4*6,	// num vertices
			2,		// num tris
			7 + 6);		// num quads

					// Set vertices

		int pos = 0;
		int uvpos = 0;
		//front (door)
		setVertex(pos++, -size, -size, -size);
		setVertex(pos++, size, -size, -size);
		setVertex(pos++, size, size, -size);
		setVertex(pos++, -size, size, -size);
		setUV(uvpos++, 1, 0.5);
		setUV(uvpos++, .5, 0.5);
		setUV(uvpos++, .5, 0);
		setUV(uvpos++, 1, 0);
		//back
		setVertex(pos++, -size, -size, size);
		setVertex(pos++, size, -size, size);
		setVertex(pos++, size, size, size);
		setVertex(pos++, -size, size, size);
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.5, 0);
		setUV(uvpos++, 0.5, 0.5);
		setUV(uvpos++, 0, 0.5);
		//left
		setVertex(pos++, -size, -size, -size);
		setVertex(pos++, -size, size, -size);
		setVertex(pos++, -size, size, size);
		setVertex(pos++, -size, -size, size);
		setUV(uvpos++, 0, 1);
		setUV(uvpos++, 0, 0.5);
		setUV(uvpos++, 0.5, .5);
		setUV(uvpos++, 0.5, 1);
		//right
		setVertex(pos++, size, -size, -size);
		setVertex(pos++, size, size, -size);
		setVertex(pos++, size, size, size);
		setVertex(pos++, size, -size, size);
		setUV(uvpos++, 0, 1);
		setUV(uvpos++, 0, 0.5);
		setUV(uvpos++, 0.5, .5);
		setUV(uvpos++, 0.5, 1);
		//bottom
		setVertex(pos++, -size, -size, -size);
		setVertex(pos++, -size, -size, size);
		setVertex(pos++, size, -size, size);
		setVertex(pos++, size, -size, -size);
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.5, 0);
		setUV(uvpos++, 0.5, 0.5);
		setUV(uvpos++, 0, 0.5);
		//top 1
		setVertex(pos++, -size, size, -size);
		setVertex(pos++, -size, size, size);
		setVertex(pos++, 0, size*1.3, size);
		setVertex(pos++, 0, size*1.3, -size);
		setUV(uvpos++, 1, 1);
		setUV(uvpos++, .5, 1);
		setUV(uvpos++, .5, .5);
		setUV(uvpos++, 1, .5);
		//top 2
		setVertex(pos++, 0, size*1.3, -size);
		setVertex(pos++, 0, size*1.3, size);
		setVertex(pos++, size, size, size);
		setVertex(pos++, size, size, -size);
		
		setUV(uvpos++, .5, .5);
		setUV(uvpos++, 1, .5);
		setUV(uvpos++, 1, 1);
		setUV(uvpos++, .5, 1);
		//toptri1
		setVertex(pos++, 0, size*1.3, -size);
		setVertex(pos++, size, size, -size);
		setVertex(pos++, -size, size, -size);
		setUV(uvpos++, .75, .5);
		setUV(uvpos++, 1, 1);
		setUV(uvpos++, .5, 1);
		//toptri2
		setVertex(pos++, 0, size*1.3, size);
		setVertex(pos++, size, size, size);
		setVertex(pos++, -size, size, size);
		setUV(uvpos++, .75, .5);
		setUV(uvpos++, 1, 1);
		setUV(uvpos++, .5, 1);

		
		//boat top
		setVertex(pos++, -size * 2, -size, -size * 3);
		setVertex(pos++, -size * 2, -size, size * 2);
		setVertex(pos++, size * 2, -size, size * 2);
		setVertex(pos++, size * 2, -size, -size * 3);
		setUV(uvpos++, 0, 0.5);
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.5, 0);
		setUV(uvpos++, 0.5, 0.5);
		//boat bot
		setVertex(pos++, -size * 2, -size*1.3, -size * 3);
		setVertex(pos++, -size * 2, -size * 1.3, size * 2);
		setVertex(pos++, size * 2, -size * 1.3, size * 2);
		setVertex(pos++, size * 2, -size * 1.3, -size * 3);
		setUV(uvpos++, 0, 0.5);
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.5, 0);
		setUV(uvpos++, 0.5, 0.5);
		//boat left
		setVertex(pos++, -size * 2, -size * 1.3, -size * 3);
		setVertex(pos++, -size * 2, -size, -size * 3);
		setVertex(pos++, -size * 2, -size, size * 2);
		setVertex(pos++, -size * 2, -size * 1.3, size * 2);
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.15, 0);
		setUV(uvpos++, 0.15, 0.5);
		setUV(uvpos++, 0, 0.5);

		//boat right
		setVertex(pos++, size * 2, -size * 1.3, -size * 3);
		setVertex(pos++, size * 2, -size, -size * 3);
		setVertex(pos++, size * 2, -size, size * 2);
		setVertex(pos++, size * 2, -size * 1.3, size * 2);
		
		setUV(uvpos++, 0.15, 0.5);
		setUV(uvpos++, 0, 0.5);
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.15, 0);
		//boat front
		setVertex(pos++, -size * 2, -size * 1.3, -size * 3);
		setVertex(pos++, size * 2, -size * 1.3, -size * 3);
		setVertex(pos++, size * 2, -size, -size * 3);
		setVertex(pos++, -size * 2, -size, -size * 3);
		
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.5, 0);
		setUV(uvpos++, 0.5, 0.25);
		setUV(uvpos++, 0, 0.25);
		//boat back
		setVertex(pos++, -size * 2, -size * 1.3, size * 2);
		setVertex(pos++, size * 2, -size * 1.3, size * 2);
		setVertex(pos++, size * 2, -size, size * 2);
		setVertex(pos++, -size * 2, -size, size * 2);
		
		setUV(uvpos++, 0.5, 0.25);
		setUV(uvpos++, 0, 0.25);
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.5, 0);

		// Build quads
		pos = 0;
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
		setFace(pos++, 20, 21, 22, 23);
		//top2
		setFace(pos++, 24, 25, 26, 27);
		//boat top
		setFace(pos++, 34, 35, 36, 37);
		//boat bot
		setFace(pos++, 41, 40, 39, 38);
		//boat right
		//setFace(pos++, 42, 43, 44, 45);
		setFace(pos++, 45, 44, 43, 42);
		//boat left
	//	setFace(pos++, 49, 48, 47, 46);
		setFace(pos++, 46, 47, 48, 49);
		//front
		setFace(pos++, 53, 52, 51, 50);
		//back
		setFace(pos++, 54, 55, 56, 57);
		//toptri 1,2
		pos = 0;
		setFace(pos++, 28, 29, 30);		
		setFace(pos++, 33, 32, 31);


		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();

		/*
		// Setup other arrays		
		pos = 0;
		//front
		for (int i = 0; i<4; i++) {
			colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		}
		//back
		for (int i = 0; i<4; i++) {
			colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		}
		//left
		for (int i = 0; i<4; i++) {
			colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 1;
		}
		//right
		for (int i = 0; i<4; i++) {
			colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 1;
		}
		//bottom
		for (int i = 0; i<4; i++) {
			colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 1;
		}
		//top
		for (int i = 0; i<4; i++) {
			colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 1;
		}
	/*
		//uvs
		pos = 0;
		for (int f = 0; f<6; f++) {
			uvs[pos++] = 0; uvs[pos++] = 0;
			uvs[pos++] = 0; uvs[pos++] = 1;
			uvs[pos++] = 1; uvs[pos++] = 1;
			uvs[pos++] = 1; uvs[pos++] = 0;
		}*/
	}


	HouseBoat::~HouseBoat(void)
	{
		// Mesh delete arrays if they have been created, not need to do anything here
	}
}
