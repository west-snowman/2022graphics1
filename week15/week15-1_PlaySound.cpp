#include<windows.h>
#include<stdio.h>
int main()
{
    printf("PlaySound()���e\n");
    ///PlaySound �u�༷wav��  ///���ݡB�P�B
    PlaySound("07072006.wav", NULL, SND_SYNC);
    printf("PlaySound()����\n");
}
