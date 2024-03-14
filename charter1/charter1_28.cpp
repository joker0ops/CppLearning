#include<iostream>
using namespace std;
int main(){
    // 语法：表达式1 ? 表达式2 : 表达式3
    // 表达式1为真，则返回表达式2的结果，否则返回表达式3的结果
    int a = 10;
    int b = 20;
    cout << (a > b ? a : b) << endl;
    system("pause");
    return 0;
}