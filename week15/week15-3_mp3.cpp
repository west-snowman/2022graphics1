#include<stdio.h>
#include "CMP3_MCI.h"///記得要下載並放在同目錄
CMP3_MCI mp3;///宣告變數

int main()
{
    mp3.Load("07072006.mp3");
    mp3.Play();

    printf("隨便等你輸入數字，程式就卡囉: ");
    int N;///為了卡住程式不要直接結束
    scanf("%d",&N);
}
