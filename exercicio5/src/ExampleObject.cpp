#include "ExampleObject.h"
//exerc 2 ficha1
void ExampleObject::draw() 
{
	glBegin(GL_QUADS);
		glVertex3d(0,0,0);
		glVertex3d(4,0,0);
		glVertex3d(4,3,0);
		glVertex3d(0,3,0);
	glEnd();

	///exercicio 1 ficha1
	glBegin(GL_TRIANGLES);
		glVertex3d(-1,3,0);
		glVertex3d(5,3,0);
		glVertex3d(2,4,0);
	glEnd();
}





void myUnitCube::draw()
{
	glBegin(GL_POLYGON);
		glVertex3d(-0.5,-0.5,-0.5);
		glVertex3d(0.5,-0.5,-0.5);
		glVertex3d(0.5,0.5,-0.5);
		glVertex3d(-0.5,0.5,-0.5);
	glEnd();


}
void tableLeg(double thick,double len)  // draw one table leg
{
    glPushMatrix();
   // glTranslated(0,len/2,0);
    glScaled(thick,len,thick);
    glutSolidCube(1.0);
    glPopMatrix();
}
void myTable::draw() //quatro pernas (0.3*3.5*0.3) e um tampo (5*0.3*3).
{  float legLen=3.5;
	float legThick=0.3;
	float topWid =5;
	float topWid2 =3;
	float topThick=0.3;
	glTranslated(topWid/2,0.1,topWid2/2);//coloca mesa no sitio e eleva-a para dar espaco para a mesa
	    glPushMatrix();
    glTranslated(0,legLen,0);
    glScaled(topWid, topThick,topWid2);
    glutSolidCube(1.0);
    glPopMatrix();
    double dist =0.95* topWid/2.0 - legThick/2.0;
	double dist2=0.95* topWid2/2.0 - legThick/2.0;
    glPushMatrix();
    glTranslated(dist,0,dist2);
    tableLeg(legThick,legLen);
    glTranslated(0.0,0.0,-2*dist2);
    tableLeg(legThick,legLen);
    glTranslated(-2*dist,0,2*dist2);
    tableLeg(legThick,legLen);
    glTranslated(0,0,-2*dist2);
    tableLeg(legThick,legLen);
	glTranslated(3,0,3);
    glPopMatrix();
	

}

void myFloor::draw() //(8*0.1*6)
{  
	//glTranslated(topWid/2,0.1,topWid2/2);/
	    glPushMatrix();
   // glTranslated(0,legLen,0);
    glScaled(8, 0.1,6);
    glutSolidCube(1.0);
    glPopMatrix();

}

void enconsto()  // draw one table leg
{
   glBegin(GL_POLYGON);
		glVertex3d(0,0,0);
		glVertex3d(1.5,0,0);
		glVertex3d(1.5,1.5,0);
		glVertex3d(0,1.5,0);
	glEnd();
 
}
void ExampleObject::drawChair()
{

	float tamanho=3.5;
	float espessura=0.3;
	//float comprimento =5;
	float largura =3;
	//float topThick=0.3;
	//glTranslated(0,0.1,0);//coloca mesa no sitio e eleva-a para dar espaco para a mesa
	    glPushMatrix();
    glTranslated(0,tamanho/2,0);
    glScaled(largura/2,espessura,largura/2);
    glutSolidCube(1.0);
    glPopMatrix();
    double dist = 2.121320343559643 - espessura/2.0;
	//double dist2=0.95* topWid2/2.0 - espessura/2.0;

    glPushMatrix();
    glTranslated(largura/4-espessura/2,tamanho/4,largura/4-espessura/2);
    tableLeg(espessura,tamanho/2  - espessura );
	glTranslated(0,0,-2*(largura/4-espessura/2));
     tableLeg(espessura,tamanho/2  - espessura );
    glTranslated(-2*(largura/4-espessura/2),0,0);
	tableLeg(espessura,tamanho/2  - espessura );
   glTranslated(0,0,2*(largura/4-espessura/2));
     tableLeg(espessura,tamanho/2  - espessura );
	 glTranslated(0, tamanho/2,0);
	  //glScaled(0, 0,espessura);
 // enconsto();
	   
   // glTranslated(0,legLen,0);
 glPushMatrix();
   // glTranslated(0,len/2,0);
    glScaled(tamanho/2  - espessura,tamanho/2  - espessura
		,espessura);
	glTranslated(tamanho/8,0,0);
    glutSolidCube(1.0);
	
    glPopMatrix();
   
	//glScaled(espessura, 1,espessura);
	// glutSolidCube(1.0);
	// glScaled(0, 0,espessura);
    glPopMatrix();

}
