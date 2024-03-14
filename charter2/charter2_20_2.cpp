/**
 * !C++允许一个类继承多个类
 * 语法：class 子类 : 继承方式 父类1, 继承方式 父类2..{}
 * 多继承可能引发父类中有同名成员出现，需要加作用域区分
 * C++实际开发中不建议用多继承、
 *
 * 菱形继承问题
 * 1. 两个派生类继承同一个基类
 * 2. 又有某个类同时继承这两个派生类
 * 3. 这种继承方式被称为菱形继承，或者钻石继承
 *                Base
 *        Son1            Son2
 *                Kid
 * !菱形继承可能引发的问题：
 * !1. 两个Son同时继承了Base的数据，当Kid使用数据时，容易产生二义性（可以通过前几课中设置作用域来解决）
 * !2. Kid继承自Base的数据继承了两份，而我们仅需要一份
 */
#include <iostream>
using namespace std;

class Animal
{
public:
    int m_Age;
};

// 在继承前加上virtual变成虚继承，解决资源浪费的问题
class Sheep : virtual public Animal
{
};
class Tuo : virtual public Animal
{
};
class SheepTuo : public Sheep, public Tuo
{
};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 100;
    st.Tuo::m_Age = 200;
    /**
     * 使用虚继承后，SheepTuo的空间存储变为
     * class SheepTuo size(12):
     *         +---
     * 0       | +--- (base class Sheep)
     * 0       | | (vbptr)
     *         | +---
     * 4       | +--- (base class Tuo)
     * 4       | | (vbptr)
     *         | +---
     *         +---
     *         +--- (virtual base Animal)
     * 8       | m_Age
     *         +---
     * 
     * SheepTuo::$vbtable@Sheep@:
     * 0       | 0
     * 1       | 8 (SheepTuod(Sheep+0)Animal)
     * 
     * SheepTuo::&vbtable@Tuo@:
     * 0       | 0
     * 1       | 4 (SheepTuod(Tuo+0)Animal)
     * vbi:       class  offset  o.vbptr  o.vbte  fVtorDisp
     *           Animal       8        0       4  0 
     * 
     * vbptr——虚基类指针
     * v - virtual
     * b - base
     * ptr - pointer
     * SheepTuo中的两个vbptr指针分别指向@Sheep@和@Tuo@两个虚基列表，并根据两个虚基列表中显示的偏移量进行偏移，最终都便宜到Virtual Base Animal中的m_Age位置
     * 这样就只有一份了
    */
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;
}

int main()
{
    test01();
    return 0;
}