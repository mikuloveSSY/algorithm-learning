#include<iostream>
using namespace std;
//本质就是马尔可夫链(随机游走&双边界),so怎么构建关系？
/*此处采用正推法
设：E[i]代表从0到i的期望
E[i]=(E[i-1]+1)*(1-P[i])+(E[i-1]+1+E[i])*P[i];
*关键*：怎么理解第二个括号？为什么自己期望里面又有自己的期望？
        因为有P[i]的概率是掉回到0的，而再次从0->i又要E[i]期望的时间
        所以是(E[i-1]+1+E[i])*P[i]
*/
//由于数据多且大，为了避免运算精度的影响，采取数学上的逆元来转化成整数间的运算保证精度

const int N = 1e5 + 5,mod=998244353;
long long me(long long, int);

int main(){
    int n;
    cin >> n;
    long long xi, yi, E = 0;
    for (int i = 1; i <= n;i++){
        cin >> xi >> yi;
        E = (yi * (1 + E) * me(yi - xi, mod - 2)) % mod;
    }
    cout << E;
    return 0;
}

long long me(long long s, int p){
    long long result = 1;
    while(p>0){
        if(p&1){
            result *= s;
            result %= mod;
        }
        s = (s * s) % mod;//取余不影响乘法
        p >>= 1;
    }
    return result;
}