#include<iostream>
using namespace std;
/*tips：本题由于条件是u<v时给出w，因此都是一致向大的,dp从小到大遍历即可
否则若有指向小的边的话，要“拓扑排序”,以确保在某点的所有入度情况被涵盖
算法1：Kahn(类似BFS)
逐步将度变为0的点加入结果队列，并将与之相连的点的度均-1
    》若最终原图有未加入结果的点，说明存在环导致点互相依赖
算法2：DFS(相当于算法1的逆求解，出度0的先入栈)
首先设置两个数组,一个是拓扑结果栈,一个是路径记录(dfs标配),从一个点开始,每一次对其邻居点(若已经入栈,则跳过)dfs递归遍历，最后将此点入栈(即栈顶)，最终结果栈的出栈顺序就是排序结果
    》若邻居点在此次遍历路径上之前出现过，说明有环
*/

//*注意1*：本题从u到v可能存在多条边！！！（虽然本题偷懒直接取max就行）
//*注意2*：本题边权有负，因此注意遇到初始值0时应该直接赋值，避免错误！！！
int route[1505][1505];
int route_to[1505][1505];
long long dp[1505];
int dp_to[1505];

long long max(long long, long long);
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        route[u][v] = route_to[u][v]? max(w, route[u][v]) : w;
        route_to[u][v] = 1;
    }
    //开始dp
    dp_to[1] = 1;
    for (int i = 1; i < n;i++){
        if(!dp_to[i])//排除从1到不了的点
            continue;
        for (int j = 1; j <= n;j++){
            if(route_to[i][j]){
                if(dp_to[j]){
                    dp[j] = max(dp[j], dp[i] + route[i][j]);
                }else{
                    dp[j] = dp[i] + route[i][j];
                }
                dp_to[j] = 1;
            }
        }
    }
    if(dp_to[n])
        cout << dp[n];
    else
        cout << -1;
    return 0;
}

long long max(long long a, long long b){
    return a > b ? a : b;
}