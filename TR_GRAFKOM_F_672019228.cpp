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
	glBegin(GL_LINES);
    glColor3f(1,1,1);
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
		glVertex3f(-180,10,-270);
		glVertex3f(-180,10,-100);
		glVertex3f(-85,10,-100);
		glVertex3f(-85,10,-270);
	glEnd();
		//bawah
		glColor3f(0.0,0.180,0.0);
	glBegin(GL_QUADS);
		glVertex3f(-230,-25,-450);
		glVertex3f(-230,-25,100);
		glVertex3f(230,-25,100);
		glVertex3f(230,-25,-450);
	glEnd();
	
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
		
		//Belakang kanan
		glColor3f(0.8784,1,1);
		glVertex3f(225,15,-340.1);
		glVertex3f(225,65,-340.1);
		glVertex3f(215,65,-340.1);
		glVertex3f(215,15,-340.1);	
		
		glVertex3f(210,15,-340.1);
		glVertex3f(210,65,-340.1);
		glVertex3f(200,65,-340.1);
		glVertex3f(200,15,-340.1);	
		
		glVertex3f(195,15,-340.1);
		glVertex3f(195,65,-340.1);
		glVertex3f(185,65,-340.1);
		glVertex3f(185,15,-340.1);
		
		glVertex3f(180,15,-340.1);
		glVertex3f(180,65,-340.1);
		glVertex3f(170,65,-340.1);
		glVertex3f(170,15,-340.1);
		
		glVertex3f(165,15,-340.1);
		glVertex3f(165,65,-340.1);
		glVertex3f(155,65,-340.1);
		glVertex3f(155,15,-340.1);
		
		glVertex3f(150,15,-340.1);
		glVertex3f(150,65,-340.1);
		glVertex3f(140,65,-340.1);
		glVertex3f(140,15,-340.1);
		
		glVertex3f(135,15,-340.1);
		glVertex3f(135,65,-340.1);
		glVertex3f(125,65,-340.1);
		glVertex3f(125,15,-340.1);
		
		glVertex3f(120,15,-340.1);
		glVertex3f(120,65,-340.1);
		glVertex3f(110,65,-340.1);
		glVertex3f(110,15,-340.1);
		
		glVertex3f(105,15,-340.1);
		glVertex3f(105,65,-340.1);
		glVertex3f(95,65,-340.1);
		glVertex3f(95,15,-340.1);
		
		glVertex3f(90,15,-340.1);
		glVertex3f(90,65,-340.1);
		glVertex3f(80,65,-340.1);
		glVertex3f(80,15,-340.1);
		
		//kanan belakang bawah
		glColor3f(0,0.5,0.5);
		glVertex3f(225,-22.5,-340.1);
		glVertex3f(225,7.5,-340.1);
		glVertex3f(215,7.5,-340.1);
		glVertex3f(215,-22.5,-340.1);	
		
		glVertex3f(210,-22.5,-340.1);
		glVertex3f(210,7.5,-340.1);
		glVertex3f(200,7.5,-340.1);
		glVertex3f(200,-22.5,-340.1);	
		
		glVertex3f(195,-22.5,-340.1);
		glVertex3f(195,7.5,-340.1);
		glVertex3f(185,7.5,-340.1);
		glVertex3f(185,-22.5,-340.1);
		
		glVertex3f(180,-22.5,-340.1);
		glVertex3f(180,7.5,-340.1);
		glVertex3f(170,7.5,-340.1);
		glVertex3f(170,-22.5,-340.1);
		
		glVertex3f(165,-22.5,-340.1);
		glVertex3f(165,7.5,-340.1);
		glVertex3f(155,7.5,-340.1);
		glVertex3f(155,-22.5,-340.1);
		
		glVertex3f(150,-22.5,-340.1);
		glVertex3f(150,7.5,-340.1);
		glVertex3f(140,7.5,-340.1);
		glVertex3f(140,-22.5,-340.1);
		
		glVertex3f(135,-22.5,-340.1);
		glVertex3f(135,7.5,-340.1);
		glVertex3f(125,7.5,-340.1);
		glVertex3f(125,-22.5,-340.1);
		
		glVertex3f(120,-22.5,-340.1);
		glVertex3f(120,7.5,-340.1);
		glVertex3f(110,7.5,-340.1);
		glVertex3f(110,-22.5,-340.1);
		
		glVertex3f(105,-22.5,-340.1);
		glVertex3f(105,7.5,-340.1);
		glVertex3f(95,7.5,-340.1);
		glVertex3f(95,-22.5,-340.1);
		
		glVertex3f(90,-22.5,-340.1);
		glVertex3f(90,7.5,-340.1);
		glVertex3f(80,7.5,-340.1);
		glVertex3f(80,-22.5,-340.1);	
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
		glColor3f(0.8784,1,1);
		glVertex3f(-230.1,15,-25);
		glVertex3f(-230.1,75,-25);
		glVertex3f(-230.1,75,-35);
		glVertex3f(-230.1,15,-35);
		
		glVertex3f(-230.1,15,-40);
		glVertex3f(-230.1,75,-40);
		glVertex3f(-230.1,75,-50);
		glVertex3f(-230.1,15,-50);
		
		glVertex3f(-230.1,15,-55);
		glVertex3f(-230.1,75,-55);
		glVertex3f(-230.1,75,-65);
		glVertex3f(-230.1,15,-65);
		
		glVertex3f(-230.1,15,-70);
		glVertex3f(-230.1,75,-70);
		glVertex3f(-230.1,75,-80);
		glVertex3f(-230.1,15,-80);
		
		glVertex3f(-230.1,15,-85);
		glVertex3f(-230.1,75,-85);
		glVertex3f(-230.1,75,-95);
		glVertex3f(-230.1,15,-95);
		
		glVertex3f(-230.1,15,-100);
		glVertex3f(-230.1,65,-100);
		glVertex3f(-230.1,65,-110);
		glVertex3f(-230.1,15,-110);
		
		glVertex3f(-230.1,15,-115);
		glVertex3f(-230.1,65,-115);
		glVertex3f(-230.1,65,-125);
		glVertex3f(-230.1,15,-125);	
		
		glVertex3f(-230.1,15,-130);
		glVertex3f(-230.1,65,-130);
		glVertex3f(-230.1,65,-140);
		glVertex3f(-230.1,15,-140);
		
		glVertex3f(-230.1,15,-145);
		glVertex3f(-230.1,65,-145);
		glVertex3f(-230.1,65,-155);
		glVertex3f(-230.1,15,-155);	
		
		glVertex3f(-230.1,15,-160);
		glVertex3f(-230.1,65,-160);
		glVertex3f(-230.1,65,-170);
		glVertex3f(-230.1,15,-170);	
		
		glVertex3f(-230.1,15,-175);
		glVertex3f(-230.1,65,-175);
		glVertex3f(-230.1,65,-185);
		glVertex3f(-230.1,15,-185);	
		
		glVertex3f(-230.1,15,-190);
		glVertex3f(-230.1,65,-190);
		glVertex3f(-230.1,65,-200);
		glVertex3f(-230.1,15,-200);	
		
		glVertex3f(-230.1,15,-205);
		glVertex3f(-230.1,65,-205);
		glVertex3f(-230.1,65,-215);
		glVertex3f(-230.1,15,-215);
		
		glVertex3f(-230.1,15,-220);
		glVertex3f(-230.1,65,-220);
		glVertex3f(-230.1,65,-230);
		glVertex3f(-230.1,15,-230);
		
		glVertex3f(-230.1,15,-235);
		glVertex3f(-230.1,65,-235);
		glVertex3f(-230.1,65,-245);
		glVertex3f(-230.1,15,-245);
		
		glVertex3f(-230.1,15,-250);
		glVertex3f(-230.1,65,-250);
		glVertex3f(-230.1,65,-260);
		glVertex3f(-230.1,15,-260);
		
		glVertex3f(-230.1,15,-265);
		glVertex3f(-230.1,65,-265);
		glVertex3f(-230.1,65,-275);
		glVertex3f(-230.1,15,-275);
		
		glVertex3f(-230.1,15,-280);
		glVertex3f(-230.1,65,-280);
		glVertex3f(-230.1,65,-290);
		glVertex3f(-230.1,15,-290);
		
		glVertex3f(-230.1,15,-295);
		glVertex3f(-230.1,65,-295);
		glVertex3f(-230.1,65,-305);
		glVertex3f(-230.1,15,-305);
		
		glVertex3f(-230.1,15,-310);
		glVertex3f(-230.1,65,-310);
		glVertex3f(-230.1,65,-320);
		glVertex3f(-230.1,15,-320);
		
		glVertex3f(-230.1,15,-325);
		glVertex3f(-230.1,65,-325);
		glVertex3f(-230.1,65,-335);
		glVertex3f(-230.1,15,-335);	
		
		glVertex3f(-230.1,15,-340);
		glVertex3f(-230.1,65,-340);
		glVertex3f(-230.1,65,-350);
		glVertex3f(-230.1,15,-350);	
		
		glVertex3f(-230.1,15,-355);
		glVertex3f(-230.1,65,-355);
		glVertex3f(-230.1,65,-365);
		glVertex3f(-230.1,15,-365);	
		
		glVertex3f(-230.1,15,-370);
		glVertex3f(-230.1,65,-370);
		glVertex3f(-230.1,65,-380);
		glVertex3f(-230.1,15,-380);	
		
		glVertex3f(-230.1,15,-385);
		glVertex3f(-230.1,65,-385);
		glVertex3f(-230.1,65,-395);
		glVertex3f(-230.1,15,-395);
		
		glVertex3f(-230.1,15,-400);
		glVertex3f(-230.1,65,-400);
		glVertex3f(-230.1,65,-410);
		glVertex3f(-230.1,15,-410);
		
		glVertex3f(-230.1,15,-415);
		glVertex3f(-230.1,65,-415);
		glVertex3f(-230.1,65,-425);
		glVertex3f(-230.1,15,-425);
		
		glVertex3f(-230.1,15,-430);
		glVertex3f(-230.1,65,-430);
		glVertex3f(-230.1,65,-440);
		glVertex3f(-230.1,15,-440);
		
		//Jendela samping kiri bawah
		glColor3f(0,0.5,0.5);
		glVertex3f(-230.1,-22.5,-25);
		glVertex3f(-230.1,7.5,-25);
		glVertex3f(-230.1,7.5,-35);
		glVertex3f(-230.1,-22.5,-35);
		
		glVertex3f(-230.1,-22.5,-40);
		glVertex3f(-230.1,7.5,-40);
		glVertex3f(-230.1,7.5,-50);
		glVertex3f(-230.1,-22.5,-50);
		
		glVertex3f(-230.1,-22.5,-55);
		glVertex3f(-230.1,7.5,-55);
		glVertex3f(-230.1,7.5,-65);
		glVertex3f(-230.1,-22.5,-65);
		
		glVertex3f(-230.1,-22.5,-70);
		glVertex3f(-230.1,7.5,-70);
		glVertex3f(-230.1,7.5,-80);
		glVertex3f(-230.1,-22.5,-80);
		
		glVertex3f(-230.1,-22.5,-85);
		glVertex3f(-230.1,7.5,-85);
		glVertex3f(-230.1,7.5,-95);
		glVertex3f(-230.1,-22.5,-95);
		
		glVertex3f(-230.1,-22.5,-100);
		glVertex3f(-230.1,7.5,-100);
		glVertex3f(-230.1,7.5,-110);
		glVertex3f(-230.1,-22.5,-110);
		
		glVertex3f(-230.1,-22.5,-115);
		glVertex3f(-230.1,7.5,-115);
		glVertex3f(-230.1,7.5,-125);
		glVertex3f(-230.1,-22.5,-125);	
		
		glVertex3f(-230.1,-22.5,-130);
		glVertex3f(-230.1,7.5,-130);
		glVertex3f(-230.1,7.5,-140);
		glVertex3f(-230.1,-22.5,-140);
		
		glVertex3f(-230.1,-22.5,-145);
		glVertex3f(-230.1,7.5,-145);
		glVertex3f(-230.1,7.5,-155);
		glVertex3f(-230.1,-22.5,-155);	
		
		glVertex3f(-230.1,-22.5,-160);
		glVertex3f(-230.1,7.5,-160);
		glVertex3f(-230.1,7.5,-170);
		glVertex3f(-230.1,-22.5,-170);	
		
		glVertex3f(-230.1,-22.5,-175);
		glVertex3f(-230.1,7.5,-175);
		glVertex3f(-230.1,7.5,-185);
		glVertex3f(-230.1,-22.5,-185);	
		
		glVertex3f(-230.1,-22.5,-190);
		glVertex3f(-230.1,7.5,-190);
		glVertex3f(-230.1,7.5,-200);
		glVertex3f(-230.1,-22.5,-200);	
		
		glVertex3f(-230.1,-22.5,-205);
		glVertex3f(-230.1,7.5,-205);
		glVertex3f(-230.1,7.5,-215);
		glVertex3f(-230.1,-22.5,-215);
		
		glVertex3f(-230.1,-22.5,-220);
		glVertex3f(-230.1,7.5,-220);
		glVertex3f(-230.1,7.5,-230);
		glVertex3f(-230.1,-22.5,-230);
		
		glVertex3f(-230.1,-22.5,-235);
		glVertex3f(-230.1,7.5,-235);
		glVertex3f(-230.1,7.5,-245);
		glVertex3f(-230.1,-22.5,-245);
		
		glVertex3f(-230.1,-22.5,-250);
		glVertex3f(-230.1,7.5,-250);
		glVertex3f(-230.1,7.5,-260);
		glVertex3f(-230.1,-22.5,-260);
		
		glVertex3f(-230.1,-22.5,-265);
		glVertex3f(-230.1,7.5,-265);
		glVertex3f(-230.1,7.5,-275);
		glVertex3f(-230.1,-22.5,-275);
		
		glVertex3f(-230.1,-22.5,-280);
		glVertex3f(-230.1,7.5,-280);
		glVertex3f(-230.1,7.5,-290);
		glVertex3f(-230.1,-22.5,-290);
		
		glVertex3f(-230.1,-22.5,-295);
		glVertex3f(-230.1,7.5,-295);
		glVertex3f(-230.1,7.5,-305);
		glVertex3f(-230.1,-22.5,-305);
		
		glVertex3f(-230.1,-22.5,-310);
		glVertex3f(-230.1,7.5,-310);
		glVertex3f(-230.1,7.5,-320);
		glVertex3f(-230.1,-22.5,-320);
		
		glVertex3f(-230.1,-22.5,-325);
		glVertex3f(-230.1,7.5,-325);
		glVertex3f(-230.1,7.5,-335);
		glVertex3f(-230.1,-22.5,-335);
		
		glVertex3f(-230.1,-22.5,-340);
		glVertex3f(-230.1,7.5,-340);
		glVertex3f(-230.1,7.5,-350);
		glVertex3f(-230.1,-22.5,-350);	
		
		glVertex3f(-230.1,-22.5,-355);
		glVertex3f(-230.1,7.5,-355);
		glVertex3f(-230.1,7.5,-365);
		glVertex3f(-230.1,-22.5,-365);	
		
		glVertex3f(-230.1,-22.5,-370);
		glVertex3f(-230.1,7.5,-370);
		glVertex3f(-230.1,7.5,-380);
		glVertex3f(-230.1,-22.5,-380);	
		
		glVertex3f(-230.1,-22.5,-385);
		glVertex3f(-230.1,7.5,-385);
		glVertex3f(-230.1,7.5,-395);
		glVertex3f(-230.1,-22.5,-395);
		
		glVertex3f(-230.1,-22.5,-400);
		glVertex3f(-230.1,7.5,-400);
		glVertex3f(-230.1,7.5,-410);
		glVertex3f(-230.1,-22.5,-410);
		
		glVertex3f(-230.1,-22.5,-415);
		glVertex3f(-230.1,7.5,-415);
		glVertex3f(-230.1,7.5,-425);
		glVertex3f(-230.1,-22.5,-425);
		
		glVertex3f(-230.1,-22.5,-430);
		glVertex3f(-230.1,7.5,-430);
		glVertex3f(-230.1,7.5,-440);
		glVertex3f(-230.1,-22.5,-440);
		
	glEnd();
	
	//jendela belakang
	glBegin(GL_QUADS);
	glColor3f(0.8784,1,1);
		glVertex3f(-15,15,-399.9);
		glVertex3f(-15,45,-399.9);
		glVertex3f(-25,45,-399.9);
		glVertex3f(-25,15,-399.9);
		
		glVertex3f(-30,15,-399.9);
		glVertex3f(-30,45,-399.9);
		glVertex3f(-40,45,-399.9);
		glVertex3f(-40,15,-399.9);
		
		glVertex3f(-45,15,-399.9);
		glVertex3f(-45,45,-399.9);
		glVertex3f(-55,45,-399.9);
		glVertex3f(-55,15,-399.9);
		
		glVertex3f(-60,15,-399.9);
		glVertex3f(-60,45,-399.9);
		glVertex3f(-70,45,-399.9);
		glVertex3f(-70,15,-399.9);
		
		glVertex3f(-75,15,-399.9);
		glVertex3f(-75,45,-399.9);
		glVertex3f(-85,45,-399.9);
		glVertex3f(-85,15,-399.9);
		
		glVertex3f(-90,15,-399.9);
		glVertex3f(-90,45,-399.9);
		glVertex3f(-100,45,-399.9);
		glVertex3f(-100,15,-399.9);
		
		glVertex3f(-105,15,-399.9);
		glVertex3f(-105,45,-399.9);
		glVertex3f(-115,45,-399.9);
		glVertex3f(-115,15,-399.9);
		
		glVertex3f(-120,15,-399.9);
		glVertex3f(-120,45,-399.9);
		glVertex3f(-130,45,-399.9);
		glVertex3f(-130,15,-399.9);
		
		glVertex3f(-135,15,-399.9);
		glVertex3f(-135,45,-399.9);
		glVertex3f(-145,45,-399.9);
		glVertex3f(-145,15,-399.9);
		
		glVertex3f(-150,15,-399.9);
		glVertex3f(-150,45,-399.9);
		glVertex3f(-160,45,-399.9);
		glVertex3f(-160,15,-399.9);
		
		glVertex3f(-165,15,-399.9);
		glVertex3f(-165,45,-399.9);
		glVertex3f(-175,45,-399.9);
		glVertex3f(-175,15,-399.9);
		
		//belakang bawah
		glColor3f(0,0.5,0.5);
		glVertex3f(-90,-22.5,-399.9);
		glVertex3f(-90,7.5,-399.9);
		glVertex3f(-100,7.5,-399.9);
		glVertex3f(-100,-22.5,-399.9);
		
		glVertex3f(-105,-22.5,-399.9);
		glVertex3f(-105,7.5,-399.9);
		glVertex3f(-115,7.5,-399.9);
		glVertex3f(-115,-22.5,-399.9);
		
		glVertex3f(-120,-22.5,-399.9);
		glVertex3f(-120,7.5,-399.9);
		glVertex3f(-130,7.5,-399.9);
		glVertex3f(-130,-22.5,-399.9);
		
		glVertex3f(-135,-22.5,-399.9);
		glVertex3f(-135,7.5,-399.9);
		glVertex3f(-145,7.5,-399.9);
		glVertex3f(-145,-22.5,-399.9);
		
		glVertex3f(-150,-22.5,-399.9);
		glVertex3f(-150,7.5,-399.9);
		glVertex3f(-160,7.5,-399.9);
		glVertex3f(-160,-22.5,-399.9);
		
		glVertex3f(-165,-22.5,-399.9);
		glVertex3f(-165,7.5,-399.9);
		glVertex3f(-175,7.5,-399.9);
		glVertex3f(-175,-22.5,-399.9);
		
	/*	//belakang belakang bawah
		glColor3f(0,0.5,0.5);
		glVertex3f(-90,-22.5,-450.1);
		glVertex3f(-90,7.5,-450.1);
		glVertex3f(-100,7.5,-450.1);
		glVertex3f(-100,-22.5,-450.1);
		
		glVertex3f(-105,-22.5,-450.1);
		glVertex3f(-105,7.5,-450.1);
		glVertex3f(-115,7.5,-450.1);
		glVertex3f(-115,-22.5,-450.1);
		
		glVertex3f(-120,-22.5,-450.1);
		glVertex3f(-120,7.5,-450.1);
		glVertex3f(-130,7.5,-450.1);
		glVertex3f(-130,-22.5,-450.1);
		
		glVertex3f(-135,-22.5,-450.1);
		glVertex3f(-135,7.5,-450.1);
		glVertex3f(-145,7.5,-450.1);
		glVertex3f(-145,-22.5,-450.1);
		
		glVertex3f(-150,-22.5,-450.1);
		glVertex3f(-150,7.5,-450.1);
		glVertex3f(-160,7.5,-450.1);
		glVertex3f(-160,-22.5,-450.1);
		
		glVertex3f(-165,-22.5,-450.1);
		glVertex3f(-165,7.5,-450.1);
		glVertex3f(-175,7.5,-450.1);
		glVertex3f(-175,-22.5,-450.1);
		
	*/	
	
	
	//jendela kiri (kanan)
	glColor3f(0.8784,1,1);
		glVertex3f(-179.9,15,-110);
		glVertex3f(-179.9,65,-110);
		glVertex3f(-179.9,65,-120);
		glVertex3f(-179.9,15,-120);
		
		glVertex3f(-179.9,15,-125);
		glVertex3f(-179.9,65,-125);
		glVertex3f(-179.9,65,-135);
		glVertex3f(-179.9,15,-135);
		
		glVertex3f(-179.9,15,-140);
		glVertex3f(-179.9,65,-140);
		glVertex3f(-179.9,65,-150);
		glVertex3f(-179.9,15,-150);
		
		glVertex3f(-179.9,15,-155);
		glVertex3f(-179.9,65,-155);
		glVertex3f(-179.9,65,-165);
		glVertex3f(-179.9,15,-165);
		
		glVertex3f(-179.9,15,-170);
		glVertex3f(-179.9,65,-170);
		glVertex3f(-179.9,65,-180);
		glVertex3f(-179.9,15,-180);
		
		glVertex3f(-179.9,15,-185);
		glVertex3f(-179.9,65,-185);
		glVertex3f(-179.9,65,-195);
		glVertex3f(-179.9,15,-195);
		
		glVertex3f(-179.9,15,-200);
		glVertex3f(-179.9,65,-200);
		glVertex3f(-179.9,65,-210);
		glVertex3f(-179.9,15,-210);
		
		glVertex3f(-179.9,15,-215);
		glVertex3f(-179.9,65,-215);
		glVertex3f(-179.9,65,-225);
		glVertex3f(-179.9,15,-225);
		
		glVertex3f(-179.9,15,-230);
		glVertex3f(-179.9,65,-230);
		glVertex3f(-179.9,65,-240);
		glVertex3f(-179.9,15,-240);
		
		glVertex3f(-179.9,15,-245);
		glVertex3f(-179.9,65,-245);
		glVertex3f(-179.9,65,-255);
		glVertex3f(-179.9,15,-255);
		
		glVertex3f(-179.9,15,-260);
		glVertex3f(-179.9,65,-260);
		glVertex3f(-179.9,65,-270);
		glVertex3f(-179.9,15,-270);
		
		glVertex3f(-179.9,15,-275);
		glVertex3f(-179.9,65,-275);
		glVertex3f(-179.9,65,-285);
		glVertex3f(-179.9,15,-285);
		
		glVertex3f(-179.9,15,-290);
		glVertex3f(-179.9,65,-290);
		glVertex3f(-179.9,65,-300);
		glVertex3f(-179.9,15,-300);
		
		glVertex3f(-179.9,15,-305);
		glVertex3f(-179.9,65,-305);
		glVertex3f(-179.9,65,-315);
		glVertex3f(-179.9,15,-315);
		
		glVertex3f(-179.9,15,-320);
		glVertex3f(-179.9,65,-320);
		glVertex3f(-179.9,65,-330);
		glVertex3f(-179.9,15,-330);
		
		glVertex3f(-179.9,15,-335);
		glVertex3f(-179.9,65,-335);
		glVertex3f(-179.9,65,-345);
		glVertex3f(-179.9,15,-345);
		
		glVertex3f(-179.9,15,-350);
		glVertex3f(-179.9,65,-350);
		glVertex3f(-179.9,65,-360);
		glVertex3f(-179.9,15,-360);
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
