#include<iostream>
#include<map>
int main(){
    int x = 0, y = 0;
    std::cin >> x >> y;
    std::map<std::pair<double, double>, int> L;
    //先把垂直考虑(k不存在时)
    int c = x;
    for (int x0 = 0; x0 < x-1;x0++){
        for (int y0 = 0; y0 < y;y0++){
            for (int x1 = x0 + 1; x1 < x;x1++){
                for (int y1 = 0; y1 < y; y1++){
                    double k, d;
                    k = (y1 - y0) / (x1 - x0);
                    d = y1 - x1 * k;
                    if(L.find({k,d})==L.end()){
                        c++;
                        L[{k, d}] = 1;
                    }
                }
            }
        }
    }
    std::cout << c;
    return 0;
}