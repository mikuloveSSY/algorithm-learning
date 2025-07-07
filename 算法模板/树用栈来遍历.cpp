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
ǰ��ABDGIEHCFJ
����GDIBEHAFJC
����GIDHEBJFCA
*/

int main(){
    Tree letters[10];
    InitTree(letters);
    printf("ǰ��\n  ");
    qianxu(&letters[0]);
    printf("\n����\n  ");
    zhongxu(&letters[0]);
    printf("\n����\n");
    houxu(&letters[0]);
    return 0;
}

//ע����ջwhileҪ�ж�k����ֹջ�պ󻹼�������
void houxu(TreeLink start){
    TreeLink stack[15], pre=NULL, now;
    int k = 0;
    //���򷽰�һ(һ�����һ������չ�����Һ��ӣ���������)
    //Ψһ��Ƿȱ�Ƕ�������������ж����˵㣬��Ϊ����ڣ�������������������չ��ֱ�ӵ�����������������һ���Ѿ�������
    //�������Һ���ΪNULL������£����δ�ر����ֻ꣬�е�preҲ��������ʱ������������
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
    //���򷽰���(Ĭ�ϰ�����ȫ������ȥ����ջ���ص�ʱ��������preȥ�ж��Ƿ�ֱ�����������ջ�Һ���)
    //�����������ͬ��ֻ�Ƕ���pre�������ж�
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
