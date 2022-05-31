#include<windows.h>
#include<stdio.h>
int main()
{
    printf("PlaySound()之前\n");
    ///PlaySound 只能撥wav檔  ///等待、同步
    PlaySound("07072006.wav", NULL, SND_SYNC);
    printf("PlaySound()之後\n");
}
