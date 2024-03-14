/**
 * 在成员变量和成员函数前加上关键字static，称为静态成员
 * 分类：
 * 静态成员变量：
 * !1. 静态成员变量属于整个类而不是某一对象，所有对象共享同一份数据
 * 2. 在编译阶段分配内存
 * !3. 类内声明，类外初始化
 * 静态成员函数：
 * 1. 所有对象共享同一个函数
 * 2. 静态成员函数只能访问静态成员变量
*/
#include<iostream>
using namespace std;

class Person{
    public:
    /**
     * 静态成员函数特点：
     * 1 程序共享同一个函数
     *! 2 静态成员函数只能访问静态成员变量
    */
    static int m_C;
    static void func(){
        cout << "func Using" << endl;
        m_A = 100;
        // m_B = 100; 错误！静态成员函数属于整个类，访问非静态成员变量会导致编译器不知道要访问哪一个对象的
    }

    private:
    /**
     * 静态成员变量特点：
     * 1 在编译阶段分配内存
     * 2 类内声明，类外初始化
     * 3 所有对象共享同一份数据
    */
    static int m_A;
    int m_B;
    static void func2(){
        cout << "func2 Using" << endl;
    }
};
//! 静态成员变量不论访问权限都是在类内声明，类外初始化 ???
int Person::m_A = 10;
int Person::m_C = 100;

void test01(){
    Person p1;
    p1.m_C = 10;
    // 静态成员变量通过类名访问的方法
    cout << Person::m_C << endl;
    Person p2;
    // 两个对象共享数据
    cout << p2.m_C << endl;
    // cout << p1.m_A << endl; 错误，私有静态成员变量无法在类外访问
}

void test02(){
    Person p1;
    // 通过对象访问静态成员函数
    p1.func();
    // 通过类名访问静态成员函数
    Person::func();
    // Person::func2(); 错误，没有权限访问不到
}

int main(){
    test01();
    test02();
    return 0;
}