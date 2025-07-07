#include<iostream>
using namespace std;
const long long mod = 1e9 + 7;
//由于是全排序，乱序且状态过多，不适用dp之类的
/*思考：怎么获得最长完美序列？
1:既然每一个数都是前一个数的因数，那么它们肯定都是第一个数的因子
2:后一个数都可以看作是前一个数分解出来的;
3:前一个数也相应可以看成是后一个数乘上一个数产生前一个数
4:显然,以最小质因数作为这个乘的数，增长最缓慢(也有可能多个小质因数都符合)
因此,不妨以1为起始,2为乘数
tips:*唯一要注意的一点*(如4所说的),遇到3时可能会有意外
    因为将其中一个2替换成3,未必会>n;
    但如果是替换成>3的数,不可能,因为哪怕乘4都是矛盾的
*/
int me(int);//快速计算log2(n)+1
//一个比较妙的[logn(m)]方法是建立1~n的数组,遍历递推log(i)=log(i/n)+1;
bool flag = 0;
long long step[25][2]={{1,0}};//记录价值

int main(){
    //预处理step
    for (int i = 1; i < 25;i++){
        step[i][0] = step[i - 1][0] * 2;
        step[i][1] = step[i - 1][0] * 3;
    }

    int T,n;
    cin >> T;
    for (int i = 0; i < T;i++){
        cin >> n;
        int cnt = me(n);
        //组合数学计算情况：C<n,k>*A<n-k,n-k>=A<n,k>
        long long state = 1;
        for (int j = n; j > cnt;j--){
            state *= j;
            state %= mod;
        }
        long long ans = 0;
        if(flag){
            //不妨先把价值累加,反正情况个数是一样的,且不会存在重复计算
            ans = 1 + (step[cnt - 1][1] * 2 - 3) % mod;
            for (int j = 1; j < cnt;j++){
                ans += (2 * step[j][0] - 1) + (step[cnt - 1][1] - step[j][1]) * 2;
                ans %= mod;
            }
            ans = (ans * state) % mod;
        }else{
            ans = state * (2 * step[cnt - 1][0] - 1)%mod;
            ans %= mod;
        }
        cout << ans << endl;
    }

    return 0;
}

int me(int n){
    int cnt = 0, n1 = n / 2, n2 = n / 3;
    //先除去2和3,比较剩余因子2的个数是否相同
    for (int i = 1; n2;i++){
        cnt = i;
        n1 >>= 1;
        n2 >>= 1;
    }
    //若n1也是0,说明剩余2相同,可以2替换成3
    if(!n1){
        flag = 1;
    }else{
        flag = 0;
        cnt++;
    }
    return cnt + 1;//这个1代表0次幂‘1’
}