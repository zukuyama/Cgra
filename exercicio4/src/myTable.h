#ifndef CGFExample_myTable_h
#define CGFExample_myTable_h

#include "CGFobject.h"
#include "CGFappearance.h"
#include "myUnitCube.h"
#include "ExampleObject.h"

class myTable: public CGFobject {
   myUnitCube cube;
	CGFappearance* tableAppearance;
public:
	myTable();
    void draw();
    void leg();
    void top();
	
};

#endif
