#include<stdio.h>
int main(){
    short count[10] = {0};
    int i;
    for (i = 1; 1 == 1;i++){
        int num = i;
        while (num)
        {
            count[num % 10]++;
            num/= 10;
        }
        int flag = 0;
        for (int j = 0; j < 10;j++){
            if(count[j]>2021){
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
    i--;
    printf("%d", i);
    return 0;
}
//3181