/*
Nama Kelompok : Cuan
Nama Anggota Kelompok :
Immanuel Yosian Leo Pratama - 672019228
Yulius - 672019014
David Aryo Wicaksono - 672019307
Elsha Yuandini Dewasasmita - 672019321
*/

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

float tangga (float x_awal, float y_awal, float z_awal,float anak_tangga,float lebar_tangga,int jenis,float rotAngle,float a,float b, float c){
	int i;
	switch(jenis){
		case 1:
			glPushMatrix();
			glRotatef(rotAngle,0,1,0);
			glTranslatef(-x_awal,-y_awal,-z_awal);
			glTranslatef(-x_awal+a,y_awal+b,-z_awal+c);
			//Tangga atas
			glBegin(GL_QUADS);
			glColor3f(1,0,0);
			glVertex3f(x_awal,y_awal+anak_tangga*2+2,z_awal-anak_tangga*2);
			glVertex3f(x_awal + lebar_tangga*2 + 3,y_awal+anak_tangga*2+2,z_awal-anak_tangga*2);
			glVertex3f(x_awal + lebar_tangga*2 + 3,y_awal+anak_tangga*2+2,z_awal-anak_tangga*2-7);
			glVertex3f(x_awal,y_awal+anak_tangga*2+2,z_awal-anak_tangga*2-7);
			glEnd();
			for(i=0;i<=anak_tangga*2;i+=2){
				glBegin(GL_QUADS);
				glColor3f(1,0,0);
				glVertex3f(x_awal,y_awal+2+i,z_awal-i);
				glVertex3f(x_awal+lebar_tangga,y_awal+2+i,z_awal-i);
				glVertex3f(x_awal+lebar_tangga,y_awal+2+i,z_awal-2-i);
				glVertex3f(x_awal,y_awal+2+i,z_awal-2-i);
				
				glColor3f(0.7,0,0);
				glVertex3f(x_awal,y_awal+i,z_awal-i);
				glVertex3f(x_awal+lebar_tangga,y_awal+i,z_awal-i);
				glVertex3f(x_awal+lebar_tangga,y_awal+2+i,z_awal-i);
				glVertex3f(x_awal,y_awal+2+i,z_awal-i);
				
				glColor3f(1,0,0);
				glVertex3f(x_awal+lebar_tangga*2+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+i);
				glVertex3f(x_awal+lebar_tangga+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+i);
				glVertex3f(x_awal+lebar_tangga+3,i+y_awal+anak_tangga*2+2,z_awal-anak_tangga*2+i);
				glVertex3f(x_awal+lebar_tangga*2+3,i+y_awal+anak_tangga*2+2,z_awal-anak_tangga*2+i);
				
				glColor3f(0.7,0,0);
				glVertex3f(x_awal+lebar_tangga*2+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+i);
				glVertex3f(x_awal+lebar_tangga+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+i);
				glVertex3f(x_awal+lebar_tangga+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+2+i);
				glVertex3f(x_awal+lebar_tangga*2+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+2+i);
				glEnd();
				
				glBegin(GL_TRIANGLES);
				glColor3f(0.7,0,0);
				glVertex3f(x_awal+lebar_tangga,y_awal+i,z_awal-i);
				glVertex3f(x_awal+lebar_tangga,y_awal+2+i,z_awal-i);
				glVertex3f(x_awal+lebar_tangga,y_awal+2+i,z_awal-2-i);
				
				glVertex3f(x_awal,y_awal+i,z_awal-i);
				glVertex3f(x_awal,y_awal+2+i,z_awal-i);
				glVertex3f(x_awal,y_awal+2+i,z_awal-2-i);
				
				glVertex3f(x_awal+lebar_tangga+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+i);
				glVertex3f(x_awal+lebar_tangga+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+2+i);
				glVertex3f(x_awal+lebar_tangga+3,i+y_awal+anak_tangga*2+2,z_awal-anak_tangga*2+i);
				
				glVertex3f(x_awal+lebar_tangga*2+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+i);
				glVertex3f(x_awal+lebar_tangga*2+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+2+i);
				glVertex3f(x_awal+lebar_tangga*2+3,i+y_awal+anak_tangga*2+2,z_awal-anak_tangga*2+i);
				
				if(i < anak_tangga*2){
					glVertex3f(x_awal+lebar_tangga,y_awal+2+i,z_awal-i);
					glVertex3f(x_awal+lebar_tangga,y_awal+2+i,z_awal-2-i);
					glVertex3f(x_awal+lebar_tangga,y_awal+4+i,z_awal-2-i);
					
					glVertex3f(x_awal,y_awal+2+i,z_awal-i);
					glVertex3f(x_awal,y_awal+2+i,z_awal-2-i);
					glVertex3f(x_awal,y_awal+4+i,z_awal-2-i);
					
					glVertex3f(x_awal+lebar_tangga+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+i);
					glVertex3f(x_awal+lebar_tangga+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+2+i);
					glVertex3f(x_awal+lebar_tangga+3,i+y_awal+anak_tangga*2+6,z_awal-anak_tangga*2+2+i);
					
					glVertex3f(x_awal+lebar_tangga*2+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+i);
					glVertex3f(x_awal+lebar_tangga*2+3,i+y_awal+anak_tangga*2+4,z_awal-anak_tangga*2+2+i);
					glVertex3f(x_awal+lebar_tangga*2+3,i+y_awal+anak_tangga*2+6,z_awal-anak_tangga*2+2+i);	
				}
					
				glEnd();
			}
			
			glBegin(GL_QUADS);
			glVertex3f(x_awal+lebar_tangga,y_awal+2,z_awal);
			glVertex3f(x_awal+lebar_tangga,y_awal+2+anak_tangga,z_awal);
			glVertex3f(x_awal+lebar_tangga,y_awal+anak_tangga*2+12,z_awal-anak_tangga*2);
			glVertex3f(x_awal+lebar_tangga,y_awal+2+anak_tangga*2,z_awal-anak_tangga*2);
			
			glVertex3f(x_awal,y_awal+2,z_awal);
			glVertex3f(x_awal,y_awal+anak_tangga+2,z_awal);
			glVertex3f(x_awal,y_awal+anak_tangga*2+12,z_awal-anak_tangga*2);
			glVertex3f(x_awal,y_awal+anak_tangga*2+2,z_awal-anak_tangga*2);
			
			glVertex3f(x_awal+lebar_tangga+3,y_awal+anak_tangga*2+4,z_awal-anak_tangga*2);
			glVertex3f(x_awal+lebar_tangga+3,y_awal+anak_tangga*2+14,z_awal-anak_tangga*2);
			glVertex3f(x_awal+lebar_tangga+3,y_awal+anak_tangga*4+14,z_awal);
			glVertex3f(x_awal+lebar_tangga+3,y_awal+anak_tangga*4+4,z_awal);
			
			glVertex3f(x_awal+lebar_tangga*2+3,y_awal+anak_tangga*2+4,z_awal-anak_tangga*2);
			glVertex3f(x_awal+lebar_tangga*2+3,y_awal+anak_tangga*2+14,z_awal-anak_tangga*2);
			glVertex3f(x_awal+lebar_tangga*2+3,y_awal+anak_tangga*4+14,z_awal);
			glVertex3f(x_awal+lebar_tangga*2+3,y_awal+anak_tangga*4+4,z_awal);
			glEnd();
			
			glPopMatrix();
		break;
	}
			
}

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
    //Tangga Gedung Kiri Depan
    tangga(0,0,0,10,15,1,180,190,10,47);
    tangga(0,0,0,8,15,1,180,190,-25,44);
	
	//Tangga Gedung Kanan depan
	tangga(0,0,0,10,15,1,180,-225,10,48);
	tangga(0,0,0,8,15,1,180,-225,-25,48);
	
	//Tangga Gedung Belakang Kiri
	tangga(0,0,0,8,15,1,0,-225,-25,-426);
	
	//Tangga Gedung Belakang Kanan
	tangga(0,0,0,8,15,1,0,190,-25,-316);
	
    glColor3f(0,1,1);
	glBegin(GL_LINES);
    glColor3f(1.0f, 0.8f, 0.0f);
	    glVertex3f(10, -25.0, 20);
	    glVertex3f(10, 15.0, 20);
	    glVertex3f(-10, 15.0, 20);
	    glVertex3f(-10, -25.0, 20);
	    glVertex3f(10, -25.0, 0);
	    glVertex3f(10, 15.0, 0);
	    glVertex3f(-10, 15.0, 0);
	    glVertex3f(-10, -25.0, 0);
    glEnd();
    //atap depan
    glBegin(GL_POLYGON);
    	glVertex3f(0,25,10);
    	glVertex3f(-20,15,20);
    	glVertex3f(20,15,20);
    glEnd();
    glBegin(GL_POLYGON);
    	glVertex3f(0,25,10);
    	glVertex3f(20,15,20);
    	glVertex3f(20,15,0);
    glEnd();
    glBegin(GL_POLYGON);
    	glVertex3f(0,25,10);
    	glVertex3f(20,15,0);
    	glVertex3f(-20,15,0);
    glEnd();
    glBegin(GL_POLYGON);
    	glVertex3f(0,25,10);
    	glVertex3f(-20,15,0);
    	glVertex3f(-20,15,20);
    glEnd();
    //gedung tengah
    glBegin(GL_QUADS);
    	glVertex3f(5,10,0);
    	glVertex3f(5,10,-20);
    	glVertex3f(5,-25,-20);
    	glVertex3f(5,-25,0);
	glEnd();
	glBegin(GL_QUADS);
    	glVertex3f(-5,10,0);
    	glVertex3f(-5,10,-20);
    	glVertex3f(-5,-25,-20);
    	glVertex3f(-5,-25,0);
	glEnd();
	glBegin(GL_QUADS);
    	glVertex3f(5,10,0);
    	glVertex3f(5,10,-20);
    	glVertex3f(-5,10,-20);
    	glVertex3f(-5,10,0);
	glEnd();
	//atap kanan
	glColor3f(0.258824,0.258824,0.435294);
	glBegin(GL_POLYGON);
		glVertex3f(55,100,0);
		glVertex3f(105,130,-60);
		glVertex3f(200,130,-60);
		glVertex3f(250,100,0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(55,100,-120);
		glVertex3f(105,130,-60);
		glVertex3f(200,130,-60);
		glVertex3f(250,100,-120);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(200,130,-60);
		glVertex3f(250,100,0);
		glVertex3f(250,100,-120);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(105,130,-60);
		glVertex3f(55,100,0);
		glVertex3f(55,100,-120);
	glEnd();
	//gedung kanan depan
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(10,10,-20);
		glVertex3f(230,10,-20);
		glVertex3f(230,-25,-20);
		glVertex3f(10,-25,-20);
	glEnd();
	//bagian atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(75,100,-20);
		glVertex3f(230,100,-20);
		glVertex3f(230,10,-20);
		glVertex3f(75,10,-20);
	glEnd();
	//gedung kanan depan
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(5,10,-100);
		glVertex3f(180,10,-100);
		glVertex3f(180,-25,-100);
		glVertex3f(5,-25,-100);
	glEnd();
	//bagian atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(75,100,-100);
		glVertex3f(180,100,-100);
		glVertex3f(180,10,-100);
		glVertex3f(75,10,-100);
	glEnd();
//	glBegin(GL_QUADS);
//	glColor3f(0.35, 0.16, 0.14);
//		glVertex3f(75,100,-20);
//		glVertex3f(75,100,-100);
//		glVertex3f(75,10,-100);
//		glVertex3f(75,10,-20);
//	glEnd();
	//samping kanan
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(230,10,-20);
		glVertex3f(230,10,-340);
		glVertex3f(230,-25,-340);
		glVertex3f(230,-25,-20);
	glEnd();
	//samping kanan atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(230,100,-20);
		glVertex3f(230,100,-100);
		glVertex3f(230,10,-100);
		glVertex3f(230,10,-20);
	glEnd();
	//samping kanan atas gedung 1nya
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
		glVertex3f(230,70,-100);
		glVertex3f(230,70,-340);
		glVertex3f(230,10,-340);
		glVertex3f(230,10,-100);
	glEnd();
	//samping kanan
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(180,10,-100);
		glVertex3f(180,10,-280);
		glVertex3f(180,-25,-280);
		glVertex3f(180,-25,-100);
	glEnd();
	//samping kanan atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(180,70,-100);
		glVertex3f(180,70,-280);
		glVertex3f(180,10,-280);
		glVertex3f(180,10,-100);
	glEnd();
	//atap
	glColor3f(0.258824,0.258824,0.435294);
	glBegin(GL_POLYGON);
		glVertex3f(240,70,-100);
		glVertex3f(200,90,-130);
		glVertex3f(200,90,-310);
		glVertex3f(240,70,-350);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(160,70,-100);
		glVertex3f(200,90,-130);
		glVertex3f(200,90,-310);
		glVertex3f(160,70,-270);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(200,90,-130);
		glVertex3f(160,70,-100);
		glVertex3f(240,70,-100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(240,70,-350);
		glVertex3f(200,90,-310);
		glVertex3f(90,90,-310);
		glVertex3f(75,70,-350);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(160,70,-270);
		glVertex3f(200,90,-310);
		glVertex3f(90,90,-310);
		glVertex3f(75,70,-270);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(90,90,-310);
		glVertex3f(75,70,-350);
		glVertex3f(75,70,-270);
	glEnd();
	//belakang
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-35,10,-340);
		glVertex3f(230,10,-340);
		glVertex3f(230,-25,-340);
		glVertex3f(-35,-25,-340);
	glEnd();
	//belakang atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(75,70,-340);
		glVertex3f(230,70,-340);
		glVertex3f(230,10,-340);
		glVertex3f(75,10,-340);
	glEnd();
	//belakang atas tengah
	glBegin(GL_QUADS);
		glVertex3f(75,70,-280);
		glVertex3f(75,70,-340);
		glVertex3f(75,-25,-340);
		glVertex3f(75,-25,-280);
	//belakang
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(75,10,-280);
		glVertex3f(180,10,-280);
		glVertex3f(180,-25,-280);
		glVertex3f(75,-25,-280);
	glEnd();
	//belakang atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(75,70,-280);
		glVertex3f(180,70,-280);
		glVertex3f(180,10,-280);
		glVertex3f(75,10,-280);
	glEnd();
	//tengah lurus kebelakang
	glColor3f(0,1,0);
	glBegin(GL_QUADS);
		glVertex3f(-35,10,-340);
		glVertex3f(-35,10,-400);
		glVertex3f(-35,-25,-400);
		glVertex3f(-35,-25,-340);
	glEnd();
	//atap
	glColor3f(0.258824,0.258824,0.435294);
	glBegin(GL_POLYGON);
		glVertex3f(20,50,-390);
		glVertex3f(0,65,-425);
		glVertex3f(-160,65,-425);
		glVertex3f(-180,50,-390);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(20,50,-465);
		glVertex3f(0,65,-425);
		glVertex3f(-160,65,-425);
		glVertex3f(-180,50,-465);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(0,65,-425);
		glVertex3f(20,50,-390);
		glVertex3f(20,50,-465);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(-160,65,-425);
		glVertex3f(-180,50,-390);
		glVertex3f(-180,50,-465);
	glEnd();
	//nyamping kanan dikit
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-10,10,-400);
		glVertex3f(10,10,-400);
		glVertex3f(10,-25,-400);
		glVertex3f(-10,-25,-400);
	glEnd();
	//nyamping kanan atas dikit
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(-10,50,-400);
		glVertex3f(10,50,-400);
		glVertex3f(10,10,-400);
		glVertex3f(-10,10,-400);
	glEnd();
	//nyamping kiri dikit
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(10,10,-400);
		glVertex3f(-180,10,-400);
		glVertex3f(-180,-25,-400);
		glVertex3f(-10,-25,-400);
	glEnd();
	//nyamping kiri atas dikit
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(10,50,-400);
		glVertex3f(-180,50,-400);
		glVertex3f(-180,10,-400);
		glVertex3f(10,10,-400);
	glEnd();
	//belakang lurus dikit
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(10,10,-400);
		glVertex3f(10,10,-450);
		glVertex3f(10,-25,-450);
		glVertex3f(10,-25,-400);
	glEnd();
	//belakang atas lurus dikit
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(10,50,-400);
		glVertex3f(10,50,-450);
		glVertex3f(10,10,-450);
		glVertex3f(10,10,-400);
	glEnd();
	//belakang
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(10,10,-450);
		glVertex3f(-230,10,-450);
		glVertex3f(-230,-25,-450);
		glVertex3f(10,-25,-450);
	glEnd();
	//belakang atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(10,50,-450);
		glVertex3f(-230,50,-450);
		glVertex3f(-230,10,-450);
		glVertex3f(10,10,-450);
	glEnd();
	//kiri samping
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-230,10,-450);
		glVertex3f(-230,10,-20);
		glVertex3f(-230,-25,-20);
		glVertex3f(-230,-25,-450);
	glEnd();
	//kiri samping atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(-230,70,-450);
		glVertex3f(-230,70,-100);
		glVertex3f(-230,10,-100);
		glVertex3f(-230,10,-450);
	glEnd();
	//kiri samping atas depan
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(-230,100,-100);
		glVertex3f(-230,100,-20);
		glVertex3f(-230,10,-20);
		glVertex3f(-230,10,-100);
	glEnd();
	//kiri samping
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-180,10,-400);
		glVertex3f(-180,10,-100);
		glVertex3f(-180,-25,-100);
		glVertex3f(-180,-25,-400);
	glEnd();
	//kiri samping atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(-180,70,-400);
		glVertex3f(-180,70,-100);
		glVertex3f(-180,10,-100);
		glVertex3f(-180,10,-400);
	glEnd();
	//kiri samping atas
	glBegin(GL_QUADS);
		glVertex3f(-180,100,-100);
		glVertex3f(-180,100,-20);
		glVertex3f(-180,10,-20);
		glVertex3f(-180,10,-100);
	glEnd();
	//atap
	glColor3f(0.258824,0.258824,0.435294);
	glBegin(GL_POLYGON);
		glVertex3f(-170,70,-100);
		glVertex3f(-205,90,-120);
		glVertex3f(-205,90,-430);
		glVertex3f(-170,70,-460);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-240,70,-100);
		glVertex3f(-205,90,-120);
		glVertex3f(-205,90,-430);
		glVertex3f(-240,70,-460);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(-205,90,-120);
		glVertex3f(-240,70,-100);
		glVertex3f(-170,70,-100);
	glEnd();
		glBegin(GL_TRIANGLES);
		glVertex3f(-205,90,-430);
		glVertex3f(-240,70,-460);
		glVertex3f(-170,70,-460);
	glEnd();
	//gedung depan kiri
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-230,10,-20);
		glVertex3f(-10,10,-20);
		glVertex3f(-10,-25,-20);
		glVertex3f(-230,-25,-20);
	glEnd();
	//gedung depan kiri atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(-230,100,-20);
		glVertex3f(-75,100,-20);
		glVertex3f(-75,10,-20);
		glVertex3f(-230,10,-20);
	glEnd();
	//gedung depan kiri
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-180,10,-100);
		glVertex3f(-10,10,-100);
		glVertex3f(-10,-25,-100);
		glVertex3f(-180,-25,-100);
	glEnd();
	//gedung depan kiri atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(-180,100,-100);
		glVertex3f(-75,100,-100);
		glVertex3f(-75,10,-100);
		glVertex3f(-180,10,-100);
	glEnd();
	//atap
	glColor3f(0.258824,0.258824,0.435294);
	glBegin(GL_POLYGON);
		glVertex3f(-55,100,0);
		glVertex3f(-105,130,-60);
		glVertex3f(-175,130,-60);
		glVertex3f(-235,100,0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-55,100,-120);
		glVertex3f(-105,130,-60);
		glVertex3f(-175,130,-60);
		glVertex3f(-235,100,-120);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(-175,130,-60);
		glVertex3f(-235,100,0);
		glVertex3f(-235,100,-120);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(-105,130,-60);
		glVertex3f(-55,100,0);
		glVertex3f(-55,100,-120);
	glEnd();
	glColor3f(0.36,0.25,0.20);
	glBegin(GL_QUADS);
		glVertex3f(-75,100,-20);
		glVertex3f(-75,100,-100);
		glVertex3f(-75,10,-100);
		glVertex3f(-75,10,-20);
	glEnd();
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
	//lorong
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_POLYGON);
		glVertex3f(90,10,-100);
		glVertex3f(90,10,-280);
		glVertex3f(90,0,-280);
		glVertex3f(90,0,-100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(90,10,-100);
		glVertex3f(90,10,-255);
		glVertex3f(90,-25,-255);
		glVertex3f(90,-25,-100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(90,10,-275);
		glVertex3f(90,10,-280);
		glVertex3f(90,-25,-280);
		glVertex3f(90,-25,-275);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(75,10,-100);
		glVertex3f(75,10,-280);
		glVertex3f(75,-25,-280);
		glVertex3f(75,-25,-100);
	glEnd();
	//atap lorong
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
		glVertex3f(92,10,-100);
		glVertex3f(82.5,20,-120);
		glVertex3f(82.5,20,-260);
		glVertex3f(92,10,-280);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(73,10,-100);
		glVertex3f(82.5,20,-120);
		glVertex3f(82.5,20,-260);
		glVertex3f(73,10,-280);
	glEnd();
	glColor3f(1,0,0);
	glBegin(GL_TRIANGLES);
		glVertex3f(82.5,20,-120);
		glVertex3f(73,10,-100);
		glVertex3f(92,10,-100);
	glEnd();
	glColor3f(1,0,0);
	glBegin(GL_TRIANGLES);
		glVertex3f(82.5,20,-260);
		glVertex3f(73,10,-280);
		glVertex3f(92,10,-280);
	glEnd();
	//lorong2 
	glBegin(GL_POLYGON);
		glVertex3f(75,-25,-295);
		glVertex3f(-75,-25,-295);
		glVertex3f(-75,0,-295);
		glVertex3f(75,0,-295);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-75,-25,-355);
		glVertex3f(-75,-25,-450);
		glVertex3f(-75,0,-450);
		glVertex3f(-75,0,-355);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-75,-25,-295);
		glVertex3f(-75,-25,-335);
		glVertex3f(-75,0,-335);
		glVertex3f(-75,0,-295);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-75,-25,-335);
		glVertex3f(-230,-25,-335);
		glVertex3f(-230,0,-335);
		glVertex3f(-75,0,-335);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(75,-25,-325);
		glVertex3f(-50,-25,-325);
		glVertex3f(-50,0,-325);
		glVertex3f(75,0,-325);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-50,-25,-325);
		glVertex3f(-50,-25,-450);
		glVertex3f(-50,0,-450);
		glVertex3f(-50,0,-325);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-75,-25,-355);
		glVertex3f(-230,-25,-355);
		glVertex3f(-230,0,-355);
		glVertex3f(-75,0,-355);
	glEnd();
	//atap lorong 2
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex3f(75,0,-290);
		glVertex3f(65,10,-310);
		glVertex3f(-63.5,10,-310);
		glVertex3f(-75,0,-290);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(75,0,-325);
		glVertex3f(65,10,-310);
		glVertex3f(-63.5,10,-310);
		glVertex3f(-50,0,-325);
	glEnd();
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
		glVertex3f(-50,0,-325);
		glVertex3f(-63.5,10,-310);
		glVertex3f(-63.5,10,-380);
		glVertex3f(-50,0,-400);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-75,0,-290);
		glVertex3f(-63.5,10,-310);
		glVertex3f(-63.5,10,-347.5);
		glVertex3f(-75,0,-335);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-75,0,-400);
		glVertex3f(-63.5,10,-380);
		glVertex3f(-63.5,10,-340);
		glVertex3f(-75,0,-355);
	glEnd();
	glColor3f(1,0,0);
	glBegin(GL_TRIANGLES);
		glVertex3f(-63.5,10,-380);
		glVertex3f(-50,0,-400);
		glVertex3f(-75,0,-400);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex3f(-75,0,-355);
		glVertex3f(-63.5,10,-345);
		glVertex3f(-150,10,-345);
		glVertex3f(-180,0,-355);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-75,0,-335);
		glVertex3f(-63.5,10,-345);
		glVertex3f(-150,10,-345);
		glVertex3f(-180,0,-335);
	glEnd();
	glColor3f(0.2,0.5,0.7);
	glBegin(GL_TRIANGLES);
		glVertex3f(-150,10,-345);
		glVertex3f(-180,0,-335);
		glVertex3f(-180,0,-355);
	glEnd();
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
