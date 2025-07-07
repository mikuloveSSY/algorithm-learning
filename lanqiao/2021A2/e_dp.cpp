#include<iostream>
const int N = 20210509;
//一眼dp
long long dp[N+10] = {0};
int main(){
    long long sum = 1;
    dp[1] = 1;
    for (int i = 2; i < N + 1;i++){
        //因为o(n^2)太大,根据约数成对性,要想办法优化成n*根号n
        //注意有平方根时的重复情况
        int j = 1;
        for (j = 1; j*j < i;j++){
            if(!(i%j)){
                dp[i] += dp[j]+dp[i/j];
            }
        }
        if(j*j==i)
            dp[i]+=dp[j];
        sum+=dp[i];
    }

    std::cout << sum;
    return 0;
}