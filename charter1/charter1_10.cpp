#include<iostream>
using namespace std;
int main(){
    // C和C++中字符变量只占用1个字节
    // 字符型变量是把ASCII编码放入内存中
    char ch = 'a';
    // 常见错误：
    // char ch2 = "n";
    // char ch3 = "abc";
    // 字符型变量的ASCII编码值
    // a - 97, A - 65
    cout << (int)ch << endl;
    return 0;
}