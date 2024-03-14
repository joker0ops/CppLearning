/**
 * 拷贝构造函数的调用时机：
 * 1. 使用一个已经创建的对象初始化一个新对象
 * 2. 值传递的方式给函数参数传值
 * 3. 以值方式返回局部对象
 */
#include <iostream>
using namespace std;
class Person
{
public:
    Person()
    {
        cout << "No segment func" << endl;
        age = 0;
    }
    Person(int Age)
    {
        cout << "With segment func" << endl;
        age = Age;
    }
    Person(const Person &p)
    {
        cout << "Copy segment func" << endl;
        age = p.age;
    }
    ~Person()
    {
        cout << "Class ending----" << endl;
    }
    int age;
};

// 使用一个已经创建完毕的对象来初始化一个新的对象
void test01()
{
    Person p1(100);
    Person newman(p1);
    Person newman2 = newman;

    Person newman3;
    newman3 = newman; // 注意这里不是调用拷贝构造函数，而是赋值操作
    // 对象赋值是完全拷贝原对象的所有成员变量，而拷贝构造函数要看具体函数实现
    cout << newman3.age << endl;
}

void dowork(Person p1)
{
    // 这里是值传递，修改p1对p无影响
    // 相当于Person p1 = p; 调用了拷贝构造函数
}
void test02()
{
    Person p;
    dowork(p);
}
/**
 * 调用原理：
 * Person p1 -> 调用默认构造函数创建p1
 * return p1 -> 并非返回p1，而是通过拷贝构造函数创建出一个p`对象，
 * 随即p1销毁（局部变量），p`返回给p（调用拷贝构造函数）这里可以理解为将p1的值返回给p
 * 注意p在接收p`时是不会再次调用构造函数的  ???
 */
Person dowork2()
{
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}
void test03()
{
    Person p = dowork2();
    cout << (int *)&p << endl;
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}