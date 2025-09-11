#include<iostream>
using namespace std;
//method1
/*原理说明：
由gcd的递推可知：a*x_0+b*y_0=gcd(a,b)=gcd(b,a%b)=b*x'+(a%b)*y'=(a-b*[a/b])*y'+b*x'=a*y'+b*(x'-[a/b]*y')
又因为由于gcd(a,b)|a,gcd(a,b)|b,所以gcd(a,b)| ax+by [任意x与y]
所以，a*y'+b*(1-[a/b])*x'必然是a*x_0+b*y_0的倍数
又由于都是整数，所以系数应当对应相等
所以，x_0=y';y_0=x'-[a/b]*y'，由此，根据下一层结合当前的a与b得到当前层的递推关系 得出
特别的，最后一层是gcd(r_[k-1],0)，对应的x,y初始值应当是1，0
*/
int exgcd1(int a, int b, int &x, int &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    int c=exgcd1(b,a%b,x,y);
    int temp=x;
    x=y,y=temp-y*(a/b);//注意！a/b必须带括号，因为这是a/b整除得到的值与y乘。若无括号会导致先乘y再整除b，这样就错了
    return c;
}
//method2
/*原理：
利用a*s_i+b*t_i=r_i 等式，得到s_[i+1]=s_[i-1]-q_i*s_i；t_[i+1]=t_[i-1]-q_i*t_i 两个递推式
证明方法：数归
*/
int exgcd2(int a, int b, int &s0, int &s1, int &t0, int &t1){

    return a;
}

int main(){
    cout << "input a and b:" << endl;
    int a,b,c;
    cin >> a >> b;
    if(a<b){
        int t=a;
        a=b,b=t;
    }
    int x,y;
    c=exgcd1(a,b,x,y);
    cout << "greatest common divisor is " << c << endl;
    cout << "method1:" << c << "=" << x << "*" << a << "+" << y << "*" << b << endl;
    int s0=1,s1=0,t0=1,t1=0;
    
    return 0;
}