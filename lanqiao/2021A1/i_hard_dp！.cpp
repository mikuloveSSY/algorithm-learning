#include<iostream>
#include<cstring>
//由*栈*的推算易知，对于一个非法序列，必能分成左侧多余右括号，右侧多余左括号
//又因为对称，因此先解决半边，另一边镜像一下就可
/*不妨先考虑添加左括号的情况
*关键*：何为本质不同？ 即括号的排列顺序
再添加的过程里，右括号是固定不变的
因此以右括号为基准，分隔出一个一个片段，这些片段里面有或没有左括号，同个片段添加不影响排列顺序
*/
//*本算法采用的是标答的dp思想*,以不变的右括号作为为i建立dp;
//*还有一种想法(不好理解)*是将需要添加的左括号括号作为i,而j代表第i个需要添加的左括号考虑在第j个右括号处的决策(包括添和不添)
using namespace std;
const int N = 1e9 + 7;
string kuohao;
/*采用dp是因为排列方式过大,不得不用dp简化运算
dp[i][j]的i表示第i个右(左)括号,j表示*前面到i为止(包括i)*一共添加了几个左(右)括号
(*addmin[i]=<j<=max_add*)
*/
long long dp[5010][5010];
long long add_L=0, add_R=0;

int main(){
    cin >> kuohao;
    //处理多余右括号
    int r, l = 0;
    int addmin[5010]={0},k=1;
    /*为啥直接遍历整个串？
    因为哪怕到了右半边,由于左括号偏多,
    至少添加的左括号数在分界线处已经达最大值,后面无影响
    直接遍历也省去了计算分界线的算力
    */
    for (int i = 0; i < kuohao.length();i++){
        if(kuohao[i]=='('){
            l++;
        }else{//记录第k个右括号前至少要添加x个左括号,这样遍历时从左往右便于计算
            if(l)//说明有待消去的左括号,那么需要添加的数量不变
                addmin[k++] = r, l--;
            else
                addmin[k++] = ++r;
        }
    }
    //此时r也恰好是总的至少需要加的左括号
    dp[0][0] = 1;//初始值置1,这样对于第一个括号来说,添加addmin到r都是方案,且这些方案都是一种
    for (int i = 1; i < k;i++){
        for (int j = addmin[i - 1] + 1; j <= r; j++){
            dp[i - 1][j] += dp[i - 1][j - 1];
        }
        for (int j = addmin[i]; j <= r;j++){
            /*这么算时间复杂度O(n^3),太大,*优化*：每次计算i时,先把i-1的都做前缀和就不用每次j都求和了
            for (int t = addmin[i-1]; t <= j;t++){
                dp[i][j] += dp[i - 1][t]%N;
            }
            */
            dp[i][j] = dp[i - 1][j];
            dp[i][j] %= N;
        }
    }
    add_L = dp[k - 1][r];


    //处理多余左括号,相当于只用把上述扫描过程倒过来即可,dp处理不变(毕竟原理不变,只是对象变了)
    r = 0, l = 0, k = 1;
    for (int i = kuohao.length()-1; i >=0;i--){
        if(kuohao[i]==')'){
            r++;
        }else{
            if(r)
                addmin[k++] = l, r--;
            else
                addmin[k++] = ++l;
        }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < k;i++){
        for (int j = addmin[i - 1] + 1; j <= l; j++){
            dp[i - 1][j] += dp[i - 1][j - 1];
        }
        for (int j = addmin[i]; j <= l;j++){
            /*
            dp[i][j] = 0;//因为前面用过了，第二次用要归零
            for (int t = addmin[i-1]; t <= j;t++){
                dp[i][j] += dp[i - 1][t]%N;
            }
            */
            dp[i][j] = dp[i - 1][j];
            dp[i][j] %= N;
        }
    }
    add_R = dp[k - 1][l];

    //*注意*上面没考虑不用添加的情况,但不用添加时方案数也是1,不影响最终结果
    cout << add_L*add_R%N;
    return 0;
}