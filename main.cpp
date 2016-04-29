#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

GLfloat pos_x=0;
GLfloat pos_y=0;

GLint ancho=600;
GLint alto=600;

GLfloat mat_ambient[3]={0.19225, 0.19225, 0.19225};
GLfloat mat_diffuse[3]={0.50754, 0.50754, 0.50754};
GLfloat mat_specular[3]={0.508273, 0.508273, 0.508273};
GLfloat shine[] = {27.8974};

GLfloat punto_luz[3]={0.0, 0.0, 1.0};
GLfloat luz_ambiental[]={0.5, 0.0, 0.0};

void init(void)
{
  // Activamos la fuente de luz
  glClearColor (0.0, 0.0, 0.0, 0.0);
  //glShadeModel(GL_SMOOTH);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0); //Activamos las luces en 0
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiental);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  // Activamos la matriz de proyeccion.
  glMatrixMode(GL_PROJECTION);
  // "limpiamos" esta con la matriz identidad.
  glLoadIdentity();
  // Usamos proyeccion ortogonal
  glOrtho(0, 2, 0, 2, -2, 2);
  // Activamos la matriz de modelado/visionado.
  glMatrixMode(GL_MODELVIEW);
  // "Limpiamos" la matriz
  glLoadIdentity();
}

void display(void)
{
	// Propiedades del material
	// "Limpiamos" el frame buffer con el color de "Clear", en este
	// caso negro.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode( GL_MODELVIEW_MATRIX );
	glLoadIdentity();
	glPushMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, punto_luz);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
	glTranslated(1.0, 1.0, 0.0);
	glutSolidSphere(0.6, 50, 50);
	glFlush();
	glutSwapBuffers();
}

void cambiar_color_esfera (GLfloat ambient[], GLfloat diffuse[], GLfloat specular[])
{
	mat_ambient[0] = ambient[0];
	mat_ambient[1] = ambient[1];
	mat_ambient[2] = ambient[2];
	mat_diffuse[0] = diffuse[0];
	mat_diffuse[1] = diffuse[1];
	mat_diffuse[2] = diffuse[2];
	mat_specular[0] = specular[0];
	mat_specular[1] = specular[1];
	mat_specular[2] = specular[2];
}

void posicion_raton (int x, int y)
{
	pos_x=(GLfloat)x/(ancho/2);
	pos_y=2-(GLfloat)y/(alto/2);
	punto_luz[0]=pos_x;
	punto_luz[1]=pos_y;
	punto_luz[2]=1.0;
	glutPostRedisplay();
}

// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
	GLfloat ambient[3];
	GLfloat diffuse[3];
	GLfloat specular[3];
	GLfloat Shine[] = {0.4};
	switch (key)
    {
	case 'c':
		ambient[0]=0.19125;
		ambient[1]=0.0735;
		ambient[2]=0.0225;
		diffuse[0]=0.7038;
		diffuse[1]=0.27048;
		diffuse[2]=0.0828;
		specular[0]=0.256777;
		specular[1]=0.137622;
		specular[2]=0.086014;
		Shine[0] = 0.1;
		break;
	case 'r':
			ambient[0]=0.05;
			ambient[1]=0.0;
			ambient[2]=0.0;
			diffuse[0]=0.5;
			diffuse[1]=0.4;
			diffuse[2]=0.4;
			specular[0]=0.7;
			specular[1]=0.04;
			specular[2]=0.04;
			Shine[0] = 0.078125;
			break;
	case 'g' :
			ambient[0]=0.24725;
			ambient[1]=0.1995;
			ambient[2]=0.0745;
			diffuse[0]=0.75164;
			diffuse[1]=0.60648;
			diffuse[2]=0.22648;
			specular[0]=0.628281;
			specular[1]=0.555802;
			specular[2]=0.366065;
			Shine[0] = 0.4;
	break;
	case 'b' :
			ambient[0]=0.329412;
			ambient[1]=0.223529;
			ambient[2]=0.027451;
			diffuse[0]=0.780392;
			diffuse[1]=0.568627;
			diffuse[2]=0.113725;
			specular[0]=0.992157;
			specular[1]=0.941176;
			specular[2]=0.807843;
			Shine[0] = 27.8974;
      break;
    case 's' :
			ambient[0]=0.19225;
			ambient[1]=0.19225;
			ambient[2]=0.19225;
			diffuse[0]=0.50754;
			diffuse[1]=0.50754;
			diffuse[2]=0.50754;
			specular[0]=0.508273;
			specular[1]=0.508273;
			specular[2]=0.508273;
			Shine[0] = 0.4;
	  break;
    }
    cambiar_color_esfera(ambient, diffuse, specular);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	// Inicializo OpenGL}
	glutInit(&argc, argv);
	// Activamos buffer simple y colores del tipo RGB
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// Definimos una ventana de medidas 800 x 600 como ventana
	// de visualizacion en pixels
	glutInitWindowSize (600, 600);
	// Posicionamos la ventana en la esquina superior izquierda de
	// la pantalla.
	glutInitWindowPosition (0, 0);
	// Creamos literalmente la ventana y le adjudicamos el nombre que se
	// observara en su barra de titulo.
	glutCreateWindow ("Esfera color");
	// Inicializamos el sistema
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(posicion_raton);
	glutMainLoop();
	return 0;
}
