#include<iostream>
/*根据左儿子右兄弟表示法，从最深子树递推可知，
对于某一层的兄弟节点，他们必可以连成右斜的单链，同时每个节点左侧都有一条儿子们节点主链，以此类推下去
因此，最终取max的值肯定是从最深子树开始层层向上比较，每层都取有最大的子树的兄弟节点，再将其放在兄弟链最后一个即可
*/
//由上述推理也可知，最重要的信息是每个节点的子节点个数，而非其数字大小
int son_N[100005],head[100005],dp[100005];
int main(){
    int N;
    std::cin >> N;
    for (int i = 2; i <= N;i++){
        int x;
        std::cin >> x;
        head[i] = x;
        son_N[x]++;
    }
    for (int i = N; i > 1;i--){
        int sum = dp[i] + son_N[head[i]];
        if(sum>dp[head[i]])
            dp[head[i]] = sum;
    }
    std::cout << dp[1];
    return 0;
}