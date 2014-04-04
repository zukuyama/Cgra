#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include "CGFobject.h"

class ExampleObject: public CGFobject {
	public:
		void draw();
		void drawChair();
};

class myUnitCube: public CGFobject {
	public:
		void draw();
};

class myTable: public CGFobject {
	
	public:
		void draw();
};

class myFloor: public CGFobject {
	
	public:
		void draw();
};
#endif