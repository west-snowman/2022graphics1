#include <opencv/highgui.h> ///使用 opencv的外掛
int main()
{
    IplImage * img = cvLoadImage("smile.png"); ///讀圖
    cvShowImage("week09", img); ///秀圖
    cvWaitKey(0);///等待任意鍵繼續
}
