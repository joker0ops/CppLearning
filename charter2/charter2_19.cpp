/**
 * 继承同名静态成员处理方式
 * 问题：继承中同名的静态成员在子类对象上如何进行访问？
 * 静态成员和非静态成员在继承成员同名问题上的处理方式一致
 *  - 访问子类同名成员 直接访问即可
 *  - 访问父类同名成员 需要加作用域
 */
#include <iostream>
using namespace std;

class Base
{
public:
    static int m_A;
    static void func()
    {
        cout << "Base static using" << endl;
    }
    static void func(int a)
    {
        cout << a << endl;
    }
};
int Base::m_A = 100;

class Son : public Base
{
public:
    static int m_A;
    static void func()
    {
        cout << "Base static using" << endl;
    }
};
int Son::m_A = 200;

void test01()
{
    // 通过对象访问
    Son s;
    cout << "Son's m_A: " << s.m_A << endl;
    cout << "Base's m_A" << s.Base::m_A << endl;
    // 通过类名访问
    cout << "Son's m_A: " << Son::m_A << endl;
    cout << "Base's m_A" << Son::Base::m_A << endl;
    // 静态成员函数的访问方式与静态成员变量类似
    // !如果子类中出现和父类同名的静态成员函数，子类的同名成员会隐藏掉父类中所有同名静态成员函数
    // !如果想访问到父类中被隐藏的同名静态成员函数，需要加作用域
}

int main()
{
    test01();
    return 0;
}