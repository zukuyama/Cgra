#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"
#include <cmath>
#include <math.h>
#include <gl\GLU.h>
#include <GL\GLU.h>
class myCylinder : public CGFobject {

	public:
		myCylinder(int slices, int stacks);
		void drawCylinder(int slices, int stacks);
};



#endif
