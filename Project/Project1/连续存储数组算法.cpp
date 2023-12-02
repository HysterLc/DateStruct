#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Arr
{
    int* pSite;
    int len;
    int max;

};

void Init_arr(struct Arr* pArr, int len);


int main()
{
    struct Arr arr;
    Init_arr(&arr, 6);
    getchar();
    return 0;
}


void Init_arr(struct Arr* pArr, int len)
{
    pArr->pSite = (int*)malloc(sizeof(int) * len);
    if (pArr->pSite == NULL)
    {
        printf("分配内存失败");
        return;

    }
    else
    {
        printf("分配内存成功");
    }
}