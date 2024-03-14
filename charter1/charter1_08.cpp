#include<iostream>
using namespace std;
int main(){
    // 语法：sizeof( 数据类型/变量 ) 返回字节数
    cout << "The count space is " << sizeof(short) << endl;
    cout << "The count space is " << sizeof(int) << endl;
    cout << "The count space is " << sizeof(long) << endl;
    cout << "The count space is " << sizeof(long long) << endl;
    // short < int <= long < long long
    system("pause");
    return 0;
}