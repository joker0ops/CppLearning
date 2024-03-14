#include<iostream>
using namespace std;
/**
 * 对象的初始化和清理
 * 构造函数：初始化
 * 析构函数：清理
 * 如若不提供构造函数和析构函数，编译器会提供。而编译器提供的构造函数和析构函数是空实现
 * 构造函数主要用于创建对象时为对象的成员属性赋值，其由编译器自动调用，无需手动调用
 * 析构函数主要用于对象销毁前的清理工作，由系统自动调用
*/

/**
 * 构造函数语法：类名(){}
 * 1. 构造函数无返回值，也不写void
 * 2. 函数名称与类名相同
 * 3. 构造函数可以有参数，因此可以发生重载
 * 4. 程序在调用对象时会自动调用构造，而且只会调用一次
*/

/**
 * 析构函数语法：~类名(){}
 * 1. 析构函数无返回值也不写void
 * 2. 函数名称与类名相同，在名称前加符号~
 * 3. 析构函数不能有参数，因此不能重载
 * 4. 程序在对象销毁前会自动调用析构，而且只会调用一次
*/

class Person{
    public:
        Person(){
            Name = "Jack";
            Age = 6;
            cout << "1" << endl;
        }
        ~Person(){
            cout << "2" << endl;
        }
        void getName(){
            cout << Name << endl;
        }
        void getAge(){
            cout << Age << endl;
        }
    private:
        string Name;
        int Age;
};

int main(){
    Person p;   // 在栈上的数据，在main()函数执行完毕之后就会释放，析构函数会在对象释放前调用 
    p.getAge();
    p.getName();
    return 0;
}