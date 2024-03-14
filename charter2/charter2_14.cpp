/**
 * 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
 * 1. 加号运算符重载：实现两个自定义数据类型相加的运算
 * 2. 左移运算符重载：实现对自定义数据类型的输出。
 * 这里<<并不是作为普通的移位运算符，而是流运算符，可以理解为数据流向。cout是数据输出接口，然后<<把运算符右边的数据输出到运算符左边的目标
 * 反之则为流式输入cin >> a >> b; cout属于输出流ostream的对象，cin属于输入流istream的对象
 * 3. 递增运算符重载：实现自定义的整形数据
 */
#include <iostream>
using namespace std;

class Person
{
    // 类中的成员变量一般都使用private进行了私有化，可以使用友元函数添加函数的访问权限
    friend Person operator+(Person &p1, Person &p2);
    friend ostream &operator<<(ostream &out, Person &p);
    friend int main();
public:
    Person()
    {
        ;
    }
    Person(int age, int score)
    {
        this->age = age;
        this->score = score;
    }
    // 利用成员函数重载+号运算符
    // Person operator+(Person &p){
    //     Person temp;
    //     temp.age = this->age + p.age;
    //     temp.score = this->score + p.score;
    //     return temp;
    // }
    // 利用成员函数重载左移运算符
    // 不会利用成员函数来重载左移运算符，只能利用全局函数来重载左移运算符
    // 在单目运算符（只有一个被操作数的运算符）重载中，如果实现为成员函数，则一般不需要参数，如果实现为全局函数则至少一个参数
    // 在双目运算符（有两个操作数的运算符如A+B）重载中，如果实现为成员函数则一般需要一个参数，如果实现为全局函数则至少需要两个参数
    // 小括号运算符参数可以有任意个
    // 例外：后置自增（自减）运算符虽然是单目运算符但因为要与前置自增（减）相区别，人为加了个int型参数
    // void operator<<(){
    //     // 至少需要一个参数，但括号内无法填参数，填为cout则重载后编程<<cout
    // }
private:
    int age;
    int score;
};

// 全局函数实现运算符重载
// 运算符重载函数也可以用成员函数的形式实现，只要使用了通用标识符operator即可实现调用时的简化
Person operator+(Person &p1, Person &p2)
{
    Person p3;
    p3.age = p1.age + p2.age;
    p3.score = p1.score + p2.score;
    return p3;
}

// 全局函数重载左移运算符，这里cout必须用引用，因为不引用的话相当于调用拷贝构造函数传值，而ostream中的拷贝构造函数是protected的，无法拷贝
// 若要实现链式编程，则把返回值由void改为ostream &，这样返回值仍是cout的类型，可以继续追加输出值
// 直接使用ostream做返回值会在返回时再次调用拷贝构造函数，为防止触发protected的保护机制则需要使用引用类型
// 引用的本质其实就是起别名，所以这里cout都换成out其实也可以
ostream &operator<<(ostream &cout, Person &p)
{
    cout << "age = " << " " << p.age << "score = " << p.score;
    return cout;
}

int main()
{
    Person p1(18, 99), p2(17, 80);
    Person p3 = p1 + p2; // 本质上是Person p3 = operator+(p1, p2); 或 Person p3 = p1.operator+(p2); 成员函数重载与全局函数重载的调用方法相同
    cout << p3.age << endl;
    cout << p3.score << endl;
    cout << p3 << "Hello World!" << endl;
    // 这里仅有cout << p3调用了运算符重载，由于其返回值仍是ostream类型，因此可将cout << p3看做cout，继续追加后续输出（链式编程）
    return 0;
}

// 对于内置的数据类型的表达式的运算符是不可能改变的：例如1+1=2不可能通过重载运算符改变结果
// 不要滥用运算符（别人可能不知道什么意思） 