#include<iostream>
#include<queue>
//这里为了减小时间复杂度，使用了STL里的优先队列
long long v[200005];
//用pair来存储任务的完成时间和算力（用struct亦可，但要重载‘<’）
typedef std::pair<long long, long long> T;
//要用小根堆，让完成时间小的在上面
std::priority_queue<T, std::vector<T>, std::greater<T>> task[200005];

int main(){
    int n, m = 0;
    long long time = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n;i++){
        std::cin >> v[i];
    }

    for (int i = 0; i < m;i++){
        int b;
        long long a,c,d;
        std::cin >> a >> b >> c >> d;
        //清除已完成的任务
        while(!task[b].empty() && task[b].top().first<=a){
            v[b]+=task[b].top().second;
            task[b].pop();
        }
        //判断能否加入任务
        if(v[b]>=d){
            v[b] -= d;
            std::cout << v[b] << std::endl;
            task[b].push({a + c, d});
        }else{
            std::cout << -1 << std::endl;
        }
    }
    return 0;
}