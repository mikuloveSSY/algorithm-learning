#include<iostream>
#include<map>
#include<queue>
using namespace std;
//其实主要在于“删除最久未使用”这一条件的实现，c用链表；但若用stl怎么实现？
//利用map的红黑树排列或者priority_queue的自动排列，按照时间戳的顺序
/*
不过若用priority_queue时，由于队列只能在头结点操作，想单独修改中间需要遍历
所以对于载入操作时，可以单独开一个数组记录某个数据的最新状况，直接push先不管之前该数据遗留的上一次情况
这样发生替换时，如遇到头结点存的数据不是该数据的最新情况，说明已经作废了，直接跳过即可，最终结果也无影响
*/
//为了方便，这里采取map，因为有find函数且可以靠key直接访问，数据量大的时候比较省事

map<int, int> cache[65536];//key为时间戳，value为映射的内存，这样默认就是key最小的在前面
int cache_lim[65536];
bool m_change[65536]={0};//记录该映射的内存之前有无被写过
pair<int, int> memory[65536];//first为-1时代表无被映射的缓存，second代表上一次的时间戳（这是为了能在cache里迅速找到a，因为cache里key是时间戳）
queue < pair<int, int>> ans;//这个只是为了输出工整所以用了个queue

int main(){
    for (int i = 0; i < 65536;i++){
        memory[i].first = -1, memory[i].second = -1;
    }
    int n, N, q, o, a;
    cin >> n >> N >> q;
    for (int i = 0; i < q;i++){
        cin >> o >> a;
        int pos = (a / n) % N;
        if(memory[a].first==-1){
            if(cache_lim[pos]==n){
                auto t = cache[pos].begin();
                //若该内存对应的缓存前面修改过，则要先对内存写入
                if(m_change[t->second]){
                    ans.push({1, t->second});
                    m_change[t->second] = 0;
                }
                memory[a] = {-1, -1};//该内存不再有缓存映射
                cache[pos].erase(t);
                cache[pos][i] = a;
            }else{
                cache_lim[pos]++;
                cache[pos][i] = a;
            }
            //记录新进入的内存a的映射
            memory[a] = {pos, i};
            ans.push({0, a});
        }else{
            //更新时间戳（cache与memory都要更新）
            auto t=cache[pos].find(memory[a].second);
            cache[pos].erase(t);
            cache[pos][i] = a;
            memory[a].second = i;
        }
        if(o){
            m_change[a] = 1;
        }
    }
    while(!ans.empty()){
        auto t = ans.front();
        cout << t.first << ' ' << t.second << endl;
        ans.pop();
    }
    return 0;
}