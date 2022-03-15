#include <GL/glut.h>
float angle=0 ,oldx=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}

void motion(int x, int y)
{
    angle += (x-oldx);
    oldx=x;
    display();///重畫畫面
}

void mouse(int button, int state, int x, int y)
{
    oldx=x;///定錨
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion);///mouse motion 動
    glutMouseFunc(mouse);///mouse按下去、放開來
    glutMainLoop();
}

