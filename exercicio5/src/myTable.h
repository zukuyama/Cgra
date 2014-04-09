#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include "CGFobject.h"


class myTable: public CGFobject {
	
	public:
		void draw();
		void drawtampo();
		void drawtableLegs(float legLen, float legThick, float topWid, 
	float topWid2, float topThick);
};

#endif