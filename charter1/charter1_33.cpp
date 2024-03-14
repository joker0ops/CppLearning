#include<iostream>
using namespace std;
int main(){
    // for循环语句
    /**
     * 语法：for(起始表达式;条件表达式;末尾循环体){循环语句;}
     * 执行顺序：起始表达式->条件表达式->循环语句->末尾循环体->条件表达式->循环语句->末尾循环体->条件表达式...
    */
    for(int i=0; i<10; i++)
        cout << i << endl;
    return 0;
}