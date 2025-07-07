#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
typedef long long LL;
/*
大致思路就是：
    先判断是哪一类，分成原子表达式和逻辑组合表达式分开处理
    过程中巧用find函数去找到操作符或者()来快速切分string
    （这里用无序map可以加速查找，毕竟这里属性的先后顺序无关）
    题解里还用了许多库函数来加快解决：
        string::stoi()  字符串转数字，即string to int
        str.substr()    取子字符串
        algorithm::set_union/set_intersection()  求交并集
*/

struct usr{
    int num;
    unordered_map<LL, LL> attrs;
}users[2555];
int n,m;
vector<int> alls;
string input_str;

vector<int> a_set_manage(string &str);//逻辑组合
vector<int> a_atomic_term(string &str);//原子表达式
vector<int> analyze(string &str);//判断是上述哪一类

vector<int> a_set_manage(string &str){
    int flag = 0, left_q = 0;
    vector<int> p, res;

    for(int i = 1; i < str.size(); i++){
        if(str[i] == '('){
            left_q ++;
            if(left_q == 1) p.push_back(i+1);
        }
        if(str[i] == ')'){
            left_q --;
            if(left_q == 0) p.push_back(i-1);
        }
    }
    auto suba = str.substr(p[0], p[1] - p[0] + 1);
    auto subb = str.substr(p[2], p[3] - p[2] + 1);

    auto a = analyze(suba);
    auto b = analyze(subb);
    /*在algorithm里(算法库)：
        set_union是求并集，若两个序列有重复元素，保留其在两序列中最大出现次数
            {1,2,2,3}U{2,3,4} = {1,2,2,3,4}
        set_intersection是求交集，若有重复元素，保留其在两序列中最小出现次数
            {1,2,2,3}交{2,3,4} = {2,3}
        注意必须是对有序集的操作！否则会导致未定义行为!
    inserter是插入迭代器，不用的话会直接覆盖res的内容，这里res代表被插入的vector，res.begin()代表插入位置
        其衍生还有back_inserter，也就是末尾插入迭代器
    */
    if(str[0] == '|') set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(res, res.begin()));
    else set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(res, res.begin()));
    return res;
}


vector<int> a_atomic_term(string &str){
    bool flag = false;
    int pos;
    if((pos = str.find(":")) != -1) flag = true;
    else pos = str.find("~");
    //stoi函数在string里，用于字符串转成数字
    int tmpa = stoi(str.substr(0 , pos));
    int tmpb = stoi(str.substr(pos + 1 , str.size() - pos - 1));
    vector<int> res;

    for(int i = 0; i < n; i ++){
        if(users[i].attrs.count(tmpa)){
            if(flag && users[i].attrs[tmpa] == tmpb ||
            !flag && users[i].attrs[tmpa] != tmpb) res.push_back(i);
        }
    }

    return res;
}

vector<int> analyze(string &str){
    if(str[0] == '|' || str[0] == '&') return a_set_manage(str);
    return a_atomic_term(str);
}

int main(){
    cin>>n;
    int tmpa, tmpb;
    for(int i = 0; i < n; i ++){
        cin>>users[i].num>>m;
        for(int j = 0; j < m; j ++){
            cin>>tmpa>>tmpb;
            users[i].attrs[tmpa] = tmpb;
        }
        alls.push_back(i);
    } 

    cin>>m;
    for(int i = 0; i < m; i ++){
        cin>>input_str;
        auto results = analyze(input_str);
        vector<int> data;
        for(auto x:results) data.push_back(users[x].num);
        sort(data.begin(), data.end());
        for(auto x: data) cout<<x<<" ";
        puts("");
    }

    return 0;
}

//作者：arr2
//链接：https://www.acwing.com/solution/content/189741/
//来源：AcWing
