//Semestre 2017 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Augusto Meza Peña				        ******//
//*************	Muñoz Alvarez Rosa Maria Yolotzin		******//
//************************************************************//
#include "Main.h"

DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

bool boca_open = true;

double tetera[3] = {0.7882,0.7490,0.6352};
double tetera_sombra[3] = { 0.5450,0.5176,0.4352};
double tetera_luz[3] = {0.9450,0.9058,0.7803};
double hair[3] = {0.3568,0.3176,0.2078};
double skin[3] = {0.8470,0.7254,0.5647};
double nose[3] = {0.8627,0.6666,0.5960};
double teeth[3] = {0.9294,0.9058,0.7921};
double boca[3] = {0.5529,0.3882,0.2980};
double lengua[3] = {0.8117,0.4823,0.4352};
double oberol[3] = {0.4666,0.5254,0.4117};
double shirt[3] = {0.8745,0.8470,0.7607};
double strip[3] = {0.3254,0.2352,0.1058 };
double back[3] = {0.3607,0.3098,0.2156};
double bag[3] = {0.4588,0.3921,0.2747};
double coin[3] = {0.6666,0.5607,0.3294};
double coin_luz[3] = {0.7843,0.7098,0.4078};
double shirt_sombra[3] = { 0.8039,0.7764, 0.6941};
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				//Blanco de fondo
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview
	glLineWidth(3.0);

	glBegin(GL_QUADS);
	// Prueba
	if (boca_open) {
		glColor3f(boca[0], boca[1], boca[2]);
	}
	else {
		glColor3f(skin[0], skin[1], skin[2]);
	}
	glVertex3d(474, 545, -0.2);
	glVertex3d(723, 719, -0.2);
	glVertex3d(687, 633, -0.2);
	glVertex3d(556, 507, -0.2);
	glEnd();

	//Augusto


	//Rosa

	glFlush();
}
 
void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	glOrtho(0,1600,900,0,0.1,2);//COORDENADAS

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	 glutPostRedisplay();
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 480)
	{
		boca_open = !boca_open;
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (1600, 900);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Greg"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutIdleFunc		  (animacion);
  glutMainLoop        ( );          // 

  return 0;
}