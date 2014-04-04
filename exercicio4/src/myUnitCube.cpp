#include "myUnitCube.h"

void myUnitCube::draw()
{
	glBegin(GL_POLYGON);
		glVertex3d(-0.5,-0.5,-0.5);
		glVertex3d(0.5,-0.5,-0.5);
		glVertex3d(0.5,0.5,-0.5);
		glVertex3d(-0.5,0.5,-0.5);
	glEnd();


}


/*myCube.draw();
	glTranslated(0,0,1);
	myCube.draw();
	glRotated(90,1,0,0); 
	glTranslated(0,-1,0);
	myCube.draw();
	glRotated(-90,0,1,0);
	myCube.draw();
	glRotated(-90,0,1,0);
	myCube.draw();
	glRotated(-90,0,1,0);*/
	//myCube.draw();