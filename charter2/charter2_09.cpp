// 初始化列表的方式进行初始化
#include<iostream>
using namespace std;
class Person{
    public:
    // Person():m_A(20), m_B(30), m_C(10){ }    // 无参构造函数初始化方法
    // 有参构造函数初始化方法
    Person(int a, int b, int c):m_A(a), m_B(b), m_C(c){
        cout << m_A << m_B << m_C << endl;
    }
    private:
    int m_A;
    int m_B;
    int m_C;
};