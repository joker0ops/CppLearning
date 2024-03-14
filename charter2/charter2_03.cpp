/**
 * C++面向对象三大特性：封装、继承、多态
 * 封装：
 * 1. 封装的意义：
 *      将属性和行为作为一个整体，表现万事万物：class 类名{ 访问权限: 属性 / 行为 };
 *      将属性和行为加以权限控制
*/
#include<string>
#include<iostream>
using namespace std;
const double PI = 3.14;
// 设计一个圆类，求其周长
class Circle{
    // 访问权限
    public:
    // 类中的属性和行为统称为成员，
    // 属性     成员属性 / 成员变量
    int r;
    // 行为     成员函数 / 成员方法
    double calculate(){
        return 2*r*PI;
    }
};

class Student{
    public:
    string Name;
    int Id;
    int Score;
    void ShowStudent(){
        cout << "Name = " << Name << " Id = " << Id << endl;
    }
    // 通过行为给属性赋值
    void SetName(string name){
        Name = name;
    }
};

/**
 * 类的三种访问权限：
 * public       类内外均可访问
 * protected    类内可以访问，类外不可以访问，子类可以访问父类中的保护内容
 * private      类内可以访问，类外不可以访问，子类不可以访问父类中的私有内容
*/
class Person{
    public:
        // 公共权限
        string name;
    protected:
        // 保护权限
        string car;
    private:
        // 私有权限
        string password;
    public:
        void func(){
            name = "Johnny";
            car = "Bench";
            password = "Joker0910$";
        }
};

// 在设置类时，尽量把成员都设置为私有权限，然后再用成员函数对成员变量进行修改
// 这样可以自己控制读写权限
// 对于写权限，我们也可以检测数据的有效性
class Person2{
    public:
        void setName(string name){
            Name = name;
        }
        string getName(){
            return Name;
        }

        void setAge(int age){
            Age = age;
        }
        int getAge(){
            return Age;
        }

        void setLover(string lover){
            Lover = lover;
        }
        string getLover(){
            return Lover;
        }
        bool isSameGuy(Person2 &p){
            if(p.getName() == Name && p.getAge() == Age && p.getLover() == Lover)
                return true;
            return false;
        }
    private:
        string Name;
        int Age;
        string Lover;
};

int main(){
    // 通过圆类，创建具体的圆（对象）
    Circle c1;
    // 通过.访问类的属性
    c1.r = 10;
    cout << "The length of this Circle is: " << c1.calculate() << endl;
    
    // 创建具体的学生
    Student st1;
    st1.Name = "Jack";
    st1.Id = 1;
    st1.ShowStudent();
    st1.SetName("Joker");
    st1.ShowStudent();

    // 保护权限和私有权限的成员在类外都访问不到
    Person p1;
    p1.name = "John";

    // struct和class唯一的区别就是class默认是私有权限，而struct默认是公共权限                                                                                                                                                                                                  

    Person2 ps2;
    ps2.setName("Jack");
    cout << ps2.getName() << endl;
    ps2.setAge(3);
    cout << ps2.getAge() << endl;
    ps2.setLover("Halen");
    cout << ps2.getLover() << endl;
    return 0;
}