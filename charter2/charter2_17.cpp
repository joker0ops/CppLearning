/**
 * 类的继承：
 * 利用继承的技术，可以使得下层的子类拥有与上层父类相同的共性，同时还有自己的特性
 * 继承的语法：class 子类:继承方式 父类
 * 继承方式
 *  - 公共继承public：该继承方式下，父类中除私有元素（最高私密性）外的其他元素均会被继承，且继承来的元素权限均不变
 *  - 保护继承protected：该继承方式下，父类中除私有元素（最高私密性）外的其他元素均会被继承，但继承来的元素均被定义为保护权限
 *  - 私有继承private：该继承方式下，父类中除私有元素（最高私密性）外的其他元素均会被继承，但继承来的元素均被定义为私有权限
*/
#include<iostream>
using namespace std;

// 父类（基类）
class Public{
public:
    void header(){
        cout << "----------header----------" << endl;
    }
    void footer(){
        cout << "----------footer----------" << endl;
    }  
    void left(){
        cout << "Java,Python,C++......" << endl;
    }
};

// 利用公共方式继承
// 子类（派生类）
class Java:public Public{
public:
    void content(){
        cout << "Java Video" << endl;
    }
};

class Python:public Public{
public:
    void content(){
        cout << "Python Video" << endl;
    }
};

void test01(){
    Java java;
    java.header();
    java.left();
    java.content();
    java.footer();
    Python python;
    python.header();
    python.left();
    python.content();
    python.footer();
}

int main(){
    test01();
    return 0;
}