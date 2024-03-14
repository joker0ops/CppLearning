#include<iostream>
using namespace std;
// 数据类型：C++规定在创建一个变量或者常量时，必须要指定出相应的数据类型，否则无法给变量分配内存
/*
整型分类：
数据类型        占用空间                                        取值范围
short          2字节                                           (-2^15~2^15-1)
int            4字节                                           (-2^31~2^31-1)
long           4字节或8字节                                     (-2^31~2^31-1)
long long      8字节                                           (-2^63~2^63-1)
*/
int main(){
    // 1、短整型(-32768~32767)
    short num1 = 32768;

    // 2、整形
    int num2 = 32768;

    // 3、长整型
    long num3 = 10;

    // 4、长长整形
    long long num4 = 10;

    cout << "num1= " << num1 << endl;
    cout << "num2= " << num2 << endl;
    cout << "num3= " << num3 << endl;
    cout << "num4= " << num4 << endl;

    system("pause");
    return 0;
}