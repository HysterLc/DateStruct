#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Arr
{
    int* pSite;
    int len;
    int cnt;

};

void Init_arr(struct Arr* pArr, int len);
void show_arr(struct Arr* pArr);
bool is_empty(struct Arr* pArr);


int main()
{
    struct Arr arr;
    Init_arr(&arr, 6);
    is_empty(&arr);
    show_arr(&arr);
    getchar();
    return 0;
}


void Init_arr(struct Arr* pArr, int len)
{
    pArr->pSite = (int*)malloc(sizeof(int) * len);
    if (pArr->pSite == NULL)
    {
        printf("分配内存失败");
        exit(-1);

    }
    else
    {
        printf("分配内存成功\n");
        pArr->len = len;
    }
    return;
}

bool is_empty(struct Arr* pArr)
{
    if (pArr->cnt != 0)
    {
        return true;

    }
    else
    {
        return false;
    }
} 
void show_arr(struct Arr* pArr)
{
    if ( is_empty(pArr))
    {
        printf("数组为空");
     }
    else
    {
        printf("结果如下\n");
        for (int i = 0; i < pArr->len; i++)
        {
            printf("%d", pArr->pSite[i]);  //第一个数字的首地址（数组）啊啊啊
        }

    }
	return;
}