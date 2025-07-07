#include<iostream>
int main(){
    long long sum = 1;
    int x = 2021;
    while(x>0){
        sum = sum * x % 100000;
        x -= 2;
    }
    std::cout << sum;
    return 0;
}