/**
 * 指针就是内存地址，用户可以通过指针间接访问内存
 * 内存编号从0开始记录，一般用十六进制数字表示
 * 可以利用指针变量保存地址
*/
#include<iostream>
using namespace std;
struct student{
    string name;
    int age;
    int score;
};
// 结构体做函数参数
void printStudent(const student* stu){
    // 当使用结构体做函数参数时，可添加const修饰来防止误操作
    // stu -> age = 100 错误，这是常量指针
    cout << stu->age << endl;
}
int main(){
    // 1. 定义指针
    int a = 10;
    // 指针定义的语法：数据类型 * 指针变量名;
    int *p;
    p = &a;
    cout << "a's address is: " << &a << endl;
    cout << "p is: " << p << endl;

    // 2. 使用指针
    // 通过在指针前加*号解引用来找到指针指向内存中的数据
    *p = 1000;
    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;

    // 在32位系统下，不论什么类型的指针，都只占用4个字节的内存空间 (Why?)
    /**
     * 解释：32位系统能够支持的寻址空间最大为2^32个字节，换算成G的话刚好是4GB；而64位系统
     * 最大支持的寻址空间为
    */     
    // 64位系统下是8个字节
    cout << "sizeof(int*) = " << sizeof(int *) << endl;
    cout << "sizeof(float*) = " << sizeof(float *) << endl;
    // 空指针指指针变量指向内存中编号为0的空间，空指针指向的内存不可访问不可使用*解引用
    // 另注：内存编号0~255为系统占用内存，不允许用户访问
    int *pa = NULL;
    // 野指针指指针变量指向非法的内存空间
    int *pb = (int*)0x1100;  // 使用强制类型转换将十六进制数转换为内存地址

    // const修饰的三种情况：
    // 1. const修饰指针的指针类型，称为常量指针
    const int* p1 = &a;
    int b;
    p1 = &b;    // 正确，可以改变指针的指向
    // *p1 = 100;   错误
    // 2. const修饰指针的指针变量名，称为指针常量
    int* const p2 = &a;
    // p2 = &b;     错误
    *p2 = 100;   // 正确，可以改变指针的值
    // 3. const既修饰指针类型，也修饰指针变量名
    const int* const p3 = &a;
    // p3 = &b      错误
    // *p3 = 100    错误

    // 指针和数组的关系：
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int* pc = arr;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout << *pc << endl;
        pc++;
    }
    // 当数组做函数参数时，在函数定义中可以使用int* arr，也可以使用int arr[]
    
    /**
     * 结构体定义：
     * struct student{
     *  string name;
     *  int age;
     *  int score;
     * };
    */
    // 创建结构体变量的三种方式
    struct student{
        string name;
        int age;
        int score;
    }stu1;

    struct student stu2;    // struct关键字可省略

    struct student stu3 = {"Jack", 12, 99};
    cout << stu3.age << endl;   // 结构体变量使用.访问其成员
    // 结构体数组定义
    struct student arrs[3] = {
        {"Mike", 9, 100},
        {"John", 18, 100},
        {"Jenny", 22, 100}
    };
    // 结构体指针
    student* ptr = &stu3;
    cout << ptr->age << endl;   // 结构体指针可以通过->操作符来访问结构体中的成员
    return 0;
}