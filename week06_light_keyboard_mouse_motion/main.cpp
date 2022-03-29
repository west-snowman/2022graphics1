#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150, y=150, z=0 ,scale=1.0,angle=0.0; ///angle:旋轉
int oldX=0, oldY=0, now=1; ///now: 1.移動 2.轉動 3.縮放
void display()
{
    glClearColor(0.5, 0.5, 0.5, 1);///背景顏色 灰 R,G,B,A A:半透明功能
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef((x-150)/150.0, -(y-150)/150.0, z);
        glRotatef(angle, 0,1,0); ///對Y軸旋轉
        glScalef(scale,scale,scale);///縮放都乘 scale倍
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard(unsigned char key, int mouseX, int mouseY)///鍵盤函式 keyboard
{
    if(key=='1' || key=='w' || key=='W') now=1; ///移動
    if(key=='2' || key=='e' || key=='E') now=2; ///轉動
    if(key=='3' || key=='r' || key=='R') now=3; ///縮放
}
void mouse(int button, int state, int mouseX, int mouseY)///上上週的主題 mouse
{
    oldX = mouseX;   oldY = mouseY;///解決瞬間移動的問題
}
void motion(int mouseX, int mouseY)///上週的主題 motion
{
    if(now==1){      ///移動
        x +=(mouseX-oldX);  y +=(mouseY-oldY);
    }
    else if(now==2){ ///轉動
        angle += (mouseX-oldX);
    }
    else if(now==3){ ///縮放
        if( mouseX-oldX > 0 ) scale*=1.01;///往右邊拉 放大
        if( mouseX-oldX < 0 ) scale*=0.99;///往左邊拉 縮小
    }
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
    glutMouseFunc(mouse);///滑鼠函式 mouse
    glutMotionFunc(motion);///motion

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();///可以讓程式卡在這裡(在這之後的程式都不會執行到)
}
