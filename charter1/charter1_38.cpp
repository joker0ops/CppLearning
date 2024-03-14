/**
 * 函数的分文件编写规范：
 * 1. 创建后缀名为.h的头文件
 * 2. 创建后缀名为.cpp的源文件
 * 3. 在头文件中写函数的声明
 * 4. 在源文件中写函数的定义
 * 5. 使用时直接include包含头文件即可
 */
// swap.h文件
#include <iostream>
using namespace std;
// 函数的声明
void swap(int a, int b);

// swap.cpp文件
// #include "swap.h"
// 函数的定义
// void swap(int a, int b)
// {
//     int temp = a;
//     a = b;
//     b = temp;

//     cout << "a= " << a << endl;
//     cout << "b= " << b << endl;
// }

// 使用时直接#include "swap.h"即可