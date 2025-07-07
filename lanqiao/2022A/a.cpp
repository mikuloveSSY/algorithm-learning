#include<iostream>
using namespace std;
//显然，选长边剪是赚的,要尽可能让每一次剪出更多边
//且剪中间比靠边好,因为有利于后面一次性剪更多边
//而且总边数一定，因此选择贪心
int jian(int, int);

int main(){
    int cnt = 0, n = 0, m = 0;
    cin >> n >> m;
    cnt = jian(n, m);
    cout << cnt+4 << endl;
    return 0;
}

int jian(int n, int m){
    static int cnt = 0;
    if(n==1){
        cnt += m - 1;
        return 0;
    }else if(m==1){
        cnt += n - 1;
        return 0;
    }
    cnt++;
    if(n>m){
        jian(n, m / 2);
        jian(n, m - m / 2);
    }else{
        jian(n / 2, m);
        jian(n - n / 2, m);
    }
    return cnt;
}