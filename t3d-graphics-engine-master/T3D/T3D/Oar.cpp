#include "Oar.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Material.h"
#include "Cylinder.h"

namespace T3D
{
	Oar::Oar()
	{
		/*
		// Init vertex and index arrays
		initArrays(4 * 6,	// num vertices
			0,		// num tris
			6);		// num quads

 // Set vertices

		int pos = 0;
		//front
		setVertex(pos++, -w, -h, -w);
		setVertex(pos++, w, -h, -w);
		setVertex(pos++, w, h, -w);
		setVertex(pos++, -w, h, -w);
		//back
		setVertex(pos++, -w, -h, w);
		setVertex(pos++, w, -h, w);
		setVertex(pos++, w, h, w);
		setVertex(pos++, -w, h, w);
		//left
		setVertex(pos++, -w, -h, -w);
		setVertex(pos++, -w, h, -w);
		setVertex(pos++, -w, h, w);
		setVertex(pos++, -w, -h, w);
		//right
		setVertex(pos++, w, -h, -w);
		setVertex(pos++, w, h, -w);
		setVertex(pos++, w, h, w);
		setVertex(pos++, w, -h, w);
		//bottom
		setVertex(pos++, -w, -h, -w);
		setVertex(pos++, -w, -h, w);
		setVertex(pos++, w, -h, w);
		setVertex(pos++, w, -h, -w);
		//top
		setVertex(pos++, -w, h, -w);
		setVertex(pos++, -w, h, w);
		setVertex(pos++, w, h, w);
		setVertex(pos++, w, h, -w);

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

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();

		// Setup other arrays		
		pos = 0;
		//front
		for (int i = 0; i < 4; i++) {
			colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		}
		//back
		for (int i = 0; i < 4; i++) {
			colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
		}
		//left
		for (int i = 0; i < 4; i++) {
			colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 1;
		}
		//right
		for (int i = 0; i < 4; i++) {
			colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 1;
		}
		//bottom
		for (int i = 0; i < 4; i++) {
			colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 1;
		}
		//top
		for (int i = 0; i < 4; i++) {
			colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 1;
		}

		//uvs
		pos = 0;
		for (int f = 0; f < 6; f++) {
			uvs[pos++] = 0; uvs[pos++] = 0;
			uvs[pos++] = 0; uvs[pos++] = 1;
			uvs[pos++] = 1; uvs[pos++] = 1;
			uvs[pos++] = 1; uvs[pos++] = 0;
		}*/
		/*stick = new GameObject(this);
		stick->setMesh(new Cylinder(10, 10, 5));
		stick->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
		//stick->getTransform()->setParent(getTransform());
		stick->getTransform()->name = "Stick";*/
	}


	Oar::~Oar(void)
	{
		// Mesh delete arrays if they have been created, not need to do anything here
	}
}
/*

Oar::Oar(T3DApplication *app) :GameObject(app) {

	

	//2.
	stick = new GameObject(app);
	stick->setMesh(new Cylinder(10, 10, 5));
	stick->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
	stick->getTransform()->setParent(getTransform());
	stick->getTransform()->name = "Stick";

}


Oar::~Oar(void)
{

}
bool Oar::init() {


	return true;
}*/