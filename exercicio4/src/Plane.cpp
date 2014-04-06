#include "Plane.h"
#include <GL/GLU.h>


Plane::Plane(void)
{
	_numDivisions = 1;
}

Plane::Plane(int n, double s, double t){
	_numDivisions = n;
	this->s=s;
	this->t=t;
}


Plane::~Plane(void)
{
}

void Plane::draw()
{
	glPushMatrix();

		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);
		
		for (int bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f((double)bx*(1.0/_numDivisions),0);
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz<_numDivisions; bz++)
		{
			glTexCoord2f((double)((bx+1)/s)*(1.0/_numDivisions),(double)bz/t*(1.0/_numDivisions));
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2f((double)(bx/s)*(1.0/_numDivisions),(double)((bz+1)/t)*(1.0/_numDivisions));
			glVertex3f(bx, 0, (bz + 1) );
		}
		glTexCoord2f((double)((bx+1)/s)*(1.0/_numDivisions),1/t);
		glVertex3d(bx+1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();
}
