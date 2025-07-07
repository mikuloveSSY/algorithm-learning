#include<iostream>
//因为无向图，不妨全看成从小到大,即动态规划
int gcd(int, int);
int main(){
    long long length[2022]={0};
    for (int i = 1; i < 2021;i++){
        for (int j = i + 1; j <= i + 21 && j < 2022;j++){
            long long now = length[i] + i * j / gcd(j, i);
            if(length[j])
                length[j] = length[j]>now?now:length[j];
            else
                length[j] = now;
        }
    }
    std::cout << length[2021];
    return 0;
}
//10266837

int gcd(int a, int b){
    if(!b)
        return a;
    else
        return gcd(b, a % b);
}