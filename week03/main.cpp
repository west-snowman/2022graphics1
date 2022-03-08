#include <GL/glut.h>
void myTeapot(float x,float y)
{
    glPushMatrix();///備份矩陣(備份舊的位置)
        ///移動會累積，因此他會修改矩陣
        glTranslatef(x,y,0);///右上角
        glColor3f(1,1,0);///顏色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣(還原舊的矩陣)

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot(0.5,0.5);   ///右上
    myTeapot(0.5,-0.5);  ///右下
    myTeapot(-0.5,-0.5); ///左下
    myTeapot(-0.5,0.5);  ///左上
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 移動");
    glutDisplayFunc(display);
    glutMainLoop();
}
