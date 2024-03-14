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

class Sheep : public Animal
{
};
class Tuo : public Animal
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
    // 当使用菱形继承时，两个父类拥有相同数据，需要加以作用域区分
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;

    // 这份数据本来只需要一份，菱形继承导致数据有两份造成了资源浪费
    /**
     *  在SheepTuo变量类型中有两份m_Age，分别是从Sheep和Tuo中继承的
     *  数据类型占8个字节的空间
    */
}

int main()
{
    test01();
    return 0;
}