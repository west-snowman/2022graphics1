#include<windows.h>
#include<stdio.h>
int main()
{   ///ASYNC不等待同步(就會比較快執行到下一行，互動性佳)
    PlaySound("07072006.wav", NULL, SND_SYNC);
    while(1){
    printf("請輸入數字: ");
    int N;
    scanf("%d",&N);
        if(N==1) PlaySound("do.wav", NULL, SND_ASYNC);
        if(N==2) PlaySound("re.wav", NULL, SND_ASYNC);
        if(N==3) PlaySound("mi.wav", NULL, SND_ASYNC);
    }
}
