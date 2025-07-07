#include<iostream>
#include<map>
using namespace std;
int A[100005],x;
int a_t[100005];//存ai.t.index
int max_index[100005];//存max[1,i](ai.t.index)
map<int, int> t_index;//存(作为t)ai的index
int n,m;
/*主要思路:
ai⊕t=x -> t=ai⊕x,因此看有没有t也在范围内即可
tips:在1~i-1内找t,并且要尽可能记录最大的index,毕竟越大越容易落在区间内
*/
//对ai开一个map/桶排序，以此记录其index,
//然后遍历中,把能取的t的index存到对应i位置上,并存ai.index入桶作为后面的可取t
//最后判断所给区间内有无符合的l<=index<=r即可

/*对于判断区间内有无符合的index:
方案一：线段树/ST表 查找区间内max(ai.t.index)(类似二分法优化查找速度)
方案二(*取巧*)：仔细观察发现,
    由于构造出的‘按序存储ai对应t.index的数组’是在[1,i-1]里取t的index
    所以其ai.t.index<i,那么若符合l<=max(ai.t.index)<=r,取到的max(ai.t.index)的i必定>l
    因此不存在[1,j].max(index)>[j+1,i].max(index)的情况
    所以直接取前缀max，判断r处的max(index)?>l即可
*/

int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    cin >> n >> m >> x;
    for (int i = 1; i <= n;i++){
        cin >> A[i];
        if(t_index.find(A[i]^x)!=t_index.end()){
            a_t[i] = t_index[A[i] ^ x];
        }
        max_index[i] = max(max_index[i - 1], a_t[i]);
        t_index[A[i]] = i;
    }
    int l, r = 0;
    for (int i = 0; i < m;i++){
        cin >> l >> r;
        if(max_index[r]>=l)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
/*算法详解：
先构造一个桶数组和ans数组(存ai对应t的index)
逐个读取,对ans[i](即ai处)赋值对应t的index,再把i存入桶数组的[ai]处作为可取的t的index
*核心原理*：（用map的话同理，只不过map空间小）
    i存t[ai],使前面的数都进入桶,从而存入ans[i]都是前面某个可以作为t的数a的index
    且由于覆盖操作,作为t的数a的index在所有数a中肯定是遍历到当前时最大的
    若t未在前面出现过，那么桶数组中的[t]必然是初始0;
    若t已经出现,那么ans[i]=桶[t],得到的必定是前面某个可作为t的数a的index
这样的操作保证了每个ai只会去和前面的配对(反正本来就无序,只要配对即可)便于遍历判断

ST表:即构造f(i,j)=max(i,i+1,i+2,i+3...i+2^j-1)
比如求[l,r]区间的max_k，那么取t=log2(r-l+1)，max_k=max(f(l,t),f(r-(1<<t),t))
这样无论哪个区间都能拆成两个有重叠的,长度为2的幂次的小区间
(本质就是量化小区间去叠加大区间,量化值为2是因为这样只需两个小区间就能叠加出来)
*/