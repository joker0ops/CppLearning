// 递增运算符重载：实现自定义的整形数据
// 重载++运算符有两种，分别是前置++重载和后置++重载
#include <iostream>
#include <string>
using namespace std;

class MyInteger{
    friend ostream &operator<<(ostream &cout, MyInteger &number);
    public:
    MyInteger(){
        this->num = 0;
    }
    // 类内重载前置++运算符
    // 这里如果要使用重载后的<<进行输出的话不能用void返回类型，因为<<接收的类型为MyInteger，因此要使用MyInteger类型
    // 另外还要注意的是，返回值类型应为引用类型而不是值传递类型，否则会导致二次递增时操作的不是同一个对象：
    /**
     * 例：
     * MyInteger &operator(){
     *     num++;
     *     return *this;
     * }
     * 
     * void test01(){
     *     MyInteger number1;
     *     // !!! 在下面的操作中，第一次++是对number对象进行操作，而第二次++操作的是返回该对象时调用的拷贝构造函数创建出来的对象
     *     // 输出结果增加两次
     *     cout << ++(++number1) << endl;
     *     // 输出结果只增加了一次
     *     cout << number1 << endl;
     * }
    */
    MyInteger &operator++(){
        num++;
        // this指针解引用返回当前对象
        return *this;
    }
    // 类内重载后置递增++运算符
    // 只要参数不同即可重定义函数，int表示占位参数，只有加了int，编译器才可以区分前置和后置++运算符重载
    // 注意后置返回的是值而不是引用，因为后置返回的temp是一个局部变量，局部变量在函数运行结束后即被释放，返回其引用是不合法的
    // 注意这里由于用的不是引用因此链式编程对其无效，即(number++)++是只增加一次的
    // 根据++在语句最后进行计算的原理设计重载函数：
    MyInteger operator++(int){
        // 先 记录当前结果
        MyInteger temp = *this;
        // 后 将表达式++
        this->num++;
        // 最后 返回当前结果
        return temp;
    }
    private:
        int num;
};

ostream &operator<<(ostream &cout, MyInteger &number){
    cout << number.num;
    return cout;
}

int main()
{
    MyInteger number;
    (number++)++;
    cout << number << endl;
    cout << endl;
    cout << ++(++number) << endl;
    cout << number << endl;
    return 0;
}