#include<iostream>
using namespace std;

int main(){
    int n;
    long long sum=0, s = 0;
    cin >> n;
    for (int i = 0; i < n;i++){
        int a;
        cin >> a;
        sum += a, s += a * a;
    }
    cout << (sum * sum - s) / 2 << endl;
    return 0;
}