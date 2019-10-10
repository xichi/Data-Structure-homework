#include <stdlib.h>
#include <stdio.h>

typedef struct PNode{
    int coef;             //系数
    int exp;              //指数
    struct PNode* link;   
}PNode;
 
typedef struct{
    struct PNode *head;
}polynominal;

//多项式的创建
void Create(polynominal *p){
    PNode *pn,*pre,*q;
    p->head = (PNode*)malloc(sizeof(PNode));
    p->head->exp = -1;
    p->head->link = p->head;               //对教材做了修改
    //p->head->link = NULL;                //教材原代码
    for(;;){
        pn=(PNode*)malloc(sizeof(PNode));
        printf("coef:\n");
        scanf("%d",&pn->coef);
        printf("exp:\n");
        scanf("%d",&pn->exp);
        if(pn->exp<0) break;
        pre = p->head;
        q = p->head->link;
        while(q && q->exp > pn->exp){
            pre = q;
            q = q->link;
        }
        pn->link = q;
        pre->link = pn;
    }
}

//多项式输出
void Output(polynominal p){
    PNode *q;
    int flag = 1;                                   //打标记,记录是否为第一项
    q = p.head->link;
    if (!q){
        return;
    }
    while(q != p.head){
        if (!flag && (q->coef > 0)) printf("+");	//在非第一项的正系数前输出+号
        flag = 0;                                   //flag置为0,表示不是第一项
        if(q->coef == 0){                           //当前项系数为0
            return;
        }
        printf("%d",q->coef);                       //当前项系数不为0
        switch(q->exp){                             //判断当前项指数
            case 0:break;                           //当前项指数为0,退出
            case 1:printf("X");break;               //当前项指数为1,输出X
            default:printf("X^%d",q->exp);break;    //当前项指数不为0,也不为1
        }
        q = q->link;
    }
}

//多项式的相加,结果存入qx中
void Add(polynominal *px,polynominal *qx){
    PNode *q,*q1 = qx->head,*p, *p1,*temp;    //q1指向qx的表头结点
    p = px->head->link;                       //p指向多项式px的第一个结点
    p1 = px->head;
    q = q1->link;                             //q1是q的前驱
    while(p->exp >= 0){
        while(p->exp < q->exp){               //跳过q->exp大的项
            q1 = q;
            q = q->link;
        }
        if(p->exp == q->exp){                 //当指数相等时,系数相加
            q->coef = q->coef + p->coef;
            if(q->coef == 0){                 //若相加后系数为0
                q1->link = q->link;           //删除q
                free(q);                      //释放q的空间
                q = q1->link;                 //重置q指针
                p = p->link;
            } 
            else{                             //若相加后系数不为0
                q1 = q;                       //q1后移
                q = q->link;
                p = p->link;                  //p也后移
            }
        }
        else{                                 //p->exp > q->exp的情况
            temp = (PNode*)malloc(sizeof(PNode));     //以p的系数和指数生成新结点
            temp->coef = p->coef;
            temp->exp = p->exp;
            temp->link = q1->link;
            q1->link = temp;
            q1 = q1->link;
            p = p->link;
        }
   }
}

//多项式乘法,暂时没有问题
void Multiply(polynominal *px,polynominal *qx){
    polynominal qx1,qx2;
    PNode *q1,*q2,*q3,*q4,*pre;
    qx1.head = (PNode*)malloc(sizeof(PNode));       //生成新多项式qx1
    qx1.head->exp = -1;
    qx1.head->link = qx1.head;                      //qx1改造成循环链表
    q1 = px->head->link;                            //q1指向px的第一项
    q2 = qx->head->link;                            //q2指向qx的第一项
    while(q2->exp != -1){                           //当q2的指数不为-1时,px先和qx的每一项相乘
        q3 = (PNode*)malloc(sizeof(PNode));         //q3存放相乘的结果
        q3->coef = q1->coef * q2->coef;
        q3->exp = q1->exp + q2->exp;
        if(qx1.head->link->exp == -1){              //q3插入到qx1多项式第一项中
            q3->link = qx1.head->link;
            qx1.head->link = q3;
            pre = qx1.head->link;
        }
        else{                                       //q3插入到qx1多项式最后一项中
            q3->link = qx1.head;
            pre->link = q3;
            pre = pre->link;
        }
        q2 = q2->link;
    }
    q1 = q1->link;                                 //q1后移一位
    while(q1->exp != -1){                          //px剩下来每一项都和qx每一项相乘
        q2 = q2->link;
        qx2.head = (PNode*)malloc(sizeof(PNode));  //生成新多项式qx2
        qx2.head->exp = -1;
        qx2.head->link = qx2.head;
        while(q2->exp != -1){   	
            q4 = (PNode*)malloc(sizeof(PNode));
            q4->coef = q1->coef * q2->coef;
            q4->exp = q1->exp + q2->exp;
            if(qx2.head->link->exp == -1){
                q4->link = qx2.head->link;
                qx2.head->link = q4;
                pre = qx2.head->link;
            }
            else{
                q4->link = qx2.head;
                pre->link = q4;
                pre = pre->link;
            }
            q2 = q2->link;
        }
        Add(&qx2,&qx1);                            //合并同类项
        q1 = q1->link;
    }
    Output(qx1);
}


int main(){
    polynominal p,q;
    printf("Please enter the first poly:\n");
    Create(&p);
    Output(p);
    printf("\n\nPlease enter the second poly:\n");
    Create(&q);
    Output(q);
    printf("\nAdd:\n");
    Add(&p,&q);
    Output(q);
    printf("\nMultiply:\n");
    Multiply(&p,&q);
    return 0;
}