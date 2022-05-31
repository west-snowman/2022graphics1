///檔案修改自上周
///week14_angles_fprintf_fscanf
#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
GLMmodel * body = NULL; ///分塊的模型
GLMmodel * arm1 = NULL;
///GLMmodel * arm2 = NULL;...
float angle[20], oldX=0;
int angleID=0; ///0號關節，1號關節...
FILE * fout = NULL, * fin = NULL;   ///f out、f in
void myWrite(){ ///每呼叫一次myWrite()
    if( fout == NULL ) fout= fopen("file.txt","w+");

    for(int i=0; i<20; i++){
        printf("%.1f ",angle[i]);///小黑印出來
        fprintf(fout, "%.1f ", angle[i]);///檔案印出來
    }
    printf("\n");///每呼叫一次myWrite()，小黑跳行
    fprintf(fout,"\n");///每呼叫一次myWrite()，檔案也跳行
}

void myRead(){
    if( fout != NULL ){ fclose(fout); fout=NULL; }
    if( fin == NULL ) fin = fopen("file.txt","r");
    for(int i=0; i<20; i++){ ///因為下面關節20個，所以要開陣列大小20(第4行)
        fscanf(fin, "%f", &angle[i]);
    }
    glutPostRedisplay();///重畫畫面
}

void keyboard(unsigned char key, int x, int y)///鍵盤按數字
{
    if(key=='s') myWrite();///調好動作，才save存檔
    if(key=='r') myRead(); ///一直按著r才能播放
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}

void mouse(int button, int state, int x, int y)///滑鼠按下去
{
    oldX = x;
}

void motion(int x, int y)///滑鼠拖曳
{
    angle[angleID] += (x-oldX);
    ///myWrite();
    oldX = x;
    glutPostRedisplay(); ///請GLUT重畫畫面
}

GLMmodel * myReadOne(char * filename){
    GLMmodel * one = NULL;
    if(one==NULL){
        body = glmReadOBJ("data/body.obj");
        glmUnitize(body);
        glmFacetNormals(body);
        glmVertexNormals(one,90);
    }
    return one;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    ///glRectf( 0.3, 0.5, -0.3, -0.5);///身體

    if(body==NULL) body = myReadOne("data/body.obj");
    glmDraw(body, GLM_TEXTURE|GLM_SMOOTH);

    glPushMatrix();///右半部
        glTranslatef( 0.3,  0.4, 0);      ///(3)把手臂掛回身體
        glRotatef(angle[0],0,0,1);   ///(2)對z軸做旋轉
        glTranslatef( -0.3, -0.4,0);   ///(1)把手的旋轉中心，放到中心
        glColor3f(1,0,0);///紅色
        ///glRectf( 0.3, 0.5, 0.7, 0.3);///右上手臂(改成下面兩行)
        if(arm1==NULL) arm1 = myReadOne("data/arm1.obj");
        glmDraw(body, GLM_TEXTURE|GLM_SMOOTH);

        glPushMatrix();
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            ///glColor3f(0,1,0);///綠色
            ///glRectf( 0.7, 0.5, 1.0, 0.3);///右上手臂

        glPopMatrix();

    glPopMatrix();

    glPushMatrix();///左半部
        glTranslatef(-0.3, 0.4, 0);      ///(3)把手臂掛回身體
        glRotatef(angle[2],0,0,1);   ///(2)對z軸做旋轉
        glTranslatef(+0.3, -0.4,0);   ///(1)把手的旋轉中心，放到中心
        ///glColor3f(1,0,0);///紅色
        ///glRectf(-0.3, 0.5,-0.7, 0.3);///左上手臂

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(+0.7,-0.4,0);
            ///glColor3f(0,1,0);///綠色
            ///glRectf(-0.7, 0.5,-1.0, 0.3);///左下手臂

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
