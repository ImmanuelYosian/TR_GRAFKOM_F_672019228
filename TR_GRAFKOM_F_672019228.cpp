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
			glVertex3f(x_awal + lebar_tangga*2 + 3,y_awal+anak_tangga*2+2,z_awal-anak_tangga*2-3);
			glVertex3f(x_awal,y_awal+anak_tangga*2+2,z_awal-anak_tangga*2-3);
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
	//Bangun Belakang
	glVertex3f(cx,cy,cz+lebar);
	glVertex3f(cx+panjang,cy,cz+lebar);
	glVertex3f(cx+panjang,cy+tinggi,cz+lebar);
	glVertex3f(cx,cy+tinggi,cz+lebar);
	
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
//	glEnd();	
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
    tangga(0,0,0,10,15,1,180,196,10,47);
    tangga(0,0,0,8,15,1,180,196,-25,44);
	
	//Tangga Gedung Kanan depan
	tangga(0,0,0,10,15,1,180,-229,10,48);
	tangga(0,0,0,8,15,1,180,-229,-25,48);
	
	//Tangga Gedung Belakang Kiri
	tangga(0,0,0,8,15,1,0,-229,-25,-426);
	
	//Tangga Gedung Belakang Kanan
	tangga(0,0,0,8,15,1,0,196,-25,-316);
	
    
	//kanan samping atas belakang
	glColor3f(0.35,0.16,0.14);
	glBegin(GL_QUADS);
		glVertex3f(180,100,-100);
		glVertex3f(180,54,-100);
		glVertex3f(230,54,-100);
		glVertex3f(230,100,-100);
	glEnd();
	//atap kanan
	
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(55,100,0);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(105,130,-60);
		glVertex3f(200,130,-60);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(250,100,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(55,100,-120);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(105,130,-60);
		glVertex3f(200,130,-60);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(250,100,-120);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(200,130,-60);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(250,100,0);
		glVertex3f(250,100,-120);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(105,130,-60);
		glColor3f(0.258824,0.258824,0.435294);
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
	//lantai 2
	glBegin(GL_QUADS);
		glVertex3f(75,54,-25);
		glVertex3f(195,54,-25);
		glVertex3f(195,54,-100);
		glVertex3f(75,54,-100);
		
		glVertex3f(230,54,-48);
		glVertex3f(195,54,-48);
		glVertex3f(195,54,-100);
		glVertex3f(230,54,-100);
		
		glVertex3f(-75,54,-25);
		glVertex3f(-195,54,-25);
		glVertex3f(-195,54,-100);
		glVertex3f(-75,54,-100);
		
		glVertex3f(-230,54,-48);
		glVertex3f(-195,54,-48);
		glVertex3f(-195,54,-100);
		glVertex3f(-230,54,-100);
	glEnd();
	
	//lantai 2
	glBegin(GL_QUADS);
		glVertex3f(75,10,-20);
		glVertex3f(195,10,-20);
		glVertex3f(195,10,-100);
		glVertex3f(75,10,-100);
		
		glVertex3f(230,10,-48);
		glVertex3f(195,10,-48);
		glVertex3f(195,10,-100);
		glVertex3f(230,10,-100);
		
		glVertex3f(180,10,-315);
		glVertex3f(230,10,-315);
		glVertex3f(230,10,-100);
		glVertex3f(180,10,-100);
		
		glVertex3f(195,10,-315);
		glVertex3f(180,10,-315);
		glVertex3f(180,10,-340);
		glVertex3f(195,10,-340);
		
		glVertex3f(75,10,-280);
		glVertex3f(180,10,-280);
		glVertex3f(180,10,-340);
		glVertex3f(75,10,-340);
		
		glVertex3f(-75,10,-20);
		glVertex3f(-195,10,-20);
		glVertex3f(-195,10,-100);
		glVertex3f(-75,10,-100);
		
		glVertex3f(-230,10,-48);
		glVertex3f(-195,10,-48);
		glVertex3f(-195,10,-100);
		glVertex3f(-230,10,-100);
		
		glVertex3f(-180,10,-424);
		glVertex3f(-230,10,-424);
		glVertex3f(-230,10,-100);
		glVertex3f(-180,10,-100);
		
		glVertex3f(-195,10,-424);
		glVertex3f(-180,10,-424);
		glVertex3f(-180,10,-450);
		glVertex3f(-195,10,-450);
		
		glVertex3f(-195,10,-400);
		glVertex3f(10,10,-400);
		glVertex3f(10,10,-450);
		glVertex3f(-195,10,-450);
		
	glEnd();
	//bagian atas
	glColor3f(0.35, 0.16, 0.14);
	//gedung kanan depan
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(10,10,-70);
		glVertex3f(75,10,-70);
		glVertex3f(75,-25,-70);
		glVertex3f(10,-25,-70);
		
		glVertex3f(75,10,-70);
		glVertex3f(75,10,-100);
		glVertex3f(75,-25,-100);
		glVertex3f(75,-25,-70);
		
		glVertex3f(-75,10,-70);
		glVertex3f(-75,10,-100);
		glVertex3f(-75,-25,-100);
		glVertex3f(-75,-25,-70);
		
		glVertex3f(75,10,-100);
		glVertex3f(180,10,-100);
		glVertex3f(180,-25,-100);
		glVertex3f(75,-25,-100);
		
		glVertex3f(-75,10,-20);
		glVertex3f(-75,10,-70);
		glVertex3f(75,10,-70);
		glVertex3f(75,10,-20);
	glEnd();
	//bagian atas
	glColor3f(0.35, 0.16, 0.14);
	glBegin(GL_QUADS);
		glVertex3f(75,100,-100);
		glVertex3f(180,100,-100);
		glVertex3f(180,10,-100);
		glVertex3f(75,10,-100);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.16, 0.14);
		glVertex3f(75,100,-20);
		glVertex3f(75,100,-100);
		glVertex3f(75,10,-100);
		glVertex3f(75,10,-20);
	glEnd();
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
		glVertex3f(230,98,-20);
		glVertex3f(230,98,-100);
		glVertex3f(230,10,-100);
		glVertex3f(230,10,-20);
	glEnd();
	
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
		glVertex3f(230,98,-20);
		glVertex3f(230,98,-100);
		glVertex3f(230,100,-100);
		glVertex3f(230,100,-20);
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
	
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(240,70,-100);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(200,90,-130);
		glVertex3f(200,90,-310);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(240,70,-350);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(160,70,-100);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(200,90,-130);
		glVertex3f(200,90,-310);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(160,70,-270);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(200,90,-130);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(160,70,-100);
		glVertex3f(240,70,-100);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(240,70,-350);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(200,90,-310);
		glVertex3f(90,90,-310);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(75,70,-350);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(160,70,-270);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(200,90,-310);
		glVertex3f(90,90,-310);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(75,70,-270);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(90,90,-310);
		glColor3f(0.258824,0.258824,0.435294);
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
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(20,50,-390);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(0,65,-425);
		glVertex3f(-160,65,-425);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-180,50,-390);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(20,50,-465);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(0,65,-425);
		glVertex3f(-160,65,-425);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-180,50,-465);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(0,65,-425);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(20,50,-390);
		glVertex3f(20,50,-465);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-160,65,-425);
		glColor3f(0.258824,0.258824,0.435294);
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
	glBegin(GL_QUADS);
		glVertex3f(-180,70,-450);
		glVertex3f(-230,70,-450);
		glVertex3f(-230,10,-450);
		glVertex3f(-180,10,-450);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-180,70,-450);
		glVertex3f(-230,70,-300);
		glVertex3f(-230,50,-300);
		glVertex3f(-180,50,-450);
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
	//kiri samping atas belakang
	glBegin(GL_QUADS);
		glVertex3f(-180,100,-100);
		glVertex3f(-180,54,-100);
		glVertex3f(-230,54,-100);
		glVertex3f(-230,100,-100);
	glEnd();
	//atap
	glColor3f(0.258824,0.258824,0.435294);
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-170,70,-100);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-120);
		glVertex3f(-205,90,-430);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-170,70,-460);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-240,70,-100);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-120);
		glVertex3f(-205,90,-430);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-240,70,-460);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-120);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-240,70,-100);
		glVertex3f(-170,70,-100);
	glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-430);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-240,70,-460);
		glVertex3f(-170,70,-460);
	glEnd();
	//gedung depan kiri
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-10,10,-70);
		glVertex3f(-75,10,-70);
		glVertex3f(-75,-25,-70);
		glVertex3f(-10,-25,-70);
	
		glVertex3f(-230,10,-20);
		glVertex3f(-10,10,-20);
		glVertex3f(-10,-25,-20);
		glVertex3f(-230,-25,-20);
	glEnd();
	//gedung depan kiri
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-180,10,-100);
		glVertex3f(-75,10,-100);
		glVertex3f(-75,-25,-100);
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
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-55,100,0);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-105,130,-60);
		glVertex3f(-175,130,-60);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-235,100,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-55,100,-120);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-105,130,-60);
		glVertex3f(-175,130,-60);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-235,100,-120);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-175,130,-60);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-235,100,0);
		glVertex3f(-235,100,-120);
	
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-105,130,-60);
		glColor3f(0.258824,0.258824,0.435294);
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
	//tiang depan
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	//tiang 1
	glVertex3f(15, -25.0, 45);
	glVertex3f(25, -25.0, 45);
	glVertex3f(25, 10.0, 45);
	glVertex3f(15, 10.0, 45);
	
	glVertex3f(15, -25.0, 35);
	glVertex3f(25, -25.0, 35);
	glVertex3f(25, 10.0, 35);
	glVertex3f(15, 10.0, 35);
	
	glVertex3f(15, -25.0, 35);
	glVertex3f(15, -25.0, 45);
	glVertex3f(15, 10.0, 45);
	glVertex3f(15, 10.0, 35);
	
	glVertex3f(25, -25.0, 35);
	glVertex3f(25, -25.0, 45);
	glVertex3f(25, 10.0, 45);
	glVertex3f(25, 10.0, 35);
	
	//tiang 2
	glVertex3f(-15, -25.0, 45);
	glVertex3f(-25, -25.0, 45);
	glVertex3f(-25, 10.0, 45);
	glVertex3f(-15, 10.0, 45);
	
	glVertex3f(-15, -25.0, 35);
	glVertex3f(-25, -25.0, 35);
	glVertex3f(-25, 10.0, 35);
	glVertex3f(-15, 10.0, 35);
	
	glVertex3f(-15, -25.0, 35);
	glVertex3f(-15, -25.0, 45);
	glVertex3f(-15, 10.0, 45);
	glVertex3f(-15, 10.0, 35);
	
	glVertex3f(-25, -25.0, 35);
	glVertex3f(-25, -25.0, 45);
	glVertex3f(-25, 10.0, 45);
	glVertex3f(-25, 10.0, 35);
	
	//tiang 3
	glVertex3f(15, -25.0, 10);
	glVertex3f(25, -25.0, 10);
	glVertex3f(25, 10.0, 10);
	glVertex3f(15, 10.0, 10);
	
	glVertex3f(15, -25.0, 0);
	glVertex3f(25, -25.0, 0);
	glVertex3f(25, 10.0, 0);
	glVertex3f(15, 10.0, 0);
	
	glVertex3f(15, -25.0, 0);
	glVertex3f(15, -25.0, 10);
	glVertex3f(15, 10.0, 10);
	glVertex3f(15, 10.0, 0);
	
	glVertex3f(25, -25.0, 0);
	glVertex3f(25, -25.0, 10);
	glVertex3f(25, 10.0, 10);
	glVertex3f(25, 10.0, 0);
	
	//tiang 4
	glVertex3f(-15, -25.0, 10);
	glVertex3f(-25, -25.0, 10);
	glVertex3f(-25, 10.0, 10);
	glVertex3f(-15, 10.0, 10);
	
	glVertex3f(-15, -25.0, 0);
	glVertex3f(-25, -25.0, 0);
	glVertex3f(-25, 10.0, 0);
	glVertex3f(-15, 10.0, 0);
	
	glVertex3f(-15, -25.0, 0);
	glVertex3f(-15, -25.0, 10);
	glVertex3f(-15, 10.0, 10);
	glVertex3f(-15, 10.0, 0);
	
	glVertex3f(-25, -25.0, 0);
	glVertex3f(-25, -25.0, 10);
	glVertex3f(-25, 10.0, 10);
	glVertex3f(-25, 10.0, 0);
	
	//tiang belakang
	//tiang 1
	glVertex3f(-25, -25.0, -85);
	glVertex3f(-25, -25.0, -95);
	glVertex3f(-25, 10.0, -95);
	glVertex3f(-25, 10.0,-85);
	
	glVertex3f(-35, -25.0, -85);
	glVertex3f(-35, -25.0, -95);
	glVertex3f(-35, 10.0, -95);
	glVertex3f(-35, 10.0,-85);
	
	glVertex3f(-35, -25.0, -85);
	glVertex3f(-25, -25.0, -85);
	glVertex3f(-25, 10.0, -85);
	glVertex3f(-35, 10.0,-85);
	
	glVertex3f(-35, -25.0, -95);
	glVertex3f(-25, -25.0, -95);
	glVertex3f(-25, 10.0, -95);
	glVertex3f(-35, 10.0,-95);
	
	//tiang 2
	glVertex3f(25, -25.0, -85);
	glVertex3f(25, -25.0, -95);
	glVertex3f(25, 10.0, -95);
	glVertex3f(25, 10.0,-85);
	
	glVertex3f(35, -25.0, -85);
	glVertex3f(35, -25.0, -95);
	glVertex3f(35, 10.0, -95);
	glVertex3f(35, 10.0,-85);
	
	glVertex3f(35, -25.0, -85);
	glVertex3f(25, -25.0, -85);
	glVertex3f(25, 10.0, -85);
	glVertex3f(35, 10.0,-85);
	
	glVertex3f(35, -25.0, -95);
	glVertex3f(25, -25.0, -95);
	glVertex3f(25, 10.0, -95);
	glVertex3f(35, 10.0,-95);
	
	//tiang 3
	glVertex3f(-25, -25.0, -155);
	glVertex3f(-25, -25.0, -145);
	glVertex3f(-25, 10.0, -145);
	glVertex3f(-25, 10.0,-155);
	
	glVertex3f(-35, -25.0, -155);
	glVertex3f(-35, -25.0, -145);
	glVertex3f(-35, 10.0, -145);
	glVertex3f(-35, 10.0,-155);
	
	glVertex3f(-35, -25.0, -155);
	glVertex3f(-25, -25.0, -155);
	glVertex3f(-25, 10.0, -155);
	glVertex3f(-35, 10.0,-155);
	
	glVertex3f(-35, -25.0, -145);
	glVertex3f(-25, -25.0, -145);
	glVertex3f(-25, 10.0, -145);
	glVertex3f(-35, 10.0,-145);
	
	//tiang 4
	glVertex3f(25, -25.0, -155);
	glVertex3f(25, -25.0, -145);
	glVertex3f(25, 10.0, -145);
	glVertex3f(25, 10.0,-155);
	
	glVertex3f(35, -25.0, -155);
	glVertex3f(35, -25.0, -145);
	glVertex3f(35, 10.0, -145);
	glVertex3f(35, 10.0,-155);
	
	glVertex3f(35, -25.0, -155);
	glVertex3f(25, -25.0, -155);
	glVertex3f(25, 10.0, -155);
	glVertex3f(35, 10.0,-155);
	
	glVertex3f(35, -25.0, -145);
	glVertex3f(25, -25.0, -145);
	glVertex3f(25, 10.0, -145);
	glVertex3f(35, 10.0,-145);
	
	glEnd();
    //atap depan
    glBegin(GL_TRIANGLES);
    	glColor3f(0.158824,0.158824,0.335294);
    	glVertex3f(0,30,20);
		glColor3f(0.258824,0.258824,0.435294);
    	glVertex3f(-30,10,50);
    	glVertex3f(30,10,50);
		
		glColor3f(0.158824,0.158824,0.335294);
    	glVertex3f(0,30,20);
    	glColor3f(0.258824,0.258824,0.435294);
    	glVertex3f(30,10,50);
    	glVertex3f(30,10,-10);
  		
  		glColor3f(0.158824,0.158824,0.335294);
    	glVertex3f(0,30,20);
    	glColor3f(0.258824,0.258824,0.435294);
    	glVertex3f(30,10,-10);
    	glVertex3f(-30,10,-10);
    
    	glColor3f(0.158824,0.158824,0.335294);
    	glVertex3f(0,30,20);
    	glColor3f(0.258824,0.258824,0.435294);
    	glVertex3f(-30,10,50);
    	glVertex3f(-30,10,-10);
    glEnd();
    
    //atap tengah
    glBegin(GL_QUADS);
    	glColor3f(0.158824,0.158824,0.335294);
	    glVertex3f(0,25,13);
	    glColor3f(0.258824,0.258824,0.435294);
	    glVertex3f(25,10,-10);
	    glVertex3f(25,10,-25);
	    glColor3f(0.158824,0.158824,0.335294);
	    glVertex3f(0,25,-50);
	    
	    glColor3f(0.158824,0.158824,0.335294);
	    glVertex3f(0,25,13);
	    glColor3f(0.258824,0.258824,0.435294);
	    glVertex3f(-25,10,-10);
	    glVertex3f(-25,10,-25);
	    glColor3f(0.158824,0.158824,0.335294);
	    glVertex3f(0,25,-50);
	    
	    glColor3f(0.158824,0.158824,0.335294);
	    glVertex3f(0,25,-35);
	    glColor3f(0.258824,0.258824,0.435294);
	    glVertex3f(25,10,-65);
	    glVertex3f(25,10,-80);
	    glColor3f(0.158824,0.158824,0.335294);
	    glVertex3f(0,25,-100);
	    
	    glColor3f(0.158824,0.158824,0.335294);
	    glVertex3f(0,25,-35);
	    glColor3f(0.258824,0.258824,0.435294);
	    glVertex3f(-25,10,-65);
	    glVertex3f(-25,10,-80);
	    glColor3f(0.158824,0.158824,0.335294);
	    glVertex3f(0,25,-100);
	glEnd();
	
	//atap tengah samping
	glBegin(GL_QUADS);
	glColor3f(0.158824,0.158824,0.335294);
    glVertex3f(-6,21,-43);
    glColor3f(0.258824,0.258824,0.435294);
    glVertex3f(-25,10,-25);
    glVertex3f(-75,10,-25);
    glColor3f(0.158824,0.158824,0.335294);
    glVertex3f(-75,21,-43);
    
    glColor3f(0.158824,0.158824,0.335294);
    glVertex3f(-6,21,-43);
    glColor3f(0.258824,0.258824,0.435294);
    glVertex3f(-25,10,-65);
    glVertex3f(-75,10,-65);
    glColor3f(0.158824,0.158824,0.335294);
    glVertex3f(-75,21,-43);
    
    glColor3f(0.158824,0.158824,0.335294);
    glVertex3f(6,21,-43);
    glColor3f(0.258824,0.258824,0.435294);
    glVertex3f(25,10,-25);
    glVertex3f(75,10,-25);
    glColor3f(0.158824,0.158824,0.335294);
    glVertex3f(75,21,-43);
    
    glColor3f(0.158824,0.158824,0.335294);
    glVertex3f(6,21,-43);
    glColor3f(0.258824,0.258824,0.435294);
    glVertex3f(25,10,-65);
    glVertex3f(75,10,-65);
    glColor3f(0.158824,0.158824,0.335294);
    glVertex3f(75,21,-43);
	glEnd();

    //Atap belakang
    glBegin(GL_TRIANGLES);
    	glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(0,40,-120);
    	glColor3f(0.258824,0.258824,0.435294);
    	glVertex3f(-40,10,-80);
    	glVertex3f(40,10,-80);

    	glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(0,40,-120);
    	glColor3f(0.258824,0.258824,0.435294);
    	glVertex3f(40,10,-80);
    	glVertex3f(40,10,-160);
  
    	glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(0,40,-120);
    	glColor3f(0.258824,0.258824,0.435294);
    	glVertex3f(40,10,-160);
    	glVertex3f(-40,10,-160);
    	
    	glColor3f(0.158824,0.158824,0.335294);
    	glVertex3f(0,40,-120);
    	glColor3f(0.258824,0.258824,0.435294);
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
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(92,10,-100);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(82.5,20,-120);
		glVertex3f(82.5,20,-260);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(92,10,-280);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(73,10,-100);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(82.5,20,-120);
		glVertex3f(82.5,20,-260);
		glVertex3f(73,10,-280);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(82.5,20,-120);
		glVertex3f(73,10,-100);
		glVertex3f(92,10,-100);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(82.5,20,-260);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(73,10,-280);
		glVertex3f(92,10,-280);
	glEnd();
	//lorong2 
		glColor3f(0.90,0.91,0.98);
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
	glBegin(GL_POLYGON);
	glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(75,0,-290);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(65,10,-310);
		glVertex3f(-63.5,10,-310);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-75,0,-290);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(75,0,-325);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(65,10,-310);
		glVertex3f(-63.5,10,-310);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-50,0,-325);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-50,0,-325);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-63.5,10,-310);
		glVertex3f(-63.5,10,-380);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-50,0,-400);
	glEnd();	
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-75,0,-290);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-63.5,10,-310);
		glVertex3f(-63.5,10,-347.5);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-75,0,-335);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-75,0,-400);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-63.5,10,-380);
		glVertex3f(-63.5,10,-340);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-75,0,-355);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-63.5,10,-380);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-50,0,-400);
		glVertex3f(-75,0,-400);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-75,0,-355);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-63.5,10,-345);
		glVertex3f(-150,10,-345);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-180,0,-355);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-75,0,-335);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-63.5,10,-345);
		glVertex3f(-150,10,-345);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-180,0,-335);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-150,10,-345);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-180,0,-335);
		glVertex3f(-180,0,-355);
	glEnd();
		//gedungputih
	//gedungputihbelakang
		glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-180,10,-270);
		glVertex3f(-85,10,-270);
		glVertex3f(-85,-25,-270);
		glVertex3f(-180,-25,-270);
	glEnd();
	//gedungputihsampingatas
		glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-85,10,-270);
		glVertex3f(-85,10,-100);
		glVertex3f(-85,0,-100);
		glVertex3f(-85,0,-270);
	glEnd();
	//tiangsampinggedungputih
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-270);
		glVertex3f(-85,0,-240);
		glVertex3f(-85,-25,-240);
		glVertex3f(-85,-25,-270);
	glEnd();
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-155);
		glVertex3f(-85,0,-158);
		glVertex3f(-85,-25,-158);
		glVertex3f(-85,-25,-155);
	glEnd();
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-162);
		glVertex3f(-85,0,-165);
		glVertex3f(-85,-25,-165);
		glVertex3f(-85,-25,-162);
	glEnd();
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-198);
		glVertex3f(-85,0,-195);
		glVertex3f(-85,-25,-195);
		glVertex3f(-85,-25,-198);
	glEnd();
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-202);
		glVertex3f(-85,0,-205);
		glVertex3f(-85,-25,-205);
		glVertex3f(-85,-25,-202);
	glEnd();
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-120);
		glVertex3f(-85,0,-100);
		glVertex3f(-85,-25,-100);
		glVertex3f(-85,-25,-120);
	glEnd();
	//atasgedungputih
		glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);
		glVertex3f(-180,10,-230);
		glVertex3f(-180,10,-100);
		glVertex3f(-125,10,-100);
		glVertex3f(-125,10,-230);
	glEnd();
		glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);
		glVertex3f(-85,10,-200);
		glVertex3f(-85,10,-100);
		glVertex3f(-125,10,-100);
		glVertex3f(-125,10,-200);
	glEnd();
		glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);
		glVertex3f(-150,10,-270);
		glVertex3f(-150,10,-230);
		glVertex3f(-180,10,-230);
		glVertex3f(-180,10,-270);
	glEnd();
		glColor3f(0.5,0.0,0.0);
	glBegin(GL_QUADS);
		glVertex3f(-150,10,-270);
		glVertex3f(-150,10,-230);
		glVertex3f(-85,10,-230);
		glVertex3f(-85,10,-270);
	glEnd();
		glColor3f(0.5,0.0,0.0);
	glBegin(GL_QUADS);
		glVertex3f(-130,10,-230);
		glVertex3f(-130,10,-200);
		glVertex3f(-85,10,-200);
		glVertex3f(-85,10,-230);
	glEnd();
	//kotak L1 atas gedungputih
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-125,15,-230);
		glVertex3f(-125,15,-200);
		glVertex3f(-125,10,-200);
		glVertex3f(-125,10,-230);
	glEnd();
		glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-135,15,-220);
		glVertex3f(-135,15,-200);
		glVertex3f(-135,10,-200);
		glVertex3f(-135,10,-220);
	glEnd();
		glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-135,15,-220);
		glVertex3f(-165,15,-220);
		glVertex3f(-165,10,-220);
		glVertex3f(-135,10,-220);
	glEnd();
			glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-125,15,-230);
		glVertex3f(-165,15,-230);
		glVertex3f(-165,10,-230);
		glVertex3f(-125,10,-230);
	glEnd();
		glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-165,15,-230);
		glVertex3f(-165,15,-220);
		glVertex3f(-165,10,-220);
		glVertex3f(-165,10,-230);
	glEnd();
			glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-125,15,-200);
		glVertex3f(-135,15,-200);
		glVertex3f(-135,10,-200);
		glVertex3f(-125,10,-200);
	glEnd();
		//kotak L2 atas gedungputih
			glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-120,15,-200);
		glVertex3f(-125,15,-200);
		glVertex3f(-125,10,-200);
		glVertex3f(-120,10,-200);
	glEnd();
			glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-120,15,-150);
		glVertex3f(-170,15,-150);
		glVertex3f(-170,10,-150);
		glVertex3f(-120,10,-150);
	glEnd();
			glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-120,15,-150);
		glVertex3f(-120,15,-200);
		glVertex3f(-120,10,-200);
		glVertex3f(-120,10,-150);
	glEnd();
			glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-130,15,-160);
		glVertex3f(-130,15,-200);
		glVertex3f(-130,10,-200);
		glVertex3f(-130,10,-160);
	glEnd();
			glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-130,15,-160);
		glVertex3f(-170,15,-160);
		glVertex3f(-170,10,-160);
		glVertex3f(-130,10,-160);
	glEnd();
			glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-170,15,-160);
		glVertex3f(-170,15,-150);
		glVertex3f(-170,10,-150);
		glVertex3f(-170,10,-160);
	glEnd();
	//ALAS 
//	glColor3f(0.0,0.180,0.0);
//	glBegin(GL_QUADS);
//	glVertex3f(-230,-25,-450);
//	glVertex3f(-230,-25,100);
//	glVertex3f(230,-25,100);
//	glVertex3f(230,-25,-450);
//	glEnd();


	
	glBegin(GL_QUADS); // jendela kanan atas		
		// kanan bawah
		glColor3f(0,0.5,0.5);
		int i;
		for(i = 0;i<7;i++){
			glVertex3f(77+i*18,-15,-19.9);
			glVertex3f(77+i*18,5,-19.9);
			glVertex3f(83+i*18,5,-19.9);
			glVertex3f(83+i*18,-15,-19.9);
			
			glVertex3f(85+i*18,-15,-19.9);
			glVertex3f(85+i*18,5,-19.9);
			glVertex3f(91+i*18,5,-19.9);
			glVertex3f(91+i*18,-15,-19.9);
			
		}
		glColor3f(0.35,0.16,0.14);
		balok(75,10,-24.9,18,5,90);
		glColor4f(0,0,0,0.8);
		glVertex3f(93,10,-24.9);
		glVertex3f(93,100,-24.9);
		glVertex3f(110,100,-24.9);
		glVertex3f(110,10,-24.9);
		for(i = 0;i<11;i++){
			glColor3f(0.35,0.16,0.14);
			balok(110+i*9,10,-24.9,3,5,65);
				//Bangun Belakang
				glColor4f(0,0,0,0.8);
				glVertex3f(110+i*9+3,10,-24.9);
				glVertex3f(110+i*9+3,75,-24.9);
				glVertex3f(110+i*9+9,75,-24.9);
				glVertex3f(110+i*9+9,10,-24.9); 
		}
		glColor3f(0.35,0.16,0.14);
		balok(199,10,-24.9,31,5,65);
		glColor3f(0.35,0.16,0.14);
		balok(110,75,-24.9,120,5,23);
		glColor3f(1,1,1);
		balok(110,98,-24.9,120,5,2);
		
		//jendela samping kanan
		for(i = 0;i<15;i++){
			glColor3f(0.8784,1,1);
			glVertex3f(230.1,10,-23-i*21);
			glVertex3f(230.1,30,-23-i*21);
			glVertex3f(230.1,30,-32-i*21);
			glVertex3f(230.1,10,-32-i*21);
			
			glVertex3f(230.1,10,-33-i*21);
			glVertex3f(230.1,30,-33-i*21);
			glVertex3f(230.1,30,-42-i*21);
			glVertex3f(230.1,10,-42-i*21);
			
			glVertex3f(230.1,45,-23-i*21);
			glVertex3f(230.1,65,-23-i*21);
			glVertex3f(230.1,65,-32-i*21);
			glVertex3f(230.1,45,-32-i*21);
			
			glVertex3f(230.1,45,-33-i*21);
			glVertex3f(230.1,65,-33-i*21);
			glVertex3f(230.1,65,-42-i*21);
			glVertex3f(230.1,45,-42-i*21);
			
			glColor3f(1,1,0);
			glVertex3f(230.1,45,-23-i*21);
			glVertex3f(230.1,30,-23-i*21);
			glVertex3f(230.1,30,-32-i*21);
			glVertex3f(230.1,45,-32-i*21);
			
			glVertex3f(230.1,45,-33-i*21);
			glVertex3f(230.1,30,-33-i*21);
			glVertex3f(230.1,30,-42-i*21);
			glVertex3f(230.1,45,-42-i*21);
			
			glColor3f(0.5,1,0.5);
			glVertex3f(230.1,-15,-23-i*21);
			glVertex3f(230.1,5,-23-i*21);
			glVertex3f(230.1,5,-32-i*21);
			glVertex3f(230.1,-15,-32-i*21);
			
			glVertex3f(230.1,-15,-33-i*21);
			glVertex3f(230.1,5,-33-i*21);
			glVertex3f(230.1,5,-42-i*21);
			glVertex3f(230.1,-15,-42-i*21);
		}
	glEnd();
	
	glBegin(GL_QUADS); // jendela kanan atas		
	// kanan bawah
	glColor3f(0,0.5,0.5);
	
	for(i = 0;i<7;i++){
		glVertex3f(-77-i*18,-15,-19.9);
		glVertex3f(-77-i*18,5,-19.9);
		glVertex3f(-83-i*18,5,-19.9);
		glVertex3f(-83-i*18,-15,-19.9);
		
		glVertex3f(-85-i*18,-15,-19.9);
		glVertex3f(-85-i*18,5,-19.9);
		glVertex3f(-91-i*18,5,-19.9);
		glVertex3f(-91-i*18,-15,-19.9);
		
	}
	glColor3f(0.35,0.16,0.14);
	balok(-75,10,-24.9,-18,5,90);
	glColor4f(0,0,0,0.8);
	glVertex3f(-93,10,-24.9);
	glVertex3f(-93,100,-24.9);
	glVertex3f(-110,100,-24.9);
	glVertex3f(-110,10,-24.9);
	for(i = 0;i<11;i++){
		glColor3f(0.35,0.16,0.14);
		balok(-110-i*9,10,-24.9,-3,5,65);
			//Bangun Belakang
			glColor4f(0,0,0,0.8);
			glVertex3f(-110-i*9-3,10,-24.9);
			glVertex3f(-110-i*9-3,75,-24.9);
			glVertex3f(-110-i*9-9,75,-24.9);
			glVertex3f(-110-i*9-9,10,-24.9); 
	}
	glColor3f(0.35,0.16,0.14);
	balok(-199,10,-24.9,-31,5,65);
	glColor3f(0.35,0.16,0.14);
	balok(-110,75,-24.9,-120,5,23);
	glColor3f(1,1,1);
	balok(-110,98,-24.9,-120,5,2);
		
		//jendela samping kiri
		for(i = 0;i<20;i++){
			glColor3f(0.8784,1,1);
			glVertex3f(-230.1,10,-23-i*21);
			glVertex3f(-230.1,30,-23-i*21);
			glVertex3f(-230.1,30,-32-i*21);
			glVertex3f(-230.1,10,-32-i*21);
			
			glVertex3f(-230.1,10,-33-i*21);
			glVertex3f(-230.1,30,-33-i*21);
			glVertex3f(-230.1,30,-42-i*21);
			glVertex3f(-230.1,10,-42-i*21);
			
			glVertex3f(-230.1,45,-23-i*21);
			glVertex3f(-230.1,65,-23-i*21);
			glVertex3f(-230.1,65,-32-i*21);
			glVertex3f(-230.1,45,-32-i*21);
			
			glVertex3f(-230.1,45,-33-i*21);
			glVertex3f(-230.1,65,-33-i*21);
			glVertex3f(-230.1,65,-42-i*21);
			glVertex3f(-230.1,45,-42-i*21);
			
			glColor3f(1,1,0);
			glVertex3f(-230.1,45,-23-i*21);
			glVertex3f(-230.1,30,-23-i*21);
			glVertex3f(-230.1,30,-32-i*21);
			glVertex3f(-230.1,45,-32-i*21);
			
			glVertex3f(-230.1,45,-33-i*21);
			glVertex3f(-230.1,30,-33-i*21);
			glVertex3f(-230.1,30,-42-i*21);
			glVertex3f(-230.1,45,-42-i*21);
			
			glColor3f(0.5,1,0.5);
			glVertex3f(-230.1,-15,-23-i*21);
			glVertex3f(-230.1,5,-23-i*21);
			glVertex3f(-230.1,5,-32-i*21);
			glVertex3f(-230.1,-15,-32-i*21);
			
			glVertex3f(-230.1,-15,-33-i*21);
			glVertex3f(-230.1,5,-33-i*21);
			glVertex3f(-230.1,5,-42-i*21);
			glVertex3f(-230.1,-15,-42-i*21);
		}
		
		for(i = 0;i<14;i++){ //perulangan belakang kanan
			glColor3f(0.8784,1,1); //jendela putih belakang kanan
			glVertex3f(115-30+i*11,10,-340.1);
			glVertex3f(115-30+i*11,30,-340.1);
			glVertex3f(115-40+i*11,30,-340.1);
			glVertex3f(115-40+i*11,10,-340.1);

			glVertex3f(115-30+i*11,45,-340.1);
			glVertex3f(115-30+i*11,65,-340.1);
			glVertex3f(115-40+i*11,65,-340.1);
			glVertex3f(115-40+i*11,45,-340.1);

			glColor3f(1,1,0); // garis tengah kuning
			glVertex3f(115-30+i*11,45,-340.1);
			glVertex3f(115-30+i*11,30,-340.1);
			glVertex3f(115-40+i*11,30,-340.1);
			glVertex3f(115-40+i*11,45,-340.1);

			glColor3f(0.5,1,0.5); // jendela bawah belakang kanan
			glVertex3f(115-30+i*11,-15,-340.1);
			glVertex3f(115-30+i*11,5,-340.1);
			glVertex3f(115-40+i*11,5,-340.1);
			glVertex3f(115-40+i*11,-15,-340.1);
		}	
		
		
	glEnd();
		
	glBegin(GL_QUADS);
//jendela kiri (kanan)
	for(i = 0;i<14;i++){ //perulangan kiri (kanan)
			glColor3f(0.8784,1,1); //jendela putih
			glVertex3f(-179.9,10,-103-i*21);
			glVertex3f(-179.9,30,-103-i*21);
			glVertex3f(-179.9,30,-112-i*21);
			glVertex3f(-179.9,10,-112-i*21);
			
			glVertex3f(-179.9,10,-113-i*21);
			glVertex3f(-179.9,30,-113-i*21);
			glVertex3f(-179.9,30,-122-i*21);
			glVertex3f(-179.9,10,-122-i*21);
			
			glVertex3f(-179.9,45,-103-i*21);
			glVertex3f(-179.9,65,-103-i*21);
			glVertex3f(-179.9,65,-112-i*21);
			glVertex3f(-179.9,45,-112-i*21);
			
			glVertex3f(-179.9,45,-113-i*21);
			glVertex3f(-179.9,65,-113-i*21);
			glVertex3f(-179.9,65,-122-i*21);
			glVertex3f(-179.9,45,-122-i*21);
			
			glColor3f(1,1,0); // garis tengah kuning
			glVertex3f(-179.9,45,-103-i*21);
			glVertex3f(-179.9,30,-103-i*21);
			glVertex3f(-179.9,30,-112-i*21);
			glVertex3f(-179.9,45,-112-i*21);
			
			glVertex3f(-179.9,45,-113-i*21);
			glVertex3f(-179.9,30,-113-i*21);
			glVertex3f(-179.9,30,-122-i*21);
			glVertex3f(-179.9,45,-122-i*21);
}

//jendela belakang
	for(i = 0;i<13;i++){ //perulangan 
			glColor3f(0.8784,1,1); //jendela putih
			glVertex3f(-170+i*12,10,-399.9);
			glVertex3f(-170+i*12,22.5,-399.9);
			glVertex3f(-180+i*12,22.5,-399.9);
			glVertex3f(-180+i*12,10,-399.9);
			
			glVertex3f(-170+i*12,37.5,-399.9);
			glVertex3f(-170+i*12,50,-399.9);
			glVertex3f(-180+i*12,50,-399.9);
			glVertex3f(-180+i*12,37.5,-399.9);
			
			glColor3f(1,1,0); // garis tengah kuning
			glVertex3f(-170+i*12,22.5,-399.9);
			glVertex3f(-170+i*12,37.5,-399.9);
			glVertex3f(-180+i*12,37.5,-399.9);
			glVertex3f(-180+i*12,22.5,-399.9);
						
		}

		//belakang bawah
		glColor3f(0.5,1,0.5); // jendela bawah
		glVertex3f(-87.5,-15,-399.9);
		glVertex3f(-87.5,5,-399.9);
		glVertex3f(-97.5,5,-399.9);
		glVertex3f(-97.5,-15,-399.9);
		
		glVertex3f(-100.5,-15,-399.9);
		glVertex3f(-100.6,5,-399.9);
		glVertex3f(-110.5,5,-399.9);
		glVertex3f(-110.5,-15,-399.9);
		
		glVertex3f(-122.5,-15,-399.9);
		glVertex3f(-122.5,5,-399.9);
		glVertex3f(-132.5,5,-399.9);
		glVertex3f(-132.5,-15,-399.9);
		
		glVertex3f(-135.5,-15,-399.9);
		glVertex3f(-135.5,5,-399.9);
		glVertex3f(-145.5,5,-399.9);
		glVertex3f(-145.5,-15,-399.9);
		
		glVertex3f(-157.5,-15,-399.9);
		glVertex3f(-157.5,5,-399.9);
		glVertex3f(-167.5,5,-399.9);
		glVertex3f(-167.5,-15,-399.9);
		
		glVertex3f(-170,-15,-399.9);
		glVertex3f(-170,5,-399.9);
		glVertex3f(-180,5,-399.9);
		glVertex3f(-180,-15,-399.9);
	
	//corong
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
		glVertex3f(80,125,-65);
		glVertex3f(90,125,-65);
		glVertex3f(90,110,-65);
		glVertex3f(80,110,-65);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(80,125,-55);
		glVertex3f(90,125,-55);
		glVertex3f(90,110,-55);
		glVertex3f(80,110,-55);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(90,125,-55);
		glVertex3f(90,125,-65);
		glVertex3f(90,110,-65);
		glVertex3f(90,110,-55);
	glEnd();	
	glBegin(GL_QUADS);
		glVertex3f(80,125,-55);
		glVertex3f(80,125,-65);
		glVertex3f(80,110,-65);
		glVertex3f(80,110,-55);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(80,125,-55);
		glVertex3f(90,125,-55);
		glVertex3f(90,125,-65);
		glVertex3f(80,125,-65);
	glEnd();
	//-------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-80,125,-65);
		glVertex3f(-90,125,-65);
		glVertex3f(-90,110,-65);
		glVertex3f(-80,110,-65);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-80,125,-55);
		glVertex3f(-90,125,-55);
		glVertex3f(-90,110,-55);
		glVertex3f(-80,110,-55);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-90,125,-55);
		glVertex3f(-90,125,-65);
		glVertex3f(-90,110,-65);
		glVertex3f(-90,110,-55);
	glEnd();	
	glBegin(GL_QUADS);
		glVertex3f(-80,125,-55);
		glVertex3f(-80,125,-65);
		glVertex3f(-80,110,-65);
		glVertex3f(-80,110,-55);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-80,125,-55);
		glVertex3f(-90,125,-55);
		glVertex3f(-90,125,-65);
		glVertex3f(-80,125,-65);
	glEnd();
	//------------------------//
	glBegin(GL_QUADS);
		glVertex3f(200,130,-45);
		glVertex3f(200,130,-55);
		glVertex3f(200,110,-55);
		glVertex3f(200,110,-45);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(195,130,-45);
		glVertex3f(195,130,-55);
		glVertex3f(195,110,-55);
		glVertex3f(195,110,-45);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(195,130,-55);
		glVertex3f(200,130,-55);
		glVertex3f(200,110,-55);
		glVertex3f(195,110,-55);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(195,130,-45);
		glVertex3f(200,130,-45);
		glVertex3f(200,110,-45);
		glVertex3f(195,110,-45);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(195,130,-45);
		glVertex3f(200,130,-45);
		glVertex3f(200,130,-55);
		glVertex3f(195,130,-55);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(195,123,-40);
		glVertex3f(200,123,-40);
		glVertex3f(200,123,-45);
		glVertex3f(195,123,-45);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(195,123,-40);
		glVertex3f(200,123,-40);
		glVertex3f(200,110,-40);
		glVertex3f(195,110,-40);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(200,123,-40);
		glVertex3f(200,123,-45);
		glVertex3f(200,110,-45);
		glVertex3f(200,110,-40);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(195,123,-40);
		glVertex3f(195,123,-45);
		glVertex3f(195,110,-45);
		glVertex3f(195,110,-40);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(180,87,-135);
		glVertex3f(180,87,-140);
		glVertex3f(180,80,-140);
		glVertex3f(180,80,-135);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(185,87,-135);
		glVertex3f(185,87,-140);
		glVertex3f(185,80,-140);
		glVertex3f(185,80,-135);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-135);
		glVertex3f(185,87,-135);
		glVertex3f(185,80,-135);
		glVertex3f(180,80,-135);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-140);
		glVertex3f(185,87,-140);
		glVertex3f(185,80,-140);
		glVertex3f(180,80,-140);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-135);
		glVertex3f(185,87,-135);
		glVertex3f(185,87,-140);
		glVertex3f(180,87,-140);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(180,87,-165);
		glVertex3f(180,87,-170);
		glVertex3f(180,80,-170);
		glVertex3f(180,80,-165);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(185,87,-165);
		glVertex3f(185,87,-170);
		glVertex3f(185,80,-170);
		glVertex3f(185,80,-165);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-165);
		glVertex3f(185,87,-165);
		glVertex3f(185,80,-165);
		glVertex3f(180,80,-165);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-170);
		glVertex3f(185,87,-170);
		glVertex3f(185,80,-170);
		glVertex3f(180,80,-170);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-165);
		glVertex3f(185,87,-165);
		glVertex3f(185,87,-170);
		glVertex3f(180,87,-170);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(180,87,-195);
		glVertex3f(180,87,-200);
		glVertex3f(180,80,-200);
		glVertex3f(180,80,-195);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(185,87,-195);
		glVertex3f(185,87,-200);
		glVertex3f(185,80,-200);
		glVertex3f(185,80,-195);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-195);
		glVertex3f(185,87,-195);
		glVertex3f(185,80,-195);
		glVertex3f(180,80,-195);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-200);
		glVertex3f(185,87,-200);
		glVertex3f(185,80,-200);
		glVertex3f(180,80,-200);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-195);
		glVertex3f(185,87,-195);
		glVertex3f(185,87,-200);
		glVertex3f(180,87,-200);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(180,87,-225);
		glVertex3f(180,87,-230);
		glVertex3f(180,80,-230);
		glVertex3f(180,80,-225);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(185,87,-225);
		glVertex3f(185,87,-230);
		glVertex3f(185,80,-230);
		glVertex3f(185,80,-225);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-225);
		glVertex3f(185,87,-225);
		glVertex3f(185,80,-225);
		glVertex3f(180,80,-225);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-230);
		glVertex3f(185,87,-230);
		glVertex3f(185,80,-230);
		glVertex3f(180,80,-230);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-225);
		glVertex3f(185,87,-225);
		glVertex3f(185,87,-230);
		glVertex3f(180,87,-230);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(180,87,-255);
		glVertex3f(180,87,-260);
		glVertex3f(180,80,-260);
		glVertex3f(180,80,-255);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(185,87,-255);
		glVertex3f(185,87,-260);
		glVertex3f(185,80,-260);
		glVertex3f(185,80,-255);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-255);
		glVertex3f(185,87,-255);
		glVertex3f(185,80,-255);
		glVertex3f(180,80,-255);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-260);
		glVertex3f(185,87,-260);
		glVertex3f(185,80,-260);
		glVertex3f(180,80,-260);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(180,87,-255);
		glVertex3f(185,87,-255);
		glVertex3f(185,87,-260);
		glVertex3f(180,87,-260);
	glEnd();
	//-------------------------//
	glBegin(GL_QUADS);
		glVertex3f(170,87,-330);
		glVertex3f(170,87,-325);
		glVertex3f(170,80,-325);
		glVertex3f(170,80,-330);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(165,87,-330);
		glVertex3f(165,87,-325);
		glVertex3f(165,80,-325);
		glVertex3f(165,80,-330);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(165,87,-325);
		glVertex3f(170,87,-325);
		glVertex3f(170,80,-325);
		glVertex3f(165,80,-325);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(165,87,-330);
		glVertex3f(170,87,-330);
		glVertex3f(170,80,-330);
		glVertex3f(165,80,-330);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(165,87,-325);
		glVertex3f(170,87,-325);
		glVertex3f(170,87,-330);
		glVertex3f(165,87,-330);
	glEnd();
	//-------------------------//
	glBegin(GL_QUADS);
		glVertex3f(150,87,-295);
		glVertex3f(150,87,-290);
		glVertex3f(150,80,-290);
		glVertex3f(150,80,-295);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(145,87,-295);
		glVertex3f(145,87,-290);
		glVertex3f(145,80,-290);
		glVertex3f(145,80,-295);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(145,87,-290);
		glVertex3f(150,87,-290);
		glVertex3f(150,80,-290);
		glVertex3f(145,80,-290);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(145,87,-295);
		glVertex3f(150,87,-295);
		glVertex3f(150,80,-295);
		glVertex3f(145,80,-295);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(145,87,-290);
		glVertex3f(150,87,-290);
		glVertex3f(150,87,-295);
		glVertex3f(145,87,-295);
	glEnd();
	//-------------------------//
	glBegin(GL_QUADS);
		glVertex3f(120,87,-295);
		glVertex3f(120,87,-290);
		glVertex3f(120,80,-290);
		glVertex3f(120,80,-295);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(115,87,-295);
		glVertex3f(115,87,-290);
		glVertex3f(115,80,-290);
		glVertex3f(115,80,-295);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(115,87,-290);
		glVertex3f(120,87,-290);
		glVertex3f(120,80,-290);
		glVertex3f(115,80,-290);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(115,87,-295);
		glVertex3f(120,87,-295);
		glVertex3f(120,80,-295);
		glVertex3f(115,80,-295);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(115,87,-290);
		glVertex3f(120,87,-290);
		glVertex3f(120,87,-295);
		glVertex3f(115,87,-295);
	glEnd();
	//--------------------------//
	glBegin(GL_QUADS);
		glVertex3f(83,87,-305);
		glVertex3f(87,87,-305);
		glVertex3f(87,80,-305);
		glVertex3f(83,80,-305);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(83,87,-310);
		glVertex3f(87,87,-310);
		glVertex3f(87,80,-310);
		glVertex3f(83,80,-310);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(87,87,-310);
		glVertex3f(87,87,-305);
		glVertex3f(87,80,-305);
		glVertex3f(87,80,-310);
	glEnd();	
	glBegin(GL_QUADS);
		glVertex3f(83,87,-310);
		glVertex3f(83,87,-305);
		glVertex3f(83,80,-305);
		glVertex3f(83,80,-310);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(83,87,-310);
		glVertex3f(87,87,-310);
		glVertex3f(87,87,-305);
		glVertex3f(83,87,-305);
	glEnd();
	//------------------------//
	glBegin(GL_QUADS);
		glVertex3f(5,63,-420);
		glVertex3f(10,63,-420);
		glVertex3f(10,63,-417);
		glVertex3f(5,63,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(5,63,-417);
		glVertex3f(10,63,-417);
		glVertex3f(10,58,-417);
		glVertex3f(5,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(5,63,-417);
		glVertex3f(5,63,-420);
		glVertex3f(5,58,-420);
		glVertex3f(5,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(10,63,-417);
		glVertex3f(10,63,-420);
		glVertex3f(10,58,-420);
		glVertex3f(10,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(5,63,-420);
		glVertex3f(10,63,-420);
		glVertex3f(10,58,-420);
		glVertex3f(5,58,-420);
	glEnd();
	//------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-40,65,-420);
		glVertex3f(-45,65,-420);
		glVertex3f(-45,65,-417);
		glVertex3f(-40,65,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-40,65,-417);
		glVertex3f(-45,65,-417);
		glVertex3f(-45,58,-417);
		glVertex3f(-40,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-40,65,-417);
		glVertex3f(-40,65,-420);
		glVertex3f(-40,58,-420);
		glVertex3f(-40,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-45,65,-417);
		glVertex3f(-45,65,-420);
		glVertex3f(-45,58,-420);
		glVertex3f(-45,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-40,65,-420);
		glVertex3f(-45,65,-420);
		glVertex3f(-45,58,-420);
		glVertex3f(-40,58,-420);
	glEnd();
	//------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-90,65,-420);
		glVertex3f(-95,65,-420);
		glVertex3f(-95,65,-417);
		glVertex3f(-90,65,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-90,65,-417);
		glVertex3f(-95,65,-417);
		glVertex3f(-95,58,-417);
		glVertex3f(-90,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-90,65,-417);
		glVertex3f(-90,65,-420);
		glVertex3f(-90,58,-420);
		glVertex3f(-90,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-95,65,-417);
		glVertex3f(-95,65,-420);
		glVertex3f(-95,58,-420);
		glVertex3f(-95,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-90,65,-420);
		glVertex3f(-95,65,-420);
		glVertex3f(-95,58,-420);
		glVertex3f(-90,58,-420);
	glEnd();
	//--------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-140,65,-420);
		glVertex3f(-145,65,-420);
		glVertex3f(-145,65,-417);
		glVertex3f(-140,65,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-140,65,-417);
		glVertex3f(-145,65,-417);
		glVertex3f(-145,58,-417);
		glVertex3f(-140,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-140,65,-417);
		glVertex3f(-140,65,-420);
		glVertex3f(-140,58,-420);
		glVertex3f(-140,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-145,65,-417);
		glVertex3f(-145,65,-420);
		glVertex3f(-145,58,-420);
		glVertex3f(-145,58,-417);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-140,65,-420);
		glVertex3f(-145,65,-420);
		glVertex3f(-145,58,-420);
		glVertex3f(-140,58,-420);
	glEnd();
	//------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-200,130,-45);
		glVertex3f(-200,130,-55);
		glVertex3f(-200,110,-55);
		glVertex3f(-200,110,-45);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,130,-45);
		glVertex3f(-195,130,-55);
		glVertex3f(-195,110,-55);
		glVertex3f(-195,110,-45);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,130,-55);
		glVertex3f(-200,130,-55);
		glVertex3f(-200,110,-55);
		glVertex3f(-195,110,-55);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,130,-45);
		glVertex3f(-200,130,-45);
		glVertex3f(-200,110,-45);
		glVertex3f(-195,110,-45);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,130,-45);
		glVertex3f(-200,130,-45);
		glVertex3f(-200,130,-55);
		glVertex3f(-195,130,-55);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-195,123,-40);
		glVertex3f(-200,123,-40);
		glVertex3f(-200,123,-45);
		glVertex3f(-195,123,-45);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,123,-40);
		glVertex3f(-200,123,-40);
		glVertex3f(-200,110,-40);
		glVertex3f(-195,110,-40);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-200,123,-40);
		glVertex3f(-200,123,-45);
		glVertex3f(-200,110,-45);
		glVertex3f(-200,110,-40);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,123,-40);
		glVertex3f(-195,123,-45);
		glVertex3f(-195,110,-45);
		glVertex3f(-195,110,-40);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-135);
		glVertex3f(-190,87,-140);
		glVertex3f(-190,80,-140);
		glVertex3f(-190,80,-135);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-135);
		glVertex3f(-195,87,-140);
		glVertex3f(-195,80,-140);
		glVertex3f(-195,80,-135);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-135);
		glVertex3f(-195,87,-135);
		glVertex3f(-195,80,-135);
		glVertex3f(-190,80,-135);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-140);
		glVertex3f(-195,87,-140);
		glVertex3f(-195,80,-140);
		glVertex3f(-190,80,-140);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-135);
		glVertex3f(-195,87,-135);
		glVertex3f(-195,87,-140);
		glVertex3f(-190,87,-140);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-165);
		glVertex3f(-190,87,-170);
		glVertex3f(-190,80,-170);
		glVertex3f(-190,80,-165);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-165);
		glVertex3f(-195,87,-170);
		glVertex3f(-195,80,-170);
		glVertex3f(-195,80,-165);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-165);
		glVertex3f(-195,87,-165);
		glVertex3f(-195,80,-165);
		glVertex3f(-190,80,-165);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-170);
		glVertex3f(-195,87,-170);
		glVertex3f(-195,80,-170);
		glVertex3f(-190,80,-170);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-165);
		glVertex3f(-195,87,-165);
		glVertex3f(-195,87,-170);
		glVertex3f(-190,87,-170);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-195);
		glVertex3f(-190,87,-200);
		glVertex3f(-190,80,-200);
		glVertex3f(-190,80,-195);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-195);
		glVertex3f(-195,87,-200);
		glVertex3f(-195,80,-200);
		glVertex3f(-195,80,-195);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-195);
		glVertex3f(-195,87,-195);
		glVertex3f(-195,80,-195);
		glVertex3f(-190,80,-195);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-200);
		glVertex3f(-195,87,-200);
		glVertex3f(-195,80,-200);
		glVertex3f(-190,80,-200);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-195);
		glVertex3f(-195,87,-195);
		glVertex3f(-195,87,-200);
		glVertex3f(-190,87,-200);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-225);
		glVertex3f(-190,87,-230);
		glVertex3f(-190,80,-230);
		glVertex3f(-190,80,-225);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-225);
		glVertex3f(-195,87,-230);
		glVertex3f(-195,80,-230);
		glVertex3f(-195,80,-225);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-225);
		glVertex3f(-195,87,-225);
		glVertex3f(-195,80,-225);
		glVertex3f(-190,80,-225);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-230);
		glVertex3f(-195,87,-230);
		glVertex3f(-195,80,-230);
		glVertex3f(-190,80,-230);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-225);
		glVertex3f(-195,87,-225);
		glVertex3f(-195,87,-230);
		glVertex3f(-190,87,-230);
	glEnd();
	//---------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-255);
		glVertex3f(-190,87,-260);
		glVertex3f(-190,80,-260);
		glVertex3f(-190,80,-255);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-255);
		glVertex3f(-195,87,-260);
		glVertex3f(-195,80,-260);
		glVertex3f(-195,80,-255);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-255);
		glVertex3f(-195,87,-255);
		glVertex3f(-195,80,-255);
		glVertex3f(-190,80,-255);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-260);
		glVertex3f(-195,87,-260);
		glVertex3f(-195,80,-260);
		glVertex3f(-190,80,-260);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-255);
		glVertex3f(-195,87,-255);
		glVertex3f(-195,87,-260);
		glVertex3f(-190,87,-260);
	glEnd();
	//--------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-285);
		glVertex3f(-190,87,-290);
		glVertex3f(-190,80,-290);
		glVertex3f(-190,80,-285);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-285);
		glVertex3f(-195,87,-290);
		glVertex3f(-195,80,-290);
		glVertex3f(-195,80,-285);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-285);
		glVertex3f(-195,87,-285);
		glVertex3f(-195,80,-285);
		glVertex3f(-190,80,-285);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-290);
		glVertex3f(-195,87,-290);
		glVertex3f(-195,80,-290);
		glVertex3f(-190,80,-290);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-285);
		glVertex3f(-195,87,-285);
		glVertex3f(-195,87,-290);
		glVertex3f(-190,87,-290);
	glEnd();
	//--------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-315);
		glVertex3f(-190,87,-320);
		glVertex3f(-190,80,-320);
		glVertex3f(-190,80,-315);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-315);
		glVertex3f(-195,87,-320);
		glVertex3f(-195,80,-320);
		glVertex3f(-195,80,-315);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-315);
		glVertex3f(-195,87,-315);
		glVertex3f(-195,80,-315);
		glVertex3f(-190,80,-315);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-320);
		glVertex3f(-195,87,-320);
		glVertex3f(-195,80,-320);
		glVertex3f(-190,80,-320);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-315);
		glVertex3f(-195,87,-315);
		glVertex3f(-195,87,-320);
		glVertex3f(-190,87,-320);
	glEnd();
	//-------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-345);
		glVertex3f(-190,87,-350);
		glVertex3f(-190,80,-350);
		glVertex3f(-190,80,-345);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-345);
		glVertex3f(-195,87,-350);
		glVertex3f(-195,80,-350);
		glVertex3f(-195,80,-345);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-345);
		glVertex3f(-195,87,-345);
		glVertex3f(-195,80,-345);
		glVertex3f(-190,80,-345);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-350);
		glVertex3f(-195,87,-350);
		glVertex3f(-195,80,-350);
		glVertex3f(-190,80,-350);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-345);
		glVertex3f(-195,87,-345);
		glVertex3f(-195,87,-350);
		glVertex3f(-190,87,-350);
	glEnd();
	//-------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-375);
		glVertex3f(-190,87,-380);
		glVertex3f(-190,80,-380);
		glVertex3f(-190,80,-375);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-375);
		glVertex3f(-195,87,-380);
		glVertex3f(-195,80,-380);
		glVertex3f(-195,80,-375);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-375);
		glVertex3f(-195,87,-375);
		glVertex3f(-195,80,-375);
		glVertex3f(-190,80,-375);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-380);
		glVertex3f(-195,87,-380);
		glVertex3f(-195,80,-380);
		glVertex3f(-190,80,-380);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-375);
		glVertex3f(-195,87,-375);
		glVertex3f(-195,87,-380);
		glVertex3f(-190,87,-380);
	glEnd();
	//-------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-405);
		glVertex3f(-190,87,-410);
		glVertex3f(-190,80,-410);
		glVertex3f(-190,80,-405);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-405);
		glVertex3f(-195,87,-410);
		glVertex3f(-195,80,-410);
		glVertex3f(-195,80,-405);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-405);
		glVertex3f(-195,87,-405);
		glVertex3f(-195,80,-405);
		glVertex3f(-190,80,-405);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-410);
		glVertex3f(-195,87,-410);
		glVertex3f(-195,80,-410);
		glVertex3f(-190,80,-410);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-405);
		glVertex3f(-195,87,-405);
		glVertex3f(-195,87,-410);
		glVertex3f(-190,87,-410);
	glEnd();
	//--------------------------//
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-435);
		glVertex3f(-190,87,-440);
		glVertex3f(-190,80,-440);
		glVertex3f(-190,80,-435);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-195,87,-435);
		glVertex3f(-195,87,-440);
		glVertex3f(-195,80,-440);
		glVertex3f(-195,80,-435);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-435);
		glVertex3f(-195,87,-435);
		glVertex3f(-195,80,-435);
		glVertex3f(-190,80,-435);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-440);
		glVertex3f(-195,87,-440);
		glVertex3f(-195,80,-440);
		glVertex3f(-190,80,-440);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-190,87,-435);
		glVertex3f(-195,87,-435);
		glVertex3f(-195,87,-440);
		glVertex3f(-190,87,-440);
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
	glTranslatef(0,-50,-400);
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
