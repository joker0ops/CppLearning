// 函数提高
#include <iostream>
using namespace std;
// 1. 在C++中，函数的形参列表中的形参可以有默认值
// 2. 如果某个位置参数有默认值，那么从该位置之后的所有参数都要有默认值
// 3. 如果函数声明有默认值，函数定义的时候就不能有默认参数
int func(int a, int b = 10, int c = 20);
int func(int a, int b, int c)
{
    return a + b;
}
int func1(int a, int b = 10, int c = 20)
{
    return 0;
}
// C++中函数的形参列表可以有占位参数用来占位，调用函数时必须填补该位置
void func2(int a, int)
{
    cout << "this is func" << endl;
}

// 函数重载
/**
 * 函数重载满足条件：
 * 1. 同一个作用域下
 * 2. 函数名称相同
 * 3. 函数参数类型不同、参数个数不同或者顺序不同————————总结来说就是参数不同
 * 注意：函数的返回值不能作为函数重载的条件
 */

// 函数重载的歧义问题
// 1. 引用作为函数重载条件
void fun(int &b)
{
    cout << "fun(int &b)" << endl;
}
void fun(const int &b)
{
    cout << "fun(const int &b)" << endl;
}
/**
 * 在调用函数时，若使用int a = 10; fun(a);那么调用的将会是第一个函数，因为传入的参数a是一个变量，且未加const修订
 * 函数参数得到的是int &b = a;这是合法的，而若调用第二个函数则是const int &b = a;这是不合法的，因为const限定。
 * 若使用fun(10);则调用的将会是第二个函数，因为int &b = 10;是不合法的，而const int &b = 10;是合法的
 */

// 2. 函数重载碰到函数默认参数
void funt(int a, int b = 10)
{
}

void funt(int a)
{
}
/**
 * 若使用funt(10);调用的话会报错，出现二义性程序无法辨别应该调用哪个函数，
 * 而若使用funt(10, 20);则不会报错，程序会直接调用第一个函数，以后使用时要尽可能避免
 */
int main()
{
    int a = func(20, 20);
    cout << a << endl;
    a = func(20);
    cout << a << endl;
    int b = func1(29, 10, 23);
    cout << b << endl;
}