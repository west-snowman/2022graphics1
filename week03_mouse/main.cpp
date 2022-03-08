#include <GL/glut.h>
float mouseX=0,mouseY=0;///new
void myTeapot(float x,float y)
{
    glPushMatrix();///備份矩陣(備份舊的位置)
        glTranslatef(x,y,0);///右上角
        glColor3f(1,1,0);///顏色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣(還原舊的矩陣)

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot((mouseX-150)/150.0,-(mouseY-150)/150.0);///new
    glutSwapBuffers();
}
void mouse(int button, int state, int x,int y)///new
{
    mouseX=x; mouseY=y;
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///new 滑鼠事件

    glutMainLoop();
}
