// 类对象作为类成员
// C++类中的成员可以是另一个类的对象，称该成员为对象成员
#include<iostream>
#include<string>
using namespace std;

/*  class A{};

    class B{
        A a;
    };
当创建B时，A与B的构造和析构的顺序是谁先谁后？
*/
class Phone{
    public:
    Phone(string name){
        m_PhoneName = name;
        cout << "Phone Starting..." << endl;
    }

    ~Phone(){
        cout << "Phone Ending..." << endl;
    }

    string m_PhoneName;
};

class Person{
    public:
    // 初始化构造列表可以告诉编译器调用哪一个构造函数
    Person(string name, string pname): m_Name(name), m_Phone(pname){
        /**
         * 这里能直接将一个字符串变量赋值给类对象的原因：
         * 初始化列表的底层实现逻辑为：
         * string m_Name = name;
         * Phone m_Phone = pname;
         * 虽然数据类型无法匹配，但是相当于有参构造函数的隐式转换法
        */
        cout << "Person Starting..." << endl;
    }

    ~Person(){
        cout << "Person Ending..." << endl;
    }

    void Print(){
        cout << m_Name << m_Phone.m_PhoneName;
    }

    string m_Name;
    Phone m_Phone;
};

int main(){
    // 当类中的成员是另一个类的对象时，称该成员为对象成员
    // 构造的顺序是：先调用对象成员的构造，再调用本类构造
    // 析构的顺序是：先调用本类的析构，再调用对象成员的析构
    Person p("Joker", "iPhone 13Plus");
    p.Print();
    return 0;
}