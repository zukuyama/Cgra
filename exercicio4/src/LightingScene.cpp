#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4
#define WINDOW_HEIGHT 2.5
#define WINDOW_WIDTH 2.5
#define FLOOR_HEIGHT 1.25
#define FLOOR_WIDTH 1.5

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0.0,0.0,0.0,1.0};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100
#define WINDOW_DIVISIONS 100
#define FLOOR_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0.0, 1.0, 0.0};
float shininessA = 120.f;


// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

// Coefficients for tableAppearance
float ambtableAppearance[3] = {0.2, 0.2, 0.2};
float diftableAppearance[3] = {0.8, 0.8, 0.8};
float spectableAppearance[3] = {0.2, 0.2, 0.2};
float shininesstableAppearance = 60.f;


// Coefficients for slidesAppearance
float ambslidesAppearance[3] = {0.2, 0.2, 0.2};
float difslidesAppearance[3] = {0.8, 0.8, 0.8};
float specslidesAppearance[3] = {0.2, 0.2, 0.2};
float shininessslidesAppearance = 60.f;


// Coefficients for boardAppearance
float ambboardAppearance[3] = {0.2, 0.2, 0.2};
float difboardAppearance[3] = {0.2, 0.2, 0.2};
float specboardAppearance[3] = {0.4, 0.4, 0.4};
float shininessboardAppearance = 140.f;



float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};

void LightingScene::init() 
{
	// Enables lighting computations
	glEnable(GL_LIGHTING);
	//enable Shade computations
	glShadeModel(GL_SMOOTH);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  
	
	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  
	
	// Declares and enables two lights, with null ambient component

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);

	light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	
	light1->enable();

	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(0); 
	light2->setKl(1);
	light2->setKq(0);//Kc=0, Kl=0.2, Kq=0
	
	light2->enable();

	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setSpecular(yellow);
	light3->setKc(0); 
	light3->setKl(0);
	light3->setKq(1);
	
	light3->enable();
	
	// Uncomment below to enable normalization of lighting normal vectors
	glEnable (GL_NORMALIZE);

	//Declares scene elements
	//cube = new myUnitCube();
	table = new myTable();
	wall = new Plane();
	boardA = new Plane(BOARD_A_DIVISIONS, 1.0, 1.0);	
	boardB = new Plane(BOARD_B_DIVISIONS, 1.0, 0.7265625);
	window = new Plane(WINDOW_DIVISIONS, 1.0, 1.0);
	floor = new Plane(WINDOW_DIVISIONS, 0.2, 0.1667);

	//Declares materials
	materialA = new CGFappearance(ambA,difA,specA,shininessA);
	materialB = new CGFappearance(ambB,difB,specB,shininessB);
	tableAppearance = new CGFappearance(ambtableAppearance,diftableAppearance,spectableAppearance,shininesstableAppearance);
	tableAppearance->setTexture("table.png");
	slidesAppearance= new CGFappearance(ambslidesAppearance,difslidesAppearance,specslidesAppearance,shininessslidesAppearance);
	slidesAppearance->setTexture("slides.png");
	boardAppearance = new CGFappearance(ambboardAppearance,difboardAppearance,specboardAppearance,shininessboardAppearance);
	boardAppearance->setTexture("board.png");
	
	windowAppearance = new CGFappearance(ambboardAppearance,difboardAppearance,specboardAppearance,shininessboardAppearance);
	windowAppearance->setTexture("window.png");
	windowAppearance->setTextureWrap(GL_CLAMP,GL_CLAMP);

	floorAppearance = new CGFappearance(ambboardAppearance,difboardAppearance,specboardAppearance,shininessboardAppearance);
	floorAppearance->setTexture("floor.png");
		floorAppearance->setTextureWrap(GL_REPEAT,GL_REPEAT);
	cylinder = new myCylinder(6, 2);
}

void LightingScene::display() 
{

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	light0->draw();
	light1->draw();
	light2->draw();
	light3->draw();
	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section
	//cube
	/*glPushMatrix();
		glTranslated(5,0,8);
		myC->draw();
	glPopMatrix();*/



	//LeftWall
	glPushMatrix();
		glTranslated(0,4,7.5);
		glRotated(-90.0,0,0,1);
		glScaled(8,0.2,15);
		//GL_TEXTURE_WRAP_S;
		//GL_CLAMP_TO_BORDER;
		//windowAppearance->apply();
		//GL_CLAMP_TO_BORDER;   The coordinates that fall outside the range will be given a specified border color.
		wall->draw();
		//materialB->apply();
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
		glTranslated(7.5,4,0);
		glRotated(90.0,1,0,0);
		glScaled(15,0.2,8);
		wall->draw();
	glPopMatrix();

	//Floor
	glPushMatrix();
	glTranslated(7.5,0,7.5);
	glScaled(15,0.2,15);
	//glScaled(FLOOR_WIDTH,FLOOR_HEIGHT,1);
	floorAppearance->apply();
	floor->draw();
	glPopMatrix();


	// Board A
	glPushMatrix();
		glTranslated(4,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		slidesAppearance->apply();
		boardA->draw();
		materialB->apply();
	glPopMatrix();
	
	//PlaneB
	glPushMatrix();
		glTranslated(10.5,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		boardAppearance->apply();
		boardB->draw();
		materialB->apply();
	glPopMatrix();

		//Window
	glPushMatrix();
		glTranslated(0.2,3.75,7.5);
		glScaled(1,WINDOW_HEIGHT,WINDOW_WIDTH);
		glRotated(-90.0,0,0,1);
		windowAppearance->apply();
		window->draw();
	glPopMatrix();
	
	//Cylinder
	glPushMatrix();
		glTranslated(2,2,1);
		cylinder->drawCylinder(10,50);
	glPopMatrix();

	glPushMatrix();
		glShadeModel(GL_SMOOTH);
		glTranslated(5,4,1);
		cylinder->drawCylinder(10,50);
	glPopMatrix();

	 	//First Table
	glPushMatrix();
		glTranslated(5,0,8);
		tableAppearance->apply();
		table->draw();
		materialB->apply();
		table->drawtableLegs(3.5, 0.3, 5, 3, 0.3);
	glPopMatrix();

	

	//Second Table
	glPushMatrix();
		glTranslated(12,0,8);
		tableAppearance->apply();
		table->draw();
		materialB->apply();
		table->drawtableLegs(3.5, 0.3, 5, 3, 0.3);
	glPopMatrix();
	// ---- END Primitive drawing section
	

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);
	delete(light2);
	delete(light3);

	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
	delete(tableAppearance);
}