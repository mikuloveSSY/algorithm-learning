#include<iostream>
#include<queue>
using namespace std;
/* 1,2是重载操作符；3是构造比较函数
(其实不用优先队列的话，可以用sort排序)
默认：前一个 __ 后一个 
    <是从小到大
    >是从大到小
    唯一不同的是：less<>大根堆 greater<>小根堆
                是'后'比'前'的
*/
//注意：c++不同于c的是：T &x 与 T* p (&x相当于是传入指针)
//同时引用时也不一样,如：add(x) 与 add(&x)

//1
struct node{
    int a;
}x,y;

bool operator<(const node &x, const node &y){
    return x.a < y.a;//小根堆
}
priority_queue<node> L1;

//2
struct node{
    int a;
    bool operator < (const node &x) const{
        return x.a < a;//小根堆
    }
}x,y;
priority_queue<node> L2;

//3
struct node{
    int a;
}x,y;

struct cmp{
    //()是函数调用重载
    bool operator()(node x, node y){
        return x.a < y.a;//小根堆
    }
};
priority_queue<node, vector<node>,cmp> L3;