#include<iostream>
int main(){
    //这里排列组合可以直接数学算，但用动态规划,i表示分解成几个数,j表示这几个数的和
    long long dp[6][2025]={0};
    dp[0][0] = 1;
    for (int i = 1; i < 6;i++){
        for (int j = 1; j < 2022;j++){
            //可以优化成先对dp[i-1]作前缀和
            //类似A1的括号序列,有异曲同工之妙,类似于2021个球分到五个位置上,只不过这里不能为0且没有太多限制
            //对于j分解成i个数,相当于1~j-1分解成i-1个数的方案和
            for (int k = i-1; k < j;k++){
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
    std::cout << dp[5][2021]<<std::endl;
    return 0;
}