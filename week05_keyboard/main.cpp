#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
        printf("你按下了 %c 在 %d %d 座標\n", key, x, y);///按下鍵盤上的任何鍵 並 印出滑鼠放在小黑上的位置
}
int main(int argc,char** argv)

{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///鍵盤函式
    glutMainLoop();

}

