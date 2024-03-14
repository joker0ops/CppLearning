/**
 * 深拷贝与浅拷贝问题：
 * 浅拷贝：简单的赋值操作(默认拷贝构造函数的视线方式)
 * 深拷贝：在堆区重新申请空间，进行拷贝操作
*/
#include<iostream>
using namespace std;
class Person{
public:
    int m_age;
    // 使用int * 型的变量存储数据，把数据存储在堆区
    int * m_height;
    // 无参（默认）构造函数    
    Person(){
        cout << "No segment func" << endl;
    }
    // 有参构造函数调用
    Person(int age, int height){
        m_age = age;
        m_height = new int(height);
        cout << "With a segment func" << endl;
    }
    // 析构函数调用
    // 析构函数终于起到作用了！在执行析构时，应该把堆区的数据释放干净
    ~Person(){
        if(m_height != NULL){
            delete m_height;
            m_height = NULL;
            /**
             * 直接这样是错误的！！！会导致空间重复释放的错误
             * 原因：编译器在执行默认拷贝构造函数时，是逐字节将原对象的数据复制到新对象上，
             * 因此原对象的m_height与新对象的m_height存储的地址相同，也就是说新旧m_height指向的堆区地址是相同的
             * 在执行Person p2(p1)后进行析构时，会先析构p2再析构p1，那么他们的m_height所指向的堆区地址就会被重复释放
             * 
             * 解决方法：在调用拷贝构造函数时，使用深拷贝的原理，自己写拷贝构造函数，新的对象重新在堆区申请数据
             * Person(const Person & p){
             *     cout << "Person Copy" << endl;
             *     m_age = p.m_age;
             *     m_height = new int(*p.m_height);
             * }
            */
        }
        cout << "Ending..." << endl;
    }
};

void test01(){
    Person p1(18, 180);
    cout << p1.m_age << " " << *p1.m_height << endl;
    // 当不在使用参数height，且不提供拷贝构造函数时，编译器执行的是系统提供的默认拷贝构造函数，即浅拷贝
    // 浅拷贝只是做一个简单的全属性赋值操作
    Person p2(p1);
    
}

int main(){
    test01();
    // !!!如果属性有在堆区开辟数据的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
    return 0;
}