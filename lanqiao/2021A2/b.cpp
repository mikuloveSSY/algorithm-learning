#include<iostream>
int main(){
    int sum = 0;
    for (int i = 1; i <= 2021;i++){
        sum += 2021 / i;
    }
    std::cout << sum;
    return 0;
}