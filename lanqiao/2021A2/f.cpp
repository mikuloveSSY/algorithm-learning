#include<iostream>
int main(){
    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 1; i < n;i++){
        if((i*i)%n*2<n)
            sum++;
    }
    std::cout << sum;
    return 0;
}