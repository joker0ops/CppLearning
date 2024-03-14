/**
 * 在程序中，有些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
 * 友元的目的：让函数或者类访问另一个类中的私有成员
 *
 * 友元的关键字：friend
 *
 * 友元的三种实现：
 * 1. 全局函数做友元
 * 2. 类做友元
 * 3. 成员函数做友元
 */
#include <iostream>
using namespace std;
//! GoodGay3中需要用到Building，因此要先声明Building
class Building;
//! GoodGay3中的成员函数作Building的友元，因此要先定义GoodGay3
class GoodGay3
{
public:
    GoodGay3();
    // 让成员函数visit可以访问Building中的私有内容
    void visit(Building *building);
    // 让成员函数visit2无法访问Building中的私有内容
    void visit2(Building *building);
};

class Building
{
    // 声明类的友元函数，声明后该函数可以访问类中的私有成员变量
    friend void GoodGay(Building* building);
    // 声明类的友元类
    friend class GoodGay2;
    // 声明类的友元类成员函数
    friend void GoodGay3::visit(Building* building);

public:
    Building()
    {
        m_Sittingroom = "KeTing";
        m_bedroom = "WoShi";
    }

public:
    string m_Sittingroom;

private:
    string m_bedroom;
};
// 类做友元
class GoodGay2
{
public:
    //! 要先在类中声明才能在类外定义成员函数和其他函数
    GoodGay2();
    void visit();
    Building *building;
};
// 类外写成员函数
void GoodGay2::visit()
{
    cout << "GoodGay Class is visiting:" << building->m_Sittingroom << endl;
    cout << "GoodGay Class is visiting:" << building->m_bedroom << endl;
}
GoodGay2::GoodGay2()
{
    // 在堆区创建一个Building的对象，并传递给指针building
    building = new Building;
}

// 全局函数作友元
void GoodGay(Building *building)
{
    cout << "GoodGay is visiting:" << building->m_Sittingroom << endl;
    cout << "GoodGay is visiting:" << building->m_bedroom << endl;
}

// 类的成员函数作另一个类的友元
GoodGay3::GoodGay3()
{
}
//! 这里对函数的定义只能放到class Building的定义后面，因为用到了其中的成员属性
void GoodGay3::visit(Building *building)
{
    cout << "GoodGay3::visit2 is visiting:" << building->m_Sittingroom << endl;
    cout << "GoodGay3::visit2 is visiting:" << building->m_bedroom << endl;
}
void GoodGay3::visit2(Building *building)
{
    cout << "GoodGay3::visit2 is visiting:" << building->m_Sittingroom << endl;
    // visit2无法访问
    // cout << "GoodGay3::visit2 is visiting:" << building->m_bedroom << endl;
}

void test01()
{
    Building building;
    //! 取地址
    GoodGay(&building);
}

void test02()
{
    //! 注意全局函数名与类名不要重名！否则容易引发冲突，
    //! 直接写GoodGay gg，编译器会把GoodGay当做函数shengming
    GoodGay2 gg;
    gg.visit();
}

int main()
{
    test01();
    test02();
    GoodGay3 gg;
    Building building;
    // 取地址
    gg.visit(&building);
    return 0;
}