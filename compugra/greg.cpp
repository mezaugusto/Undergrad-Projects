//Semestre 2017 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Augusto Meza Peña				        ******//
//*************	Muñoz Alvarez Rosa Maria Yolotzin		******//
//************************************************************//
#include "Main.h"
int c = 0;
int a = 1;
int m = 2;
int star = 3;
double colors[4][3] = {
	{0.9098, 0.7882, 0.364},//Beige
	{0.8196, 0.4196, 0.3294 }, //Cereza
	{0.6627, 0.8470, 0.7843}, //Azul
	{0.2627, 0.2039, 0.2784} //Morado
};
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview


	glPointSize(5.0);
	glLineWidth(4.0);

	/*glBegin(GL_LINE_LOOP);
		glVertex3f(1.0, 1.0, -0.2);
		glVertex3f(1.0, 8.0, -0.2);
		glVertex3f(5.0, 8.0, -0.2);
		glVertex3f(5.0, 6.0, -0.2);
		glVertex3f(2.8, 6.0, -0.2);
		glVertex3f(2.8, 3.0, -0.2);
		glVertex3f(5.0, 3.0, -0.2);
		glVertex3f(5.0, 1.0, -0.2);
	glEnd();*/

	glBegin(GL_QUADS);
	// Letra C
	glColor3f(colors[c][0], colors[c][1], colors[c][2]);
		glVertex3f(1.0, 1.0, -0.2);
		glVertex3f(2.8, 3.0, -0.2);
		glVertex3f(5.0, 3.0, -0.2);
		glVertex3f(5.0, 1.0, -0.2);

		glVertex3f(1.0, 1.0, -0.2);
		glVertex3f(1.0, 8.0, -0.2);
		glVertex3f(2.8, 6.0, -0.2);
		glVertex3f(2.8, 3.0, -0.2);

		glVertex3f(1.0, 8.0, -0.2);
		glVertex3f(5.0, 8.0, -0.2);
		glVertex3f(5.0, 6.0, -0.2);
		glVertex3f(2.8, 6.0, -0.2);
	//Letra A
	glColor3f(colors[a][0], colors[a][1], colors[a][2]);

		glVertex3f(6.0, 1.0, -0.2);
		glVertex3f(9.0, 8.0, -0.2);
		glVertex3f(9.0, 6.0, -0.2);
		glVertex3f(7.0, 1.0, -0.2);

		glVertex3f(9.0, 8.0, -0.2);
		glVertex3f(9.0, 6.0, -0.2);
		glVertex3f(11.0, 1.0, -0.2);
		glVertex3f(12.0, 1.0, -0.2);

		glVertex3f(8.2, 4.0, -0.2);
		glVertex3f(9.8, 4.0, -0.2);
		glVertex3f(10.2, 3.0, -0.2);
		glVertex3f(7.8, 3.0, -0.2);
	//Letra M
	glColor3f(colors[m][0], colors[m][1], colors[m][2]);

		glVertex3f(13.0, 1.0, -0.2);
		glVertex3f(13.0, 8.0, -0.2);
		glVertex3f(14.0, 5.5, -0.2);
		glVertex3f(14.0, 1.0, -0.2);

		glVertex3f(13.0, 8.0, -0.2);
		glVertex3f(16.0, 5.0, -0.2);
		glVertex3f(16.0, 3.5, -0.2);
		glVertex3f(14.0, 5.5, -0.2);

		glVertex3f(16.0, 3.5, -0.2);
		glVertex3f(16.0, 5.0, -0.2);
		glVertex3f(19.0, 8.0, -0.2);
		glVertex3f(18.0, 5.5, -0.2);

		glVertex3f(19.0, 8.0, -0.2);
		glVertex3f(19.0, 1.0, -0.2);
		glVertex3f(18.0, 1.0, -0.2);
		glVertex3f(18.0, 5.5, -0.2);

	glEnd();

	//Estrella
	glBegin(GL_POLYGON);
	glColor3f(colors[star][0], colors[star][1], colors[star][2]);
		glVertex3f(25.0, 3.0, -0.2);
		glVertex3f(26.2, 4.2, -0.2);
		glVertex3f(26.0, 6.0, -0.2);
		glVertex3f(24.0, 6.0, -0.2);
		glVertex3f(23.8, 4.2, -0.2);
	glEnd(); 

	glBegin(GL_TRIANGLES);
	glColor3f(colors[star][0], colors[star][1], colors[star][2]);

		glVertex3f(24.0, 6.0, -0.2);
		glVertex3f(25.0, 8.5, -0.2);
		glVertex3f(26.0, 6.0, -0.2);

		glVertex3f(26.0, 6.0, -0.2);
		glVertex3f(28.5, 6.0, -0.2);
		glVertex3f(26.2, 4.2, -0.2);

		glVertex3f(26.2, 4.2, -0.2);
		glVertex3f(27.0, 1.8, -0.2);
		glVertex3f(25.0, 3.0, -0.2);

		glVertex3f(25.0, 3.0, -0.2);
		glVertex3f(23.0, 1.8, -0.2);
		glVertex3f(23.8, 4.2, -0.2);

		glVertex3f(24.0, 6.0, -0.2);
		glVertex3f(21.5, 6.0, -0.2);
		glVertex3f(23.8, 4.2, -0.2);
	glEnd();

	/*Poner aqui codigo ha dibujar
	glBegin(GL_POLYGON); //POLYGON, QUADS, TRANGLES, STRIP, FAN
	glColor3f(0.2, 0.84, 0.87);
		glVertex3f(0.0, 0.0, -0.2); //regla de union: orden de aparicion de vertices
		glVertex3f(5.0, 0.0, -0.2);
	glColor3f(1.0, 1.0, 1.0);
		glVertex3f(6.0, 5.0, -0.2);	
	glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-2.0, 6.0, -0.2);
		glVertex3f(-14.0, 3.0, -0.2);
	glEnd();*/

	/*glBegin(GL_POINTS); LINES
		glVertex3f(-4.0, 3.0, -0.2);
	glEnd();*/



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

	// Ortogonal
	glOrtho(0,30,0,10,0.1,2);//COORDENADAS

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
		case 'c':
			if (c == 3) {
				c = 0;
				a = 1;
				m = 2;
				star = 3;
			}
			else {
				int temp = c;
				c = a;
				a = m;
				m = star;
				star = temp;
			}
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
  glutMainLoop        ( );          // 

  return 0;
}