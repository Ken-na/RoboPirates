// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// DrawTask.cpp
//
// Simple task for drawing to and animating textures, used in tutorial 1 for practice implementing drawing routines

#pragma once
#include "task.h"
#include "T3DApplication.h"
#include "Texture.h"

namespace T3D{

	class DrawTask :
		public Task
	{
	public:
		DrawTask(T3DApplication *app, Texture* tex);
		~DrawTask(void);

		void init();
		void drawDDALine(int x1, int y1, int x2, int y2, Colour c);
		void drawBresLine(int x1, int y1, int x2, int y2, Colour c);
		void drawCircle(int cx, int cy, int r, Colour c);
		void drawPie(int cx, int cy, int r, float ntheta, Colour c);
		void DrawTask::drawRect(int x, int y, int w, int h, Colour c);
		void DrawTask::drawRATriangle(int flip, int x1, int y1, int w, int h, Colour c);
		void DrawTask::drawEQTriangle(int x1, int y1, int w, Colour c);
		void DrawTask::drawRhobus( int x1, int y1, int w, int h, Colour c);
		void DrawTask::drawLines(vector<Vector3> points, Vector3 offset);
		void DrawTask::drawTristrip(vector<Vector3> points, Vector3 offset);
		void DrawTask::drawDDALin2e(int x1, int y1, int x2, int y2, Colour c);
		virtual void update(float dt);

	private:
		Texture *drawArea;
		Vector3 poly[5];
		Vector3 polyDup[5];
		Vector3 polyDup2[5];
		Matrix3x3 poly2[5];
		Vector3 line[2];

		vector<Vector3> stlLine;
		Vector3 stlOffset;
		Vector3 stlPoints[10];
		Vector3 tripoints[10];
		//vector3 poly adding at 4/08
	};

}

