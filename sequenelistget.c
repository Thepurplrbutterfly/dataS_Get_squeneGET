#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequenelist.h"

/*数据存储顺序表创建函数*/
sl * list_create(int value)
{
    sl * S = (sl *)malloc(sizeof(sl));
    if(S == NULL)
    {
        printf("the memory assigning for S failed->the list creating failed!\n");
        return NULL;
    }
    S->head = S->last = 0;
    S->maxlen = value;
    S->data = (data_t *)malloc(S->maxlen);
    if(S->data == NULL)
    {
        printf("the memory assigning for array S->data failed->the list creating failed!\n");
        return NULL;
    }
    memset(S->data, 0, S->maxlen);
    return S;
}

/*数据入表函数*/
int list_en(sl * S)
{
    int i;
    if(S == NULL)
    {
        printf("the memory assigning for S failed->the list creating failed!\n");
        return -1;
    }
    printf("please enter input number:\n");
    for(i = 0; i < S->maxlen; i++)
    {
        scanf("%d", &(S->data[i]));
    }
    printf("the original order in the array is: ");
    for(i = 0; i < S->maxlen; i++)
    {
        printf("%d ", S->data[i]);
    }
    putchar('\n');
    //对数组中元素进行升序排序
    list_sequencing(S);
    printf("the order after sequencing is: ");
    for(i = 0; i < S->maxlen; i++)
    {
        printf("%d ", S->data[i]);
    }
    putchar('\n');
    return 0;
}

/*升序排序函数*/
void list_sequencing(sl * S)
{
    if(S == NULL)
    {
        printf("the memory assigning for S failed->the list creating failed!\n");
        return ;
    }
    int i,j,midn;
    for(i = 0; i < S->maxlen-1; i++)
    {
        for(j = 0; j < S->maxlen-1-i; j++)
        {
            if(S->data[j]>S->data[j+1])
            {
                midn = S->data[j+1];
                S->data[j+1] = S->data[j];
                S->data[j] = midn;
            }
        }
    }
}

/*顺序查找函数*/
int list_sequencingGET(sl * S, data_t value)
{
    if(S == NULL)
    {
        printf("the memory assigning for S failed->the list creating failed!\n");
        return -1;
    }
    int i = 0;
    int flag = 0;
    while(i < S->maxlen)
    {
        if(value == S->data[i])
        {
            printf("the value is in %d-th position in the list\n", i+1);
            flag = 1;
            break;
        }
        else{
            flag = 0;
        }
        i++;
    }
    if(flag == 0)
    {
        printf("the value is not matched by the list!\n");
    }
    return 0;
}
