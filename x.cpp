#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int main() {
    std::vector<int> a = {1, 2, 2, 3};
    std::vector<int> b = {2, 3, 4};
    std::vector<int> uni, inter;

    // 计算并集
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(uni));
    // 计算交集
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(inter));

    std::cout << "Union: ";
    for (int x : uni) std::cout << x << " "; // 输出 1 2 2 3 4
    std::cout << "\nIntersection: ";
    for (int x : inter) std::cout << x << " "; // 输出 2 2

    return 0;
}