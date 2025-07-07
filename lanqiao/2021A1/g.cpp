#include<iostream>
//贪心思想
/*
思考：
胜负与x的什么特征有关？
因为是轮流，某一位的0、1及其个数是否对结果产生影响？

x二进制位上的0、1;显然与0的^对数值*无影响*，考虑1即可
*/
int main(){
    int T;
    std::cin >> T;
    for (int i = 0; i < T;i++){
        int n = 0;
        std::cin >> n;
        /*因为Alice先手优势
        若某位的1个数为偶数,无论怎么优选,双方此位的异或结果肯定相同
        因此考虑最高的个数为奇的位即可(必有胜负)：而此时*细想*后又分1 or !1
        */
        int bit[22] = {0};
        for (int j = 0; j < n;j++){
            int x;
            std::cin >> x;
            for (int k = 0; x;k++){
                bit[k] += x & 1, x >> 1;
            }
        }
        int j = 21;
        while(bit[j--]%2&&j>=0);
        if(j<0){
            std::cout << "0" << std::endl;
        }else{
            if(bit[j+1]==1){
                std::cout << "1" << std::endl;
            }else{
                //不为1时,Alice选完1次后,同时剩余偶数个1
                //此时对于Alice要使自己的1最终个数为奇，对方则相反
                /*
                n为奇时,剩余偶数个0，Alice都能维持个数为奇或让对方为偶
                n为偶时,剩余奇数个0,对方不断选0能最后压制Alice最终获胜
                */
                if(n%2)
                    std::cout << "1" << std::endl;
                else
                    std::cout << "-1" << std::endl;
            }
        }

    }
    return 0;
}