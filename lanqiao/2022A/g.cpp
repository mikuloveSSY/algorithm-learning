#include<iostream>
#include<map>
using namespace std;

const int n = 1e5 + 5;
int N, K;
int A[n],start[n];
map<int, int> last;

int main(){
    cin >> N >> K;
    int st = 1;
    for (int i = 1; i <= N;i++){
        cin >> A[i];
        if(A[i]<A[i-1]){
            last[st] = i - 1;
            st = i;
        }
        start[i] = st;
    }
    int max = 0;
    for (int i = 1; i <= N - K;i++){
        int l;
        if(A[i]<=A[i+K+1]){
            l = last[start[i + K + 1]] - start[i]+1;
        }else{
            l = i + K + 1 - start[i];
        }
        max = max > l ? max : l;
    }
    cout << max << endl;
    return 0;
}