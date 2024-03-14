#include <iostream>
using namespace std;
int main()
{
    /*
        1. 单精度float      占用4字节   能表示7位有效数字
        2. 双精度double     占用8字节   能表示15-16位有效数字
    */
    // 默认情况下输出一个小数会显示出6位有效数字
    float f1 = 3.1415926f;
    cout << "f1 = " << f1 << endl;
    double d1 = 3.1415926;
    cout << "d1 = " << d1 << endl;
    // 科学计数法
    float f2 = 3e2; // 3*10^2;
    cout << f2 << endl;
    float f3 = 3e-4;
    cout << f3 << endl;
    system("pause");
    return 0;
}