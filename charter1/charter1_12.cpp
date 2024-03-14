#include<iostream>
#include<string>
using namespace std;
int main(){
    // 第一种
    // C风格的字符串
    // char 变量名[] = “字符串值”
    char str1[] = "Hello World";
    string str2 = "Hello World!";
    cout << str1 << endl;
    cout << str2 << endl;
    system("pause");
    return 0;
}