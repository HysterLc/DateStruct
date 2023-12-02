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
        printf("�����ڴ�ʧ��");
        exit(-1);

    }
    else
    {
        printf("�����ڴ�ɹ�\n");
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
        printf("����Ϊ��");
     }
    else
    {
        printf("�������\n");
        for (int i = 0; i < pArr->len; i++)
        {
            printf("%d", pArr->pSite[i]);  //��һ�����ֵ��׵�ַ�����飩������
        }

    }
	return;
}