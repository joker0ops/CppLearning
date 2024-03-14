/**
 * C++对象模型和this指针
 * 在C++中，类内的成员变量和成员函数分开存储
 * 仅非静态成员变量才属于类的对象上
 *
 * 内存对齐：
 * 在32位操作系统下，gcc和vs编译器都是默认按4个字节的大小进行内存对齐的
 * 即结构体或类中的内存分配默认按照4个字节的倍数进行分配
 *
 * this指针是隐含每一个非静态成员函数的一种指针
 * this指针不需要定义，直接使用即可
 * this指针的用途：
 * 1. 当形参和成员变量同名时，可用this指针来区分
 * 2. 在类的非静态成员函数中返回对象本身，可以使用return *this
 *
 * const修饰成员函数
 * 常函数：
 * 1. 成员函数后加const后我们称为常函数
 * 2. 常函数内不可以修改成员属性
 * 3. 成员属性声明时加关键字mutable后，在常函数中依然可以修改
 *
 * 常对象：
 * 1. 声明对象前加const称该对象为常对象
 * 2. 常对象只能调用常函数
 */
#include <iostream>
#include <string>
using namespace std;

class Null
{
};

class A
{
public:
    int a;          // 非静态成员变量 属于类的对象上
    static int m_B; // 静态成员变量，不属于类的对象上

    void func()
    {
        // 非静态成员函数，不属于类的对象上
        // 每一个非静态成员函数只会诞生一份函数实例，即多个同类型的对象共用一块代码
        // C++通过this指针指向 被调用的成员函数所属的对象 来表明是哪个对象调用了成员函数
    }

    static void func2()
    {
        // 静态成员函数，不属于类的对象上
    }
};
int A::m_B = 4;

class Person
{
public:
    Person(int age)
    {
        // 这样写会让编译器认为函数体和函数参数中的age是同一个，与成员变量age无关
        // age = age;
        this->age = age; // 使用this指针，this指向p1（谁调用该函数，this指向谁）
    }
    // 返回本体要用引用的方式做返回，如果用值的方式（Person）返回会调用拷贝构造函数再创建出一个对象p`
    Person &PersonAddPerson(Person &p)
    {
        this->age += p.age;
        // this指向调用该函数的对象，*this解引用后就会返回对象本体
        return *this;
    }
    int age;
};

class B
{
public:
    void showClassName()
    {
        cout << "this is B class" << endl;
    }

    void showPersonAge()
    {
        // 一般要添加一个指针的判断
        if (this == NULL)
        {
            return;
        }
        cout << "age = " << m_Age << endl;
        // 编译器认为每个类函数中出现的属性都含有this指针，即this->m_Age
    }

    int m_Age;
};

class C
{
public:
    // const修饰成员函数，使得成员变量的值无法在函数内更改
    // 在成员函数后添加const修饰的是this
    C()
    {
    }
    void showC() const
    {
        // m_A = 100;
        /**
         * 原理：
         * 在成员函数中m_A实际相当于this->m_A，而this指针的本质是指针常量，this的指向不可修改，
         * 添加const后也同时限制了this指向变量的值的修改
         */
        m_B = 100;
    }
    int m_A;
    // 加了mutable关键字后，仍然可以在常函数中修改
    mutable int m_B;
};

void test01()
{
    Null n1;
    // 空对象占用内存空间为一个字节
    // C++编译器为每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也都有一个独一无二的内存地址
    cout << sizeof(n1) << endl;
}

void test02()
{
    A a;
    // 不论有没有静态成员变量，对象a所占用的空间都是4
    cout << sizeof(a) << endl;
}

void test03()
{
    Person p1(18);
    cout << "p1's age is: " << p1.age << endl;
    Person p2(10);
    p2.PersonAddPerson(p1);
    // 可以看出，此时p2的年龄发生了变化，但PersonAddPerson在一个语句中只能调用一次
    cout << "p2's age is: " << p2.age << endl;
    // 若要在语句中多次调用Age增量函数，就需要把返回值改为Person类型
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "P2-plus's age is: " << p2.age << endl;
}

void test04()
{
    B *b = NULL;
    // 空指针也可以调用成员函数，但不能访问成员变量
    b->showClassName();
    // b->showPersonAge(); B * b = NULL创建出的是一个空指针，没有实体
    /**
     * 1. 成员函数的调用是通过函数指针进行的：在C++中，成员函数在底层实现上是通过this指针将类的地址作为额外的参数隐式地传递给成员函数，
     *    当通过空指针调用成员函数时，实际上会将空指针作为对象地址传递给成员函数，而只要函数内部不使用该指针，编译器就可以正常处理
     * 2. 成员变量的访问需要有效的对象：成员变量依附于对象而不是依附于类或函数。当访问成员变量时，需要通过有效的对象来访问。空指针
     *    并不指向任何有效的对象，因此无法直接访问成员变量。
     */
    /* !!!注意这里若使用const则必须为类添加无参构造函数 */
    const C c1; // 变为常对象仍然不可修改成员变量
    // c1.m_A = 100;
    // 加特殊关键字的成员变量可以
    c1.m_B = 100;
}

int main()
{
    test01();
    test02();
    test03();
    test04();
    return 0;
}