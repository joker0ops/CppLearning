/**
 * 继承中同名成员处理方式
 *  - 访问子类同名成员：直接访问即可
 *  - 访问父类同名成员：需要加作用域
 */
#include <iostream>
using namespace std;

class Base
{
public:
    Base(){
        m_A = 100;
    }
    void func(){
        cout << "Base's func using" << endl;
    }
    // 在父类中对func进行重载
    void func(int a){
        cout << "Base output a " << a << endl;
    }
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son : public Base
{
public:
    Son(){
        m_A = 200;
    }
    void func(){
        cout << "Son's func using" << endl;
    }
    int m_A;
    int m_D;
};

/**
 * 利用开发人员命令提示工具查看对象模型
 * 跳转盘符到项目代码所在盘符 D:
 * cd 到对应的目录下
 * cl /d1 reportSingleClassLayout要查看的类名 所属文件名
 */

void test01()
{
    // 测算Son数据类型的大小，可见Son其实继承了Base中所有的元素，只是private权限的元素私密性较高所以子类无法访问
    // 父类中的私有成员被编译器隐藏
    cout << sizeof(Son) << endl;
}

void test02(){
    Son s;
    cout << "Son's m_A is: " << s.m_A << endl;
    // 通过子类对象访问父类中的同名成员需要加作用域
    cout << "Base's m_A is: " << s.Base::m_A << endl;
}

void test03(){
    Son s;
    // 直接调用调用的是子类中的func函数
    s.func();
    // 若想调用父类中的成员函数必须加作用域
    s.Base::func();
    // !如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    // !如果想访问到父类中被隐藏的同名成员函数，需要加作用域
    // !s.func(8); X
    s.Base::func(6);
}

int main()
{
    //! 继承中构造和析构的顺序如下：
    //! 先构造父类，再构造子类，析构的顺序与构造的顺序相反（类似以其他类的对象做为类的成员变量）
    //! 先调用父类构造函数，再调用子类构造函数
    test01();
    return 0;
}