#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int bfs[10000];
int change[] = {
    1000, 100, 10, 1,      // 单转轮转动
    1100, 110, 11,         // 双转轮转动
    1110, 111,             // 三转轮转动
    1111                   // 四转轮转动
}; 
//对列：不断在头元素基础上递推后面情况并入队，保证是按层顺序递推，因此肯定是最小的
void precompute() {
    memset(bfs, -1, sizeof(bfs)); // 初始化所有状态为未访问
    queue<int> q;
    q.push(0);
    bfs[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 10; ++i) {
            int bu = change[i];
            // 处理正向转动
            int v_forward = 0;
            int temp_u = u;
            int temp_bu = bu;
            for (int j = 0; j < 4; j++) {
                int digit = (temp_u % 10 + temp_bu % 10) % 10;
                v_forward = digit * 1000 + (v_forward / 10);
                temp_u /= 10;
                temp_bu /= 10;
            }
            if (bfs[v_forward] == -1) {
                bfs[v_forward] = bfs[u] + 1;
                q.push(v_forward);
            }
            // 处理逆向转动
            int v_backward = 0;
            temp_u = u;
            temp_bu = bu;
            for (int j = 0; j < 4; j++) {
                int digit = (temp_u % 10 - temp_bu % 10 + 10) % 10;
                v_backward = digit * 1000 + (v_backward / 10);
                temp_u /= 10;
                temp_bu /= 10;
            }
            if (bfs[v_backward] == -1) {
                bfs[v_backward] = bfs[u] + 1;
                q.push(v_backward);
            }
        }
    }
}

int main() {
    precompute();
    int Q, a, b;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        int ans = 0;
        for (int j = 0; j < 4; j++) {
            int diff = (b % 10 - a % 10 + 10) % 10;
            ans = diff * 1000 + ans / 10; // 构建残差状态
            a /= 10;
            b /= 10;
        }
        cout << ans << ' ' << bfs[ans] << endl;
    }
    return 0;
}