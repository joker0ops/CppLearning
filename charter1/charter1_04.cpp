#include<iostream>
using namespace std;
/*
    常量的定义方式：
    1、#define 宏常量
    2、const修饰的变量
*/

#define week 7
int main(){
    // week = 14; 报错，表达式左值不可修改
    cout << week << endl;
    const int Day = 7;
    // Day = 14; 报错，表达式左值不可修改
    cout << Day << endl;
    system("pause");
    return 0;
}