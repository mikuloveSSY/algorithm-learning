#include<iostream>
//方案一：直接全部因数搞出来，在里面选三个使乘积为n(注意LWH是有顺序的)
/*方案二：质因数分解，在用排列组合去解决>>
(从2直接开始除以自然数就可以了，因为从小到大除质数，合数必已经算在质数里，不可能有合数情况)
(原理类似快速生成质数表)
*/
int main(){
    long long n = 2021041820210418;
    int prime[100]={0}, pcount[100]={0},end=0;
    //注意带上ll结尾标记
    for (long long i = 2; i <= n&&end<100;i++){
        if(n%i==0){
            prime[end] = i;
            while(n%i==0){
                pcount[end]++;
                n /= i;
            }
            end++;
        }
    }
    int sum = 1;
    for (int i = 0; i < end;i++){
        //排列组合：假设加上3个虚的位子，然后插板法
        int c = pcount[i]+3;
        sum *= (c - 1) * (c - 2) / 2;
    }
    std::cout << sum;
    return 0;
}
//2430（质因数为2,3,17,131,2857,5882353）