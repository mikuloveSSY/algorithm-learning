#include<iostream>
using namespace std;
//感觉像是后缀min，全程中遇到的最小负能量就是开始至少要有的
//而某一处没补给b，从这往后所有的w都会减少b

int n, a[100005]={0}, b[100005]={0};
int now_w[100005] = {0}, min_w[100005]={0};//min_w[i]代表i+1以及之后需要的最少w
int min(int, int);
int main(){
    cin >>n;
    for (int i = 0; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        cin >> b[i];
    }
    //补给可以看作是让i到i+1的a[i]变成a[i]-b[i]。另外这里n+1用来代表n到0的！
    for (int i = 1; i <= n+1;i++){
        now_w[i] = now_w[i - 1] - a[i - 1] + b[i - 1];
    }
    for (int i = n; i >= 0;i--){
        min_w[i] = min(now_w[i + 1], min_w[i + 1]);
    }
    // 某处i少b，从这之后的所有now_w都少b:
    //若原来的minnest在前部分，那么新的就是min(min_w[0],min_w[i+1]-b);
    //若原来的minnest在i之后，那么就是min_w[i]-b,用了min(...)也无影响
    for (int i = 1; i <= n;i++){
        int ans = min(min_w[0], min_w[i] - b[i]);
        if(ans>=0){
            cout << 0;
        }else{
            cout << -ans;
        }
        cout << ' ';
    }
}
int min(int x, int y){
    return x < y ? x : y;
}
