/* 
 * File:   main.cpp
 * Author: jblake
 *
 * Created on October 1, 2015, 5:00 PM
 */

#include <cstdlib>
#include <GL/glut.h>

using namespace std;
GLfloat v[3][2] = {{-0.5, -0.5}, {0.5, -0.5}, {0.0,0.5}};

void divide_triangle(GLfloat*, GLfloat*, GLfloat*, int);

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    divide_triangle(v[0], v[1], v[2], 6);
    glFlush();
}
void triangle(GLfloat *a, GLfloat *b, GLfloat *c){
    glBegin(GL_TRIANGLES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();
    
}
void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m){
    GLfloat center[3][2];
    int j;
    if(m > 0){
        for(j = 0; j < 2; j++){center[0][j] = (a[j] + b[j])/2;}
        for(j = 0; j < 2; j++) {center[1][j] = (a[j] + c[j])/2;}
        for(j = 0; j < 2; j++){center[2][j] = (b[j] + c[j])/2;}
        divide_triangle(a, center[0], center[1], m-1);
        divide_triangle(center[0], b, center[2], m-1);
        divide_triangle(center[1], center[2], c, m-1);  
    }
    else
        (triangle(a,b,c));
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.5, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    }
/*
 * 
 */
int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sierpinski's Triangle");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
  
}

