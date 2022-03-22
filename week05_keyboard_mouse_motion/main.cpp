#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0 ,scale=1.0;
int oldX=0, oldY=0;
void display()
{
    glClearColor(0.5, 0.5, 0.5, 1);///背景顏色 灰 R,G,B,A A:半透明功能
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef((x-150)/150.0, -(y-150)/150.0, z);
        glScalef(scale,scale,scale);///縮放都乘 scale倍
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard(unsigned char key, int mouseX, int mouseY)///鍵盤函式 keyboard
{

}
void mouse(int button, int state, int mouseX, int mouseY)///上上週的主題 mouse
{
    oldX = mouseX;   oldY = mouseY;///解決瞬間移動的問題
}
void motion(int mouseX, int mouseY)///上週的主題 motion
{
    if( mouseX-oldX > 0 ) scale*=1.01;///往右邊拉 放大
    if( mouseX-oldX < 0 ) scale*=0.99;///往左邊拉 縮小
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
    glutKeyboardFunc(keyboard);///鍵盤函式 keyboard
    glutMouseFunc(mouse);///上上週的主題 mouse
    glutMotionFunc(motion);///上週的主題 motion
    glutMainLoop();
}

