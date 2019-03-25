
//Semestre 2019 - 2 ******************************************//
//************************************************************//
//************** Alumno: López Pérez Marcos Emiliano *********//
//************** Práctica #7 Ejercicio de Clase 		******//
//************** Microsoft Visual Studio 2017 			******//
//************************************************************//

#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;

float LightAngle = 30.0f;

bool	light = false;		// Luz ON/OFF
bool	positional = true;

static int spin = 0;


GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };			    // Light Position

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background
GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };					// Object Color main
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest



// Variables used to calculate frames per second: (Windows)

DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

//Variables used to create movement
int sol = 0, mercurio = 0, venus = 0;
int tierra = 0, marte = 0, jupiter = 0;
int saturno = 0, urano = 0, neptuno = 0;
int parametro = 30;

float camaraZ = 0.0;
float camaraX = 0.0;
float RotarX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position


GLfloat MerDiffuse[] = { 0.64f, 0.164f, 0.161f, 1.0f };			// Mercurio
GLfloat MerSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MerShininess[] = { 50.0 };

GLfloat VenDiffuse[] = { 0.90f, 0.91f, 0.28f, 1.0f };			// Venus
GLfloat VenSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat VenShininess[] = { 50.0 };


GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat JupDiffuse[] = { 0.80f, 0.5f, 0.2f, 1.0f };			// Jupiter
GLfloat JupSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat JupShininess[] = { 50.0 };


void InitGL(GLvoid)     // Inicializamos parametros
{
	glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//glEnable (GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Light
	//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// Position The Light
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			// Direction Of The Light

	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);							// Enable Light One
	//glEnable(GL_LIGHT0);

}

void display(void)   // Creamos la funcion donde se dibuja

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara
	glPushMatrix();
	glRotatef(RotarX, 1, 0, 0);
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	if (positional)
	{
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection);
	}
	else
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);

	glutSolidSphere(0.07, 10, 10);
	if (!light)
	{
		glDisable(GL_LIGHTING);
	}
	else
	{
		glEnable(GL_LIGHTING);
	}
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glutSolidSphere(20.0, 20, 20);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glRotatef(mercurio, 0.0, 1.0, 0.0);	//gira sobre su eje
	glTranslatef(27.20, 0, 0);
	glColor3f(0.64, 0.16456, 0.16278);	//Mercurio
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MerDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MerSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MerShininess);
	glutSolidSphere(0.38, 14, 14);
	glPopMatrix();

	glPushMatrix();
	glRotatef(venus, 0.0, 1.0, 0.0);	//gira sobre su eje
	glTranslatef(34.40, 0, 0);
	glColor3f(0.90, 0.91, 0.98);	//Venus
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, VenSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, VenShininess);
	glutSolidSphere(0.95, 14, 14);
	glPopMatrix();


	glPushMatrix();
	glRotatef(tierra, 0.0, 1.0, 0.0);	//gira sobre su eje
	glTranslatef(40.0, 0, 0);
	glColor3f(0.0, 0.0, 0.7);	//Tierra
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
	glutSolidSphere(1.0, 14, 14);
	glPushMatrix();


	glRotatef(tierra, 0.0, 1.0, 0.0);
	glTranslatef(1.30, 0, 0);
	glColor3f(0.90, 0.90, 0.90);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.10, 14, 14);  //Draw Moon;
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(marte, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glTranslatef(50.40, 0, 0);
	glColor3f(0.7, 0.0, 0.0);	//Marte
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
	glutSolidSphere(0.6, 14, 14);

	glPushMatrix();
	glRotatef(marte, 0.0, 1.0, 0.0);
	glTranslatef(1.30, 0, 0);
	glColor3f(0.90, 0.20, 0.90);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.10, 14, 14);  //Draw Moon;

	glPopMatrix();
	glPushMatrix();



	glRotatef(tierra, 0.0, 1.0, 0.0);
	glTranslatef(1.10, 0, 0);
	glColor3f(0.20, 0.20, 0.30);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.12, 14, 14);  //Draw Moon;

	glPopMatrix();



	glPopMatrix();



	glPushMatrix();
	glRotatef(jupiter, 0.0, 1.0, 0.0);	//gira sobre su eje
	glTranslatef(72.0, 0, 0);
	glColor3f(0.8, 0.5, 0.2);	//jupiter
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, JupDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, JupSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, JupShininess);
	glutSolidSphere(11.2, 14, 14);  //Draw Jupiter
	glPushMatrix();
	   
	glRotatef(urano, 0.0, 1.0, 0.0);
	glTranslatef(12.30, 0, 0);
	glColor3f(0.90, 0.90, 0.90);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.60, 14, 14);  //Draw Moon;
	glPopMatrix();
	glPushMatrix();

	glRotatef(neptuno, 0.0, 1.0, 0.0);
	glTranslatef(12.430, 0.2, 0);
	glColor3f(0.90, 0.80, 0.80);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.10, 14, 14);  //Draw Moon;
	glPopMatrix();
	glPushMatrix();

	glRotatef(saturno, 0.0, 1.0, 0.0);
	glTranslatef(12.30, -2.2, 0);
	glColor3f(0.70, 0.70, 0.90);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.70, 14, 14);  //Draw Moon;
	glPopMatrix();
	glPushMatrix();

	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glTranslatef(13.30, 0, 0);
	glColor3f(0.60, 0.90, 0.60);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.30, 14, 14);  //Draw Moon;
	glPopMatrix();
	glPushMatrix();

	glRotatef(urano, 0.0, 1.0, 0.0);

	glTranslatef(13.30, 4.4, 0);

	glColor3f(0.30, 0.40, 0.50);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.60, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(venus, 0.0, 1.0, 0.0);

	glTranslatef(12.30, 0.1, 0);

	glColor3f(0.10, 0.30, 0.50);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.10, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(mercurio, 0.0, 1.0, 0.0);

	glTranslatef(12.50, 2.2, 0);

	glColor3f(0.60, 0.50, 0.50);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.80, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(urano, 0.0, 1.0, 0.0);

	glTranslatef(12.350, 0.3, 0);

	glColor3f(034, 0.43, 0.67);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.90, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(tierra, 0.0, 1.0, 0.0);

	glTranslatef(12.50, -3.3, 0);

	glColor3f(0.78, 0.12, 0.21);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.40, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(jupiter, 0.0, 1.0, 0.0);

	glTranslatef(12.30, 7.0, 0);

	glColor3f(0.40, 0.50, 0.20);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.50, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPopMatrix();



	glPushMatrix();

	glRotatef(saturno, 0.0, 1.0, 0.0);	//gira sobre su eje

	glTranslatef(115.40, 0, 0);

	glColor3f(0.36, 0.25, 0.20);	//Saturno

	glutSolidSphere(9.41, 14, 14);

	glPushMatrix();



	glRotatef(urano, 0.0, 1.0, 0.0);

	glTranslatef(12.350, 6.3, 0);

	glColor3f(0.30, 0.90, 0.90);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.90, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(tierra, 0.0, 1.0, 0.0);

	glTranslatef(12.50, -7.3, 0);

	glColor3f(0.90, 0.30, 0.90);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.40, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(jupiter, 0.0, 1.0, 0.0);

	glTranslatef(12.30, 12.0, 0);

	glColor3f(0.90, 0.90, 0.30);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.50, 14, 14);  //Draw Moon;

	glPopMatrix();
	   	  
	glPushMatrix();
	   	//glTranslatef(115.40, 0, 0);
	glRotatef(saturno, 0.0, 1.0, 0.0);	//gira sobre su eje	
	glRotatef(90, 1, 0, 0);
	glScalef(1.0, 1.0, 0.1);
	glColor3f(0.30, 0.40, 0.5);	//anillos
	glutSolidTorus(3.5, 12.0, 3, 20);
	glPopMatrix();



	glPopMatrix();
	glPushMatrix();
	glRotatef(urano, 0.0, 1.0, 0.0);	//gira sobre su eje
	glTranslatef(212.0, 0, 0);
	glColor3f(0.0, 0.20, 0.7);	//Urano
	glutSolidSphere(4.0, 14, 14);
	glPushMatrix();
	glRotatef(saturno, 0.0, 1.0, 0.0);
	glTranslatef(4.30, -2.2, 0);
	glColor3f(0.90, 0.10, 0.50);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.70, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(jupiter, 0.0, 1.0, 0.0);

	glTranslatef(4.10, 0, 0);

	glColor3f(0.90, 0.80, 0.70);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.30, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(urano, 0.0, 1.0, 0.0);

	glTranslatef(5.0, 0.4, 0);

	glColor3f(0.50, 0.60, 0.70);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.60, 14, 14);  //Draw Moon;

	glPopMatrix();



	glPopMatrix();



	glPushMatrix();

	glRotatef(neptuno, 0.0, 1.0, 0.0);	//gira sobre su eje

	glTranslatef(320.0, 0, 0);

	glColor3f(0.0, 0.0, 0.3);	//Neptuno

	glutSolidSphere(3.8, 14, 14);



	glPushMatrix();



	glRotatef(saturno, 0.0, 1.0, 0.0);

	glTranslatef(4.35, -1.2, 0);

	glColor3f(0.10, 0.20, 0.30);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.70, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(jupiter, 0.0, 1.0, 0.0);

	glTranslatef(4.40, 0.2, 0);

	glColor3f(0.30, 0.20, 0.10);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.30, 14, 14);  //Draw Moon;

	glPopMatrix();

	glPushMatrix();



	glRotatef(urano, 0.0, 1.0, 0.0);

	glTranslatef(4.80, 1.4, 0);

	glColor3f(0.70, 0.60, 0.50);	//Luna
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.60, 14, 14);  //Draw Moon;

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}



void animacion()

{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;



	//Velocidades de traslación alrededor del sol



	if (dwElapsedTime >= parametro)

	{

		sol = (sol + 1) % 360;

		mercurio = (mercurio + 8) % 360;

		venus = (venus + 7) % 360;

		tierra = (tierra + 6) % 360;

		marte = (marte + 5) % 360;

		jupiter = (jupiter + 4) % 360;

		saturno = (saturno + 3) % 360;

		urano = (urano + 2) % 360;

		neptuno = (neptuno + 1) % 360;



		dwLastUpdateTime = dwCurrentTime;

	}



	glutPostRedisplay();

}



void reshape(int width, int height)   // Creamos funcion Reshape

{

	if (height == 0)										// Prevenir division entre cero

	{

		height = 1;

	}



	glViewport(0, 0, width, height);



	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix

	glLoadIdentity();



	// Tipo de Vista



	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 600.0);



	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix

	//glLoadIdentity();

}



void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function

{

	switch (key) {

	case 'w':   //Movimientos de camara

	case 'W':

		camaraZ += 0.5f;

		break;

	case 's':

	case 'S':

		camaraZ -= 0.5f;

		break;

	case 'a':

	case 'A':

		camaraX -= 0.5f;

		break;

	case 'd':

	case 'D':

		camaraX += 0.5f;

		break;



	case 'i':		//Movimientos de Luz

	case 'I':



		break;

	case 'k':

	case 'K':



		break;
	case 'l':   //Activamos/desactivamos luz
	case 'L':
		light = !light;
		break;

		//Botón de Pausa

	case 'p':
	case 'P':
		if (parametro == 30)
		{
			parametro = -1;
		}

		break;

		//Botón de reinicio

	case 'O':
	case 'o':
		if (parametro == -1)
		{
			parametro = 30;
		}
		break;
	
	case 27:        // Cuando Esc es presionado...

		exit(0);   // Salimos del programa

		break;

	default:        // Cualquier otra

		break;

	}

	glutPostRedisplay();

}



void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)

{

	switch (a_keys) {

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA, rota en eje x...

		RotarX += 0.5f;

		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO rota en eje x...

		RotarX -= 0.5f;

		break;

	case GLUT_KEY_LEFT:



		break;

	case GLUT_KEY_RIGHT:



		break;

	default:

		break;

	}

	glutPostRedisplay();

}





int main(int argc, char** argv)   // Main Function

{

	glutInit(&argc, argv); // Inicializamos OpenGL

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )

	glutInitWindowSize(800, 800);	// Tamaño de la Ventana

	glutInitWindowPosition(20, 60);	//Posicion de la Ventana

	glutCreateWindow("Práctica 6"); // Nombre de la Ventana

	InitGL();						// Parametros iniciales de la aplicacion

	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo

	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano

	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado

	glutSpecialFunc(arrow_keys);	//Otras

	glutIdleFunc(animacion);

	glutMainLoop();          // 



	return 0;

}