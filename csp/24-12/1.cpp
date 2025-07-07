#include<iostream>
using namespace std;

int main(){
    int n, k, x0, y0;
    string s;
    cin >> n >> k;
    for (int i = 0; i < k;i++){
        cin >> x0 >> y0 >> s;
        for(int j = 0; j < s.length();j++){
            if(s[j]=='r'&&x0<n){
                x0 += 1;
            }else if(s[j]=='f'&&y0<n){
                y0 += 1;
            }else if(s[j]=='b'&&y0>1){
                y0 -= 1;
            }else if(x0>1){
                x0 -= 1;
            }
        }
        cout << x0 << ' ' << y0;
    }
    return 0;
}