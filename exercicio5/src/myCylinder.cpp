#include "myCylinder.h"

myCylinder::myCylinder(int slices, int stacks) {
//	for (int i=0; i< slices; i++){
// glPushMatrix();
//    glTranslated(dist,0,dist2);
//   slice( ????) ;
//    glPopMatrix();
//	}
//
//}
//
//void slice(double size)  // draw one table leg
//{
//    glPushMatrix();
//    glTranslated(0,size,0);
//    glPopMatrix();
//}

	/*double x, y;
	double angle;
	double PI= 3.141592653589793238462643383279502884;
		
	glBegin(GL_POLYGON);
  
	for (int sideIndex = 0; sideIndex < slices; sideIndex++) {
		angle = (((PI * 2.0f) * sideIndex) / slices);
		x = cos(angle);
		y = sin(angle);
		glVertex2f(x, y);
	}
	glEnd();*/


		//Cylinder
	
		
}

void myCylinder::drawCylinder(int slices, int stacks){                 
	GLUquadricObj *quadratic=gluNewQuadric();
	gluCylinder(quadratic,1.0f,1.0f,5.0f,slices,stacks);
}


/*slices
Specifies the number of subdivisions around the z axis.

stacks
Specifies the number of subdivisions along the z axis.*/

