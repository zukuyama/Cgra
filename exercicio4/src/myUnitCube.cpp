#include "myUnitCube.h"



void myUnitCube::myRect(float x1, float y1, float x2, float y2){
	glBegin(GL_QUADS);

	glTexCoord2f(x1,y1);
    glVertex3f(x1,y1,0);

	glTexCoord2f(x2,y1);
    glVertex3f(x2,y1,0);

	glTexCoord2f(x2,y2);
    glVertex3f(x2,y2,0);

	glTexCoord2f(x1,y2);
    glVertex3f(x1,y2,0);
	glEnd();
}

void myUnitCube::draw()
{
    glPushMatrix();
    glTranslatef(0, 0, -0.5);
    glNormal3d(0, 0, -1);
    myRect(0.5, -0.5, -0.5, 0.5);
    
    glTranslatef(0, 0.5, 0.5);
    glRotatef(90, 1, 0, 0);
    glNormal3d(0, 0, -1);
    myRect(0.5, -0.5, -0.5, 0.5);
    
    glTranslatef(0, 0.5, 0.5);
    glRotatef(90, 1, 0, 0);
    glNormal3d(0, 0, -1);
    myRect(0.5, -0.5, -0.5, 0.5);
    
    glTranslatef(0, 0.5, 0.5);
    glRotatef(90, 1, 0, 0);
    glNormal3d(0, 0, -1);
    myRect(0.5, -0.5, -0.5, 0.5);
    
    glTranslatef( -0.5, 0, 0.5);
    glRotatef(90, 0, 1, 0);
    glNormal3d(0, 0, -1);
    myRect(0.5, -0.5, -0.5, 0.5);
    
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, -1);
    glNormal3d(0, 0, -1);
    myRect(0.5, -0.5, -0.5, 0.5);
    
    glPopMatrix();
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