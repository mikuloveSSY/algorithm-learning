#include<iostream>
using namespace std;

int main(){
    char T[100],x[100];
    cin >> T >> x;
    //计算长度
    int L, l = 0;
    while(T[++L]!='\0');
    while(x[++l]!='\0');
    cout << "总字符串长：" << L << " 目标字符串长" << l << endl;
    int *next = new int[l];
    //求next数组，第二精髓的部分（最精妙的部分）
    //可以用数归推导（或者说*dp*,毕竟过程非常相似）来理解；若太难理解，可以枚举例子康康
    int j = 0, k = -1;
    next[0] = -1;
    while(j< l-1){
        //注意：要理解这里的k一直代表0~k的子串，最关键的就是这个k=next[k]的转移，从而能快速确定j前面相同的子串
        if(k==-1||x[j]==x[k]){//(最最开始k=-1直接记录了)最开始时的初状态是x[1]与x[0]比较，这里其实就已经开始了：1到j的子串与开头0~k的子串比较
            next[++j] = ++k;  //注意：这里判断的是[j]，但记录的是[j+1]的next！
                              //因为[j]与[k]相同，那么对于[j+1]来说可以回退上一个的位置就是k+1！
        }else{                //    若相等，那么*j+1*前面就有和‘0到k的子串’相同的部分，所以回退到的上一个子串是++k的位置
            k = next[k];      //    若不等，那么k就利用前面已经记录的next回退到上一个子串来和j检验，都失败了，那*j+1*前面不可能有与开头重合的子串，于是就会k=-1
        }                     //(由于这里next是逐步向前推的，因此记录的肯定是最大的那一个子串)
    }
    //开始寻找目标字符串，第一精髓的部分
    int i = 0;
    j = 0;
    while(i<L){
        //若j=-1，说明这个i无论哪个子串部分都对不上，所以从i+1开始，并且j归0
        if(j!=-1){
            if(T[i]==x[j]){
                i++, j++;
            }else{
                //若没匹配上，则换用下一个子串部分尝试
                j = next[j];
            }
        }else{
            i++;
            j = 0;
        }
        if(j==l)
            break;
    }
    cout << "查询结果：" << endl;
    if(j==l){
        cout << "   start:" << i - l << endl;
        cout << "   end:" << i - 1 << endl;
    }else{
        cout << "   failed" << endl;
    }

    cout << "next数组：" << endl;
    for (int i = 0; i < l;i++){
        cout << next[i] << " ";
    }
    delete next;
    return 0;
}