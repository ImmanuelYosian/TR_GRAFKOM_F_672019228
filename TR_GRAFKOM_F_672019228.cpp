#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void init(void);
void tampil(void);
void mobil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int x, int y);
void mouse(int button, int state, int x, int y);
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;
const double PI = 3.142857143;
int i, radius, jumlah_titik, x_tengah, y_tengah,n;
float angle = 0;
int gerak = 0;
bool atas = true;
int is_depth;
bool jalans = 1;

void ab(float xkiri, float xkanan, float y, float zdepan, float zbelakang) {
    glBegin(GL_QUADS);
    glVertex3f(xkiri, y, zdepan);
    glVertex3f(xkanan, y, zdepan);
    glVertex3f(xkanan, y, zbelakang);
    glVertex3f(xkiri, y, zbelakang);
    glEnd();
}

void kotakatap(){
	glBegin(GL_QUADS);
		glColor3f(0.8,0.8,0.8);
		glVertex3f(-225,75,-290);
		glVertex3f(-185,75,-290);
		glVertex3f(-185,75,-340);
		glVertex3f(-225,75,-340);
		
		glColor3f(0.6,0.6,0.6);
		glVertex3f(-220,75,-290);
		glVertex3f(-220,85,-290);
		glVertex3f(-220,85,-340);
		glVertex3f(-220,75,-340);
		
		glVertex3f(-225,75,-290);
		glVertex3f(-225,85,-290);
		glVertex3f(-225,85,-340);
		glVertex3f(-225,75,-340);
		
		glVertex3f(-190,75,-290);
		glVertex3f(-190,85,-290);
		glVertex3f(-190,85,-340);
		glVertex3f(-190,75,-340);
		
		glVertex3f(-185,75,-290);
		glVertex3f(-185,85,-290);
		glVertex3f(-185,85,-340);
		glVertex3f(-185,75,-340);
		
		glVertex3f(-185,85,-290);
		glVertex3f(-190,85,-290);
		glVertex3f(-190,85,-340);
		glVertex3f(-185,85,-340);
		
		glVertex3f(-225,85,-290);
		glVertex3f(-220,85,-290);
		glVertex3f(-220,85,-340);
		glVertex3f(-225,85,-340);
		
		glVertex3f(-190,85,-290);
		glVertex3f(-220,85,-290);
		glVertex3f(-220,75,-290);
		glVertex3f(-190,75,-290);
		
		glVertex3f(-190,85,-295);
		glVertex3f(-220,85,-295);
		glVertex3f(-220,75,-295);
		glVertex3f(-190,75,-295);
		
		glVertex3f(-190,85,-335);
		glVertex3f(-220,85,-335);
		glVertex3f(-220,75,-335);
		glVertex3f(-190,75,-335);
		
		glVertex3f(-190,85,-340);
		glVertex3f(-220,85,-340);
		glVertex3f(-220,75,-340);
		glVertex3f(-190,75,-340);
		
		glVertex3f(-220,85,-340);
		glVertex3f(-220,85,-335);
		glVertex3f(-190,85,-335);
		glVertex3f(-190,85,-340);
		
		glVertex3f(-220,85,-290);
		glVertex3f(-220,85,-295);
		glVertex3f(-190,85,-295);
		glVertex3f(-190,85,-290);
		glEnd();
}

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

void bar (){
	//bar
	glColor3f(0.6,0.3,0.0);
	glBegin(GL_QUADS);
		glVertex3f(-160,-15,-250);
		glVertex3f(-85,-15,-250);
		glVertex3f(-85,-25,-250);
		glVertex3f(-160,-25,-250);
	
		glVertex3f(-150,-15,-260);
		glVertex3f(-85,-15,-260);
		glVertex3f(-85,-25,-260);
		glVertex3f(-150,-25,-260);
	
		glVertex3f(-150,-15,-250);
		glVertex3f(-85,-15,-250);
		glVertex3f(-85,-15,-260);
		glVertex3f(-150,-15,-260);
	
		glVertex3f(-150,-15,-250);
		glVertex3f(-150,-15,-270);
		glVertex3f(-150,-25,-270);
		glVertex3f(-150,-25,-250);
	
		glVertex3f(-160,-15,-250);
		glVertex3f(-160,-15,-270);
		glVertex3f(-160,-25,-270);
		glVertex3f(-160,-25,-250);
	
		glVertex3f(-160,-15,-250);
		glVertex3f(-150,-15,-250);
		glVertex3f(-150,-15,-270);
		glVertex3f(-160,-15,-270);
	glEnd();
	//lemarikaca bar
	glColor4f(1.0,1.0,1.0,1);
	glBegin(GL_QUADS);
		glVertex3f(-150,-15,-252);
		glVertex3f(-95,-15,-252);
		glVertex3f(-95,-5,-255);
		glVertex3f(-150,-5,-255);
	
		glVertex3f(-150,-15,-260);
		glVertex3f(-95,-15,-260);
		glVertex3f(-95,-5,-260);
		glVertex3f(-150,-5,-260);
	
		glVertex3f(-150,-5,-260);
		glVertex3f(-95,-5,-260);
		glVertex3f(-95,-5,-255);
		glVertex3f(-150,-5,-255);
	
		glVertex3f(-150,-15,-252);
		glVertex3f(-150,-15,-260);
		glVertex3f(-150,-5,-260);
		glVertex3f(-150,-5,-255);
	
		glVertex3f(-95,-15,-252);
		glVertex3f(-95,-15,-260);
		glVertex3f(-95,-5,-260);
		glVertex3f(-95,-5,-255);
	glEnd();
}

void lemari(){
	glBegin(GL_QUADS);
	glColor3f(0.2,0,0);
	glVertex3f(0,-25,60);
	glVertex3f(40,-25,60);
	glVertex3f(40,-10,60);
	glVertex3f(0,-10,60);
	
	glVertex3f(0,-10,50);
	glVertex3f(40,-10,50);
	glVertex3f(40,-10,60);
	glVertex3f(0,-10,60);
	
	glColor3f(0.1,0,0);
	glVertex3f(0,-18,50);
	glVertex3f(40,-18,50);
	glVertex3f(40,-18,60);
	glVertex3f(0,-18,60);
	
	glColor3f(0.2,0,0);
	glVertex3f(0,-25,50);
	glVertex3f(40,-25,50);
	glVertex3f(40,-25,60);
	glVertex3f(0,-25,60);	
	
	glVertex3f(0,-25,50);
	glVertex3f(0,-10,50);
	glVertex3f(0,-10,60);
	glVertex3f(0,-25,60);
	
	glVertex3f(40,-25,50);
	glVertex3f(40,-10,50);
	glVertex3f(40,-10,60);
	glVertex3f(40,-25,60);	
	glEnd();
}

void meja(){
	glColor3f(0.2,0,0);
	glBegin(GL_QUADS);
		glVertex3f(-35,-15,-190);
		glVertex3f(-35,-15,-192);
		glVertex3f(-35,-25,-192);
		glVertex3f(-35,-25,-190);
	
		glVertex3f(-35,-15,-210);
		glVertex3f(-35,-15,-212);
		glVertex3f(-35,-25,-212);
		glVertex3f(-35,-25,-210);
	
		glVertex3f(-33,-15,-190);
		glVertex3f(-33,-15,-192);
		glVertex3f(-33,-25,-192);
		glVertex3f(-33,-25,-190);
	
		glVertex3f(-33,-15,-210);
		glVertex3f(-33,-15,-212);
		glVertex3f(-33,-25,-212);
		glVertex3f(-33,-25,-210);
	
		glVertex3f(-25,-15,-190);
		glVertex3f(-25,-15,-192);
		glVertex3f(-25,-25,-192);
		glVertex3f(-25,-25,-190);
	
		glVertex3f(-25,-15,-210);
		glVertex3f(-25,-15,-212);
		glVertex3f(-25,-25,-212);
		glVertex3f(-25,-25,-210);
	
		glVertex3f(-23,-15,-190);
		glVertex3f(-23,-15,-192);
		glVertex3f(-23,-25,-192);
		glVertex3f(-23,-25,-190);
	
		glVertex3f(-23,-15,-210);
		glVertex3f(-23,-15,-212);
		glVertex3f(-23,-25,-212);
		glVertex3f(-23,-25,-210);
	
		glVertex3f(-35,-15,-210);
		glVertex3f(-33,-15,-210);
		glVertex3f(-33,-25,-210);
		glVertex3f(-35,-25,-210);
	
		glVertex3f(-35,-15,-212);
		glVertex3f(-33,-15,-212);
		glVertex3f(-33,-25,-212);
		glVertex3f(-35,-25,-212);
	
		glVertex3f(-35,-15,-190);
		glVertex3f(-33,-15,-190);
		glVertex3f(-33,-25,-190);
		glVertex3f(-35,-25,-190);

		glVertex3f(-35,-15,-192);
		glVertex3f(-33,-15,-192);
		glVertex3f(-33,-25,-192);
		glVertex3f(-35,-25,-192);
	
		glVertex3f(-25,-15,-210);
		glVertex3f(-23,-15,-210);
		glVertex3f(-23,-25,-210);
		glVertex3f(-25,-25,-210);
	
		glVertex3f(-25,-15,-212);
		glVertex3f(-23,-15,-212);
		glVertex3f(-23,-25,-212);
		glVertex3f(-25,-25,-212);
	
		glVertex3f(-25,-15,-190);
		glVertex3f(-23,-15,-190);
		glVertex3f(-23,-25,-190);
		glVertex3f(-25,-25,-190);
	
		glVertex3f(-25,-15,-192);
		glVertex3f(-23,-15,-192);
		glVertex3f(-23,-25,-192);
		glVertex3f(-25,-25,-192);
	
		glVertex3f(-37,-15,-215);
		glVertex3f(-20,-15,-215);
		glVertex3f(-20,-15,-187);
		glVertex3f(-37,-15,-187);
	glEnd();
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

void kursiPanjang(){
	glBegin(GL_QUADS);
	glColor3f(0.2,0,0);
	glVertex3f(0,-20,30);
	glVertex3f(0,-20,80);
	glVertex3f(10,-20,80);
	glVertex3f(10,-20,30);
	
	glVertex3f(0,-10,30);
	glVertex3f(0,-10,80);
	glVertex3f(0,-20,80);
	glVertex3f(0,-20,30);
	
	glVertex3f(3,-20,31);
	glVertex3f(3,-25,31);
	glVertex3f(1,-25,31);
	glVertex3f(1,-20,31);
	
	glVertex3f(3,-20,33);
	glVertex3f(3,-25,33);
	glVertex3f(1,-25,33);
	glVertex3f(1,-20,33);
	
	glVertex3f(3,-20,77);
	glVertex3f(3,-25,77);
	glVertex3f(1,-25,77);
	glVertex3f(1,-20,77);
	
	glVertex3f(3,-20,79);
	glVertex3f(3,-25,79);
	glVertex3f(1,-25,79);
	glVertex3f(1,-20,79);
	
	glVertex3f(1,-20,79);
	glVertex3f(1,-25,79);
	glVertex3f(1,-25,77);
	glVertex3f(1,-20,77);
	
	glVertex3f(3,-20,79);
	glVertex3f(3,-25,79);
	glVertex3f(3,-25,77);
	glVertex3f(3,-20,77);
	
	glVertex3f(1,-20,33);
	glVertex3f(1,-25,33);
	glVertex3f(1,-25,31);
	glVertex3f(1,-20,31);
	
	glVertex3f(3,-20,33);
	glVertex3f(3,-25,33);
	glVertex3f(3,-25,31);
	glVertex3f(3,-20,31);
	
	
	glVertex3f(7,-20,31);
	glVertex3f(7,-25,31);
	glVertex3f(9,-25,31);
	glVertex3f(9,-20,31);
	
	glVertex3f(9,-20,33);
	glVertex3f(9,-25,33);
	glVertex3f(7,-25,33);
	glVertex3f(7,-20,33);
	
	glVertex3f(9,-20,77);
	glVertex3f(9,-25,77);
	glVertex3f(7,-25,77);
	glVertex3f(7,-20,77);
	
	glVertex3f(9,-20,79);
	glVertex3f(9,-25,79);
	glVertex3f(7,-25,79);
	glVertex3f(7,-20,79);
	
	glVertex3f(7,-20,79);
	glVertex3f(7,-25,79);
	glVertex3f(7,-25,77);
	glVertex3f(7,-20,77);
	
	glVertex3f(9,-20,79);
	glVertex3f(9,-25,79);
	glVertex3f(9,-25,77);
	glVertex3f(9,-20,77);
	
	glVertex3f(7,-20,33);
	glVertex3f(7,-25,33);
	glVertex3f(7,-25,31);
	glVertex3f(7,-20,31);
	
	glVertex3f(9,-20,33);
	glVertex3f(9,-25,33);
	glVertex3f(9,-25,31);
	glVertex3f(9,-20,31);
	glEnd();
}

void kursi(){
	glBegin(GL_QUADS);
	glColor3f(0.2,0,0);
	glVertex3f(0,-20,30);
	glVertex3f(0,-20,40);
	glVertex3f(10,-20,40);
	glVertex3f(10,-20,30);
	
	glVertex3f(10,-10,30);
	glVertex3f(10,-10,40);
	glVertex3f(10,-20,40);
	glVertex3f(10,-20,30);
	
	glVertex3f(3,-20,31);
	glVertex3f(3,-25,31);
	glVertex3f(1,-25,31);
	glVertex3f(1,-20,31);
	
	glVertex3f(3,-20,33);
	glVertex3f(3,-25,33);
	glVertex3f(1,-25,33);
	glVertex3f(1,-20,33);
	
	glVertex3f(3,-20,37);
	glVertex3f(3,-25,37);
	glVertex3f(1,-25,37);
	glVertex3f(1,-20,37);
	
	glVertex3f(3,-20,39);
	glVertex3f(3,-25,39);
	glVertex3f(1,-25,39);
	glVertex3f(1,-20,39);
	
	glVertex3f(1,-20,39);
	glVertex3f(1,-25,39);
	glVertex3f(1,-25,37);
	glVertex3f(1,-20,37);
	
	glVertex3f(3,-20,39);
	glVertex3f(3,-25,39);
	glVertex3f(3,-25,37);
	glVertex3f(3,-20,37);
	
	glVertex3f(1,-20,33);
	glVertex3f(1,-25,33);
	glVertex3f(1,-25,31);
	glVertex3f(1,-20,31);
	
	glVertex3f(3,-20,33);
	glVertex3f(3,-25,33);
	glVertex3f(3,-25,31);
	glVertex3f(3,-20,31);
	
	
	glVertex3f(7,-20,31);
	glVertex3f(7,-25,31);
	glVertex3f(9,-25,31);
	glVertex3f(9,-20,31);
	
	glVertex3f(9,-20,33);
	glVertex3f(9,-25,33);
	glVertex3f(7,-25,33);
	glVertex3f(7,-20,33);
	
	glVertex3f(9,-20,37);
	glVertex3f(9,-25,37);
	glVertex3f(7,-25,37);
	glVertex3f(7,-20,37);
	
	glVertex3f(9,-20,39);
	glVertex3f(9,-25,39);
	glVertex3f(7,-25,39);
	glVertex3f(7,-20,39);
	
	glVertex3f(7,-20,39);
	glVertex3f(7,-25,39);
	glVertex3f(7,-25,37);
	glVertex3f(7,-20,37);
	
	glVertex3f(9,-20,39);
	glVertex3f(9,-25,39);
	glVertex3f(9,-25,37);
	glVertex3f(9,-20,37);
	
	glVertex3f(7,-20,33);
	glVertex3f(7,-25,33);
	glVertex3f(7,-25,31);
	glVertex3f(7,-20,31);
	
	glVertex3f(9,-20,33);
	glVertex3f(9,-25,33);
	glVertex3f(9,-25,31);
	glVertex3f(9,-20,31);
	glEnd();
}

void init(void)
{
    glClearColor(0.4, 0.7, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(20.0);
    glLineWidth(6.0f);

}

void mading(){
	glBegin(GL_QUADS);
	glColor3f(0.1,0,0);
	glVertex3f(0,-20,70);
	glVertex3f(30,-20,70);
	glVertex3f(30,10,70);
	glVertex3f(0,10,70);
	
	glVertex3f(0,-20,72);
	glVertex3f(30,-20,72);
	glVertex3f(30,10,72);
	glVertex3f(0,10,72);
	
	glVertex3f(30,-20,72);
	glVertex3f(30,-20,70);
	glVertex3f(30,10,70);
	glVertex3f(30,10,72);
	
	glVertex3f(0,-20,72);
	glVertex3f(0,-20,70);
	glVertex3f(0,10,70);
	glVertex3f(0,10,72);
	
	glVertex3f(30,-20,72);
	glVertex3f(30,-20,70);
	glVertex3f(0,-20,70);
	glVertex3f(0,-20,72);
	
	glVertex3f(30,10,72);
	glVertex3f(30,10,70);
	glVertex3f(0,10,70);
	glVertex3f(0,10,72);
	
	glColor3f(0.3,0.3,0.3);
	glVertex3f(2,-18,72.1);
	glVertex3f(28,-18,72.1);
	glVertex3f(28,8,72.1);
	glVertex3f(2,8,72.1);
	
	glEnd();
}

void jalan() {
    glColor3f(0.1, 0.1, 0.1);
    ab(-280.0, 280.0, -25.10, 100, 50);

    //garis
    glColor3f(1.0, 1.0, 1.0);
    ab(-240.0, -210.0, -25.09, 76.0, 73.0);
    ab(-180.0, -150.0, -25.09, 76.0, 73.0);
    ab(-120.0, -90.0, -25.09, 76.0, 73.0);
    ab(-60.0, -30.0, -25.09, 76.0, 73.0);
    ab(0.0, 30.0, -25.09, 76.0, 73.0);
    ab(60.0, 90.0, -25.09, 76.0, 73.0);
    ab(120.0, 150.0, -25.09, 76.0, 73.0);
    ab(180.0, 200.0, -25.09, 76.0, 73.0);
    ab(230.0, 260.0, -25.09, 76.0, 73.0);
}
void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
	mobil();
	jalan();
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
	glColor3f(0.90,0.91,0.98);
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
		glVertex3f(-180,70,-300);
		glVertex3f(-180,50,-300);
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
	
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-120);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-240,70,-100);
		glVertex3f(-170,70,-100);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-170,70,-100);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-120);
		glVertex3f(-205,90,-270);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-170,70,-300);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-240,70,-100);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-120);
		glVertex3f(-205,90,-270);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-240,70,-300);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-270);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-230,75,-290);
		glVertex3f(-180,75,-290);
	glEnd();
	
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-360);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-230,75,-340);
		glVertex3f(-180,75,-340);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-170,70,-460);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-430);
		glVertex3f(-205,90,-360);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-170,70,-330);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-240,70,-460);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-430);
		glVertex3f(-205,90,-360);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-240,70,-330);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.158824,0.158824,0.335294);
		glVertex3f(-205,90,-430);
		glColor3f(0.258824,0.258824,0.435294);
		glVertex3f(-240,70,-460);
		glVertex3f(-170,70,-460);
	glEnd();
	
	
	glPushMatrix();
	glTranslatef(0,-10,0);
		kotakatap();
	glPopMatrix();

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
	glColor3f(0.35, 0.16, 0.14);
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
	
	//ALAS 
	glColor3f(0.0,0.180,0.0);
	glBegin(GL_QUADS);
	glVertex3f(-280,-25.2,-500);
	glVertex3f(-280,-25.2,50);
	glVertex3f(230,-25.2,50);
	glVertex3f(230,-25.2,-500);
	glEnd();
	glColor3f(0.0,0.180,0.0);
	glBegin(GL_QUADS);
	glVertex3f(230,-25,-460);
	glVertex3f(230,-25,-20);
	glVertex3f(260,-25,-20);
	glVertex3f(260,-25,-460);
	glEnd();
	glColor3f(0.0,0.180,0.0);
	glBegin(GL_QUADS);
	glVertex3f(260,-25.2,-500);
	glVertex3f(260,-25.2,50);
	glVertex3f(280,-25.2,50);
	glVertex3f(280,-25.2,-500);
	glEnd();


	
	glBegin(GL_QUADS); // jendela kanan atas		
		// kanan bawah
		glColor3f(0.1,0.1,0.1);
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
			glColor3f(0.1,0.1,0.1);
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
			
			glColor3f(1,1,0.5);
			glVertex3f(230.1,45,-23-i*21);
			glVertex3f(230.1,30,-23-i*21);
			glVertex3f(230.1,30,-32-i*21);
			glVertex3f(230.1,45,-32-i*21);
			
			glVertex3f(230.1,45,-33-i*21);
			glVertex3f(230.1,30,-33-i*21);
			glVertex3f(230.1,30,-42-i*21);
			glVertex3f(230.1,45,-42-i*21);
			
			
			if(i == 1 || i == 2){
				
				if( i == 1){
					glColor3f(0.2,0.2,0.2);
					glVertex3f(230.1,-5,-33-i*21);
					glVertex3f(233.1,-8,-33-i*21);
					glVertex3f(233.1,-8,-63-i*21);
					glVertex3f(230.1,-5,-63-i*21);
					
					glColor3f(0.1,0.1,0.1);
					glVertex3f(230.1,-15,-23-i*21);
					glVertex3f(230.1,5,-23-i*21);
					glVertex3f(230.1,5,-32-i*21);
					glVertex3f(230.1,-15,-32-i*21);
					
					glColor3f(0,0,0);
					glVertex3f(230.1,-25,-33-i*21);
					glVertex3f(230.1,-5,-33-i*21);
					glVertex3f(230.1,-5,-42-i*21);
					glVertex3f(230.1,-25,-42-i*21);
				} else {
					glColor3f(0,0,0);
					glVertex3f(230.1,-25,-23-i*21);
					glVertex3f(230.1,-5,-23-i*21);
					glVertex3f(230.1,-5,-42-i*21);
					glVertex3f(230.1,-25,-42-i*21);
				}
			} else {
				glColor3f(0.1,0.1,0.1);
				glVertex3f(230.1,-15,-23-i*21);
				glVertex3f(230.1,5,-23-i*21);
				glVertex3f(230.1,5,-32-i*21);
				glVertex3f(230.1,-15,-32-i*21);
				
				glVertex3f(230.1,-15,-33-i*21);
				glVertex3f(230.1,5,-33-i*21);
				glVertex3f(230.1,5,-42-i*21);
				glVertex3f(230.1,-15,-42-i*21);
			}
			
			
		}
	glEnd();
	
	glBegin(GL_QUADS); // jendela kanan atas		
	// kanan bawah
	glColor3f(0.1,0.1,0.1);
	
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
			glColor3f(0.1,0.1,0.1);
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
			
			glColor3f(1,1,0.5);
			glVertex3f(-230.1,45,-23-i*21);
			glVertex3f(-230.1,30,-23-i*21);
			glVertex3f(-230.1,30,-32-i*21);
			glVertex3f(-230.1,45,-32-i*21);
			
			glVertex3f(-230.1,45,-33-i*21);
			glVertex3f(-230.1,30,-33-i*21);
			glVertex3f(-230.1,30,-42-i*21);
			glVertex3f(-230.1,45,-42-i*21);
			
			glColor3f(0.1,0.1,0.1);
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
			glColor3f(0.1,0.1,0.1); //jendela putih belakang kanan
			glVertex3f(115-30+i*11,10,-340.1);
			glVertex3f(115-30+i*11,30,-340.1);
			glVertex3f(115-40+i*11,30,-340.1);
			glVertex3f(115-40+i*11,10,-340.1);

			glVertex3f(115-30+i*11,45,-340.1);
			glVertex3f(115-30+i*11,65,-340.1);
			glVertex3f(115-40+i*11,65,-340.1);
			glVertex3f(115-40+i*11,45,-340.1);

			glColor3f(1,1,0.5); // garis tengah kuning
			glVertex3f(115-30+i*11,45,-340.1);
			glVertex3f(115-30+i*11,30,-340.1);
			glVertex3f(115-40+i*11,30,-340.1);
			glVertex3f(115-40+i*11,45,-340.1);

			glColor3f(0.1,0.1,0.1); // jendela bawah belakang kanan
			glVertex3f(115-30+i*11,-15,-340.1);
			glVertex3f(115-30+i*11,5,-340.1);
			glVertex3f(115-40+i*11,5,-340.1);
			glVertex3f(115-40+i*11,-15,-340.1);
		}	
		
		
	glEnd();
		
	glBegin(GL_QUADS);
//jendela kiri (kanan)
	for(i = 0;i<14;i++){ //perulangan kiri (kanan)
			glColor3f(0.1,0.1,0.1); //jendela putih
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
			
			glColor3f(1,1,0.5); // garis tengah kuning
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
			glColor3f(0.1,0.1,0.1); //jendela putih
			glVertex3f(-170+i*12,10,-399.9);
			glVertex3f(-170+i*12,22.5,-399.9);
			glVertex3f(-180+i*12,22.5,-399.9);
			glVertex3f(-180+i*12,10,-399.9);
			
			glVertex3f(-170+i*12,37.5,-399.9);
			glVertex3f(-170+i*12,50,-399.9);
			glVertex3f(-180+i*12,50,-399.9);
			glVertex3f(-180+i*12,37.5,-399.9);
			
			glColor3f(1,1,0.5); // garis tengah kuning
			glVertex3f(-170+i*12,22.5,-399.9);
			glVertex3f(-170+i*12,37.5,-399.9);
			glVertex3f(-180+i*12,37.5,-399.9);
			glVertex3f(-180+i*12,22.5,-399.9);
						
		}

		//belakang bawah
		glColor3f(0.1,0.1,0.1); // jendela bawah
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
	glPushMatrix();
	glScalef(3,2,1);
	glTranslatef(125,-50,-15);
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
	glPopMatrix();
	
	glPushMatrix();
	glScalef(3,4,3);
	glTranslatef(125,-65,180);
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
	glPopMatrix();
	//--------------------------//
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
	bar();
	//lemari
	glPushMatrix();
	glTranslatef(-125.1,14,-160.1);
	glScalef(1,1.5,1);
	lemari();
	glPopMatrix();
	//kursi
	for(i=0;i<3;i++){
		glPushMatrix();
		glTranslatef(-120,0,-170-i*15);
		kursi();
		glPopMatrix();
		
		glPushMatrix();
		glRotatef(180,0,1,0);
		glTranslatef(138,0,100+i*15);
		kursi();
		glPopMatrix();
	}
	//meja
	glPushMatrix();
	glTranslatef(-100,0,250);
	glScalef(1,1,2);
	glColor3f(0.2,0,0);
	meja();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-179.9,0,-270);
	kursiPanjang();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(100,0,-169.9);
	mading();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-120,0,-169.9);
	mading();
	glPopMatrix();
	
	//Depan
	glBegin(GL_QUADS);
	glColor3f(0.575,0.575,0.575);
	glVertex3f(-75,-25,-20);
	glVertex3f(-75,-25,100);
	glVertex3f(75,-25,100);
	glVertex3f(75,-25,-20);
	
	//pembatas kiri
	glColor3f(0.675,0.675,0.375);
	glVertex3f(-75,-24.8,50);
	glVertex3f(-75,-24.8,-20);
	glVertex3f(-70,-24.8,-20);
	glVertex3f(-70,-24.8,50);
	
	glVertex3f(-75,-18,50);
	glVertex3f(-75,-18,-20);
	glVertex3f(-70,-18,-20);
	glVertex3f(-70,-18,50);
	
	glVertex3f(-75,-18,50);
	glVertex3f(-75,-18,-20);
	glVertex3f(-75,-24.8,-20);
	glVertex3f(-75,-24.8,50);
	
	glVertex3f(-70,-18,50);
	glVertex3f(-70,-18,-20);
	glVertex3f(-70,-24.8,-20);
	glVertex3f(-70,-24.8,50);
	
	//Pembatas kanan
	glVertex3f(75,-24.8,50);
	glVertex3f(75,-24.8,-20);
	glVertex3f(70,-24.8,-20);
	glVertex3f(70,-24.8,50);
	
	glVertex3f(75,-18,50);
	glVertex3f(75,-18,-20);
	glVertex3f(70,-18,-20);
	glVertex3f(70,-18,50);
	
	glVertex3f(75,-18,50);
	glVertex3f(75,-18,-20);
	glVertex3f(75,-24.8,-20);
	glVertex3f(75,-24.8,50);
	
	glVertex3f(70,-18,50);
	glVertex3f(70,-18,-20);
	glVertex3f(70,-24.8,-20);
	glVertex3f(70,-24.8,50);
	
	//pintu 
	glColor3f(0,0,0);
	
	glVertex3f(213,-25,-19.9);
	glVertex3f(203,-25,-19.9);
	glVertex3f(203,-5,-19.9);
	glVertex3f(213,-5,-19.9);
	
	//atas pintu
	glColor3f(0.3,0.3,0.3);
	glVertex3f(213,-5,-19.9);
	glVertex3f(203,-5,-19.9);
	glVertex3f(203,-7,-16.9);
	glVertex3f(213,-7,-16.9);
	
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
		glVertex3f(-85,0,-165);
		glVertex3f(-85,-25,-165);
		glVertex3f(-85,-25,-155);
	glEnd();
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-205);
		glVertex3f(-85,0,-195);
		glVertex3f(-85,-25,-195);
		glVertex3f(-85,-25,-205);
	glEnd();
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-120);
		glVertex3f(-85,0,-100);
		glVertex3f(-85,-25,-100);
		glVertex3f(-85,-25,-120);
	glEnd();
	
	//pintu gedung putih 1 kiri
	glColor4f(0,0,0,0.4);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-120);
		glVertex3f(-85,0,-140);
		glVertex3f(-85,-25,-140);
		glVertex3f(-85,-25,-120);
	glEnd();
	//pintu gedung putih 1 kanan
	glColor4f(0,0,0,0.4);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-155);
		glVertex3f(-80,0,-140);
		glVertex3f(-80,-25,-140);
		glVertex3f(-85,-25,-155);
	glEnd();
	
	
	//pintu gedung putih 2 kiri
	glColor4f(0,0,0,0.4);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-165);
		glVertex3f(-85,0,-180);
		glVertex3f(-85,-25,-180);
		glVertex3f(-85,-25,-165);
	glEnd();
	//pintu gedung putih 2 kanan
	glColor4f(0,0,0,0.4);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-195);
		glVertex3f(-80,0,-180);
		glVertex3f(-80,-25,-180);
		glVertex3f(-85,-25,-195);
	glEnd();
	
	//pintu gedung putih 3 kiri
	glColor4f(0,0,0,0.4);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-205);
		glVertex3f(-85,0,-225);
		glVertex3f(-85,-25,-225);
		glVertex3f(-85,-25,-205);
	glEnd();
	//pintu gedung putih 3 kanan
	glColor4f(0,0,0,0.4);
	glBegin(GL_QUADS);
		glVertex3f(-85,0,-240);
		glVertex3f(-80,0,-225);
		glVertex3f(-80,-25,-225);
		glVertex3f(-85,-25,-240);
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
		glVertex3f(-125,10,-230);
		glVertex3f(-125,10,-200);
		glVertex3f(-85,10,-200);
		glVertex3f(-85,10,-230);
	glEnd();
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_QUADS);
		glVertex3f(-140,15,-160);
		glVertex3f(-140,15,-100);
		glVertex3f(-140,10,-100);
		glVertex3f(-140,10,-160);
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
	//rumput
	glColor3f(0.0,0.3,0.0);
	glBegin(GL_QUADS);
		glVertex3f(-165,12,-230);
		glVertex3f(-165,12,-220);
		glVertex3f(-125,12,-220);
		glVertex3f(-125,12,-230);
	glEnd();
	glColor3f(0.0,0.3,0.0);
	glBegin(GL_QUADS);
		glVertex3f(-170,12,-150);
		glVertex3f(-170,12,-160);
		glVertex3f(-120,12,-160);
		glVertex3f(-120,12,-150);
	glEnd();
		glColor3f(0.0,0.3,0.0);
	glBegin(GL_QUADS);
		glVertex3f(-130,12,-200);
		glVertex3f(-130,12,-160);
		glVertex3f(-120,12,-160);
		glVertex3f(-120,12,-200);
	glEnd();
		glColor3f(0.0,0.3,0.0);
	glBegin(GL_QUADS);
		glVertex3f(-135,12,-200);
		glVertex3f(-135,12,-220);
		glVertex3f(-125,12,-220);
		glVertex3f(-125,12,-200);
	glEnd();
	//jalan setapak gedungdepan dan kanan
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);
		glVertex3f(160,-25,-280);
		glVertex3f(160,-25,-100);
		glVertex3f(180,-25,-100);
		glVertex3f(180,-25,-280);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);
		glVertex3f(90,-25,-120);
		glVertex3f(90,-25,-100);
		glVertex3f(180,-25,-100);
		glVertex3f(180,-25,-120);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);
		glVertex3f(90,-25,-260);
		glVertex3f(90,-25,-280);
		glVertex3f(180,-25,-280);
		glVertex3f(180,-25,-260);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);
		glVertex3f(90,-25,-280);
		glVertex3f(90,-25,-100);
		glVertex3f(100,-25,-100);
		glVertex3f(100,-25,-280);
	glEnd();
	//jalan setapak tengah
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_QUADS);
		glVertex3f(-180,-25,-270);
		glVertex3f(-180,-25,-295);
		glVertex3f(75,-25,-295);
		glVertex3f(75,-25,-270);
	glEnd();
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_QUADS);
		glVertex3f(50,-25,-270);
		glVertex3f(50,-25,-70);
		glVertex3f(75,-25,-70);
		glVertex3f(75,-25,-270);
	glEnd();
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_QUADS);
		glVertex3f(-85,-25,-70);
		glVertex3f(-85,-25,-155);
		glVertex3f(75,-25,-155);
		glVertex3f(75,-25,-70);
	glEnd();
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_QUADS);
		glVertex3f(-60,-25,-270);
		glVertex3f(-60,-25,-70);
		glVertex3f(-85,-25,-70);
		glVertex3f(-85,-25,-270);
	glEnd();
//	jalan 
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_QUADS);
		glVertex3f(260,-65,-70);
		glVertex3f(260,-25.2,50);
		glVertex3f(230,-25.2,50);
		glVertex3f(230,-65,-70);
	glEnd();
//tembokjalan bawah tanah
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_TRIANGLES);
		glVertex3f(230,-65,-70);
		glVertex3f(230,-25,50);
		glVertex3f(230,-25,-70);
		glEnd();
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_TRIANGLES);
		glVertex3f(260,-65,-70);
		glVertex3f(260,-25,50);
		glVertex3f(260,-25,-70);
		glEnd();
	//bawah tanah
	//alas
		glColor3f(0.1,0.1,0.1);
		glBegin(GL_QUADS);
		glVertex3f(-230,-65,-370);
		glVertex3f(-230,-65,-70);
		glVertex3f(260,-65,-70);
		glVertex3f(260,-65,-370);
	glEnd();
	//kiri
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_QUADS);
		glVertex3f(-230,-65,-370);
		glVertex3f(-230,-65,-70);
		glVertex3f(-230,-25,-70);
		glVertex3f(-230,-25,-370);
	glEnd();
	//kanan
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_QUADS);
		glVertex3f(260,-65,-370);
		glVertex3f(260,-65,-70);
		glVertex3f(260,-25,-70);
		glVertex3f(260,-25,-370);
	glEnd();
	//belakang
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_QUADS);
		glVertex3f(260,-65,-370);
		glVertex3f(-230,-65,-370);
		glVertex3f(-230,-25,-370);
		glVertex3f(260,-25,-370);
	glEnd();
	//depan
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_QUADS);
		glVertex3f(230,-65,-70);
		glVertex3f(-230,-65,-70);
		glVertex3f(-230,-25,-70);
		glVertex3f(230,-25,-70);
	glEnd();

    glPopMatrix();
    glutSwapBuffers();
}
void mobil() {
    //perintah animasi
    glPushMatrix();
    glTranslatef(gerak, 5, 0);
    //tengah
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(23.5, -25.0, 85.0);
    glVertex3f(23.5, -15.5, 85.0);
    glVertex3f(70.0, -15.5, 85.0);
    glVertex3f(70.0, -25.0, 85.0);
    glEnd();
    //tengah atas
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(28.5, -15.5, 85.0);
    glVertex3f(31.5, 0.5, 85.0);
    glVertex3f(67.0, 0.5, 85.0);
    glVertex3f(70.0, -15.5, 85.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(70.0, -25.0, 85.0);
    glVertex3f(70.0, -15.5, 85.0);
    glVertex3f(81.0, -15.5, 85.0);
    glVertex3f(81.0, -25.0, 85.0);
    glEnd();

    //tengah
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(23.5, -25.0, 65.0);
    glVertex3f(23.5, -15.5, 65.0);
    glVertex3f(70.0, -15.5, 65.0);
    glVertex3f(70.0, -25.0, 65.0);
    glEnd();
    //tengah atas
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(28.5, -15.5, 65.0);
    glVertex3f(31.5, 0.5, 65.0);
    glVertex3f(67.0, 0.5, 65.0);
    glVertex3f(70.0, -15.5, 65.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(70.0, -25.0, 65.0);
    glVertex3f(70.0, -15.5, 65.0);
    glVertex3f(81.0, -15.5, 65.0);
    glVertex3f(81.0, -25.0, 65.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(31, 0.5, 65.0);
    glVertex3f(67, 0.5, 65.0); //belakang
    glVertex3f(67, 0.5, 85.0); //depan kanan
    glVertex3f(31, 0.5, 85.0); //depan kiri
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);;
    glVertex3f(67.0, 0.0, 85.0);
    glVertex3f(70.0, -15.0, 85.0);
    glVertex3f(70.0, -15.0, 65.0);
    glVertex3f(67.0, 0.0, 65.0);
    glEnd();
    //kaca-depan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(67.1, 0.0, 83.0);
    glVertex3f(70.1, -15.0, 83.0);
    glVertex3f(70.1, -15.0, 68.0);
    glVertex3f(67.1, 0.0, 68.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(31.0, 0.0, 85.0);
    glVertex3f(28.0, -15.0, 85.0);
    glVertex3f(28.0, -15.0, 65.0);
    glVertex3f(31.0, 0.0, 65.0);
    glEnd();
    //tutup cap depan
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(67, -15.5, 85.0);
    glVertex3f(80, -15.5, 85.0); //belakang
    glVertex3f(80, -15.5, 65.0); //depan kanan
    glVertex3f(67, -15.5, 65.0); //depan kiri
    glEnd();
    //tutup cap belakang
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(23, -15.5, 85.0);
    glVertex3f(28, -15.5, 85.0); //belakang
    glVertex3f(28, -15.5, 65.0); //depan kanan
    glVertex3f(23, -15.5, 65.0); //depan kiri
    glEnd();
    //tempat lampu
    //depan
    glBegin(GL_QUADS);
    glColor3f(1, 0.43, 0.78);
    glVertex3f(81.0, -15.0, 85.0);
    glVertex3f(81.0, -25.0, 85.0);
    glVertex3f(81.0, -25.0, 65.0);
    glVertex3f(81.0, -15.0, 65.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
	glColor3f(1, 0.43, 0.78);
    glVertex3f(23.0, -15.0, 85.0);
    glVertex3f(23.0, -25.0, 85.0);
    glVertex3f(23.0, -25.0, 65.0);
    glVertex3f(23.0, -15.0, 65.0);
    glEnd();
    //jendela 1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(50.5, -15.5, 85.1);
    glVertex3f(50.5, 0.5, 85.1);
    glVertex3f(62.0, 0.5, 85.1);
    glVertex3f(66.0, -15.5, 85.1);
    glEnd();
    //jendela 1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(50.5, -15.5, 65.1);
    glVertex3f(50.5, 0.5, 65.1);
    glVertex3f(62.0, 0.5, 65.1);
    glVertex3f(66.0, -15.5, 65.1);
    glEnd();

    //jendela 1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(32.0, -15.5, 85.1);
    glVertex3f(34.0, 0.5, 85.1);
    glVertex3f(48.5, 0.5, 85.1);
    glVertex3f(48.5, -15.5, 85.1);
    glEnd();
    //jendela 1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(32.0, -15.5, 65.1);
    glVertex3f(34.0, 0.5, 65.1);
    glVertex3f(48.5, 0.5, 65.1);
    glVertex3f(48.5, -15.5, 65.1);
    glEnd();

    //ban depan1
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 3500;
    y_tengah = -2500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 85.1);
    }
    glEnd();
    glFlush();

    //ban depan2
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 6700;
    y_tengah = -2500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 85.1);
    }
    glEnd();
    glFlush();

    //ban belakang1
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 3500;
    y_tengah = -2500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 64.9);
    }
    glEnd();
    glFlush();

    //ban belakang2
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 6700;
    y_tengah = -2500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 64.9);
    }
    glEnd();
    glFlush();
    glPopMatrix();
}

void timer2(int t) {
    angle -= 6.3;
    glutPostRedisplay();

    glutTimerFunc(1000, timer2, 0);
}

void timer(int t)
{	
	if(jalans){
		if (atas) {
	        gerak += 1;
	    }
	    else {
	        gerak -= 1;
	    }
	    if (gerak > 150) {
	        atas = false;
	    }
	    else if (gerak < -280) {
	        atas = true;
	    }
	} else {
		gerak += 0;
	}
	    
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}
void mouseMotion(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case 'x':
    case 'X':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'i':
    case 'I':
        glRotatef(3.0, 1.0, 0.0, 0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-3.0, 1.0, 0.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(3.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-3.0, 0.0, 1.0, 0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(3.0, 0.0, 0.0, 1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-3.0, 0.0, 0.0, 1.0);
        break;
    case 'p':
    case 'P':
        if(jalans){
        	jalans = 0;
		} else {
			jalans = 1;
		}
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("Zhejiang University");
    init();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glDepthFunc(GL_LEQUAL);
//    glShadeModel(GL_SMOOTH);
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glutTimerFunc(1, timer, 0);
    glutTimerFunc(1, timer2, 0);
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void ukuran(int width, int height)
{
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, width / height, 30.0, 2000.0);
    glTranslatef(0.0, -100.0, -500.0);
    glMatrixMode(GL_MODELVIEW);
}
