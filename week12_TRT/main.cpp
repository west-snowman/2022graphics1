#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glutSolidTeapot(0.3);///�զ�(����)
    glPushMatrix();
        glTranslatef(0.2,0,0);         ///(3)���k����(���ө��k�䲾��)
        glRotatef(angle, 0, 0, 1); ///(2)����
        glTranslatef(0.2,0,0);       ///(1)����त�ߡA���@�ɤ���
        glColor3f(1, 0, 0);
        glutSolidTeapot(0.2);///����(����u)
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
