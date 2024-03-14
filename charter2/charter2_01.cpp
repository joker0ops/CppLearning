/**
 * C++内存分区
 * 程序运行前（即未执行.exe文件前）：
 *  1. 代码区：存放代码的二进制形式，由操作系统进行管理，是共享且只读的，目的是防止其他程序修改内存以及一份程序的频繁执行
 *  2. 全局区：存放全局变量和静态变量并包含常量区，该区域数据将会一直存放到程序结束，之后由操作系统释放 
 *  3. 常量区：存放字符串常量和其他常量
 * 程序运行后：
 *  1. 栈区：存放函数的参数值，局部变量等，注意一定不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
 *  2. 堆区：堆区由程序员进行开辟和释放管理，可以使用new在堆区开辟内存，使用delete释放内存
*/
#include<iostream>
#include<string>
using namespace std;
// 全局变量
int a = 1;
// const修饰的全局变量
const int c = 190;

int* func(){
    int* a = new int(10);
    return a;
}

int& test02(){
    static int a = 20;
    return a;
}

void showvalue(const int& value){
    // value += 10; 错误
    cout << value << endl;
}

int main(){
    // 静态变量
    static int b = 10;
    // 常量
    // 字符串常量
    cout << (int)&"Hello World!" << endl;
    // const修饰变量
    // 1. const修饰全局变量存放在常量区
    // 2. const修饰局部变量 
    const int d = 100;  // 局部const常量存放在栈区

    // new操作符的使用——>new 数据类型
    int* prt = new int(10);
    string* pst = new string("Hello World");
    int* pfunc = func();
    cout << *pfunc << endl;
    delete pfunc;
    // 堆区开辟数组
    int* arr = new int[10];
    // 堆区释放数组，在delete后加[]，后跟数组首地址
    delete[]  arr;

    // 引用类型的使用
    // 数据类型 &别名 = 原名（本质上是指针常量，可以修改指针所指内存的值，不可更改指针指向）
    int a = 10;
    int &b = a;
    // 注意：引用必须初始化，可以对别名赋值，但不可以更改别名的指向，引用的使用示例见swap.cpp
    // 使用引用作为函数的返回值时，可以将函数调用作为左值，但切记不要返回局部变量的引用，因为局部变量
    int &ref = test02();
    cout << "ref = " << endl;
    test02() = 1000;
    cout << "ref = " << endl;
    /*
        解释：如果函数作为左值出现，则返回类型必须是引用（仔细思考一下：若函数作为左值存在，
        那么函数的返回值在函数运行结束后应该一直存在，一般数据类型中只有引用才符合这个条件）
        在ref接收test02()的返回值后，ref就作为test02返回值的别名，那么对test02返回值的修改其实也是对ref的修改
    */ 
    // 常量引用：在函数形参列表中，可以使用const修饰形参，防止形参改变实参
    int a = 10;
    showvalue(a);
    return 0;
}