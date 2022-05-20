#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include "glm.h"
GLMmodel * pmodel = NULL;///空指標
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB,  GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot(0.3);
    if( pmodel == NULL){///如果是空指標(第5行)，表示模型沒裝好，所以要讀模型(只會跑一次)
        pmodel = glmReadOBJ("data/Gundam.obj"); ///讀模型
        glmUnitize( pmodel ); ///換算成Unit單位大小(-1...+1)
        glmFacetNormals( pmodel ); ///重新計算模型的"面"的法向量
        glmVertexNormals( pmodel , 90 ); ///重新計算模型的"頂點"的法向量
    }

    glPushMatrix();
        glRotatef(angle, 0,1,0);
        glmDraw( pmodel, GLM_TEXTURE );///有模型後，把pmodel畫出來(面、貼圖)
    glPopMatrix();

    glutSwapBuffers();
    angle +=1;
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 gundam");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");    ///這邊要修改!!
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
