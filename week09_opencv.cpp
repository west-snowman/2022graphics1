#include <opencv/highgui.h> ///�ϥ� opencv���~��
int main()
{
    IplImage * img = cvLoadImage("smile.png"); ///Ū��
    cvShowImage("week09", img); ///�q��
    cvWaitKey(0);///���ݥ��N���~��
}
