#include <GL/glut.h>
void myTeapot(float x,float y)
{
    glPushMatrix();///�ƥ��x�}(�ƥ��ª���m)
        ///���ʷ|�ֿn�A�]���L�|�ק�x�}
        glTranslatef(x,y,0);///�k�W��
        glColor3f(1,1,0);///�C��
        glutSolidTeapot(0.3);///����
    glPopMatrix();///�٭�x�}(�٭��ª��x�})

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot(0.5,0.5);   ///�k�W
    myTeapot(0.5,-0.5);  ///�k�U
    myTeapot(-0.5,-0.5); ///���U
    myTeapot(-0.5,0.5);  ///���W
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 ����");
    glutDisplayFunc(display);
    glutMainLoop();
}
