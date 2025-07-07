#include<iostream>
#include<stdlib.h>
//背包问题，但记录的是可以称的重量
/*
方案一：dp二维数组（注意减的时候要加||来把负的差转正）
(滚动数组优化,但不太好理解)方案二：转化为01背包问题，要么先都加再都减遍历两次；要么直接构造有正负的2N个砝码
（进一步优化：使用bitset，位运算，反正最后结果记录的是把可以的质量置1）
*/
//此处选择方案二的1
int W[100005]={0};
int main(){
    int n,sum=0;
    std::cin >> n;
    int* w=new int[n];
    for (int i = 0; i < n;i++){
        std::cin >> w[i];
        sum += w[i];
    }
    W[0] = 1;
    //正的
    for (int i = 0; i < n;i++){
        for (int j = sum; j >= W[i]; j--){
            W[j] |= W[j - w[i]];
        }
    }
    //负的,相当于正的倒过来,即“第i个‘放变不放,不放变放另一侧’”，不过实际上第二次运算改变的只有“不放变另一侧”
    //*注意*，“另一侧>此侧”的情况，互换一下，就相当于已经包含在此侧>另一侧的情况，所以不用管
    for (int i = 0; i < n;i++){
        for (int j = 0; j <= sum-w[i]; j++){
            W[j] |= W[j + w[i]];
        }
    }
    int count = 0;
    for (int i = 1; i <= sum;i++){
        count += W[i];
    }
    std::cout << count;
    delete w;
    return 0;
}