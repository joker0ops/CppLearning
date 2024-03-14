#include<iostream>
#include<string>
using namespace std;
/**
 * 默认情况下，C++编译器至少给一个类添加3个函数
 * 1. 默认构造函数（无参，函数体为空）
 * 2. 默认析构函数（无参，函数体为空）
 * 3. 默认拷贝构造函数，对属性进行值拷贝
 * 
 * 构造函数调用规则如下：
 * - 如果用户定义有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造函数
 * - 如果用户定义拷贝构造函数，C++不会再提供其他构造函数
 * 以上规律及构造函数提供级别：拷贝构造函数 > 有参构造函数 > 默认构造函数
 * 默认的拷贝构造函数是浅拷贝，只复制原对象的所有成员属性
*/
class Student{
    public:
    Student(){
        age = 18;
        name = "XXX";
    }
    Student(int Age){
        age = Age;
    }
    Student(const Student & st){
        age = st.age;
    }
    ~Student(){
        ;
    }
    public:
    int age;
    string name;
};

int main(){
    // 此时用户已经定义了拷贝构造函数，编译器不再提供默认构造函数和有参构造函数
    Student p1;     // 若用户没有定义默认构造函数，则这种情况下程序会在此处报错
    Student p2(10); // 若用户没有定义有参构造函数，则这种情况下程序会在此处报错
    Student p3(p2);
    return 0;
}