#include<iostream>
/*
[xooo]  [xxoo]  [oxoo]  [oxxo]
[oooo]  [oooo]  [oooo]  [oooo]
*/
//关键:如何策略最优？
int main(){
    std::cout << "LLLV" << std::endl;
    return 0;
}
/*
无论小蓝怎么下，都能输
No.1 L
[xoyo]  小蓝下上面,就下面中间下yy
[oooo]  小蓝下下面,就也下下面,个数与他奇偶反即可

No.2 L
[xxyy]  再根据小蓝下下面的个数，下奇偶相反个数即可
[oooo]

No.3 L
[oxoy]  这样策略同No.1
[oooo]

唯一胜利情况No.4
[oxxo] -> [oxxy];[oxxo];[oxxo];[oxxo]
[oooo]    [oxxo] [xxyo] [xyyo] [oxyy]
必能victory
*/