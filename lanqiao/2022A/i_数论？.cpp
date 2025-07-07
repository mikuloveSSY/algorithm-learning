#include<iostream>
using namespace std;
/*易得：
根据质因数分解，ai=求积{zi^ki}，zi都是质数
    而ai=x1^y1 * x2^y2，不妨对x1与x2也分解
    <=> ai={bi^pi}^y1 * {ci^qi}^y2
    <=>   ={bi^(pi*y1)} * {ci^(qi*y2)}
    所以ki=pi*y1+qi*y2，当y1取2，y2取3时，必定有pi+qi>=1的整数解
(y2取3，既包含了奇数，同时也排除了最小奇数次数为1的情况,因为这时候无解)
*/
//原思路*错误点*：同个质数可以同时出现在两边！所以若假设只出现在一边再去找公因数是错的！
//同时也发现当引入pi与qi两个变量时，对ki的分解方便很多

int main(){
    int T;
    cin >> T;
    long long a; 
    for (int i = 0; i < T;i++){
        cin >> a;
        bool flag = 1;
        for (int j = 2; j <= a;j++){
            int cnt = 0;
            while(!(a%j)){
                cnt++;
                a /= j;
            }
            if(cnt==1){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}