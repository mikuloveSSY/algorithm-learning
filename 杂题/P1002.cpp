#include<iostream>
#include<vector>//浅试一波vector
//因为卒的行走逻辑非常简单：向下或向右，因此dp显然更快速
//25大小是防止越界
std::vector<std::vector<long long>> map(25, std::vector<long long>(25, 0));
int move[4]= {1, 2, -1, -2};

int main(){
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    map[x][y] = -1;
    for (int i = 0;i<4;i++){
        for (int j = 0; j < 4;j++){
            int a = x + move[i], b = y + move[j];
            if(i%2!=j%2&&(a>=0)&&(b>=0)){
                map[a][b] = -1;
            }
        }
    }
    //开始dp
    map[0][0] = 1;
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= m;j++){
            if(map[i][j]==-1)continue;
            if(i>0)
                map[i][j] += map[i - 1][j] > 0 ? map[i - 1][j] : 0;
            if(j>0)
                map[i][j] += map[i][j - 1] > 0 ? map[i][j - 1] : 0;
        }
    }
    // for (int i = 0; i <= n;i++){
    //     for (int j = 0; j <= m;j++){
    //         std::cout << map[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << map[n][m] << std::endl;
    return 0;
}