// 构造函数的分类和调用
#include <iostream>
using namespace std;
// 分类
/**
 * 按参数分为：有参构造和无参构造（默认构造）
 * 按类型分为：普通构造和拷贝构造
 */
// 调用方式
/**
 * 括号法
 * 显示法
 * 隐式转换法
 */
class Person
{
public:
    // 默认构造函数
    Person()
    {
        cout << "No canshu" << endl;
    }
    // 有参构造
    Person(int a)
    {
        age = a;
        cout << "Have canshu" << endl;
    }
    // 拷贝构造
    /**
     * 此处为何必须使用常量引用类型的参数？
     * 1. 避免无限递归调用造成栈溢出
     * 若拷贝构造函数的参数不是引用而是一个值传递，那么在拷贝构造函数内部将会调用自身
     * class MyClass{
     * public:
     *     MyClass(MyClass obj){
     *
     *     }
     * };
     * MyClass p4 = p3; 这里调用拷贝构造函数，但参数是按值传递，则有
     * MyClass obj = p3; 又是一个拷贝构造函数的调用
     * MyClass obj = p3;
     * 若使用引用类型的参数
     * 则参数传递的过程是MyClass &obj = p3，不会形成拷贝构造函数
     *
     * 2. 避免不必要的复制：使用引用可以避免将整个对象复制一份，提高了程序的性能和效率。
     * 使用引用可以使得传递的仅仅是一个指向对象的指针而不是复制整个对象。
     *
     * 3. 拷贝构造函数的目的是复制一个对象，而不是修改它，因此应当使用常量引用以保证该语义。
     *
     */
    Person(const Person &p)
    {
        age = p.age;
        cout << "Copy" << endl;
    }
    ~Person()
    {
        cout << "XiGouFunc!" << endl;
    }
    int age;
    string name;
};

int main()
{
    // 调用无参构造函数
    // 这里注意调用无参构造函数不能在对象后加()，否则编译器会认为这是一个Person返回类型的函数声明
    Person p;
    // 括号法调用有参构造函数
    Person p1(10);
    Person p2(p1);

    // 显示法
    Person p3 = Person(10);
    Person p4 = Person(p3);
    // 如果单独写Person(10)就是生成一个匿名对象，生成后会立刻析构
    /**
     * 注意：不能使用拷贝构造函数初始化匿名对象，编译器会认为这是一个对象声明
     * Person(p4) === Person p4;
     */

    // 隐式转换法
    Person p5 = 10;
    /**
     * 若类的有参构造函数含有两个及以上参数时，有两种方法使用隐式转换法创建对象
     * 例：
     * class MyClass {
     * public:
     *     MyClass(int x, double y){
     *         // 构造函数逻辑
     *     }
     * }
     * 1. MyClass obj = {42, 3.14};
     * 2. MyClass obj = (MyClass)42, 3.14;
     */
    return 0;
}