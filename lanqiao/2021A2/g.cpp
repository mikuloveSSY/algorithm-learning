#include<iostream>
//质因数分解，只需算奇数次方的即可
int main(){
    long long n,x=1;
    std::cin >> n;

    for (int i = 2; i <= n;i++){
        int cnt = 0;
        if(n%i==0){
            while(n%i==0){
                cnt++;
                n /= i;
            }
        }
        if(cnt%2)
            x *= i;
    }
    std::cout << x;
    return 0;
}