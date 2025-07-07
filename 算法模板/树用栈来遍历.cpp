#include<stdio.h>

typedef struct tree{
    char data;
    struct tree* lchild, *rchild;
}Tree,*TreeLink;

void InitTree(TreeLink letters);
void qianxu(TreeLink start);
void zhongxu(TreeLink start);
void houxu(TreeLink start);
/*
             A
        B         C
      D   E      F
    G  I    H     J
前序：ABDGIEHCFJ
中序：GDIBEHAFJC
后序：GIDHEBJFCA
*/

int main(){
    Tree letters[10];
    InitTree(letters);
    printf("前序：\n  ");
    qianxu(&letters[0]);
    printf("\n中序：\n  ");
    zhongxu(&letters[0]);
    printf("\n后序：\n");
    houxu(&letters[0]);
    return 0;
}

//注意退栈while要判断k，防止栈空后还继续访问
void houxu(TreeLink start){
    TreeLink stack[15], pre=NULL, now;
    int k = 0;
    //后序方案一(一个结点一个结点得展开左右孩子，先右再左)
    //唯一的欠缺是对于输出条件的判定多了点，因为相较于（二）中由于是沿左孩子展开直接到底因此退上来后左边一定已经遍历完
    //这里在右孩子为NULL的情况下，左边未必遍历完，只有当pre也等于左孩子时才真正遍历完
    printf("1:");
    stack[k++] = start;
    while(k){
        now = stack[k-1];
        if(now->rchild!=NULL)
            stack[k++] = now->rchild;
        if(now->lchild!=NULL)
            stack[k++] = now->lchild;
        while(k){
            if((stack[k-1]->rchild==NULL&&(stack[k-1]->lchild==NULL||stack[k-1]->lchild==pre))||stack[k-1]->rchild==pre){
                printf("%c", stack[k-1]->data);
                pre = stack[k - 1];
                k--;
            }else
                break;
        }
    }
    printf("\n2:");
    //后序方案二(默认把左孩子全遍历下去，退栈返回的时候再利用pre去判断是否直接输出还是入栈右孩子)
    //与中序遍历相同，只是多了pre的条件判断
    stack[k++] = start;
    pre = NULL;
    while(k){
        while(stack[k-1]->lchild!=NULL){
            now = stack[k - 1];
            stack[k++] = now->lchild;
        }
        while(k){
            if(stack[k-1]->rchild==NULL||pre==stack[k-1]->rchild){
                printf("%c", stack[k - 1]->data);
                pre = stack[k - 1];
                k--;
            }else{
                now = stack[k - 1];
                stack[k++] = now->rchild;
                break;
            }
        }
    }
}
void zhongxu(TreeLink start){
    TreeLink stack[15], now;
    int k = 0;
    stack[k++] = start;
    while(k){
        while(stack[k-1]->lchild!=NULL){
            now = stack[k - 1];
            stack[k++] = now->lchild;
        }
        while(k){
            now = stack[k - 1];
            printf("%c", stack[k - 1]->data);
            k--;
            if(now->rchild!=NULL){
                stack[k++] = now->rchild;
                break;
            }
        }
    }
}
void qianxu(TreeLink start){
    TreeLink stack[15], now;
    int k = 0;
    stack[k++] = start;
    while(k){
        now = stack[k - 1];
        printf("%c", now->data);
        k--;
        if(now->rchild!=NULL)
            stack[k++] = now->rchild;
        if(now->lchild!=NULL)
            stack[k++] = now->lchild;
    }
}


void InitTree(TreeLink letters){
    for (int i = 0; i < 10;i++){
        letters[i].data = i + 'A';
        letters[i].lchild = NULL, letters[i].rchild = NULL;
    }
    char str[] = "ABCDEF#GI#H#J##";
    for (int i = 1; i <= 15/2;i++){
        if(str[i-1]!='#'){
            if(str[2*i-1]!='#')
                letters[str[i - 1] - 'A'].lchild = &letters[str[2 * i - 1] - 'A'];
            if(str[2*i]!='#')
                letters[str[i - 1] - 'A'].rchild = &letters[str[2 * i] - 'A'];
        }
    }
}
