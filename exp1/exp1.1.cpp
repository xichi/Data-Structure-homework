/* 实验一：
   题目一：顺序表的初始化、查找、插入、删除、输出、撤销 
   示例输出结果：
   0123456789
   012346789
*/
#include <stdlib.h>
#include <stdio.h>

#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5

typedef int ElemType;
typedef int status;

typedef struct{
    int n;                     //顺序表的长度
    int maxLength;             //顺序表的最大允许长度
    ElemType *element;         //指示顺序表的存储空间的首地址
} SeqList;

status Init(SeqList *L, int mSize){
    L->maxLength = mSize;
    L->n = 0;
    L->element = (ElemType*)malloc(sizeof(ElemType)*mSize);
    if(!L->element)
        return ERROR;
    return OK;
}

status Find(SeqList L, int i, ElemType *x){
    if (i < 0 || i > L.n-1 )  
        return ERROR;
    *x = L.element[i];
    return OK;
}

status Insert(SeqList *L, int i, ElemType x){
    int j;
    if (i < -1 || i > L->maxLength) 
        return ERROR;
    if (L->n == L->maxLength) 
        return ERROR;
    for (j = L->n-1; j > i; j--) {
        L->element[j+1] = L->element[j];
    }
    L->element[i+1] = x;
    L->n = L->n+1;
    return OK;
}

status Delete(SeqList *L, int i){
    int j;
    if (i < 0 || i > L->n-1)  
        return ERROR;
    if (!L->n)  
        return ERROR;
    for (j = i+1; j < L->n; j++) {
        L->element[j - 1] = L->element[j];
    }
    L->n--;
    return OK;
}

status Output(SeqList L){
    int i;
    if (!L.n)  
        return ERROR;
    for (i = 0; i <= L.n-1; i++) {
        printf("%d", L.element[i]);
    }
    printf("\n");
    return OK;
}

void Destroy(SeqList *L){
    (*L).n = 0;
    (*L).maxLength = 0;
    free((*L).element);
}

int main(){
    int i;
    SeqList list;
    Init(&list, 10);
    for (i=0; i<10; i++) {
        Insert(&list, i - 1, i);
    }
    Output(list);
    Delete(&list, 5);
    Output(list);
    Destroy(&list);
    getchar();
    return 0;
}