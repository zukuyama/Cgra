
#include "myTable.h"

void tableLeg(double thick,double len)  // draw one table leg
{
    glPushMatrix();
    glTranslated(0,len/2,0);
    glScaled(thick,len,thick);
    glutSolidCube(1.0);
    glPopMatrix();
}


void myTable::drawtableLegs(float legLen, float legThick, float topWid, 
	float topWid2, float topThick){
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


static void
drawBox(GLfloat size, GLenum type)
{
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {0, 1, 2, 3},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {4, 5, 1, 0},
    {5, 6, 2, 1},
    {7, 4, 0, 3}
  };
  GLfloat v[8][3];
  GLint i;
 
  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size /2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = size /2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size /2;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = size /2;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size /2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = size /2;
 
  for (i = 0; i <= 5; i++) {
    glBegin(type);
    glNormal3fv(&n[i][0]);
    glVertex3fv(&v[faces[i][0]][0]);
    glVertex3fv(&v[faces[i][1]][0]);
    glVertex3fv(&v[faces[i][2]][0]);
    glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}
 

void glSolid(GLdouble size)
{
	drawBox(size, GL_QUADS); 
}
//glTranslated(1.5,0,1.5);//posiciona mesa e chao no local correto


void myTable::drawtampo(){
	float legLen=3.5;
	float legThick=0.3;
	float topWid =5;
	float topWid2 =3;
	float topThick=0.3;

	glTranslated(topWid/2,0.1,topWid2/2);//coloca mesa no sitio e eleva-a para dar espaco para a mesa
	glPushMatrix();
	
    glTranslated(0,legLen,0);
    glScaled(topWid, topThick,topWid2);
 
	
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glSolid(1);
		
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();

	//drawtableLegs(legLen, legThick, topWid, topWid2, topThick);
}

void myTable::draw() //quatro pernas (0.3*3.5*0.3) e um tampo (5*0.3*3).
{  
	drawtampo();
}