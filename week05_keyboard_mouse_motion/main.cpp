#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0 ,scale=1.0;
int oldX=0, oldY=0;
void display()
{
    glClearColor(0.5, 0.5, 0.5, 1);///�I���C�� �� R,G,B,A A:�b�z���\��
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�ƥ��x�}
        glTranslatef((x-150)/150.0, -(y-150)/150.0, z);
        glScalef(scale,scale,scale);///�Y�񳣭� scale��
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
}
void keyboard(unsigned char key, int mouseX, int mouseY)///��L�禡 keyboard
{

}
void mouse(int button, int state, int mouseX, int mouseY)///�W�W�g���D�D mouse
{
    oldX = mouseX;   oldY = mouseY;///�ѨM�������ʪ����D
}
void motion(int mouseX, int mouseY)///�W�g���D�D motion
{
    if( mouseX-oldX > 0 ) scale*=1.01;///���k��� ��j
    if( mouseX-oldX < 0 ) scale*=0.99;///������� �Y�p
    ///x +=(mouseX-oldX);  y +=(mouseY-oldY);
    oldX =mouseX;       oldY =mouseY;
    display();
}
int main(int argc,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///��L�禡 keyboard
    glutMouseFunc(mouse);///�W�W�g���D�D mouse
    glutMotionFunc(motion);///�W�g���D�D motion
    glutMainLoop();
}

