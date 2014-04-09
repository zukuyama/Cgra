#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include "CGFobject.h"
#include "CGFappearance.h"

class myTable: public CGFobject {
   
	CGFappearance* tableAppearance;
public:
	myTable();
    void draw();
    void leg();
    void top();
	
};

#endif
