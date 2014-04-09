#include "src\MyClock.h"

MyClock::MyClock()
{
}


void MyClock::draw()
{
	glPushMatrix();
		GLUquadricObj *quadratic=gluNewQuadric();
		gluCylinder(quadratic,1.0f,1.0f,5.0f,12,2);
		//gluDisk(quadratic, 0.0f, 1.0f, 12, 1);
		glTranslatef(0.0f, 0.0f, 5.0f);
		gluDisk(quadratic, 0.0f, 1.0f, 12, 1);
		glTranslatef(0.0f, 0.0f, -5.0f);
	glPopMatrix();
}