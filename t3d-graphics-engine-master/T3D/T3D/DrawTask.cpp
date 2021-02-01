// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// GameObject.cpp
//
// Simple task for drawing to and animating textures, used in tutorial 1 for practice implementing drawing routines

#include <math.h>
#include "DrawTask.h"

namespace T3D {

	DrawTask::DrawTask(T3DApplication *app, Texture* tex) : Task(app)
	{
		drawArea = tex;
		//Create some member variables for the vertices of your polygon and initialise them in the constructor.
		/*int polygon[4][2];
		polygon[0][0] = 300;
		polygon[0][1] = 300;
		polygon[1][0] = 300;
		polygon[1][1] = 600;

		polygon[2][0] = 600;
		polygon[2][1] = 600;
		polygon[3][0] = 600;
		polygon[3][1] = 300;*/

		//line
		line[0].x = 100;
		line[0].y = 150; 
		line[1].x = 200;
		line[1].y = 150;
		//Vector3 poly[4];
		poly[0].x = 300;
		poly[0].y = 300;
		poly[1].x = 300;
		poly[1].y = 600;
		poly[2].x = 600;
		poly[2].y = 600;
		poly[3].x = 600;
		poly[3].y = 300;
		poly[4].x = 300;
		poly[4].y = 300;

		polyDup[0].x = 100;
		polyDup[0].y = 100;
		polyDup[1].x = 100;
		polyDup[1].y = 200;
		polyDup[2].x = 200;
		polyDup[2].y = 200;
		polyDup[3].x = 200;
		polyDup[3].y = 100;
		polyDup[4].x = 100;
		polyDup[4].y = 100;

		polyDup2[0].x = 100;
		polyDup2[0].y = 100;
		polyDup2[1].x = 100;
		polyDup2[1].y = 200;
		polyDup2[2].x = 200;
		polyDup2[2].y = 200;
		polyDup2[3].x = 200;
		polyDup2[3].y = 100;
		polyDup2[4].x = 100;
		polyDup2[4].y = 100;

		stlOffset.x = 200;
		stlOffset.y = 200;
		stlOffset.z = 1;

		/*stlPoints[0].x = 0;
		stlPoints[0].y = 0;
		stlPoints[0].z = 1;

		stlPoints[1].x = 100;
		stlPoints[1].y = 0;
		stlPoints[1].z = 1;

		stlPoints[2].x = 100;
		stlPoints[2].y = 10;
		stlPoints[2].z = 1;

		stlPoints[3].x = 0;
		stlPoints[3].y = 10;
		stlPoints[3].z = 1;*/

		



		for (int i = 0;i < 5;i++) {
			poly[i].z = 1; //assuming that z is used instead of w for homo coords
			polyDup[i].z = 1;

			for (int j = 0;j < 3;j++) {
				for (int h = 0; h < 3;h++) {
					poly2[i][j][h] = 0;
				}
			}
			

		}

		//translation matrix
		poly2[0][0][0] = 1;
		poly2[0][1][1] = 1;
		poly2[0][2][0] = -.01;//100;
		poly2[0][2][1] = 0;//100;
		poly2[0][2][2] = 1;

		//rotation matrix uhhh spinning around point 0,0
		//.001 in all values worked well for square, trying higher for vector lines.
		poly2[1][0][0] = cos(.001);
		poly2[1][0][1] = sin(.001);
		poly2[1][1][0] = -sin(.001);
		poly2[1][1][1] = cos(.001);
		poly2[1][2][0] = 0;
		poly2[1][2][1] = 0;
		poly2[1][2][2] = 1;

		//translation matrix
		poly2[2][0][0] = 1.;
		poly2[2][1][1] = 1.01;
		poly2[2][2][2] = 1;

		//rotation translatiob  1
		poly2[3][0][0] = 1;
		poly2[3][1][1] = 1;
		poly2[3][2][0] = 150;//100;
		poly2[3][2][1] = 150;//100;
		poly2[3][2][2] = 1;
		//rotation translatiob  2
		poly2[4][0][0] = 1;
		poly2[4][1][1] = 1;
		poly2[4][2][0] = -150;//100;
		poly2[4][2][1] = -150;//100;
		poly2[4][2][2] = 1;

		stlPoints[0].x = 100;
		stlPoints[0].y = 0;
		stlPoints[0].z = 1;

		stlPoints[1].x = 100;
		stlPoints[1].y = 100;
		stlPoints[1].z = 1;

		stlPoints[2].x = 0;
		stlPoints[2].y = 0;
		stlPoints[2].z = 1;

		stlPoints[3].x = 0;
		stlPoints[3].y = 100;
		stlPoints[3].z = 1;

		stlPoints[4].x = -100;
		stlPoints[4].y = 0;
		stlPoints[4].z = 1;

		//FOR ROB

		//stlPoints[5].x = -100;
		//stlPoints[5].y = 100;
		//stlPoints[5].z = 1;

		for (int i = 0; i < 5; i++) {
			stlLine.push_back(stlPoints[i]);
		}
		init();
		
	}


	DrawTask::~DrawTask(void)
	{
	}
	void DrawTask::init(){		
		 //start week 2
		drawArea->clear(Colour(255,255,255,255));
		/*for (int theta = 0; theta < 1024; theta += 1) {
			drawDDALine(500, 500, (500 + 100 * cos(theta)), (500 + 100 * sin(theta)), Colour(255, 0, 255, 255));
		}/*
		drawDDALine(300, 300, 300, 400, Colour(255, 80, 80, 80));
		drawDDALine(300, 300, 300, 200, Colour(255, 80, 80, 80));
		drawDDALine(300, 300, 400, 300, Colour(255, 80, 80, 80));
		drawDDALine(300, 300, 200, 300, Colour(255, 80, 80, 80));

		drawDDALine(300, 300, 400, 400, Colour(255, 80, 80, 80));
		drawDDALine(300, 300, 200, 200, Colour(255, 80, 255, 80)); //con 2, being weird
		drawDDALine(300, 300, 400, 200, Colour(255, 80, 80, 80));
		drawDDALine(300, 300, 200, 400, Colour(255, 80, 80, 80));

		drawDDALine(300, 300, 200, 400, Colour(255, 255, 80, 80)); //con 1 good, cond 4 wrong.
		

		//drawDDALine(300, 300, 260, 400, Colour(255, 255, 80, 80));
		
		drawCircle(500, 300, 40, Colour(255, 192, 203, 255));
		drawCircle(600, 300, 40, Colour(255, 192, 203, 255));

		drawCircle(500, 300, 10, Colour(255, 20, 147, 255));
		drawCircle(600, 300, 10, Colour(255, 20, 147, 255));
		//end week 2 */
		//start week 3 
		
		//draw square
		/*
		drawDDALine(300, 300, 300, 600, Colour(255, 0, 255, 255));
		drawDDALine(300, 600, 600, 600, Colour(255, 0, 255, 255));
		drawDDALine(600, 600, 600, 300, Colour(255, 0, 255, 255));
		drawDDALine(600, 300, 300, 300, Colour(255, 0, 255, 255));
		*/

		//test to ensure it does not draw pixels that are out of bounds
		//drawDDALine(600, 300, 99900, 9900, Colour(255, 0, 255, 255));




	}

	void DrawTask::drawDDALine(int x1, int y1, int x2, int y2,Colour c){
		int deltay = (y2 - y1);
		int deltax = (x2 - x1);
		int steps;
		if (deltax == deltay) {
			deltax++;
		}
		/*
			https://www.tutorialspoint.com/computer_graphics/line_generation_algorithm
		
		if (abs(deltax) > abs(deltay)) {
			steps = abs(deltax);
		}
		else {
			steps = abs(deltay);
		}

		float xinc = deltax / (float)steps;
		float yinc = deltay / (float)steps;

		float x=x1;
		float y=y1;

		for (int v = 0; v < steps; v++) {
			x += xinc;
			y += yinc;
			drawArea->plotPixel(int(x), int(y), c);
		}
		/*
		end
		*/


		//unsure if the *-1 is correct on cond 2 n 4.
		if (abs(deltax) < abs(deltay)) {// is a steep line
			
			if (y1<y2) { //top to bottom
				//float ystep = deltay / deltax;
				//printf("cond1\n");
				//printf("%d -> %d, %d ->%d\n", x1, x2, y1, y2);
				float xstep = (float)deltax / (float)deltay;
				//printf("Xstep %f\n Deltax, %d, Deltay, %d\n", xstep, deltax, deltay);
				float x = x1;
				for (int y = y1; y <= y2; y++) {
					//printf("%d, %d\n",int(x),y);
					//printf("float x: %f step = %f\n", x, xstep);
					drawArea->plotPixel(int(x), y, c);
					x += xstep;
				}
			}
			else {
				float xstep = (float)deltax / (float)deltay;
				//xstep = xstep * -1;
				//printf("cond2\n");
				float x = x1;
				for (int y = y1; y >= y2; y--) {
					drawArea->plotPixel(int(x), y, c);
					x -= xstep;
				}
			}
		}
		else {
			if (x1<x2) { //left to right
				//original
				//printf("cond3\n");
				float ystep = (float)deltay / (float)deltax;
				//float ystep = abs(deltay);
				float y = y1;
				for (int x = x1; x <= x2; x++) {
					drawArea->plotPixel(x, int(y), c);
					y += ystep;
				}
			}
			else {//right to left
				//currently this is getting a negative step
				//printf("cond4\n");
				//printf("%d -> %d, %d ->%d\n", x1, x2, y1, y2);
				float ystep = (float)deltay / (float)deltax;
				//ystep = ystep * -1;
				//printf("Xstep %f\n Deltax, %d, Deltay, %d\n", ystep, deltax, deltay);
				
				//float ystep = abs(deltay);
				float y = y1;
				for (int x = x1; x >= x2; x--) {
					//printf("%d, %d\n", x, int(y));
					//printf("float x: %f step = %f\n", x, ystep);

					drawArea->plotPixel(x, int(y), c);
					y -= ystep;
				}
			}
		}/**/

	}
		


	void DrawTask::drawDDALin2e(int x1, int y1, int x2, int y2, Colour c) {
		int deltay = (y2 - y1);
		int deltax = (x2 - x1);
		int steps;
		if (deltax == deltay) {
			deltax++;
		}
		/*
		https://www.tutorialspoint.com/computer_graphics/line_generation_algorithm

		if (abs(deltax) > abs(deltay)) {
		steps = abs(deltax);
		}
		else {
		steps = abs(deltay);
		}

		float xinc = deltax / (float)steps;
		float yinc = deltay / (float)steps;

		float x=x1;
		float y=y1;

		for (int v = 0; v < steps; v++) {
		x += xinc;
		y += yinc;
		drawArea->plotPixel(int(x), int(y), c);
		}
		/*
		end
		*/


		//unsure if the *-1 is correct on cond 2 n 4.
		if (abs(deltax) < abs(deltay)) {// is a steep line

			if (y1<y2) { //top to bottom
						 //float ystep = deltay / deltax;
						 //printf("cond1\n");
						 //printf("%d -> %d, %d ->%d\n", x1, x2, y1, y2);
				float xstep = (float)deltax / (float)deltay;
				//printf("Xstep %f\n Deltax, %d, Deltay, %d\n", xstep, deltax, deltay);
				float x = x1;
				for (int y = y1; y <= y2; y++) {
					//printf("%d, %d\n",int(x),y);
					//printf("float x: %f step = %f\n", x, xstep);
					drawArea->plotPixel(int(x), y, c);
					x += xstep;
				}
			}
			else {
				float xstep = (float)deltax / (float)deltay;
				//xstep = xstep * -1;
				//printf("cond2\n");
				float x = x1;
				for (int y = y1; y >= y2; y--) {
					drawArea->plotPixel(int(x), y, c);
					x -= xstep;
				}
			}
		}
		else {
			if (x1<x2) { //left to right
						 //original
						 //printf("cond3\n");
				float ystep = (float)deltay / (float)deltax;
				//float ystep = abs(deltay);
				float y = y1;
				for (int x = x1; x <= x2; x++) {
					drawArea->plotPixel(x, int(y), c);
					y += ystep;
				}
			}
			else {//right to left
				  //currently this is getting a negative step
				  //printf("cond4\n");
				  //printf("%d -> %d, %d ->%d\n", x1, x2, y1, y2);
				float ystep = (float)deltay / (float)deltax;
				//ystep = ystep * -1;
				//printf("Xstep %f\n Deltax, %d, Deltay, %d\n", ystep, deltax, deltay);

				//float ystep = abs(deltay);
				float y = y1;
				for (int x = x1; x >= x2; x--) {
					//printf("%d, %d\n", x, int(y));
					//printf("float x: %f step = %f\n", x, ystep);

					drawArea->plotPixel(x, int(y), c);
					y -= ystep;
				}
			}
		}/**/

	}
	void DrawTask::drawBresLine(int x1, int y1, int x2, int y2,Colour c){
	}
	//you can call MATH::TWO_PI for pi value,
	void DrawTask::drawCircle(int cx, int cy, int r, Colour c) {
		float step = 2 * 3.141592653589793238463 / 720; //how many lines are drawn 
		for (float theta = 0; theta < 2 * 3.141592653589793238463; theta += step) {
			int x = cx + r * cos(theta);
			int y = cy + r * sin(theta);
			printf("%d, %d\n", x, y);
			drawArea->plotPixel(int(x), int(y), c);
		}
	}
	void DrawTask::drawPie(int cx, int cy, int r, float ntheta, Colour c) {
		
		float step = 2 * 3.141592653589793238463 / 2880; //how many lines are drawn

		ntheta = ((3.141592653589793238463) / 2) + ntheta;
		//drawDDALine(cx + r * cos(ntheta), cy + r * cos(ntheta), cx, cy, c);

		//drawDDALine(cx, cy + r * cos(ntheta), cx, cy, c);
		/*(float theta = ntheta; theta >= (3.141592653589793238463) / 2; theta -= step) {
			while(r<0)
		}
		/*for (float theta = ntheta; theta >= (3.141592653589793238463) / 2; theta -= step) {
			int x = cx + r * cos(theta);
			int y = cy + r * sin(theta);
			printf("%d, %d\n", x, y);
			//drawDDALine(cx, cy, x, y, c);
			//drawArea->plotPixel(int(x), int(y), c);
		}*/


		/*
		
		
		float step = 2 * 3.141592653589793238463 / 2880; //how many lines are drawn

		ntheta = ((3.141592653589793238463)/2) + ntheta;
		for (float theta = ntheta; theta >= (3.141592653589793238463)/2; theta -= step) {
			int x = cx + r * cos(theta);
			int y = cy + r * sin(theta);
			printf("%d, %d\n", x, y);
			//drawDDALine(cx, cy, x, y, c);
			//drawArea->plotPixel(int(x), int(y), c);
		}*/

		/* old
		
		
		
		float step = 2 * 3.141592653589793238463 / 2880; //how many lines are drawn
		ntheta = (2 * 3.141592653589793238463) - ntheta;
		for (float theta = ntheta; theta <= 2 * 3.141592653589793238463; theta += step) {
			int x = cx + r * cos(theta);
			int y = cy + r * sin(theta);
			printf("%d, %d\n", x, y);
			drawDDALine(cx, cy, x, y, c);
			//drawArea->plotPixel(int(x), int(y), c);
		}*/
	}
	
	void DrawTask::drawRect(int x, int y, int w, int h, Colour c) {
		for (int i = x; i <= (x + w); i++) {
			drawDDALine(i, y, i, y+h, c);
		}
	}
	//0=normal, 1 = flipped
	void DrawTask::drawRATriangle(int flip, int x1, int y1, int w, int h, Colour c) {
		int deltay = ((y1+h) - y1);
		int deltax = ((x1+w) - x1);
		int steps;
		if (deltax == deltay) {
			deltax++;
		}
		/*
		https://www.tutorialspoint.com/computer_graphics/line_generation_algorithm
		*/
		if (flip == 0) {
			if (abs(deltax) > abs(deltay)) {
				steps = abs(deltax);
			}
			else {
				steps = abs(deltay);
			}

			float xinc = deltax / (float)steps;
			float yinc = deltay / (float)steps;

			float x = x1;
			float y = y1;

			for (int v = 0; v < steps; v++) {
				x += xinc;
				y += yinc;
				drawDDALine(x1, y, x, y, c);
				//drawArea->plotPixel(int(x), int(y), c);
			}
		}else{
			if (abs(deltax) > abs(deltay)) {
				steps = abs(deltax);
			}
			else {
				steps = abs(deltay);
			}

			float xinc = deltax / (float)steps;
			float yinc = deltay / (float)steps;

			float x = x1;
			float y = y1;

			for (int v = 0; v < steps; v++) {
				x -= xinc;
				y += yinc;
				drawDDALine(x+w, y, x1+w, y, c);
				//drawArea->plotPixel(int(x), int(y), c);
			}
		}
		


	}
	void DrawTask::drawRhobus( int x1, int y1, int w, int h, Colour c) {
		int deltay = ((y1 + h) - y1);
		int deltax = ((x1 + w) - x1);
		int steps;
		if (deltax == deltay) {
			deltax++;
		}

		if (abs(deltax) > abs(deltay)) {
			steps = abs(deltax);
		}
		else {
			steps = abs(deltay);
		}

		float xinc = deltax / (float)steps;
		float yinc = deltay / (float)steps;

		float x = x1;
		float y = y1;

		for (int v = 0; v < steps; v++) {
			x += xinc;
			y -= yinc;
			drawDDALine(x + w, y, x, y, c);
			//drawArea->plotPixel(int(x), int(y), c);
		}
	}
	//right angle triange must be 2xh as it is wide
	void DrawTask::drawEQTriangle(int x1, int y1, int w, Colour c) {
		drawRATriangle(0, x1, y1, w, w * 2, c);
		drawRATriangle(1, x1 - w, y1, w, w * 2, c);
	}

	void DrawTask::drawLines(vector<Vector3> points, Vector3 offset) {
		drawArea->plotPixel(150, 150, Colour(255, 0, 0, 255));
		drawArea->plotPixel(151, 151, Colour(255, 0, 0, 255));
		drawArea->plotPixel(149, 149, Colour(255, 0, 0, 255));

		for (int i = 0; i < 4; i++) {
			//points[i] = points[i] * (poly2[4] * poly2[1] * poly2[3]);
			//points[i] = points[i] * poly2[1]; //does not add, it just changes it to the rotation angle
		}
		for (int i = 0; i < (4); i++) { //points.size does not work

			if (i % 2 == 0) {

				drawDDALine(points[i].x + offset.x, points[i].y + offset.y, points[i + 1].x + offset.x, points[i + 1].y + offset.y, Colour(255, 0, 0, 255));

			}
		}
		printf("line drawn\n");
	}


	void DrawTask::drawTristrip(vector<Vector3> points, Vector3 offset) {
		//for (int i = 0; i<4;i++){
		/*drawDDALine(points[0].x+offset.x, points[0].y + offset.y, points[1].x + offset.x, points[1].y + offset.y, Colour(255, 0, 0, 255));
		drawDDALine(points[1].x + offset.x, points[1].y + offset.y, points[3].x + offset.x, points[3].y + offset.y, Colour(255, 0, 0, 255));
		drawDDALine(points[0].x + offset.x, points[0].y + offset.y, points[3].x + offset.x, points[3].y + offset.y, Colour(255, 0, 0, 255));

		drawDDALine(points[0].x + offset.x, points[0].y + offset.y, points[2].x + offset.x, points[2].y + offset.y, Colour(255, 0, 0, 255));
		drawDDALine(points[2].x + offset.x, points[2].y + offset.y, points[3].x + offset.x, points[3].y + offset.y, Colour(255, 0, 0, 255));

		drawDDALine(points[4].x + offset.x, points[4].y + offset.y, points[3].x + offset.x, points[3].y + offset.y, Colour(255, 0, 0, 255));
		drawDDALine(points[2].x + offset.x, points[2].y + offset.y, points[4].x + offset.x, points[4].y + offset.y, Colour(255, 0, 0, 255));*/


		for (int i = 0; i < points.size()-2; i+=1) {
			drawDDALine(points[i].x + offset.x, points[i].y + offset.y, points[i+1].x + offset.x, points[i+1].y + offset.y, Colour(255, 0, 0, 255));
			drawDDALine(points[i+1].x + offset.x, points[i+1].y + offset.y, points[i + 2].x + offset.x, points[i + 2].y + offset.y, Colour(255, 0, 0, 255));
			drawDDALine(points[i].x + offset.x, points[i].y + offset.y, points[i+2].x + offset.x, points[i+2].y + offset.y, Colour(255, 0, 0, 255));

			//drawDDALine(points[1].x + offset.x, points[1].y + offset.y, points[3].x + offset.x, points[3].y + offset.y, Colour(255, 0, 0, 255));
			//drawDDALine(points[0].x + offset.x, points[0].y + offset.y, points[3].x + offset.x, points[3].y + offset.y, Colour(255, 0, 0, 255));
		}





		//drawDDALine(points[5].x + offset.x, points[5].y + offset.y, points[3].x + offset.x, points[3].y + offset.y, Colour(255, 0, 0, 255));
		//drawDDALine(points[4].x + offset.x, points[4].y + offset.y, points[3].x + offset.x, points[3].y + offset.y, Colour(255, 0, 0, 255));

		/*drawDDALine(points[0].x + offset.x, points[0].y + offset.y, points[1].x + offset.x, points[1].y + offset.y, Colour(255, 0, 0, 255));
		drawDDALine(points[1].x + offset.x, points[1].y + offset.y, points[3].x + offset.x, points[3].y + offset.y, Colour(255, 0, 0, 255));
		drawDDALine(points[0].x + offset.x, points[0].y + offset.y, points[3].x + offset.x, points[3].y + offset.y, Colour(255, 0, 0, 255));*/





			//drawArea->plotPixel(points[0], points[1]., Colour(255, 0, 0, 255));
			//drawArea->plotPixel(points[1], points[2], Colour(255, 0, 0, 255));
			//drawArea->plotPixel(points[2], points[3], Colour(255, 0, 0, 255));
		//}

	}



	void DrawTask::update(float dt){
		drawArea->clear(Colour(255,255,255,255));
		
		//drawPie(400, 400, 300, (float)(3.141592653589793238463 / 12), Colour(0, 255, 255, 255)); //good

		drawPie(500, 300, 200, (float)(3.141592653589793238463 / 6), Colour(0, 255, 255, 255));

		//drawCircle(400, 400, 300, Colour(0, 255, 255, 255));
		//drawRATriangle(0, 200, 200, 600, 300, Colour(0, 255, 255, 255)); //good 
		//drawEQTriangle(200, 200, 200,  Colour(0, 255, 255, 255)); //goodish
		// drawRect(100, 100, 500, 200, Colour(0, 255, 255, 255)); //good
		//drawRhobus(200, 200, 200, 200, Colour(0, 255, 255, 255)); //bad

		/*drawDDALine(300, 300, 300, 600, Colour(255, 0, 255, 255));
		drawDDALine(300, 600, 600, 600, Colour(255, 0, 255, 255));
		drawDDALine(600, 600, 600, 300, Colour(255, 0, 255, 255));
		drawDDALine(600, 300, 300, 300, Colour(255, 0, 255, 255));*/
		
		/*drawLines(stlLine, )
			https://mylo.utas.edu.au/d2l/le/content/322798/viewContent/3174730/View
	https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
	https://mylo.utas.edu.au/d2l/le/content/322798/viewContent/3174469/View
	https://www.geeksforgeeks.org/list-cpp-stl/ */
		//stlOffset = stlOffset * (poly2[4] * poly2[1] * poly2[3]);
		//stlOffset = stlOffset * poly2[1];
		//stlOffset = stlOffset * poly2[2]; //can move point, why does it not rotate

		//start works good
		//I would ideally make a seperate rotate with the offset positions in it, when calling the method if would not apply multiple times
		//it would just go to the angle specfied in ther otation matrix/position ect
		for (int i = 0; i < stlLine.size();i++) {
			stlLine[i] = stlLine[i] * poly2[1];
		}
		//drawLines(stlLine, stlOffset); 
		//end works good/**/

		drawTristrip(stlLine, stlOffset);

		//Modify the drawing code so that it uses a for loop with the new member variables.
		//for (int i = 0; i < 2; i++) {
			//line[0] = line[0] * (poly2[4] * poly2[1] * poly2[3]);
			//line[1] = line[1] * (poly2[4] * poly2[1] * poly2[3]);
			//drawDDALine(line[1].x, line[1].y, line[0].x, line[0].y, Colour(255, 255, 255, 255)); //not about
		//}
		for (int i = 0; i < 4;i++) {	
			//movement and scale working.
			//polyDup[i] = polyDup[i] * poly2[0];//translate
			//polyDup[i] = polyDup[i] * poly2[2];//scale
				//polyDup[i] = polyDup[i] * ( poly2[2] * poly2[0]); //good


			//trying to get rotating on the spot working.
			//polyDup[i] = polyDup[i] * poly2[3];//translate
					//polyDup[i] = polyDup[i] * (poly2[4] * poly2[1] * poly2[3]); //horray square spins
			
			//polyDup[i] = polyDup[i] * poly2[3];//translate

			//polyDup[i] = polyDup[i] * poly2[3];//translate

			//polyDup2[i] = polyDup2[i] * poly2[0];//translate
			//polyDup2[i] = polyDup2[i] * poly2[1];//rotation
			//polyDup2[i] = polyDup2[i] * poly2[0];//translate

			//Test that animation is working by adding a small offset to each x and y coordinate before drawing the lines.
				//poly[i].x++; //moves square, works

			if (i == 3) {
				drawDDALine(poly[i].x, poly[i].y, poly[0].x, poly[0].y, Colour(255, 0, 255, 255));
				drawDDALine(polyDup[i].x, polyDup[i].y, polyDup[0].x, polyDup[0].y, Colour(255, 0, 255, 255));
				drawDDALine(polyDup2[i].x, polyDup2[i].y, polyDup2[0].x, polyDup2[0].y, Colour(255, 255, 255, 255));
			}
			else {

				drawDDALine(poly[i].x, poly[i].y, poly[i + 1].x, poly[i + 1].y, Colour(255, 0, 255, 255));
				drawDDALine(polyDup[i].x, polyDup[i].y, polyDup[i + 1].x, polyDup[i + 1].y, Colour(255, 0, 255, 255));
				drawDDALine(polyDup2[i].x, polyDup2[i].y, polyDup2[i + 1].x, polyDup2[i + 1].y, Colour(255, 255, 255, 255));
			}		
		}

		app->getRenderer()->reloadTexture(drawArea);
	}

}
