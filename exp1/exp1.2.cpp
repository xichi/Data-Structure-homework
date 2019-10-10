/* 
    实验一：
    题目二：带表头节点单链表的初始化、查找、插入、删除、输出、撤销 
    示例输出结果：
        the linklist is:
        0 1 2 3 4 5 6 7 8
        the following linklist is:
        0 1 2 3 4 6 7 8
        the found value is:
        4
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
typedef int Status;

typedef struct Node{
    ElemType element;           //结点的数据域
    struct Node *link;          //结点的指针域
}Node;
typedef struct{
    int n;                     //链表的长度
    Node *head;
}HeaderList;

Status Init(HeaderList *h){
    h->head = (Node *)malloc(sizeof(Node));
    if (!h->head) 
        return ERROR;
    h->head->link = NULL;
    h->n = 0;
    return OK;
}

Status Insert(HeaderList *h, int i,ElemType x){
    if (i < -1 || i > h->n-1)
        return ERROR;
    Node *p = h->head;
    for (int j=0; j<=i; j++) {
        p = p->link;
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->element = x;
    q->link = p->link;
    p->link = q;
    h->n++;
    return OK;
}

Status Delete(HeaderList *h, int i){
    int j;
    Node *p, *q;
    if (!h->n)
        return ERROR;
    if (i < 0 || i > h->n-1 )
        return ERROR;
    q = h->head;
    for (j = 0; j < i; j++)
        q = q->link;
    p = q->link;
    q->link = p->link;
    free(p);
    h->n--;
    return OK;
}

Status Find(HeaderList *h, int i, ElemType *x){
    Node *p;
    int j;
    if (i < 0 || i > h->n-1 )
        return ERROR;
    p = h->head;
    for (j = 0; j < i; j++)
        p = p->link;
    *x = p->element;
    return OK;
}

Status Output(HeaderList *h){
    Node *p;
    if (!h->n)
        return ERROR;
    p = h->head;
    p = p->link;
    while (p) {
        printf("%d ", p->element);
        p = p->link;
    }
    return OK;
}

void Destroy(HeaderList *h){
    (*h).n = 0;
    free((*h).head);
}

int main(){
    int i;
    int x;
    HeaderList list;
    Init(&list);
    for (i=0; i<9; i++) {
        Insert(&list, i-1, i);
    }
    printf("the linklist is:\n");
    Output(&list);
    Delete(&list, 5);
    printf("\nthe following linklist is:\n");
    Output(&list);
    Find(&list, 5, &x);
    printf("\nthe found value is:\n");
    printf("%d ", x);
    Destroy(&list);
    getchar();
    return 0;
}
