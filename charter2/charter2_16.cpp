/**
 * C++类会默认提供的第四个函数：=运算符重载函数
 * 函数调用运算符()也可以发生重载
 * 由于重载后使用的方式非常像函数调用，因此称为仿函数
 * 仿函数没有固定写法，非常灵活
*/
#include<iostream>
using namespace std;

class Person{
    friend ostream &operator<<(ostream &cout, Person &p);
    public:
    Person(int age){
        // 把m_Age开辟到堆区，并在析构函数中再次
        m_Age = new int(age);
    }

    ~Person(){
        if(m_Age != NULL){
            // 撤销m_Age指针与其指向的内存地址之间的连接，将内存还给操作系统
            delete m_Age;
            // 将指针的指向重新定位到空地址
            m_Age = NULL;
        }
    }
    // 赋值运算符是一个右结合的操作符，要实现操作符的链式编程，就要将返回值改为Person
    /**
     * a = 10;
     * b = 20;
     * c = 30;
     * a=b=c;
     * a=30;
    */
    // 重载类默认的赋值运算符
    Person &operator=(Person &p){
        // 编译器默认赋值重载是浅拷贝，即
        // this->m_Age = p.m_Age;
        // !在自定义赋值重载时，要先判断是否已经有成员变量存放在堆区，例如这里的this，其可能已经在有参构造函数中创建了堆区数据，要先释放干净再深拷贝
        if(this->m_Age != NULL){
            delete this->m_Age;
            this->m_Age = NULL;
        }
        this->m_Age = new int(*p.m_Age);
        return *this;
    }
    // 在C++中，对于比较运算符不支持链式编程，例如a<b<c不是a<b&&b<c而是(a<b)<c，是让a<b的结果与c比较，因此不必返回Person类型
    bool operator==(Person &p){
        if(*this->m_Age == *p.m_Age){
            return true;
        }
        return false;
    }

    bool operator<(Person &p){
        if(*this->m_Age < *p.m_Age){
            return true;
        }
        return false;
    }

    bool operator>(Person &p){
        if(*this->m_Age > *p.m_Age){
            return true;
        }
        return false;
    }

    bool operator!=(Person &p){
        if(*this->m_Age != *p.m_Age){
            return true;
        }
        return false;
    }
    private:
    int *m_Age;
};

class MyAdd{
    public:
    // 重载小括号形成仿函数
    int operator()(int a, int b){
        return a + b;
    }
};

ostream &operator<<(ostream &cout, Person &p){
    cout << *p.m_Age;
    return cout;
}

void test01(){
    Person p1(18);
    Person p2(20);
    cout << "p1 = " << p1 << " " << "p2 = " << p2 << endl;
    // 如果使用默认的赋值重载函数则会报错，默认的赋值重载是浅拷贝，当p2和p1调用析构函数时，会重复释放同一内存，因此需要自定义赋值重载函数
    p2 = p1;
    cout << "After, " << "p1 = " << p1 << " " << "p2 = " << p2 << endl;
    Person p3(23);
    p3 = p2 = p1;
    cout << "p3 = " << p3 << endl;
    if(p1 == p2)
        cout << "p1 = p2" << endl;
    else if(p1 != p2)
        cout << "p1 != p2" << endl;
    if(p1 < p2)
        cout << "p1 < p2" << endl;
    else if(p1 > p2)
        cout << "p1 > p2" << endl;
}

void test02(){
    MyAdd myadd;
    // 可以看出仿函数的调用方法与普通函数调用大体相同，只是调用时要跟在函数对象后面
    int c = myadd(1, 2);
    cout << c << endl;
    // 先通过MyAdd()生成一个匿名对象，再用匿名对象调用()重载函数
    cout << MyAdd()(3, 4) << endl;
}

int main(){
    test01();
    return 0;
}