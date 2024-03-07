#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Arr
{
    int* pSite;
    int len;
    int cnt;

};

void Init_arr(struct Arr* pArr, int len);
void show_arr(struct Arr* pArr);
bool is_empty(struct Arr* pArr);
bool append_arr(struct Arr* pArr, int val);
bool is_full(struct Arr* pArr);
bool insert_arr(struct Arr* parr, int pos,int val); //pos从1开始
bool delete_arr(struct Arr* pArr, int pos,int* val);
void inversion_arr(struct Arr* pArr);
void sort_arr(struct Arr* pArr);

int main()
{
    struct Arr arr;
    Init_arr(&arr, 8);
    append_arr(&arr, 1);
    show_arr(&arr);
    append_arr(&arr, 2);
    show_arr(&arr);
    insert_arr(&arr, 1, 7);
    show_arr(&arr);
    insert_arr(&arr, 4, 9);
    show_arr(&arr);
    int* val = (int*)malloc(sizeof(int) * 50);
    delete_arr(&arr,2,val);
    show_arr(&arr);
    inversion_arr(&arr);
    show_arr(&arr);
    sort_arr(&arr);
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
        pArr->cnt = 0;
    }
    return;
}


bool is_empty(struct Arr* pArr)
{
    if (pArr->cnt == 0)
    {
        return true;

    }
    else
    {
        return false;
    }
}

bool is_full(struct Arr* pArr)
{
    if (pArr->cnt == pArr->len)
    {
        return true;         //满了返回错误
    }
    else
    {
        return false;
    }
}


void show_arr(struct Arr* pArr)
{
    if (is_empty(pArr))
    {
        printf("数组为空");
    }
    else
    {
        printf("结果如下\n");
        for (int i = 0; i < pArr->cnt; i++)
        {
            printf("%d\n", pArr->pSite[i]);  //第一个数字的首地址（数组）啊啊啊
        }

    }
    return;
}



bool append_arr(struct Arr* pArr, int val)  //val是要添加的值
{
    if (is_full(pArr))                    //判断是否满了
    {
        printf("数组已满");
        return false;

    }
    else
    {
        if (pArr->cnt > pArr->len)
        {
            printf("数组越界");
            return false;
        }
        printf("在索引第%d处插入%d\n", pArr->cnt+1, val);
        pArr->pSite[pArr->cnt] = val;
        pArr->cnt++;
        printf("插入成功\n");
        return true;

    }
   
}


bool insert_arr(struct Arr* pArr, int pos, int val)
{
    if (is_full(pArr))
    {
        printf("数组已满，插入失败");
        return false;
    }
    else 
    {
        if (pos<0 || pos>pArr->len)
        {
            printf("插入位置错误");
            return false;
        }
       
    }
    
    
    for (int i = pArr->cnt; i >= pos; --i)
    {
        pArr->pSite[i] = pArr->pSite[i-1];
    }
     
    pArr->pSite[pos-1] = val;
    printf("插入位置%d成功\n",pos);
    pArr->cnt++;
    return true;
    
        
}

bool delete_arr(struct Arr *pArr,int pos,int* val)
{
    if (is_empty(pArr))
    {
        printf("数组为空");
        return false;
    }

    else
    {
        *val = pArr->pSite[pos - 1];
        for (int i = pos; i < pArr->cnt;i++) 
        {
            pArr->pSite[i] = pArr->pSite[i + 1];
        }
        pArr->cnt--;
        printf("本次删除的元素是%d", *val);
        return true;
    }
}


void inversion_arr(struct Arr* pArr)
{
    int t;
    int j = 0;
    int k = pArr->cnt - 1;
    while (j < k)
    {
        int t= pArr->pSite[k];
        pArr->pSite[k] = pArr->pSite[j];
        pArr->pSite[j] = t;
        j++;
        k--;
    }
    return ;
}

void sort_arr(struct Arr* pArr)
{
    for (int i = 0; i < pArr->cnt ;i++)
    {
        for (int j = 0; j < pArr->cnt - 1 - i; j++)
        {
            if (pArr->pSite[j] > pArr->pSite[j + 1])
            {
                int t= pArr->pSite[j+1];
                pArr->pSite[j+1] = pArr->pSite[j];
                pArr->pSite[j] = t;
            }
        }
    }
    printf("排序成功");
    return;
}