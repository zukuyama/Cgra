

#include "myTable.h"
#include "CGFapplication.h"
#include "CGFappearance.h"
#include "myUnitCube.h"


myTable::myTable(){
	 //Coefficients for tableAppearance
float ambtableAppearance[3] = {0.2, 0.2, 0.2};
float diftableAppearance[3] = {0.8, 0.8, 0.8};
float spectableAppearance[3] = {0.2, 0.2, 0.2};
float shininesstableAppearance = 60.f;
	// Coefficients for table top

tableAppearance = new CGFappearance(ambtableAppearance,diftableAppearance,spectableAppearance,shininesstableAppearance);
	tableAppearance->setTextureWrap(GL_REPEAT,GL_REPEAT);
	tableAppearance->setTexture("table.png");
}
void myTable::leg() {
    glPushMatrix();
    glScalef(0.3, 3.5, 0.3);
     glutSolidCube(1.0);
    glPopMatrix();
}
void myTable::top() {
    glPushMatrix();
	
	
    glScalef(5.0, 0.3, 3.0);
	 tableAppearance->apply();
  // glutSolidCube(1.0);
 
 // glTranslated(2.5,0.1,1.5);
 cube.draw();
  
    glPopMatrix();
}

void myTable::draw() {
    glPushMatrix();
    
	glDisable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(-2.25, 1.75, -1.25);
    leg();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.25, 1.75, 1.25);
    leg();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.25, 1.75, 1.25);
    leg();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.25, 1.75, -1.25);
    leg();
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(-2.25, 1.9, 1.25);
    top();
    glPopMatrix();
    
    glPopMatrix();
}