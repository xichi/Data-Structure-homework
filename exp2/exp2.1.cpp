/* 
    完成二叉树的先序创建、先序遍历、中序遍历、后序遍历
 */
#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BinaryTreeNode{
    ElemType Data;
    struct BinaryTreeNode *LChild, *RChild;
}BiTree;

//先序遍历
void PreOrderTransverse(BiTree *t){
    if(t==NULL){
        return;
    }
    printf("%c",t->Data);           //打印输出根结点，此处可以定义其他操作
    PreOrderTransverse(t->LChild);  //然后先序遍历左子树
    PreOrderTransverse(t->RChild);  //最后先序遍历右子树
}

//中序遍历
void InOrderTransverse(BiTree *t){
    if(t==NULL){
        return;
    }
    InOrderTransverse(t->LChild);  //中序遍历根结点的左子树
    printf("%c",t->Data);          //打印输出根结点，此处可以定义其他操作
    InOrderTransverse(t->RChild);  //最后中序遍历根结点的右子树
}


//后序遍历
void PostOrderTransverse(BiTree *t){
    if(t==NULL){
        return;
    }
    PostOrderTransverse(t->LChild);  //后序遍历根结点的左子树
    PostOrderTransverse(t->RChild);  //然后后序遍历根结点的右子树
    printf("%c",t->Data);            //最后打印输出根结点，此处可以定义其他操作
}


//先序遍历构建二叉树
BiTree *PreCreateBt(BiTree *t){
    char ch;
    ch = getchar();
    if(ch == '#'){                           //输入为#表示这里建立空二叉树，即遍历算法的空操作
        t = NULL;
    }
    else{
        t = (BiTree *)malloc(sizeof(BiTree));
        t->Data = ch;                        //构造根结点
        t->LChild = PreCreateBt(t->LChild);  //构造左子树
        t->RChild = PreCreateBt(t->RChild);  //构造右子树
    }
    return t;
}

int main(){
    BiTree *t = NULL;
    printf("PreCreateBt:\n");
    t = PreCreateBt(t);                     
    printf("\nPreOrderTransverse:\n");
	PreOrderTransverse(t);
    printf("\nInOrderTransverse:\n");
    InOrderTransverse(t);
    printf("\nPostOrderTransverse:\n");
    PostOrderTransverse(t);
    printf("\n");
    getchar();
    return 0;
}