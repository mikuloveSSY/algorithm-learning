#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
/*
方法一：直接按极坐标系模拟旋转
方法二：入堆出堆，先全部按照d排序
        每一次移动到下一个最近的点(与棒的相差角度最小)
        一次移动内碰到的点，都是同一个序号(即都是同时碰到的)
        伸长后，把新的能碰到的点全加入堆中，且都是按照相差角度排序的
        最终直到堆空，那么出堆的顺序就是碰到顺序，剩下的就是碰不到的
本质都属于模拟，但模拟是从过程出发，堆方法是从数据出发，可以确定复杂度，比较明确
*/
//注意分左右半圆,从而区分同k不同位
const int N=2e5 + 5;
struct point{
	int id, z;
	double k, d;
} lp[N], rp[N];

bool cmp(point a, point b){
	if(a.k==b.k){
		return a.d < b.d;
	}
	return a.k > b.k;
}

int ans[N] = {0}, lp[N], rp[N]; // 记录顺序和有无访问过

int main(){
	int n, ln=1, rn=1;
	long long L;
	cin >> n >> L;
	for (int i = 1; i <= n;i++){
		int x, y, z;
		cin >> x >> y >> z;
		if(x==0){
			if(y>=0){
				rp[rn].id = i;
				rp[rn].z = z;
				rp[rn].k= 1e20;//即让k无限大
				rp[rn].d = sqrt(x * x + y * y);
				rn++;
			}
		}
		
	}

	int num = 0,cnt=0;//cnt一直加,当k不一样时,说明转动了,则要num=cnt,否则num不变
	bool flag = 1;//若一圈内没有碰到点，说明结束了
	while(flag){

	}


	for (int i = 1; i <= n;i++){
		if(ans[i])
			cout << ans[i];
		else
			cout << -1;
		cout << ' ';
	}
	return 0;
}
