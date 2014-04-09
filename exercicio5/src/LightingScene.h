#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myUnitCube.h"
#include "myCylinder.h"
#include "MyClock.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	//myUnitCube* cube;
	myTable* table;
	myCylinder* cylinder;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	Plane* window;
	Plane* floor;
	MyClock* clock;
	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* tableAppearance;
	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance*  windowAppearance;
	CGFappearance*  floorAppearance;
	CGFappearance* clockAppearance;
	~LightingScene();
};

#endif