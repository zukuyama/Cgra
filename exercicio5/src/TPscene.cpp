#include "TPscene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#include "CGFappearance.h"

CGFappearance *mat1;
//exerc 2 ficha1
//ExampleObject myObject;

//exercicio 5 ficha1
//myUnitCube myCube;
myTable myCube;
myFloor myCube1;


void TPscene::init() 
{
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);  // Define ambient light
	
	// Declares and enables a light
	float light0_pos[4] = {4.0, 6.0, 5.0, 1.0};
	CGFlight* light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->enable();

	// Defines a default normal
	glNormal3f(0,0,1);

}

void TPscene::display() 
{
	
	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup


	// ---- BEGIN Geometric transformation section

	// NOTE: OpenGL transformation matrices are transposed

	// Translate (5, 0, 2)
	
	float tra[16] = { 1.0, 0.0, 0.0, 0.0,
                      0.0, 1.0, 0.0, 0.0,
                      0.0, 0.0, 1.0, 0.0,
                      5.0, 0.0, 2.0, 1.0};

	// Rotate 30 degrees around Y
	// These constants would normally be pre-computed at initialization time
	// they are placed here just to simplify the exampl
	
	float a_rad=30.0*deg2rad;
	float cos_a = cos(a_rad);
	float sin_a = sin(a_rad);

	float rot[16] = { cos_a,  0.0,  -sin_a,  0.0,
                      0.0,    1.0,   0.0,    0.0,
                      sin_a,  0.0,   cos_a,  0.0,
                      0.0,    0.0,   0.0,    1.0};

	// Scaling by (2,2,1)
	float sca[16] = { 2.0, 0.0, 0.0, 0.0,
                      0.0, 2.0, 0.0, 0.0,
                      0.0, 0.0, 1.0, 0.0,
                      0.0, 0.0, 0.0, 1.0};

	// Multiplication of the previous transformations
	// glMultMatrixf(sca);
	//glMultMatrixf(rot);  
	//glMultMatrixf(tra);     // GT = GT * tra
	//glMultMatrixf(rot);     // GT = GT * rot
	//glMultMatrixf(sca);     // GT = GT * sca

	//glPushMatrix();//4.5 ficha1
	//glTranslated(0,5,0);

	//exercicio 4c) ficha1
	//myObject.draw();
	
	//glPopMatrix(); //4.5 ficha1
	
	//exercicio 4 ficha1
	
	//glRotated(30,0,1,0);  
	//glScaled(2,2,1);
	//glTranslated(5,0,2);
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
	//glTranslated(1.5,0,1.5);//posiciona mesa e chao no local correto
	//glColor3d (1, 1, 0.05); Perguntar como fazer a mesa castanha?
	//myCube.draw();
	//myCube1.draw();
	mychair.drawChair();
	//glTranslated(
	// ---- END Geometric transformation section
	

	// ---- BEGIN Primitive drawing section

    // NOTE: the visible face of the polygon is determined by the order of the vertices

	//exerc 2 ficha1
	
	//myObject.draw();
	
	// ---- END Primitive drawing section

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}
