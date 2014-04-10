#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include "CGFobject.h"



class myUnitCube: public CGFobject {
    public:
		void myRect(float a, float b, float c, float d);
        void draw();

};
#endif