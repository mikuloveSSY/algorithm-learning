#include<iostream>
//不能用走迷宫的图遍历法，量太大算不出
/*还是用动态规划（背包问题）,
把已经到过的楼的记录(以21位二进制记录)作为一个阶段,
并记录此阶段下最后到达的楼号,不断累加到最后
*/
int gcd(int, int);
long long go[1 << 21][22] = {0};
int main(){
    int route[22][22] = {0};
    for (int i = 1; i < 21;i++){
        for (int j = i + 1; j < 22;j++){
            if(gcd(j,i)==1){
                route[i][j] = 1;
                route[j][i] = 1;
            }
        }
    }
    
    go[1][0] = 1;
    for (int i = 1; i < (1 << 21);i++){
        for (int j = 0; j < 21;j++){
            if(!(i>>j&1))continue;//若j还没到过,说明此状态不可能从j楼继续走下去
            //计算从此状态的j楼继续可以走到的且还没去过的下一个楼
            for (int k = 0; k < 21;k++){
                if(route[j+1][k+1]&&!(i>>k&1)){
                    go[i + (1 << k)][k]+= go[i][j];
                }
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i < 21;i++){
        sum += go[(1 << 21) - 1][i];
    }
    std::cout << sum;
    return 0;
}
//881012367360

int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a % b);
}