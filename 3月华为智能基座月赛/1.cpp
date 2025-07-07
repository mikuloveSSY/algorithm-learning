#include<iostream>
#include<map>
using namespace std;

int luck[4];
map<unsigned long long, short> ifcan;
map<unsigned long long, short>::iterator x;
/*考虑到数据给的非常大，每一次都纯判断肯定不行
由于取模，且增量一定，那么取模结果必然是一个循环序列（t与M互质时会包含所有余数可能性）
所以记录已经产生的余数能快速归类luck的种类
*/

short check(unsigned long long);
int main(){
    int k;
    unsigned long long t, M, cnt = 1;
    cin >> k >> t >> M;
    t %= M;
    for (int i = 0; i < k;i++){
        x = ifcan.find(cnt);
        if(x!=ifcan.end()){
            luck[x->second]++;
        }else{
            luck[check(cnt)]++;
        }
        cnt = (cnt + t) % M;
    }

    for (int i = 1; i <= 3;i++){
        cout << luck[i] << " ";
    }
    return 0;
}

short check(unsigned long long x){
    short flag = 0;//记录归类
    while(x){
        if(x%10==1){
            flag |= 1;
        }else if(x%10==0){
            flag |= 2;
        }
        if(flag==3)
            break;
        x /= 10;
    }
    ifcan[x] = flag;
    return flag;
}