#include<iostream>
using namespace std;
int main(){
    /*
        bool类型
        true——真（本质是1）
        false——假（本质是0）
        bool数据类型占一个字节大小
    */
    bool flag = true;
    cout << sizeof(flag) << endl;
    cout << flag << endl;
    system("pause");
    return 0;
}