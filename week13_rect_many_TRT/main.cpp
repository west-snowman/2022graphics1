///week13_rect_many_TRT
#include <GL/glut.h>
float angle[20], oldX=0;
int angleID=0; ///0�����`�A1�����`...
void keyboard(unsigned char key, int x, int y)///��L���Ʀr
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}

void mouse(int button, int state, int x, int y)///�ƹ����U�h
{
    oldX = x;
}

void motion(int x, int y)///�ƹ��즲
{
    angle[angleID] += (x-oldX);
    oldX = x;
    glutPostRedisplay(); ///��GLUT���e�e��
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ�
    glRectf( 0.3, 0.5, -0.3, -0.5);///����

    glPushMatrix();///�k�b��
        glTranslatef( 0.3,  0.4, 0);      ///(3)����u���^����
        glRotatef(angle[0],0,0,1);   ///(2)��z�b������
        glTranslatef( -0.3, -0.4,0);   ///(1)��⪺���त�ߡA��줤��
        glColor3f(1,0,0);///����
        glRectf( 0.3, 0.5, 0.7, 0.3);///�k�W���u

        glPushMatrix();
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);///���
        glRectf( 0.7, 0.5, 1.0, 0.3);///�k�W���u

        glPopMatrix();

    glPopMatrix();

    glPushMatrix();///���b��
        glTranslatef(-0.3, 0.4, 0);      ///(3)����u���^����
        glRotatef(angle[2],0,0,1);   ///(2)��z�b������
        glTranslatef(+0.3, -0.4,0);   ///(1)��⪺���त�ߡA��줤��
        glColor3f(1,0,0);///����
        glRectf(-0.3, 0.5,-0.7, 0.3);///���W���u

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(+0.7,-0.4,0);
            glColor3f(0,1,0);///���
        glRectf(-0.7, 0.5,-1.0, 0.3);///���U���u

        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT TRT");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();

}
