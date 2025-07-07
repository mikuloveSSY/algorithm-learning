#include<iostream>
#include<string>
using namespace std;

int main(){
    string x, y;
    getline(cin, x,'k');
    //参数是'cin,str,ch',ch为遇到某字符停止,默认是'\n',但不会读取'\n',当getline()读取直接遇到'\n'，会将其读入并替换成'\0'
    //cin.ignore(5,'l');
    //默认是'1,EOF'或遇到'\n' 若第二个为字符ch,则直到ch退出且丢弃ch  
    getline(cin, y);
    cout << x << endl;
    cout << y << endl;
    return 0;
}
/*
《情况1》           《情况2》               《ignore情况》
input：             input：                 intput：
abc cbak            abc cbakaaa             abc cba kaalcc
aaa

output:             output：                output：(可见其丢弃了l)
abc cba             abc cba                 abc cba
                    aaa                     cc
*/

//注意cin.getline是iostream里的，它的参数是(字符数组，个数，遇到截止到字符)
//但它不能用string！，只能用字符数组！