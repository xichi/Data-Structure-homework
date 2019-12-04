#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct BinTree
{
    ElemType data;
    struct BinTree *lchild, *rchild;
} BinTree, *BiTree;
void PreCreateBt(BiTree *T)
{
    ElemType c;
    scanf("%c", &c);
    if ('#' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BinTree *)malloc(sizeof(BinTree));
        (*T)->data = c;
        PreCreateBt(&(*T)->lchild);
        PreCreateBt(&(*T)->rchild);
    }
}
void PreOrderTransverse(BiTree T)
{
    if (T)
    {
        printf("%c", T->data);
        PreOrderTransverse(T->lchild);
        PreOrderTransverse(T->rchild);
    }
}
void InOrderTransverse(BiTree T)
{
    if (T)
    {
        PreOrderTransverse(T->lchild);
        printf("%c", T->data);
        PreOrderTransverse(T->rchild);
    }
}
void PostOrderTransverse(BiTree T)
{
    if (T)
    {
        PreOrderTransverse(T->lchild);
        PreOrderTransverse(T->rchild);
        printf("%c", T->data);
    }
}
int CountLeaf(BiTree T)
{
    if (T == NULL)
        return 0;
    else
        return CountLeaf(T->lchild) + CountLeaf(T->rchild) + 1;
}
int Leaf(BiTree T)
{
    if (T == NULL)
        return 0;
    if (!(T->lchild) && !(T->rchild))
        return 1;
    else
        return (Leaf(T->lchild) + Leaf(T->rchild));
}
int Depth(BiTree T)
{
    if (T == NULL)
        return 0;
    int left, right, depth;
    left = Depth(T->lchild);
    right = Depth(T->rchild);
    depth = (left > right ? left : right) + 1;
    return depth;
}
void Exchange(BiTree T)
{
    BiTree p;
    if (T != NULL)
    {
        p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
        Exchange(T->lchild);
        Exchange(T->rchild);
    }
}
int main()
{
    BiTree T = NULL;
    printf("先序创建：");
    PreCreateBt(&T);
    printf("先序遍历PreOrderTransverse：");
    PreOrderTransverse(T);
    printf("\n中序遍历InOrderTransverse：");
    InOrderTransverse(T);
    printf("\n后序遍历PostOrderTransverse：");
    PostOrderTransverse(T);
    printf("\n结点个数：%d", CountLeaf(T));
    printf("\n叶子结点个数：%d", Leaf(T));
    printf("\n二叉树的高度：%d", Depth(T));
    printf("\nProcessing:交换左右子树");
    Exchange(T);
    printf("\nProcessed: 交换左右子树");
    printf("\n先序遍历PreOrderTransverse：");
    PreOrderTransverse(T);
    printf("\n中序遍历InOrderTransverse：");
    InOrderTransverse(T);
    printf("\n后序遍历PostOrderTransverse：");
    PostOrderTransverse(T);
    return 0;
}

