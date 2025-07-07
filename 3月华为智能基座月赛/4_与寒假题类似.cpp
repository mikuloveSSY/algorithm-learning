#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

void fanyi();
int main(){
    char x;
    while((x=cin.get())!='\n'){
        if(x=='{'){
            fanyi();
        }else{
            cout << x;
        }
    }
    return 0;
}

void fanyi(){
    char x;
    int num=0;
    while((x=cin.get())!='}'){
        if(x>='0'&&x<='9'){
            num = num * 10 + x - '0';
        }
    }
    printf("0x%X", num);
}