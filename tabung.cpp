#include <windows.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<math.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int ,int);
void mouse(int button, int state, int x, int y);
void ukuran(int,int);
void mouseMotion(int x, int y);

bool atap = true;
int is_depth;
float xrot = 0.0f;
float yrot = 0.0f;
float xtrans = 0.0f;
float ytrans = 0.0f;
float ztrans = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	
	glutInitWindowSize(800,600);
	glutInitWindowPosition(250,80);
	glutCreateWindow("YULIUS - 672019014");
	glEnable( GL_BLEND );
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
	glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	
    glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void){
	glClearColor (0,0,0,0);
	glMatrixMode(GL_PROJECTION);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void ngon(int n, float cx, float cy, float cz,float tinggi, float radius, float rotAngle){
    double angle, angleInc;
    int k;

    if(n<3) return;
    angle=3.14159265/180;
    angleInc=2*3.14159265/n;
  	
    //ini titik berikutnya
    for(k=0;k<n;k++){
//    	angle=(20*k)*3.14159265/n;
        glVertex3f((radius)*cos(angle)+cx, cy,(radius)*sin(angle)+cz);
      angle+=angleInc;
    }
    
    for(k=0;k<n;k++){
//    	angle=(20*k)*3.14159265/n;
        glVertex3f((radius)*cos(angle)+cx, cy+tinggi,(radius)*sin(angle)+cz);
      angle+=angleInc;
    }
}

void balok(float cx,float cy,float cz, float panjang, float lebar, float tinggi){
	glBegin(GL_QUADS);
	//Bangun Depan
	glVertex3f(cx,cy,cz);
	glVertex3f(cx+panjang,cy,cz);
	glVertex3f(cx+panjang,cy+tinggi,cz);
	glVertex3f(cx,cy+tinggi,cz);
	
	//Bangun Kiri
	glVertex3f(cx,cy,cz);
	glVertex3f(cx,cy,cz+lebar);
	glVertex3f(cx,cy+tinggi,cz+lebar);
	glVertex3f(cx,cy+tinggi,cz);
	
	//Bangun Kanan
	glVertex3f(cx+panjang,cy,cz);
	glVertex3f(cx+panjang,cy,cz+lebar);
	glVertex3f(cx+panjang,cy+tinggi,cz+lebar);
	glVertex3f(cx+panjang,cy+tinggi,cz);
	
	//Bangun Belakang
	glVertex3f(cx,cy,cz+lebar);
	glVertex3f(cx+panjang,cy,cz+lebar);
	glVertex3f(cx+panjang,cy+tinggi,cz+lebar);
	glVertex3f(cx,cy+tinggi,cz+lebar);
	
	// Bangun atas
	glVertex3f(cx,cy+tinggi,cz);
	glVertex3f(cx+panjang,cy+tinggi,cz);
	glVertex3f(cx+panjang,cy+tinggi,cz+lebar);
	glVertex3f(cx,cy+tinggi,cz+lebar);
	
	// Bangun Bawah
	glVertex3f(cx,cy,cz);
	glVertex3f(cx+panjang,cy,cz);
	glVertex3f(cx+panjang,cy,cz+lebar);
	glVertex3f(cx,cy,cz+lebar);
	
	glEnd();	
}

void tampil(void){
	if (is_depth) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else glClear(GL_COLOR_BUFFER_BIT);
	
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(xtrans,ytrans,ztrans);
    glPushMatrix();
    glColor3f(0,1,1);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.8f, 0.0f);
	    glVertex3f(20, -25.0, 40);
	    glVertex3f(20, 10.0, 40);
	    glVertex3f(-20, 10.0, 40);
	    glVertex3f(-20, -25.0, 40);
	    glVertex3f(20, -25.0, 0);
	    glVertex3f(20, 10.0, 0);
	    glVertex3f(-20, 10.0, 0);
	    glVertex3f(-20, -25.0, 0);
	    
	    glVertex3f(30, -25.0, -150);
	    glVertex3f(30, 10.0, -150);
	    glVertex3f(-30, 10.0, -150);
	    glVertex3f(-30, -25.0, -150);
	    glVertex3f(30, -25.0, -90);
	    glVertex3f(30, 10.0, -90);
	    glVertex3f(-30, 10.0, -90);
	    glVertex3f(-30, -25.0, -90);
    glEnd();
    //atap depan
    glBegin(GL_TRIANGLES);
    	glColor3f(0.8f, 0.6f, 0.0f);
    	glVertex3f(0,30,20);
    	glColor3f(1.0f, 0.8f, 0.0f);
    	glVertex3f(-30,10,50);
    	glVertex3f(30,10,50);
		
		glColor3f(0.8f, 0.6f, 0.0f);
    	glVertex3f(0,30,20);
    	glColor3f(1.0f, 0.8f, 0.0f);
    	glVertex3f(30,10,50);
    	glVertex3f(30,10,-10);
  		
  		glColor3f(0.8f, 0.6f, 0.0f);
    	glVertex3f(0,30,20);
    	glColor3f(1.0f, 0.8f, 0.0f);
    	glVertex3f(30,10,-10);
    	glVertex3f(-30,10,-10);
    
    	glColor3f(0.8f, 0.6f, 0.0f);
    	glVertex3f(0,30,20);
    	glColor3f(1.0f, 0.8f, 0.0f);
    	glVertex3f(-30,10,50);
    	glVertex3f(-30,10,-10);
    glEnd();
    
    //atap tengah
//    glColor3f(0,1,0);
    glBegin(GL_QUADS);
    	glColor3f(0.8f, 0.6f, 0.0f);
	    glVertex3f(0,25,13);
	    glColor3f(1.0f, 0.8f, 0.0f);
	    glVertex3f(25,10,-10);
	    glVertex3f(25,10,-25);
	    glColor3f(0.8f, 0.6f, 0.0f);
	    glVertex3f(0,25,-50);
	    
	    glColor3f(0.8f, 0.6f, 0.0f);
	    glVertex3f(0,25,13);
	    glColor3f(1.0f, 0.8f, 0.0f);
	    glVertex3f(-25,10,-10);
	    glVertex3f(-25,10,-25);
	    glColor3f(0.8f, 0.6f, 0.0f);
	    glVertex3f(0,25,-50);
	    
	    glColor3f(0.8f, 0.6f, 0.0f);
	    glVertex3f(0,25,-35);
	    glColor3f(1.0f, 0.8f, 0.0f);
	    glVertex3f(25,10,-65);
	    glVertex3f(25,10,-80);
	    glColor3f(0.8f, 0.6f, 0.0f);
	    glVertex3f(0,25,-100);
	    
	    glColor3f(0.8f, 0.6f, 0.0f);
	    glVertex3f(0,25,-35);
	    glColor3f(1.0f, 0.8f, 0.0f);
	    glVertex3f(-25,10,-65);
	    glVertex3f(-25,10,-80);
	    glColor3f(0.8f, 0.6f, 0.0f);
	    glVertex3f(0,25,-100);
	    glColor3f(1.0f, 0.8f, 0.0f);
	glEnd();
	
	//atap tengah samping
//	glColor3f(0,1,1);
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.6f, 0.0f);
    glVertex3f(-6,21,-43);
    glColor3f(1.0f, 0.8f, 0.0f);
    glVertex3f(-25,10,-25);
    glVertex3f(-75,10,-25);
    glVertex3f(-75,21,-43);
    
    glColor3f(0.8f, 0.6f, 0.0f);
    glVertex3f(-6,21,-43);
    glColor3f(1.0f, 0.8f, 0.0f);
    glVertex3f(-25,10,-65);
    glVertex3f(-75,10,-65);
    glVertex3f(-75,21,-43);
    
    glColor3f(0.8f, 0.6f, 0.0f);
    glVertex3f(6,21,-43);
    glColor3f(1.0f, 0.8f, 0.0f);
    glVertex3f(25,10,-25);
    glVertex3f(75,10,-25);
    glVertex3f(75,21,-43);
    
    glColor3f(0.8f, 0.6f, 0.0f);
    glVertex3f(6,21,-43);
    glColor3f(1.0f, 0.8f, 0.0f);
    glVertex3f(25,10,-65);
    glVertex3f(75,10,-65);
    glVertex3f(75,21,-43);
    
//    glVertex3f(0,25,13);
//    glVertex3f(-25,10,-10);
//    glVertex3f(-25,10,-25);
//    glVertex3f(0,25,-50);
//    
//    
//    glVertex3f(0,25,-35);
//    glVertex3f(25,10,-65);
//    glVertex3f(25,10,-80);
//    glVertex3f(0,25,-100);
//    
//    glVertex3f(0,25,-35);
//    glVertex3f(-25,10,-65);
//    glVertex3f(-25,10,-80);
//    glVertex3f(0,25,-100);
	glEnd();

    //Atap belakang
    glBegin(GL_TRIANGLES);
    	glColor3f(0.8f, 0.6f, 0.0f);
		glVertex3f(0,40,-120);
    	glColor3f(1.0f, 0.8f, 0.0f);
    	glVertex3f(-40,10,-80);
    	glVertex3f(40,10,-80);

    	glColor3f(0.8f, 0.6f, 0.0f);
		glVertex3f(0,40,-120);
    	glColor3f(1.0f, 0.8f, 0.0f);
    	glVertex3f(40,10,-80);
    	glVertex3f(40,10,-160);
  
    	glColor3f(0.8f, 0.6f, 0.0f);
		glVertex3f(0,40,-120);
    	glColor3f(1.0f, 0.8f, 0.0f);
    	glVertex3f(40,10,-160);
    	glVertex3f(-40,10,-160);
    	
    	glColor3f(0.8f, 0.6f, 0.0f);
    	glVertex3f(0,40,-120);
    	glColor3f(1.0f, 0.8f, 0.0f);
    	glVertex3f(-40,10,-80);
    	glVertex3f(-40,10,-160);
    glEnd();
    
    
    
    
    //gedung tengah
    glBegin(GL_QUADS);
    	glVertex3f(10,10,0);
    	glVertex3f(10,10,-20);
    	glVertex3f(10,-25,-20);
    	glVertex3f(10,-25,0);
	glEnd();
	glBegin(GL_QUADS);
    	glVertex3f(-10,10,0);
    	glVertex3f(-10,10,-20);
    	glVertex3f(-10,-25,-20);
    	glVertex3f(-10,-25,0);
	glEnd();
//	glBegin(GL_QUADS);
//    	glVertex3f(5,10,0);
//    	glVertex3f(5,10,-20);
//    	glVertex3f(-5,10,-20);
//    	glVertex3f(-5,10,0);
//	glEnd();
//	//gedung kanan depan
//	glBegin(GL_QUADS);
//		glVertex3f(5,10,-20);
//		glVertex3f(205,10,-20);
//		glVertex3f(205,-25,-20);
//		glVertex3f(5,-25,-20);
//	glEnd();
//	glBegin(GL_QUADS);
//		glVertex3f(205,10,-20);
//		glVertex3f(205,10,-320);
//		glVertex3f(205,-25,-320);
//		glVertex3f(205,-25,-20);
//	glEnd();
//	glBegin(GL_QUADS);
//		glVertex3f(-10,10,-320);
//		glVertex3f(205,10,-320);
//		glVertex3f(205,-25,-320);
//		glVertex3f(-10,-25,-320);
//	glEnd();
//	//tengah lurus kebelakang
//	glColor3f(1,0,0);
//	glBegin(GL_QUADS);
//		glVertex3f(-10,10,-320);
//		glVertex3f(-10,10,-400);
//		glVertex3f(-10,-25,-400);
//		glVertex3f(-10,-25,-320);
//	glEnd();
//	//nyamping kanan dikit
//	glColor3f(1.0f, 0.8f, 0.0f);
//	glBegin(GL_QUADS);
//		glVertex3f(-10,10,-400);
//		glVertex3f(10,10,-400);
//		glVertex3f(10,-25,-400);
//		glVertex3f(-10,-25,-400);
//	glEnd();
//	//belakang lurus dikit
//	glBegin(GL_QUADS);
//		glVertex3f(10,10,-400);
//		glVertex3f(10,10,-450);
//		glVertex3f(10,-25,-450);
//		glVertex3f(10,-25,-400);
//	glEnd();
//	//belakang
//	glBegin(GL_QUADS);
//		glVertex3f(10,10,-450);
//		glVertex3f(-205,10,-450);
//		glVertex3f(-205,-25,-450);
//		glVertex3f(10,-25,-450);
//	glEnd();
//	//kiri samping
//	glBegin(GL_QUADS);
//		glVertex3f(-205,10,-450);
//		glVertex3f(-205,10,-20);
//		glVertex3f(-205,-25,-20);
//		glVertex3f(-205,-25,-450);
//	glEnd();
//	//gedung depan kiri
//	glBegin(GL_QUADS);
//		glVertex3f(-205,10,-20);
//		glVertex3f(-5,10,-20);
//		glVertex3f(-5,-25,-20);
//		glVertex3f(-205,-25,-20);
//	glEnd();
	glPopMatrix();	
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'w':
		case 'W':
			ztrans += 3;
		break;
		case 'd':
		case 'D':
			xtrans += 3;
		break;
		case 's':
		case 'S':
			ztrans -= 3;
		break;
		case 'a':
		case 'A':
			xtrans -= 3;
		break;
		case 'l':
		case 'L':
			ytrans += 3;
		break;
		case 'h':
		case 'H':
			ytrans -= 3;
		break;
		case '5':
			if(is_depth){
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			} else {
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
			
	}
		tampil();
}

void ukuran(int lebar ,int tinggi){
	if(tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80,lebar/tinggi,5,600);
	glTranslatef(0,-50,-200);
	glMatrixMode(GL_MODELVIEW);
}

void idle()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff= x - yrot;
        ydiff= -y +xrot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

