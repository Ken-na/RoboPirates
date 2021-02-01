
#include "HoleInTheWall.h"
#include "Math.h"

//Only works with even density, i appologise for how spaghetti some of this code gets. 
	//but it does work ! 
		//and that's what matters ;)
			//and i dont think the assignment spec says anything about "ODD" numbers, who would even use those yucky numbers ....
namespace T3D
{
	HoleInTheWall::HoleInTheWall(
		Vector3 wallSize,
		float holeX,
		float holeY,
		float radius,
		int density)
	{
		initArrays(4 * 6 + density + (density * 2) + (density + 1) * 2,	// num vertices
			density * 2 + 8,		// num tris // was *2
			density + 4);		// num quads //the number of quads is making it mad, when i add 6 it yells. 


		//HOLE SET VERTICES		
		int pos = 0;
		float dTheta = Math::TWO_PI / density;
		float theta = 0;
		for (int i = 0; i < density; i++) {
			theta = i * dTheta;
			float x = radius * cos(theta) + holeX;
			float y = radius * sin(theta) + holeY;
			// front vertex
			setVertex(i, x, y, wallSize.z);
			// back vertex
			setVertex(density + i, x, y, 0);
			//double front
			setVertex(density * 2 + i, x, y, wallSize.z);
			//double back
			setVertex(density * 3 + i, x, y, 0);
		}		
		//HOLE SET FACES
		for (int i = 0; i < density; i++) {
			setFace(i,   // face id
				i,         // current top vertex
				(i + 1) % density,   // next top vertex (wrapping)
				density + (i + 1) % density, // next bottom vertex (wrapping) 
				density + i        // current bottom vertex			
			);
		}
		// WALL: Set vertices
		pos = density*4;
		//Front
		//the comments correlate each vertex with a number in my diagram, ignore em if ya want. 
		setVertex(pos++, 0, wallSize.y, wallSize.z); //3
		setVertex(pos++, wallSize.x, wallSize.y, wallSize.z);//2
		setVertex(pos++, wallSize.x, 0, wallSize.z);//6
		setVertex(pos++, 0, 0, wallSize.z);//7
		//back
		setVertex(pos++, 0, wallSize.y, 0); //0
		setVertex(pos++, wallSize.x, wallSize.y, 0); //1
		setVertex(pos++, wallSize.x, 0, 0); //5
		setVertex(pos++, 0, 0, 0);//4
		//left
		setVertex(pos++, 0, wallSize.y, wallSize.z); //3
		setVertex(pos++, 0, wallSize.y, 0); //0		
		setVertex(pos++, 0, 0, 0);//4 
		setVertex(pos++, 0, 0, wallSize.z);//7
		//right
		setVertex(pos++, wallSize.x, wallSize.y, wallSize.z);//2
		setVertex(pos++, wallSize.x, wallSize.y, 0); //1
		setVertex(pos++, wallSize.x, 0, 0); //5
		setVertex(pos++, wallSize.x, 0, wallSize.z);//6
		//bottom
		setVertex(pos++, wallSize.x, 0, wallSize.z);//6
		setVertex(pos++, wallSize.x, 0, 0); //5		
		setVertex(pos++, 0, 0, 0);//4		
		setVertex(pos++, 0, 0, wallSize.z);//7
		//top
		setVertex(pos++, 0, wallSize.y, 0); //0
		setVertex(pos++, wallSize.x, wallSize.y, 0); //1
		setVertex(pos++, wallSize.x, wallSize.y, wallSize.z);//2
		setVertex(pos++, 0, wallSize.y, wallSize.z);//3
		//front face doubled
		setVertex(pos++, 0, 0, wallSize.z);//7
		setVertex(pos++, wallSize.x, 0, wallSize.z);//6
		setVertex(pos++, wallSize.x, wallSize.y, wallSize.z);//2 
		setVertex(pos++, 0, wallSize.y, wallSize.z); //3		
		//back face doubled		
		setVertex(pos++, wallSize.x, 0, 0); //5		
		setVertex(pos++, 0, 0, 0);//4
		setVertex(pos++, 0, wallSize.y, 0); //0
		setVertex(pos++, wallSize.x, wallSize.y, 0); //1
		//WALL: Set quad faces
		pos = density;
		int place = density * 4;
		//front
		//setFace(pos++, 3, 2, 1, 0);
		//back
		//setFace(pos++, 4, 5, 6, 7);
		//left
		setFace(pos++, place + 8, place + 9, place + 10, place + 11);
		//right
		setFace(pos++, place + 15, place + 14, place + 13, place + 12);
		//bottom
		setFace(pos++, place + 19, place + 18, place + 17, place + 16);
		//top
		setFace(pos++, place + 23, place + 22, place + 21, place + 20);
		//pos++;*/
		pos = 0;
		//printf("\n");
		//Connect the hole to the wall
			//for the comments there's an "xyz" indicating what "section" the vertex is in for example, X is more than, 0 is less that, = is equal. 
		for (int i = 0; i < (density * 2); i++) {
			//printf(" Start-");
			if (getVertex(i).x > holeX) {
				//printf(" x > -");
				if (getVertex(i).y > holeY) {
					//printf(" y > ");
					if (getVertex(i).z > 0) {
						//printf(" z > ");
						//xyz
						setFace(pos++,
							density * 4 + 1,
							(density * 2) + i + 1,
							(density * 2) + i
						);
					}
					else {
						//xy0
						setFace(pos++,
							(density * 2) + i,
							(density * 2) + i + 1,
							density * 4 + 5
						);
					}
				}
				else if (getVertex(i).y < holeY){ // y is less
					//printf(" y < -");
					if (getVertex(i).z > 0) {
						//printf(" z > ");
						//x0z
						//this section has the possibility of wrapping to the other layer, therefore i will put a check to connect it back to vertice 0 if needed.
						if (i == density - 1) {
							setFace(pos++,
								density * 4 + 2,
								(density * 2),
								(density * 2) + i
							);
						}
						else {
							setFace(pos++,
								density * 4 + 2,
								(density * 2) + i + 1,
								(density * 2) + i
							);
						}
					}
					else {
						//x00
						if (i == density * 2 - 1) {
							setFace(pos++,
								(density * 2) + i,
								(density * 3), 
								density * 4 + 6
							);
						}
						else {
							setFace(pos++,
								(density * 2) + i,
								(density * 2) + i + 1, 
								density * 4 + 6
							);
						}												
					}
				}
				else { //y is =
					//printf(" y = -");
					if (getVertex(i).z > 0) {
						//x=z
						setFace(pos++,
							density * 4 + 1,
							(density * 2) + i + 1,
							(density * 2) + i
						);
						setFace(pos++,
							density * 4 + 2,
							density * 4 + 1,
							(density * 2) + i
						);
					}
					else {
						//x=0
						setFace(pos++,
							(density * 2) + i,
							(density * 2) + i + 1,
							density * 4 + 5
						);
						setFace(pos++,
							density * 4 + 5,
							density * 4 + 6,
							(density * 2) + i
						);
					}
				}
			}
			else if (getVertex(i).x < holeX) { //less x 
				//printf(" x < -");
				if (std::abs(getVertex(i).y - holeY) < .001) { // y is =
					//printf(" y = -");
					if (getVertex(i).z > 0) {
						//printf(" z > ");
						//0=z
						setFace(pos++,
							density * 4 + 3,
							(density * 2) + i + 1,
							(density * 2) + i
						);
						setFace(pos++,
							density * 4 + 0,
							density * 4 + 3,
							(density * 2) + i
						);
					}
					else {
						setFace(pos++,
							(density * 2) + i,
							(density * 2) + i + 1,
							density * 4 + 7
						);
						setFace(pos++,
							density * 4 + 7,
							density * 4 + 4,
							(density * 2) + i
						);
					}
				}
				else if (getVertex(i).y > holeY) {
					//printf(" y > -");
					if (getVertex(i).z > 0) {
						//printf(" z > ");
						//0yz
						setFace(pos++,
							density * 4 + 0,
							(density * 2) + i + 1,
							(density * 2) + i
							
						);
					}			
					else {
						//0y0
						setFace(pos++,
							(density * 2) + i,
							(density * 2) + i + 1,
							density * 4 + 4
						);
					}
				}
				else if(getVertex(i).y < holeY){
					//printf(" y < -");
					if (getVertex(i).z > 0) {
						//printf(" z > ");
						//00z
						setFace(pos++,
							density * 4 + 3,
							(density * 2) + i + 1,
							(density * 2) + i
						);
					}
					else{
						//000
						setFace(pos++,
							(density * 2) + i,
							(density * 2) + i + 1,
							density * 4 + 7
						);
					}
				}
			}
			else { // x is = 
			//printf(" x = -");
				if (getVertex(i).y > holeY) {
					//printf(" y > -");
					if (getVertex(i).z > 0) {
						//printf(" z > ");
						//=yz
						setFace(pos++,
							density * 4 + 0,
							(density * 2) + i + 1,
							(density * 2) + i
						);
						setFace(pos++,
							density * 4 + 1,
							density * 4 + 0,
							(density * 2) + i
						);
					}
					else {
						//=y0
						setFace(pos++,
							(density * 2) + i,
							(density * 2) + i + 1,
							density * 4 + 4
						);
						setFace(pos++,
							density * 4 + 4,
							density * 4 + 5,
							(density * 2) + i
						);
					}
				}
				else if (getVertex(i).y < holeY) {
					//printf(" y < -");
					if (getVertex(i).z > 0) {
						//=0z
						setFace(pos++,
							density * 4 + 2,
							(density * 2) + i + 1,
							(density * 2) + i
						);
						setFace(pos++,
							density * 4 + 3,
							density * 4 + 2,
							(density * 2) + i
						);
					}
					else {
						//=00
						setFace(pos++,
							(density * 2) + i,
							(density * 2) + i + 1,
							density * 4 + 6
						);

						setFace(pos++,
							density * 4 + 6,
							density * 4 + 7,
							(density * 2) + i
						);
					}
				}
			}
			//printf(" @ %d @ X %f, Y %f, Z %f\n",i, getVertex(i).x, getVertex(i).y, getVertex(i).z);
		}
		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();
	}


	HoleInTheWall::~HoleInTheWall(void)
	{
		// Mesh delete arrays if they have been created, not need to do anything here
	}
}
