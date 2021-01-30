//
// Created by duwei on 2021/1/30.
//

#include "bar.h"

void bar(void)
{
    char bar[N];
    memset(bar,'\0',sizeof(bar));

    const char label[5]="|/-\\";
    int i = 0;
    while(i < 100)
    {
        fflush(stdout);
        bar[i++] = '#';
        printf("[%-100s][%3d%%][%c]\r",bar,i,label[i%4]);
        usleep(10000);
    }
    printf("\n");
}